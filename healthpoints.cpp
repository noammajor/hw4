#include "healthpoints.h"


   
    HealthPoints::HealthPoints(int HP)
    {
       if ( HP <= 0 )
       {
           throw InvalidArgument();
       }
        healthPoints = HP;
        maxHealthPoints = HP;
    }
    

    //
     HealthPoints operator+(const HealthPoints& hp1 ,int add)
    {
        HealthPoints healthTemp = hp1;
        return healthTemp += add;
    }
    /*
    HealthPoints& HealthPoints::operator=(const HealthPoints& hp1)
    {
        healthPoints = hp1.healthPoints;
        maxHealthPoints = hp1.maxHealthPoints;
        return *this;
    }*/
    HealthPoints operator+(int add, const HealthPoints& hp1)
    {
        HealthPoints healthTemp=hp1;
        return healthTemp += add;
    }
    
    
  
    
   HealthPoints& HealthPoints::operator+=(int add)
    {
       if(healthPoints + add >= maxHealthPoints)
       {
           healthPoints = maxHealthPoints;
           return *this;
       }
      if(healthPoints + add <= 0)
      {
          healthPoints = 0;
          return *this;
      }
       healthPoints = healthPoints + add;
      return *this;
   }
    
    /*
    HealthPoints& HealthPoints::operator-=(int sub)
    {
        healthPoints+= - sub;
        if(healthPoints<0)
        {
            healthPoints=0;
        }
        if (healthPoints>maxHealthPoints)
        {
            healthPoints=maxHealthPoints;
        }
        return *this;
    }*/

HealthPoints operator-(const HealthPoints& hp1,int sub)
    {
        HealthPoints healthTemp = hp1;
        return healthTemp += -sub;
    }
    
    HealthPoints operator-(int sub,const HealthPoints& hp1)
    {
        HealthPoints healthTemp=hp1;
        return healthTemp+= -sub;
     }

HealthPoints& operator-=(HealthPoints& hp1, int sub)
{
        return hp1 += -sub;
}
    
    
    bool operator==(const HealthPoints& hp1,const HealthPoints& hp2)
    {
        if(hp2.healthPoints==hp1.healthPoints)
        {
            return true;
        }

       return false;
    }
    
    
    bool operator!=(const HealthPoints& hp1,const HealthPoints& hp2)
    {
        return(!(hp2==hp1));
    }
    
    
    bool operator>=(const HealthPoints& hp1,const HealthPoints& hp2)
    {
        if(hp1.healthPoints>=hp2.healthPoints)
        {
            return true;
        }
        return false;
    }
    
    
    bool operator>(const HealthPoints& hp1,const HealthPoints& hp2)
    {
        if(hp1>=hp2 && hp1!=hp2)
        {
            return true;
        }
        return false;
    }
    
    
    bool operator<=(const HealthPoints& hp1,const HealthPoints& hp2)
    {
        if(!(hp1>=hp2)||hp1==hp2)
        {
            return true;
        }
        return false;
    }
    
    bool operator<(const HealthPoints& hp1,const HealthPoints& hp2)
    {
        return(!(hp1>=hp2));
    }
    
    
    std::ostream& operator<<(std::ostream& os, const HealthPoints& hp1)
    {
        os << hp1.healthPoints << '(' << hp1.maxHealthPoints << ')';
            return os;
    }
