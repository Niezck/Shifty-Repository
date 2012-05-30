#include "Units.h"

string filename;
string logfilename;
extern Ship Player[1000];
extern Ship AI[1000];
extern CommandShip PlayerCommand[100];
extern CommandShip AICommand[100];
extern int playerbonus;
extern int aibonus;
extern bool flee[9];
extern int fleeselection;
extern int fleehull; 
extern int playernumber;
extern int ainumber;
extern int playercommandnumber;
extern int aicommandnumber;
extern string StringToUpper(string strToConvert);
extern int victory;
void ListShips();

bool CheckFile()
{
    string YN;
    ifstream check(filename.c_str(),ios::in);
    if (check.is_open() ) 
    {
        cout<<"That file already exists, overwrite? [Y/N]\n";
        cin>>YN;
        YN = StringToUpper(YN);
        if (YN == "Y") 
        {
            return true;
        }
        else if (YN == "N")
        {
            return false;
        }
        else 
        {
            cout<<"Incorrect input.\n";
        }
    }
    else 
    {
        return true;
    }
}

void ListStats()
{
    ofstream logfile(filename.c_str(),ios::trunc);               
    logfile<<"*****Battle report: "<<filename<<"*****\n\n";
    logfile<<"[Starting Stats]:\n\n";
    if (playerbonus > 0) 
    {
        logfile<<"[b]Player fleet receives a power bonus of "<<playerbonus<<"[/b]\n"<<endl;
    }
    if (flee[1] == true) 
    {
        logfile<<"[b]Player fleet will flee if 50% casualties are taken.[/b]\n";
    }
    if (flee[2] == true) 
    {
        logfile<<"[b]Player fleet will flee if all command ships are destroyed.[/b]\n";
    }
    if (flee[3] == true) 
    {
        logfile<<"[b]Player fleet will have a 10% chance to flee each combat around.[/b]\n";
    }
    if (flee[4] == true) 
    {
        logfile<<"[b]Player fleet will flee if "<<Player[fleeselection].name<<" is destroyed.[/b]\n";
    }
    if (flee[5] == true) 
    {
        logfile<<"[b]Player fleet will flee if "<<Player[fleeselection].name<<" is reduced to "<<fleehull<<" points of hull or less.[/b]\n";
    }
    logfile.close();
    ListShips();
    logfile.open(filename.c_str(),ios::app);
    logfile<<"\n[Combat Details]:\n";
    logfile.close();
}

void FinalStats()
{
    ofstream logfile(filename.c_str(),ios::app);
    logfile<<"\n\n*****RESULTS*****";
    if (victory == 1)
    {
        logfile<<"\n\nPlayer wins!\n";
    }
    else if (victory == 2)
    {
        logfile<<"\n\nAI wins!\n";
    }
    if (playercommandnumber > 0)
    {
        for (int x=1;x<=playercommandnumber;x++)
        {
            logfile<<PlayerCommand[x].name<<" gained "<<PlayerCommand[x].xp<<"XP!\n";
        }
    }
    if (aicommandnumber > 0)
    {
        for (int x=1;x<=aicommandnumber;x++)
        {
            logfile<<AICommand[x].name<<" gained "<<AICommand[x].xp<<"XP!\n";
        }
    }
    logfile<<"\n[Losses]:\n";
    if (playercommandnumber > 0)
    {
        for (int x=1;x<=playercommandnumber;x++)
        {
            if (PlayerCommand[x].currenthp == -1)
            {
                logfile<<PlayerCommand[x].name<<" destroyed!\n";
            }
        }
    }
    if (aicommandnumber > 0)
    {
        for (int x=1;x<=aicommandnumber;x++)
        {
            if (AICommand[x].currenthp == -1)
            {
                logfile<<AICommand[x].name<<" destroyed!\n";
            }
        }
    }
    logfile<<endl;
    for (int x=1;x<=playernumber;x++)
    {
        if (Player[x].currenthp <= 0)
        {
            logfile<<Player[x].name<<" destroyed!\n";
        }
    }
    for (int x=1;x<=ainumber;x++)
    {
        if (AI[x].currenthp <= 0)
        {
            logfile<<AI[x].name<<" destroyed!\n";
        }
    }
    logfile<<"\n[Finishing Stats]:\n";
    logfile.close();
    ListShips(); 
}

void ListShips()
{
    ofstream logfile(filename.c_str(),ios::app);
    if (playercommandnumber > 0)
    {
        for (int x=1;x<=playercommandnumber;x++)
        {
            logfile<<"[b][color=green]"<<PlayerCommand[x].name<<": Command Rating "<<PlayerCommand[x].rating<<", Power "<<PlayerCommand[x].power<<", HP "<<PlayerCommand[x].currenthp<<"/"<<PlayerCommand[x].maxhp<<"[/b][/color]\n";
        }
    }
    for (int x=1;x<=playernumber;x++)
    {
        logfile<<"[color=green]"<<Player[x].name<<": Power "<<Player[x].power;
        if (Player[x].temppower >0) { logfile<<", Temp Power "<<Player[x].temppower<<" for "<<Player[x].tempduration; }
        if (Player[x].shpdamage >0) { logfile<<", Bonus Shield Hull Damage "<<Player[x].shpdamage; }        
        if (Player[x].shieldmitpower>0) 
        { 
            logfile<<", Shield Mit Gun "<<Player[x].shieldmitpower<<"/";
            if (Player[x].shieldmitduration == 0) {logfile<<"Unlimited"; }
            else {logfile<<Player[x].shieldmitduration; }            
        }
        if (Player[x].shieldstrpower>0) 
        { 
            logfile<<", Shield Str Gun "<<Player[x].shieldstrpower<<"/";
            if (Player[x].shieldstrduration == 0) {logfile<<"Unlimited"; }
            else {logfile<<Player[x].shieldstrduration; }
        }
        if (Player[x].shielddrop == true )
        {
            logfile<<", Shield Drop for ";
            if (Player[x].shielddropdur == 0) {logfile<<"unlimited"; }
            else {logfile<<Player[x].shielddropdur; }
        }        
        logfile<<", Shield Mitigation "<<Player[x].shieldmit<<", Shield Strength "<<Player[x].shieldstr<<", HP "<<Player[x].currenthp<<"/"<<Player[x].maxhp;
        if (Player[x].maxshp>0) {logfile<<", Shield HP "<<Player[x].currentshp<<"/"<<Player[x].maxshp; }
        if (Player[x].commanded >0) { logfile<<" (Commanded +"<<Player[x].commanded<<" by Player Command Ship "<<Player[x].commandedby<<")"; }
        logfile<<"[/color]\n";
    }
    logfile<<endl;
    if (aibonus > 0)
    {
        logfile<<"[b]AI fleet receives a power bonus of "<<aibonus<<"[/b]\n";
    }
    if (aicommandnumber > 0)
    {
        for (int x=1;x<=aicommandnumber;x++)
        {
            logfile<<"[b][color=red]"<<AICommand[x].name<<": Command Rating "<<AICommand[x].rating<<", Power "<<AICommand[x].power<<", HP "<<AICommand[x].currenthp<<"/"<<AICommand[x].maxhp<<"[/b][/color]\n";
        }
    }
    for (int x=1;x<=ainumber;x++)
    {
        logfile<<"[color=red]"<<AI[x].name<<": Power "<<AI[x].power;
        if (AI[x].temppower >0) { logfile<<", Temp Power "<<AI[x].temppower<<" for "<<AI[x].tempduration; }
        if (AI[x].shpdamage >0) { logfile<<", Bonus Shield Hull Damage "<<AI[x].shpdamage; }
        if (AI[x].shieldmitpower>0)
        { 
            logfile<<", Shield Mit Gun "<<AI[x].shieldmitpower<<"/";
            if (AI[x].shieldmitduration == 0) {logfile<<"Unlimited"; }
            else { logfile<<AI[x].shieldmitduration; }            
        }
        if (AI[x].shieldstrpower>0) 
        { 
            logfile<<", Shield Str Gun "<<AI[x].shieldstrpower<<"/";
            if (AI[x].shieldstrduration == 0) {logfile<<"Unlimited"; }
            else { logfile<<AI[x].shieldstrduration; }
        }
        if (AI[x].shielddrop == true )
        {
            logfile<<", Shield Drop for ";
            if (AI[x].shielddropdur == 0) {logfile<<"unlimited"; }
            else {logfile<<AI[x].shielddropdur; }
        }
        logfile<<", Shield Mitigation "<<AI[x].shieldmit<<", Shield Strength "<<AI[x].shieldstr<<", HP "<<AI[x].currenthp<<"/"<<AI[x].maxhp;
        if (AI[x].maxshp>0) {logfile<<", Shield HP "<<AI[x].currentshp<<"/"<<AI[x].maxshp; }
        if (AI[x].commanded >0) { logfile<<" (Commanded +"<<AI[x].commanded<<" by AI Command Ship "<<AI[x].commandedby<<")"; }
        logfile<<"[/color]\n";
    }
}    
