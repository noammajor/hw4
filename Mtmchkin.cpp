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

using namespace std;

Mtmchkin::Mtmchkin(const std::string fileName)
{
    ifstream cards ("fileName.txt");
    string line;
    //exception.
    while (getline(cards,line))
    {
        if(line.empty())
        {
            break;
        }

        switch(line)
        {
            case line.compare(DRAGCOMP):
            {
                Dragon card = Dragon();
                m_cardsQueue.push(&card);
                break;
            }
            case line.compare(VAMPCOMP):
            {
                Vampire card = Vampire();
                m_cardsQueue.push(&card);
                break;
            }
            case line.compare(GOBLCOMP):
            {
                Goblin card = Goblin();
                m_cardsQueue.push(&card);
                break;
            }
            //fairy
            case line.compare(FairCOMP):
            {
                Goblin card = Goblin();
                m_cardsQueue.push(&card);
                break;
            }


        }
    }

void Mtmchkin::playRound()
{
    void printRoundStartMessage(m_numberOfRounds);
    for (int i = 0 ; i < m_numberOfPlayersInGames ; i++)
    {
        void printTurnStartMessage(m_playersQueue.front());
        Card currentCard = m_cardsQueue.front();
        Player currentPlayer = m_playersQueue.front();
        currentCard.applyEncounter(currentPlayer);
        m_playersQueue.pop();
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
