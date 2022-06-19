#include "Fairy.h"


void Fairy::applyEncounter(Player& player)
{
    bool isWizard=false;
    if(player. == "Wizard")
    {
        isWizard=true;
        player.heal(HEALTH_HEAL);
    }
        printFairyMessage( isWizard);
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

std::string Fairy::getType() const
{
    return type;
}