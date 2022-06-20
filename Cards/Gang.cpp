#include "Gang.h"

void Gang::applyEncounter(Player& player)
{
    bool lose=false;
    for (int i=0;i<m_cardsDeque.size();i++)
    {
        std::unique_ptr<Card> currentCard = move(m_cardsDeque.front());
        if(lose)
        {
            switch (battl)
            {

            }
            player.heal(currentCard)

        }
        m_cardsDeque.pop_front();
        currentCard->applyEncounter(player);
        m_cardsDeque.push_back(move(currentCard));
    }


}
/*
static  std::deque<unique_ptr<Gang>> Gang::Gang(std::ifstream& cards)
{
    std::string line;
    std::deque<std::unique_ptr<Card>> cardsDeque;
    while (getline(cards, line)) {
        if (line.empty()) {
            break;
        }
        switch (m_battleMap[line])
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
                throw DeckFileFormatError(linesCounter);  //exception?
        }
    }
}

std::unique_ptr<Gang> Gang::createGang(std::ifstream &cards, int& linesCounter)
{
    std::unique_ptr<Gang> gangCard(new Gang(cards, linesCounter));
}


std::map <std::string, int> Gang::initializeBattleMap()
{
    std::map<std::string, int> battleCards =
            {
                    {"Dragon", Dragon},
                    {"Vampire", Vampire},
                    {"Goblin", Goblin}
            };
    return battleCards;
}

