#pragma once
#include <iostream>

#include "Mob.h"
#include "Races/Elf.h"
#include "Races/Human.h"
#include "Races/Orc.h"

class Game
{
private:
    int random();
 
    void action(Mob& mobAttacker, Mob& mobDefender);
   
    bool isNumber();
    Mob defineMob(std::string choice, std::string name);
    Mob characterCreation(std::string firstOneRace);
public:
    void lunchGame();
};