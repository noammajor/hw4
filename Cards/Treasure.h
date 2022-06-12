#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H
#include "Appliance.h"
#include "Card.h"

class Treasure : public Appliance
{
public:
    Treasure();
    ~Treasure();

    void applyEncounter(Player& player) override;


protected:


};


#endif //HW4_TREASURE_H
