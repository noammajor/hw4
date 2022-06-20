#ifndef BATTLE_H_
#define BATTLE_H_
#include "Card.h"
//#include <string>
//#include <iostream>
//#include <fstream>


class Battle : public Card
{

protected:

    Battle(int force, int health, int loot);
    
   // ~Battle() override = default;

    void winBattle(Player& player,int loot);
    ~Battle()=default;
    virtual void loseBattle(Player& player,int health);
    void printCard(std::ostream& os) const override;

    std::string getType() const override = 0;
    bool applyEncounter(Player& player) override;

    //friend  std::ostream& operator<<(std::ostream& os, const Battle& card);
public:
    int getdamage() const;
private:
    int const m_battleForce;
    int const m_healthLose;
    int const m_gainedLoot;

};

#endif
