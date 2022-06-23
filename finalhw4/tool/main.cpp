#include "Mtmchkin.h"
#include <memory>
#include <iostream>



int main()
{
    Mtmchkin game("deck.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < 100)
    {
        game.playRound();
    }
    game.printLeaderBoard();
    return 1;
}
