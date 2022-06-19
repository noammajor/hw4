#include "Player.h"



Player::Player(const std::string& name) : m_name(name), m_force(DEFAULT_FORCE), m_playerhealthpoints(),
                            m_level(INITIAL_LEVEL), m_coins(DEFAULT_COINS)
{
}


//Player::~Player() {}


/*void Player::printInfo() const
{
    printPlayerDetails(std::cout , m_name, m_job, m_level, m_force, m_playerhealthpoints.getHP(), m_coins);
}


std::string Player::getType() const
{
    return m_job;
}*/



std::string Player::getName() const
{
    return m_name;
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


int Player::getCoins() const
{
    return m_coins;
}


void Player::buff (int powerUp)
{
    m_force += powerUp;
    if(m_force <0)
    {
        m_force = 0;
    }
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
    if(m_playerhealthpoints.getHP() <= 0)
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


std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.print();
    return os;
}