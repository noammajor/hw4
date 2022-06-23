#include "Barfight.h"


const std::string Barfight::BARFIGHT = "Barfight";

bool Barfight::applyEncounter(Player& player)
{
    bool isFighter = true;
    if(player.getType() != "Fighter")
    {
        isFighter = false;
        player.damage(DAMAGE);
    }
    printBarfightMessage(isFighter);
    return false;
}


std::string Barfight::getType() const
{
    return BARFIGHT;
}


std::unique_ptr<Barfight> Barfight::createBarfight()
{
    std::unique_ptr<Barfight> BarfightCard(new Barfight());
    if (!BarfightCard)
    {
        throw std::bad_alloc();
    }
    return BarfightCard;
}

