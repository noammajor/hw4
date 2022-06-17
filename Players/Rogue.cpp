#include "Rogue.h"


Rogue::Rogue(const std::string &name) :  Player(name)
{
}

void Rogue::addCoins(int coinsToAdd)
{
    m_coins += 2*coinsToAdd;
}


std::unique_ptr<Rogue> Rogue::createRogue(const std::string &name)
{
    std::unique_ptr<Rogue> rogueCard(new Rogue(name));
    if (!rogueCard)
    {
        throw std::bad_alloc();
    }
    return rogueCard;
}


void Rogue::print() const
{
    printPlayerDetails(std::cout, m_name, ROGUE, m_level, m_force, m_playerhealthpoints.getHP(), m_coins);
}

