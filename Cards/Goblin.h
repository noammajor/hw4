#ifndef GOBLIN_H_
#define GOBLIN_H_
#include "Battle.h"

class Goblin: public Battle
{
public:
    Goblin();
    Goblin& operator=(const Goblin& goblin) = default;
    Goblin(const Goblin&) = default;
    ~Goblin() override = default;


private:
       std::string TYPE_MONSTER= "Goblin";
       int static const GOBLIN_DAMAGE = 10;
       int static const GOBLIN_COINS = 2;
       int static const GOBLIN_FORCE = 6;
};
#endif
