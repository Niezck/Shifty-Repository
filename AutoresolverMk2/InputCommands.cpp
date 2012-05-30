#include "Units.h"

using namespace std;

extern int playernumber;
extern int playercommandnumber;
extern int ainumber;
extern int aicommandnumber;
extern Ship Player[1000];
extern Ship AI[1000];
extern CommandShip PlayerCommand[10];
extern CommandShip AICommand[10];
extern string StringToUpper(string strToConvert);
extern bool flee[9];
extern int fleehull;
extern int fleeselection;
extern int playerbonus;
extern int aibonus;

/* Input Functions */

bool Options()
{
    string input;
    cout<<"\nEnter options: [Bonus|Commander|Done|Exit|Flee|Help]\n";
    cin>>input;
    if (StringToUpper(input) == "BONUS")
    {
        string choice;
        cout<<"Player or AI?\n";
        cin>>choice;
        if (StringToUpper(choice) == "PLAYER")
        {
            cout<<"Enter amount - ";
            cin>>playerbonus;
        }
        else if (StringToUpper(choice) == "AI")
        {
            cout<<"Enter amount - ";
            cin>>aibonus;
        }
        else
        {
            cout<<"Incorrect input.\n";
        }
    }
    else if (StringToUpper(input) == "COMMANDER")
    {
        string choice;
        cout<<"Player or AI?\n";
        cin>>choice;
        if (StringToUpper(choice) == "PLAYER")
        {
            playercommandnumber+=1;
            cout<<"Player Command Ship "<<playercommandnumber<<": \n";
            cout<<"Enter command rating - ";
            cin>>PlayerCommand[playercommandnumber].rating;
            PlayerCommand[playercommandnumber].SetBonus();
            cout<<"Enter power - ";
            cin>>PlayerCommand[playercommandnumber].power;
            cout<<"Enter HP - ";
            cin>>PlayerCommand[playercommandnumber].maxhp;
            PlayerCommand[playercommandnumber].currenthp = PlayerCommand[playercommandnumber].maxhp;
        }
        else if (StringToUpper(choice) == "AI")
        {
            aicommandnumber+=1;
            cout<<"AI Command Ship "<<aicommandnumber<<": \n";
            cout<<"Enter command rating - ";
            cin>>AICommand[aicommandnumber].rating;
            AICommand[aicommandnumber].SetBonus();
            cout<<"Enter power - ";
            cin>>AICommand[aicommandnumber].power;
            cout<<"Enter HP - ";
            cin>>AICommand[aicommandnumber].maxhp;
            AICommand[aicommandnumber].currenthp = AICommand[aicommandnumber].maxhp;
        }
        else
        {
            cout<<"Incorrect input.\n";
        }
    }
    else if (StringToUpper(input) == "DONE")
    {
        return true;
    }
    else if (StringToUpper(input) == "EXIT")
    {
        exit(0);
    }
    else if (StringToUpper(input) == "FLEE")
    {
        cout<<"Enter flee option: 1. 50% casualties\n2. All command ships dead\n3. 10% chance each round\n4. Death of a specific ship\n5. Ship is reduced below X hull\n";
        int fleechoice;
        cin>>fleechoice;
        flee[fleechoice] = true;
        if ((flee[4] == true) || (flee[5] == true))
        {
            cout<<"Which ship?\n";
            cin>>fleeselection;
        }
        if (flee[5] == true) 
        {
            cout<<"What value of hull?\n";
            cin>>fleehull; 
        }
    }
    else if (StringToUpper(input) == "HELP")
    {
        cout<<"/---------- Help ----------/\n";
        cout<<"Bonus - This applies a flat bonus to all ships in either the player or AI fleet.\n";
        cout<<"Commander - This adds a command ship to either the player or AI fleet.\n";
        cout<<"Done - This closes the options menu and proceeds to run the combat.\n";
        cout<<"Exit - This closes the program completely.\n";
        cout<<"Flee - This adds a flee option to either the player or AI fleet.\n";
        cout<<"Help - This displays this menu.\n";
    }
    else
    {
        cout<<"That is not a valid option. Please select one of the listed options.\n";
    }
    return false;
}

void GetPlayerNumber()
{
    cout<<"Enter number of player ships - ";
    cin>>playernumber;
}

void GetAINumber()
{
    cout<<"Enter number of AI ships - ";
    cin>>ainumber;
}

void GetPlayerPowers()
{
    for (int x=1;x<=playernumber;x++)
    {
        cout<<"Enter power of player ship "<<x<<" - ";
        cin>>Player[x].power;
    }
}

void GetAIPowers()
{
    for (int x=1;x<=ainumber;x++)
    {
        cout<<"Enter power of AI ship "<<x<<" - ";
        cin>>AI[x].power;
    }
}

void GetPlayerShieldMit()
{
    for (int x=1;x<=playernumber;x++)
    {
        cout<<"Enter shield mitigation of player ship "<<x<<" - ";
        cin>>Player[x].shieldmit;
    }
}

void GetAIShieldMit()
{
    for (int x=1;x<=ainumber;x++)
    {
        cout<<"Enter shield mitigation of AI ship "<<x<<" - ";
        cin>>AI[x].shieldmit;
    }
}

void GetPlayerShieldStr()
{
    for (int x=1;x<=playernumber;x++)
    {
        cout<<"Enter shield strength of player ship "<<x<<" - ";
        cin>>Player[x].shieldstr;
    }
}

void GetAIShieldStr()
{
    for (int x=1;x<=ainumber;x++)
    {
        cout<<"Enter shield strength of AI ship "<<x<<" - ";
        cin>>AI[x].shieldstr;
    }
}

void GetPlayerHP()
{
    for (int x=1;x<=playernumber;x++)
    {
        cout<<"Enter HP of player ship "<<x<<" - ";
        cin>>Player[x].maxhp;
        Player[x].currenthp = Player[x].maxhp;
    }
}

void GetAIHP()
{
    for (int x=1;x<=ainumber;x++)
    {
        cout<<"Enter HP of AI ship "<<x<<" - ";
        cin>>AI[x].maxhp;
        AI[x].currenthp = AI[x].maxhp;
    }
}


