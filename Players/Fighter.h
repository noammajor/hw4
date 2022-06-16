#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H
#include <iostream>
#include "Player.h"
#include <memory>

class Fighter  : public Player
{

public:
    int getAttackStrength() const override;

    explicit Fighter(const std::string &name);

    ~Fighter() override = default;
    static std::unique_ptr<Fighter> createFighter(const std::string &name);

    void print(std::ostream& os) const override;

private:
    const std::string FIGHTER = "Fighter";



};


#endif //HW4_FIGHTER_H
