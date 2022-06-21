#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const std::string &fileName) : m_winners(), m_losers(),m_numberOfRounds(0)
{
    printStartGameMessage();
    m_cardsMap = initializeCardsMap();
    m_cardsQueue = initializeCardsQueue(fileName);
    m_numberOfPlayersInGames = initializePlayersNumber();
    m_playersJobsMap = initializeJobsMap();
    m_playersQueue = initializePlayersQueue(m_numberOfPlayersInGames);
}


std::deque<std::unique_ptr<Card>> Mtmchkin::initializeCardsQueue(const std::string &fileName)
{
    std::ifstream cards(fileName);
    if(!cards)
    {
        throw DeckFileNotFound();
    }
    std::string line;
    std::deque<std::unique_ptr<Card>> cardsQueue;
    int linesCounter = 0;
    while (getline(cards, line))
    {
        if (line.empty())
        {
            break;
        }
        linesCounter++;
        switch (m_cardsMap[line])
        {
            case Dragon:
                cardsQueue.push_back(Dragon::createDragon());
                break;
            case Vampire:
                cardsQueue.push_back(Vampire::createVampire());
                break;
            case Goblin:
                cardsQueue.push_back(Goblin::createGoblin());
                break;
            case Fairy:
                cardsQueue.push_back(Fairy::createFairy());
                break;
            case Treasure:
                cardsQueue.push_back(Treasure::createTreasure());
                break;
            case Merchant:
                cardsQueue.push_back(Merchant::createMerchant());
                break;
            case Pitfall:
                cardsQueue.push_back(Pitfall::createPitfall());
                break;
            case Barfight:
                cardsQueue.push_back(Barfight::createBarfight());
                break;
            case Gang:
               cardsQueue.push_back(Gang::createGang(cards, &linesCounter));
                break;
            default:
                throw DeckFileFormatError(cardsQueue.size()+1); //check size later
        }
    }
    if(cardsQueue.size()<MIN_CARDS)
    {
        throw DeckFileInvalidSize();
    }
    return cardsQueue;
}

/*
std::deque<std::unique_ptr<Card>> Mtmchkin::initializeCardsQueue(const std::string &fileName)
{
    std::ifstream cards(fileName);
    if(!cards)
    {
        throw DeckFileNotFound();
    }
    std::string line;
    std::deque<std::unique_ptr<Card>> cardsQueue;
    int linesCounter = 0;
    while (getline(cards, line))
    {
        if (line.empty())
        {
            break;
        }
        linesCounter++;
        if (line == "Gang")
        {
            cardsQueue.push_back(Gang::createGang(cards, &linesCounter));
            break;
        }
        else
        {
            insertToDeque(cardsQueue, line, linesCounter);
        }
    }
    if(cardsQueue.size()<MIN_CARDS)
    {
        throw DeckFileInvalidSize();
    }
    return cardsQueue;
}


void Mtmchkin::insertToDeque (std::deque<std::unique_ptr<Card>> cardsDeque, std::string currentCard, int line) {
    switch (m_cardsMap[currentCard])
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
        case Fairy:
            cardsDeque.push_back(Fairy::createFairy());
            break;
        case Treasure:
            cardsDeque.push_back(Treasure::createTreasure());
            break;
        case Merchant:
            cardsDeque.push_back(Merchant::createMerchant());
            break;
        case Pitfall:
            cardsDeque.push_back(Pitfall::createPitfall());
            break;
        case Barfight:
            cardsDeque.push_back(Barfight::createBarfight());
            break;
        default:
            throw DeckFileFormatError(line);
    }
}
*/

int Mtmchkin::initializePlayersNumber()
{
    std::string input;
    int numberOfPlayers = 0;
    while (numberOfPlayers == 0)
    {
        printEnterTeamSizeMessage();
        getline(std::cin, input);
        numberOfPlayers = stoi(input);
        if (numberOfPlayers < MIN_PLAYER || numberOfPlayers > MAX_PLAYER)
        {
            printInvalidTeamSize();
            numberOfPlayers = 0;
        }
    }
    return numberOfPlayers;
}


std::map <std::string, int> Mtmchkin::initializeJobsMap()
{
    std::map<std::string, int> playersJobs =
            {
                    {"Rogue",   Rogue},
                    {"Wizard",  Wizard},
                    {"Fighter", Fighter}
            };
    return playersJobs;
}


