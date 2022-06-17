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
    /*vector<unique_ptr<Card>> cards;
    cards.push_back(unique_ptr<Card>(new Goblin()));
    cards.push_back(unique_ptr<Card>(new Vampire()));
    cards.push_back(unique_ptr<Card>(new Dragon()));
    cards.push_back(unique_ptr<Card>(new Treasure()));
    cards.push_back(unique_ptr<Card>(new Merchant()));
    cards.push_back(unique_ptr<Card>(new Fairy()));
    cards.push_back(unique_ptr<Card>(new Barfight()));
    cards.push_back(unique_ptr<Card>(new Pitfall()));
    for(unique_ptr<Card>& card : cards){
        cout << *card;
    }
    cards.erase(cards.begin(),cards.end());*/
    return 1;
}
