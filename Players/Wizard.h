#ifndef WIZARD_H_
#define WIZARD_H_

#include <memory>
#include "../utilities.h"


class Wizard: public Player
{

public:
    /*
    * C'tor of Wizard class
    */
    explicit Wizard(const std::string &name);

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Wizard() override = default;
    Wizard(const Wizard&) = default;
    Wizard& operator=(const Wizard&) = default;

    /*
    * heals the players and add to his HP during the game
    */
    void heal(int HpToHeal) override;

    /*
    * returns  a unique_ptr to a new Wizard player
    * @param name - the requested name for  the new player
    */
    static std::unique_ptr<Wizard> createWizard(const std::string &name);

    /*
    *returns players type
    */
    std::string getType() const override;

    /*
    *prints the players details to the screen
    */
    void print() const override;


private:
    static const std::string WIZARD;

};

#endif
