#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H
#include "Appliance.h"

class Pitfall : public Appliance
{
public:
    Pitfall(int damage=10);
    Pitfall& operator=(const Pitfall& fairy)=default;
    Pitfall(const Pitfall&) = default;
    ~Pitfall()override=default;
    std::unique_ptr<Pitfall> createPitfall();
    void applyEncounter(std::unique_ptr<Player> player) override;


private:
int giveDamage;
};


#endif //HW4_PITFALL_H
