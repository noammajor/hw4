#include "Goblin.h"


Goblin::Goblin():
Battle(GOBLIN_FORCE, GOBLIN_DAMAGE,GOBLIN_COINS)
{
}


std::unique_ptr<Goblin> Goblin::createGoblin()
{
    std::unique_ptr<Goblin> GoblinCard(new Goblin());
    return GoblinCard;
}


std::string Goblin::getType() const
{
    return TYPE_MONSTER;
}