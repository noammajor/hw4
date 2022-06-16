#ifndef WIZARD_H_
#define WIZARD_H_
#include "Player.h"
#include <memory>
#include "utilities.h"


class Wizard: public Player
{

public:
    Wizard(const std::string &name);
    ~Wizard() override = default;
    void heal(int HpToHeal) override;
    static std::unique_ptr<Wizard> createWizard(const std::string &name);

    void print(std::ostream& os) const override;

private:
    const static std::string WIZARD;

};
#endif
