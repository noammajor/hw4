#ifndef APPLIANCE_H_
#define APPLIANCE_H_
#include "Card.h"
class Appliance :public Card
{
public:
    Appliance()=default;
    virtual ~Appliance()=0;
    virtual void applyEncounter(std::unique_ptr<Player> player)=0;

protected:
};
#endif
