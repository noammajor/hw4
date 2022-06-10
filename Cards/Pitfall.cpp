#include "Pitfall.h"
#include "Player.h"
void Pitfall::applyEncounter(Player& player)
{
    if(player.getname().compare("Rogue"))
    {
        return;
    }
    else
        //look at later
        player.damage(m_hpEffect);
        return;
}


