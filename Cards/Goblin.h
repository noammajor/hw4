#ifndef GOBLIN_H_
#define GOBLIN_H_
#include "Battle.h"

class Goblin: public Battle
{
public:
    Goblin();
    ~Goblin() override = default;
    static std::unique_ptr<Goblin> createGoblin();
    std::string getType() const override;

private:
       std::string const TYPE_MONSTER = "Goblin";
       int static const GOBLIN_DAMAGE = 10;
       int static const GOBLIN_COINS = 2;
       int static const GOBLIN_FORCE = 6;
};
#endif
