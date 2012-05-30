#include "wxStuff.h"

Ship currentship;
Ship shipstats[10];
int numships;
int shipyardsel = -1;

GameWindow::GameWindow(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{
    srand(time(NULL));
    wxInitAllImageHandlers();
    
/*    menu = new wxMenuBar;
    file = new wxMenu;
    file->Append(wxID_EXIT,wxT("&Quit"));
    menu->Append(file,wxT("&File"));
    
    SetMenuBar(menu); */
    
    locked64.LoadFile(wxT("Data\\Images\\Misc\\Locked64.png"),wxBITMAP_TYPE_PNG);
    locked128.LoadFile(wxT("Data\\Images\\Misc\\Locked128.png"),wxBITMAP_TYPE_PNG);
    back.LoadFile(wxT("Data\\Images\\Misc\\back.png"),wxBITMAP_TYPE_PNG);
    
    //Define notebook panels
    
    shiptime.state = rand()%4+1;
    shiptime.day = rand()%31+1;
    shiptime.month = 1;
    shiptime.year = 2464;
    
    GenerateShips();
    MainMenu();
//    CreateDealerControls();
    
    Centre();
        
    SetIcon( wxIcon( _T("Data\\Images\\Misc\\icon.ico"), wxBITMAP_TYPE_ICO ) );
  
}

void GameWindow::CreateStartingControls()
{

    leftpanel = new wxPanel(this,-1);
    rightpanel = new wxPanel(this,-1);

    mainbook = new wxNotebook(leftpanel,ID_MAINBOOK);
    logbook = new wxNotebook(rightpanel,-1);
    
    logpanel = new wxPanel(logbook,-1);
    
    captainsctrl = new wxTextCtrl(logpanel,ID_CAPLOGCTRL,wxT(""),wxDefaultPosition,wxDefaultSize,wxTE_READONLY|wxTE_MULTILINE,wxDefaultValidator,wxT("Captain's Log"));
    captainslog = new wxLogTextCtrl(captainsctrl);    
    
    A = new wxButton(logpanel,ID_BUTTON_A,wxT("A"));
    B = new wxButton(logpanel,ID_BUTTON_B,wxT("B"));
    C = new wxButton(logpanel,ID_BUTTON_C,wxT("C"));
    D = new wxButton(logpanel,ID_BUTTON_D,wxT("D"));
    E = new wxButton(logpanel,ID_BUTTON_E,wxT("E"));
    F = new wxButton(logpanel,ID_BUTTON_F,wxT("F"));    
    
    wxBoxSizer *rightvbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *rightvbox2 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *righthbox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *leftvbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);    

    leftvbox->Add(mainbook,1,wxALL|wxEXPAND,0);
    rightvbox->Add(logbook,1,wxALL|wxEXPAND,0);

    righthbox->Add(A,1,wxALL|wxEXPAND,2);
    righthbox->Add(B,1,wxALL|wxEXPAND,2);
    righthbox->Add(C,1,wxALL|wxEXPAND,2);
    righthbox->Add(D,1,wxALL|wxEXPAND,2);
    righthbox->Add(E,1,wxALL|wxEXPAND,2);
    righthbox->Add(F,1,wxALL|wxEXPAND,2);

    rightvbox2->Add(captainsctrl,1,wxALL|wxEXPAND,5);
    rightvbox2->Add(righthbox,0,wxALL|wxEXPAND,5);
    hbox->Add(leftpanel,1,wxALL|wxEXPAND,10);
    hbox->Add(rightpanel,1,wxALL|wxEXPAND,10);
    
    logbook->AddPage(logpanel,wxT("Captain's Log"),false,-1);
    
    logpanel->SetSizer(rightvbox2);
    rightpanel->SetSizer(rightvbox);
    leftpanel->SetSizer(leftvbox);

    vbox->Add(hbox,2,wxALL|wxEXPAND,0);
    vbox->Layout();
    
   
    captainslog->SetTimestamp(NULL);
    captainslog->SetActiveTarget(captainslog);    
    
}

