#ifndef HW4_GANG_H
#define HW4_GANG_H
#include "Card.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"

class Gang : public Card
{
public:
     explicit Gang(std::ifstream& cards);
    ~Gang() override= default;
    void applyEncounter(Player& player) override;

    static  std::unique_ptr<Gang> createGang(std::ifstream& cards);

    std::string getType() const override;


private:


};


#endif //HW4_BARFIGHT_H
