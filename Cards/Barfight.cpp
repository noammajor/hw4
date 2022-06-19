#include "Barfight.h"




void Barfight::applyEncounter(Player& player)
{
    bool isFighter= true;
    if(player.getName() != "Fighter")
    {
        isFighter= false;
        player.damage(GIVEDAMAGE);
    }
    printBarfightMessage( isFighter);


}
std::string Barfight::getType() const
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

