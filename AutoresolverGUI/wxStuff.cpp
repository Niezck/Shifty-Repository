#include "wxStuff.h"

extern int playernumber;
extern int ainumber;
extern int playercommandnumber;
extern int aicommandnumber;
extern Ship AI[1000];
extern Ship Player[1000];
extern CommandShip AICommand[100];
extern CommandShip PlayerCommand[100];
extern void ListStats();
extern void FinalStats();
extern void CombatRound();
extern void CombatRoundM();
extern void CheckStatus();
extern void CheckStatusM();
extern void SetUpPreBattle();
extern bool victory;
extern string filename;
extern string logfilename;
extern bool flee[9];
extern int fleeselection;
extern int fleehull;
extern int playerbonus;
extern int aibonus;
extern bool lif;
bool lifglobal;
bool shieldhullglobal;
bool temppowerglobal;
bool mitgunglobal;
bool strgunglobal;
bool shieldhulldamageglobal;
bool shieldhulldropglobal;
bool pfleeglobal;
bool efleeglobal;
bool ptempbonusglobal;
bool pbonusglobal;
bool etempbonusglobal;
bool ebonusglobal;
Ship OAI[1000],OPlayer[1000];
CommandShip OAICommand[100],OPlayerCommand[100];
extern void CopyOldShips();
extern int totalexchanges;
extern int playertempbonus;
extern int playertempduration;
extern int aitempbonus;
extern int aitempduration;
bool rickroll;
bool added;
bool edited;

PreferencesDialog::PreferencesDialog(const wxString& title, bool settings)
      : wxDialog(NULL,-1,title,wxDefaultPosition,wxSize(-1,520))
{
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer *bsizer1 = new wxStaticBoxSizer(wxVERTICAL,this,wxT("Combat Options"));
    wxStaticBoxSizer *bsizer2 = new wxStaticBoxSizer(wxVERTICAL,this,wxT("Ship Options"));
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    
    ebonusbox = new wxCheckBox(this,wxID_ANY,wxT("Enemy Fleet: Bonus"));
    efleebox = new wxCheckBox(this,wxID_ANY,wxT("Enemy Fleet: Flee"));
    etempbonusbox = new wxCheckBox(this,wxID_ANY,wxT("Enemy Fleet: Temporary Bonus"));
    pbonusbox = new wxCheckBox(this,wxID_ANY,wxT("Player Fleet: Bonus"));
    pfleebox = new wxCheckBox(this,wxID_ANY,wxT("Player Fleet: Flee"));
    ptempbonusbox = new wxCheckBox(this,wxID_ANY,wxT("Player Fleet: Temporary Bonus"));
    lifbox = new wxCheckBox(this,wxID_ANY,wxT("Shields: Limited Invulnerability Fields"));
    shieldhullbox = new wxCheckBox(this,wxID_ANY,wxT("Shield Hull Rating"));
    temppowerbox = new wxCheckBox(this,wxID_ANY,wxT("Temporary Power"));
    mitgunbox = new wxCheckBox(this,wxID_ANY,wxT("Shield Mitigation Damage"));
    strgunbox = new wxCheckBox(this,wxID_ANY,wxT("Shield Strength Damage"));
    shulldamagebox = new wxCheckBox(this,wxID_ANY,wxT("Shield Hull Damage"));
    shulldropbox = new wxCheckBox(this,wxID_ANY,wxT("Shield Drop"));
    
    wxButton *go;
    
    if (settings == false) {go = new wxButton(this, ID_CHANGEPREF, wxT("OK"),wxDefaultPosition); }
    else {go = new wxButton(this,ID_CHANGESETTINGS,wxT("OK"),wxDefaultPosition); }
    wxButton *cancel = new wxButton(this, ID_CANCELPREF, wxT("Cancel"),wxDefaultPosition);

    bsizer1->Add(ebonusbox,1,wxALL,5);
    bsizer1->Add(efleebox,1,wxALL,5);
    bsizer1->Add(etempbonusbox,1,wxALL,5);
    bsizer1->Add(pbonusbox,1,wxALL,5);
    bsizer1->Add(pfleebox,1,wxALL,5);
    bsizer1->Add(ptempbonusbox,1,wxALL,5);
    bsizer1->Add(lifbox,1,wxALL,5);
    vbox->Add(bsizer1,0,wxALL,10);    

    bsizer2->Add(shieldhullbox,1,wxALL,5);
    bsizer2->Add(temppowerbox,1,wxALL,5);
    bsizer2->Add(mitgunbox,1,wxALL,5);
    bsizer2->Add(strgunbox,1,wxALL,5);
    bsizer2->Add(shulldamagebox,1,wxALL,5);
    bsizer2->Add(shulldropbox,1,wxALL,5);
    vbox->Add(bsizer2,0,wxALL,10);

    hbox2->Add(go,1,wxALL,10);
    hbox2->Add(cancel,1,wxALL,10);
    vbox->Add(hbox2,0,wxBOTTOM,10);

    Connect(ID_CHANGEPREF,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(PreferencesDialog::OnGo));
    Connect(ID_CHANGESETTINGS,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(PreferencesDialog::OnSettings));
    Connect(ID_CANCELPREF,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(PreferencesDialog::OnClose));
    if (settings == false)
    {
        fstream infile("Preferences.ini");
        string line = "";
        char *out;
        for (int linenum = 1;linenum<=16;linenum++)
        {
            getline(infile,line);
            char cstr[line.size() + 1];
            strcpy(cstr,line.c_str());
            out = strtok(cstr,"=");
            out = strtok(NULL," ");
            if ((linenum == 2) && (atoi(out) == 1)) {ebonusbox->SetValue(true); }
            if ((linenum == 3) && (atoi(out) == 1)) {efleebox->SetValue(true); }
            if ((linenum == 4) && (atoi(out) == 1)) {etempbonusbox->SetValue(true); }
            if ((linenum == 5) && (atoi(out) == 1)) {pbonusbox->SetValue(true); }
            if ((linenum == 6) && (atoi(out) == 1)) {pfleebox->SetValue(true); }
            if ((linenum == 7) && (atoi(out) == 1)) {ptempbonusbox->SetValue(true); }
            if ((linenum == 8) && (atoi(out) == 1)) { lifbox->SetValue(true); }
            if ((linenum == 11) && (atoi(out) == 1)) { shieldhullbox->SetValue(true); }
            if ((linenum == 12) && (atoi(out) == 1)) { temppowerbox->SetValue(true); }
            if ((linenum == 13) && (atoi(out) == 1)) { mitgunbox->SetValue(true); }
            if ((linenum == 14) && (atoi(out) == 1)) { strgunbox->SetValue(true); }
            if ((linenum == 15) && (atoi(out) == 1)) { shulldamagebox->SetValue(true); }
            if ((linenum == 16) && (atoi(out) == 1)) { shulldropbox->SetValue(true); }
        }
        infile.close();
    }
    else
    {
        pbonusbox->SetValue(pbonusglobal);
        pfleebox->SetValue(pfleeglobal);
        ptempbonusbox->SetValue(ptempbonusglobal);
        ebonusbox->SetValue(ebonusglobal);
        efleebox->SetValue(efleeglobal);
        etempbonusbox->SetValue(etempbonusglobal);
        lifbox->SetValue(lifglobal);
        shieldhullbox->SetValue(shieldhullglobal);
        temppowerbox->SetValue(temppowerglobal);
        mitgunbox->SetValue(mitgunglobal);
        strgunbox->SetValue(strgunglobal);
        shulldamagebox->SetValue(shieldhulldamageglobal);
        shulldropbox->SetValue(shieldhulldropglobal);
    }
    

    SetSizer(vbox);
    Center();
    ShowModal();
};

void PreferencesDialog::OnSettings(wxCommandEvent &event)
{
    pbonusglobal = pbonusbox->GetValue();
    pfleeglobal = pfleebox->GetValue();
    ptempbonusglobal = ptempbonusbox->GetValue();
    ebonusglobal = ebonusbox->GetValue();
    efleeglobal = efleebox->GetValue();
    etempbonusglobal = etempbonusbox->GetValue();
    lifglobal = lifbox->GetValue();
    shieldhullglobal = shieldhullbox->GetValue();
    temppowerglobal = temppowerbox->GetValue();
    mitgunglobal = mitgunbox->GetValue();
    strgunglobal = strgunbox->GetValue();
    shieldhulldamageglobal = shulldamagebox->GetValue();
    shieldhulldropglobal = shulldropbox->GetValue();
    Destroy();
}

void PreferencesDialog::OnGo(wxCommandEvent &event)
{
    ofstream outfile;
    outfile.open("preferences.ini",ios::trunc);
    outfile<<"[Combat Options]\n";
    outfile<<"Enemy Bonus = ";
    outfile<<ebonusbox->GetValue()<<endl;
    outfile<<"Enemy Flee = ";
    outfile<<efleebox->GetValue()<<endl;
    outfile<<"Enemy Temporary Bonus = ";
    outfile<<etempbonusbox->GetValue()<<endl;
    outfile<<"Player Bonus = ";
    outfile<<pbonusbox->GetValue()<<endl;
    outfile<<"Player Flee = ";
    outfile<<pfleebox->GetValue()<<endl;
    outfile<<"Player Temporary Bonus = ";
    outfile<<ptempbonusbox->GetValue()<<endl;
    outfile<<"Shields Limited Invulnerability Fields = ";
    outfile<<lifbox->GetValue()<<endl;
    outfile<<endl;
    outfile<<"[Ship Options]\n";
    outfile<<"Shield Hull Rating = ";
    outfile<<shieldhullbox->GetValue()<<endl;
    outfile<<"Temporary Power = ";
    outfile<<temppowerbox->GetValue()<<endl;
    outfile<<"Shield Mitigation Damage = ";
    outfile<<mitgunbox->GetValue()<<endl;
    outfile<<"Shield Strength Damage = ";
    outfile<<strgunbox->GetValue()<<endl;
    outfile<<"Shield Hull Damage = ";
    outfile<<shulldamagebox->GetValue()<<endl;
    outfile<<"Shield Hull Drop = ";
    outfile<<shulldropbox->GetValue()<<endl;
    outfile.close();
    if (lifbox->GetValue()) { rickroll = true; }
    else if (!lifbox->GetValue()) { rickroll = false; }
    Destroy();
}

void PreferencesDialog::OnClose(wxCommandEvent &event)
{
    Destroy();
}

