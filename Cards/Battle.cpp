#include "Battle.h"


Battle::Battle(int force, int health, int loot) : m_battleForce(force),m_healthLose(health),m_gainedLoot(loot)
{
}


bool Battle::applyEncounter(Player& player)
{
    bool victory = true;
    if (player.getAttackStrength() >= m_battleForce)
    {
        winBattle( player, m_gainedLoot);
    }
    else
    {
        loseBattle (player,m_healthLose);
        victory = false;
    }
    return victory;
}


void Battle::winBattle(Player& player, int loot)
{
    player.addCoins(loot);
}


void Battle::loseBattle(Player &player, int healthLose)
{
    player.damage(healthLose);
    printLossBattle(player.getName(),getType());
}


void Battle::printCard(std::ostream& os) const
{
    printCardDetails(os,getType());
    bool isDragon = false;
    if(getType() == "Dragon")
    {
        isDragon = true;
    }
     printMonsterDetails(os,  m_battleForce,  m_healthLose,  m_gainedLoot,  isDragon);
     printEndOfCardDetails(os);
}