#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H
#include "Appliance.h"

class Barfight : public Appliance
{
    Barfight() = default;
    ~Barfight();

    void applyEncounter(Player& player) override;


protected:


};


#endif //HW4_BARFIGHT_H
