#include "Wizard.h"
#include "Player.h"


Wizard::Wizard(const std::string &name) :  Player(name, WIZARD)
{
}


void Player::heal(int HpToHeal)
{
    m_playerhealthpoints += 2*HpToHeal;
}
