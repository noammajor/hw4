#include "Battle.h"

Battle::Battle(int force,int health,int loot)
{
     m_battleForce=force;
     m_healthLose=health;
     m_gainedLoot=loot;
}
void Battle::applyEncounter(Player &player)
{
    if (player.getAttackStrength()>=m_battleForce)
    {
        winbattle(Player& player,int m_gainedLoot);
        return;
    }
    else
        losebattle(Player& player,int m_healthLose);
    return;

}

void Battle::winbattle(Player& player, int loot)
{
player.levelUp();
player.addCoins(loot);
printWinBattle(player.m_name, m_monster);
if(player.getLevel()==10)
{
    //leadership board

}
return;
}
void Battle::losebattle(Player &player, int health)
{
    player.damage(health);
    printLossBattle(player.m_name,m_monster);
    if(player.isKnockedOut())
    {
        //leadership board
    }
    return;
}
