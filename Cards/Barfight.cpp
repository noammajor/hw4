#include "Barfight.h"
#include "Player.h"


void Barfight::applyEncounter(std::unique_ptr<Player>)
{
    if(player->getname().compare("Fighter"))
    {
        return;
    }
    else {
        //look at later
//        player.damage(m_hpEffect);
        return;
    }
}


