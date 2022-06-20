#include "Gang.h"

std::string Gang::getType() const
{
    return TYPE;
}


Gang::Gang(std::ifstream& cards, int& linesCounter) : m_battleMap (initializeBattleMap())
{
    std::string line;
    std::deque<std::unique_ptr<Card>> cardsDeque;
    while (getline(cards, line))
    {
        if (line.empty())
        {
            throw DeckFileFormatError(linesCounter);
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
                return;
            default:
                throw DeckFileFormatError(linesCounter);
        }
    }
}


bool Gang::applyEncounter(Player& player)
{
    bool lose=false;
    for (int i=0;i<m_cardsDeque.size();i++)
    {
        std::unique_ptr<Card> currentCard = move(m_cardsDeque.front());
        if(lose)
        {
            switch (m_battleMap[currentCard->getType()])
            {
                case Dragon:
                    player.heal(DRAGONDAMAGE);

                    break;
                case Goblin:
                    player.heal(GOBLINDAMAGE);
                    break;
                case Vampire:
                    player.heal(VAMPIREDAMAGE);
                    break;
            }
        }
        m_cardsDeque.pop_front();
        lose=currentCard->applyEncounter(player);
        m_cardsDeque.push_back(move(currentCard));
    }


}
