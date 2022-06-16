#include "Treasure.h"
#include "Player.h"
#include "Card.h"



void Treasure::applyEncounter(std::unique_ptr<Player> player)
{
     player->addCoins(LOOT);
}


std::unique_ptr<Treasure> Treasure::createTreasure()
{
    std::unique_ptr<Treasure> treasureCard(new Treasure());
    return treasureCard;
}

