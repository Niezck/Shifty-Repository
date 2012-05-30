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

void CheckStatus()
{
    ofstream logfile(filename.c_str(),ios::app);
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
                    logfile<<"[b]Due to defeat, Player Command Ship "<<a<<" has taken 1 damage![/b]\n";
                    PlayerCommand[a].currenthp -= 1;
                    if (PlayerCommand[a].currenthp <= -1)
                    {
                        logfile<<"[color=blue][b]Player Command Ship "<<a<<" has been destroyed![/b][/color]\n";
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
                    logfile<<"[b]Due to defeat, AI Command Ship "<<a<<" has taken 1 damage![/b]\n";
                    AICommand[a].currenthp -= 1;
                    if (AICommand[a].currenthp <= -1)
                    {
                        logfile<<"[b][color=red]AI Command Ship "<<a<<" has been destroyed![/color][/b]\n";
                    }
                    done = true;
                }
            }
        }
    }
    logfile.close();
}

void CombatRound()
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
        if (playerroll+PlayerCommand[c].power+PlayerCommand[c].rating > airoll+AICommand[d].power+AICommand[d].rating)
        {
            logfile<<"[color=green][b]Player Command Ship "<<c<<" rolled "<<playerroll<<" + "<<PlayerCommand[c].power+PlayerCommand[c].rating<<" [+"<<PlayerCommand[c].rating<<" Sup] vs AI Command Ship "<<d<<"'s "<<airoll<<" + "<<AICommand[d].power+AICommand[d].rating<<" [+"<<AICommand[d].rating<<" Sup], dealing 1 damage.[/b][/color]\n";
            AICommand[d].currenthp-=1;
            if (AICommand[d].currenthp <= -1)
            {
                aicommandnumber-=1;
                logfile<<"[color=blue][b]AI Command Ship "<<d<<" was destroyed! The AI fleet is thrown into disarray![/color][/b]\n";
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
            logfile<<"[color=red][b]AI Command Ship "<<d<<" rolled "<<airoll<<" + "<<AICommand[d].power+AICommand[d].rating<<" [+"<<AICommand[d].rating<<" Sup] vs Player Command Ship "<<c<<"'s "<<playerroll<<" + "<<PlayerCommand[c].power+PlayerCommand[c].rating<<" [+"<<PlayerCommand[c].rating<<" Sup], dealing 1 damage.[/b][/color]\n";
            PlayerCommand[c].currenthp-=1;
            if (PlayerCommand[c].currenthp <= -1)
            {
                playercommandnumber-=1;
                logfile<<"[color=blue][b]Player Command Ship "<<c<<" was destroyed! The Player fleet is thrown into disarray![/color][/b]\n";
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
            logfile<<"Player Command Ship "<<c<<" and AI Command Ship "<<d<<" fought but nobody gained an advantage!\n";   
        }
    }
    else if (e == 10)
    {
        int playercommanddamage = ((playerroll+PlayerCommand[c].power+PlayerCommand[c].rating) - (airoll+AI[b].power+AI[b].shieldmit+AI[b].commanded));
        int playercommandshielddamage = ((playerroll+PlayerCommand[c].power+PlayerCommand[c].rating) - (airoll+AI[b].power+AI[b].commanded));
        if (playercommanddamage < 0) {playercommanddamage = 0;}
        if (playercommandshielddamage < 0) {playercommandshielddamage = 0;}        
        logfile<<"[b][color=green]Player Command Ship "<<c<<" rolled "<<playerroll<<" + "<<PlayerCommand[c].power+PlayerCommand[c].rating<<" [+"<<PlayerCommand[c].rating<<" Sup] vs AI Ship "<<b<<"'s "<<airoll<<" + "<<AI[b].power+AI[b].commanded<<" [+"<<AI[b].commanded<<" Sup], dealing "<<playercommanddamage<<" damage [-"<<AI[b].shieldmit<<" Shield Mit][/b][/color].\n";
        AI[b].currenthp -= playercommanddamage;
        if (playercommandshielddamage < AI[b].shieldmit)
        {
            AI[b].shieldstr -= playercommandshielddamage;
        }
        else
        {
            AI[b].shieldstr -= AI[b].shieldmit;
        }
        if ((AI[b].shieldstr <= 0) && (AI[b].shieldmit > 0))
        {
            logfile<<"[color=red]AI Ship "<<b<<"'s shields have collapsed![/color]\n";
            AI[b].shieldmit = 0;
        }
        if (AI[b].currenthp <= 0)
        {
            logfile<<"[color=blue]AI Ship "<<b<<" was destroyed![/color]\n";
            PlayerCommand[c].xp+=2;
            aideaths +=1;
        }
    }
    else if (f == 10)
    {
        int aicommanddamage = ((airoll+AICommand[d].power+AICommand[d].rating) - (playerroll+Player[a].power+Player[a].shieldmit+Player[a].commanded));
        int aicommandshielddamage = ((airoll+AICommand[d].power+AICommand[d].rating) - (playerroll+Player[a].power+Player[a].commanded));
        if (aicommanddamage < 0) {aicommanddamage = 0;}
        if (aicommandshielddamage < 0) {aicommandshielddamage = 0;}
        logfile<<"[b][color=red]AI Command Ship "<<d<<" rolled "<<airoll<<" + "<<AICommand[d].power+AICommand[d].rating<<" [+"<<AICommand[d].rating<<" Sup] vs Player Ship "<<a<<"'s "<<playerroll<<" + "<<Player[a].power+Player[a].commanded<<" [+"<<Player[a].commanded<<" Sup], dealing "<<aicommanddamage<<" damage [-"<<Player[a].shieldmit<<" Shield Mit][/b][/color]\n";
        Player[a].currenthp -= aicommanddamage;
        if (aicommandshielddamage < Player[a].shieldmit)
        {
            Player[a].shieldstr -= aicommandshielddamage;
        }
        else
        {
            Player[a].shieldstr -= Player[a].shieldmit;
        }
        if ((Player[a].shieldstr <= 0) && (Player[a].shieldmit > 0))
        {
            logfile<<"[color=green]Player Ship "<<a<<"'s shields have collapsed![/color]\n";
            Player[a].shieldmit = 0;
        }
        if (Player[a].currenthp <= 0)
        {
            logfile<<"[color=blue]Player Ship "<<a<<" was destroyed![/color]\n";
            AICommand[d].xp+=2;
            playerdeaths+=1;
        }
    }
    else
    {
        int damage;
        int shielddamage;
        if ((playerroll+Player[a].power+Player[a].commanded) > (airoll+AI[b].power+AI[b].commanded))
        {
            shielddamage = ((playerroll+Player[a].power+Player[a].commanded) - (airoll+AI[b].power+AI[b].commanded));
            damage = ((playerroll+Player[a].power+Player[a].commanded) - (airoll+AI[b].power+AI[b].commanded+AI[b].shieldmit));
            if (damage < 0) {damage = 0;}
            if (shielddamage <0) {shielddamage = 0;}
            logfile<<"[color=green]Player Ship "<<a<<" rolled "<<playerroll<<" + "<<Player[a].power+Player[a].commanded<<" [+"<<Player[a].commanded<<" Sup] vs AI Ship "<<b<<"'s "<<airoll<<" + "<<AI[b].power+AI[b].commanded<<" [+"<<AI[b].commanded<<" Sup], dealing "<<damage<<" damage [-"<<AI[b].shieldmit<<" Shield Mit][/color]!\n";
            AI[b].currenthp -= damage;
            if (shielddamage < AI[b].shieldmit)
            {
                AI[b].shieldstr -= shielddamage;
            }
            else
            {
                AI[b].shieldstr -= AI[b].shieldmit;
            }
            if ((AI[b].shieldstr <= 0) && (AI[b].shieldmit > 0))
            {
                logfile<<"[color=red]AI Ship "<<b<<"'s shields have collapsed![/color]\n";
                AI[b].shieldmit = 0;
            }
            if (AI[b].currenthp <= 0)
            {
                logfile<<"[color=blue]AI Ship "<<b<<" was destroyed![/color]\n";
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
            logfile<<"[color=red]AI Ship "<<b<<" rolled "<<airoll<<" + "<<AI[b].power+AI[b].commanded<<" [+"<<AI[b].commanded<<" Sup] vs Player Ship "<<a<<"'s "<<playerroll<<" + "<<Player[a].power+Player[a].commanded<<" [+"<<Player[a].commanded<<" Sup], dealing "<<damage<<" damage! [-"<<Player[a].shieldmit<<" Shield Mit][/color]\n";
            Player[a].currenthp -= damage;
            if (shielddamage < Player[a].shieldmit)
            {
                Player[a].shieldstr -= shielddamage;
            }
            else
            {
                Player[a].shieldstr -= Player[a].shieldmit;
            }
            if ((Player[a].shieldstr <= 0) && (Player[a].shieldmit > 0))
            {
                logfile<<"[color=green]Player Ship "<<a<<"'s shields have collapsed![/color]\n";
                Player[a].shieldmit = 0;
            }
            if (Player[a].currenthp <= 0)
            {
                logfile<<"[color=blue]Player Ship "<<a<<" was destroyed![/color]\n";
                playerdeaths +=1;
                AICommand[AI[b].commandedby].xp+=1;
            }
        }
        else
        {
            logfile<<"Player ship "<<a<<" and AI ship "<<b<<" fought but nobody gained an advantage!\n";
        }
    }
    logfile.close();
}
