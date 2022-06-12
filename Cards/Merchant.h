#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H
#include "Player.h"
#include "utilities.h"
#include "Appliance.h"
using std::cout;

class Merchant : public Appliance
{
public:
    Merchant()=default;
    ~Merchant()override=default;

    void applyEncounter(Player& player) override;

protected:

private:
    static const int HP_COST = 5;
    static const int FORCE_COST = 10;
    static const int BUY_NOTHING = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;


};


#endif //HW4_MERCHANT_H
