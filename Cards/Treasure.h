#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H
#include "Appliance.h"
#include "Card.h"

class Treasure : public Appliance
{
public:
    explicit Treasure(int payment = 10);
    ~Treasure() override = default;

    void applyEncounter(std::unique_ptr<Player> player) override;
    std::unique_ptr<Treasure> createTreasure();


private:
    int giveTreasure;

};


#endif //HW4_TREASURE_H
