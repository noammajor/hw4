#include "Pitfall.h"
#include "Player.h"
void Pitfall::applyEncounter(std::unique_ptr<Player>)
{
    if(player.getname().compare("Rogue"))
    {
        return;
    }
    else
        //look at later
        player.damage(m_hpEffect);

}
Pitfall::Pitfall(int damage)
{
  giveDamage=10;
}

