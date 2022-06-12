#include "Merchant.h"
#include "utilities.h"
#include <iostream>
void Merchant::applyEncounter(Player& player)
    {
    int whatToDo;
       printMerchantInitialMessageForInteractiveEncounter(cout, player.getname(), player.getcoins());
       std::cin>>whatToDo;
       if (whatToDo!=BUY_NOTHING && whatToDo!=BUY_HP&& whatToDo!=BUY_FORCE)
       {
           printInvalidInput();
           std::cin>>whatToDo;
       }
        if(whatToDo==BUY_NOTHING)
        {
            return;
        }
        if (whatToDo==BUY_HP)
        {
            if (player.getcoins()>=HP_COST)
            {
                player.pay(HP_COST);
                player.heal(1);
                printMerchantSummary(std::cout,player.getname(), whatToDo, HP_COST);
                return;
            }
        }
        if(whatToDo==BUY_FORCE)
        {
            if (player.getcoins()>=FORCE_COST)
            {
                player.pay(FORCE_COST);
                player.buff (1);
                printMerchantSummary(std::cout,player.getname(), whatToDo, FORCE_COST);
                return;
            }
        }
    };








