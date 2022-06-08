#include "Mtmchkin.h"
#include "Players/Player.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "Cards/Card.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"

using namespace std;

Mtmchkin::Mtmchkin(const std::string fileName)
{
    ifstream cards ("fileName.txt");
    string line;
    //exception.
    while (getline(cards,line))
    {
        if(line.empty())
        {
            break;
        }

        switch(line)
        {
            case line.compare(DRAGCOMP):
            {
                Dragon card = Dragon();
                m_cardsQueue.push(&card);
                break;
            }
            case line.compare(VAMPCOMP):
            {
                Vampire card = Vampire();
                m_cardsQueue.push(&card);
                break;
            }
            case line.compare(GOBLCOMP):
            {
                Goblin card = Goblin();
                m_cardsQueue.push(&card);
                break;
            }
            //fairy
            case line.compare(FairCOMP):
            {
                Goblin card = Goblin();
                m_cardsQueue.push(&card);
                break;
            }


        }
    }

}
