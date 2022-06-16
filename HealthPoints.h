#ifndef EX3_HealthPoint_H
#define EX3_HealthPoint_H
#include <iostream>

class HealthPoints
{

public:

    /*
        * C'tor of HealthPoints class
        *
        * @param HP - amount of hp in the class, default is 100.
        * @return
       */
    HealthPoints();


    /*
         * Here we are explicitly telling the compiler to use the default methods
    */
    ~HealthPoints() = default;
    HealthPoints(const HealthPoints&) = default;

    //the equal operator here should only be for the specific health value.
    HealthPoints& operator=(const HealthPoints& hp1) = default;

    int getHP() const;
    /*
         * Here we are defining the operators +=,-=.
    */
    HealthPoints& operator+=(int add);


    /*
         * error argument
    */
    class InvalidArgument
    {
    };


private:
    /*
         * variables of the class
         * @param healthPoints - amount of healthpoints the user currently has
         * @param maxHealthPoints - maximum healthpoints a player can have
    */
    int m_healthPoints;
   static const int m_maxHealthPoints=100;

    /*
         * boolian operators for our class
    */
    friend bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
    friend bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp1);
};

/*
     * operators that require symmetry
*/
HealthPoints operator+(const HealthPoints& hp1, int add);
HealthPoints operator+(int add, const HealthPoints& hp1);
HealthPoints operator-(int sub, const HealthPoints& hp2);
HealthPoints operator-(const HealthPoints& hp2, int sub);
HealthPoints& operator-=(HealthPoints& hp1, int sub);

/*
     * boolian operators that use the 2 friends
*/
bool operator<(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2) ;

#endif
