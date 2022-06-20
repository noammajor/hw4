#include "Gang.h"


static  std::deque<unique_ptr<Gang>> Gang::Gang(std::ifstream& cards) {
    std::string line;
    std::deque<std::unique_ptr<Card>> cardsDeque;
    while (getline(cards, line)) {
        if (line.empty()) {
            break;
        }
        switch (m_cardsMap[line])
        {
            case Dragon:
                cardsDeque.push_back(Dragon::createDragon());
                break;
            case Vampire:
                cardsDeque.push_back(Vampire::createVampire());
                break;
            case Goblin:
                cardsDeque.push_back(Goblin::createGoblin());
                break;
            case EndGang:
                return cardsDeque;
                break;
            default:
                throw DeckFileFormatError(cardsQueue.size()+1);  //exception?
        }
    }
}

std::unique_ptr<Gang> Gang::createGang(std::ifstream &cards)
{
    std::unique_ptr<Gang> gangCard(new Gang(cards));
}