#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H
#include "Card.h"

class Gang : public Card
{
public:
     explicit Gang()=default;
    ~Gang() override= default;
    void applyEncounter(Player& player) override;
    static  std::unique_ptr<Gang> createGang();
    std::string getType() const override;

private:
    std::deque<std::unique_ptr<Battle>> m_gang;


};


#endif //HW4_BARFIGHT_H
