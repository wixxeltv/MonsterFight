#include <iostream>

#include "Mob.h"
#include "Races/Elf.h"
#include "Races/Human.h"
#include "Races/Orc.h"

int random()
{
    srand(time(NULL));
    return rand() % 3 + 1;
}
void action()
{
    int mobAction = random();
    switch (mobAction)
    {
        ;
    }
}
bool isNumber()
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
Mob defineMob(int choice, std::string name)
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
Mob characterCreation()
{
    int choice;
    while (true)
    {
        std::cout << "Chose your character.\n {1} Human\n {2} Orc\n {3} Elf\n";
        std::cin >> choice;
        if(isNumber() || (choice < 1 || choice > 3)) {std::cout << "Invalid input\n"; continue;}
        else{break;}
      
    }
    std::cout << "Chose his name: ";
    std::string name;
    std::cin >> name;
        
    std::cout << " Your brand new ";
    Mob mob1 = defineMob(choice, name);
    std::cout << "is here.\n";
    return mob1;
}


int main(int argc, char* argv[])
{
   Mob mob1 = characterCreation();
   Mob mob2 = characterCreation();
   int i = 1; 
   while (mob1.healthPoints_ > 0 && mob2.healthPoints_ > 0)
   {
       std::cout << "---------Tour " << i << "---------\n";
       int mob1Action = random();
       
       int mob2Action = random();
   } 
}
