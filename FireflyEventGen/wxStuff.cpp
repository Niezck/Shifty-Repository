#include "wxStuff.h"

EventWindow::EventWindow(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{
    srand(time(NULL));
    wxInitAllImageHandlers();
    
    panel = new wxPanel(this,-1);
    mainbook = new wxNotebook(panel,-1);
    
    basicpanel = new wxPanel(mainbook,-1);
    typepanel = new wxPanel(mainbook,-1);
    optionApanel = new wxPanel(mainbook,-1);
    optionBpanel = new wxPanel(mainbook,-1);
    optionCpanel = new wxPanel(mainbook,-1);
    optionDpanel = new wxPanel(mainbook,-1);
    optionEpanel = new wxPanel(mainbook,-1);
    optionFpanel = new wxPanel(mainbook,-1);
    
    GenerateBasicPage();
    GenerateTypePage();
    
    mainbook->AddPage(basicpanel,wxT("Event Basics"),true,-1);
    mainbook->AddPage(typepanel,wxT("Event Type"),false,-1);
    mainbook->AddPage(optionApanel,wxT("Option A"),false,1);
    mainbook->AddPage(optionBpanel,wxT("Option B"),false,1);
    mainbook->AddPage(optionCpanel,wxT("Option C"),false,1);
    mainbook->AddPage(optionDpanel,wxT("Option D"),false,1);
    mainbook->AddPage(optionEpanel,wxT("Option E"),false,1);
    mainbook->AddPage(optionFpanel,wxT("Option F"),false,1);
    
    panelsizer = new wxBoxSizer(wxVERTICAL);
    panelsizer->Add(mainbook,1,wxALL|wxEXPAND,5);
    panel->SetSizer(panelsizer);
    vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(panel,1,wxALL|wxEXPAND,0);
    SetSizer(vbox);
    Centre();
    location->SetSelection(0);
    priority->SetSelection(0);
}

void EventWindow::GenerateTypePage()
{
    type = new wxListBox(typepanel,ID_TYPELIST);
    type->SetExtraStyle(wxLB_SINGLE|wxLB_HSCROLL);
    typetext = new wxStaticText(typepanel,-1,wxT("Event Type"));
    typeinfo = new wxTextCtrl(typepanel,-1,wxT("Information about the selected event type"),wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE|wxTE_READONLY,wxDefaultValidator,wxT(""));
    
    typeoptiontext1 = new wxStaticText(typepanel,-1,wxT("Option A Type"));
    typeoptiontext2 = new wxStaticText(typepanel,-1,wxT("Option B Type"));
    typeoptiontext3 = new wxStaticText(typepanel,-1,wxT("Option C Type"));
    typeoptiontext4 = new wxStaticText(typepanel,-1,wxT("Option D Type"));
    typeoptiontext5 = new wxStaticText(typepanel,-1,wxT("Option E Type"));
    typeoptiontext6 = new wxStaticText(typepanel,-1,wxT("Option F Type"));
    
    typeoption1 = new OptionChoice(typepanel,ID_OPTIONA);
    typeoption2 = new OptionChoice(typepanel,ID_OPTIONB);
    typeoption3 = new OptionChoice(typepanel,ID_OPTIONC);
    typeoption4 = new OptionChoice(typepanel,ID_OPTIOND);
    typeoption5 = new OptionChoice(typepanel,ID_OPTIONE);
    typeoption6 = new OptionChoice(typepanel,ID_OPTIONF);
    
    typehbox = new wxBoxSizer(wxHORIZONTAL);
    typevbox = new wxBoxSizer(wxVERTICAL);
    typevbox1 = new wxBoxSizer(wxVERTICAL);
    typehbox1 = new wxBoxSizer(wxHORIZONTAL);
    typehbox2 = new wxBoxSizer(wxHORIZONTAL);
    typehbox3 = new wxBoxSizer(wxHORIZONTAL);
    typehbox4 = new wxBoxSizer(wxHORIZONTAL);
    typehbox5 = new wxBoxSizer(wxHORIZONTAL);
    typehbox6 = new wxBoxSizer(wxHORIZONTAL);
    
    typehbox1->Add(typeoptiontext1,0,wxALL|wxEXPAND,5);
    typehbox1->Add(typeoption1,1,wxALL|wxEXPAND,5);
    typehbox2->Add(typeoptiontext2,0,wxALL|wxEXPAND,5);
    typehbox2->Add(typeoption2,1,wxALL|wxEXPAND,5);
    typehbox3->Add(typeoptiontext3,0,wxALL|wxEXPAND,5);
    typehbox3->Add(typeoption3,1,wxALL|wxEXPAND,5);
    typehbox4->Add(typeoptiontext4,0,wxALL|wxEXPAND,5);
    typehbox4->Add(typeoption4,1,wxALL|wxEXPAND,5);
    typehbox5->Add(typeoptiontext5,0,wxALL|wxEXPAND,5);
    typehbox5->Add(typeoption5,1,wxALL|wxEXPAND,5);
    typehbox6->Add(typeoptiontext6,0,wxALL|wxEXPAND,5);
    typehbox6->Add(typeoption6,1,wxALL|wxEXPAND,5);
    
    typevbox1->Add(typeinfo,1,wxALL|wxEXPAND,5);
    typevbox1->Add(typehbox1,0,wxALL|wxEXPAND,2);
    typevbox1->Add(typehbox2,0,wxALL|wxEXPAND,2);
    typevbox1->Add(typehbox3,0,wxALL|wxEXPAND,2);
    typevbox1->Add(typehbox4,0,wxALL|wxEXPAND,2);
    typevbox1->Add(typehbox5,0,wxALL|wxEXPAND,2);
    typevbox1->Add(typehbox6,0,wxALL|wxEXPAND,2);
    typevbox->Add(typetext,0,wxALL|wxEXPAND,5);
    typevbox->Add(type,1,wxALL|wxEXPAND,5);
    typehbox->Add(typevbox,1,wxALL|wxEXPAND,10);
    typehbox->Add(typevbox1,1,wxALL|wxEXPAND,10);
    
    
    typepanel->SetSizer(typehbox);
}

void EventWindow::GenerateBasicPage()
{
    description = new wxTextCtrl(basicpanel,-1,wxT("Captain's Log Entry"),wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE,wxDefaultValidator,wxT(""));
    priority = new wxChoice(basicpanel,-1);
    location = new wxChoice(basicpanel,ID_LOCATIONLIST);
    descriptiontxt = new wxStaticText(basicpanel,-1,wxT("Captain's Log Entry"));
    prioritytxt = new wxStaticText(basicpanel,-1,wxT("Event Priority"));
    locationtxt = new wxStaticText(basicpanel,-1,wxT("Location"));
    basicvbox = new wxBoxSizer(wxVERTICAL);
    basichbox = new wxBoxSizer(wxHORIZONTAL);
    basicvbox1 = new wxBoxSizer(wxVERTICAL);
    basicvbox2 = new wxBoxSizer(wxVERTICAL);
    basicvbox3 = new wxBoxSizer(wxVERTICAL);

    basicvbox1->Add(prioritytxt,0,wxALL|wxEXPAND,5);
    basicvbox1->Add(priority,1,wxALL|wxEXPAND,5);
    basicvbox2->Add(locationtxt,0,wxALL|wxEXPAND,5);
    basicvbox2->Add(location,1,wxALL|wxEXPAND,5);
    basicvbox3->Add(descriptiontxt,0,wxALL|wxEXPAND,5);
    basicvbox3->Add(description,1,wxALL|wxEXPAND,5);
    basichbox->Add(basicvbox1,1,wxALL|wxEXPAND,10);
    basichbox->Add(basicvbox2,1,wxALL|wxEXPAND,10);
    basicvbox->Add(basichbox,2,wxALL|wxEXPAND,10);
    basicvbox->Add(basicvbox3,1,wxALL|wxEXPAND,10);
    basicpanel->SetSizer(basicvbox);

    for (int x = 1;x<=10;x++)
    {
        stringstream ss;
        ss<<x;
        wxString foo(ss.str().c_str(),wxConvUTF8);
        priority->Append(foo);
    }
    location->Append(wxT("Space"));
    location->Append(wxT("Planetside"));
}

void EventWindow::OnLocation(wxCommandEvent &event)
{
    int sel = event.GetSelection();
    type->Clear();
    type->Append(wxT("Positive Crew Interaction"));
    type->Append(wxT("Negative Crew Interaction"));
    type->Append(wxT("Positive Comm Interaction"));
    type->Append(wxT("Negative Comm Interaction"));
    if (sel == 0)
    {
        type->Append(wxT("Positive Ship Interaction"));
        type->Append(wxT("Negative Ship Interaction"));
    }
    else
    {
        type->Append(wxT("Positive Native Interaction"));
        type->Append(wxT("Negative Native Interaction"));
    }
    type->Append(wxT("REAVERS!"));
}

void EventWindow::OnType(wxCommandEvent &event)
{
    int sel = event.GetSelection();
    int loc = location->GetSelection();
    wxString out;
    if (loc == 0)
    {
        out<<wxT("Info about Space ");
        switch(sel)
        {
            case 0:
                out<<wxT("Positive Crew Event");
                break;
            case 1:
                out<<wxT("Negative Crew Event");
                break;
            case 2:
                out<<wxT("Positive Comm Event");
                break;
            case 3:
                out<<wxT("Negative Comm Event");
                break;
            case 4:
                out<<wxT("Positive Ship Event");
                break;
            case 5:
                out<<wxT("Negative Ship Event");
                break;
            case 6:
                out<<wxT("REAVERS!");
                break;
            default:
                break;
        }
    }
    else if (loc == 1)
    {
        out<<wxT("Info about Planetside ");
        switch(sel)
        {
            case 0:
                out<<wxT("Positive Crew Event");
                break;
            case 1:
                out<<wxT("Negative Crew Event");
                break;
            case 2:
                out<<wxT("Positive Comm Event");
                break;
            case 3:
                out<<wxT("Negative Comm Event");
                break;
            case 4:
                out<<wxT("Positive Native Event");
                break;
            case 5:
                out<<wxT("Negative Native Event");
                break;
            case 6:
                out<<wxT("REAVERS!");
                break;
            default:
                break;
        }
    }
    typeinfo->ChangeValue(out);
    typeoption1->SetOptions(loc,sel);
    typeoption2->SetOptions(loc,sel);
    typeoption3->SetOptions(loc,sel);
    typeoption4->SetOptions(loc,sel);
    typeoption5->SetOptions(loc,sel);
    typeoption6->SetOptions(loc,sel);
}

BEGIN_EVENT_TABLE(EventWindow,wxFrame)
    EVT_CHOICE(ID_LOCATIONLIST,EventWindow::OnLocation)
    EVT_LISTBOX(ID_TYPELIST,EventWindow::OnType)
END_EVENT_TABLE()
