#include "Fighter.h"



Fighter::Fighter(const std::string &name) :  Player(name)
{
}


int Fighter::getAttackStrength() const
{
    return (m_level + m_force*2);
}


std::unique_ptr<Fighter> Fighter::createFighter(const std::string &name)
{
    std::unique_ptr<Fighter> fighterCard(new Fighter(name));
    return fighterCard;
}


void Fighter::print() const
{
    printPlayerDetails(std::cout, m_name, FIGHTER, m_level, m_force, m_playerhealthpoints.getHP(), m_coins);
}

