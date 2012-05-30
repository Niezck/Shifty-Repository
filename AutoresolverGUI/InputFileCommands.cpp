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
extern int playertempbonus;
extern int playertempduration;
extern int aitempbonus;
extern int aitempduration;
extern string ifilename;
string line;
int playerprocessed = 0;
int aiprocessed = 0;
int playercommandprocessed = 0;
int aicommandprocessed = 0;
char* trim(char* c);
char* nospace(char* c);

void ProcessLine(string s, int linenum)
{
    char *cstr, *out;
    cstr = new char[s.size()+1];
    strcpy(cstr,s.c_str());
    if (linenum <= 12)
    {
        out = strtok(cstr,"=");
    }
    else if (linenum > 12)
    {
        out = strtok(cstr,"=/");
    }
    if (out!=NULL)
    {
        if (linenum > 12)
        {
            out = trim(out);
            if (playercommandprocessed < playercommandnumber)
            {
                int num = playercommandprocessed+1;
                if (atoi(out) == 1)
                {
                    stringstream sstm;
                    sstm<<"Player Command Ship "<<num;
                    PlayerCommand[num].name = sstm.str();
                }
                else
                {
                    PlayerCommand[num].name = out;
                }
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                PlayerCommand[num].power = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                PlayerCommand[num].rating = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                PlayerCommand[num].currenthp = atoi(out);
                PlayerCommand[num].maxhp = atoi(out);
                PlayerCommand[num].SetBonus();
                playercommandprocessed+=1;
            }                
            else if (playerprocessed < playernumber)
            {
                out = trim(out);
                int num = playerprocessed+1;
                if (atoi(out) == 1)
                {
                    stringstream sstm;
                    sstm<<"Player Ship "<<num;
                    Player[num].name = sstm.str();
                }
                else
                {
                    Player[num].name = out;
                }
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].power = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].shieldmit = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].shieldstr = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].maxhp = atoi(out);
                Player[num].currenthp = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].maxshp = atoi(out);
                Player[num].currentshp = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/"); 
                Player[num].temppower = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].tempduration = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].shieldstrpower = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].shieldstrduration = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].shieldmitpower = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                Player[num].shieldmitduration = atoi(out); 
                playerprocessed+=1;
            }
            else if (aicommandprocessed < aicommandnumber)
            {
                out = trim(out);
                int num = aicommandprocessed+1;
                if (atoi(out) == 1)
                {
                    stringstream sstm;
                    sstm<<"AI Command Ship "<<num;
                    AICommand[num].name = sstm.str();
                }
                else
                {
                    AICommand[num].name = out;
                }
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AICommand[num].power = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AICommand[num].rating = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AICommand[num].maxhp = atoi(out);
                AICommand[num].currenthp = atoi(out);
                AICommand[num].SetBonus();
                aicommandprocessed+=1;
            }                
            else if (aiprocessed < ainumber)
            {
                out = trim(out);
                int num = aiprocessed+1;
                if (atoi(out) == 1)
                {
                    stringstream sstm;
                    sstm<<"AI Ship "<<num;
                    AI[num].name = sstm.str();
                }
                else
                {
                    AI[num].name = out;
                }
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].power = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].shieldmit = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].shieldstr = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].currenthp = atoi(out);
                AI[num].maxhp = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].currentshp = atoi(out);
                AI[num].maxshp = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].temppower = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].tempduration = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].shieldstrpower = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].shieldstrduration = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].shieldmitpower = atoi(out);
                out = strtok(NULL,":/");
                out = strtok(NULL,":/");
                AI[num].shieldmitduration = atoi(out); 
                aiprocessed+=1;
            }
        }
        else
        {
            out = strtok(NULL," /");
            switch(linenum) 
            {
                case 1:
                    playernumber = atoi(out);
                    break;
                case 2:
                    ainumber = atoi(out);
                    break;
                case 3:
                    playercommandnumber = atoi(out);
                    break;
                case 4:
                    aicommandnumber = atoi(out);
                    break;
                case 5:
                    playerbonus = atoi(out);
                    break;
                case 6:
                    aibonus = atoi(out);
                    break;
                case 7:
                    flee[atoi(out)] = true;
                    if ((atoi(out) == 4) || (atoi(out) == 5))
                    {
                        int tempout = atoi(out);
                        out = strtok(NULL,":/");
                        fleeselection = atoi(out);
                        if (tempout == 5)
                        {
                            out = strtok(NULL,":/");
                            fleehull = atoi(out);
                        }
                    }
                case 8:
                    break;
                case 9:
                    playertempbonus = atoi(out);
                    break;
                case 10:
                    playertempduration = atoi(out);
                    break;
                case 11:
                    aitempbonus = atoi(out);
                    break;
                case 12:
                    aitempduration = atoi(out);
                    break; 
                default:
                    break;
            }
        }
    }
    delete[] cstr;
}

bool CheckIFile()
{
    string YN;
    ifstream check(ifilename.c_str(),ios::in);
    if (!(check.is_open()) ) 
    {
        cout<<"That file does not exist.\n";
        check.close();
        return false;
    }
    else 
    {
        check.close();
        return true;
    }
}

void GetInput()
{
    int x=0;    
    ifstream infile(ifilename.c_str());
    while (infile.eof() != true)
    {
        getline(infile,line);
        x+=1;
        ProcessLine(line,x);
    }
}

char* nospace(char* c)
{
    string s = string(c);
    s.erase(remove_if (s.begin(),s.end(),(int(*)(int))isspace),s.end());
    char *returnval = new char[s.size()+1];
    strcpy(returnval,s.c_str());
    return returnval;
}

char* trim(char* c)
{
    string s = string(c);
    string pWhiteSpace = " \t";
    size_t beginStr = s.find_first_not_of(pWhiteSpace);
    size_t endStr = s.find_last_not_of(pWhiteSpace);
    size_t range = endStr - beginStr+1;
    s = s.substr(beginStr,range);
    char *returnval = new char[s.size()+1];
    strcpy(returnval,s.c_str());
    return returnval;
}
