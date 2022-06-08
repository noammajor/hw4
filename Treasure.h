#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H


class Treasure : public Appliance
{
    Treasure() = default;
    ~Treasure() = default;

    void applyEncounter(Player& player) override;


protected:


};


#endif //HW4_TREASURE_H
