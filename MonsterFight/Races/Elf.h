#pragma once
#include "../Mob.h"

class Elf : public Mob
{
public:
    Elf(std::string name):Mob(name, 90, 25, 5, 25, "Elf"){}
};
