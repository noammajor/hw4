#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Appliance.h"


class Fairy : public Appliance
{
public:
    Fairy(int heal=10);
    Fairy& operator=(const Fairy& fairy)=default;
    Fairy(const Fairy&) = default;
    ~Fairy()override=default;

    void applyEncounter(Player& player) override;


protected:
int healthHeal;

};


#endif HW4_FAIRY_H
