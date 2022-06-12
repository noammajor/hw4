#include "Fairy.h"
void Fairy::applyEncounter(Player& player)
{
    if(player.getname().compare("Wizard"))
    {
        //look at later
        player.heal(healthHeal);
    }
    else
        return;
}
Fairy::Fairy(int heal)
{
    healthHeal=heal;
}