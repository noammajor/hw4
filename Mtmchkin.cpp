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
#include "Barfight.h"

using namespace std;

Mtmchkin::Mtmchkin(const std::string fileName) : m_winners(deque<unique_ptr<Player>>()), m_losers(deque<unique_ptr<Player>>()),
        m_numberOfRounds(0)

{
    m_cardsMap = initializeCardsMap();
    m_cardsQueue = initializeCardsQueue(fileName);
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
        switch (m_cardsMap[line])
        {
            case Dragon:
                cardsQueue.push_back(Dragon::createDragon());
                break;
            case Vampire:
                cardsQueue.push_back(Vampire::createVampire());
                break;
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
            case Barfight:
                cardsQueue.push_back(Barfight::createBarfight());
            default:
                throw DeckFileFormatError(cardsQueue.size()+1);
        }
    }
    if(cardsQueue.size()<MIN_CARDS)
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
        if (numberOfPlayers < MIN_PLAYER || numberOfPlayers > MAX_PLAYER)
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
    char currentChar = getchar();
    string input;
    string currentName;
    string currentJob;
    bool correct, playerCreated;
    for (int i = 0; i < numberOfPlayers ; i++)
    {
        printInsertPlayerMessage();
        do
        {
            do
            {
                correct = true;
                playerCreated = true;
                while (EOF != (currentChar = getchar()))
                {
                    if (currentChar == ' ')
                    {
                        break;
                    }
                    currentName += currentChar;
                }
                if (currentName.length() > MAX_LENGTH_NAME || currentName.empty())
                {
                    printInvalidName();
                    printInsertPlayerMessage();
                    currentName = getchar();
                    correct = false;
                }
            }
            while (!correct);
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
                        playerCreated = false;
                }
            }
            while (!playerCreated);
        }
    return playersQueue;
}


void Mtmchkin::playRound()
{
    printRoundStartMessage(m_numberOfRounds);
    for (int i = m_numberOfPlayersInGames ; i > 0 ; i--)
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
            m_winners.push_back(std::move(currentPlayer));
        }
        else if (move(currentPlayer)->isKnockedOut())
        {
            m_numberOfPlayersInGames--;
            m_losers.push_front(move(currentPlayer));
        }
        else
        {
            m_playersQueue.push_back(move(currentPlayer));
        }
    }
    if (m_numberOfPlayersInGames == 0)
    {
        printGameEndMessage();
        printLeaderBoard();
    }
    m_numberOfRounds++;
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