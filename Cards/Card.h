#ifndef EX2_Card_H
#define EX2_Card_H

//#include <string>
//#include "../Players/Player.h"
#include "../utilities.h"
#include <memory>
//#include <iostream>
//#include <ostream>

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/

class Card
{
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    explicit Card()=default;
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual bool applyEncounter(Player& player) = 0;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */

    virtual ~Card() = default;

    virtual void printCard(std::ostream& os) const = 0;

    virtual std::string getType() const = 0;

    friend  std::ostream& operator<<(std::ostream& os, const Card& card);

};

#endif //EX2_Card_H
