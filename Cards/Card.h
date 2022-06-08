#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Player.h"
#include "../utilities.h"

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
    Card();
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    virtual Card(const Card&) = default;
    virtual ~Card();
    virtual Card& operator=(const Card& other) = default;

};

#endif //EX2_Card_H
