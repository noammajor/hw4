#ifndef APPLIANCE_H_
#define APPLIANCE_H_
#include "Card.h"
//#include <string>
class Appliance :public Card
{
public:
    Appliance() = default;
    ~Appliance() override = default;
    //virtual void applyEncounter(std::unique_ptr<Player> player)=0;
    void printCard(std::ostream& os) const override;
    std::string getType() const override = 0;

    //friend  std::ostream& operator<<(std::ostream& os, const Appliance& card);

private:

};
#endif
