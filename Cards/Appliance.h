#ifndef APPLIANCE_H_
#define APPLIANCE_H_
#include "Card.h"
class Appliance :public Card
{
    Appliance()=default;

    ~Appliance()=default;

    virtual void applyEncounter(Player& player)=0;

protected:
    int const m_hpEffect=10;

};
#endif
