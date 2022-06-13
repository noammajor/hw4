#ifndef VAMPIRE_H_
#define VAMPIRE_H_
#include "Battle.h"

class Vampire: public Battle
{
public:
    Vampire();
    Vampire& operator=(const Vampire& dragon) = default;
    Vampire(const Vampire&) = default;
    ~Vampire() override = default;
    std::unique_ptr<Vampire> createVampire();



private:
    const std::string TYPE_MONSTER = "Vampire";
    int  static const VAMPIRE_DAMAGE = 10;
    int  static const VAMPIRE_COINS = 2;
    int static const VAMPIRE_FORCE = 10;
};
#endif

