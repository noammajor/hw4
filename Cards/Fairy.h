#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Appliance.h"


class Fairy : public Appliance
{
public:
    explicit Fairy() = default;
    Fairy& operator=(const Fairy& fairy) = default;
    Fairy(const Fairy&) = default;
    ~Fairy()override = default;
    static std::unique_ptr<Fairy> createFairy();

    void applyEncounter(std::unique_ptr<Player> player) override;


private:
    static const int HEALTH_HEAL=10;

};


#endif //HW4_FAIRY_H
