#ifndef HW4_GANG_H
#define HW4_GANG_H
#include "Card.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include <deque>
#include <map>

class Gang : public Card
{
public:
     Gang(std::ifstream& cards, int& linesCounter);
    ~Gang() override= default;
    void applyEncounter(Player& player) override;

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


};


#endif //HW4_BARFIGHT_H
