#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H
#include "Appliance.h"
#include "Card.h"

class Treasure : public Appliance
{
public:
    Treasure(int payment=10);
    ~Treasure() override=default;

    void applyEncounter(Player& player) override;


private:
    int giveTreasure;

};


#endif //HW4_TREASURE_H
