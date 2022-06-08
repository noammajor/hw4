#include "Goblin.h"
Goblin::Goblin(int const GOBLIN_FORCE,int const GOBLIN_DAMAGE,int const GOBLIN_COINS,std::string const TYPE_MONSTER)
{
    m_battleForce(GOBLIN_FORCE),m_healthLose(GOBLIN_DAMAGE),m_gainedLoot(GOBLIN_COINS),m_monster(TYPE_MONSTER);
}
