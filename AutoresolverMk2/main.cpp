#include "Units.h"

using namespace std;

//Object definitions
Ship Player[100];
CommandShip PlayerCommand[10];
Ship AI[100];
CommandShip AICommand[10];

//Integer definitions
int playernumber;
int ainumber;
int playercommandnumber;
int aicommandnumber;
int fleehull;
int fleeselection;
int playerbonus;
int aibonus;
int playerdeaths;
int aideaths;
int victory = 0;
int totalexchanges = 0;
int playertempbonus = 0;
int playertempduration = 0;
int aitempbonus = 0;
int aitempduration = 0;

//Bool definitions
bool flee[9];
bool fled = false;
bool magicmode = false;

//File definitions
fstream logfile;
string filename;
string ifilename;
void Cleanup();
void GetFileName();
void GetIFileName();
extern bool CheckFile();
extern bool CheckIFile();
extern void ListStats();
extern void FinalStats();
extern void GetInput();

//Combat definitions
extern void CombatRound();
extern void CombatRoundM();
extern void CheckStatus();
extern void CheckStatusM();

//Utility definitions
string StringToUpper(string strToConvert);
void SetUpPrebattle();
bool ConfirmBattle();
void GetCombatType();
bool InputCorrect = false;

//Input definitions
extern void GetPlayerNumber();
extern void GetAINumber();
extern void GetPlayerPowers();
extern void GetAIPowers();
extern void GetPlayerShieldMit();
extern void GetAIShieldMit();
extern void GetPlayerShieldStr();
extern void GetAIShieldStr();
extern void GetPlayerHP();
extern void GetAIHP();
extern bool Options();


int main()
{
    Cleanup();
    GetCombatType();
    if (magicmode == true)
    {
        while (!InputCorrect)
        {
            GetIFileName();
            if (CheckIFile() == true)
            {
                InputCorrect = true;
            }
            GetInput();
        }
    }
    if (magicmode == false)
    {
        GetFileName();
        GetPlayerNumber();
        GetAINumber();
        GetPlayerPowers();
        GetAIPowers();
        GetPlayerShieldMit();
        GetAIShieldMit();
        GetPlayerShieldStr();
        GetAIShieldStr();
        GetPlayerHP();
        GetAIHP();
        while (true)
        {
            if (Options() == true)
            {
                break;
            }
        }
    }
    SetUpPrebattle();
    ConfirmBattle();
    while (true)
    {
        GetFileName();
        if (CheckFile() == true)
        {
            break;
        }
    }
    ListStats();
    while (true)
    {
        if (magicmode = true)
        {
            CombatRoundM();
            totalexchanges+=1;
            CheckStatusM();
        }
        else
        {
            CombatRound();
            totalexchanges+=1;
            CheckStatus();
        }
        if (victory > 0) {break;}
    }
    FinalStats();
    cout<<"Combat autoresolved successfully. Press any key to close.\n";
    cin.ignore();
    char foo[256];
    cin.get(foo,256);
}

/* Utility Functions */

void GetCombatType()
{
    string input;
    cout<<"Magic Mode? [Y|N]\n";
    cin>>input;
    if (StringToUpper(input) == "Y")
    {
        magicmode = true;
    }
    else
    {
    }
}

void GetIFileName()
{
    cout<<"Enter filename of the input file:\n";
    cin>>ifilename;
    ifilename.append(".txt");
}


