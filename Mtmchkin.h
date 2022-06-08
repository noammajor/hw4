#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <queue>
#include "Card.h"

class Mtmchkin{

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
    int m_numberOfCards;
    std::queue<Card*> m_cardsQueue;
    std::string VAMPCOMP = "Vampire";
    std::string DRAGCOMP = "Dragon";




    //std::string TYPE_MONSTER = "Vampire";


};



#endif /* MTMCHKIN_H_ */
