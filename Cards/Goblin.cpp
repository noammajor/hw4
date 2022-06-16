#include "Goblin.h"
Goblin::Goblin():
Battle(GOBLIN_FORCE, GOBLIN_DAMAGE,GOBLIN_COINS,TYPE_MONSTER)
{

}


std::unique_ptr<Goblin> Goblin::createGoblin()
{
    std::unique_ptr<Goblin>GoblinCard(new Goblin());
    return GoblinCard;
}


std::string const Goblin::TYPE_MONSTER= "Goblin";