#include "Gang.h"



Gang::Gang(std::ifstream& cards, int* linesCounter) : m_battleMap (initializeBattleMap())
{
    m_cardsDeque = initializeBattleQueue(cards, linesCounter);
}


std::deque<std::unique_ptr<Card>> Gang::initializeBattleQueue(std::ifstream& cards, int* linesCounter)
{
    std::string line;
    std::deque<std::unique_ptr<Card>> cardsDeque;
    while (getline(cards, line))
    {
        if (line.empty())
        {
            throw DeckFileFormatError(*linesCounter);
        }
        linesCounter++;
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
            default:
                throw DeckFileFormatError(*linesCounter);
        }
    }
    return cardsDeque;
}



bool Gang::applyEncounter(Player& player)
{
    bool lose = false;
    std::unique_ptr<Card> currentCard;
    int i = m_cardsDeque.size();
    for ( ; i > 0 ; i--)
    {
        currentCard = move(m_cardsDeque.front());
        m_cardsDeque.pop_front();
        if(lose)
        {
            switch (m_battleMap[currentCard->getType()])
            {
                case Dragon:
                    player.damage(DRAGONDAMAGE);
                    break;
                case Goblin:
                    player.damage(GOBLINDAMAGE);
                    break;
                case Vampire:
                    player.damage(VAMPIREDAMAGE);
                    break;
            }
            printLossBattle(player.getName(), currentCard->getType());
        }
        else
        {
            lose = currentCard->applyEncounter(player);
        }
        m_cardsDeque.push_back(move(currentCard));
    }
    return lose;
}


std::unique_ptr<Gang> Gang::createGang(std::ifstream &cards, int* linesCounter)
{
    std::unique_ptr<Gang> gangCard(new Gang(cards, linesCounter));
    return gangCard;
}


std::map <std::string, int> Gang::initializeBattleMap()
{
    std::map<std::string, int> battleCards =
            {
                    {"Dragon", Dragon},
                    {"Vampire", Vampire},
                    {"Goblin", Goblin},
                    {"EndGang", EndGang}
            };
    return battleCards;
}


std::string Gang::getType() const
{
    return TYPE;
}


void Gang::printCard(std::ostream& os) const
{
    printCardDetails(os,getType());
}

