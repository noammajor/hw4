#include <iostream>
#include "utilities.h"
#include "Mtmchkin.h"
#include <fstream>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printInvalidInput();
        return 0;
    }
    Mtmchkin game(argv[1]);
    printStartGameMessage();

    int Mtmchkin::initializePlayersNumber()
    {
        int numberOfPlayers = 0;
        printEnterTeamSizeMessage();
        cin >> numberOfPlayers;
        while (numberOfPlayers < 2 || numberOfPlayers > 6)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            cin >> numberOfPlayers;
        }
    }


    std::queue<Player*> Mtmchkin::initializePlayersQueue(int numberOfPlayers)
    {
        std::queue<Player*> playersQueue;
        string currentName;
        string currentJob;
        for (int i = 0; i < numberOfPlayers ; i++)
        {
            printInsertPlayerMessage();
            getline(std::cin, currentName);
            while (currentName.length() > 15 || currentName.empty())
            {
                printInvalidName();
                printInsertPlayerMessage();
                getline(std::cin, currentName);
            }
            getline(std::cin, currentJob);
            switch (currentJob)
            {
                case Rogue:
                    Rogue()
            }
        }

        return playersQueue;
    }



}