AddShipDialog::AddShipDialog(wxListBox* list, const wxString& title, bool player, bool commandbool, bool edit, wxSize size)
      : wxDialog(NULL, -1, title, wxDefaultPosition, size)
{
    sel = list->GetSelection();
    cmd = commandbool;
    plyr = player;
    listi = list;
    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *vbox1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *vbox2 = new wxBoxSizer(wxVERTICAL);
    
    
    wxGridSizer *gsizer1 = new wxGridSizer(1,1,10,10);
    wxGridSizer *gsizer2 = new wxGridSizer(1,1,10,10);

    wxString gobuttontag;
    if (edit == false) { gobuttontag = wxT("Add Ship"); }
    else { gobuttontag = wxT("Edit Ship"); }
    wxButton *go = new wxButton(this, ID_ADDSHIP, gobuttontag,wxDefaultPosition);
    wxButton *cancel = new wxButton(this, ID_CANCELSHIP, wxT("Cancel"),wxDefaultPosition);

    text1 = new wxStaticText(this,wxID_ANY,wxT("Name"));
    text2 = new wxStaticText(this,wxID_ANY,wxT("Hull Rating"));
    text3 = new wxStaticText(this,wxID_ANY,wxT("Power"));

    name = new wxTextCtrl(this,wxID_ANY);
    hull = new wxTextCtrl(this,wxID_ANY);
    if (commandbool == false)
    {
        shieldhp = new wxTextCtrl(this,wxID_ANY);
        power = new wxTextCtrl(this,wxID_ANY);
        temppower = new wxTextCtrl(this,wxID_ANY);
        tempduration = new wxTextCtrl(this,wxID_ANY);        
        mit = new wxTextCtrl(this,wxID_ANY);
        str = new wxTextCtrl(this,wxID_ANY);
        shieldmitpwr = new wxTextCtrl(this,wxID_ANY);
        shieldmitdur = new wxTextCtrl(this,wxID_ANY);
        shieldstrpwr = new wxTextCtrl(this,wxID_ANY);
        shieldstrdur = new wxTextCtrl(this,wxID_ANY);
        shulldamage = new wxTextCtrl(this,wxID_ANY);
        shulldrop = new wxCheckBox(this,wxID_ANY,wxT(""));
        shulldropdur = new wxTextCtrl(this,wxID_ANY);
        text4 = new wxStaticText(this,wxID_ANY,wxT("Shield Mitigation"));
        text5 = new wxStaticText(this,wxID_ANY,wxT("Shield Strength"));
        text6 = new wxStaticText(this,wxID_ANY,wxT("Shield Hull"));
        text7 = new wxStaticText(this,wxID_ANY,wxT("Mitigation Damage"));
        text8 = new wxStaticText(this,wxID_ANY,wxT("Mitigation Dur"));
        text9 = new wxStaticText(this,wxID_ANY,wxT("Strength Damage"));
        text10 = new wxStaticText(this,wxID_ANY,wxT("Strength Dur"));
        text11 = new wxStaticText(this,wxID_ANY,wxT("Temp Power"));
        text12 = new wxStaticText(this,wxID_ANY,wxT("Temp Dur"));
        text13 = new wxStaticText(this,wxID_ANY,wxT("Shield Hull Damage"));
        text14 = new wxStaticText(this,wxID_ANY,wxT("Shield Drop"));
        text15 = new wxStaticText(this,wxID_ANY,wxT("Shield Drop Dur"));        
        if (temppowerglobal == false) {temppower->Disable(); tempduration->Disable(); text11->Disable(); text12->Disable(); }
        if (mitgunglobal == false) {shieldmitpwr->Disable(); shieldmitdur->Disable(); text7->Disable(); text8->Disable(); }
        if (strgunglobal == false) {shieldstrpwr->Disable(); shieldstrdur->Disable(); text9->Disable(); text10->Disable(); }
        if (shieldhullglobal == false) {shieldhp->Disable(); text6->Disable(); }
        if (shieldhulldamageglobal == false) {shulldamage->Disable(); text13->Disable(); }
        if (shieldhulldropglobal == false) {shulldrop->Disable(); shulldropdur->Disable(); text14->Disable(); text15->Disable(); }
    }
    else
    {
        power = new wxTextCtrl(this,wxID_ANY);
    }
    if (edit == false) {
    if (plyr == 1)
    {
        name->AppendText(wxT("Player "));
        if (cmd == 1)
        {
            wxString foo = wxString::Format(wxT("Command Ship %i"),playercommandnumber+1);
            name->AppendText(foo);
        }
        else
        {
            wxString foo = wxString::Format(wxT("Ship %i"),playernumber+1);
            name->AppendText(foo);
        }
    }
    else
    {
         name->AppendText(wxT("Enemy "));
         if (cmd == 1)
         {
             wxString foo = wxString::Format(wxT("Command Ship %i"),aicommandnumber+1);
             name->AppendText(foo);
         }
         else
         {
             wxString foo = wxString::Format(wxT("Ship %i"),ainumber+1);
             name->AppendText(foo);
         }
    }
    hull->AppendText(wxT("0"));
    power->AppendText(wxT("0"));
    }
    else if (edit == true)
    {
        if (plyr == 1)
        {
            if (cmd == 1)
            {
                wxString foo(OPlayerCommand[sel+1].name.c_str(),wxConvUTF8);
                name->AppendText(foo);
                hull->AppendText(wxString::Format(wxT("%i"),OPlayerCommand[sel+1].maxhp));
                power->AppendText(wxString::Format(wxT("%i"),OPlayerCommand[sel+1].power));
            }
            else
            {
                wxString foo(OPlayer[sel+1].name.c_str(),wxConvUTF8);
                name->AppendText(foo);
                hull->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].maxhp));
                power->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].power));
            }
        }
        else
        {
            if (cmd == 1)
            {
                wxString foo(OAICommand[sel+1].name.c_str(),wxConvUTF8);
                name->AppendText(foo);
                hull->AppendText(wxString::Format(wxT("%i"),OAICommand[sel+1].maxhp));
                power->AppendText(wxString::Format(wxT("%i"),OAICommand[sel+1].power));
            }
            else
            {
                wxString foo(OAI[sel+1].name.c_str(),wxConvUTF8);
                name->AppendText(foo);
                hull->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].maxhp));
                power->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].power));
            }
        }
    }
    if (commandbool == 0)
    {
    if (edit == 0)
    {
    shieldhp->AppendText(wxT("0"));
    mit->AppendText(wxT("0"));
    str->AppendText(wxT("0"));
    shieldmitpwr->AppendText(wxT("0"));
    shieldmitdur->AppendText(wxT("0"));
    shieldstrpwr->AppendText(wxT("0"));
    shieldstrdur->AppendText(wxT("0"));
    temppower->AppendText(wxT("0"));
    tempduration->AppendText(wxT("0"));
    shulldamage->AppendText(wxT("0"));
    shulldrop->SetValue(false);
    shulldropdur->AppendText(wxT("0"));
    }
    else
    {
        if (plyr == 1)
        {
            mit->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].shieldmit));
            str->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].shieldstr));
            shieldhp->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].maxshp));
            shieldmitpwr->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].shieldmitpower));
            shieldmitdur->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].shieldmitduration));
            shieldstrpwr->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].shieldstrpower));
            shieldstrdur->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].shieldstrduration));
            temppower->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].temppower));
            tempduration->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].tempduration));
            shulldamage->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].shpdamage));
            shulldrop->SetValue(OPlayer[sel+1].shielddrop);
            shulldropdur->AppendText(wxString::Format(wxT("%i"),OPlayer[sel+1].shielddropdur));
        }
        else
        {
            mit->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].shieldmit));
            str->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].shieldstr));
            shieldhp->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].maxshp));
            shieldmitpwr->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].shieldmitpower));
            shieldmitdur->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].shieldmitduration));
            shieldstrpwr->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].shieldstrpower));
            shieldstrdur->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].shieldstrduration));            
            temppower->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].temppower));
            tempduration->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].tempduration));            
            shulldamage->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].shpdamage));
            shulldrop->SetValue(OAI[sel+1].shielddrop);
            shulldropdur->AppendText(wxString::Format(wxT("%i"),OAI[sel+1].shielddropdur));            
        }
    }
    wxBoxSizer *hbox6 = new wxBoxSizer(wxHORIZONTAL);
    vbox1->Add(text1,0,wxALL,5);
    vbox1->Add(text2,0,wxALL,5);
    vbox1->Add(text6,0,wxALL,5);
    vbox1->Add(text3,0,wxALL,5);
    vbox1->Add(text11,0,wxALL,5);
    vbox1->Add(text12,0,wxALL,5);
    vbox1->Add(text4,0,wxALL,5);
    vbox1->Add(text5,0,wxALL,5);
    vbox1->Add(text7,0,wxALL,5);
    vbox1->Add(text8,0,wxALL,5);
    vbox1->Add(text9,0,wxALL,5);
    vbox1->Add(text10,0,wxALL,5);
    vbox1->Add(text13,0,wxALL,5);
    vbox1->Add(text14,0,wxALL,5);
    vbox1->Add(text15,0,wxALL,5);
    gsizer1->Add(vbox1,0,wxEXPAND,5);
    hbox1->Add(gsizer1,1,wxEXPAND,5);

    vbox2->Add(name,0,wxALL,1);
    vbox2->Add(hull,0,wxALL,1);
    vbox2->Add(shieldhp,0,wxALL,1);
    vbox2->Add(power,0,wxALL,1);
    vbox2->Add(temppower,0,wxALL,1);
    vbox2->Add(tempduration,0,wxALL,1);
    vbox2->Add(mit,0,wxALL,1);
    vbox2->Add(str,0,wxALL,1);
    vbox2->Add(shieldmitpwr,0,wxALL,1);
    vbox2->Add(shieldmitdur,0,wxALL,1);
    vbox2->Add(shieldstrpwr,0,wxALL,1);
    vbox2->Add(shieldstrdur,0,wxALL,1);
    vbox2->Add(shulldamage,0,wxALL,1);
    vbox2->Add(shulldrop,1,wxALL,1);
    vbox2->Add(shulldropdur,0,wxALL,1);
    gsizer2->Add(vbox2,0,wxEXPAND,5);
    hbox1->Add(gsizer2,1,wxEXPAND,5);

    hbox2->Add(go,0,wxALL,5);
    hbox2->Add(cancel,0,wxALL,5);

    }
    else if (commandbool == 1)
    {
    command = new wxTextCtrl(this,wxID_ANY);
    if (edit == false)
    {
    command->AppendText(wxT("0"));
    }
    else
    {
        if (plyr == 1)
        {
            command->AppendText(wxString::Format(wxT("%i"),OPlayerCommand[sel+1].rating));
        }
        else
        {
            command->AppendText(wxString::Format(wxT("%i"),OAICommand[sel+1].rating));
        }
    }
    wxStaticText *text6 = new wxStaticText(this,wxID_ANY,wxT("Command"));
    vbox1->Add(text1,0,wxALL,5);
    vbox1->Add(text2,0,wxALL,5);
    vbox1->Add(text3,0,wxALL,5);
    vbox1->Add(text6,0,wxALL,5);
    gsizer1->Add(vbox1,0,wxEXPAND,5);
    hbox1->Add(gsizer1,1,wxEXPAND,5);
    
    vbox2->Add(name,0,wxALL,1);
    vbox2->Add(hull,0,wxALL,1);
    vbox2->Add(power,0,wxALL,1);
    vbox2->Add(command,0,wxALL,1);
    gsizer2->Add(vbox2,0,wxEXPAND,5);
    hbox1->Add(gsizer2,1,wxEXPAND,5);
    
    hbox2->Add(go,0,wxALL,5);
    hbox2->Add(cancel,0,wxALL,5);
    }

    Connect(ID_CANCELSHIP,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(AddShipDialog::OnClose));
    if (edit == false ) {Connect(ID_ADDSHIP,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(AddShipDialog::OnGo));}
    else  {Connect(ID_ADDSHIP,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(AddShipDialog::OnEdit));}

    vbox->Add(hbox1,0,wxEXPAND|wxALL,5);
    vbox->Add(hbox2,0,wxEXPAND|wxALL,5);
    SetSizer(vbox);
    Center();
    ShowModal();


};

