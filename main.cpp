#include "Mtmchkin.h"
#include <memory>
#include <iostream>
#include <vector>

using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;
using std::istringstream;
using std::vector;


int main()
{
    printStartGameMessage();
    Mtmchkin game("deck.txt");
    while(!game.isGameOver())
    {
        game.playRound();
    }
    return 1;
}
