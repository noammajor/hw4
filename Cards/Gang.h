#ifndef HW4_GANG_H
#define HW4_GANG_H
#include "Card.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include <deque>
#include <map>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>

class Gang : public Card
{
public:
     explicit Gang(std::ifstream& cards);
    ~Gang() override= default;
    void applyEncounter(Player& player) override;

    static  std::unique_ptr<Gang> createGang(std::ifstream& cards);

    std::string getType() const override;


private:
    std::deque<std::unique_ptr<Card>> m_cardsDeque;

};


#endif //HW4_BARFIGHT_H
