#include "Treasure.h"
Treasure::Treasure(int payment)
{
giveTreasure=payment;
}


void Treasure::applyEncounter(Player& player)
{
    player.addCoins(giveTreasure);
}


