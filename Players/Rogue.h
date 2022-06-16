#include "Player.h"
#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H
#include <memory>
#include <string>

class Rogue  : public Player
{
public:
    explicit Rogue(const std::string &name);
    ~Rogue() override = default;
    void addCoins(int coinsToAdd)  override;

    static std::unique_ptr<Rogue> createRogue(const std::string &name);

    void print() const override;

private:
    const std::string ROGUE = "Rogue";



};


#endif //HW4_ROGUE_H
