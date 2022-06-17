#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H
#include "Appliance.h"

class Pitfall : public Appliance
{
public:
    explicit Pitfall()=default;
    ~Pitfall()override=default;
    static std::unique_ptr<Pitfall> createPitfall();
    void applyEncounter(Player& player) override;
    std::string getType() const;

private:
    static const int GIVE_DAMAGE = 10;
    const std::string type = "Pitfall";

};


#endif //HW4_PITFALL_H
