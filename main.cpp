#include "Mtmchkin.h"


int main(int argc, char** argv)
{
    printStartGameMessage();
    try
    {
        Mtmchkin game(argv[1]);
        while(!game.isGameOver())
        {
            game.playRound();
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
    return 1;
}
