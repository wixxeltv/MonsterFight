#pragma once
#include <string>

class Mob
{
private:
    const int bonusDefense = 5;
    int paryOn_;
public:
    int healthPoints_;
    int attackDamage_;
    int defensePoints_;
    int speed_;
    std::string race_;
    std::string name_;


public:

    Mob(std::string name,int healthPoints, int attackDamage, int defensePoints, int speed, std::string race) : healthPoints_(healthPoints), attackDamage_(attackDamage), defensePoints_(defensePoints), speed_(speed), race_(race)
    {
        name_ = name;
    }

    void attack(Mob mob);
    void heal();
    void pary();
    void paryOnDecrement();
};
