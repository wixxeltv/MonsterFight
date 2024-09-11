#include "Mob.h"

void Mob::attack(Mob mob)
{
    healthPoints_ -= mob.attackDamage_ - defensePoints_;
}
void Mob::pary()
{
    paryOn_ = 2;
    defensePoints_ += bonusDefense;
}
void Mob::heal()
{
    healthPoints_ += 10;
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
    }
}


