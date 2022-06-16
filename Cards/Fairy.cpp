#include "Fairy.h"


void Fairy::applyEncounter(std::unique_ptr<Player> player)
{
    if(player->getName().compare("Wizard"))
    {
        //look at later
        player->heal(healthHeal);
    }
    else
        return;
}
Fairy::Fairy(int heal)
{
    healthHeal=heal;
}
std::unique_ptr<Fairy> Fairy::createFairy()
{
    std::unique_ptr<Fairy>FairyCard(new Fairy());
    return FairyCard;
}