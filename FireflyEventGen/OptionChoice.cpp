#include "OptionChoice.h"

OptionChoice::OptionChoice(wxWindow *par, wxWindowID cid)
        : wxChoice(par,cid)
{
    
}

void OptionChoice::SetOptions(int loc, int type)
{
    if (loc == 0)
    {
        switch (type)
        {
            case 0:
                break;
            default:
                break;
        }
    }
    else if (loc == 1)
    {
        switch (type)
        {
            case 0:
                break;
            default:
                break;
        }                
    }
}
