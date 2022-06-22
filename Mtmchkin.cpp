#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const std::string &fileName) : m_winners(), m_losers(),m_numberOfRounds(0)
{
    printStartGameMessage();
    m_cardsMap = initializeCardsMap();
    m_cardsDeque = initializeCardsDeque(fileName);
    m_numberOfPlayersInGames = initializePlayersNumber();
    m_playersJobsMap = initializeJobsMap();
    m_playersDeque = initializePlayersDeque(m_numberOfPlayersInGames);
}


std::deque<std::unique_ptr<Card>> Mtmchkin::initializeCardsDeque(const std::string &fileName)
{
    int linesCounter = 0;
    std::ifstream cards(fileName);
    if(!cards)
    {
        throw DeckFileNotFound();
    }
    std::string line;
    std::deque<std::unique_ptr<Card>> cardsQueue;
    while (getline(cards, line))
    {
        if (line.empty())
        {
            if(linesCounter==0)
            {
                throw DeckFileFormatError(1);
            }
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
                throw DeckFileFormatError(linesCounter);
        }
    }
    if(cardsQueue.size()<MIN_CARDS)
    {
        throw DeckFileInvalidSize();
    }
    return cardsQueue;
}


int Mtmchkin::initializePlayersNumber()
{
    std::string input;
    int numberOfPlayers = 0;
    while (numberOfPlayers == 0)
    {
        printEnterTeamSizeMessage();
        getline(std::cin, input);
        try
        {
            numberOfPlayers = stoi(input);
        }
        catch (std::exception &err)
        {
            numberOfPlayers = 0;
        }
        if (numberOfPlayers < MIN_PLAYER || numberOfPlayers > MAX_PLAYER )
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


std::deque<std::unique_ptr<Player>> Mtmchkin::initializePlayersDeque(int numberOfPlayers)
{
    std::deque<std::unique_ptr<Player>> playersQueue;
    int currentChar;
    std::string input;
    std::string currentName= "/0";
    std::string currentJob = "/0";
    bool correct, playerCreated;
    //printInsertPlayerMessage();
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
               if(currentChar > MAX_LENGTH_NAME|| currentChar==0 )
               {
                   printInvalidName();
                 //  printInsertPlayerMessage();
                   correct = false;
               }
                currentName = input.substr(0,currentChar);
                currentJob = input.substr(currentChar+1);
                if(!containsOnlyLetters(currentName ) && correct)
                {
                    printInvalidName();
                    correct = false;
                }
            }
            while (!correct);
                switch (m_playersJobsMap[currentJob])
                {
                    case ROGUE:
                        playersQueue.push_back(Rogue::createRogue(currentName));
                        break;
                    case WIZARD:
                        playersQueue.push_back(Wizard::createWizard(currentName));
                        break;
                    case FIGHTER:
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


void Mtmchkin::playRound()
{
    bool winBattle;
    printRoundStartMessage(m_numberOfRounds + 1);
    for (int i = m_numberOfPlayersInGames ; i > 0 ; i--)
    {
        printTurnStartMessage(m_playersDeque.front()->getName());
        std::unique_ptr<Card> currentCard = move(m_cardsDeque.front());
        m_cardsDeque.pop_front();
        std::unique_ptr<Player> currentPlayer = move(m_playersDeque.front());
        m_playersDeque.pop_front();
        winBattle = currentCard->applyEncounter(*currentPlayer);
        if (winBattle)
        {
            currentPlayer->levelUp();
            printWinBattle(currentPlayer->getName(),currentCard-> getType());
        }
        m_cardsDeque.push_back(move(currentCard));
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
            m_playersDeque.push_back(move(currentPlayer));
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
    for (std::deque<std::unique_ptr<Player>>::const_iterator iter = m_playersDeque.begin() ; iter != m_playersDeque.end() ; iter++)
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
                    {"Vampire", Vampire},
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


bool Mtmchkin::containsOnlyLetters(std::string &currentName)
{
   for(char i : currentName)
   {
       if(int(i)>122 || int(i)<65)
       {
           return false;
       }
       if(int(i)>90 && int(i)<97)
       {
           return false;
       }
   }
    return true;
}

