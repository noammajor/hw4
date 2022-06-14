#include "Barfight.h"
#include "Player.h"


void Barfight::applyEncounter(std::unique_ptr<Player> player)
{
    if(player->getName() == "Fighter")
    {
        return;
    }
    else
    {
        player->damage(GiveDamage);
    }

}


Barfight::Barfight(int damage)
{
    GiveDamage = damage;
}


std::unique_ptr<Barfight> Barfight::createBarfight()
{
    std::unique_ptr<Barfight>BarfightCard(new Barfight());
    return BarfightCard;
}