void AddShipDialog::OnClose(wxCommandEvent& event)
{
    Destroy();
}

void AddShipDialog::OnEdit(wxCommandEvent& event)
{
    listi->SetString(sel,name->GetValue());
    if (cmd == 1)
    {
        if (plyr == 1)
        {
            OPlayerCommand[sel+1].name = string(name->GetValue().mb_str());
            OPlayerCommand[sel+1].power = wxAtoi(power->GetValue());
            OPlayerCommand[sel+1].maxhp = wxAtoi(hull->GetValue());
            OPlayerCommand[sel+1].rating = wxAtoi(command->GetValue());
            OPlayerCommand[sel+1].SetBonus();
            OPlayerCommand[sel+1].currenthp = OPlayerCommand[sel+1].maxhp;
        }
        else
        {
            OAICommand[sel+1].name = string(name->GetValue().mb_str());
            OAICommand[sel+1].power = wxAtoi(power->GetValue());
            OAICommand[sel+1].maxhp = wxAtoi(hull->GetValue());
            OAICommand[sel+1].rating = wxAtoi(command->GetValue());
            OAICommand[sel+1].SetBonus();
            OAICommand[sel+1].currenthp = OAICommand[sel+1].maxhp;
        }
    }
    else
    {
        if (plyr == 1)
        {
            OPlayer[sel+1].name= string(name->GetValue().mb_str());
            OPlayer[sel+1].power = wxAtoi(power->GetValue());
            OPlayer[sel+1].maxhp = wxAtoi(hull->GetValue());
            OPlayer[sel+1].shieldmit = wxAtoi(mit->GetValue());
            OPlayer[sel+1].shieldstr = wxAtoi(str->GetValue());
            OPlayer[sel+1].maxshp = wxAtoi(shieldhp->GetValue());
            OPlayer[sel+1].currentshp = OPlayer[sel+1].maxshp;
            OPlayer[sel+1].currenthp = OPlayer[sel+1].maxhp;
            OPlayer[sel+1].shieldmitpower = wxAtoi(shieldmitpwr->GetValue());
            OPlayer[sel+1].shieldmitduration = wxAtoi(shieldmitdur->GetValue());
            OPlayer[sel+1].shieldstrpower = wxAtoi(shieldstrpwr->GetValue());
            OPlayer[sel+1].shieldstrduration = wxAtoi(shieldstrdur->GetValue());
            OPlayer[sel+1].temppower = wxAtoi(temppower->GetValue());
            OPlayer[sel+1].tempduration = wxAtoi(tempduration->GetValue());
            OPlayer[sel+1].shpdamage = wxAtoi(shulldamage->GetValue());
            OPlayer[sel+1].shielddrop = shulldrop->GetValue();
            OPlayer[sel+1].shielddropdur = wxAtoi(shulldropdur->GetValue());
        }
        else
        {
            OAI[sel+1].name=string(name->GetValue().mb_str());
            OAI[sel+1].maxhp = wxAtoi(hull->GetValue());
            OAI[sel+1].power = wxAtoi(power->GetValue());
            OAI[sel+1].shieldmit = wxAtoi(mit->GetValue());
            OAI[sel+1].shieldstr = wxAtoi(str->GetValue());
            OAI[sel+1].maxshp = wxAtoi(shieldhp->GetValue());
            OAI[sel+1].currentshp = OAI[sel+1].maxshp;
            OAI[sel+1].currenthp = OAI[sel+1].maxhp;
            OAI[sel+1].shieldmitpower = wxAtoi(shieldmitpwr->GetValue());
            OAI[sel+1].shieldmitduration = wxAtoi(shieldmitdur->GetValue());
            OAI[sel+1].shieldstrpower = wxAtoi(shieldstrpwr->GetValue());
            OAI[sel+1].shieldstrduration = wxAtoi(shieldstrdur->GetValue());            
            OAI[sel+1].temppower = wxAtoi(temppower->GetValue());
            OAI[sel+1].tempduration = wxAtoi(tempduration->GetValue());
            OAI[sel+1].shpdamage = wxAtoi(shulldamage->GetValue());
            OAI[sel+1].shielddrop = shulldrop->GetValue();
            OAI[sel+1].shielddropdur = wxAtoi(shulldropdur->GetValue());            
        }
    }
    edited = true;
    Destroy();
}

void AddShipDialog::OnGo(wxCommandEvent& event)
{
    listi->Append(name->GetValue());
    if (cmd == 1)
    {
        if (plyr == 1)
        {
            playercommandnumber++;
            OPlayerCommand[playercommandnumber].name = string(name->GetValue().mb_str());
            OPlayerCommand[playercommandnumber].power = wxAtoi(power->GetValue());
            OPlayerCommand[playercommandnumber].maxhp = wxAtoi(hull->GetValue());
            OPlayerCommand[playercommandnumber].rating = wxAtoi(command->GetValue());
            OPlayerCommand[playercommandnumber].SetBonus();
            OPlayerCommand[playercommandnumber].currenthp = OPlayerCommand[playercommandnumber].maxhp;
        }
        else
        {
            aicommandnumber++;
            OAICommand[aicommandnumber].name = string(name->GetValue().mb_str());
            OAICommand[aicommandnumber].power = wxAtoi(power->GetValue());
            OAICommand[aicommandnumber].maxhp = wxAtoi(hull->GetValue());
            OAICommand[aicommandnumber].rating = wxAtoi(command->GetValue());
            OAICommand[aicommandnumber].SetBonus();
            OAICommand[aicommandnumber].currenthp = OAICommand[aicommandnumber].maxhp;
        }
    }
    else
    {
        if (plyr == 1)
        {
            playernumber++;
            OPlayer[playernumber].name=string(name->GetValue().mb_str());
            OPlayer[playernumber].power = wxAtoi(power->GetValue());
            OPlayer[playernumber].maxhp = wxAtoi(hull->GetValue());
            OPlayer[playernumber].shieldmit = wxAtoi(mit->GetValue());
            OPlayer[playernumber].shieldstr = wxAtoi(str->GetValue());
            OPlayer[playernumber].currenthp = OPlayer[playernumber].maxhp;
            OPlayer[playernumber].maxshp = wxAtoi(shieldhp->GetValue());
            OPlayer[playernumber].currentshp = OPlayer[playernumber].maxshp;
            OPlayer[playernumber].shieldmitpower = wxAtoi(shieldmitpwr->GetValue());
            OPlayer[playernumber].shieldmitduration = wxAtoi(shieldmitdur->GetValue());
            OPlayer[playernumber].shieldstrpower = wxAtoi(shieldstrpwr->GetValue());
            OPlayer[playernumber].shieldstrduration = wxAtoi(shieldstrdur->GetValue());            
            OPlayer[playernumber].temppower = wxAtoi(temppower->GetValue());
            OPlayer[playernumber].tempduration = wxAtoi(tempduration->GetValue());
            OPlayer[playernumber].shpdamage = wxAtoi(shulldamage->GetValue());
            OPlayer[playernumber].shielddrop = shulldrop->GetValue();
            OPlayer[playernumber].shielddropdur = wxAtoi(shulldropdur->GetValue());            
        }
        else
        {
            ainumber++;
            OAI[ainumber].name=string(name->GetValue().mb_str());
            OAI[ainumber].maxhp = wxAtoi(hull->GetValue());
            OAI[ainumber].power = wxAtoi(power->GetValue());
            OAI[ainumber].shieldmit = wxAtoi(mit->GetValue());
            OAI[ainumber].shieldstr = wxAtoi(str->GetValue());
            OAI[ainumber].currenthp = OAI[ainumber].maxhp;
            OAI[ainumber].maxshp = wxAtoi(shieldhp->GetValue());
            OAI[ainumber].currentshp = OAI[ainumber].maxshp;
            OAI[ainumber].shieldmitpower = wxAtoi(shieldmitpwr->GetValue());
            OAI[ainumber].shieldmitduration = wxAtoi(shieldmitdur->GetValue());
            OAI[ainumber].shieldstrpower = wxAtoi(shieldstrpwr->GetValue());
            OAI[ainumber].shieldstrduration = wxAtoi(shieldstrdur->GetValue());            
            OAI[ainumber].temppower = wxAtoi(temppower->GetValue());
            OAI[ainumber].tempduration = wxAtoi(tempduration->GetValue());            
            OAI[ainumber].shpdamage = wxAtoi(shulldamage->GetValue());
            OAI[ainumber].shielddrop = shulldrop->GetValue();
            OAI[ainumber].shielddropdur = wxAtoi(shulldropdur->GetValue());            
        }
    }
    added = true;
    Destroy();
}

