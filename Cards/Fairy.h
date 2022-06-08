#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H


class Fairy : public Appliance
{
    Fairy() = default;
    ~Fairy() = default;

    void applyEncounter(Player& player) override;


protected:


};


#endif //HW4_FAIRY_H
