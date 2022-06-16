#include "Wizard.h"
#include "Player.h"
#include "utilities.h"


Wizard::Wizard(const std::string &name) :  Player(name, WIZARD)
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


void Wizard::print(std::ostream& os) const
{
    printPlayerDetails(os, m_name, m_job, m_level, m_force, m_playerhealthpoints.getHP(), m_coins);
}
