#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H

#include "Appliance.h"


/*
* Run Length Encoding List
*
* Implements a Fairy card of the mtmchkin game
*
* the following class is available:
* Fairy
*
* The following functions are available:
*
*/

class Fairy : public Appliance
{

public:
    /*
    * C'tor of Fairy class
    */
    explicit Fairy() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fairy() override = default;
    Fairy(const Fairy&) = default;
    Fairy& operator=(const Fairy&) = default;

    /*
    * returns  a unique_ptr to a new Fairy card
    */
    static std::unique_ptr<Fairy> createFairy();

    /*
    * Handling the player's encounter with the card:
    *
    * @param player - The player.
    * @return bool - true if the player won a battle
    *
    */
    bool applyEncounter(Player& player) override;

    /*
    *returns the cards type
    */
    std::string getType() const override;


private:
    static const int HEALTH_HEAL = 10;
    static const std::string FAIRY;

};


#endif //HW4_FAIRY_H
