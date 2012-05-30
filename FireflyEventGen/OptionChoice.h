#pragma once
#include "Includes.h"

class OptionChoice : public wxChoice
{
    public:
        OptionChoice(wxWindow *par, wxWindowID cid);
        void SetOptions(int loc, int type);
};
