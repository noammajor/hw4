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
    * Default
    * @return A new instance of Barfight.
    */
     explicit Barfight() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Barfight() override = default;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight&) = default;

    /*
    *  Applies each Cards effect on Player
    *  @param player- player who turn it is on the card
    *  @return true if a battle has happened and the player has won, otherwise false
    */
    bool applyEncounter(Player& player) override;

    /*
    *  Creates and returns a unique pointer to new instance of Barfight
    *  @return unique pointer
    */
    static std::unique_ptr<Barfight> createBarfight();

    /*
    *  Gives us the Type of the card
    *  @return string "Barfight"
    */
    std::string getType() const override;


private:
    static const int DAMAGE = 10;
    static const std::string BARFIGHT;

};

#endif //HW4_BARFIGHT_H
