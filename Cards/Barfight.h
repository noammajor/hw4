#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H
#include "Appliance.h"

class Barfight : public Appliance
{
public:
    Barfight() = default;
    ~Barfight();

    void applyEncounter(std::unique_ptr<Player>) override;


protected:


};


#endif //HW4_BARFIGHT_H
