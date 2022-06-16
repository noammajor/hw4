#include "Mtmchkin.h"
#include <memory>
#include "Players/Player.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include "Cards/Card.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include "Fairy.h"
#include "Merchant.h"
#include "Treasure.h"
#include "Pitfall.h"
#include "utilities.h"
#include "Fighter.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Exception.h"

using namespace std;

Mtmchkin::Mtmchkin(const std::string fileName) : m_winners(deque<unique_ptr<Player>>()), m_losers(deque<unique_ptr<Player>>()),
        m_numberOfRounds(0)

{
    m_cardsMap = initializeCardsMap();
    m_cardsQueue = initializeCardsQueue(fileName);
    printStartGameMessage();
    m_numberOfPlayersInGames = initializePlayersNumber();
    m_playersJobsMap = initializeJobsMap();
    m_playersQueue = initializePlayersQueue(m_numberOfPlayersInGames);
}


std::deque<std::unique_ptr<Card>> Mtmchkin::initializeCardsQueue(const std::string& fileName)
{
    ifstream cards("fileName.txt");
    string line;
    std::deque<std::unique_ptr<Card>> cardsQueue;
    if(!cards.is_open())
    {
      throw DeckFileNotFound();
    }
    while (getline(cards, line))
    {
        if (line.empty())
        {
            break;
        }
        switch (m_cardsMap[line]) {
            case Dragon:
            {
                cardsQueue.push_back(Dragon::createDragon());
                break;
            }
            case Vampire: {
                cardsQueue.push_back(Vampire::createVampire());
                break;
            }
            case Goblin:
                cardsQueue.push_back(Goblin::createGoblin());
                break;
            case Fairy:
                cardsQueue.push_back(Fairy::createFairy());
                break;
            case Treasure:
                cardsQueue.push_back(Treasure::createTreasure());
                break;
            case Merchant:
                cardsQueue.push_back(Merchant::createMerchant());
                break;
            case Pitfall:
                cardsQueue.push_back(Pitfall::createPitfall());
                break;
            default:

                throw DeckFileFormatError(cardsQueue.size()+1);
        }
    }
    if(cardsQueue.size()<MINCARDS)
    {
        throw DeckFileInvalidSize();
    }
    return cardsQueue;
}


int Mtmchkin::initializePlayersNumber()
{
    string input;
    int numberOfPlayers = 0;
    while (numberOfPlayers == 0)
    {
        printEnterTeamSizeMessage();
        getline(std::cin, input);
        numberOfPlayers = stoi(input);
        if (numberOfPlayers < MINPLAYER || numberOfPlayers > MAXPLAYER)
        {
            printInvalidTeamSize();
            numberOfPlayers = 0;
        }
    }
    return numberOfPlayers;
}


std::map <std::string, int> Mtmchkin::initializeJobsMap()
{
    std::map<std::string, int> playersJobs =
            {
                    {"Rogue",   ROGUE},
                    {"Wizard",   WIZARD},
                    {"Fighter", FIGHTER}
            };
    return playersJobs;
}


std::deque<std::unique_ptr<Player>> Mtmchkin::initializePlayersQueue(int numberOfPlayers)
{
    std::deque<std::unique_ptr<Player>> playersQueue;
    char currentChar;
    string input;
    string currentName;
    string currentJob;
    int i = 0;
    bool correct;
    for (int i = 0; i < numberOfPlayers ; i++)
    {
        printInsertPlayerMessage();
        correct = true;
        do
        {
            //we need to read only the first word with no spaces!!

            getline(std::cin, input);
            while(input[i] != ' ')
            {
                currentName += input[i];
            }
            while (currentName.length() > 15 || currentName.empty())
            {
                printInvalidName();
                printInsertPlayerMessage();
                getline(std::cin, currentName);
            }
            getline(std::cin, currentJob);
            switch (m_playersJobsMap[currentJob])
            {
                case ROGUE:
                    playersQueue.push_back(Rogue::createRogue(currentName));
                    break;
                case WIZARD:
                    playersQueue.push_back(Wizard::createWizard(currentName));
                    break;
                case FIGHTER:
                    playersQueue.push_back(Fighter::createFighter(currentName));
                    break;
                default:
                    printInvalidClass();
                    correct = false;
            }
        }
        while (!correct);
    }
    return playersQueue;
}


void Mtmchkin::playRound()
{
    printRoundStartMessage(m_numberOfRounds);
    for (int i = 0 ; i < m_numberOfPlayersInGames ; i++)
    {
        printTurnStartMessage(m_playersQueue.front()->getName());
        unique_ptr<Card> currentCard = move(m_cardsQueue.front());
        m_cardsQueue.pop_front();
        unique_ptr<Player> currentPlayer = move(m_playersQueue.front());
        m_playersQueue.pop_front();
        currentCard->applyEncounter(move(currentPlayer));
        m_cardsQueue.push_back(move(currentCard));
        if (move(currentPlayer)->getLevel() == 10)
        {
            m_numberOfPlayersInGames--;
            m_winners.push_front(std::move(currentPlayer));
        }
        else if (move(currentPlayer)->isKnockedOut())
        {
            m_numberOfPlayersInGames--;
            m_losers.push_back(move(currentPlayer));
        }
        else
        {
            m_playersQueue.push_back(move(currentPlayer));
        }
    }
    if (m_numberOfPlayersInGames == 0)
    {
        // check if leader board was updated
        printGameEndMessage();

        // end the game here
    }
}


void Mtmchkin::printLeaderBoard() const
{
    Player* player;
    int ranking=1;
    printLeaderBoardStartMessage();
    for (player = m_winners.front().get() ; player != nullptr ; player++)
    {
        printPlayerLeaderBoard( ranking, *player);
        ranking++;
    }
    for (player = m_playersQueue.front().get() ; player != nullptr ; player++)
    {
        printPlayerLeaderBoard( ranking, *player);
        ranking++;
    }
    for (player = m_losers.front().get() ; player != nullptr ; player++)
    {
        printPlayerLeaderBoard( ranking, *player);
        ranking++;
    }
}


bool Mtmchkin::isGameOver() const
{
    if (m_numberOfPlayersInGames == 0)
    {
        return true;
    }
    return false;
}


int Mtmchkin::getNumberOfRounds() const
{
    return m_numberOfRounds;
}

std::map <std::string,int> Mtmchkin::initializeCardsMap()
{
    static std::map<std::string,int> setupCards =
            {
                    {"Vampire", Vampire },
                    {"Dragon" , Dragon},
                    {"Goblin" , Goblin},
                    {"Fairy", Fairy},
                    {"Treasure",Treasure},
                    {"Merchant", Merchant},
                    {"Pitfall",Pitfall}
            };
    return setupCards;
}