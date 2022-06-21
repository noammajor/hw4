#include "Goblin.h"


const std::string Goblin::GOBLIN = "Goblin";

Goblin::Goblin(): Battle(GOBLIN_FORCE, GOBLIN_DAMAGE,GOBLIN_COINS)
{
}


std::unique_ptr<Goblin> Goblin::createGoblin()
{
    std::unique_ptr<Goblin> GoblinCard(new Goblin());
    return GoblinCard;
}


std::string Goblin::getType() const
{
    return GOBLIN;
}