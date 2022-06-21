#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Appliance.h"


/*
* Run Length Encoding List
*
* Implements a Barfight card mtmchkin game

* the following class is available:
* Barfight
* The following functions are available:
*
*/

class Barfight : public Appliance
{

public:
    /*
    * C'tor of Barfight class
    */
    explicit Barfight() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Barfight() override = default;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight&) = default;

    /*
    * Handling the player's encounter with the card:
    *
    * @param player - The player.
    * @return bool - true if the player won a battle
    *
    */
    bool applyEncounter(Player& player) override;

    /*
    * returns the cards type
    */
    std::string getType() const override;

    /*
    * returns  a unique_ptr to a new Barfight card
    */
    static std::unique_ptr<Barfight> createBarfight();


private:
    static const int DAMAGE = 10;
    static const std::string BARFIGHT;

};

#endif //HW4_BARFIGHT_H
