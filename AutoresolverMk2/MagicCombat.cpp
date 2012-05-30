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
extern int playerdeaths;
extern int aideaths;
extern bool fled;
extern int totalexchanges;
extern int playertempbonus;
extern int playertempduration;
extern int aitempbonus;
extern int aitempduration;

void CheckStatusM()
{
    ofstream logfile(filename.c_str(),ios::app);
    if (totalexchanges == playertempduration)
    {
        for (int x=1;x<=playernumber;x++)
        {
            Player[x].power -= playertempbonus;
        }
        logfile<<"Player fleet has lost its temporary power bonus!\n";
    }
    if (totalexchanges == aitempduration)
    {
        for (int x=1;x<=ainumber;x++)
        {
            AI[x].power -= aitempbonus;
        }
        logfile<<"AI fleet has lost its temporary power bonus!\n";
    }
    for (int x=1;x<=playernumber;x++)
    {
        for (int y=1;y<=100;y++)
        {
            if ((Player[x].shieldmitdroppedduration[y] == Player[x].exchanges) && (Player[x].exchanges >0))
            {
                Player[x].shieldmit += Player[x].shieldmitdropped[y];
                logfile<<Player[x].name<<" has had "<<Player[x].shieldmitdropped[y]<<" shield mitigation restored!\n";
                Player[x].shieldmitdroppedduration[y] = 0;
                Player[x].shieldmitdropped[y] = 0;
            }
            if ((Player[x].shieldstrdroppedduration[y] == Player[x].exchanges) && (Player[x].exchanges >0))
            {
                Player[x].shieldstr += Player[x].shieldstrdropped[y];
                logfile<<Player[x].name<<" has had "<<Player[x].shieldstrdropped[y]<<" shield strength restored!\n";
                Player[x].shieldstrdroppedduration[y] = 0;
                Player[x].shieldstrdropped[y] = 0;                
            }
        }
        if (Player[x].tempduration > 0)
        {
            if (Player[x].tempduration == Player[x].exchanges)
            {
                Player[x].power -= Player[x].temppower;
                logfile<<Player[x].name<<" has lost its temporary power bonus!\n";
                Player[x].tempduration = 0;
            }
        }
    }
    for (int x=1;x<=ainumber;x++)
    {
        for (int y=1;y<=100;y++)
        {
            if ((AI[x].shieldmitdroppedduration[y] == AI[x].exchanges) && (AI[x].exchanges > 0))
            {
                AI[x].shieldmit += AI[x].shieldmitdropped[y];
                logfile<<AI[x].name<<" has had "<<AI[x].shieldmitdropped[y]<<" shield mitigation restored!\n";
                AI[x].shieldmitdropped[y] = 0;
                AI[x].shieldmitdroppedduration[y] = 0;
            }
            if ((AI[x].shieldstrdroppedduration[y] == AI[x].exchanges) && (AI[x].exchanges > 0))
            {
                AI[x].shieldstr += AI[x].shieldstrdropped[y];
                logfile<<AI[x].name<<" has had "<<AI[x].shieldstrdropped[y]<<" shield strength restored!\n";
                AI[x].shieldstrdropped[y] = 0;
                AI[x].shieldstrdroppedduration[y] = 0;                
            }
        }
        if (AI[x].tempduration > 0)
        {
            if (AI[x].tempduration == AI[x].exchanges)
            {
                AI[x].power -= AI[x].temppower;
                logfile<<AI[x].name<<" has lost its temporary power bonus!\n";
                AI[x].tempduration = 0;
            }
        }
    }    
    if (flee[1] == true) 
    {
        if (playerdeaths/playernumber <= 0.5)
        {
            logfile<<"Player fleet has fled!\n";
            fled = true;
            victory = 2;
        }
    }
    if (flee[2] == true )
    {
        if (playercommandnumber <= 0)
        {
            logfile<<"Player fleet has fled!\n";
            fled = true;
            victory = 2;
        }
    }
    if (flee[3] == true)
    {
        int x = (rand()%10+1);
        if (x == 1)
        {
            logfile<<"Player fleet has fled!\n";
            fled = true;
            victory = 2;
        }
    }
    if (flee[4] == true)
    {
        if(Player[fleeselection].currenthp <= 0)
        {
            logfile<<"Player fleet has fled!\n";
            fled = true;
            victory = 2;
        }
    }
    if (flee[5] == true)
    {
        if (Player[fleeselection].currenthp <= fleehull)
        {
            logfile<<"Player fleet has fled!\n";
            fled = true;
            victory = 2;
        }
    }
    if (playerdeaths == playernumber)
    {
        victory = 2;
        if (playercommandnumber > 0)
        {
            bool done = false;
            while (!done)
            {
                int a = (rand()%playercommandnumber+1);
                if (PlayerCommand[a].currenthp >= -1)
                {
                    logfile<<"[b]Due to defeat, "<<PlayerCommand[a].name<<" has taken 1 damage![/b]\n";
                    PlayerCommand[a].currenthp -= 1;
                    if (PlayerCommand[a].currenthp <= -1)
                    {
                        logfile<<"[color=blue][b]"<<PlayerCommand[a].name<<" has been destroyed![/b][/color]\n";
                    }
                    done = true;
                }
            }
        }
    }
    if (aideaths == ainumber)
    {
        victory = 1;
        if (aicommandnumber > 0)
        {
            bool done = false;
            while (!done)
            {
                int a = (rand()%aicommandnumber+1);
                if (AICommand[a].currenthp >= -1)
                {
                    logfile<<"[b]Due to defeat, "<<AICommand[a].name<<" has taken 1 damage![/b]\n";
                    AICommand[a].currenthp -= 1;
                    if (AICommand[a].currenthp <= -1)
                    {
                        logfile<<"[b][color=red]"<<AICommand[a].name<<" has been destroyed![/color][/b]\n";
                    }
                    done = true;
                }
            }
        }
    }
    logfile.close();
}

