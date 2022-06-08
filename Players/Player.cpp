#include "Player.h"

Player::Player(const std::string &name, const std::string &job) : m_name(name), m_force(DEFAULT_FORCE), m_playerhealthpoints(MAX_HP),
                            m_level(INITIAL_LEVEL), m_coins(DEFAULT_COINS), m_job(job)
{
}



