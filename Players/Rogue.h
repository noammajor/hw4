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
    void addCoins(int coinsToAdd);

    static std::unique_ptr<Rogue> createRogue(const std::string &name);

    void print(std::ostream& os) const override;

private:
    const static std::string ROGUE;



};


#endif //HW4_ROGUE_H
