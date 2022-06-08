#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H


class Merchant : public Appliance
{
    Merchant() = default;
    ~Merchant() = default;

    void applyEncounter(Player& player) override;

    void applyBuff (Player& player);
    void applyHeal (Player& player);

protected:

private:
    static const int HP_COST = 5;
    static const int FORCE_COST = 10;
    static const int BUY_NOTHING = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;


};


#endif //HW4_MERCHANT_H
