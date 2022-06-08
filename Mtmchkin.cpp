#include"Mtmchkin.h"
#include "Player/"
#include "Card/"
#include <queue>

Mtmchkin::Mtmchkin(const std::string fileName)
{
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
