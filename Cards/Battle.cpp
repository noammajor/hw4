#include "Battle.h"

//using namespace std;
Battle::Battle(int force, int health, int loot) : m_battleForce(force),m_healthLose(health),m_gainedLoot(loot)
{
}
int Battle::getdamage() const
{
    return m_healthLose;
}

bool Battle::applyEncounter(Player& player)
{
    if (player.getAttackStrength() >= m_battleForce)
    {
        winBattle( player, m_gainedLoot);
        return true;
    }
    else
        loseBattle( player,m_healthLose);
    return false;
}


void Battle::winBattle(Player& player, int loot)
{
    player.addCoins(loot);
}


void Battle::loseBattle(Player &player, int health)
{
    player.damage(health);
    printLossBattle(player.getName(),getType());
}

void Battle::printCard(std::ostream& os) const
{
    printCardDetails(os,getType());
    bool isDragon=false;
    if(getType() == "Dragon")
    {
        isDragon = true;
    }
     printMonsterDetails(os,  m_battleForce,  m_healthLose,  m_gainedLoot,  isDragon);
     printEndOfCardDetails(os);
}

/*
std::ostream& operator<<(std::ostream& os, const Battle& card)
{
    printCardDetails(os,card.getType());
    bool isDragon=false;
    if(card.getType() == "Dragon")
    {
        isDragon = true;
    }
    printMonsterDetails(os,  card.m_battleForce,  card.m_healthLose,  card.m_gainedLoot,  isDragon);
    printEndOfCardDetails(os);
    return os;
}*/