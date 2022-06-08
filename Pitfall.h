#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H


class Pitfall : public Appliance
{
    Pitfall() = default;
    ~Pitfall() = default;


    void applyEncounter(Player& player) override;


protected:

};


#endif //HW4_PITFALL_H
