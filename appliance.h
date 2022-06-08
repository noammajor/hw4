#ifndef APPLIANCE_H_
#define APPLIANCE_H_
#include "Card.h"
class Appliance :public Card
{
    Appliance()=default;

    ~Appliance()=default;

    virtual void applyEncounter(Player& player);
protected:
    int static const m_hpEffect=10;
}
#endif
