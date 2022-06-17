#include "Battle.h"

Battle::Battle(int force, int health, int loot) : m_battleForce(force),m_healthLose(health),m_gainedLoot(loot)
{
}


void Battle::applyEncounter(Player& player)
{
    if (player.getAttackStrength() >= m_battleForce)
    {
        winBattle( player, m_gainedLoot);
        return;
    }
    else
        loseBattle( player,m_healthLose);
}


void Battle::winBattle(Player& player, int loot)
{
    player.levelUp();
    player.addCoins(loot);
    printWinBattle(player.getName(), getType());
}


void Battle::loseBattle(Player &player, int health)
{
    player.damage(health);
    printLossBattle(player.getName(),getType());
}

void Battle::printCard(std::ostream& os) const
{
    printCardDetails(std::cout,getType());
    bool isDragon=false;
    if(getType() == "Dragon")
    {
        isDragon = true;
    }
     printMonsterDetails(std::cout,  m_battleForce,  m_healthLose,  m_gainedLoot,  isDragon);
     printEndOfCardDetails(std::cout);
}