#pragma once
#include "Includes.h"
#include "Object.h"
#include "Clock.h"

class GameWindow : public wxFrame
{
public:
    GameWindow(const wxString& title);
    
    Clock shiptime;
    wxMenuBar *menu;
    wxMenu *file;
    
    void OnExit(wxCommandEvent &event);
    
    void MainMenu();
    void NewGame(wxCommandEvent &event);
    
    void CreateMainControls();
    void CreateStartingControls();
    void CreateFirstCaptainControl();
    void CreateCaptainControls();
    void CreateDealerControls();
    void GenerateShips();
    
    void BackgroundA(wxCommandEvent &event);
    void BackgroundB(wxCommandEvent &event);
    void BackgroundC(wxCommandEvent &event);
    void BackgroundD(wxCommandEvent &event);
    void BackgroundE(wxCommandEvent &event);
    void BackgroundF(wxCommandEvent &event);
    void AdvanceCaptain(wxCommandEvent &event);
    void AdvanceBackgroundA(wxCommandEvent &event);
    void AdvanceBackgroundB(wxCommandEvent &event);
    void AdvanceBackgroundC(wxCommandEvent &event);
    void AdvanceBackgroundD(wxCommandEvent &event);
    void AdvanceBackgroundE(wxCommandEvent &event);
    void AdvanceBackgroundF(wxCommandEvent &event);
    void RestoreBackgrounds(wxCommandEvent &event);
    void AllegianceA(wxCommandEvent &event);
    void AllegianceI(wxCommandEvent &event);
    void AllegianceN(wxCommandEvent &event);
    void AdvanceAllegianceA(wxCommandEvent &event);
    void AdvanceAllegianceI(wxCommandEvent &event);
    void AdvanceAllegianceN(wxCommandEvent &event);
    void RestoreAllegiances(wxCommandEvent &event);
    void JobA(wxCommandEvent &event);
    void JobB(wxCommandEvent &event);
    void JobC(wxCommandEvent &event);
    void JobD(wxCommandEvent &event);
    void JobE(wxCommandEvent &event);
    void JobF(wxCommandEvent &event);
    void AdvanceJobA(wxCommandEvent &event);
    void AdvanceJobB(wxCommandEvent &event);
    void AdvanceJobC(wxCommandEvent &event);
    void AdvanceJobD(wxCommandEvent &event);
    void AdvanceJobE(wxCommandEvent &event);
    void AdvanceJobF(wxCommandEvent &event);
    void RestoreJobs(wxCommandEvent &event);
    void PerkA(wxCommandEvent &event);
    void PerkB(wxCommandEvent &event);
    void PerkC(wxCommandEvent &event);
    void PerkD(wxCommandEvent &event);
    void PerkE(wxCommandEvent &event);
    void PerkF(wxCommandEvent &event);
    void AdvancePerkA(wxCommandEvent &event);
    void AdvancePerkB(wxCommandEvent &event);
    void AdvancePerkC(wxCommandEvent &event);
    void AdvancePerkD(wxCommandEvent &event);
    void AdvancePerkE(wxCommandEvent &event);
    void AdvancePerkF(wxCommandEvent &event);
    void RestorePerks(wxCommandEvent &event);
    
    void ShipyardA(wxCommandEvent &event);
    void ShipyardB(wxCommandEvent &event);
    void ShipyardC(wxCommandEvent &event);
    void ShipyardD(wxCommandEvent &event);
    void ShipyardE(wxCommandEvent &event);
    void ShipyardF(wxCommandEvent &event);
    void ShipyardAdvanceA(wxCommandEvent &event);
    void ShipyardAdvanceB(wxCommandEvent &event);
    void ShipyardAdvanceC(wxCommandEvent &event);
    void ShipyardAdvanceD(wxCommandEvent &event);
    void ShipyardAdvanceE(wxCommandEvent &event);
    void ShipyardAdvanceF(wxCommandEvent &event);
    void RestoreShipyard(wxCommandEvent &event);
    void SetShipName(wxCommandEvent &event);
    
    void ChoiceA(wxCommandEvent &event);
    void ChoiceB(wxCommandEvent &event);
    void ChoiceC(wxCommandEvent &event);
    void ChoiceD(wxCommandEvent &event);
    void ChoiceE(wxCommandEvent &event);
    void ChoiceF(wxCommandEvent &event);
    
    wxString GenerateShipyardText(int sel);
    
    wxBitmap locked64, locked128, back;
    
    //------Main Menu
    wxBitmapButton *newgame;
    wxButton *loadgame;
    wxStaticBitmap *menubackground;
    wxBoxSizer *mainmenuhbox;
    wxBoxSizer *vbox;
    
    //------General Interface
    wxLogTextCtrl *captainslog;
    wxTextCtrl *captainsctrl;
    wxButton *A;
    wxButton *B;
    wxButton *C;
    wxButton *D;
    wxButton *E;
    wxButton *F;
    wxNotebook *mainbook;
    wxNotebook *logbook;
    wxPanel *leftpanel;
    wxPanel *rightpanel;
    wxPanel *logpanel;
    
