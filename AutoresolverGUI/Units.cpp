#include "Units.h"

Ship::Ship()
{
    Destroy();
}

Ship::~Ship()
{
    Destroy();
}

void Ship::Destroy()
{
    maxhp = 0;
    currenthp = 0;
    name = "";
    power = 0;
    shieldmit = 0;
    shieldstr = 0;
    commandedby = 0;
    commanded = 0;
    maxshp = 0;
    currentshp = 0;
    exchanges = 0;
    temppower = 0;
    tempduration = 0;
    shieldstrpower = 0;
    shieldstrduration = 0;
    shieldmitpower = 0;
    shieldmitduration = 0;
    shieldstrdroppednum = 0;
    shieldmitdroppednum = 0;
    for (int x=0;x<100;x++)
    {
        shieldstrdropped[x] = 0;
        shieldmitdropped[x] = 0;
        shieldstrdroppedduration[x] = 0;
        shieldmitdroppedduration[x] = 0;
    }
    shpdamage = 0;
    shielddrop = false;
    shielddropdur = 0;
    alive = false;
    used = false;
}

void CommandShip::SetBonus()
{
    if (rating%2 == 0) {bonus = rating/2;}
    else if (rating%2 != 0) {bonus = (rating+1)/2;}
}

Ship Player[1000];
Ship AI[1000];
CommandShip PlayerCommand[100];
CommandShip AICommand[100];
int playernumber;
int ainumber;
int playercommandnumber;
int aicommandnumber;
int aibonus;
int playerbonus;
bool flee[9];
int fleeselection;
int fleehull;
int victory;
int playerdeaths = 0;
int aideaths = 0;
bool fled;
extern string filename;
extern string logfilename;
int totalexchanges;
int playertempbonus;
int playertempduration;
int aitempbonus;
int aitempduration;
extern bool lif;

void Cleanup()
{
    playerbonus = 0;
    aibonus = 0;
    for (int x=0;x<10;x++) {flee[x] = false;}
    fleeselection = 0;
    fleehull = 0;
    victory = 0;
    playerdeaths = 0;
    aideaths = 0;
    fled = false;
    playertempbonus = 0;
    playertempduration = 0;
    aitempbonus = 0;
    aitempduration = 0;
    totalexchanges = 0;
    lif = false;
}

extern Ship OAI[1000],OPlayer[1000];
extern CommandShip OAICommand[100],OPlayerCommand[100];

void CopyOldShips()
{
    ofstream logfile2(logfilename.c_str(),ios::app);
    logfile2<<"\nCommencing Copying Ships\n";
    for (int x=1;x<=playernumber;x++)
    {
        Player[x] = OPlayer[x];
        logfile2<<"Player Ship "<<x<<" done!\n";        
    }
    for (int x=1;x<=ainumber;x++)
    {
        AI[x] = OAI[x];
        logfile2<<"AI Ship "<<x<<" done!\n";        
    }
    for (int x=1;x<=playercommandnumber;x++)
    {
        PlayerCommand[x] = OPlayerCommand[x];
        logfile2<<"Player Command Ship "<<x<<" done!\n";        
    }
    for (int x=1;x<=aicommandnumber;x++)
    {
        AICommand[x] = OAICommand[x];
        logfile2<<"AI Command Ship "<<x<<" done!\n";
    }       
    logfile2.close(); 
}
