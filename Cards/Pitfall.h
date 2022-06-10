#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H
#include "Appliance.h"

class Pitfall : public Appliance
{
    Pitfall() = default;
    Pitfall& operator=(const Pitfall& fairy)=default;
    Pitfall(const Pitfall&) = default;
    ~Pitfall();
    void applyEncounter(Player& player) override;


protected:

};


#endif //HW4_PITFALL_H