std::deque<std::unique_ptr<Player>> Mtmchkin::initializePlayersQueue(int numberOfPlayers)
{
    std::deque<std::unique_ptr<Player>> playersQueue;
    int currentChar;
    std::string input;
    std::string currentName= "/0";
    std::string currentJob = "/0";
    bool correct, playerCreated;
    for (int i = 0; i < numberOfPlayers ; i++)
    {
        printInsertPlayerMessage();
        do
        {
            do
            {
                correct = true;
                playerCreated = true;
                getline(std::cin,input);
                currentChar = input.find(" ",0);
                if(currentChar > MAX_LENGTH_NAME|| currentChar == 0)
                {
                    printInvalidName();
                    printInsertPlayerMessage();
                    correct = false;
                }
                currentName = input.substr(0,currentChar);
                currentJob = input.substr(currentChar+1);
            }
            while (!correct);
                switch (m_playersJobsMap[currentJob])
                {
                    case Rogue:
                        playersQueue.push_back(Rogue::createRogue(currentName));
                        break;
                    case Wizard:
                        playersQueue.push_back(Wizard::createWizard(currentName));
                        break;
                    case Fighter:
                        playersQueue.push_back(Fighter::createFighter(currentName));
                        break;
                    default:
                        printInvalidClass();
                        playerCreated = false;
                }
            }
            while (!playerCreated);
        }
    return playersQueue;
}

/*
bool Mtmchkin::createPlayer (std::deque<std::unique_ptr<Player>> playersDeque, std::string playersJob)
{

}*/


void Mtmchkin::playRound()
{
    bool winBattle;
    printRoundStartMessage(m_numberOfRounds + 1);
    for (int i = m_numberOfPlayersInGames ; i > 0 ; i--)
    {
        printTurnStartMessage(m_playersQueue.front()->getName());
        std::unique_ptr<Card> currentCard = move(m_cardsQueue.front());
        m_cardsQueue.pop_front();
        std::unique_ptr<Player> currentPlayer = move(m_playersQueue.front());
        m_playersQueue.pop_front();
        winBattle = currentCard->applyEncounter(*currentPlayer);
        if (winBattle)
        {
            currentPlayer->levelUp();
            printWinBattle(currentPlayer->getName(),currentCard-> getType());
        }
        m_cardsQueue.push_back(move(currentCard));
        if (currentPlayer->getLevel() == 10)
        {
            m_numberOfPlayersInGames--;
            m_winners.push_back(std::move(currentPlayer));
        }
        else if (move(currentPlayer)->isKnockedOut())
        {
            m_numberOfPlayersInGames--;
            m_losers.push_front(move(currentPlayer));
        }
        else
        {
            m_playersQueue.push_back(move(currentPlayer));
        }
    }
    if (m_numberOfPlayersInGames == 0)
    {
        printGameEndMessage();
    }
    m_numberOfRounds++;
}


void Mtmchkin::printLeaderBoard() const
{
    int ranking=1;
    printLeaderBoardStartMessage();
    for (std::deque<std::unique_ptr<Player>>::const_iterator iter = m_winners.begin() ; iter != m_winners.end() ; iter++)
 {
     printPlayerLeaderBoard( ranking,**iter);
     ranking++;
 }
    for (std::deque<std::unique_ptr<Player>>::const_iterator iter = m_playersQueue.begin() ; iter != m_playersQueue.end() ; iter++)
 {
     printPlayerLeaderBoard( ranking, **iter);
     ranking++;
 }
    for (std::deque<std::unique_ptr<Player>>::const_iterator iter = m_losers.begin() ; iter != m_losers.end() ; iter++)
    {
     printPlayerLeaderBoard(ranking, **iter);
     ranking++;
 }
}


bool Mtmchkin::isGameOver() const
{
    if (m_numberOfPlayersInGames == 0)
    {
        return true;
    }
    return false;
}


int Mtmchkin::getNumberOfRounds() const
{
    return m_numberOfRounds;
}


std::map <std::string,int> Mtmchkin::initializeCardsMap()
{
    static std::map<std::string,int> setupCards =
            {
                    {"Vampire", Vampire },
                    {"Dragon" , Dragon},
                    {"Goblin" , Goblin},
                    {"Fairy", Fairy},
                    {"Treasure",Treasure},
                    {"Merchant", Merchant},
                    {"Pitfall",Pitfall},
                    {"Barfight", Barfight},
                    {"Gang", Gang}
            };
    return setupCards;
}