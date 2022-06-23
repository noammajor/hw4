#include "Fairy.h"


const std::string Fairy::FAIRY = "Fairy";

bool Fairy::applyEncounter(Player& player)
{
    bool isWizard = false;
    if(player.getType() == "Wizard")
    {
        isWizard = true;
        player.heal(HEALTH_HEAL);
    }
        printFairyMessage( isWizard);
    return false;
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
    return FAIRY;
}