#ifndef GOBLIN_H_
#define GOBLIN_H_
#include "../Battle.h"

class Goblin: public Battle
{
    Goblin(int const force, int const damage, int const loot,std:string type);

    ~Goblin() = default;


private:
       std::string TYPE_MONSTER= Goblin;
       int static const GOBLIN_DAMAGE = 10;
       int static const GOBLIN_COINS = 2;
       int static const GOBLIN_FORCE = 6;
};
#endif
