#include "Wizard.h"
#include "Player.h"
#include "utilities.h"


Wizard::Wizard(const std::string &name) :  Player(name)
{
}


void Wizard::heal(int HpToHeal)
{
    m_playerhealthpoints += 2*HpToHeal;
}


std::unique_ptr<Wizard> Wizard::createWizard(const std::string &name)
{
    std::unique_ptr<Wizard> wizardCard(new Wizard(name));
    if (!wizardCard)
    {
        throw std::bad_alloc();
    }
    return wizardCard;
}


void Wizard::print() const
{
    printPlayerDetails(std::cout, m_name, WIZARD, m_level, m_force, m_playerhealthpoints.getHP(), m_coins);
}
