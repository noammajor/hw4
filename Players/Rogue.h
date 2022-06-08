#include "Player.h"
#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H


class Rogue  : public Player
{
    Rogue(const std::string &name);
    ~Rogue();
    void addCoins(int coinsToAdd) override;


private:
    const static std::string ROGUE = Rogue;



};


#endif //HW4_ROGUE_H
