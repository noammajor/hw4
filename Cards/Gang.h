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
     Gang(std::ifstream& cards, int& linesCounter);
    ~Gang() override= default;
    bool applyEncounter(Player& player) override;

    static  std::unique_ptr<Gang> createGang(std::ifstream& cards, int& linesCounter);

    std::string getType() const override;


private:

    static std::map <std::string, int> initializeBattleMap();

    enum jobs
    {
        Dragon=1,
        Vampire,
        Goblin
    };

    std::deque<std::unique_ptr<Card>> m_cardsDeque;
     const std::string TYPE ="Gang";
    int static const DRAGONDAMAGE = -100;
    int static const VAMPIREDAMAGE = 10;
    int static const GOBLINDAMAGE = 10;


};


#endif //HW4_BARFIGHT_H
