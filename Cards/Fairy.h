#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Appliance.h"


class Fairy : public Appliance
{
    Fairy() = default;
    Fairy& operator=(const Fairy& fairy)=default;
    Fairy(const Fairy&) = default;
    ~Fairy();

    void applyEncounter(Player& player) override;


protected:
int healthHeal=10;

};


#endif HW4_FAIRY_H
