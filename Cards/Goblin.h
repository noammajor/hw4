#ifndef GOBLIN_H_
#define GOBLIN_H_

#include "Battle.h"


/*
* Run Length Encoding List
*
* Implements a Goblin card of the mtmchkin game
*
* the following class is available:
* Goblin
*
* The following functions are available:
*
*/

class Goblin: public Battle
{

public:
    /*
    * C'tor of Goblin class
    */
    explicit Goblin();

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Goblin() override = default;
    Goblin(const Goblin&) = default;
    Goblin& operator=(const Goblin&) = default;

    /*
    * returns  a unique_ptr to a new Goblin card
    */
    static std::unique_ptr<Goblin> createGoblin();

    /*
    *returns the cards type
    */
    std::string getType() const override;

private:
       static const std::string GOBLIN;
       int static const GOBLIN_DAMAGE = 10;
       int static const GOBLIN_COINS = 2;
       int static const GOBLIN_FORCE = 6;

};

#endif
