#include "Player.h"
#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H

#include <string>

class Rogue  : public Player
{
public:
    Rogue(const std::string &name);
    ~Rogue();
    void addCoins(int coinsToAdd);


private:
    const static std::string ROGUE = "Rogue";



};


#endif //HW4_ROGUE_H
