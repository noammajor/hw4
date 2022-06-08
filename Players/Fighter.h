#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

class Fighter  : public Player
{

    Fighter(const std::string &name);
    ~Fighter();
    int getAttackStrength() const override;


private:
    const static std::string FIGHTER = Fighter;



};













#endif //HW4_FIGHTER_H
