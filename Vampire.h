#ifndef VAMPIRE_H_
#define VAMPIRE_H_
#include "Battle.h"

class Vampire: public Battle
{
    Vampire(int const force, int const damage, int const loot,std::string const type);

    ~Vampire()=default;


private:
    std::string m_type = Vampire;
    int static const VAMPIRE_DAMAGE = 10;
    int static const VAMPIRE_COINS = 2;
    int static const VAMPIRE_FORCE = 10;
};
#endif