void GameWindow::CreateMainControls()
{
    bridgepanel = new wxPanel(mainbook,-1);
    crewpanel = new wxPanel(mainbook,-1);
    storepanel = new wxPanel(mainbook,-1);
    commspanel = new wxPanel(mainbook,-1);

    string status = "Date: 22nd February 2103\nShip Time: 6pm\nShip Class: Firefly\nShip Status: Nominal\nCrew Compliment: 7\nNearest Planet: Orilla\nWealth: 63,973";
    wxString foo(status.c_str(),wxConvUTF8);
    generalstatus = new wxStaticText(bridgepanel,-1,foo);

    statussizer = new wxStaticBoxSizer(wxVERTICAL,bridgepanel,wxT("Ship Status"));

    shipdisplay = new wxStaticBitmap(bridgepanel,-1,currentship.portrait);

    statussizer->Add(shipdisplay,0,wxALL|wxEXPAND,5);
    statussizer->Add(generalstatus,1,wxALL|wxEXPAND,5);

    bridgepanel->SetSizer(statussizer);

    mainbook->AddPage(bridgepanel,wxT("Bridge"),false,-1);
    mainbook->AddPage(crewpanel,wxT("Crew"),false,-1);
    mainbook->AddPage(storepanel,wxT("Stores"),false,-1);
    mainbook->AddPage(commspanel,wxT("Comms"),false,-1);

    string s = "\nCaptain's Entry [394]\nDiscovered Jayne and Simon brawling. Simon was getting the short end of it.\nConfined both to bunks.";
    wxString wxs(s.c_str(),wxConvUTF8);
    wxLogMessage(wxs);
    string s2 = "\nCaptain's Entry [395]\nPicked up a distress signal claiming to be from a nearby ship.\nA: View distress signal\nB: Hail them and change course to assist\nC: Ignore it, could be a pirate's ambush\nD: Change course but do not hail; ready crew for armed boarding\nE: Make ready for ship combat\nF: Tell them to piss off";
    wxString wxs2(s2.c_str(),wxConvUTF8);
    wxLogMessage(wxs2);
}    

void GameWindow::GenerateShips()
{
    numships = 6;
    shipstats[0].name = wxT("Firefly Class Transport");
    shipstats[0].description = wxT("A multipurpose, mid-bulk transport.  Commonly seen throughout the 'verse, the Firefly is a reliable workhorse. The hull's a little fragile and the nav computer rudimentary, but she's got good speed for her size.  As a purely civilian vessel, the Firefly of course has no weapon mounting capacity.");
    shipstats[0].portrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 1\\Portrait.png"),wxBITMAP_TYPE_PNG);    
    shipstats[0].shipyardportrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 1\\Shipyard.png"),wxBITMAP_TYPE_PNG);    
    shipstats[0].logname = "Firefly Class Transport";
    shipstats[0].mincrew = 3;
    shipstats[0].maxcrew = 10;
    shipstats[0].cannons = 0;
    shipstats[0].missiles = 0;
    shipstats[0].hull = 3;
    shipstats[0].speed = 3;
    shipstats[0].cargohold = 100;
    shipstats[0].cargopercrew = 15;
    shipstats[0].numothers = 1;
    shipstats[0].otherattribs[0] = wxT("All manner of nooks and crannies, if keeping things hidden is a must.");
    shipstats[1].portrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 2\\Portrait.png"),wxBITMAP_TYPE_PNG);
    shipstats[1].shipyardportrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 2\\Shipyard.png"),wxBITMAP_TYPE_PNG);    
    shipstats[2].portrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 3\\Portrait.png"),wxBITMAP_TYPE_PNG);
    shipstats[2].shipyardportrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 3\\Shipyard.png"),wxBITMAP_TYPE_PNG);
    shipstats[3].portrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 4\\Portrait.png"),wxBITMAP_TYPE_PNG);
    shipstats[3].shipyardportrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 4\\Shipyard.png"),wxBITMAP_TYPE_PNG);
    shipstats[4].portrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 5\\Portrait.png"),wxBITMAP_TYPE_PNG);
    shipstats[4].shipyardportrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 5\\Shipyard.png"),wxBITMAP_TYPE_PNG);
    shipstats[5].portrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 6\\Portrait.png"),wxBITMAP_TYPE_PNG);
    shipstats[5].shipyardportrait.LoadFile(wxT("Data\\Images\\Ships\\Ship 6\\Shipyard.png"),wxBITMAP_TYPE_PNG);
}


