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
        player->damage(GIVEDAMAGE);
    }

}
std::string Barfight::gettype()
{
    return type;
}
 //const std::string Appliance::m_type="Barfight";



std::unique_ptr<Barfight> Barfight::createBarfight()
{
    std::unique_ptr<Barfight>BarfightCard(new Barfight());
    if (!BarfightCard)
    {
        throw std::bad_alloc();
    }
    return BarfightCard;
}

