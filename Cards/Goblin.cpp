#include "Goblin.h"
Goblin::Goblin():
Battle(GOBLIN_FORCE, GOBLIN_DAMAGE,GOBLIN_COINS,TYPE_MONSTER)
{

}
std::unique_ptr<Goblin> createGoblin()
{
    std::unique_ptr<Goblin>GoblinCard(new Goblin());
    return GoblinCard;
}