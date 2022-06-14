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


using namespace std;

Mtmchkin::Mtmchkin(const std::string fileName) : m_winners(deque<unique_ptr<Player>>()), m_losers(deque<unique_ptr<Player>>())
{
    m_cardsMap = initializeCardsMap();
    m_cardsQueue = initializeCardsQueue(fileName);
    printStartGameMessage();
    m_numberOfPlayersInGames = initializePlayersNumber();
    m_playersJobsMap = initializeJobsMap();
    m_playersQueue = initializePlayersQueue(m_numberOfPlayersInGames);
    m_numberOfRounds = 0; // check if  it is the correct number in the prints
}


std::deque<std::unique_ptr<Card>> Mtmchkin::initializeCardsQueue(const std::string& fileName)
{
    ifstream cards("fileName.txt");
    string line;
    std::deque<std::unique_ptr<Card>> cardsQueue;
    //exception.
    while (getline(cards, line))
    {
        if (line.empty())
        {
            break;
        }

        switch (m_cardsMap[line]) {
            case Dragon: {
                class Dragon card;
                cardsQueue.push_back(card.createDragon());
                break;
            }
            case Vampire: {
                class Vampire card;
                cardsQueue.push_back(card.createVampire());
                break;
            }
            case Goblin: {
                class Goblin card;
                cardsQueue.push_back(card.createGoblin());
                break;
            }

            case Fairy: {
                class Fairy card;
                cardsQueue.push_back(card.createFairy());
                break;
            }
            case Treasure: {
                class Treasure card;
                cardsQueue.push_back(card.createTreasure());
                break;
            }
            case Merchant: {
                class Merchant card;
                cardsQueue.push_back(card.createMerchant());
                break;
            }
            case Pitfall: {
                class Pitfall card;
                cardsQueue.push_back(card.createPitfall());
                break;
            }
        }
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
        if (numberOfPlayers < 2 || numberOfPlayers > 6)
        {
            printInvalidTeamSize();
            numberOfPlayers = 0;
        }
    }
    return numberOfPlayers;
}


std::map <std::string, int> Mtmchkin::initializeJobsMap()
{
    static std::map<std::string, int> playersJobs =
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
    string currentName;
    string currentJob;
    bool correct;
    for (int i = 0; i < numberOfPlayers ; i++)
    {
        printInsertPlayerMessage();
        correct = true;
        do
        {
            getline(std::cin, currentName);
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
            m_winners.push_back(std::move(currentPlayer));
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
    for (Player* player = m_losers.front().get() ; player != nullptr ; player++)
    {
        player->printInfo();
    }
    for (Player* player = m_playersQueue.front().get() ; player != nullptr ; player++)
    {
        player->printInfo();
    }
    for (Player* player = m_winners.front().get() ; player != nullptr ; player++)
    {
        player->printInfo();
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