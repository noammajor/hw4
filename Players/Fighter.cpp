#include "Fighter.h"



Fighter::Fighter(const std::string &name) :  Player(name)
{
}
 std::string Fighter::getType() const
{
    return FIGHTER;
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
    printPlayerDetails(std::cout, this->m_name, this->FIGHTER, this->m_level, this->m_force,this-> m_playerhealthpoints.getHP(), this->m_coins);

}

