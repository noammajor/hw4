#include "Rogue.h"
#include "Player.h"
#include "utilities.h"

Rogue::Rogue(const std::string &name) :  Player(name, ROGUE)
{
}

void Rogue::addCoins(int coinsToAdd)
{
    m_coins += 2*coinsToAdd;
}


std::unique_ptr<Rogue> Rogue::createRogue(const std::string &name)
{
    std::unique_ptr<Rogue> rogueCard(new Rogue(name));
    return rogueCard;
}


void Rogue::print(std::ostream& os) const
{
    printPlayerDetails(os, m_name, m_job, m_level, m_force, m_playerhealthpoints.getHP(), m_coins);
}

////// delete m_job!!




const std::string Rogue::ROGUE = "Rogue";