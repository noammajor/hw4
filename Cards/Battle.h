#ifndef BATTLE_H_
#define BATTLE_H_
#include "Card.h"
#include <string>


class Battle : public Card
{

protected:

    Battle(int force, int health, int loot);
    
    ~Battle() override = default;

    void applyEncounter(std::unique_ptr<Player>) override;

    void winBattle(Player& player,int loot);

    void loseBattle(Player& player,int health);
    void printCard(std::ostream& os) const override;

    virtual std::string getType() const = 0;

private:
    int const m_battleForce;
    int const m_healthLose;
    int const m_gainedLoot;

};

#endif
