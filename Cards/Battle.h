#ifndef BATTLE_H_
#define BATTLE_H_
#include "Card.h"

class Battle : public Card
{
    Battle(int force, int health, int loot);
    
    //~Battle()=default;

  //  void applyEncounter(Player& player) override;

    void winbattle(Player& player,int loot);

    void losebattle(Player& player);

protected:
    int static const m_battleForce;
    int static const m_healthLose;
    int static const m_gainedLoot;
}

#endif
