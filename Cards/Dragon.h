#ifndef DRAGON_H_
#define DRAGON_H_
#include "Battle.h"

class Dragon: public Battle
{
    Dragon(int const force, int const damage, int const loot);

    ~Dragon()=default;


private:
    std::string TYPETYPE_MONSTER = Dragon;
    int static const DRAGON_DAMAGE = 100;
    int static const DRAGON_COINS = 1000;
    int static const DRAGON_FORCE = 25;
};

#endif