void CombatRoundM()
{
    ofstream logfile(filename.c_str(),ios::app);
    int a,b,c,d,e,f,playerroll,airoll;
    playerroll = (rand()%12+1)-6;
    airoll = (rand()%12+1)-6;
    a = (rand()%playernumber+1);
    if (playernumber == 1) {a=1;}
    b = (rand()%ainumber+1);
    if (ainumber == 1) {b=1;}
    if (playercommandnumber == 0) {c=0;}
    else if (playercommandnumber == 1) {c=1;}
    else {c = (rand()%playercommandnumber+1);}
    if (aicommandnumber == 0) {d=0;}
    else if (aicommandnumber == 1) {d=1;}
    else {d = (rand()%aicommandnumber+1);}
    while (Player[a].currenthp <= 0)
    {
        a = (rand()%playernumber+1);
    }
    while (AI[b].currenthp <= 0)
    {
        b = (rand()%ainumber+1);
    }
    if (playercommandnumber > 0)
    {
        e = (rand()%10+1);
    }
    if (aicommandnumber > 0)
    {
        f = (rand()%10+1);
    }
    if ((e == 10) && (f == 10))
    {
        PlayerCommand[c].exchanges+=1;
        AICommand[d].exchanges+=1;
        if (playerroll+PlayerCommand[c].power+PlayerCommand[c].rating > airoll+AICommand[d].power+AICommand[d].rating)
        {
            logfile<<"[color=green][b]"<<PlayerCommand[c].name<<" rolled "<<playerroll<<" + "<<PlayerCommand[c].power+PlayerCommand[c].rating<<" [+"<<PlayerCommand[c].rating<<" Sup] vs "<<AICommand[d].name<<"'s "<<airoll<<" + "<<AICommand[d].power+AICommand[d].rating<<" [+"<<AICommand[d].rating<<" Sup], dealing 1 damage.[/b][/color]\n";
            AICommand[d].currenthp-=1;
            if (AICommand[d].currenthp <= -1)
            {
                aicommandnumber-=1;
                logfile<<"[color=blue][b]"<<AICommand[d].name<<" was destroyed! The AI fleet is thrown into disarray![/color][/b]\n";
                int done = 0;
                int num = 1;
                PlayerCommand[c].xp += 2;
                AICommand[d].xp = 0;
                while (done < AICommand[d].rating)
                {
                    if (AI[num].commandedby == d)
                    {
                        AI[num].commanded = 0;
                        AI[num].commandedby = 0;
                        done+=1;
                    }
                    num+=1;
                }
            }
        }
        else if (playerroll+PlayerCommand[c].power+PlayerCommand[c].rating < airoll+AICommand[d].power+AICommand[d].rating)
        {
            logfile<<"[color=red][b]"<<AICommand[d].name<<" rolled "<<airoll<<" + "<<AICommand[d].power+AICommand[d].rating<<" [+"<<AICommand[d].rating<<" Sup] vs "<<PlayerCommand[c].name<<"'s "<<playerroll<<" + "<<PlayerCommand[c].power+PlayerCommand[c].rating<<" [+"<<PlayerCommand[c].rating<<" Sup], dealing 1 damage.[/b][/color]\n";
            PlayerCommand[c].currenthp-=1;
            if (PlayerCommand[c].currenthp <= -1)
            {
                playercommandnumber-=1;
                logfile<<"[color=blue][b]"<<PlayerCommand[c].name<<" was destroyed! The Player fleet is thrown into disarray![/color][/b]\n";
                int done = 0;
                int num = 1;
                AICommand[d].xp += 2;
                PlayerCommand[c].xp = 0;
                while (done < PlayerCommand[c].rating)
                {
                    if (Player[num].commandedby == c)
                    {
                        Player[num].commanded = 0;
                        Player[num].commandedby = 0;
                        done +=1;
                    }
                    num+=1;
                }
            }
        }
        else if (playerroll+PlayerCommand[c].power+PlayerCommand[c].rating == airoll+AICommand[d].power+AICommand[d].rating)
        {
            logfile<<"[b]"<<PlayerCommand[c].name<<" and "<<AICommand[d].name<<" fought but nobody gained an advantage![/b]\n";   
        }
    }
    else if (e == 10)
    {
        PlayerCommand[c].exchanges+=1;
        AI[b].exchanges+=1;
        int playercommanddamage = ((playerroll+PlayerCommand[c].power+PlayerCommand[c].rating) - (airoll+AI[b].power+AI[b].shieldmit+AI[b].commanded));
        int playercommandshielddamage = ((playerroll+PlayerCommand[c].power+PlayerCommand[c].rating) - (airoll+AI[b].power+AI[b].commanded));
        if (playercommanddamage < 0) {playercommanddamage = 0;}
        if (playercommandshielddamage < 0) {playercommandshielddamage = 0;}        
        logfile<<"[b][color=green]"<<PlayerCommand[c].name<<" rolled "<<playerroll<<" + "<<PlayerCommand[c].power+PlayerCommand[c].rating<<" [+"<<PlayerCommand[c].rating<<" Sup] vs "<<AI[b].name<<"'s "<<airoll<<" + "<<AI[b].power+AI[b].commanded<<" [+"<<AI[b].commanded<<" Sup], dealing "<<playercommanddamage<<" damage [-"<<AI[b].shieldmit<<" Shield Mit][/b][/color].\n";
        AI[b].currenthp -= playercommanddamage;
        AI[b].shieldstr -= AI[b].shieldmit;
        if ((AI[b].shieldstr <= 0) && (AI[b].shieldmit > 0))
        {
            logfile<<"[color=red]"<<AI[b].name<<"'s shields have collapsed![/color]\n";
            AI[b].shieldmit = 0;
        }
        if (AI[b].currenthp <= 0)
        {
            logfile<<"[color=blue]"<<AI[b].name<<" was destroyed![/color]\n";
            PlayerCommand[c].xp+=2;
            aideaths +=1;
        }
    }
    else if (f == 10)
    {
        AICommand[d].exchanges+=1;
        Player[a].exchanges+=1;
        int aicommanddamage = ((airoll+AICommand[d].power+AICommand[d].rating) - (playerroll+Player[a].power+Player[a].shieldmit+Player[a].commanded));
        int aicommandshielddamage = ((airoll+AICommand[d].power+AICommand[d].rating) - (playerroll+Player[a].power+Player[a].commanded));
        if (aicommanddamage < 0) {aicommanddamage = 0;}
        if (aicommandshielddamage < 0) {aicommandshielddamage = 0;}
        logfile<<"[b][color=red]"<<AICommand[d].name<<" rolled "<<airoll<<" + "<<AICommand[d].power+AICommand[d].rating<<" [+"<<AICommand[d].rating<<" Sup] vs "<<Player[a].name<<"'s "<<playerroll<<" + "<<Player[a].power+Player[a].commanded<<" [+"<<Player[a].commanded<<" Sup], dealing "<<aicommanddamage<<" damage [-"<<Player[a].shieldmit<<" Shield Mit][/b][/color]\n";
        Player[a].currenthp -= aicommanddamage;
        Player[a].shieldstr -= Player[a].shieldmit;
        if ((Player[a].shieldstr <= 0) && (Player[a].shieldmit > 0))
        {
            logfile<<"[color=green]"<<Player[a].name<<"'s shields have collapsed![/color]\n";
            Player[a].shieldmit = 0;
        }
        if (Player[a].currenthp <= 0)
        {
            logfile<<"[color=blue]"<<Player[a].name<<" was destroyed![/color]\n";
            AICommand[d].xp+=2;
            playerdeaths+=1;
        }
    }
    else
    {
        Player[a].exchanges+=1;
        AI[b].exchanges+=1;        
        int damage;
        int shielddamage;
        if ((playerroll+Player[a].power+Player[a].commanded) > (airoll+AI[b].power+AI[b].commanded))
        {
            shielddamage = ((playerroll+Player[a].power+Player[a].commanded) - (airoll+AI[b].power+AI[b].commanded));
            damage = ((playerroll+Player[a].power+Player[a].commanded) - (airoll+AI[b].power+AI[b].commanded+AI[b].shieldmit));
            if (damage < 0) {damage = 0;}
            if (shielddamage <0) {shielddamage = 0;}
            logfile<<"[color=green]"<<Player[a].name<<" rolled "<<playerroll<<" + "<<Player[a].power+Player[a].commanded<<" [+"<<Player[a].commanded<<" Sup] vs "<<AI[b].name<<"'s "<<airoll<<" + "<<AI[b].power+AI[b].commanded<<" [+"<<AI[b].commanded<<" Sup], dealing "<<damage<<" damage [-"<<AI[b].shieldmit<<" Shield Mit][/color]!\n";
            AI[b].currenthp -= damage;
            if (Player[a].shieldstrpower > 0)
            {
                AI[b].shieldstrdroppednum+=1;
                int num = AI[b].shieldstrdroppednum;
                AI[b].shieldstrdropped[num] = Player[a].shieldstrpower;
                AI[b].shieldstrdroppedduration[num] = Player[a].shieldstrduration+AI[b].exchanges;
                AI[b].shieldstr -= Player[a].shieldstrpower;
                logfile<<AI[b].name<<"'s shield strength has been dropped by "<<Player[a].shieldstrpower<<" for "<<Player[a].shieldstrduration<<" exchanges!\n";
            }   
            if (Player[a].shieldmitpower > 0)
            {
                AI[b].shieldmitdroppednum+=1;
                int num = AI[b].shieldmitdroppednum;
                AI[b].shieldmitdropped[num] = Player[a].shieldmitpower;
                AI[b].shieldmitdroppedduration[num] = Player[a].shieldmitduration+AI[b].exchanges;
                AI[b].shieldmit -= Player[a].shieldmitpower;
                logfile<<AI[b].name<<"'s shield mitigation has been dropped by "<<Player[a].shieldmitpower<<" for "<<Player[a].shieldmitduration<<" exchanges!\n";
            }                          
            AI[b].shieldstr -= AI[b].shieldmit;
            if ((AI[b].shieldstr <= 0) && (AI[b].shieldmit > 0))
            {
                logfile<<"[color=red]"<<AI[b].name<<"'s shields have collapsed![/color]\n";
                AI[b].shieldmit = 0;
            }
            if (AI[b].currenthp <= 0)
            {
                logfile<<"[color=blue]"<<AI[b].name<<" was destroyed![/color]\n";
                aideaths +=1;
                PlayerCommand[Player[a].commandedby].xp+=1;
            }
        }
        else if ((playerroll+Player[a].power+Player[a].commanded) < (airoll+AI[b].power+AI[b].commanded))
        {
            shielddamage = ((airoll+AI[b].power+AI[b].commanded) - (playerroll+Player[a].power+Player[a].commanded));
            damage = ((airoll+AI[b].power+AI[b].commanded) - (playerroll+Player[a].power+Player[a].commanded+Player[a].shieldmit));
            if (damage < 0) {damage = 0;}
            if (shielddamage <0) {shielddamage = 0;}            
            logfile<<"[color=red]"<<AI[b].name<<" rolled "<<airoll<<" + "<<AI[b].power+AI[b].commanded<<" [+"<<AI[b].commanded<<" Sup] vs "<<Player[a].name<<"'s "<<playerroll<<" + "<<Player[a].power+Player[a].commanded<<" [+"<<Player[a].commanded<<" Sup], dealing "<<damage<<" damage! [-"<<Player[a].shieldmit<<" Shield Mit][/color]\n";
            Player[a].currenthp -= damage;
            if (AI[b].shieldmitpower > 0)
            {
                Player[a].shieldmitdroppednum+=1;
                int num = Player[a].shieldmitdroppednum;
                Player[a].shieldmitdropped[num] = AI[b].shieldmitpower;
                Player[a].shieldmitdroppedduration[num] = AI[b].shieldmitduration+Player[a].exchanges;
                Player[a].shieldmit -= AI[b].shieldmitpower;
                logfile<<Player[a].name<<"'s shield mitigation has been dropped by "<<AI[b].shieldmitpower<<" for "<<AI[b].shieldmitduration<<" exchanges!\n";
            }
            if (AI[b].shieldstrpower > 0)
            {
                Player[a].shieldstrdroppednum+=1;
                int num = Player[a].shieldstrdroppednum;
                Player[a].shieldstrdropped[num] = AI[b].shieldstrpower;
                Player[a].shieldstrdroppedduration[num] = AI[b].shieldstrduration+Player[a].exchanges;
                Player[a].shieldstr -= AI[b].shieldstrpower;
                logfile<<Player[a].name<<"'s shield strength has been dropped by "<<AI[b].shieldstrpower<<" for "<<AI[b].shieldstrduration<<" exchanges!\n";
            }            
            Player[a].shieldstr -= Player[a].shieldmit;
            if ((Player[a].shieldstr <= 0) && (Player[a].shieldmit > 0))
            {
                logfile<<"[color=green]"<<Player[a].name<<"'s shields have collapsed![/color]\n";
                Player[a].shieldmit = 0;
            }
            if (Player[a].currenthp <= 0)
            {
                logfile<<"[color=blue]"<<Player[a].name<<" was destroyed![/color]\n";
                playerdeaths +=1;
                AICommand[AI[b].commandedby].xp+=1;
            }
        }
        else
        {
            logfile<<Player[a].name<<" and "<<AI[b].name<<" fought but nobody gained an advantage!\n";
        }
    }
    logfile.close();
}