AutoresolverWindow::AutoresolverWindow(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{

  wxInitAllImageHandlers();

  panel = new wxPanel(this, -1);

  wxToolBar *toolbar = CreateToolBar();

  info.SetName(wxT("Galactic Nations Combat Autoresolver"));
  info.SetVersion(wxT("3.1.5.1"));
  info.SetDescription(wxT("A utility for resolving combats in the Galactic Nations game."));
  info.AddDeveloper(wxT("Niezck"));

  wxButton *autoresolvebutton = new wxButton(panel, ID_AUTORESOLVE, wxT("Autoresolve!"),wxDefaultPosition);
  wxButton *clearbutton = new wxButton(panel,ID_CLEARSHIPS,wxT("Clear Ships"),wxDefaultPosition);

  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *vbox1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *vbox2 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *vbox3 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *vbox4 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *vbox5 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *vbox6 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *hbox0 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox4 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox5 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox6 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox7 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox8 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox9 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox10 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer *hbox11 = new wxBoxSizer(wxHORIZONTAL);

  wxGridSizer *gsizer = new wxGridSizer(2,2,10,10);

  text1 = new wxStaticText(panel,wxID_ANY, wxT("List of Player Ships"));
  text2 = new wxStaticText(panel,wxID_ANY, wxT("List of Player Command Ships"));
  text3 = new wxStaticText(panel,wxID_ANY, wxT("List of Enemy Ships"));
  text4 = new wxStaticText(panel,wxID_ANY, wxT("List of Enemy Command Ships"));
  text5 = new wxStaticText(panel,wxID_ANY, wxT("Player Bonus"));
  text6 = new wxStaticText(panel,wxID_ANY, wxT("Enemy Bonus"));
  text7 = new wxStaticText(panel,wxID_ANY, wxT("Player Flee"));
  text8 = new wxStaticText(panel,wxID_ANY, wxT("Enemy Flee"));
  text9  = new wxStaticText(panel,wxID_ANY,wxT("Filename"));
  text10 = new wxStaticText(panel,wxID_ANY,wxT("Player Temp Bonus"));
  text11 = new wxStaticText(panel,wxID_ANY,wxT("Player Temp Dur"));
  text12 = new wxStaticText(panel,wxID_ANY,wxT("Enemy Temp Bonus"));
  text13 = new wxStaticText(panel,wxID_ANY,wxT("Enemy Temp Dur"));
  text14 = new wxStaticText(panel,wxID_ANY,wxT("X"));
  text15 = new wxStaticText(panel,wxID_ANY,wxT("X"));
  text16 = new wxStaticText(panel,wxID_ANY,wxT("Y"));
  text17 = new wxStaticText(panel,wxID_ANY,wxT("Y"));

  wxStaticBoxSizer *bsizer1 = new wxStaticBoxSizer(wxHORIZONTAL,panel,wxT("Player Ship Stats"));
  wxStaticBoxSizer *bsizer2 = new wxStaticBoxSizer(wxHORIZONTAL,panel,wxT("Player Command Ship Stats"));
  wxStaticBoxSizer *bsizer3 = new wxStaticBoxSizer(wxHORIZONTAL,panel,wxT("Enemy Ship Stats"));
  wxStaticBoxSizer *bsizer4 = new wxStaticBoxSizer(wxHORIZONTAL,panel,wxT("Enemy Command Ship Stats"));

  wxBitmap AddPShipIcon(wxT("Icons\\AddPShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap DelPShipIcon(wxT("Icons\\DelPShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap EditPShipIcon(wxT("Icons\\EditPShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap CopyPShipIcon(wxT("Icons\\CopyPShipIcon.ico"),wxBITMAP_TYPE_ICO);

  wxBitmap AddPCShipIcon(wxT("Icons\\AddPCShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap DelPCShipIcon(wxT("Icons\\DelPCShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap EditPCShipIcon(wxT("Icons\\EditPCShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap CopyPCShipIcon(wxT("Icons\\CopyPCShipIcon.ico"),wxBITMAP_TYPE_ICO);

  wxBitmap AddEShipIcon(wxT("Icons\\AddEShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap DelEShipIcon(wxT("Icons\\DelEShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap EditEShipIcon(wxT("Icons\\EditEShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap CopyEShipIcon(wxT("Icons\\CopyEShipIcon.ico"),wxBITMAP_TYPE_ICO);

  wxBitmap AddECShipIcon(wxT("Icons\\AddECShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap DelECShipIcon(wxT("Icons\\DelECShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap EditECShipIcon(wxT("Icons\\EditECShipIcon.ico"),wxBITMAP_TYPE_ICO);
  wxBitmap CopyECShipIcon(wxT("Icons\\CopyECShipIcon.ico"),wxBITMAP_TYPE_ICO);

  display1 = new wxListBox(panel, wxID_ANY, wxDefaultPosition, wxSize(0,0));
  display2 = new wxListBox(panel, wxID_ANY, wxDefaultPosition, wxSize(0,0));
  display3 = new wxListBox(panel, wxID_ANY, wxDefaultPosition, wxSize(0,0));
  display4 = new wxListBox(panel, wxID_ANY, wxDefaultPosition, wxSize(0,0));

  pbonustxt = new wxTextCtrl(panel, wxID_ANY);
  ebonustxt = new wxTextCtrl(panel, wxID_ANY);
  pfleetxt1 = new wxChoice(panel, ID_PFLEE);
  pfleetxt2 = new wxChoice(panel, ID_PFLEESHIP);
  pfleetxt3 = new wxChoice(panel, wxID_ANY);
  efleetxt1 = new wxChoice(panel, ID_EFLEE);
  efleetxt2 = new wxChoice(panel, ID_EFLEESHIP);
  efleetxt3 = new wxChoice(panel, wxID_ANY);
  filenameget = new wxTextCtrl(panel,wxID_ANY);
  ptempbonus = new wxTextCtrl(panel,wxID_ANY);
  ptempduration = new wxTextCtrl(panel,wxID_ANY);
  etempbonus = new wxTextCtrl(panel,wxID_ANY);
  etempduration = new wxTextCtrl(panel,wxID_ANY);
  pbonustxt->Disable();
  ebonustxt->Disable();
  pfleetxt1->Disable();
  pfleetxt2->Disable();
  pfleetxt3->Disable();
  efleetxt1->Disable();
  efleetxt2->Disable();
  efleetxt3->Disable();
  ptempbonus->Disable();
  ptempduration->Disable();
  etempbonus->Disable();
  etempduration->Disable();
  text5->Disable();
  text6->Disable();
  text7->Disable();
  text8->Disable();
  text10->Disable();
  text11->Disable();
  text12->Disable();
  text13->Disable();
  text14->Disable();
  text15->Disable();
  text16->Disable();
  text17->Disable();
  
  ifstream infile("Preferences.ini");
  string line;
  char *out;
  for (int linenum = 1;linenum<=16;linenum++)
  {
    getline(infile,line);
    char cstr[line.size() + 1];
    strcpy(cstr,line.c_str());
    out = strtok(cstr,"=");
    out = strtok(NULL,"");
            if ((linenum == 2) && (atoi(out) == 1)) {ebonusglobal = true; ebonustxt->Enable(); text6->Enable(); }
            if ((linenum == 3) && (atoi(out) == 1)) {efleeglobal = true; efleetxt1->Enable(); text8->Enable(); }
            if ((linenum == 4) && (atoi(out) == 1)) {etempbonusglobal = true; etempbonus->Enable(); etempduration->Enable(); text12->Enable(); text13->Enable(); }
            if ((linenum == 5) && (atoi(out) == 1)) {pbonusglobal = true; pbonustxt->Enable(); text5->Enable(); }
            if ((linenum == 6) && (atoi(out) == 1)) {pfleeglobal = true; pfleetxt1->Enable(); text7->Enable(); }
            if ((linenum == 7) && (atoi(out) == 1)) {ptempbonusglobal = true; ptempbonus->Enable(); ptempduration->Enable(); text10->Enable(); text11->Enable(); }
            if ((linenum == 8) && (atoi(out) == 1)) { lifglobal = true; }
            if ((linenum == 11) && (atoi(out) == 1)) { shieldhullglobal = true; }
            if ((linenum == 12) && (atoi(out) == 1)) { temppowerglobal = true; }
            if ((linenum == 13) && (atoi(out) == 1)) { mitgunglobal = true; }
            if ((linenum == 14) && (atoi(out) == 1)) { strgunglobal = true; }
            if ((linenum == 15) && (atoi(out) == 1)) { shieldhulldamageglobal = true; }
            if ((linenum == 16) && (atoi(out) == 1)) { shieldhulldropglobal = true; }
  }
  infile.close();
  
  pfleetxt1->Append(wxT("None"));
  pfleetxt1->Append(wxT("50% Casualties"));
  pfleetxt1->Append(wxT("All Command Ships Destroyed"));
  pfleetxt1->Append(wxT("10% Chance Each Round"));
  pfleetxt1->Append(wxT("X Ship Destroyed"));
  pfleetxt1->Append(wxT("X Ship Brought to Y Hull"));
  efleetxt1->Append(wxT("None"));
  efleetxt1->Append(wxT("50% Casualties"));
  efleetxt1->Append(wxT("All Command Ships Destroyed"));
  efleetxt1->Append(wxT("10% Chance Each Round"));
  efleetxt1->Append(wxT("X Ship Destroyed"));
  efleetxt1->Append(wxT("X Ship Brought to Y Hull"));  
  
  pbonustxt->AppendText(wxT("0"));
  ebonustxt->AppendText(wxT("0"));
  pfleetxt1->SetSelection(0);
  efleetxt1->SetSelection(0);
  filenameget->AppendText(wxT("ExampleFile"));
  ptempbonus->AppendText(wxT("0"));
  ptempduration->AppendText(wxT("0"));
  etempbonus->AppendText(wxT("0"));
  etempduration->AppendText(wxT("0"));

  menubar = new wxMenuBar;
  file = new wxMenu;
  playership = new wxMenu;
  enemyship = new wxMenu;
  help = new wxMenu;
  help->Append(ID_ABOUT,wxT("&About"));
  playership->Append(ID_NEWPSHIP, wxT("Add Player &Ship"));
  playership->Append(ID_NEWPCSHIP, wxT("Add Player &Command Ship"));
  playership->AppendSeparator();
  playership->Append(ID_EDITPSHIP,wxT("Edit Player Ship"));
  playership->Append(ID_EDITPCSHIP,wxT("Edit Player Command Ship"));
  playership->AppendSeparator();
  playership->Append(ID_COPYPSHIP,wxT("Copy Player Ship"));
  playership->Append(ID_COPYPCSHIP,wxT("Copy Player Command Ship"));
  playership->AppendSeparator();
  playership->Append(ID_DELPSHIP, wxT("Remove Player Ship"));
  playership->Append(ID_DELPCSHIP, wxT("Remove Player Command Ship"));
  enemyship->Append(ID_NEWESHIP, wxT("Add Enemy &Ship"));
  enemyship->Append(ID_NEWECSHIP, wxT("Add Enemy &Command Ship"));
  enemyship->AppendSeparator();
  enemyship->Append(ID_EDITESHIP,wxT("Edit Enemy Ship"));
  enemyship->Append(ID_EDITECSHIP,wxT("Edit Enemy Command Ship"));
  enemyship->AppendSeparator();
  enemyship->Append(ID_COPYESHIP,wxT("Copy Enemy Ship"));
  enemyship->Append(ID_COPYECSHIP,wxT("Copy Enemy Command Ship"));
  enemyship->AppendSeparator();
  enemyship->Append(ID_DELESHIP, wxT("Remove Enemy Ship"));
  enemyship->Append(ID_DELECSHIP, wxT("Remove Enemy Command Ship"));
  file->Append(ID_AUTORESOLVE, wxT("&Autoresolve"));
  file->Append(ID_CLEARSHIPS,wxT("&Clear Ships"));
  file->Append(ID_PREFERENCES, wxT("&Preferences"));
  file->Append(ID_SETTINGS, wxT("&Settings"));
  file->Append(wxID_EXIT, wxT("&Quit"));
  menubar->Append(file, wxT("&File"));
  menubar->Append(playership, wxT("&Player Ships"));
  menubar->Append(enemyship, wxT("&Enemy Ships"));
  menubar->Append(help,wxT("&Help"));
  SetMenuBar(menubar);

  pshiplist = new wxListBox(panel, ID_PSHIPBOX, wxPoint(-1,-1), wxSize(-1,-1));
  eshiplist = new wxListBox(panel, ID_PCSHIPBOX, wxPoint(128,-1), wxSize(-1,-1));
  pcshiplist = new wxListBox(panel, ID_ESHIPBOX, wxPoint(-1,128), wxSize(-1,-1));
  ecshiplist = new wxListBox(panel, ID_ECSHIPBOX, wxPoint(128,128), wxSize(-1,-1));

  toolbar->AddTool(ID_TOOLADDPSHIP,AddPShipIcon,wxT("Add Player Ship"));
  toolbar->AddTool(ID_TOOLDELPSHIP,DelPShipIcon,wxT("Remove Player Ship"));
  toolbar->AddTool(ID_TOOLEDITPSHIP,EditPShipIcon,wxT("Edit Player Ship"));
  toolbar->AddTool(ID_TOOLCOPYPSHIP,CopyPShipIcon,wxT("Copy Player Ship"));
  toolbar->AddSeparator();
  toolbar->AddTool(ID_TOOLADDPCSHIP,AddPCShipIcon,wxT("Add Player Command Ship"));
  toolbar->AddTool(ID_TOOLDELPCSHIP,DelPCShipIcon,wxT("Remove Player Command Ship"));
  toolbar->AddTool(ID_TOOLEDITPCSHIP,EditPCShipIcon,wxT("Edit Player Command Ship"));
  toolbar->AddTool(ID_TOOLCOPYPCSHIP,CopyPCShipIcon,wxT("Copy Player Command Ship"));
  toolbar->AddSeparator();
  toolbar->AddTool(ID_TOOLADDESHIP,AddEShipIcon,wxT("Add Enemy Ship"));
  toolbar->AddTool(ID_TOOLDELESHIP,DelEShipIcon,wxT("Remove Enemy Ship"));
  toolbar->AddTool(ID_TOOLEDITESHIP,EditEShipIcon,wxT("Edit Enemy Ship"));
  toolbar->AddTool(ID_TOOLCOPYESHIP,CopyEShipIcon,wxT("Copy Enemy Ship"));
  toolbar->AddSeparator();
  toolbar->AddTool(ID_TOOLADDECSHIP,AddECShipIcon,wxT("Add Enemy Command Ship"));
  toolbar->AddTool(ID_TOOLDELECSHIP,DelECShipIcon,wxT("Remove Enemy Command Ship"));
  toolbar->AddTool(ID_TOOLEDITECSHIP,EditECShipIcon,wxT("Edit Enemy Command Ship"));
  toolbar->AddTool(ID_TOOLCOPYECSHIP,CopyECShipIcon,wxT("Copy Enemy Command Ship"));

  hbox0->Add(text9,0,wxALL,5);
  hbox0->Add(filenameget,0,wxALL,5);
  vbox5->Add(hbox0,0,wxEXPAND|wxALL,10);

  hbox1->Add(text5,0,wxALL,5);
  hbox1->Add(pbonustxt,0,wxALL,5);
  vbox5->Add(hbox1,0,wxEXPAND | wxALL,10);
  
  hbox8->Add(text10,0,wxALL,5);
  hbox8->Add(ptempbonus,0,wxALL,5);
  hbox8->Add(text11,0,wxALL,5);
  hbox8->Add(ptempduration,0,wxALL,5);
  vbox5->Add(hbox8,0,wxEXPAND|wxALL,10);

  hbox2->Add(text6,0,wxALL,5);
  hbox2->Add(ebonustxt,0,wxALL,5);
  vbox5->Add(hbox2,0,wxEXPAND | wxALL,10);
  
  hbox9->Add(text12,0,wxALL,5);
  hbox9->Add(etempbonus,0,wxALL,5);
  hbox9->Add(text13,0,wxALL,5);
  hbox9->Add(etempduration,0,wxALL,5);
  vbox5->Add(hbox9,0,wxEXPAND|wxALL,10);  

  hbox3->Add(text7,0,wxALL,5);
  hbox3->Add(pfleetxt1,0,wxALL,5);
  hbox3->Add(text14,0,wxALL,5);
  hbox3->Add(pfleetxt2,0,wxALL,5);
  hbox3->Add(text16,0,wxALL,5);
  hbox3->Add(pfleetxt3,0,wxALL,5);
  vbox5->Add(hbox3,0,wxEXPAND | wxALL,10);

  hbox4->Add(text8,0,wxALL,5);
  hbox4->Add(efleetxt1,0,wxALL,5);
  hbox4->Add(text15,0,wxALL,5);
  hbox4->Add(efleetxt2,0,wxALL,5);
  hbox4->Add(text17,0,wxALL,5);
  hbox4->Add(efleetxt3,0,wxALL,5);
  vbox5->Add(hbox4,0,wxEXPAND | wxALL,10);

  vbox1->Add(text1,0,wxEXPAND | wxALL,5);
  vbox2->Add(text2,0,wxEXPAND | wxALL,5);
  vbox3->Add(text3,0,wxEXPAND | wxALL,5);
  vbox4->Add(text4,0,wxEXPAND | wxALL,5);
  vbox1->Add(pshiplist, 1, wxEXPAND | wxALL, 5);
  vbox2->Add(pcshiplist, 1, wxEXPAND | wxALL, 5);
  vbox3->Add(eshiplist, 1, wxEXPAND | wxALL, 5);
  vbox4->Add(ecshiplist, 1, wxEXPAND | wxALL, 5);

  hbox6->Add(autoresolvebutton,0,wxCENTER,5);
  hbox6->Add(clearbutton,0,wxCENTER,5);
  vbox5->Add(hbox6,0,wxEXPAND|wxALL,10);

  GenerateDisplay1();
  GenerateDisplay2();
  GenerateDisplay3();
  GenerateDisplay4();
  bsizer1->Add(display1,1,wxEXPAND,0);
  gsizer->Add(bsizer1,0,wxEXPAND,0);
  bsizer2->Add(display2,1,wxEXPAND,0);
  gsizer->Add(bsizer2,0,wxEXPAND,0);
  bsizer3->Add(display3,1,wxEXPAND,0);
  gsizer->Add(bsizer3,0,wxEXPAND,0);
  bsizer4->Add(display4,1,wxEXPAND,0);
  gsizer->Add(bsizer4,0,wxEXPAND,0);
  vbox5->Add(gsizer,1,wxEXPAND,0);

  hbox->Add(vbox1,0,wxEXPAND | wxALL, 0);
  hbox->Add(vbox2,0,wxEXPAND | wxALL, 0);
  hbox->Add(vbox3,0,wxEXPAND | wxALL, 0);
  hbox->Add(vbox4,0,wxEXPAND | wxALL, 0);
  hbox->Add(vbox5,1,wxEXPAND|wxALL,0);

  Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnQuit));
  Connect(ID_NEWPSHIP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnNewPShip));
  Connect(ID_NEWPCSHIP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnNewPCShip));
  Connect(ID_NEWESHIP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnNewEShip));
  Connect(ID_NEWECSHIP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnNewECShip));
  Connect(ID_DELPSHIP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnDelPShip));
  Connect(ID_DELPCSHIP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnDelPCShip));
  Connect(ID_DELESHIP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnDelEShip));
  Connect(ID_DELECSHIP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnDelECShip));
  Connect(ID_EDITPSHIP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnEditPShip));
  Connect(ID_EDITPCSHIP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnEditPCShip));
  Connect(ID_EDITESHIP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnEditEShip));
  Connect(ID_EDITECSHIP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnEditECShip));
  Connect(ID_COPYPSHIP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnCopyPShip));
  Connect(ID_COPYPCSHIP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnCopyPCShip));
  Connect(ID_COPYESHIP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnCopyEShip));
  Connect(ID_COPYECSHIP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnCopyECShip));
  Connect(ID_AUTORESOLVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(AutoresolverWindow::Autoresolve));
  Connect(ID_AUTORESOLVE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AutoresolverWindow::Autoresolve));
  Connect (ID_CLEARSHIPS, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::ClearShips));
  Connect (ID_CLEARSHIPS, wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(AutoresolverWindow::ClearShips));
  Connect(ID_PSHIPBOX, wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnClick1));
  Connect(ID_ESHIPBOX, wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnClick2));
  Connect(ID_PCSHIPBOX, wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnClick3));
  Connect(ID_ECSHIPBOX, wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(AutoresolverWindow::OnClick4));
  Connect(ID_ABOUT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnAbout));
  Connect(ID_TOOLADDPSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnNewPShip));
  Connect(ID_TOOLDELPSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnDelPShip));
  Connect(ID_TOOLEDITPSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnEditPShip));
  Connect(ID_TOOLCOPYPSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnCopyPShip));
  Connect(ID_TOOLADDPCSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnNewPCShip));
  Connect(ID_TOOLDELPCSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnDelPCShip));
  Connect(ID_TOOLEDITPCSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnEditPCShip));
  Connect(ID_TOOLCOPYPCSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnCopyPCShip));
  Connect(ID_TOOLADDESHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnNewEShip));
  Connect(ID_TOOLDELESHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnDelEShip));
  Connect(ID_TOOLEDITESHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnEditEShip));
  Connect(ID_TOOLCOPYESHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnCopyEShip));
  Connect(ID_TOOLADDECSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnNewECShip));
  Connect(ID_TOOLDELECSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnDelECShip));
  Connect(ID_TOOLEDITECSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnEditECShip));
  Connect(ID_TOOLCOPYECSHIP,wxEVT_COMMAND_TOOL_CLICKED,wxCommandEventHandler(AutoresolverWindow::OnCopyECShip));
  Connect(ID_PREFERENCES,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnPreferences));
  Connect(ID_SETTINGS,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(AutoresolverWindow::OnSettings));
  Connect(ID_PFLEE,wxEVT_COMMAND_CHOICE_SELECTED,wxCommandEventHandler(AutoresolverWindow::PFleeClicked));
  Connect(ID_EFLEE,wxEVT_COMMAND_CHOICE_SELECTED,wxCommandEventHandler(AutoresolverWindow::EFleeClicked));
  Connect(ID_PFLEESHIP,wxEVT_COMMAND_CHOICE_SELECTED,wxCommandEventHandler(AutoresolverWindow::PFleeShipClicked));
  Connect(ID_EFLEESHIP,wxEVT_COMMAND_CHOICE_SELECTED,wxCommandEventHandler(AutoresolverWindow::EFleeShipClicked));
  toolbar->Realize();
  Centre();
  Maximize(true);
  panel->SetSizer(hbox);
  SetIcon( wxIcon( _T("Icons\\Autoresolver.ico"), wxBITMAP_TYPE_ICO ) );
  
