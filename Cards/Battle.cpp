#include "Battle.h"
#include "Player.h"

Battle::Battle(int force, int health, int loot, std::string) : m_battleForce(force),m_healthLose(health),m_gainedLoot(loot)
{
}


void Battle::applyEncounter(std::unique_ptr<Player>)
{
    if (player->getAttackStrength()>=m_battleForce)
    {
        winBattle( *player, m_gainedLoot);
        return;
    }
    else
        loseBattle( *player,m_healthLose);
}


void Battle::winBattle(Player& player, int loot)
{
    player.levelUp();
    player.addCoins(loot);
    printWinBattle(player.getname(), m_monster);
    if(player.getLevel()==10)
    {
    //leadership board

    }

}


void Battle::loseBattle(Player &player, int health)
{
    player.damage(health);
    printLossBattle(player.getname(),m_monster);
    if(player.isKnockedOut())
    {
        //leadership board
    }
}