bool ConfirmBattle()
{
    cout<<"Confirm Ship information: \n";
    if (playercommandnumber > 0) 
    {
         for (int x=1;x<=playercommandnumber;x++)
         {
                cout<<PlayerCommand[x].name<<": Command "<<PlayerCommand[x].rating<<", Pwr "<<PlayerCommand[x].power<<", HP "<<PlayerCommand[x].maxhp<<endl;
         }
    }
    for (int x=1;x<=playernumber;x++)
    {
        cout<<Player[x].name<<": HP"<<Player[x].maxhp<<" Pwr"<<Player[x].power<<" Mit"<<Player[x].shieldmit<<" SStr"<<Player[x].shieldstr<<"\n";
    }
    if (aicommandnumber > 0) 
    {
        for (int x=1;x<=aicommandnumber;x++) 
        {
            cout<<AICommand[x].name<<": Command "<<AICommand[x].rating<<", Pwr "<<AICommand[x].power<<", HP "<<AICommand[x].maxhp<<endl; 
        }
    }
    for (int x=1;x<=ainumber;x++) 
    {
        cout<<AI[x].name<<": HP"<<AI[x].maxhp<<" Pwr"<<AI[x].power<<" Mit"<<AI[x].shieldmit<<" SStr"<<AI[x].shieldstr<<"\n";
    }
    while (true)
    {
        cout<<"Confirm? [Yes|No]\n";
        string confirm;
        cin>>confirm;
        string answer = StringToUpper(confirm);
        if (answer == "YES")
        {
            return true;
        }
        else if (answer == "NO")
        {
            return false;
            cout<<"Closing.\n";
            Cleanup();
            exit(0);
        }
        else
        {
            cout<<"Incorrect input.\n";
        }
    }
    return false;
}

void SetUpPrebattle()
{
    srand((unsigned)time(0));
    for (int x=1;x<=playernumber;x++)
    {
        if (Player[x].tempduration > 0)
        {
            Player[x].power += Player[x].temppower;
        }
    }
    for (int x=1;x<=ainumber;x++)
    {
        if (AI[x].tempduration > 0)
        {
            AI[x].power += AI[x].temppower;
        }
    }
    if (playercommandnumber > 0)
    {
        for (int x=1;x<=playercommandnumber;x++)
        {
            int q = 0;
            while (true)
            {
                int p = (rand()%playernumber+1);
                if (Player[p].commandedby == 0)
                {
                    Player[p].commandedby = x;
                    Player[p].commanded = PlayerCommand[x].bonus;
                    q++;
                }
                if ((q == PlayerCommand[x].rating) || (q == playernumber))
                {
                    break;
                }
            }
        }
    }
    if (aicommandnumber > 0)
    {
        for (int x=1;x<=aicommandnumber;x++)
        {
            int q = 0;
            while (true)
            {
                int p = (rand()%ainumber+1);
                if (AI[p].commandedby == 0)
                {
                    AI[p].commandedby = x;
                    AI[p].commanded = AICommand[x].bonus;
                    q++;
                }
                if ((q == AICommand[x].rating) || (q == ainumber))
                {
                    break;
                }                
            }
        }        
    }
    if (aibonus > 0)
    {
        for (int x=1;x<=ainumber;x++)
        {
            AI[x].power+=aibonus;
        }
    }
    if (playerbonus > 0)
    {
        for (int x=1;x<=playernumber;x++)
        {
            Player[x].power+=playerbonus;
        }
    }
    if (playertempduration > 0)
    {
        for (int x=1;x<=playernumber;x++)
        {
            Player[x].power += playertempbonus;
        }
    }
    if (aitempduration > 0)
    {
        for (int x=1;x<=ainumber;x++)
        {
            AI[x].power += aitempbonus;
        }
    }
}

void Cleanup()
{
    playernumber = 0;
    playercommandnumber = 0;
    ainumber = 0;
    aicommandnumber = 0;
    filename = "";
    fleehull = 0;
    fleeselection = 0;
    aibonus = 0;
    playerbonus = 0;
    victory = 0;
    fled = false;
    for (int x=1;x<10;x++) {flee[x] = false;}
    playerdeaths = 0;
    aideaths = 0;
    fleehull = 0;
    fleeselection = 0;
    
}

void GetFileName()
{
    cout<<"Enter filename of the output file.\n";
    cin>>filename;
    filename.append(".txt");
}

string StringToUpper(string strToConvert)
{ //change each element of the string to upper case
   for(unsigned int i=0;i<strToConvert.length();i++)
   {
      strToConvert[i] = toupper(strToConvert[i]);
   }
   return strToConvert;//return the converted string
}
