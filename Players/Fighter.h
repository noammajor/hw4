#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

#include <memory>
#include "../utilities.h"


class Fighter  : public Player
{

public:
    /*
    * C'tor of Fighter class
    */
    explicit Fighter(const std::string &name);

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fighter() override = default;
    Fighter(const Fighter&) = default;
    Fighter& operator=(const Fighter&) = default;

    int getAttackStrength() const override;

    /*
    * returns  a unique_ptr to a new Fighter player
    * @param name - the requested name for  the new player
    */
    static std::unique_ptr<Fighter> createFighter(const std::string &name);

    /*
    *returns players type
    */
    std::string getType() const override;


    /*
    *prints the players details to the screen
    */
    void print() const override;


private:
    static const std::string FIGHTER;

};

#endif //HW4_FIGHTER_H
