#include "Vampire.h"

Vampire::Vampire(): Battle(VAMPIRE_FORCE,VAMPIRE_DAMAGE,VAMPIRE_COINS,TYPE_MONSTER)
{
};
std::unique_ptr<Vampire> createVampire()
{
    std::unique_ptr<Vampire>VampireCard(new Vampire());
    return VampireCard;
}
