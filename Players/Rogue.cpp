#include "Rogue.h"


Rogue::Rogue(const std::string &name) :  Player(name)
{
}

void Rogue::addCoins(int coinsToAdd)
{
    m_coins += 2*coinsToAdd;
}
std::string Rogue::getType() const
{
    return ROGUE;
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
    printPlayerDetails(std::cout, this->m_name, this->ROGUE, this->m_level, this->m_force,this-> m_playerhealthpoints.getHP(), this->m_coins);
}

