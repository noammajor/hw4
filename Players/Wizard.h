#ifndef WIZARD_H_
#define WIZARD_H_
//#include "Player.h"
#include <memory>
#include "../utilities.h"


class Wizard: public Player
{

public:
    explicit Wizard(const std::string &name);
    ~Wizard() override = default;
    void heal(int HpToHeal) override;
    static std::unique_ptr<Wizard> createWizard(const std::string &name);
    std::string getType() const override;
    void print() const override;


private:
    const std::string WIZARD = "Wizard";

};
#endif
