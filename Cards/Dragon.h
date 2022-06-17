#ifndef DRAGON_H_
#define DRAGON_H_
#include "Battle.h"
#include <memory>

class Dragon: public Battle
{
public:
    Dragon();
    Dragon& operator=(const Dragon& dragon) = default;
    Dragon(const Dragon&) = default;
    ~Dragon() override=default;
    static std::unique_ptr<Dragon> createDragon();


private:
    cd hw
};

#endif
