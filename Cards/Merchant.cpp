#include "Merchant.h"
#include "utilities.h"
#include <iostream>
void Merchant::applyEncounter(std::unique_ptr<Player> player)
    {
    int whatToDo;
       printMerchantInitialMessageForInteractiveEncounter(cout, player->getName(), player->getCoins());
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
            if (player->getCoins()>=HP_COST)
            {
                player->pay(HP_COST);
                player->heal(1);
                printMerchantSummary(std::cout,player->getName(), whatToDo, HP_COST);
                return;
            }
        }
        if(whatToDo==BUY_FORCE)
        {
            if (player->getCoins()>=FORCE_COST)
            {
                player->pay(FORCE_COST);
                player->buff (1);
                printMerchantSummary(std::cout,player->getName(), whatToDo, FORCE_COST);
                return;
            }
        }
    };

std::unique_ptr<Merchant> createMerchant()
{
    std::unique_ptr<Merchant>MerchantCard(new Merchant());
    return MerchantCard;
}








