#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

class Fighter  : public Player
{

    int getAttackStrength() const;

    Fighter(std::string name);

    ~Fighter();

private:
    const static  std::string FIGHTER = "Fighter";



};













#endif //HW4_FIGHTER_H
