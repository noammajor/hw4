#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H

#include "Appliance.h"


class Treasure : public Appliance
{

public:
    /*
    * C'tor of Treasure class
    */
    explicit Treasure() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Treasure() override = default;
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure&) = default;

    /*
    * Handling the player's encounter with the card:
    *
    * @param player - The player.
    * @return bool - true if the player won a battle
    *
    */
    bool applyEncounter(Player& player) override;

    /*
    * returns  a unique_ptr to a new Treasure card
    */
    static std::unique_ptr<Treasure> createTreasure();

    /*
    *returns the cards type
    */
    std::string getType() const override;

private:
    static const int LOOT = 10;
    static  const std::string TREASURE;

};

#endif //HW4_TREASURE_H
