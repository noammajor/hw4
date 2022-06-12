#include "Barfight.h"
#include "Player.h"


void Barfight::applyEncounter(std::unique_ptr<Player>)
{
    if(player->getname().compare("Fighter"))
    {
        return;
    }
    else
    {
        player.damage(m_hpEffect);
    }
    return;
}
Barfight::Barfight(int damage)
{
    GiveDamage=damage;
};