    //------Captain interface
    wxPanel *captainpanel;
    wxBoxSizer *captainvbox;
    
    //General Information
    wxTextCtrl *name;
    wxChoice *age;
    wxChoice *gender;
    wxChoice *hair;
    wxChoice *eyes;
    wxStaticText *nametext;
    wxStaticText *agetext;
    wxStaticText *gendertext;
    wxStaticText *hairtext;
    wxStaticText *eyestext;
    wxButton *captainadvance;
    wxStaticText *captainname;
    wxStaticText *captainage;
    wxStaticText *captaingender;
    wxStaticText *captainhair;
    wxStaticText *captaineyes;
    wxBoxSizer *captainfirstvbox;
    wxBoxSizer *captainfirsthbox1;
    wxBoxSizer *captainfirsthbox2;
    wxBoxSizer *captainfirsthbox3;
    wxBoxSizer *captainfirsthbox4;
    wxBoxSizer *captainfirsthbox5;
    
    //Background Information
    wxBitmap dice[2];
    wxBitmap ship[2];
    wxBitmap money[2];
    wxBitmap friends[2];
    wxTextCtrl *pathdesc;
    wxBitmapButton *pathbmp;
    wxButton *backgroundadvancea;
    wxButton *backgroundadvanceb;
    wxButton *backgroundadvancec;
    wxButton *backgroundadvanced;
    wxButton *backgroundadvancee;
    wxButton *backgroundadvancef;
    wxBitmapButton *backgrounda;
    wxBitmapButton *backgroundb;
    wxBitmapButton *backgroundc;
    wxBitmapButton *backgroundd;
    wxBitmapButton *backgrounde;
    wxBitmapButton *backgroundf;
    wxGridSizer *captaingsizer;
    wxBoxSizer *captainbacksizera;
    wxBoxSizer *captainbacksizerb;
    wxBoxSizer *captainbacksizerc;
    wxBoxSizer *captainbacksizerd;
    wxBoxSizer *captainbacksizere;
    wxBoxSizer *captainbacksizerf;
    wxStaticText *backtexta;
    wxStaticText *backtextb;
    wxStaticText *backtextc;
    wxStaticText *backtextd;
    wxStaticText *backtexte;
    wxStaticText *backtextf;
    
    //Allegiance Information
    wxBitmapButton *alliance;
    wxBitmapButton *indeps;
    wxBitmapButton *neutral;
    wxStaticText *alliancetext;
    wxStaticText *indepstext;
    wxStaticText *neutraltext;
    wxTextCtrl *allegiancedesc;
    wxBitmapButton *allegiancebmp;
    wxBitmap allianceflag[2];
    wxBitmap indepsflag[2];
    wxBitmap neutralflag[2];
    wxButton *allegianceadvancea;
    wxButton *allegianceadvancei;
    wxButton *allegianceadvancen;
    wxBoxSizer *alliancesizer;
    wxBoxSizer *indepssizer;
    wxBoxSizer *neutralsizer;
    
    //Job Information
    wxBitmapButton *joba;
    wxBitmapButton *jobb;
    wxBitmapButton *jobc;
    wxBitmapButton *jobd;
    wxBitmapButton *jobe;
    wxBitmapButton *jobf;
    wxStaticText *jobtexta;
    wxStaticText *jobtextb;
    wxStaticText *jobtextc;
    wxStaticText *jobtextd;
    wxStaticText *jobtexte;
    wxStaticText *jobtextf;
    wxGridSizer *jobgsizer;
    wxBoxSizer *jobsizera;
    wxBoxSizer *jobsizerb;
    wxBoxSizer *jobsizerc;
    wxBoxSizer *jobsizerd;
    wxBoxSizer *jobsizere;
    wxBoxSizer *jobsizerf;
    wxButton *jobadvancea;
    wxButton *jobadvanceb;
    wxButton *jobadvancec;
    wxButton *jobadvanced;
    wxButton *jobadvancee;
    wxButton *jobadvancef;
    wxBitmapButton *jobbmp;
    wxTextCtrl *jobdesc;
    wxBitmap criminal[2];
    wxBitmap companion[2];
    wxBitmap jack[2];
    wxBitmap trader[2];
    wxBitmap shepherd[2];
    wxBitmap soldier[2];
    
    //Perk Information
    wxBitmapButton *perka;
    wxBitmapButton *perkb;
    wxBitmapButton *perkc;
    wxBitmapButton *perkd;
    wxBitmapButton *perke;
    wxBitmapButton *perkf;
    wxButton *perkadvancea;
    wxButton *perkadvanceb;
    wxButton *perkadvancec;
    wxButton *perkadvanced;
    wxButton *perkadvancee;
    wxButton *perkadvancef;
    wxStaticText *perktexta;
    wxStaticText *perktextb;
    wxStaticText *perktextc;
    wxStaticText *perktextd;
    wxStaticText *perktexte;
    wxStaticText *perktextf;
    wxGridSizer *perkgsizer;
    wxBoxSizer *perksizera;
    wxBoxSizer *perksizerb;
    wxBoxSizer *perksizerc;
    wxBoxSizer *perksizerd;
    wxBoxSizer *perksizere;
    wxBoxSizer *perksizerf;
    wxBitmapButton *perkbmp;
    wxTextCtrl *perkdesc;
    wxBitmap perk1[2];
    wxBitmap perk2[2];
    wxBitmap perk3[2];
    wxBitmap perk4[2];
    wxBitmap perk5[2];
    wxBitmap perk6[2];
    
