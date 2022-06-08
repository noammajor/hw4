#include "Fighter.h"
#include "Player.h"


Fighter::Fighter(const std::string &name) :  Player(name, FIGHTER)
{
}


int Player::getAttackStrength() const
{
    return (m_level + m_force*2);
}



