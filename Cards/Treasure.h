#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H
#include "Appliance.h"
//#include "Card.h"
//#include "../Players/Player.h"

class Treasure : public Appliance
{
public:
    explicit Treasure() = default;
    ~Treasure() override = default;
    void applyEncounter(Player& player) override;
    static std::unique_ptr<Treasure> createTreasure();
    std::string getType() const override;

private:
    static const int LOOT = 10;
    const std::string type = "Treasure";

};


#endif //HW4_TREASURE_H
