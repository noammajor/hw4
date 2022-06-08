#ifndef BATTLE_H_
#define BATTLE_H_
#include "Card.h"

class Battle : public Card
{
    Battle(int force, int health, int loot);
    
    ~Battle()=default;

    void applyEncounter(Player& player) override;

    void winbattle(Player& player);

    void losebattle(Player& player);

protected:
    int m_battleForce;
    int m_healthLose;
    int m_gainedLoot;
}

#endif
