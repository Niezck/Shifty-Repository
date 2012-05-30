#pragma once
#include "Includes.h"

class Object
{
    public:
        wxString name;
        wxString description;
        wxBitmap portrait;
};

class Weapon : public Object
{
    
};

class Ship : public Object
{
    public:
        Ship();
        wxBitmap shipyardportrait;
        string logname;
        int mincrew;
        int maxcrew;
        int cannons;
        int missiles;
        int hull;
        int speed;
        int cargohold;
        int cargopercrew;
        int numothers;
        wxString otherattribs[10];
};

