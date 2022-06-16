#include "Treasure.h"



void Treasure::applyEncounter(std::unique_ptr<Player> player)
{
     player->addCoins(LOOT);
}


std::unique_ptr<Treasure> Treasure::createTreasure()
{
    std::unique_ptr<Treasure> treasureCard(new Treasure());
    if (!treasureCard)
    {
        throw std::bad_alloc();
    }
    return treasureCard;
}

std::string Treasure::gettype()
{
    return type;
}