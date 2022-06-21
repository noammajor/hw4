#ifndef EX2_Card_H
#define EX2_Card_H

#include "../utilities.h"
#include <memory>


/*
* Implements the cards of mtmchkin game
*
* the following class is available:
* Card
* The following functions are available:
*
*/

class Card
{

public:
    /*
    * C'tor of Card class
    * The class has no parameters
    */
    explicit Card() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    virtual ~Card() = default;
    Card(const Card&) = default;
    Card& operator=(const Card&) = default;

    /*
     * Handling the player's encounter with the card:
     *
     * @param player - The player.
     * @return bool - true if the player won a battle
     *
    */
    virtual bool applyEncounter(Player& player) = 0;

    /*
    * prints the cards details to the screen
    * @ param os - output stream
    */
    virtual void printCard(std::ostream& os) const = 0;

    /*
    *returns the cards type
    */
    virtual std::string getType() const = 0;

    friend  std::ostream& operator<<(std::ostream& os, const Card& card);

};

#endif //EX2_Card_H
