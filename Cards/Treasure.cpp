#include "Treasure.h"


Treasure::Treasure(int payment)
{
giveTreasure=payment;
}


void Treasure::applyEncounter(std::unique_ptr<Player> player)
{
     player->addCoins(giveTreasure);
}


std::unique_ptr<Treasure> Treasure::createTreasure()
{
    std::unique_ptr<Treasure>TreasureCard(new Treasure());
    return TreasureCard;
}

