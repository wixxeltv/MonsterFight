#pragma once
#include "../Mob.h"

class Elf : public Mob
{
public:
    Elf(std::string name):Mob(name, 75, 30, 15, 25, "Elf"){}
};
