#include "Rogue.h"
#include "Player.h"

Rogue::Rogue(const std::string &name) :  Player(name, ROGUE)
{
}

void Rogue::addCoins(int coinsToAdd)
{
    m_coins += 2*coinsToAdd;
}
