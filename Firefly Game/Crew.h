#pragma once
#include "Object.h"
#include "Place.h"
#include "Includes.h"

class Crew
{
    public:
        wxString name;
        wxString description;
        wxBitmap portrait;
        int gender;
        int age;
        int skills[100];
        int morale;
        int discipline;
        Object equipment[10];
        Object owneditems[100];
        int relationships[10];
        Place liked, disliked;
        Object liked, disliked;
        Crew liked, disliked;
        int liked, disliked;
};
