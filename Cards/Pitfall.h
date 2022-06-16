#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H
#include "Appliance.h"

class Pitfall : public Appliance
{
public:
    explicit Pitfall()=default;
    Pitfall& operator=(const Pitfall& fairy)=default;
    Pitfall(const Pitfall&) = default;
    ~Pitfall()override=default;
    static std::unique_ptr<Pitfall> createPitfall();
    void applyEncounter(std::unique_ptr<Player> player) override;

private:
    static const int GIVE_DAMAGE = 10;

};


#endif //HW4_PITFALL_H
