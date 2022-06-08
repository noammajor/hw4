#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H


class Rogue  : public Player
{

    void addCoins(int coinsToAdd) override;

    Rogue(std:string name);

    ~Rogue();

private:
    const static  std::string ROGUE = Rogue;



};


#endif //HW4_ROGUE_H
