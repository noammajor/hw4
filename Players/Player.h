#ifndef Player_H_
#define Player_H_

#include "../HealthPoints.h"


/*
* Run Length Encoding List
*
* Implements a Player in mtmchkin game

*the following class is available:
*player
*the following variables are part of the class:
*name
*force
*level [1,10]
*HP-Health Points between [0,maxHP]
*coins
* The following functions are available:
*
*/

class Player
{

public:

    /*
    * C'tor of player class
    *
    * @param name - name of player.
    */
    explicit Player(const std::string &name);

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    virtual ~Player() = default;
    Player(const Player&) = default;
    Player& operator=(const Player&) = default;

    /*
    *returns players type
    */
    virtual std::string getType() const = 0;

    /*
    * returns players name
    */
    std::string getName() const;


    /*
    * adds a level to player during game
    */
    void levelUp();


    /*
    * returns players level
    */
    int getLevel() const;

    /*
    *  returns players amount of coins
    */
    int getCoins() const;


    /*
    * adds to the force of the player during the game
    */
    void buff (int powerUp);


    /*
    * heals the player and add him HP during the game
    */
     virtual void heal(int HpToHeal);


    /*
    * lowers the players HP after the loss of the battle
    */
    void damage(int damageTaken);


    /*
    * checks if player lost game and lost all of his HP
    */
    bool isKnockedOut() const;


    /*
    * adds coins after getting the coins add card
    */
    virtual void addCoins(int coinsToAdd);


    /*
    * used for payment to buy items during game using cards
    */
    bool pay(int payment);


    /*
    * returns the attack strength of the player which is force+level
    */
    virtual int getAttackStrength() const;



protected:
    static const int MAX_LEVEL = 10;

    const std::string m_name;
    int m_force;
    HealthPoints m_healthpoints;
    int m_level;
    int m_coins;

    /*
    *prints players info to screen
    */
    virtual void print() const = 0;

private:
    static const int DEFAULT_FORCE = 5;
    static const int INITIAL_LEVEL = 1;
    static const int DEFAULT_COINS = 10;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif