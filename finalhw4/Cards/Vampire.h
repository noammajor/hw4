#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "Battle.h"


class Vampire: public Battle
{

public:
    /*
    * C'tor of Vampire class
    */
    explicit Vampire();

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Vampire() override = default;
    Vampire(const Vampire&) = default;
    Vampire& operator=(const Vampire&) = default;

    /*
    * returns  a unique_ptr to a new Vampire card
    */
    static std::unique_ptr<Vampire> createVampire();

    /*
    *returns the cards type
    */
    std::string getType() const override;

    /*
    * apply the vampire effect on the player in a case he was defeated
    */
    void loseBattle(Player& player,int health) override;

private:
    static const std::string VAMPIRE;
    int  static const VAMPIRE_DAMAGE = 10;
    int  static const VAMPIRE_COINS = 2;
    int static const VAMPIRE_FORCE = 10;
    int  static const VAMPIRE_FORCE_LOSS = -1;

};

#endif

