#ifndef WIZARD_H_
#define WIZARD_H_
#include "Player.h"

class Wizard: public Player
{
public:
    Wizard(const std::string &name);
    ~Wizard();
    void heal(int HpToHeal) override ;


private:
const static std::string WIZARD = Wizard;

};
#endif