    //------Shipyard interface
    wxPanel *shipyardpanel;
    wxTextCtrl *shipyarddesc;
    wxBoxSizer *shipyardvbox;
    wxGridSizer *shipyardgsizer;
    wxBitmapButton *shipa;
    wxBitmapButton *shipb;
    wxBitmapButton *shipc;
    wxBitmapButton *shipd;
    wxBitmapButton *shipe;
    wxBitmapButton *shipf;
    wxStaticText *shiptexta;
    wxStaticText *shiptextb;
    wxStaticText *shiptextc;
    wxStaticText *shiptextd;
    wxStaticText *shiptexte;
    wxStaticText *shiptextf;
    wxBoxSizer *shipsizera;
    wxBoxSizer *shipsizerb;
    wxBoxSizer *shipsizerc;
    wxBoxSizer *shipsizerd;
    wxBoxSizer *shipsizere;
    wxBoxSizer *shipsizerf;
    wxButton *shipadvancea;
    wxButton *shipadvanceb;
    wxButton *shipadvancec;
    wxButton *shipadvanced;
    wxButton *shipadvancee;
    wxButton *shipadvancef;
    wxBitmapButton *shipback;
    wxStaticText *shipnametext;
    wxStaticBitmap *shipnamebmp;
    wxTextCtrl *shipnamectrl;
    wxButton *shipnamebutton;
    wxBoxSizer *shipnamesizer;
    
    //------Recruit interface
    wxPanel *recruitpanel;
    
    //------Jobs interface
    wxPanel *jobspanel;
    
    //------Bridge interface
    wxPanel *bridgepanel;
    wxStaticText *generalstatus;
    wxStaticBitmap *shipdisplay;    
    wxStaticBoxSizer *statussizer;
    
    //------Crew interface
    wxPanel *crewpanel;
    
    //------Store interface
    wxPanel *storepanel;
    
    //------Comms interface
    wxPanel *commspanel;
    
    //------Combat interface
    wxPanel *combatpanel;
  

    private:
        DECLARE_EVENT_TABLE()
    
};

enum
{
ID_MAINBOOK = wxID_HIGHEST,
ID_CAPLOG,
ID_CAPLOGCTRL,
ID_BUTTON_A,
ID_BUTTON_B,
ID_BUTTON_C,
ID_BUTTON_D,
ID_BUTTON_E,
ID_BUTTON_F,
ID_SHIPBUTTON_A,
ID_SHIPBUTTON_B,
ID_SHIPBUTTON_C,
ID_SHIPBUTTON_D,
ID_SHIPBUTTON_E,
ID_SHIPBUTTON_F,
ID_SHIPBUTTON_BACK,
ID_SHIPADVANCEA,
ID_SHIPADVANCEB,
ID_SHIPADVANCEC,
ID_SHIPADVANCED,
ID_SHIPADVANCEE,
ID_SHIPADVANCEF,
ID_BACKGROUNDA,
ID_BACKGROUNDB,
ID_BACKGROUNDC,
ID_BACKGROUNDD,
ID_BACKGROUNDE,
ID_BACKGROUNDF,
ID_CAPTAINADVANCE,
ID_BACKGROUND_BACK,
ID_BACKGROUNDADVANCEA,
ID_BACKGROUNDADVANCEB,
ID_BACKGROUNDADVANCEC,
ID_BACKGROUNDADVANCED,
ID_BACKGROUNDADVANCEE,
ID_BACKGROUNDADVANCEF,
ID_ALLEGIANCEA,
ID_ALLEGIANCEI,
ID_ALLEGIANCEN,
ID_ALLEGIANCEBACK,
ID_ALLEGIANCEADVANCEA,
ID_ALLEGIANCEADVANCEI,
ID_ALLEGIANCEADVANCEN,
ID_JOBA,
ID_JOBB,
ID_JOBC,
ID_JOBD,
ID_JOBE,
ID_JOBF,
ID_ADVANCEJOBA,
ID_ADVANCEJOBB,
ID_ADVANCEJOBC,
ID_ADVANCEJOBD,
ID_ADVANCEJOBE,
ID_ADVANCEJOBF,
ID_BACKJOB,
ID_PERKA,
ID_PERKB,
ID_PERKC,
ID_PERKD,
ID_PERKE,
ID_PERKF,
ID_ADVANCEPERKA,
ID_ADVANCEPERKB,
ID_ADVANCEPERKC,
ID_ADVANCEPERKD,
ID_ADVANCEPERKE,
ID_ADVANCEPERKF,
ID_PERKBACK,
ID_SETSHIPNAME,
ID_NEWGAME,
ID_LOADGAME,
};
