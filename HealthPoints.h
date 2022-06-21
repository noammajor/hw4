#ifndef EX3_HealthPoint_H
#define EX3_HealthPoint_H
#include <iostream>

class HealthPoints
{

public:

    /*
    * C'tor of HealthPoints class
    */
    explicit HealthPoints();


    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~HealthPoints() = default;
    HealthPoints(const HealthPoints&) = default;
    HealthPoints& operator=(const HealthPoints&) = default;

    /*
    * @return hp quantity
    */
    int getHP() const;

    /*
    * Here we are defining the operator +=
    */
    HealthPoints& operator+=(int add);


private:
    /*
    * variables of the class
    * @param healthPoints - amount of healthpoints the user currently has
    */
    int m_healthPoints;
    static const int MAX_HP =100;

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
