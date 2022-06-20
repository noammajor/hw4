#include "Barfight.h"




bool Barfight::applyEncounter(Player& player)
{
    bool isFighter= true;
    if(player.getType() != "Fighter")
    {
        isFighter= false;
        player.damage(GIVEDAMAGE);
    }
    printBarfightMessage(isFighter);
    return true;
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

