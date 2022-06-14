#include "HealthPoints.h"


HealthPoints::HealthPoints(int healthPoints)
{
    if ( healthPoints <= 0 )
    {
        throw InvalidArgument();
    }
    m_healthPoints = healthPoints;
    m_maxHealthPoints = healthPoints;
}


int HealthPoints::getHP() const
{
    return m_healthPoints;
}


HealthPoints operator+(const HealthPoints& hp1 ,int add)
{
    HealthPoints healthTemp = hp1;
    return healthTemp += add;
}


HealthPoints operator+(int add, const HealthPoints& hp1)
{
    HealthPoints healthTemp = hp1;
    return healthTemp += add;
}


HealthPoints& HealthPoints::operator+=(int add)
{
    if(m_healthPoints + add >= m_maxHealthPoints)
    {
        m_healthPoints = m_maxHealthPoints;
        return *this;
    }
    if(m_healthPoints + add <= 0)
    {
        m_healthPoints = 0;
        return *this;
    }
    m_healthPoints = m_healthPoints + add;
    return *this;
}


HealthPoints operator-(const HealthPoints& hp1, int sub)
{
    HealthPoints healthTemp = hp1;
    return healthTemp += -sub;
}


HealthPoints operator-(int sub,const HealthPoints& hp1)
{
    HealthPoints healthTemp = hp1;
    return healthTemp += -sub;
}


HealthPoints& operator-=(HealthPoints& hp1, int sub)
{
    return hp1 += -sub;
}


bool operator==(const HealthPoints& hp1, const HealthPoints& hp2)
{
    if(hp2.m_healthPoints == hp1.m_healthPoints)
    {
        return true;
    }
    return false;
}


bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return(!(hp2 == hp1));
}


bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    if(hp1.m_healthPoints >= hp2.m_healthPoints)
    {
        return true;
    }
    return false;
}


bool operator>(const HealthPoints& hp1, const HealthPoints& hp2)
{
    if(hp1 >= hp2 && hp1 != hp2)
    {
        return true;
    }
    return false;
}


bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    if(!(hp1 >= hp2)||hp1 == hp2)
    {
        return true;
    }
    return false;
}


bool operator<(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return(!(hp1 >= hp2));
}


std::ostream& operator<<(std::ostream& os, const HealthPoints& hp1)
{
    os << hp1.m_healthPoints << '(' << hp1.m_maxHealthPoints << ')';
    return os;
}
