#include "Units.h"

extern fstream logfile;
extern string filename;
extern Ship Player[100];
extern Ship AI[100];
extern CommandShip PlayerCommand[10];
extern CommandShip AICommand[10];
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
extern int playertempbonus;
extern int playertempduration;
extern int aitempbonus;
extern int aitempduration;

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
    if (playertempbonus > 0)
    {
            logfile<<"[b]Player fleet receives a temporary power bonus of "<<playertempbonus<<" for "<<playertempduration<<" rounds.[/b]\n";
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
    if (playercommandnumber > 0)
    {
        for (int x=1;x<=playercommandnumber;x++)
        {
            logfile<<"[b][color=green]"<<PlayerCommand[x].name<<": Command Rating "<<PlayerCommand[x].rating<<", Power "<<PlayerCommand[x].power<<", HP "<<PlayerCommand[x].currenthp<<"[/b][/color]\n";
        }
    }
    for (int x=1;x<=playernumber;x++)
    {
        logfile<<"[color=green]"<<Player[x].name<<": Power "<<Player[x].power<<", Temp Power "<<Player[x].temppower<<" for "<<Player[x].tempduration<<" exchanges, Shield Mit Gun "<<Player[x].shieldmitpower<<"/"<<Player[x].shieldmitduration<<", Shield Str Gun "<<Player[x].shieldstrpower<<"/"<<Player[x].shieldstrduration<<", Shield Mitigation "<<Player[x].shieldmit<<", Shield Strength "<<Player[x].shieldstr<<", HP "<<Player[x].currenthp<<", Shield HP "<<Player[x].currentshp<<" (Commanded +"<<Player[x].commanded<<" by Player Command Ship "<<Player[x].commandedby<<")[/color]\n";;
    }
    logfile<<endl;
    if (aibonus > 0)
    {
        logfile<<"[b]AI fleet receives a power bonus of "<<aibonus<<"[/b]\n";
    }
    if (aitempbonus > 0)
    {
        logfile<<"[b]AI fleet receives a temporary power bonus of "<<aitempbonus<<" for "<<aitempduration<<" rounds.[/b]\n";
    }    
    if (aicommandnumber > 0)
    {
        for (int x=1;x<=aicommandnumber;x++)
        {
            logfile<<"[b][color=red]"<<AICommand[x].name<<": Command Rating "<<AICommand[x].rating<<", Power "<<AICommand[x].power<<", HP "<<AICommand[x].currenthp<<"[/b][/color]\n";
        }
    }
    for (int x=1;x<=ainumber;x++)
    {
        logfile<<"[color=red]"<<AI[x].name<<": Power "<<AI[x].power<<", Temp Power "<<AI[x].temppower<<" for "<<AI[x].tempduration<<" exchanges, Shield Mit Gun "<<AI[x].shieldmitpower<<"/"<<AI[x].shieldmitduration<<", Shield Str Gun "<<AI[x].shieldstrpower<<"/"<<AI[x].shieldstrduration<<", Shield Mitigation "<<AI[x].shieldmit<<", Shield Strength "<<AI[x].shieldstr<<", HP "<<AI[x].currenthp<<", Shield HP "<<AI[x].currentshp<<" (Commanded +"<<AI[x].commanded<<" by AI Command Ship "<<AI[x].commandedby<<")[/color]\n";
    }
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
    if (playercommandnumber > 0)
    {
        for (int x=1;x<=playercommandnumber;x++)
        {
            logfile<<"[b][color=green]"<<PlayerCommand[x].name<<x<<": Command Rating "<<PlayerCommand[x].rating<<", Power "<<PlayerCommand[x].power<<", HP "<<PlayerCommand[x].currenthp<<"/1[/b][/color]\n";
        }
    }
    for (int x=1;x<=playernumber;x++)
    {
        logfile<<"[color=green]"<<Player[x].name<<": Power "<<Player[x].power<<", Shield Mitigation "<<Player[x].shieldmit<<", Shield Strength "<<Player[x].shieldstr<<", HP "<<Player[x].currenthp<<"/"<<Player[x].maxhp<<"[/color]\n";;
    }
    logfile<<endl;
    if (aicommandnumber > 0)
    {
        for (int x=1;x<=aicommandnumber;x++)
        {
            logfile<<"[b][color=red]"<<AICommand[x].name<<": Command Rating "<<AICommand[x].rating<<", Power "<<AICommand[x].power<<", HP "<<AICommand[x].currenthp<<"/1[/b][/color]\n";
        }
    }
    for (int x=1;x<=ainumber;x++)
    {
        logfile<<"[color=red]"<<AI[x].name<<": Power "<<AI[x].power<<", Shield Mitigation "<<AI[x].shieldmit<<", Shield Strength "<<AI[x].shieldstr<<", HP "<<AI[x].currenthp<<"/"<<AI[x].maxhp<<"[/color]\n";
    }    
    logfile.close();
}

