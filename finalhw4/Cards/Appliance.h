#ifndef APPLIANCE_H_
#define APPLIANCE_H_

#include "Card.h"


class Appliance :public Card
{

public:

    /*
    * C'tor of Aplliance class
    */
    explicit Appliance() = default;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Appliance() override = default;
    Appliance(const Appliance&) = default;
    Appliance& operator=(const Appliance&) = default;

    /*
    * prints the cards details to the screen
    * @ param os - output stream
    */
    void printCard(std::ostream& os) const override;

    /*
    *returns the cards type
    */
    std::string getType() const override = 0;

};

#endif
