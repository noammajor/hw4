#include "Pitfall.h"


void Pitfall::applyEncounter(Player& player)
{
    if(player.getName() == "Rogue")
    {
        return;
    }
    else
        player.damage(GIVE_DAMAGE);
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

