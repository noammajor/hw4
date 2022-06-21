#include "Vampire.h"


const std::string Vampire::VAMPIRE = "Vampire";

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


std::string Vampire::getType() const
{
    return VAMPIRE;
}