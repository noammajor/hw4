#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Cards/Card.h"
#include "Players/Player.h"
#include <deque>
#include <map>
#include <queue>
#include <memory>


class Mtmchkin
{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    int m_numberOfRounds;
    int m_numberOfPlayersInGames;
    static const int MINCARDS=5;
    static const int MAXPLAYER=6;
    static const int MINPLAYER=2;
    //int m_numberOfCards;
    std::deque<std::unique_ptr<Card>> m_cardsQueue;
    std::deque<std::unique_ptr<Player>> m_playersQueue;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    static std::map <std::string, int> m_playersJobsMap;
    std::map<std::string, int> m_cardsMap;

    /*std::string VAMPCOMP = "Vampire";
    std::string DRAGCOMP = "Dragon";
    std::string GOBLCOMP = "Goblin";
    std::string FairCOMP = "Fairy";*/
    enum TypeOfCard
    {
    Vampire,Dragon,Goblin,Fairy,Treasure,Merchant,Pitfall
    };

    static std::map <std::string,int> initializeCardsMap();

     std::deque<std::unique_ptr<Card>> initializeCardsQueue(const std::string& fileName);
    std::map <std::string, int> initializeJobsMap();
    static int initializePlayersNumber();
   static std::deque<std::unique_ptr<Player>> initializePlayersQueue(int numberOfPlayers);


    enum jobs
    {
        ROGUE,
        WIZARD,
        FIGHTER
    };


    //std::string TYPE_MONSTER = "Vampire";


};



#endif /* MTMCHKIN_H_ */