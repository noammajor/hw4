#include "Merchant.h"


const std::string Merchant::MERCHANT = "Merchant";


bool Merchant::applyEncounter(Player& player)
{
    std::string getFromPlayer;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int whatToDo;
    do
    {
        std::getline(std::cin,getFromPlayer);
        try
        {
            whatToDo = std::stoi(getFromPlayer);
        }
        catch (std::exception &err)
        {
            whatToDo = INVALID_INPUT;
        }
        if (whatToDo < BUY_NOTHING || whatToDo > BUY_FORCE)
        {
            printInvalidInput();
        }
    }
    while (whatToDo != BUY_NOTHING && whatToDo != BUY_HP && whatToDo != BUY_FORCE);
    if(whatToDo == BUY_NOTHING)
    {
        printMerchantSummary(std::cout,player.getName(), whatToDo, 0);
    }
    else if (whatToDo == BUY_HP && player.pay(HP_COST))
    {
        player.heal(1);
        printMerchantSummary(std::cout,player.getName(), whatToDo, HP_COST);
    }
    else if(whatToDo == BUY_FORCE && player.pay(FORCE_COST))
    {
        player.buff (1);
        printMerchantSummary(std::cout,player.getName(), whatToDo, FORCE_COST);
    }
    else
    {
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout,player.getName(), whatToDo, 0);
    }
    return false;
}


std::unique_ptr<Merchant> Merchant::createMerchant()
{
    std::unique_ptr<Merchant> merchantCard(new Merchant());
    if (!merchantCard)
    {
        throw std::bad_alloc();
    }
    return merchantCard;
}


std::string Merchant::getType() const
{
    return MERCHANT;
}





