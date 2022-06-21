#ifndef BATTLE_H_
#define BATTLE_H_

#include "Card.h"


/*
* Run Length Encoding List
*
* Implements a Battle card mtmchkin game
*
* the following class is available:
* Battle
* the following variables are part of the class:
* m_battleForce - the monster's attack force
* m_healthLose - the damage to the player's hp in case he was  defeated
* m_gainedLoot - the amount of coins the player gains in case of winning the battle
* The following functions are available:
*
*/

class Battle : public Card
{

protected:

    /*
    * C'tor of Aplliance class
    * @param force - the monsters attack force
    * @param health - the damage to the players hp in case he was  defeated
    * @param name - loot - the amount of coins the player gains in case of winning the battle
    */
    Battle(int force, int health, int loot);

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Battle() override = default;
    Battle(const Battle&) = default;
    Battle& operator=(const Battle&) = default;

    /*
    * apply the suitable effect on the player according to the battle results
    */
    void winBattle(Player& player,int loot);
    virtual void loseBattle(Player& player,int healthLose);

    /*
    *prints the cards details to the screen
    */
    void printCard(std::ostream& os) const override;

    /*
    *returns the cards type
    */
    std::string getType() const override = 0;

    /*
     * Handling the player's encounter with the card:
     *
     * @param player - The player.
     * @return bool - true if the player won a battle
     *
    */
    bool applyEncounter(Player& player) override;


private:
    int const m_battleForce;
    int const m_healthLose;
    int const m_gainedLoot;

};

#endif
