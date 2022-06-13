#include "Pitfall.h"
#include "Player.h"
void Pitfall::applyEncounter(std::unique_ptr<Player> player)
{
    if(player->getName().compare("Rogue"))
    {
        return;
    }
    else
        //look at later
        player->damage(giveDamage);

}
Pitfall::Pitfall(int damage)
{
  giveDamage=10;
}

std::unique_ptr<Pitfall> createPitfall()
{
    std::unique_ptr<Pitfall>PitfallCard(new Pitfall());
    return PitfallCard;
}

