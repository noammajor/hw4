#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H

#include <memory>
#include "../utilities.h"


class Rogue  : public Player
{

public:
    /*
    * C'tor of Rogue class
    */
    explicit Rogue(const std::string &name);

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Rogue() override = default;
    Rogue(const Rogue&) = default;
    Rogue& operator=(const Rogue&) = default;

    /*
    * adds coins after getting a suitable card
    */
    void addCoins(int coinsToAdd)  override;

    /*
    * returns  a unique_ptr to a new Rogue player
    * @param name - the requested name for  the new player
    */
    static std::unique_ptr<Rogue> createRogue(const std::string &name);

    /*
    *returns players type
    */
    std::string getType() const override;

    /*
    *prints the players details to the screen
    */
    void print() const override;

private:
    static const std::string ROGUE;

};

#endif //HW4_ROGUE_H
