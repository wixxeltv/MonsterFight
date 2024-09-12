#pragma once
#include <string>

class Mob
{
    
private:
    int initialHealPoints_;
    int bonusDefense = 5;
    int paryOn_ = -1;
    int healthPoints_;
    int attackDamage_;
    //int defensePoints_;
    int speed_;
    std::string race_;
    std::string name_;
    int action_;
    int defensePoints_;

public:
    // Getters
    int getSpeed() const;
    std::string getRace() const;
    std::string getName() const;
    int getAction() const;
    int getHealthPoints() const;

    // Setters
    void setSpeed(int speed);
    void setRace(std::string& race);
    void setName(std::string& name);
    void setAction(int action);
    void setHealthPoints(int healthPoints);


    Mob(std::string name,int healthPoints, int attackDamage, int defensePoints, int speed, std::string race) : healthPoints_(healthPoints), attackDamage_(attackDamage), defensePoints_(defensePoints), speed_(speed), race_(race)
    {
        name_ = name;
        initialHealPoints_ = healthPoints;
    }

    void attack(Mob& mob);
    void heal();
    void parry();
    void paryOnDecrement();
    bool isAlive();
};
