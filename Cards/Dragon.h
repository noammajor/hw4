#ifndef DRAGON_H_
#define DRAGON_H_
#include "Battle.h"

class Dragon: public Battle
{
public:
    Dragon();
    Dragon& operator=(const Dragon& dragon) = default;
    Dragon(const Dragon&) = default;
    ~Dragon() override=default;



private:
    std::string TYPE_MONSTER = "Dragon";
    int static const DRAGON_DAMAGE = 100;
    int static const DRAGON_COINS = 1000;
    int static const DRAGON_FORCE = 25;
};

#endif
