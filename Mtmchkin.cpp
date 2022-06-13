#include "Mtmchkin.h"
#include "Players/Player.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
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

Mtmchkin::Mtmchkin(const std::string& fileName)
{
    ifstream cards("fileName.txt");
    string line;
    //exception.
    while (getline(cards, line))
    {
        if(line.empty())
        {
            break;
        }

        switch (SetupCards[line]) {
            case Dragon: {
                class Dragon card;
                m_cardsQueue.push_back(&card);
                break;
            }
            case Vampire: {
                class Vampire card;
                m_cardsQueue.push_back(&card);
                break;
            }
            case Goblin: {
                class Goblin card;
                m_cardsQueue.push_back(&card);
                break;
            }
                //fairy
            case Fairy: {
                class Fairy card;
                m_cardsQueue.push_back(&card);
                break;
            }
            case Treasure: {
                class Treasure card;
                m_cardsQueue.push_back(&card);
                break;
            }
            case Merchant: {
                class Merchant card;
                m_cardsQueue.push_back(&card);
                break;
            }
            case Pitfall: {
                class Pitfall card;
                m_cardsQueue.push_back(&card);
                break;

        }
    }
    printStartGameMessage();
    m_numberOfPlayersInGames = initializePlayersNumber();
    m_playersJobs = initializeJobsMap();
    m_playersQueue = initializePlayersQueue(m_numberOfPlayersInGames);

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


std::queue<std::unique_ptr<Player>> Mtmchkin::initializePlayersQueue(int numberOfPlayers)
{
    std::queue<std::unique_ptr<Player>> playersQueue;
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
            switch (m_playersJobs[currentJob])
            {
                case ROGUE:
                    playersQueue.push(make_unique<Player>(Rogue(currentName)));
                    break;
                case WIZARD:
                    playersQueue.push(make_unique<Player>(Wizard(currentName)));
                    break;
                case FIGHTER:
                    playersQueue.push(make_unique<Player>(Fighter(currentName)));
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
        Card* currentCard = m_cardsQueue.front();
        unique_ptr<Player> currentPlayer = move(m_playersQueue.front());
        currentCard->applyEncounter(currentPlayer);
        m_playersQueue.pop_back();
        if (currentPlayer->getLevel() == 10)
        {
            m_numberOfPlayersInGames--;
            m_winners.push(std::move(currentPlayer));
        }
        else if (currentPlayer->isKnockedOut())
        {
            m_numberOfPlayersInGames--;
            m_losers.push(currentPlayer);
        }
        else
        {
            m_playersQueue.push(currentPlayer);
        }
        m_cardsQueue.pop();
        m_cardsQueue.push(currentCard);
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
    for(Player player : m_playersQueue)
    {
        player.printInfo();
    }
}
// we have to print: m_losers, m_players, m_winners



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

std::map <std::string,int> Mtmchkin::Initializemap()
{
    static std::map<std::string,int> SetupCards =
            {
                    {"Vampire", Vampire },
                    {"Dragon" , Dragon},
                    {"Goblin" , Goblin},
                    {"Fairy", Fairy},
                    {"Treasure",Treasure},
                    {"Merchant", Merchant},
                    {"Pitfall",Pitfall}
            };
}