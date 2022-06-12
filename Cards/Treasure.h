#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H


class Treasure : public Appliance
{
    Treasure() = default;
    ~Treasure() = default;

    void applyEncounter(std::unique_ptr<Player>) override;


protected:


};


#endif //HW4_TREASURE_H