/*        wxSound *bar = new wxSound(wxT("\\Sounds\\Background.wav"),false);
        wxMessageDialog *yay;
        wxMessageDialog *nay;
        if (bar->IsOk() == true)
        {
            if (bar->Play(wxSOUND_ASYNC | wxSOUND_LOOP )  == true)
            {
                yay = new wxMessageDialog(NULL,wxT("YAY!"),wxT("YAY!"),wxOK);
                yay->ShowModal();
            }
        }
        else
        {
            nay = new wxMessageDialog(NULL,wxT("NAY!"),wxT("NAY!"),wxOK);
            nay->ShowModal();
        }  */

}

void AutoresolverWindow::ClearShips(wxCommandEvent& event)
{
    for (int x=1;x<=playernumber;x++)
    {
        OPlayer[x].Destroy();
        Player[x].Destroy();
    }
    for (int x=1;x<=playercommandnumber;x++)
    {
        OPlayerCommand[x].Destroy();
        PlayerCommand[x].Destroy();
    }
    for (int x=1;x<=ainumber;x++)
    {
        OAI[x].Destroy();
        AI[x].Destroy();
    }
    for (int x=1;x<=aicommandnumber;x++)
    {
        OAICommand[x].Destroy();
        AICommand[x].Destroy();
    }
    playernumber = 0;
    playercommandnumber = 0;
    ainumber = 0;
    aicommandnumber = 0;
    Cleanup();
    pshiplist->Clear();
    pcshiplist->Clear();
    eshiplist->Clear();
    ecshiplist->Clear();
    UpdateDisplay1();
    UpdateDisplay2();
    UpdateDisplay3();
    UpdateDisplay4();
    pfleetxt1->SetSelection(0);
    pfleetxt2->Clear();
    pfleetxt2->Disable();
    pfleetxt3->Clear();
    pfleetxt3->Disable();
    efleetxt1->SetSelection(0);
    efleetxt2->Clear();
    efleetxt2->Disable();
    efleetxt3->Clear();
    efleetxt3->Disable();
}

