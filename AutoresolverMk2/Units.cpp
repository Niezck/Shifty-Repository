#include "Units.h"

Ship::Ship()
{
    maxhp = 0;
    currenthp = 0;
    power = 0;
    shieldmit = 0;
    shieldstr = 0;
    commandedby = 0;
    commanded = 0;
    alive = true;
    used = true;
}

Ship::~Ship()
{
    
}

void CommandShip::SetBonus()
{
    if (rating%2 == 0) {bonus = rating/2;}
    else if (rating%2 != 0) {bonus = (rating+1)/2;}
}

Ship Player[100];
Ship AI[100];
CommandShip PlayerCommand[10];
CommandShip AICommand[10];
