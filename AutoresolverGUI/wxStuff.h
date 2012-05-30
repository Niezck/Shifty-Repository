#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/listbox.h>
#include <wx/textdlg.h>
#include <wx/event.h>
#include <wx/listctrl.h>
#include <wx/aboutdlg.h>
#include <wx/mediactrl.h>
#include <wx/sound.h>
#include <string>
#include "Units.h"
#include "Resources.h"

class PreferencesDialog : public wxDialog
{
public:
    PreferencesDialog(const wxString& title, bool settings);
    void OnGo(wxCommandEvent& event);
    void OnClose(wxCommandEvent& event);
    void OnSettings(wxCommandEvent& event);
    wxCheckBox *shieldhullbox;
    wxCheckBox *mitgunbox;
    wxCheckBox *strgunbox;
    wxCheckBox *temppowerbox;
    wxCheckBox *shulldamagebox;
    wxCheckBox *shulldropbox;
    wxCheckBox *lifbox;
    wxCheckBox *pbonusbox;
    wxCheckBox *ebonusbox;
    wxCheckBox *ptempbonusbox;
    wxCheckBox *etempbonusbox;
    wxCheckBox *pfleebox;
    wxCheckBox *efleebox;
};

class AddShipDialog : public wxDialog
{
public:
    AddShipDialog(wxListBox* list, const wxString& title, bool player, bool commandbool, bool edit, wxSize size);
    void OnClose(wxCommandEvent& event);
    void OnGo(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    bool plyr;
    bool cmd;
    int sel;
    wxListBox *listi;
    wxTextCtrl *name;
    wxTextCtrl *hull;
    wxTextCtrl *power;
    wxTextCtrl *mit;
    wxTextCtrl *str;
    wxTextCtrl *command;
    wxTextCtrl *shieldhp;
    wxTextCtrl *shieldmitpwr;
    wxTextCtrl *shieldmitdur;
    wxTextCtrl *shieldstrpwr;
    wxTextCtrl *shieldstrdur;
    wxTextCtrl *temppower;
    wxTextCtrl *tempduration;
    wxTextCtrl *shulldamage;
    wxCheckBox *shulldrop;
    wxTextCtrl *shulldropdur; 
    wxStaticText *text1;
    wxStaticText *text2;
    wxStaticText *text3;
    wxStaticText *text4;
    wxStaticText *text5;
    wxStaticText *text6;
    wxStaticText *text7;
    wxStaticText *text8;
    wxStaticText *text9;
    wxStaticText *text10;
    wxStaticText *text11;
    wxStaticText *text12;
    wxStaticText *text13;
    wxStaticText *text14;
    wxStaticText *text15;
};

class AutoresolverWindow : public wxFrame
{
public:
    AutoresolverWindow(const wxString& title);
    void ClearShips(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnPreferences(wxCommandEvent& event);
    void OnSettings(wxCommandEvent& event);
    void OnNewPShip(wxCommandEvent& event);
    void OnDelPShip(wxCommandEvent& event);    
    void OnEditPShip(wxCommandEvent& event);
    void OnCopyPShip(wxCommandEvent &event);
    void OnNewEShip(wxCommandEvent& event);
    void OnDelEShip(wxCommandEvent& event);
    void OnEditEShip(wxCommandEvent& event);
    void OnCopyEShip(wxCommandEvent& event);
    void OnNewPCShip(wxCommandEvent& event);
    void OnDelPCShip(wxCommandEvent& event);
    void OnEditPCShip(wxCommandEvent& event);
    void OnCopyPCShip(wxCommandEvent& event);
    void OnNewECShip(wxCommandEvent& event);
    void OnDelECShip(wxCommandEvent& event);
    void OnEditECShip(wxCommandEvent& event);
    void OnCopyECShip(wxCommandEvent& event);
    void Autoresolve(wxCommandEvent& event);
    void OnClick1(wxCommandEvent& event);
    void OnClick2(wxCommandEvent& event);
    void OnClick3(wxCommandEvent& event);
    void OnClick4(wxCommandEvent& event);
    void PFleeClicked(wxCommandEvent& event);
    void EFleeClicked(wxCommandEvent& event);
    void PFleeShipClicked(wxCommandEvent& event);
    void EFleeShipClicked(wxCommandEvent& event);
    void UpdateDisplay1();
    void UpdateDisplay2();
    void UpdateDisplay3();
    void UpdateDisplay4();
    void GenerateDisplay1();
    void GenerateDisplay2();
    void GenerateDisplay3();
    void GenerateDisplay4();
    void UpdatePFleeHP();
    void UpdateEFleeHP();
    wxAboutDialogInfo info;
    wxListBox *pshiplist;
    wxListBox *eshiplist;
    wxListBox *pcshiplist;
    wxListBox *ecshiplist;    
    wxMenuBar *menubar;
    wxMenu *file;
    wxMenu *playership;
    wxMenu *enemyship;
    wxMenu *help;
    wxTextCtrl *pbonustxt;
    wxTextCtrl *ebonustxt;
    wxChoice *pfleetxt1;
    wxChoice *pfleetxt2;
    wxChoice *pfleetxt3;
    wxChoice *efleetxt1;
    wxChoice *efleetxt2;
    wxChoice *efleetxt3;
    wxTextCtrl *filenameget;
    wxTextCtrl *ptempbonus;
    wxTextCtrl *ptempduration;
    wxTextCtrl *etempbonus;
    wxTextCtrl *etempduration;
    wxListBox *display1;
    wxListBox *display2;
    wxListBox *display3;
    wxListBox *display4;
    wxPanel *panel;
    wxStaticText *text1;
    wxStaticText *text2;
    wxStaticText *text3;
    wxStaticText *text4;
    wxStaticText *text5;
    wxStaticText *text6;
    wxStaticText *text7;
    wxStaticText *text8;
    wxStaticText *text9;
    wxStaticText *text10;
    wxStaticText *text11;
    wxStaticText *text12;
    wxStaticText *text13;
    wxStaticText *text14;
    wxStaticText *text15;
    wxStaticText *text16;
    wxStaticText *text17;
    wxString dname[4];
    int dhull[4];
    int dshull[2];
    int dpower[4];
    int dmit[2];
    int dstr[2];
    int dcommand[2];
    int dmitpwr[2];
    int dmitdur[2];
    int dstrpwr[2];
    int dstrdur[2];
    int dtmppwr[2];
    int dtmpdur[2];
    int dshpdamage[2];
    bool dsdrop[2];
    int dsdropdur[2];
    wxString dstring[4];
};

const int ID_PSHIPBOX = 1001;
const int ID_PCSHIPBOX = 1002;
const int ID_ESHIPBOX = 1003;
const int ID_ECSHIPBOX = 1004;
const int ID_NEWPSHIP = 1006;
const int ID_NEWPCSHIP = 1007;
const int ID_DELPSHIP = 1008;
const int ID_DELPCSHIP = 1009;
const int ID_NEWESHIP = 1010;
const int ID_NEWECSHIP = 1011;
const int ID_DELESHIP = 1012;
const int ID_DELECSHIP = 1013;
const int ID_AUTORESOLVE = 1014;
const int ID_ADDSHIP = 1015;
const int ID_CANCELSHIP = 1016;
const int ID_SELECTED = 1017;
const int ID_ABOUT = 1018;
const int ID_EDITPSHIP = 1019;
const int ID_EDITPCSHIP = 1020;
const int ID_EDITESHIP = 1021;
const int ID_EDITECSHIP = 1022;
const int ID_EDITSHIP = 1023;
const int ID_TOOLADDPSHIP = 1024;
const int ID_TOOLADDPCSHIP = 1025;
const int ID_TOOLADDESHIP = 1026;
const int ID_TOOLADDECSHIP = 1027;
const int ID_TOOLDELPSHIP = 1028;
const int ID_TOOLDELPCSHIP = 1029;
const int ID_TOOLDELESHIP = 1030;
const int ID_TOOLDELECSHIP = 1031;
const int ID_TOOLEDITPSHIP = 1032;
const int ID_TOOLEDITPCSHIP = 1033;
const int ID_TOOLEDITESHIP = 1034;
const int ID_TOOLEDITECSHIP = 1035;
const int ID_TOOLCOPYPSHIP = 1036;
const int ID_TOOLCOPYPCSHIP = 1037;
const int ID_TOOLCOPYESHIP = 1038;
const int ID_TOOLCOPYECSHIP = 1039;
const int ID_COPYPSHIP = 1040;
const int ID_COPYPCSHIP = 1041;
const int ID_COPYESHIP = 1042;
const int ID_COPYECSHIP = 1043;
const int ID_PREFERENCES = 1044;
const int ID_CHANGEPREF = 1045;
const int ID_CANCELPREF = 1046;
const int ID_CLEARSHIPS = 1047;
const int ID_CHANGESETTINGS = 1048;
const int ID_SETTINGS = 1049;
const int ID_PFLEE = 1050;
const int ID_EFLEE = 1051;
const int ID_PFLEESHIP = 1052;
const int ID_EFLEESHIP = 1053;
