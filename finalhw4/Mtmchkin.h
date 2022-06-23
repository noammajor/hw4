#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <deque>
#include <map>
#include <fstream>
#include "Cards/Dragon.h"
#include "Cards/Vampire.h"
#include "Cards/Goblin.h"
#include "Cards/Fairy.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Pitfall.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Exception.h"
#include "Cards/Barfight.h"
#include "Cards/Gang.h"


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
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Mtmchkin() = default;
    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin&) = delete;

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

    static const int MIN_CARDS = 5;
    static const int MAX_PLAYER = 6;
    static const int MIN_PLAYER = 2;
    static const int MAX_LEVEL = 10;
    static const int MAX_LENGTH_NAME = 15;
    static const int MAX_ASCII_VALUE = 122;
    static const int MIN_ASCII_VALUE = 65;
    static const int UPPER_INTER_ASCII_VALUE = 97;
    static const int LOWER_INTER_ASCII_VALUE = 90;


    std::deque<std::unique_ptr<Card>> m_cardsDeque;
    std::deque<std::unique_ptr<Player>> m_playersDeque;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    std::map <std::string, int> m_playersJobsMap;
    std::map<std::string, int> m_cardsMap;

    int m_numberOfRounds;
    int m_numberOfPlayersInGames;


    /*
    *  creates the map for creating the deck.
    *
    *  @return
    *        map holding a string and int (int is represented as a emun)
    */
    static std::map <std::string,int> initializeCardsMap();

    /*
    *  checks if the input is only alphabet letters
    *
    *  @return
    *          bool - true if the name is only letter.
    */
    bool static containsOnlyLetters(std::string &currentName);

    /*
    *  creates the deck of cards for the game
    *
    *  @return
    *         deque - returns the deck of cards
    */
    std::deque<std::unique_ptr<Card>> initializeCardsDeque(const std::string &fileName);

    /*
    *  creates the map for creating the players.
    *
    *  @return
    *        map - holding a string and int (int is represented as a emun)
    */
    static std::map <std::string, int> initializeJobsMap();

    /*
    *  recieves from the user the amount of players who want to play
    *
    *  @return
    *        int - the amount of players
    */
    static int initializePlayersNumber();

    /*
    *  creates the deck that holds the layers for the game
    *
    *  @return
    *         deque - returns the deck of cards
    */
    std::deque<std::unique_ptr<Player>> initializePlayersDeque(int numberOfPlayers);

    /*
    *  finds the place of " " and chooses right boolian value
    *
    *  @return
    *         int - place in string to "cut" into two words
    */
    static int setupOfPlayersDeck(bool& correct, bool& playercreated, std::string& input);

    /*
    *  checks if word only has letters
    */
    static void ifOnlyHasLetter (bool& correct, std::string& currentName);

    /*
    *  checks if length of word is legal
    */
    static void ifIsLegalLength (bool& correct,int currentChar);

    /*
    *  takes the string apart to two diffrent strings, player name and type
    */
    static void takingAppartTheName (std::string& input,int currentChar,std::string& currentName,std::string& currentJob);

    /*
    *  checks which card name was chosen, pushes them into deck.
    */
    void pushCardsToDeck( std::deque<std::unique_ptr<Card>>& cardsDeque,int& linesCounter,
                          std::string& line,std::ifstream& cards);


    enum Jobs
    {
        Rogue = 1,
        Wizard,
        Fighter
    };


    enum TypeOfCard
    {
        Vampire = 1,
        Dragon,
        Goblin,
        Fairy,
        Treasure,
        Merchant,
        Pitfall,
        Barfight,
        Gang
    };

};

#endif /* MTMCHKIN_H_ */
