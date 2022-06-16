#include "Pitfall.h"


void Pitfall::applyEncounter(std::unique_ptr<Player> player)
{
    if(player->getName() == "Rogue")
    {
        return;
    }
    else
        player->damage(GIVE_DAMAGE);
}


std::unique_ptr<Pitfall> Pitfall::createPitfall()
{
    std::unique_ptr<Pitfall>PitfallCard(new Pitfall());
    if (!PitfallCard)
    {
        throw std::bad_alloc();
    }
    return PitfallCard;
}
std::string Pitfall::gettype()
{
    return type;
}

