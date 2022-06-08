#include "../HealthPoints.h"
#include <iostream>
#include <string>
#ifndef Player_H_
#define Player_H_


/*
* Run Length Encoding List
*
* Implements a Player in muchkin game

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
     * @param level- the level of the player during the game.
     * @param force - strength of the player.
     * @param HP - the amount of health left for a player.
     * @param coins - the amount of tresure available to player.
     */
    Player(const std::string &name, const std::string &job);


    /*
     *copy C'tor
     *get player1 and copies into player2
     */
    Player(const Player&);

    /*
    *assignment operator
    *get player1 and copies into player2
    */
    Player& operator=(const Player& other);

    /*
     *D'tor
     */
    ~Player() = default;


    /*
     *prints players info to screen
     */
    void printInfo() const;


    /*
     *adds a level to player during game
     */
    void levelUp();


    /*
     *returns players level
     */
    int getLevel() const;


    /*
     *adds to the force of the player during the game
     */
    void buff (int powerUp);


    /*
     *heals the players HP during the game
     */
     void heal(int HpToHeal);


    /*
     *functions that lowers the players HP after the loss of the battle
     */
    void damage(int damageTaken);


    /*
     *checks if player lost game and lost all of his HP
     */
    bool isKnockedOut() const;


    /*
     *adds coins after getting the coins add card
     */
    void addCoins(int coinsToAdd);


    /*
     used for payment to buy iteams during game using cards
     */
    bool pay(int payment);


    /*
     *returns the attack strength of the player which is force+level
     */
    int getAttackStrength() const;


    /*
    *returns the attack strength of the player which is force+level
    */
    int getAttackStrength() const;


protected:
    static const int NO_COINS = 0;
    static const int MAX_LEVEL = 10;
    static const int MAX_HP = 100;


    std::string m_name;
    const std::string m_job;
    int m_level;
    int m_force;
    HealthPoints m_playerhealthpoints;
    int m_coins;


private:
    static const int DEFAULT_FORCE = 5;
    static const int INITIAL_LEVEL = 1;
    static const int DEFAULT_COINS = 10;
};

#endif