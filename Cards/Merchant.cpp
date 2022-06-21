#include "Merchant.h"


bool Merchant::applyEncounter(Player& player)
{
    std::string getFromPlayer;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::getline(std::cin,getFromPlayer);
    int whatToDo;
    try
    {
        whatToDo=std::stoi(getFromPlayer);
    }
    catch (std::exception &err)
    {
        whatToDo=3;
    }
    while (whatToDo!=BUY_NOTHING && whatToDo!=BUY_HP&& whatToDo!=BUY_FORCE)
    {
        printInvalidInput();
        std::getline(std::cin,getFromPlayer);
        try
        {
            whatToDo=std::stoi(getFromPlayer);
        }
        catch (std::exception &err)
        {
            whatToDo=INVALID_INPUT;
        }
    }
    if(whatToDo==BUY_NOTHING)
    {
        printMerchantSummary(std::cout,player.getName(), whatToDo, 0);
        return true;
    }
    if (whatToDo==BUY_HP)
    {
        if (player.getCoins()>=HP_COST)
        {
            player.pay(HP_COST);
            player.heal(1);
            printMerchantSummary(std::cout,player.getName(), whatToDo, HP_COST);
            return true;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    if(whatToDo==BUY_FORCE)
    {
        if (player.getCoins()>=FORCE_COST)
        {
            player.pay(FORCE_COST);
            player.buff (1);
            printMerchantSummary(std::cout,player.getName(), whatToDo, FORCE_COST);
            return true;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    printMerchantSummary(std::cout,player.getName(), whatToDo, 0);
    return true;
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
    return type;
}





