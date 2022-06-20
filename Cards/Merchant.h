#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H
#include "Appliance.h"


class Merchant : public Appliance
{

public:
     explicit Merchant() = default;
    ~Merchant()override = default;

    bool applyEncounter(Player& player) override;
    static std::unique_ptr<Merchant> createMerchant();
    std::string getType() const override;


private:
    static const int HP_COST = 5;
    static const int FORCE_COST = 10;
    static const int BUY_NOTHING = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;
    const std::string type = "Merchant";


};


#endif //HW4_MERCHANT_H
