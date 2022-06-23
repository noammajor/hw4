#ifndef DRAGON_H_
#define DRAGON_H_

#include "Battle.h"


/*
* Run Length Encoding List
*
* Implements a Dragon card of the mtmchkin game
*
* the following class is available:
* Dragon
*
* The following functions are available:
*
*/

class Dragon: public Battle
{

public:
    /*
    * C'tor of Dragon class
    */
    explicit Dragon();

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Dragon() override = default;
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon&) = default;

    /*
    * returns  a unique_ptr to a new Dragon card
    */
    static std::unique_ptr<Dragon> createDragon();

    /*
    *returns the cards type
    */
    std::string getType() const override;


private:
    const std::string TYPE_MONSTER = "Dragon";
    int static const DRAGON_DAMAGE = 100;
    int static const DRAGON_COINS = 1000;
    int static const DRAGON_FORCE = 25;

};

#endif //DRAGON_H_
