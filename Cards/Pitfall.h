#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H

#include "Appliance.h"


class Pitfall : public Appliance
{

public:
    /*
    * C'tor of Pitfall class
    */
    explicit Pitfall() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Pitfall()override = default;
    Pitfall(const Pitfall&) = default;
    Pitfall& operator=(const Pitfall&) = default;

    /*
    * returns  a unique_ptr to a new Pitfall card
    */
    static std::unique_ptr<Pitfall> createPitfall();

    /*
    * Handling the player's encounter with the card:
    *
    * @param player - The player.
    * @return bool - true if the player won a battle
    *
    */
    bool applyEncounter(Player& player) override;

    /*
    *returns the cards type
    */
    std::string getType() const override;

private:
    static const int GIVE_DAMAGE = 10;
    static const std::string PITFALL;

};


#endif //HW4_PITFALL_H
