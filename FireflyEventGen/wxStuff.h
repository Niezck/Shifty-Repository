#pragma once
#include "Includes.h"
#include "OptionChoice.h"

class EventWindow : public wxFrame
{
public:
    EventWindow(const wxString& title);
    
    void OnLocation(wxCommandEvent &event);
    void OnType(wxCommandEvent &event);
    
    void GenerateBasicPage();
    void GenerateTypePage();
    void GenerateOptionA();
    void GenerateOptionB();
    void GenerateOptionC();
    void GenerateOptionD();
    void GenerateOptionE();
    void GenerateOptionF();
    
    
    wxBoxSizer *vbox;
    wxBoxSizer *panelsizer;
    wxPanel *panel;
    wxNotebook *mainbook;
    wxPanel *basicpanel;
    wxPanel *typepanel;
    wxPanel *optionApanel, *optionBpanel, *optionCpanel, *optionDpanel, *optionEpanel, *optionFpanel;
    
    //Basic Panel Stuff
    wxTextCtrl *description;
    wxChoice *priority;
    wxChoice *location;
    wxStaticText *descriptiontxt;
    wxStaticText *prioritytxt;
    wxStaticText *locationtxt;
    wxBoxSizer *basicvbox;
    wxBoxSizer *basichbox;
    wxBoxSizer *basicvbox1, *basicvbox2, *basicvbox3;
    
    //Type Panel Stuff
    wxListBox *type;
    wxStaticText *typetext;
    wxTextCtrl *typeinfo;
    wxBoxSizer *typevbox;
    wxBoxSizer *typehbox;
    wxStaticText *typeoptiontext1, *typeoptiontext2, *typeoptiontext3, *typeoptiontext4, *typeoptiontext5, *typeoptiontext6;
    OptionChoice *typeoption1, *typeoption2, *typeoption3, *typeoption4, *typeoption5, *typeoption6;
    wxBoxSizer *typehbox1, *typehbox2, *typehbox3, *typehbox4, *typehbox5, *typehbox6;
    wxBoxSizer *typevbox1;
    
    //Options Panel stuff
    wxTextCtrl *optiondescription[6];
    wxStaticText *option[6];
    
    private:
        DECLARE_EVENT_TABLE()
    
};

enum
{
ID_LOCATIONLIST = wxID_HIGHEST,
ID_TYPELIST,
ID_OPTIONA,
ID_OPTIONB,
ID_OPTIONC,
ID_OPTIOND,
ID_OPTIONE,
ID_OPTIONF,
};
