#include "Mtmchkin.h"
#include "Players/Player.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "Cards/Card.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include "Fairy.h"
#include "Merchant.h"
#include "Treasure.h"
#include "Pitfall.h"
#include "utilities.h"

using namespace std;

Mtmchkin::Mtmchkin(const std::string fileName)
{
    ifstream cards("fileName.txt");
    string line;
    //exception.
    while (getline(cards, line)) {
        if (line.empty()) {
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
    }
}
void Mtmchkin::playRound()
{
    printRoundStartMessage(m_numberOfRounds);
    for (int i = 0 ; i < m_numberOfPlayersInGames ; i++)
    {
        printTurnStartMessage(m_playersQueue.front());
        Card currentCard = m_cardsQueue.front();
        Player currentPlayer = m_playersQueue.front();
        currentCard.applyEncounter(currentPlayer);
        m_playersQueue.pop_back();
        if (currentPlayer.getLevel() == 10)
        {
            m_playersQueue--;
            m_winners.push(&currentPlayer);
        }
        else if (currentPlayer.isKnockedOut())
        {
            m_playersQueue--;
            m_losers.push(&currentPlayer);
        }
        else
        {
            m_playersQueue.push(&currentPlayer);
        }
        m_cardsQueue.pop();
        m_cardsQueue.push(&currentCard);
    }
    if (m_playersQueue == 0)
    {
        // check if leader board was updated
        printGameEndMessage();

        // end the game here
    }
}


void Mtmchkin::printLeaderBoard() const
{

    // we have to print: m_losers, m_players, m_winners
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