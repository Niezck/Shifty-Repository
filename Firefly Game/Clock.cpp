#include "Clock.h"
#include "wxStuff.h"

Clock::Clock()
{
    dayspermonth[0], dayspermonth[2], dayspermonth[4], dayspermonth[5], dayspermonth[7], dayspermonth[9], dayspermonth[11] = 31;
    dayspermonth[3], dayspermonth[5], dayspermonth[6], dayspermonth[8] = 30;
    if (year%4 == 0)
    {
        dayspermonth[1] = 29;
    }
    else
    {
        dayspermonth[1] = 28;
    }
    monthsperyear = 12;
}

void Clock::UpdateTime(int dur)
{
    if (dur > 0)
    {
        state += dur;
        while (state > 4)
        {
            if (state > 4)
            {
                state -= 4;
                day++;
                // Day update code here
            }
            else
            {
                break;
            }
        }
        while (day > dayspermonth[month-1])
        {
            if (day > dayspermonth[month-1])
            {            
                day -= dayspermonth[month-1];
                month++;
                // Month update code here
            }
            else
            {
                break;
            }
        }
        while (month > monthsperyear)
        {
            if (month > monthsperyear)
            {
                month -= monthsperyear;
                year++;
                if (year%4 == 0)
                {
                    dayspermonth[1] = 29;
                }
                else
                {
                    dayspermonth[1] = 28;
                }                
                //Year update code here
            }
            else
            {
                break;
            }
        }
    }
    else
    {
    }
}

string Clock::TimeString()
{
        string retstr = "";
        switch (state)
        {
            case 1:
                retstr.append("Morning, ");
                break;
            case 2:
                retstr.append("Afternoon, ");
                break;
            case 3:
                retstr.append("Evening, ");
                break;
            case 4:
                retstr.append("Night, ");
                break;
            default:
                break;
        }
        switch (day)
        {
            case 1:
                retstr.append("1st ");
                break;
            case 2:
                retstr.append("2nd ");
                break;
            case 3:
                retstr.append("3rd ");
                break;
            case 4:
                retstr.append("4th ");
                break;
            case 5:
                retstr.append("5th ");
                break;
            case 6:
                retstr.append("6th ");
                break;
            case 7:
                retstr.append("7th ");
                break;
            case 8:
                retstr.append("8th ");
                break;
            case 9:
                retstr.append("9th ");
                break;
            case 10:
                retstr.append("10th ");
                break;
            case 11:
                retstr.append("11th ");
                break;
            case 12:
                retstr.append("12th ");
                break;
            case 13:
                retstr.append("13th ");
                break;
            case 14:
                retstr.append("14th ");
                break;
            case 15:
                retstr.append("15th ");
                break;
            case 16:
                retstr.append("16th ");
                break;
            case 17:
                retstr.append("17th ");
                break;
            case 18:
                retstr.append("18th ");
                break;
            case 19:
                retstr.append("19th ");
                break;
            case 20:
                retstr.append("20th ");
                break;
            case 21:
                retstr.append("21st ");
                break;
            case 22:
                retstr.append("22nd ");
                break;
            case 23:
                retstr.append("23rd ");
                break;
            case 24:
                retstr.append("24th ");
                break;
            case 25:
                retstr.append("25th ");
                break;
            case 26:
                retstr.append("26th ");
                break;
            case 27:
                retstr.append("27th ");
                break;
            case 28:
                retstr.append("28th ");
                break;
            case 29:
                retstr.append("29th ");
                break;
            case 30:
                retstr.append("30th ");
                break;
            case 31:
                retstr.append("31st ");
                break;
            default:
                break;
        }
        switch (month)
        {
            case 1:
                retstr.append("January, ");
                break;
            case 2:
                retstr.append("February, ");
                break;
            case 3:
                retstr.append("March, ");
                break;
            case 4:
                retstr.append("April, ");
                break;
            case 5:
                retstr.append("May, ");
                break;
            case 6:
                retstr.append("June, ");
                break;
            case 7:
                retstr.append("July, ");
                break;
            case 8:
                retstr.append("August, ");
                break;
            case 9:
                retstr.append("September, ");
                break;
            case 10:
                retstr.append("October, ");
                break;
            case 11:
                retstr.append("November, ");
                break;
            case 12:
                retstr.append("December, ");
                break;
            default:
                break;
        }
        stringstream ss;
        ss<<retstr<<year;
        return ss.str();
}

wxString Clock::wxTimeString()
{
        wxString ret;
        string retstr;
        
        switch (state)
        {
            case 1:
                retstr.append("Morning, ");
                break;
            case 2:
                retstr.append("Afternoon, ");
                break;
            case 3:
                retstr.append("Evening, ");
                break;
            case 4:
                retstr.append("Night, ");
                break;
            default:
                break;
        }
        switch (day)
        {
            case 1:
                retstr.append("1st ");
                break;
            case 2:
                retstr.append("2nd ");
                break;
            case 3:
                retstr.append("3rd ");
                break;
            case 4:
                retstr.append("4th ");
                break;
            case 5:
                retstr.append("5th ");
                break;
            case 6:
                retstr.append("6th ");
                break;
            case 7:
                retstr.append("7th ");
                break; 
            case 8:
                retstr.append("8th ");
                break;
            case 9:
                retstr.append("9th ");
                break;
            case 10:
                retstr.append("10th ");
                break;                     
            case 11:
                retstr.append("11th ");
                break;
            case 12:
                retstr.append("12th ");
                break;
            case 13:
                retstr.append("13th ");
                break;
            case 14:
                retstr.append("14th ");
                break;
            case 15:
                retstr.append("15th ");
                break;
            case 16:
                retstr.append("16th ");
                break;
            case 17:
                retstr.append("17th ");
                break;
            case 18:
                retstr.append("18th ");
                break;
            case 19:
                retstr.append("19th ");
                break;
            case 20:
                retstr.append("20th ");
                break;
            case 21:
                retstr.append("21st ");
                break;
            case 22:
                retstr.append("22nd ");
                break;
            case 23:
                retstr.append("23rd ");
                break;
            case 24:
                retstr.append("24th ");
                break;
            case 25:
                retstr.append("25th ");
                break;
            case 26:
                retstr.append("26th ");
                break;
            case 27:
                retstr.append("27th ");
                break;
            case 28:
                retstr.append("28th ");
                break;
            case 29:
                retstr.append("29th ");
                break;
            case 30:
                retstr.append("30th ");
                break;
            case 31:
                retstr.append("31st ");
                break;
            default:
                break;
        }
        switch (month)
        {
            case 1:
                retstr.append("January, ");
                break;
            case 2:
                retstr.append("February, ");
                break;
            case 3:
                retstr.append("March, ");
                break;
            case 4:
                retstr.append("April, ");
                break;
            case 5:
                retstr.append("May, ");
                break;
            case 6:
                retstr.append("June, ");
                break;
            case 7:
                retstr.append("July, ");
                break;
            case 8:
                retstr.append("August, ");
                break;
            case 9:
                retstr.append("September, ");
                break;
            case 10:
                retstr.append("October, ");
                break;
            case 11:
                retstr.append("November, ");
                break;
            case 12:
                retstr.append("December, ");
                break;
            default:
                break;
        }
        stringstream ss;
        ss<<retstr<<year;
        ret = wxString(ss.str().c_str(),wxConvUTF8);
        return ret;
}
