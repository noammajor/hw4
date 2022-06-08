#ifndef GOBLIN_H_
#define GOBLIN_H_
#include "Battle.h"

class Goblin: public Battle
{
    Goblin();

    ~Goblin()=default;

private:
    int static const GOBLIN_FORCE = 6;
    int static const GOBLIN_DAMAGE = 10;
    int static const GOBLIN_COINS = 2;
};
#endif