void GameWindow::ChoiceA(wxCommandEvent &event)
{
}

void GameWindow::ChoiceB(wxCommandEvent &event)
{
}

void GameWindow::ChoiceC(wxCommandEvent &event)
{
}

void GameWindow::ChoiceD(wxCommandEvent &event)
{
}

void GameWindow::ChoiceE(wxCommandEvent &event)
{
}

void GameWindow::ChoiceF(wxCommandEvent &event)
{
}

void GameWindow::OnExit(wxCommandEvent &event)
{
    this->Close(true);
}

BEGIN_EVENT_TABLE(GameWindow,wxFrame)
    EVT_BUTTON(ID_BUTTON_A,GameWindow::ChoiceA)
    EVT_BUTTON(ID_BUTTON_B,GameWindow::ChoiceB)
    EVT_BUTTON(ID_BUTTON_C,GameWindow::ChoiceC)
    EVT_BUTTON(ID_BUTTON_D,GameWindow::ChoiceD)
    EVT_BUTTON(ID_BUTTON_E,GameWindow::ChoiceE)
    EVT_BUTTON(ID_BUTTON_F,GameWindow::ChoiceF)
    EVT_BUTTON(ID_SHIPBUTTON_A,GameWindow::ShipyardA)
    EVT_BUTTON(ID_SHIPBUTTON_B,GameWindow::ShipyardB)
    EVT_BUTTON(ID_SHIPBUTTON_C,GameWindow::ShipyardC)
    EVT_BUTTON(ID_SHIPBUTTON_D,GameWindow::ShipyardD)
    EVT_BUTTON(ID_SHIPBUTTON_E,GameWindow::ShipyardE)
    EVT_BUTTON(ID_SHIPBUTTON_F,GameWindow::ShipyardF)
    EVT_BUTTON(ID_SHIPADVANCEA,GameWindow::ShipyardAdvanceA)
    EVT_BUTTON(ID_SHIPADVANCEB,GameWindow::ShipyardAdvanceB)
    EVT_BUTTON(ID_SHIPADVANCEC,GameWindow::ShipyardAdvanceC)
    EVT_BUTTON(ID_SHIPADVANCED,GameWindow::ShipyardAdvanceD)
    EVT_BUTTON(ID_SHIPADVANCEE,GameWindow::ShipyardAdvanceE)
    EVT_BUTTON(ID_SHIPADVANCEF,GameWindow::ShipyardAdvanceF)
    EVT_BUTTON(ID_SHIPBUTTON_BACK,GameWindow::RestoreShipyard)
    EVT_BUTTON(ID_BACKGROUNDA,GameWindow::BackgroundA)
    EVT_BUTTON(ID_BACKGROUNDB,GameWindow::BackgroundB)
    EVT_BUTTON(ID_BACKGROUNDC,GameWindow::BackgroundC)
    EVT_BUTTON(ID_BACKGROUNDD,GameWindow::BackgroundD)
    EVT_BUTTON(ID_BACKGROUNDE,GameWindow::BackgroundE)
    EVT_BUTTON(ID_BACKGROUNDF,GameWindow::BackgroundF)
    EVT_BUTTON(ID_CAPTAINADVANCE,GameWindow::AdvanceCaptain)
    EVT_BUTTON(ID_BACKGROUND_BACK,GameWindow::RestoreBackgrounds)
    EVT_BUTTON(ID_BACKGROUNDADVANCEA,GameWindow::AdvanceBackgroundA)
    EVT_BUTTON(ID_BACKGROUNDADVANCEB,GameWindow::AdvanceBackgroundB)
    EVT_BUTTON(ID_BACKGROUNDADVANCEC,GameWindow::AdvanceBackgroundC)
    EVT_BUTTON(ID_BACKGROUNDADVANCED,GameWindow::AdvanceBackgroundD)
    EVT_BUTTON(ID_BACKGROUNDADVANCEE,GameWindow::AdvanceBackgroundE)
    EVT_BUTTON(ID_BACKGROUNDADVANCEF,GameWindow::AdvanceBackgroundF)
    EVT_BUTTON(ID_ALLEGIANCEA,GameWindow::AllegianceA)
    EVT_BUTTON(ID_ALLEGIANCEI,GameWindow::AllegianceI)
    EVT_BUTTON(ID_ALLEGIANCEN,GameWindow::AllegianceN)
    EVT_BUTTON(ID_ALLEGIANCEADVANCEA,GameWindow::AdvanceAllegianceA)
    EVT_BUTTON(ID_ALLEGIANCEADVANCEI,GameWindow::AdvanceAllegianceI)
    EVT_BUTTON(ID_ALLEGIANCEADVANCEN,GameWindow::AdvanceAllegianceN)
    EVT_BUTTON(ID_ALLEGIANCEBACK,GameWindow::RestoreAllegiances)
    EVT_BUTTON(ID_JOBA,GameWindow::JobA)
    EVT_BUTTON(ID_JOBB,GameWindow::JobB)
    EVT_BUTTON(ID_JOBC,GameWindow::JobC)
    EVT_BUTTON(ID_JOBD,GameWindow::JobD)
    EVT_BUTTON(ID_JOBE,GameWindow::JobE)
    EVT_BUTTON(ID_JOBF,GameWindow::JobF)
    EVT_BUTTON(ID_ADVANCEJOBA,GameWindow::AdvanceJobA)
    EVT_BUTTON(ID_ADVANCEJOBB,GameWindow::AdvanceJobB)
    EVT_BUTTON(ID_ADVANCEJOBC,GameWindow::AdvanceJobC)
    EVT_BUTTON(ID_ADVANCEJOBD,GameWindow::AdvanceJobD)
    EVT_BUTTON(ID_ADVANCEJOBE,GameWindow::AdvanceJobE)
    EVT_BUTTON(ID_ADVANCEJOBF,GameWindow::AdvanceJobF)
    EVT_BUTTON(ID_BACKJOB,GameWindow::RestoreJobs)
    EVT_BUTTON(ID_PERKA,GameWindow::PerkA)
    EVT_BUTTON(ID_PERKB,GameWindow::PerkB)
    EVT_BUTTON(ID_PERKC,GameWindow::PerkC)
    EVT_BUTTON(ID_PERKD,GameWindow::PerkD)
    EVT_BUTTON(ID_PERKE,GameWindow::PerkE)
    EVT_BUTTON(ID_PERKF,GameWindow::PerkF)
    EVT_BUTTON(ID_ADVANCEPERKA,GameWindow::AdvancePerkA)
    EVT_BUTTON(ID_ADVANCEPERKB,GameWindow::AdvancePerkB)
    EVT_BUTTON(ID_ADVANCEPERKC,GameWindow::AdvancePerkC)
    EVT_BUTTON(ID_ADVANCEPERKD,GameWindow::AdvancePerkD)
    EVT_BUTTON(ID_ADVANCEPERKE,GameWindow::AdvancePerkE)
    EVT_BUTTON(ID_ADVANCEPERKF,GameWindow::AdvancePerkF)
    EVT_BUTTON(ID_PERKBACK,GameWindow::RestorePerks)
    EVT_BUTTON(ID_SETSHIPNAME,GameWindow::SetShipName)
    EVT_BUTTON(ID_NEWGAME,GameWindow::NewGame)
    EVT_BUTTON(wxID_EXIT,GameWindow::OnExit)
END_EVENT_TABLE()
