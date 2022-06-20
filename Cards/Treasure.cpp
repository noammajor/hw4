#include "Treasure.h"



bool Treasure::applyEncounter(Player& player)
{
    printTreasureMessage();
     player.addCoins(LOOT);
    return false;
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

std::string Treasure::getType() const
{
    return type;
}