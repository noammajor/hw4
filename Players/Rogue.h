#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H
#include "Player.h"
#include <memory>
#include <string>
#include "../utilities.h"

class Rogue  : public Player
{
public:
    explicit Rogue(const std::string &name);
    ~Rogue() override = default;
    void addCoins(int coinsToAdd)  override;

    static std::unique_ptr<Rogue> createRogue(const std::string &name);
    std::string getType() const override;
    void print() const override;

private:
    const std::string ROGUE = "Rogue";



};


#endif //HW4_ROGUE_H
