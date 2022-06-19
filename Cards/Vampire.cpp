#include "Vampire.h"


Vampire::Vampire(): Battle(VAMPIRE_FORCE,VAMPIRE_DAMAGE,VAMPIRE_COINS)
{
}


std::unique_ptr<Vampire> Vampire::createVampire()
{
    std::unique_ptr<Vampire>VampireCard(new Vampire());
    return VampireCard;
}
void Vampire::loseBattle(Player &player, int health)
{
    player.damage(health);
    player.buff(VAMPIRE_FORCE_LOSS);
    printLossBattle(player.getName(),getType());
}


//const std::string Vampire::TYPE_MONSTER = "Vampire";


std::string Vampire::getType() const
{
    return TYPE_MONSTER;
}