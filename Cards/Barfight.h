#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H
#include "Appliance.h"

class Barfight : public Appliance
{
    Barfight(int damage=10);
    ~Barfight()=default;

    void applyEncounter(std::unique_ptr<Player>) override;


private:
    int GiveDamage;


};


#endif //HW4_BARFIGHT_H
