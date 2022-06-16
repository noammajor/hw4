#include "Dragon.h"


Dragon::Dragon(): Battle(DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_COINS,TYPE_MONSTER)
{
}


std::unique_ptr<Dragon> Dragon::createDragon()
{
    std::unique_ptr<Dragon>DragonCard(new Dragon());
    return DragonCard;
}
