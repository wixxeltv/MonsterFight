#pragma once
#include "../Mob.h"

class Human : public Mob
{
public:
    //healthPoints_(), attackDamage_(), defensePoints_(), speed_(), race_()
    Human(std::string name):Mob(name, 100, 20, 20, 20, "Human"){}
    
};
