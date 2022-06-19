#ifndef BATTLE_H_
#define BATTLE_H_
#include "Card.h"
#include <string>
#include <iostream>
#include <fstream>


class Battle : public Card
{

protected:

    Battle(int force, int health, int loot);
    
    ~Battle() override = default;

    void applyEncounter(Player& player) override;

    void winBattle(Player& player,int loot);

    void loseBattle(Player& player,int health);
    void printCard(std::ostream& os) const override;

    virtual std::string getType() const = 0;

    //friend  std::ostream& operator<<(std::ostream& os, const Battle& card);

private:
    int const m_battleForce;
    int const m_healthLose;
    int const m_gainedLoot;

};

#endif
