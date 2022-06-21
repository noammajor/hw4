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
    * Default
    * @return A new instance of Fairy.
    */
    explicit Fairy() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fairy() override = default;
    Fairy(const Fairy&) = default;
    Fairy& operator=(const Fairy&) = default;

    /*
    *  Creates and returns a unique pointer to new instance of Fairy
    *  @return unique pointer
    */
    static std::unique_ptr<Fairy> createFairy();

    /*
    *  Applies each Cards effect on Player
    *  @param player- player who turn it is on the card
    *  @return false always
    */
    bool applyEncounter(Player& player) override;

    /*
    *  Gives us the Type of the card
    *  @return string "Fairy"
    */
    std::string getType() const override;


private:
    static const int HEALTH_HEAL = 10;
    static const std::string FAIRY;

};


#endif //HW4_FAIRY_H
