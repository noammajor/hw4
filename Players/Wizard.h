#ifndef WIZARD_H_
#define WIZARD_H_
#include "Player.h"

class Wizard: public Player
{

    void heal(int HpToHeal) override;

    Wizard(std:string name);

    ~Wizard();

private:
const static  std::string WIZARD=Wizard;

};
#endif
