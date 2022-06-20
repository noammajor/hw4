#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Appliance.h"
//#include <iostream>
//#include <memory>
//#include "../Players/Player.h"


class Fairy : public Appliance
{
public:
    explicit Fairy() = default;
    ~Fairy()override = default;
    static std::unique_ptr<Fairy> createFairy();
    void applyEncounter(Player& player) override;
    std::string getType() const override;


private:
    static const int HEALTH_HEAL = 10;
    const std::string type = "Fairy";

};


#endif //HW4_FAIRY_H
