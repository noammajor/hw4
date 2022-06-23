#ifndef HW4_GANG_H
#define HW4_GANG_H

#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include <deque>
#include <map>
#include <fstream>


/*
* Run Length Encoding List
*
* Implements a Gang card of the mtmchkin game
*
* the following class is available:
* Gang
*
* the following variables are available:
* m_cardsDeque - a deque of the monsters of the gang
*
* The following functions are available:
*
*/

class Gang : public Card
{

public:
    /*
    * C'tor of Dragon class
    */
    Gang(std::ifstream& cards, int& linesCounter);

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Gang() override = default;
    Gang(const Gang&);
    Gang& operator=(const Gang&);

    /*
    * Handling the player's encounter with the card:
    *
    * @param player - The player.
    * @return bool - true if the player won a battle
    *
    */
    bool applyEncounter(Player& player) override;

    /*
    * returns  a unique_ptr to a new Gang card
    * @param cards - input stream
    * @param linesCounter - counts the lines of the input in order to return it in a case of error
    */
    static std::unique_ptr<Gang> createGang(std::ifstream& cards, int& linesCounter);

    /*
    * returns a deque of cards' unique_ptrs
    * @param cards - input stream
    * @param linesCounter - counts the lines of the input in order to return it in a case of error
    */
    std::deque<std::unique_ptr<Card>> initializeBattleQueue(std::ifstream& cards, int &linesCounter);

    /*
    *returns the cards type
    */
    std::string getType() const override;

    /*
    *  prints the cards details to the screen
    *  @param os - output stream
    */
    void printCard(std::ostream& os) const override;







private:

    std::map<std::string, int> m_battleMap;
    static std::map <std::string, int> initializeBattleMap();

    enum jobs
    {
        Dragon = 1,
        Vampire,
        Goblin,
        EndGang
    };

    std::deque<std::unique_ptr<Card>> m_cardsDeque;

    int static const DRAGONDAMAGE = 100;
    int static const VAMPIREDAMAGE = 10;
    int static const GOBLINDAMAGE = 10;
    int static const VAMPIRE_FORCE_LOSS=-1;
    static const std::string GANG;

};


#endif //HW4_GANG_H