void AutoresolverWindow::OnCopyPShip(wxCommandEvent& event)
{
    int sel = pshiplist->GetSelection();
    if (sel > -1)
    {
    wxString name = wxString::Format(wxT("Player Ship %i"),playernumber+1);
    stringstream ss;
    ss<<"Player Ship "<<playernumber+1;
    string sname = ss.str();
    int hull = OPlayer[sel+1].maxhp;
    int shull = OPlayer[sel+1].maxshp;
    int power = OPlayer[sel+1].power;
    int mit = OPlayer[sel+1].shieldmit;
    int str = OPlayer[sel+1].shieldstr;
    int mitpwr = OPlayer[sel+1].shieldmitpower;
    int mitdur = OPlayer[sel+1].shieldmitduration;
    int strpwr = OPlayer[sel+1].shieldstrpower;
    int strdur = OPlayer[sel+1].shieldstrduration;
    int tmppwr = OPlayer[sel+1].temppower;
    int tmpdur = OPlayer[sel+1].tempduration;
    int shpdamage = OPlayer[sel+1].shpdamage;
    bool sdrop = OPlayer[sel+1].shielddrop;
    int sdropdur = OPlayer[sel+1].shielddropdur;    
    pshiplist->Append(name);
    OPlayer[playernumber+1].name = sname;
    OPlayer[playernumber+1].maxhp = hull;
    OPlayer[playernumber+1].currenthp = hull;
    OPlayer[playernumber+1].maxshp = shull;
    OPlayer[playernumber+1].currentshp = shull;
    OPlayer[playernumber+1].power = power;
    OPlayer[playernumber+1].shieldmit = mit;
    OPlayer[playernumber+1].shieldstr = str;
    OPlayer[playernumber+1].shieldmitpower = mitpwr;
    OPlayer[playernumber+1].shieldmitduration = mitdur;
    OPlayer[playernumber+1].shieldstrpower = strpwr;
    OPlayer[playernumber+1].shieldstrduration = strdur;
    OPlayer[playernumber+1].temppower = tmppwr;
    OPlayer[playernumber+1].tempduration = tmpdur;
    OPlayer[playernumber+1].shpdamage = shpdamage;
    OPlayer[playernumber+1].shielddrop = sdrop;
    OPlayer[playernumber+1].shielddropdur = sdropdur;    
    playernumber++;
    }
}

void AutoresolverWindow::OnCopyPCShip(wxCommandEvent& event)
{
    int sel = pcshiplist->GetSelection();
    if (sel > -1)
    {
    wxString name = wxString::Format(wxT("Player Command Ship %i"),playercommandnumber+1);
    stringstream ss;
    ss<<"Player Command Ship "<<playercommandnumber+1;
    string sname = ss.str();
    int hull = OPlayerCommand[sel+1].maxhp;
    int power = OPlayerCommand[sel+1].power;
    int command = OPlayerCommand[sel+1].rating;
    pcshiplist->Append(name);
    OPlayerCommand[playercommandnumber+1].name = sname;
    OPlayerCommand[playercommandnumber+1].maxhp = hull;
    OPlayerCommand[playercommandnumber+1].currenthp = hull;
    OPlayerCommand[playercommandnumber+1].power = power;
    OPlayerCommand[playercommandnumber+1].rating = command;
    OPlayerCommand[playercommandnumber].SetBonus();
    playercommandnumber++;
    }
}

void AutoresolverWindow::OnCopyEShip(wxCommandEvent& event)
{
    int sel = eshiplist->GetSelection();
    if (sel > -1)
    {
    wxString name = wxString::Format(wxT("Enemy Ship %i"),ainumber+1);
    stringstream ss;
    ss<<"Enemy Ship "<<ainumber+1;
    string sname = ss.str();
    int hull = OAI[sel+1].maxhp;
    int shull = OAI[sel+1].maxshp;
    int power = OAI[sel+1].power;
    int mit = OAI[sel+1].shieldmit;
    int str = OAI[sel+1].shieldstr;
    int mitpwr = OAI[sel+1].shieldmitpower;
    int mitdur = OAI[sel+1].shieldmitduration;
    int strpwr = OAI[sel+1].shieldstrpower;
    int strdur = OAI[sel+1].shieldstrduration;
    int tmppwr = OAI[sel+1].temppower;
    int tmpdur = OAI[sel+1].tempduration;    
    int shpdamage = OAI[sel+1].shpdamage;
    bool sdrop = OAI[sel+1].shielddrop;
    int sdropdur = OAI[sel+1].shielddropdur;
    eshiplist->Append(name);
    OAI[ainumber+1].name = sname;
    OAI[ainumber+1].maxhp = hull;
    OAI[ainumber+1].currenthp = hull;
    OAI[ainumber+1].maxshp = shull;
    OAI[ainumber+1].currentshp = shull;
    OAI[ainumber+1].power = power;
    OAI[ainumber+1].shieldmit = mit;
    OAI[ainumber+1].shieldstr = str;
    OAI[ainumber+1].shieldmitpower = mitpwr;
    OAI[ainumber+1].shieldmitduration = mitdur;
    OAI[ainumber+1].shieldstrpower = strpwr;
    OAI[ainumber+1].shieldstrduration = strdur;
    OAI[ainumber+1].temppower = tmppwr;
    OAI[ainumber+1].tempduration = tmpdur;    
    OAI[ainumber+1].shpdamage = shpdamage;
    OAI[ainumber+1].shielddrop = sdrop;
    OAI[ainumber+1].shielddropdur = sdropdur;    
    ainumber++;
    }
}

