#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H
#include "Appliance.h"
#include "Card.h"
#include "Player.h"

class Treasure : public Appliance
{
public:
    explicit Treasure() = default;
    ~Treasure() override = default;
    void applyEncounter(std::unique_ptr<Player> player) override;
    static std::unique_ptr<Treasure> createTreasure();

private:
    static const int LOOT = 10;

};


#endif //HW4_TREASURE_H
