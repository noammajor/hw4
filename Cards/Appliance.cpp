#include "Appliance.h"

void Appliance::printCard(std::ostream& os) const
{
    printCardDetails(std::cout, getType());
    printEndOfCardDetails(std::cout);
}


