#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H

#include "Appliance.h"


/*
* Run Length Encoding List
*
* Implements a Merchant card of the mtmchkin game
*
* the following class is available:
* Merchant
*
* The following functions are available:
*
*/

class Merchant : public Appliance
{

public:
    /*
    * C'tor of Merchant class
    */
     explicit Merchant() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Merchant()override = default;
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant&) = default;

    /*
    * Handling the player's encounter with the card:
    *
    * @param player - The player.
    * @return bool - true if the player won a battle
    *
    */
    bool applyEncounter(Player& player) override;

    /*
    * returns  a unique_ptr to a new Merchant card
    */
    static std::unique_ptr<Merchant> createMerchant();

    /*
    *returns the cards type
    */
    std::string getType() const override;


private:
    static const int HP_COST = 5;
    static const int FORCE_COST = 10;
    static const int BUY_NOTHING = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;
    static const std::string MERCHANT;

};

#endif //HW4_MERCHANT_H
