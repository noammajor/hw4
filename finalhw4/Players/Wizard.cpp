#include "Wizard.h"


const std::string Wizard::WIZARD = "Wizard";

Wizard::Wizard(const std::string &name) :  Player(name)
{
}


void Wizard::heal(int HpToHeal)
{
    m_healthpoints += 2 * HpToHeal;
}


std::string Wizard::getType() const
{
    return WIZARD;
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
    printPlayerDetails(std::cout, this->m_name, this->WIZARD, this->m_level,
                       this->m_force, this-> m_healthpoints.getHP(), this->m_coins);
}
