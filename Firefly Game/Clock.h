#pragma once
#include "Includes.h"


class Clock
{
    public:
    Clock();
    int state, day, month, year;
    int dayspermonth[12];
    int monthsperyear;
    string TimeString();
    wxString wxTimeString();
    void UpdateTime(int dur);
};
