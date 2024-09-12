#include "Mob.h"

#include <iostream>
#include <ostream>

// Getters
int Mob::getSpeed() const {
    return speed_;
}

std::string Mob::getRace() const {
    return race_;
}

std::string Mob::getName() const {
    return name_;
}

int Mob::getAction() const {
    return action_;
}

int Mob::getHealthPoints() const {
    return healthPoints_;
}

// Setters
void Mob::setSpeed(int speed)
{
    speed_ = speed;
}

void Mob::setRace(std::string& race) {
    race_ = race;
}

void Mob::setName(std::string& name) {
    name_ = name;
}

void Mob::setAction(int action) {
    action_ = action;
}

void Mob::setHealthPoints(int healthPoints) {
    if(healthPoints_ + healthPoints >= initialHealPoints_)
    {
        healthPoints_ = initialHealPoints_;
    }
    else healthPoints_ += healthPoints;
}

void Mob::attack(Mob& mobAttacker)
{
    healthPoints_ -= mobAttacker.attackDamage_ - defensePoints_;
    if(healthPoints_ < 0)
    {
        healthPoints_ = 0;
    }
}
void Mob::parry()
{
    if(paryOn_ == -1)
    {
        paryOn_ = 2;
        defensePoints_ += bonusDefense;
    }
   
}
void Mob::heal()
{
    setHealthPoints(3);
}
void Mob::paryOnDecrement()
{
    if (paryOn_ > 0)
    {
        paryOn_--;
    }
    else if (paryOn_ == 0)
    {
        defensePoints_-= bonusDefense;
        paryOn_ =-1;
    }
    //std::cout << name_ << " pary on status is on :" << paryOn_ << "\n";
}
bool Mob::isAlive()
{
    return healthPoints_ > 0;
}



