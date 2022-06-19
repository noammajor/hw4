#ifndef VAMPIRE_H_
#define VAMPIRE_H_
#include "Battle.h"

class Vampire: public Battle
{
public:
    explicit Vampire();
    ~Vampire() override = default;
    static std::unique_ptr<Vampire> createVampire();

    std::string getType() const override;
    void loseBattle(Player& player,int health) override;

private:
    const std::string TYPE_MONSTER = "Vampire";
    int  static const VAMPIRE_DAMAGE = 10;
    int  static const VAMPIRE_COINS = 2;
    int static const VAMPIRE_FORCE = 10;
    int  static const VAMPIRE_FORCE_LOSS = -1;

};
#endif

