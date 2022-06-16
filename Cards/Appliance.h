#ifndef APPLIANCE_H_
#define APPLIANCE_H_
#include "Card.h"
#include <string>
class Appliance :public Card
{
public:
    Appliance();
    ~Appliance() override = default;
    virtual void applyEncounter(std::unique_ptr<Player> player)=0;
    void printCard() override;
    virtual std::string gettype();

private:

};
#endif
