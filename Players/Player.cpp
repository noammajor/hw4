#include "Player.h"
#include "../utilities.h"

Player::Player(const std::string &name, const std::string &job) : m_name(name), m_force(DEFAULT_FORCE), m_playerhealthpoints(MAX_HP),
                            m_level(INITIAL_LEVEL), m_coins(DEFAULT_COINS), m_job(job)
{
}


void Player::printInfo() const
{
    printPlayerDetails(os, &m_name, &m_job, &m_level, &m_force, &m_playerhealthpoints, &m_coins);
    //first argument?
}


void Player::levelUp()
{
    if (m_level == MAX_LEVEL)
    {
        return;
    }
    m_level++;
}


int Player::getLevel() const
{
    return m_level;
}


void Player::buff (int powerUp)
{
    if (powerUp < 0)
    {
        return;
    }
    m_force += powerUp;
}


void Player::heal(int HpToHeal)
{
    m_playerhealthpoints += HpToHeal;
}


void Player::damage(int damageTaken)
{
    if (damageTaken < 0)
    {
        return;
    }
    m_playerhealthpoints -= damageTaken;
}


bool Player::isKnockedOut() const
{
    if(m_playerhealthpoints <= 0)
    {
        return true;
    }
    return false;
}


void Player::addCoins(int coinsToAdd)
{
    if (coinsToAdd < 0)
    {
        return;
    }
    m_coins += coinsToAdd;
}


bool Player::pay(int payment)
{
    if(m_coins < payment)
    {
        return false;
    }
    if (m_coins <= 0)
    {
        return true;
    }
    m_coins -= payment;
    return true;
}


int Player::getAttackStrength() const
{
    return (m_level + m_force);
}
