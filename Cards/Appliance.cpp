#include "Appliance.h"


void Appliance::printCard(std::ostream& os) const
{
    printCardDetails(os, getType());
    printEndOfCardDetails(os);
}