void AutoresolverWindow::OnCopyECShip(wxCommandEvent& event)
{
    int sel = ecshiplist->GetSelection();
    if (sel > -1)
    {
    wxString name = wxString::Format(wxT("Enemy Command Ship %i"),aicommandnumber+1);
    stringstream ss;
    ss<<"Enemy Command Ship "<<aicommandnumber+1;
    string sname = ss.str();
    int hull = OAICommand[sel+1].maxhp;
    int power = OAICommand[sel+1].power;
    int command = OAICommand[sel+1].rating;
    ecshiplist->Append(name);
    OAICommand[aicommandnumber+1].name = sname;
    OAICommand[aicommandnumber+1].maxhp = hull;
    OAICommand[aicommandnumber+1].currenthp = hull;
    OAICommand[aicommandnumber+1].power = power;
    OAICommand[aicommandnumber+1].rating = command;
    OAICommand[aicommandnumber+1].SetBonus();
    aicommandnumber++;
    }
}

void AutoresolverWindow::OnAbout(wxCommandEvent &event)
{
    wxAboutBox(info);
}

void AutoresolverWindow::OnEditPShip(wxCommandEvent& event)
{
    if (playernumber > 0)
    {
        AddShipDialog *foo = new AddShipDialog(pshiplist, wxT("Edit Player Ship"),true,false,true,wxSize(256,480));
        UpdateDisplay1();
        if (edited == true)
        {
            UpdatePFleeHP();
            edited = false;
        }
    }
}

void AutoresolverWindow::OnEditPCShip(wxCommandEvent& event)
{
    if (playercommandnumber > 0)
    {
        AddShipDialog *foo = new AddShipDialog(pcshiplist, wxT("Edit Player Command Ship"),true,true,true,wxSize(256,192));
        UpdateDisplay2();
    }
}

void AutoresolverWindow::OnEditEShip(wxCommandEvent& event)
{
    if (ainumber > 0)
    {
        AddShipDialog *foo = new AddShipDialog(eshiplist, wxT("Edit Enemy Ship"),false,false,true,wxSize(256,480));
        UpdateDisplay3();
        if (edited == true)
        {
            UpdateEFleeHP();
            edited = false;
        }
    }
}

void AutoresolverWindow::OnEditECShip(wxCommandEvent& event)
{
    if (aicommandnumber > 0)
    {
        AddShipDialog *foo = new AddShipDialog(ecshiplist, wxT("Edit Enemy Command Ship"),false,true,true,wxSize(256,192));
        UpdateDisplay4();
    }
}

void AutoresolverWindow::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  Close(true);
}

void AutoresolverWindow::OnNewPShip(wxCommandEvent& event)
{
    AddShipDialog *foo = new AddShipDialog(pshiplist, wxT("Add Player Ship"),true,false,false,wxSize(256,480));
    if ((added == true) && (pfleetxt1->GetSelection() > 3))
    {
        wxString bleh(OPlayer[playernumber].name.c_str(),wxConvUTF8);
        pfleetxt2->Append(bleh);
        added = false;
    }
}

void AutoresolverWindow::OnNewPCShip(wxCommandEvent& event)
{
    AddShipDialog *foo = new AddShipDialog(pcshiplist, wxT("Add Player Command Ship"),true,true,false,wxSize(256,192));
}

void AutoresolverWindow::OnNewEShip(wxCommandEvent& event)
{
    AddShipDialog *foo = new AddShipDialog(eshiplist, wxT("Add Enemy Ship"),false,false,false,wxSize(256,480));
    if ((added == true) && (efleetxt1->GetSelection() > 3))
    {
        wxString bleh(OAI[ainumber].name.c_str(),wxConvUTF8);
        efleetxt2->Append(bleh);
        added = false;
    }    
}

void AutoresolverWindow::OnNewECShip(wxCommandEvent& event)
{
    AddShipDialog *foo = new AddShipDialog(ecshiplist, wxT("Add Enemy Command Ship"),false,true,false,wxSize(256,192));
}

void AutoresolverWindow::OnDelPShip(wxCommandEvent& event)
{
    int sel = pshiplist->GetSelection();
    if (sel != -1)
    {
        pshiplist->Delete(sel);
        sel+=1;
        OPlayer[sel].Destroy();
        int x = sel;
        while (true)
        {
        if (x<playernumber)
        {
            OPlayer[x] = OPlayer[x+1];
        }
        else
        {
            break;
        }
        x++;
        }
        playernumber-=1;
    }
}

void AutoresolverWindow::OnDelPCShip(wxCommandEvent& event)
{
    int sel = pcshiplist->GetSelection();
    if (sel != -1)
    {
        pcshiplist->Delete(sel);
        sel+=1;
        OPlayerCommand[sel].Destroy();
        int x = sel;
        while (true)
        {
        if (x<playercommandnumber)
        {
            OPlayerCommand[x] = OPlayerCommand[x+1];
        }
        else
        {
            break;
        }
        x++;
        }
        playercommandnumber-=1;
    }
}

void AutoresolverWindow::OnDelEShip(wxCommandEvent& event)
{
    int sel = eshiplist->GetSelection();
    if (sel != -1)
    {
        eshiplist->Delete(sel);
        sel+=1;
        OAI[sel].Destroy();
        int x = sel;
        while (true)
        {
        if (x<ainumber)
        {
            OAI[x] = OAI[x+1];
        }
        else
        {
            break;
        }
        x++;
        }
        ainumber-=1;
    }
}

void AutoresolverWindow::OnDelECShip(wxCommandEvent& event)
{
    int sel = ecshiplist->GetSelection();
    if (sel != -1)
    {
        ecshiplist->Delete(sel);
        sel+=1;
        OAICommand[sel].Destroy();
        int x = sel;
        while (true)
        {
        if (x<aicommandnumber)
        {
            OAICommand[x] = OAICommand[x+1];
        }
        else
        {
            break;
        }
        x++;
        }
        aicommandnumber-=1;
    }
}
void AutoresolverWindow::Autoresolve(wxCommandEvent& event)
{
  //  wxMessageDialog *blar = new wxMessageDialog(NULL,wxT("BLAR!"),wxT("BLAR!"),wxOK);
//    blar->ShowModal();    
    Cleanup();    
    wchar_t urlW[ MAX_PATH ];
    wxBeginBusyCursor();
    HINSTANCE hInst;
    wxMessageDialog *bar;
    wxMessageDialog *blargh;
    filename = "";
    logfilename = "";
    filename.append("Output\\");
    logfilename.append("Logs\\");
    filename.append(string(filenameget->GetValue().mb_str()));
    logfilename.append(string(filenameget->GetValue().mb_str()));
    filename.append(".txt");
    logfilename.append(".txt");
    playertempbonus = wxAtoi(ptempbonus->GetValue());
    playertempduration = wxAtoi(ptempduration->GetValue());
    aitempbonus = wxAtoi(etempbonus->GetValue());
    aitempduration = wxAtoi(etempduration->GetValue());
    int fl1 = pfleetxt1->GetSelection();
    if ((playernumber < 1) | (ainumber<1))
    {
        blargh = new wxMessageDialog(NULL,wxT("Not enough ships entered, combat cannot happen!"),wxT("Error!"),wxOK);
        blargh->ShowModal();
        goto end;
    }
    flee[fl1] = true;
    if ((fl1 == 4) || (fl1 == 5))
    {
        fleeselection = pfleetxt2->GetSelection()+1;
    }
    if (fl1 == 5)
    {
        fleehull = pfleetxt3->GetSelection()+1;
    }
    playerbonus = wxAtoi(pbonustxt->GetValue());
    aibonus = wxAtoi(ebonustxt->GetValue());
    CopyOldShips();
//    blar->ShowModal();    
    SetUpPreBattle();
    ListStats();
    while (true)
    {
        CheckStatusM();
        if (victory > 0)
        {
            break;
        }
        CombatRoundM();
        totalexchanges+=1;
    }
    FinalStats();
    bar = new wxMessageDialog(NULL, wxT("Autoresolve succesful!"), wxT("Autoresolve successful!"), wxOK);
    bar->ShowModal();
    copy( filename.c_str(), filename.c_str() + lstrlenA( filename.c_str() ) + 1, urlW );
    hInst = ShellExecute(NULL,L"edit",urlW,NULL,NULL,SW_SHOWNORMAL);
    end:
    wxEndBusyCursor();
}

void AutoresolverWindow::GenerateDisplay1()
{
    display1->Clear();
    wxString foobar;
    foobar<<dname[0];
    display1->Append(foobar);
    foobar = wxT("");
    foobar<<wxT("Hull ");
    foobar<<dhull[0];
    display1->Append(foobar);
    foobar = wxT("");
    foobar<<wxT("Shield Hull ");
    foobar<<dshull[0];
    display1->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Power ");
    foobar<<dpower[0];
    display1->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Temp Power ");
    foobar<<dtmppwr[0];
    foobar<<wxT(" for ");
    foobar<<dtmpdur[0];
    display1->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Mitigation ");
    foobar<<dmit[0];
    display1->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Strength ");
    foobar<<dstr[0];
    display1->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Mitigation Damage ");
    foobar<<dmitpwr[0];
    foobar<<wxT(" for ");
    foobar<<dmitdur[0];
    display1->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Strength Damage ");
    foobar<<dstrpwr[0];
    foobar<<wxT(" for ");
    foobar<<dstrdur[0];
    display1->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Shield Hull Damage ");
    foobar<<dshpdamage[0];
    display1->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Shield Drop ");
    if (dsdrop[0] == true) {foobar<<wxT("for "); foobar<<dsdropdur[0]; }
    if (dsdrop[0] == false) {foobar<<wxT("Off"); }
    display1->Append(foobar);
}

void AutoresolverWindow::GenerateDisplay2()
{
    display2->Clear();
    wxString foobar;
    foobar<<dname[1];
    display2->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Hull ");
    foobar<<dhull[1];
    display2->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Power ");
    foobar<<dpower[1];
    display2->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Command ");
    foobar<<dcommand[0];
    display2->Append(foobar);
}

