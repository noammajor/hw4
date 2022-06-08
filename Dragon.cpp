#include "Dragon.h"
Dragon::Dragon(int const VAMPIRE_FORCE,int const VAMPIRE_DAMAGE,int const VAMPIRE_COINS,std::string const TYPE_MONSTER)
{
    m_battleForce(DRAGON_FORCE),m_healthLose(DRAGON_DAMAGE),m_gainedLoot(DRAGON_COINS),m_monster(TYPE_MONSTER);
}
