#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H
#include <iostream>
#include "Player.h"

class Fighter  : public Player
{

public:
    int getAttackStrength() const override;

    explicit Fighter(const std::string &name);

    ~Fighter();

private:
    const static  std::string FIGHTER = Fighter;



};













#endif //HW4_FIGHTER_H
