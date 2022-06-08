#include "Vampire.h"
Vampire::Vampire(int const VAMPIRE_FORCE,int const VAMPIRE_DAMAGE,int const VAMPIRE_COINS,std::string const TYPE_MONSTER)
{
    m_battleForce(VAMPIRE_FORCE),m_healthLose(VAMPIRE_DAMAGE),m_gainedLoot(VAMPIRE_COINS),m_monster(TYPE_MONSTER);
}
