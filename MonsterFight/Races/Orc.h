#pragma once
#include "../Mob.h"

class Orc : public Mob
{
public:
    Orc(std::string name):Mob(name, 200, 10, 30, 5, "Orc"){}
};
