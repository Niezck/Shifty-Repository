#include "Includes.h"
#include "Object.h"

Ship::Ship()
{
    name = wxT("Not Available");
    description = wxT("This ship is not available.");
    logname = "Not Available";
    portrait = wxNullBitmap;
    mincrew = 0;
    maxcrew = 0;
    cannons = 0;
    missiles = 0;
    hull = 0;
    speed = 0;
    cargohold = 0;
    cargopercrew = 0;
    numothers = 0;
    for (int x=0;x<10;x++)
    {
        otherattribs[x] = wxT("");
    }
}
