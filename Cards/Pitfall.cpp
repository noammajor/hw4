#include "Pitfall.h"


void Pitfall::applyEncounter(Player& player)
{
    bool isRogue=true;
    if(player.getName() != "Rogue")
    {
        player.damage(GIVE_DAMAGE);
        isRogue=false;
    }
    printPitfallMessage( isRogue);
}


std::unique_ptr<Pitfall> Pitfall::createPitfall()
{
    std::unique_ptr<Pitfall> pitfallCard(new Pitfall());
    if (!pitfallCard)
    {
        throw std::bad_alloc();
    }
    return pitfallCard;
}
std::string Pitfall::getType() const
{
    return type;
}

