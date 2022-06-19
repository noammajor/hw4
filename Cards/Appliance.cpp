#include "Appliance.h"

void Appliance::printCard(std::ostream& os) const
{
    printCardDetails(os, getType());
    printEndOfCardDetails(os);
}

/*
std::ostream& operator<<(std::ostream& os, const Appliance& card)
{
    printCardDetails(os, card.getType());
    printEndOfCardDetails(os);
    return os;
}*/
