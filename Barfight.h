#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

class Barfight : public Appliance
{
    Barfight() = default;
    ~Barfight() = default;

    void applyEncounter(Player& player) override;


protected:


};


#endif //HW4_BARFIGHT_H
