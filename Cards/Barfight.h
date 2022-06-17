#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H
#include "Appliance.h"

class Barfight : public Appliance
{

public:
     explicit Barfight()=default;
    ~Barfight() = default;
    void applyEncounter(Player& player) override;
    static  std::unique_ptr<Barfight> createBarfight();
    std::string getType() const override;


private:
    static const int GIVEDAMAGE=10;
    const std::string type = "Barfight";

};


#endif //HW4_BARFIGHT_H
