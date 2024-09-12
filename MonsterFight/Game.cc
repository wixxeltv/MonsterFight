#include "Game.h"
#pragma once
#include <iostream>

#include "Mob.h"
#include "Races/Elf.h"
#include "Races/Human.h"
#include "Races/Orc.h"

int Game::random()
{
    return rand() % 3 + 1;
}
void Game::action(Mob& mobAttacker, Mob& mobDefender)
{
    //std::cout << mobAttacker.getName() << " attacker defense: " << mobAttacker.defensePoints_ << "\n";
    //std::cout << mobDefender.getName() << " defender defense : " << mobDefender.defensePoints_ << "\n";
    switch (mobAttacker.getAction())
    {
        //1 = Attack, 2 = Heal, 3 = Pary
    case 1:
        if (mobDefender.getAction() == 3)
        {
            mobDefender.parry();
            std::cout << "OUUUUUH " << mobDefender.getName() << " just paried " << mobAttacker.getName() << " attack.\n"
            << mobDefender.getName() <<" defense points has been increased by 5 for the next 2 rounds.\n";
        }
        else
        {
            std::cout << "Waaaw incredible " << mobAttacker.getName() << " strikes "<< mobDefender.getName() <<" ! "<< mobDefender.getName() << "'s health drops from "
            << mobDefender.getHealthPoints() << " to " ;
            mobDefender.attack(mobAttacker);
            std::cout << mobDefender.getHealthPoints() << " !\n";
        }
        break;
    case 2:
        std::cout << "There it is! " << mobAttacker.getName() << " heals up, boosting their health from " << mobAttacker.getHealthPoints();
        mobAttacker.heal();
        std::cout << " to " << mobAttacker.getHealthPoints() << " !!!\n";
        break;
    case 3:
        if(mobDefender.getAction() != 1){
            std::cout <<"OUUUUUH " << mobAttacker.getName() << " goes for a block, but "<< mobDefender.getName() << " didnt attack...\n";
        }
        break;

    }
}
bool Game::isNumber()
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        return true;
    }
    else
    {
        return false;
    }
}
Mob Game::defineMob(int choice, std::string name)
{
    Elf mobElf(name);
    Human mobHuman(name);
    Orc mobOrc(name);
    switch (choice)
    {
    case 1: std::cout << name << " the Human ";
        return mobHuman;
    case 2: std::cout << name << " the Orc ";
        return mobOrc;
    case 3: std::cout << name << " the Elf ";
        return mobElf;
    }
}
Mob Game::characterCreation()
{
    int choice;
    while (true)
    {
        std::cout << "Chose your character.\n {1} Human\n {2} Orc\n {3} Elf\n";
        std::cin >> choice;
        if(isNumber() || (choice < 1 || choice > 3)) {std::cout << "Invalid input\n"; continue;}
        else{break;}
    }
    std::string name;
    while (true)
    {
        std::cout << "Chose his name: ";

        std::cin >> name;
        if(name.length() < 3)std::cout << "Invalid input minimum 3 character\n";

        else break;
    }


    std::cout << " The brand new ";
    Mob mob1 = defineMob(choice, name);
    std::cout << "has join the battle.\n";
    return mob1;
}


void Game::lunchGame()
{
    srand(time(NULL));
    Mob mob1 = characterCreation();
    Mob mob2 = characterCreation();
    std::cin.ignore();
    int i = 1;
    Mob &first = mob1;
    Mob &second = mob2;
   
    while (true)
    {
   
        //1 = Attack, 2 = Heal, 3 = Pary
        std::cout << "---------Round " << i << "---------\n";
        i++;
        mob1.setAction(random());
        mob2.setAction(random());


        if (mob1.getSpeed() < mob2.getSpeed())
        {
            std::swap(first, second);
        }
        std::cout << first.getName() << " goes first\n";
        first.paryOnDecrement();
        second.paryOnDecrement();
        action(first, second);
        if(second.getHealthPoints() <= 0)break;
        action(second, first);
        if(first.getHealthPoints() <= 0)break;
   
        std::cin.get();
    }
    Mob winner = mob1;
    if(mob1.getHealthPoints() > mob2.getHealthPoints())
    {
        std::cout << mob2.getName() << " is defeated! Looks like " << mob1.getName() << " is just too good. Try not to embarrass yourself next time!\n";
    }
    else
    {
        std::cout << mob1.getName() << " loses! Who knew winning could be so easy? " << mob2.getName() << " must be having an off day, right?\n";
    }
}