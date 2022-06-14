#include "Fighter.h"
#include "Player.h"
#include "utilities.h"


Fighter::Fighter(const std::string &name) :  Player(name, FIGHTER)
{
}


int Player::getAttackStrength() const
{
    return (m_level + m_force*2);
}


std::unique_ptr<Fighter> Fighter::createFighter(const std::string &name)
{
    std::unique_ptr<Fighter> fighterCard(new Fighter(name));
    return fighterCard;
}


void Fighter::print(std::ostream& os) const
{
    printPlayerDetails(os, m_name, m_job, m_level, m_force, m_playerhealthpoints.getHP(), m_coins);
}


const std::string Fighter::FIGHTER = "Fighter";

