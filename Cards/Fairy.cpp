#include "Fairy.h"


void Fairy::applyEncounter(std::unique_ptr<Player> player)
{
    if(player->getName() == "Wizard")
    {
        //look at later
        player->heal(HEALTH_HEAL);
    }
    else
        return;
}

std::unique_ptr<Fairy> Fairy::createFairy()
{
    std::unique_ptr<Fairy>FairyCard(new Fairy());
    if (!FairyCard)
    {
        throw std::bad_alloc();
    }
    return FairyCard;
}