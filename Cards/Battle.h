#ifndef BATTLE_H_
#define BATTLE_H_
#include "Card.h"
#include "string.h"
#include <string>

class Battle : public Card
{
public:
    Battle();

    Battle(int force,int health,int loot,std::string Type);
    
    ~Battle()=default;

    void applyEncounter(Player& player) override;

    void winbattle(Player& player,int loot);

    void losebattle(Player& player,int health);

protected:
    std::string const m_monster;
    int const m_battleForce;
    int const m_healthLose;
    int const m_gainedLoot;

};

#endif
