#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H
#include "Appliance.h"


class Merchant : public Appliance
{

public:
    /*
* C'tor of Merchant class
*Default
*@return A new instance of Merchant.
*/
     explicit Merchant() = default;
    /*
  * D'tor of Merchant class
  *
  *Default
  * destroys Merchant
  */
    ~Merchant()override = default;
    /*
 *  Applies each Cards effect on Player- give player options to buy
 *  prints the exchange
 *  @param player- player who turn it is on the card
 *  @return false always
 */
    bool applyEncounter(Player& player) override;
/*
*  Creates and returns a unique pointer to new instance of Merchant
*  @return unique point
 *  */
static std::unique_ptr<Merchant> createMerchant();
    /*
   *  Gives us the Type of the card
   *  @return string "Merchant"
   */
std::string getType() const override;


private:
static const int HP_COST = 5;
static const int FORCE_COST = 10;
static const int BUY_NOTHING = 0;
static const int BUY_HP = 1;
static const int BUY_FORCE = 2;
static const int INVALID_INPUT=-1;
const std::string type = "Merchant";


};


#endif //HW4_MERCHANT_H
