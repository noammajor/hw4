#include "Appliance.h"

void Appliance::printCard()
{
    printCardDetails(std::cout, gettype());
    printEndOfCardDetails(std::cout);
}


