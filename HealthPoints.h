#ifndef EX3_HealthPoint_H
#define EX3_HealthPoint_H
#include <iostream>

class HealthPoints
{
public:
    static const int DefaultHealth = 100;
    /*
        * C'tor of HealthPoints class
        *
        * @param HP - amount of hp in the class, defult is 100.
        * @return
       */
    HealthPoints(int HP = DefaultHealth );
    /*
         * Here we are explicitly telling the compiler to use the default methods
    */
    ~HealthPoints() = default;
    HealthPoints(const HealthPoints&) = default;
    //the equal operator here should only be for the specific health value.
    HealthPoints& operator=(const HealthPoints& hp1) = default;
    /*
         * Here we are defining the operators +=,-=.
    */
    HealthPoints& operator+=(int add);
    /*
         * error argument
    */
    class InvalidArgument{};

    
private:
    /*
         * varubales of the class
         * @param healthPoints - amount of healthpoints the user currently has
         * @param maxHealthPoints - maximum healthpoints a player can have
    */
   int healthPoints;
   int maxHealthPoints;
    /*
         * boolian operators for our class
    */
   friend bool operator==(const HealthPoints& hp1,const HealthPoints& hp2);
   friend bool operator>=(const HealthPoints& hp1,const HealthPoints& hp2);
   friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp1);
};
/*
     * opperators that require symetry
*/
HealthPoints operator+(const HealthPoints& hp1,int add);
HealthPoints operator+(int add, const HealthPoints& hp1);
HealthPoints operator-(int sub,const HealthPoints& hp2);
HealthPoints operator-(const HealthPoints& hp2,int sub);
HealthPoints& operator-=(HealthPoints& hp1, int sub);

/*
     * boolian operaters that use the 2 friends
*/
bool operator<(const HealthPoints& hp1,const HealthPoints& hp2);
bool operator!=(const HealthPoints& hp1,const HealthPoints& hp2);
bool operator>(const HealthPoints& hp1,const HealthPoints& hp2);
bool operator<=(const HealthPoints& hp1,const HealthPoints& hp2) ;

#endif