void AutoresolverWindow::GenerateDisplay3()
{
    display3->Clear();
    wxString foobar;
    foobar<<dname[2];
    display3->Append(foobar);
    foobar = wxT("");
    foobar<<wxT("Hull ");
    foobar<<dhull[2];
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Shield Hull ");
    foobar<<dshull[1];
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Power ");
    foobar<<dpower[2];
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Temp Power ");
    foobar<<dtmppwr[1];
    foobar<<wxT(" for ");
    foobar<<dtmpdur[1];    
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Mitigation ");
    foobar<<dmit[1];
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Strength ");
    foobar<<dstr[1];
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Mitigation Damdage ");
    foobar<<dmitpwr[1];
    foobar<<wxT(" for ");
    foobar<<dmitdur[1];
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Strength Damage ");
    foobar<<dstrpwr[1];
    foobar<<wxT(" for ");
    foobar<<dstrdur[1];
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Shield Hull Damage ");
    foobar<<dshpdamage[1];
    display3->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Shield Drop ");
    if (dsdrop[1] == true) {foobar<<wxT("for "); foobar<<dsdropdur[1]; }
    if (dsdrop[1] == false) {foobar<<wxT("Off"); }
    display3->Append(foobar);
}

void AutoresolverWindow::GenerateDisplay4()
{
    display4->Clear();
    wxString foobar;
    foobar<<dname[3];
    display4->Append(foobar);
    foobar = wxT("");
    foobar<<wxT("Hull ");
    foobar<<dhull[3];
    display4->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Power ");
    foobar<<dpower[3];
    display4->Append(foobar);
    foobar = wxT("");    
    foobar<<wxT("Command ");
    foobar<<dcommand[1];
    display4->Append(foobar);
}

void AutoresolverWindow::UpdateDisplay1()
{
    int num1 = (pshiplist->GetSelection()+1);
    wxString name1(OPlayer[num1].name.c_str(), wxConvUTF8);
    dname[0] = name1;
    dhull[0] = OPlayer[num1].maxhp;
    dpower[0] = OPlayer[num1].power;
    dmit[0] = OPlayer[num1].shieldmit;
    dstr[0] = OPlayer[num1].shieldstr;
    dmitpwr[0] = OPlayer[num1].shieldmitpower;
    dmitdur[0] = OPlayer[num1].shieldmitduration;
    dstrpwr[0] = OPlayer[num1].shieldstrpower;
    dstrdur[0] = OPlayer[num1].shieldstrduration;
    dshull[0] = OPlayer[num1].maxshp;
    dtmppwr[0] = OPlayer[num1].temppower;
    dtmpdur[0] = OPlayer[num1].tempduration;
    dshpdamage[0] = OPlayer[num1].shpdamage;
    dsdrop[0] = OPlayer[num1].shielddrop;
    dsdropdur[0] = OPlayer[num1].shielddropdur;
    GenerateDisplay1();
}

void AutoresolverWindow::UpdateDisplay2()
{
    int num2 = (pcshiplist->GetSelection()+1);
    wxString name2(OPlayerCommand[num2].name.c_str(), wxConvUTF8);
    dname[1] = name2;
    dhull[1] = OPlayerCommand[num2].maxhp;
    dpower[1] = OPlayerCommand[num2].power;
    dcommand[0] = OPlayerCommand[num2].rating;
    GenerateDisplay2();
}

void AutoresolverWindow::UpdateDisplay3()
{
    int num3 = (eshiplist->GetSelection()+1);
    wxString name3(OAI[num3].name.c_str(), wxConvUTF8);
    dname[2] = name3;
    dhull[2] = OAI[num3].maxhp;
    dpower[2] = OAI[num3].power;
    dmit[1] = OAI[num3].shieldmit;
    dstr[1] = OAI[num3].shieldstr;
    dmitpwr[1] = OAI[num3].shieldmitpower;
    dmitdur[1] = OAI[num3].shieldmitduration;
    dstrpwr[1] = OAI[num3].shieldstrpower;
    dstrdur[1] = OAI[num3].shieldstrduration;
    dshull[1] = OAI[num3].maxshp;
    dtmppwr[1] = OAI[num3].temppower;
    dtmpdur[1] = OAI[num3].tempduration;
    dshpdamage[1] = OAI[num3].shpdamage;
    dsdrop[1] = OAI[num3].shielddrop;
    dsdropdur[1] = OAI[num3].shielddropdur;
    GenerateDisplay3();
}

void AutoresolverWindow::UpdateDisplay4()
{
    int num4 = (ecshiplist->GetSelection()+1);
    wxString name4(OAICommand[num4].name.c_str(), wxConvUTF8);
    dname[3] = name4;
    dhull[3] = OAICommand[num4].maxhp;
    dpower[3] = OAICommand[num4].power;
    dcommand[1] = OAICommand[num4].rating;
    GenerateDisplay4();
}

void AutoresolverWindow::OnClick1(wxCommandEvent &event)
{
    UpdateDisplay1();
}

void AutoresolverWindow::OnClick2(wxCommandEvent &event)
{
    UpdateDisplay2();
}

void AutoresolverWindow::OnClick3(wxCommandEvent &event)
{
    UpdateDisplay3();
}

void AutoresolverWindow::OnClick4(wxCommandEvent &event)
{
    UpdateDisplay4();
}

void AutoresolverWindow::OnPreferences(wxCommandEvent &event)
{
    PreferencesDialog *foo = new PreferencesDialog(wxT("Preferences"), false);
    if (rickroll == true)
    {
  //      PlaySound(TEXT("Background.wav"),NULL,SND_FILENAME|SND_NODEFAULT);
    wxSound *foo = new wxSound(wxT("Background.wav"),false);
    foo->Create(wxT("Background.wav"),false);
    if (foo->IsOk() == true)
    {
        foo->Play();
    }
    }
/*        wxSound *bar = new wxSound(wxT("\\Sounds\\Background.wav"),false);
        wxMessageDialog *yay;
        wxMessageDialog *nay;
        if (bar->IsOk() == true)
        {
            if (bar->Play(wxSOUND_ASYNC | wxSOUND_LOOP )  == true)
            {
                yay = new wxMessageDialog(NULL,wxT("YAY!"),wxT("YAY!"),wxOK);
                yay->ShowModal();            
            }
        }
        else
        {
            nay = new wxMessageDialog(NULL,wxT("NAY!"),wxT("NAY!"),wxOK);
            nay->ShowModal();
        } */
}

void AutoresolverWindow::OnSettings(wxCommandEvent &event)
{
    PreferencesDialog *foo = new PreferencesDialog(wxT("Settings"), true);
    if (pbonusglobal == false) { pbonustxt->Disable(); text5->Disable(); }
    else { pbonustxt->Enable(); text5->Enable(); }
    if (pfleeglobal == false) { pfleetxt1->Disable(); text7->Disable();}
    else { pfleetxt1->Enable(); text7->Enable(); /*pfleetxt1->SetSelection(0);*/ }
    if (ptempbonusglobal == false) {text10->Disable(); text11->Disable(); ptempbonus->Disable(); ptempduration->Disable(); }
    else { text10->Enable(); text11->Enable(); ptempbonus->Enable(); ptempduration->Enable(); }
    if (ebonusglobal == false) { ebonustxt->Disable(); text6->Disable(); }
    else { ebonustxt->Enable(); text6->Enable(); }
    if (efleeglobal == false) {efleetxt1->Disable(); text8->Disable(); }
    else { efleetxt1->Enable(); text8->Enable(); /*efleetxt1->SetSelection(0);*/}
    if (etempbonusglobal == false) {text12->Disable(); text13->Disable(); etempbonus->Disable(); etempduration->Disable(); }
    else { text12->Enable(); text13->Enable(); etempbonus->Enable(); etempduration->Enable(); }
}

void AutoresolverWindow::PFleeClicked(wxCommandEvent &event)
{
    pfleetxt2->Clear();
    pfleetxt3->Clear();    
    int sel = pfleetxt1->GetSelection();
    if (sel > 3)
    {
        pfleetxt2->Enable();
        text14->Enable();
        for (int x=1;x<=playernumber;x++)
        {
            wxString bleh(OPlayer[x].name.c_str(),wxConvUTF8);
            pfleetxt2->Append(bleh);
        }
    }
    else
    {
        pfleetxt2->Disable();
        pfleetxt3->Disable();
        text14->Disable();
        text16->Disable();
    }
}

void AutoresolverWindow::EFleeClicked(wxCommandEvent &event)
{
    efleetxt2->Clear();
    efleetxt3->Clear();
    int sel = efleetxt1->GetSelection();
    if (sel > 3)
    {
        efleetxt2->Enable();
        text15->Enable();
        for (int x=1;x<=ainumber;x++)
        {
            wxString bleh(OAI[x].name.c_str(),wxConvUTF8);
            efleetxt2->Append(bleh);
        }
    }
    else
    {
        efleetxt2->Disable();
        efleetxt3->Disable();
        text15->Disable();
        text17->Disable();
    }
}

void AutoresolverWindow::PFleeShipClicked(wxCommandEvent &event)
{
    pfleetxt3->Clear();
    int sel = pfleetxt2->GetSelection()+1;
    if (pfleetxt1->GetSelection() == 5)
    {
        pfleetxt3->Enable();
        text16->Enable();
        for (int x=1;x<=OPlayer[sel].maxhp;x++)
        {
            wxString bleh = wxString::Format(wxT("%i"),x);
            pfleetxt3->Append(bleh);
        }
    }
}

void AutoresolverWindow::EFleeShipClicked(wxCommandEvent &event)
{
    efleetxt3->Clear();
    int sel = efleetxt2->GetSelection()+1;
    if (efleetxt1->GetSelection() == 5)
    {
        efleetxt3->Enable();
        text17->Enable();
        for (int x=1;x<=OAI[sel].maxhp;x++)
        {
            wxString bleh = wxString::Format(wxT("%i"),x);
            efleetxt3->Append(bleh);
        }
    }    
}

void AutoresolverWindow::UpdatePFleeHP()
{
    pfleetxt3->Clear();
    int sel = pfleetxt2->GetSelection()+1;
    if (pfleetxt1->GetSelection() == 5)
    {
        pfleetxt3->Enable();
        text16->Enable();
        for (int x=1;x<=OPlayer[sel].maxhp;x++)
        {
            wxString bleh = wxString::Format(wxT("%i"),x);
            pfleetxt3->Append(bleh);
        }
    }
}

void AutoresolverWindow::UpdateEFleeHP()
{
    efleetxt3->Clear();
    int sel = efleetxt2->GetSelection()+1;
    if (efleetxt1->GetSelection() == 5)
    {
        efleetxt3->Enable();
        text17->Enable();
        for (int x=1;x<=OAI[sel].maxhp;x++)
        {
            wxString bleh = wxString::Format(wxT("%i"),x);
            efleetxt3->Append(bleh);
        }
    }    
}
