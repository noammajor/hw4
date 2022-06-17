#include "Card.h"
/*Card::Card()
{
}


Card::~Card()
{
}*/
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printCard(os);
    return os;
}