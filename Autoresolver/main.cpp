#include <cstdlib>
#include <iostream>
#include <string.h>
#include <sstream>
#include <ctype.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

bool flee[9];
bool fled = false;
bool quit = false;
void commandprompt();
void interpreter(string command);
void simple();
void complex();
int playernumber;
int enemynumber;
int temphp1, temphp2, tempval1, tempval2, temppower1, temppower2, tempsupport1, tempsupport2, tempmit1, tempmit2, tempgen1, tempgen2;
int exp = 0;
int pxp = 0;
fstream logfile;
string filename;
string StringToUpper(string strToConvert);
string StringToLower(string strToConvert); 

void interpreter(string command)
{
     if (StringToUpper(command) == "SIMPLE") { simple(); }
     else if (StringToUpper(command) == "COMPLEX") { complex(); }
     else if (StringToUpper(command) == "EXIT") { quit = true; }
     else { cout<<"Incorrect input.\n"; }
}
     

void commandprompt()
{
    string command;
    cout<<"Enter type of fight:"<<endl;
    cin>>command;
    interpreter(command);     
}

void complex()
{
     srand((unsigned)time(0));
     bool pbonus = false;
     bool ebonus = false;
     int fleehull;
     int fleeselection;     
     int pbonusval = 0;
     int ebonusval = 0;     
     int a,b,c,d,e,f,g,h;
     int pgeneralcount=0;
     int egeneralcount=0;
     int psupport[3];
     int esupport[3];
     int pgeneralpower[3];
     int egeneralpower[3];
     int pgeneralxp[3];
     int egeneralxp[3];
     int pgeneralhp[3];
     int egeneralhp[3];
     cout<<"Enter filename:\n";
     cin>>filename; 
     string options;
     bool done = false;
          cout<<"Enter number of player forces.\n";
          cin>>playernumber;
          cout<<"Enter number of AI forces.\n";
          cin>>enemynumber;
          int originalenemy = enemynumber;
          int originalplayer = playernumber;
          int playerpower[playernumber];
          int enemypower[enemynumber];
          int playerhp[playernumber];
          int enemyhp[enemynumber];
          int pactualhp[playernumber];
          int eactualhp[enemynumber];
          int playerval[playernumber];
          int enemyval[enemynumber];
          int punitsupport[playernumber];
          int eunitsupport[enemynumber];
          int psupported = 0;
          int esupported = 0;
          int pounitsupport[playernumber];
          int eounitsupport[enemynumber];          
          int punitgeneral[playernumber];
          int eunitgeneral[enemynumber];
          int pounitgeneral[playernumber];
          int eounitgeneral[enemynumber];
          int originalplayerhp[playernumber];
          int originalenemyhp[enemynumber];  
          int playermit[playernumber];
          int oplayermit[playernumber];
          int enemymit[enemynumber];
          int oenemymit[enemynumber];
          int playershield[playernumber];
          int enemyshield[enemynumber];
          bool playerdead[playernumber];
          bool enemydead[enemynumber];
          fled = false; 
          for (int x=0;x<10;x++) {
              flee[x] = false; } 
          for (int x=1;x<=playernumber;x++) {
              cout<<"Enter power of Player ship "<<x<<" : ";
              cin>>playerpower[x];
              playerval[x] = x; }
          for (int x=1;x<=enemynumber;x++) {
              cout<<"Enter power of AI ship "<<x<<" : ";
              cin>>enemypower[x];
              enemyval[x] = x; }
          for (int x=1;x<=playernumber;x++) {
              cout<<"Enter shield mitigation of Player ship "<<x<<" : ";
              cin>>playermit[x];
              oplayermit[x] = playermit[x]; }
          for (int x=1;x<=enemynumber;x++) {
              cout<<"Enter shield mitigation of AI ship "<<x<<" : ";
              cin>>enemymit[x];
              oenemymit[x] = enemymit[x]; } 
          for (int x=1;x<=playernumber;x++) {
              cout<<"Enter shield strength of Player ship "<<x<<" : ";
              cin>>playershield[x]; }
          for (int x=1;x<=enemynumber;x++) {
              cout<<"Enter shield strength of AI ship "<<x<<" : ";
              cin>>enemyshield[x]; }                          
          for (int x=1;x<=playernumber;x++) {
              cout<<"Enter HP of Player ship "<<x<<" : ";
              cin>>playerhp[x];
              pactualhp[x] = playerhp[x];
              originalplayerhp[x] = playerhp[x]; }
          for (int x=1;x<=enemynumber;x++) {
          cout<<"Enter HP of AI ship "<<x<<" : ";
          cin>>enemyhp[x];
          eactualhp[x] = enemyhp[x];
          originalenemyhp[x] = enemyhp[x]; }      
     while (done == false) {
     cout<<"Enter Options:\n";
     cin>>options;
     if (StringToUpper(options) == "FLEE") {
        cout<<"Enter flee options:\n1. 50% casualties\n2. All command ships dead\n3. 10% chance each round\n4. Death of a specific ship\n5. Ship is reduced below X hull\n";
        int fleechoice;
        cin>>fleechoice;
        flee[fleechoice] = true;
        if ((flee[4] == true) || (flee[5] == true)) {
                   cout<<"Which ship?\n";
                   cin>>fleeselection; }
        if (flee[5] == true) {
                    cout<<"What value of hull?\n";
                    cin>>fleehull; }
     }
     if (StringToUpper(options) == "BONUS") {
          cout<<"Player or AI?\n";
          string choice;
          cin>>choice;
          if (StringToUpper(choice) == "PLAYER") {
                                    pbonus = true;
                                    cout<<"Enter value:\n";
                                    cin>>pbonusval; }
          else if (StringToUpper(choice) == "AI") {
                                    ebonus = true;
                                    cout<<"Enter value:\n";
                                    cin>>ebonusval; } }
     else if (StringToUpper(options) == "GENERAL") {
          cout<<"Player or AI?\n";
          string choice;
          cin>>choice;
          if (StringToUpper(choice) == "PLAYER") {
          if (pgeneralcount <3) {
          pgeneralcount+=1;
          pgeneralxp[pgeneralcount]=0;          
          cout<<"General Number "<<pgeneralcount<<endl;
          cout<<"Enter Support Rating:\n";
          cin>>psupport[pgeneralcount];
          if (psupport[pgeneralcount] >= 12) {psupport[pgeneralcount] = 12; }          
          cout<<"Enter Power:\n";
          cin>>pgeneralpower[pgeneralcount];
          cout<<"Enter HP: [0 or 1]\n";
          cin>>pgeneralhp[pgeneralcount];
          if (pgeneralhp[pgeneralcount] >=1) {pgeneralhp[pgeneralcount] = 1; }
          if (pgeneralpower[pgeneralcount] >= 12) {pgeneralpower[pgeneralcount] = 12; }}        
          else if (pgeneralcount >= 3) {cout<<"Too many command ships already\n"; } }
          else if (StringToUpper(choice) == "AI") {
          if (egeneralcount <3) {
          egeneralcount+=1;
          cout<<egeneralcount<<endl;
          egeneralxp[egeneralcount]=0;
          cout<<"General Number "<<egeneralcount<<endl;
          cout<<"Enter Support Rating:\n";
          cin>>esupport[egeneralcount];                    
          if (esupport[egeneralcount] >= 12) {esupport[egeneralcount] = 12; }          
          cout<<"Enter Power:\n";
          cin>>egeneralpower[egeneralcount];
          cout<<"Enter HP: [0 or 1]\n";
          cin>>egeneralhp[egeneralcount];
          if (egeneralhp[egeneralcount] >=1) {egeneralhp[egeneralcount] = 1; }          
          if (egeneralpower[egeneralcount] >= 12) {egeneralpower[egeneralcount] = 12; }}
          else if (egeneralcount >= 3) {cout<<"Too many general already\n"; } } }
     else if (StringToUpper(options) == "DONE") {
          cout<<"Confirm Ship information: \n";
          if (pgeneralcount > 0) { for (int x=1;x<=pgeneralcount;x++) { cout<<"Player Command Ship "<<x<<": Command "<<psupport[x]<<"Pwr"<<pgeneralpower[x]<<endl; } }
          for (int x=1;x<=playernumber;x++) {
              cout<<"Player Ship "<<x<<": HP"<<pactualhp[playerval[x]]<<" Pwr"<<playerpower[x]<<" Mit"<<playermit[x]<<" SStr"<<playershield[x]<<"\n"; }    
          if (egeneralcount > 0) { for (int x=1;x<=egeneralcount;x++) { cout<<"AI Command Ship "<<x<<": Command "<<esupport[x]<<"Pwr"<<egeneralpower[x]<<endl; } }
          for (int x=1;x<=enemynumber;x++) {
              cout<<"AI Ship "<<x<<": HP"<<enemyhp[x]<<" Pwr"<<enemypower[x]<<" Mit"<<enemymit[x]<<" SStr"<<enemyshield[x]<<"\n"; }         
          cout<<"Confirm?\n";
          string confirm;
          cin>>confirm;
          if (StringToUpper(confirm) == "YES") { }
           else if (StringToUpper(confirm) == "NO") { complex(); }
           else {cout<<"Incorrect Syntax\n"; complex(); }           
           done = true; } }
          cout<<"DEBUG 0\n";           
     bool write = false;
     string YN;     
     filename.append(".txt");
     ifstream check(filename.c_str(),ios::in);
     if (check.is_open() ) {
                         cout<<"That file already exists, overwrite? [Y/N]\n";
                         cin>>YN;
                         YN = StringToUpper(YN);
                         if (YN == "Y") { write = true; }
                         else if (YN == "N") { }
                         else { complex(); } }
     else { write = true; } 
     if (write == true) {
               if (pbonus == true) {
                          for (int x=1;x<=playernumber;x++) {playerpower[x]+=pbonusval;}
                          for (int x=1;x<=pgeneralcount;x++) {pgeneralpower[x]+=pbonusval;} }
               if (ebonus == true) {
                          for (int x=1;x<=enemynumber;x++) {enemypower[x]+=ebonusval;}
                          for (int x=1;x<=egeneralcount;x++) {egeneralpower[x]+=ebonusval;} }
               cout<<"DEBUG 1\n";
     ofstream logfile(filename.c_str(),ios::trunc);               
               logfile<<"*****Battle report: "<<filename<<"*****\n\n";
               logfile<<"[Starting Stats]:\n\n";
               if (pbonus == true) {logfile<<"[b]Player fleet receives a power bonus of "<<pbonusval<<"[/b]\n"<<endl; }
               if (flee[1] == true) {logfile<<"[b]Player fleet will flee if 50% casualties are taken.[/b]\n"; }
               if (flee[2] == true) {logfile<<"[b]Player fleet will flee if all command ships are destroyed.[/b]\n"; }
               if (flee[3] == true) {logfile<<"[b]Player fleet will have a 10% chance to flee each combat around.[/b]\n"; }
               if (flee[4] == true) {logfile<<"[b]Player fleet will flee if ship "<<fleeselection<<" is destroyed.[/b]\n"; }
               if (flee[5] == true) {logfile<<"[b]Player fleet will flee if ship "<<fleeselection<<" is reduced to "<<fleehull<<" points of hull or less.[/b]\n"; }
               if (pgeneralcount > 0) { for (int x=1;x<=pgeneralcount;x++) {logfile<<"[color=green]Player Command Ship "<<x<<" Command "<<psupport[x]<<", Power "<<pgeneralpower[x]<<", HP "<<pgeneralhp[x]<<"[/color]\n"; } }
               for (int x=1;x<=playernumber;x++) {
                   logfile<<"[color=green]Player ship "<<x<<": HP ["<<playerhp[x]<<"] Power ["<<playerpower[x]<<"] Shield Mitigation ["<<playermit[x]<<"] Shield Strength ["<<playershield[x]<<"][/color]\n"; }
               logfile<<endl;
               if (ebonus == true) {logfile<<"[b]AI fleet receives a power bonus of "<<ebonusval<<"[/b]\n"<<endl; }               
               if (egeneralcount > 0) { for (int x=1;x<=egeneralcount;x++) { logfile<<"[color=red]AI Command Ship "<<x<<" Command "<<esupport[x]<<", Power "<<egeneralpower[x]<<", HP "<<egeneralhp[x]<<"[/color]\n"; } }
               for (int x=1;x<=enemynumber;x++) {
                   logfile<<"[color=red]AI ship "<<x<<": HP ["<<enemyhp[x]<<"] Power ["<<enemypower[x]<<"] Shield Mitigation ["<<enemymit[x]<<"] Shield Strength ["<<enemyshield[x]<<"][/color]\n"; }
               logfile<<"\n[Combat Details]\n\n";
               for (int x=1;x<=playernumber;x++) {punitsupport[x]=0; pounitsupport[x]=0; }
               for (int x=1;x<=enemynumber;x++) {eunitsupport[x]=0; eounitsupport[x]=0; }               
               cout<<"DEBUG 2\n";
               if (pgeneralcount > 0) {
                                 cout<<"DEBUG 3\n";
               for (int y=1;y<=pgeneralcount;y++) {
                  int psupportbonus;
                  if (psupport[y]%2 == 0) {psupportbonus = (psupport[y]/2);}
                  else if (psupport[y]%2 > 0) {psupportbonus = ((psupport[y]+1)/2);}
                  if (psupport[y] >= playernumber) {
                               for (int x=1;x<=playernumber;x++) {
                                   punitsupport[x] = psupportbonus;
                                   pounitsupport[x] = psupportbonus;
                                   punitgeneral[x] = y;
                                   pounitgeneral[x] = y;
                                   psupported+=1; } }
                  else if (psupport[y] < playernumber) {
                          int pcounter = 0;
                          while (pcounter<psupport[y]+1) {
                              int e = (rand()%(playernumber+1));
                              cout<<"DEBUG1\n";
                              cout<<"Y="<<y<<" E="<<e<<" supporte="<<punitsupport[e]<<" ysupport="<<psupport[y]<<" counter="<<pcounter<<endl;
                              if (pcounter == psupport[y]) {break;}
                              if (psupported == playernumber) {break;}                              
                              if (punitsupport[e] == 0) { psupported+=1; pcounter+=1; pounitgeneral[e] = y; punitgeneral[e] = y; punitsupport[e]=psupportbonus; pounitsupport[e]=psupportbonus; cout<<"PUnit "<<e<<endl; }
                             } } } } 
               if (egeneralcount > 0) {
                                 cout<<"DEBUG 4\n";
               for (int y=1;y<=egeneralcount;y++) {
                  int esupportbonus;
                  if (esupport[y]%2 == 0) {esupportbonus = (esupport[y]/2);}
                  else if (esupport[y]%2 > 0) {esupportbonus = ((esupport[y]+1)/2);}                                 
                  if (esupport[y] >= enemynumber) {
                               for (int x=1;x<=enemynumber;x++) {
                                   eunitsupport[x] = esupportbonus;
                                   eounitsupport[x] = esupportbonus;
                                   eunitgeneral[x] = y;
                                   eounitgeneral[x] = y;
                                   esupported +=1; } }
                  else if (esupport[y] < enemynumber) {
                          int ecounter =0;
                          while (ecounter<esupport[y]+1) {
                              int e = (rand()%(enemynumber+1));
                              cout<<"DEBUG2\n";
                              if (ecounter == esupport[y]) {break;}
                              if (esupported == enemynumber) {break;}
                              if (eunitsupport[e] == 0) { esupported+=1; ecounter+=1; eounitgeneral[e] = y; eunitgeneral[e] = y; eunitsupport[e]=esupportbonus; eounitsupport[e]=esupportbonus; }
                               } } } }                          
                               cout<<"DEBUG 5\n";
               while ((playernumber > 0) && (enemynumber > 0)) {
                     cout<<"DEBUG 6\n";
               if (flee[1] == true) { 
                           if (playernumber/originalplayer <= 0.5) {
                                                           fled=true; } }
               if (flee[2] == true) {  }
               if (flee[3] == true) {  }
               if (flee[4] == true) { 
                           cout<<"DEBUGFLED\n";
                           if (pactualhp[fleeselection] <= 0) {
                                                          
                                                        cout<<"DEBUGFLED2\n";
                                                        cout<<pactualhp[fleeselection-1]<<endl;
                                                        cout<<fleeselection-1<<endl;
                                                        fled=true; } }
               if (flee[5] == true) {
                           if (pactualhp[fleeselection] <= fleehull) {
                                                          cout<<fleeselection<<" ship's hull is "<<pactualhp[fleeselection-1]<<" and is less than "<<fleehull<<endl;
                                                          cout<<"Flee due to hull\n";
                                                          fled = true;} }
               if (fled == true) {
                                                         cout<<"DEBUGFLEE2\n";
                                                         logfile<<"[b][color=orange]Player fleet has fled the battle![/color][/b]\n";
                                                         break; }                                                          
               a = 0;
               b = 0;
               c = 0;
               d = 0;
               b = (rand()%(playernumber));
               int orib = b;
               cout<<"DEBUG 12\n";
               if (b <= 1) { b=1; }
               if (b >= playernumber) {b=playernumber; }
               c = (rand()%(enemynumber));
               int oric = c;
               if (c <= 1) { c=1; }
               if (c >= enemynumber) {c=enemynumber; }
               a = (rand()%12+1)-6;
               if (a >=6) { a=6; }
               if (a <=-6) { a=-6; }
               d = (rand()%12+1)-6;
               if (d >=6) { d=6; }
               if (d <=-6) { d=-6; }
               cout<<"DEBUG 13\n";
               e = (rand()%10+1);
               g = (rand()%10+1);
               if ((pgeneralcount > 0) || (egeneralcount >0)) {
               cout<<"DEBUG 14\n";
               if (pgeneralcount > 0) { f = (rand()%pgeneralcount+1); }
               if (egeneralcount > 0) { h = (rand()%egeneralcount+1); }
               cout<<"DEBUG 16\n";
               if ((pgeneralcount>0) && (egeneralcount>0)) {
               if ((e==10) && (g==10) && (pgeneralhp[f] >=0) && (egeneralhp[h]>=0)) {
               if ((pgeneralpower[f]+psupport[f])>(egeneralpower[h]+esupport[h])) {
               logfile<<"[color=green][b]Player Command Ship "<<f<<" rolled "<<a<<" + "<<pgeneralpower[f]+psupport[f]<<" [+"<<psupport[f]<<" Sup] vs AI Command Ship "<<h<<"'s "<<d<<" + "<<egeneralpower[h]+esupport[h]<<" [+"<<esupport[h]<<" Sup], dealing 1 damage.[/b][/color]\n";
               egeneralhp[h]-=1;
               if (egeneralhp[h]==-1) {
                                      int done = esupport[h];
                                      int x = 1;
                                      pgeneralxp[f] +=2;
                                      egeneralxp[h] = 0;
                                      logfile<<"[color=blue][b]AI Command Ship "<<h<<" has been destroyed! The AI fleet is thrown into disarray![/b][/color]\n";
                                      while (done>0) {
                                            if (eunitgeneral[x] == h) {done-=1; eunitsupport[x] = 0; eunitgeneral[x]=0;}
                                            x+=1; } } }
               else if ((egeneralpower[h]+esupport[h])>(pgeneralpower[f]+psupport[f])) {
               logfile<<"[color=red][/b]AI Command Ship "<<h<<" rolled "<<d<<" + "<<egeneralpower[h]+esupport[h]<<" [+"<<esupport[h]<<" Sup] vs Player Command Ship "<<f<<"'s "<<a<<" + "<<pgeneralpower[f]+psupport[f]<<" [+"<<psupport[f]<<" Sup], dealing 1 damage.[/color][/b]\n";
               pgeneralhp[f]-=1;
               if (pgeneralhp[h]==-1) {
                                    int done = psupport[f];
                                    int x = 1;
                                    egeneralhp[h] +2;
                                    pgeneralxp[f] = 0;
                                    logfile<<"[color=blue][b]Player Command Ship "<<f<<" has been destroyed! The Player fleet is thrown into disarray![/color][/b]\n";
                                    while (done>0) {
                                          if (punitgeneral[x] == f) {done-=1; punitsupport[x]=0; punitgeneral[x]=0; }
                                          x+=1; }}}
                                          e = 0; g = 0;}}}
                                            
               
               
               
               
               
               
               
               
               
               if ((pgeneralcount > 0) && (pgeneralhp[f] >=0) && (enemyhp[c]>0)) {
               int damage3 = ((a+pgeneralpower[f]+psupport[f])-(d+enemypower[c])-eunitsupport[c]-enemymit[c]);
               if (damage3<0) {damage3=0;}
               cout<<"DEBUG 7\n";
               if ((e == 10) && (enemyhp[c] >0)) {
                      cout<<"DEBUG 8\n";
               if (eunitsupport[c] <= 0) {logfile<<"[color=green][b]Player Command Ship "<<f<<" rolled "<<a<<" + "<<pgeneralpower[f]+psupport[f]<<" [+"<<psupport[f]<<" Sup] vs AI ship "<<enemyval[c]<<"'s "<<d<<" + "<<enemypower[c]<<", dealing "<<damage3<<" [-"<<enemymit[c]<<" Mit] damage.[/color][/b]\n";}
               if (eunitsupport[c] > 0) {logfile<<"[color=green][b]Player Command Ship "<<f<<" rolled "<<a<<" + "<<pgeneralpower[f]+psupport[f]<<" [+"<<psupport[f]<<" Sup] vs AI ship "<<enemyval[c]<<"'s "<<d<<" + "<<enemypower[c]+eunitsupport[c]<<" [+"<<eunitsupport[c]<<" Sup], dealing "<<damage3<<" [-"<<enemymit[c]<<" Mit] damage.[/color][/b]\n";}               
               enemyhp[c]-=damage3;
               eactualhp[enemyval[c]]-=damage3;
                                      if (enemyshield[enemyval[c]] > 0) {enemyshield[enemyval[c]]-=enemymit[enemyval[c]];
                                      if (enemyshield[enemyval[c]] <= 0) {enemymit[enemyval[c]] = 0; logfile<<"[color=red]AI ship "<<enemyval[c]<<"'s shields have collapsed![/color]\n"; } }
                                      if(enemyhp[c] <= 0) {
                                      pgeneralxp[f]+=2; 
                                      enemydead[c] = true;
                                      if (enemyshield[enemyval[c]] > 0) {enemymit[enemyval[c]] = 0; logfile<<"[color=red]AI ship "<<enemyval[c]<<"'s shields have collapsed![/color]\n"; }
                                      logfile<<"[color=blue]AI ship "<<enemyval[c]<<" been destroyed.[/color]\n";
                                      tempval1 = enemyval[c];
                                      temphp1 = enemyhp[c];
                                      temppower1 = enemypower[c];
                                      tempsupport1 = eunitsupport[c];
                                      tempmit1 = enemymit[c];
                                      tempgen1 = eunitgeneral[c];                                     
                                      for (int y=c;y<=originalenemy;y++) {
                                          enemyhp[y] = enemyhp[y+1];
                                          enemypower[y] = enemypower[y+1];
                                          enemyval[y] = enemyval[y+1];
                                          eunitsupport[y] = eunitsupport[y+1];
                                          enemymit[y] = enemymit[y+1]; 
                                          eunitgeneral[y] = eunitgeneral[y+1];}
                                          enemyhp[originalenemy] = temphp1;
                                          enemyval[originalenemy] = tempval1;
                                          enemypower[originalenemy] = temppower1;
                                          eunitsupport[originalenemy] = tempsupport1;
                                          enemymit[originalenemy] = tempmit1;
                                          eunitgeneral[originalenemy] = tempgen1; 
                                          enemynumber = enemynumber - 1;
                                       } }  } 
               if ((egeneralcount > 0) && (egeneralhp[h]>=0) && (playerhp[b]>0)) {
               int damage4 = ((d+egeneralpower[h]+esupport[h])-(a+playerpower[b])-(punitsupport[b])-playermit[b]);
               if (damage4<0) {damage4=0;}
               if ((g == 10) && (playerhp[b] >0)) {
               if (punitsupport[b] <= 0) {logfile<<"[color=red][b]AI Command Ship "<<h<<" rolled "<<d<<" + "<<egeneralpower[h]+esupport[h]<<" [+"<<esupport[h]<<" Sup]"<<" vs Player ship "<<playerval[b]<<"'s "<<a<<" + "<<playerpower[b]<<", dealing "<<damage4<<" [-"<<playermit[b]<<" Mit] damage.[/color][/b]\n"; }
               if (punitsupport[b] > 0) {logfile<<"[color=red][b]AI Command Ship "<<h<<" rolled "<<d<<" + "<<egeneralpower[h]+esupport[h]<<" [+"<<esupport[h]<<" Sup]"<<" vs Player ship "<<playerval[b]<<"'s "<<a<<" + "<<playerpower[b]+punitsupport[b]<<" [+"<<punitsupport[b]<<" Sup], dealing "<<damage4<<" [-"<<playermit[b]<<" Mit] damage.[/color][/b]\n"; }               
               playerhp[b]-=damage4;
               pactualhp[playerval[b]]-=damage4;
               if (playershield[playerval[b]] > 0) {playershield[playerval[b]]-=playermit[playerval[b]];
               if (playershield[playerval[b]] <= 0) {playermit[playerval[b]] = 0; logfile<<"[color=green]Player ship "<<playerval[b]<<"'s shields have collapsed![/color]\n"; } } 
                       if(playerhp[b] <= 0) {
                       egeneralxp[h]+=2; 
                       playerdead[b] = true;
                        if (playershield[playerval[b]] > 0) {playermit[playerval[b]] = 0; logfile<<"[color=green]Player ship "<<playerval[b]<<"'s shields have collapsed![/color]\n"; }
                         logfile<<"[color=blue]Player ship "<<playerval[b]<<" been destroyed.[/color]\n";
                         tempval2 = playerval[b];
                         temphp2 = playerhp[b];
                         temppower2 = playerpower[b];
                         tempmit2 = playermit[b];
                         tempsupport2 = punitsupport[b];
                         tempgen2 = punitgeneral[b];
                         for (int y = b;y<=originalplayer;y++) {
                             playerhp[y] = playerhp[y+1];
                             playerpower[y] = playerpower[y+1];
                             playerval[y] = playerval[y+1];
                             punitsupport[y] = punitsupport[y+1];
                             playermit[y] = playermit[y+1]; 
                             punitgeneral[y] = punitgeneral[y+1];}
                             playerval[originalplayer] = tempval2;
                             playerhp[originalplayer] = temphp2;
                             playerpower[originalplayer] = temppower2;
                             punitsupport[originalplayer] = tempsupport2;
                             playermit[originalplayer] = tempmit2;
                             punitgeneral[originalplayer] = tempgen2;
                             playernumber = playernumber - 1;
                       } } }               
               
               if ((playerhp[b] > 0) && (enemyhp[c] > 0)) {
                                cout<<"DEBUG 9\n";
               if ((a+playerpower[b]+punitsupport[b]) > (d+enemypower[c]+eunitsupport[c])) {
                                                      cout<<"DEBUG 10\n";
                                      int damage1 = ((a+playerpower[b]+punitsupport[b])-(d+enemypower[c]+eunitsupport[c])-enemymit[c]);
                                      if (damage1 < 1) {damage1=0;}
                                      enemyhp[c]-=damage1;
                                      eactualhp[enemyval[c]]-=damage1;
                                      logfile<<"[color=green]Player ship "<<playerval[b]<<" rolled "<<a<<" + ";
                                      if (punitsupport[b] > 0) {logfile<<playerpower[b]+punitsupport[b]<<" [+"<<punitsupport[b]<<" Sup]"; }
                                      else if (punitsupport[b] == 0) {logfile<<playerpower[b]; }
                                      logfile<<" vs AI ship "<<enemyval[c]<<"'s "<<d<<" + ";
                                      if (eunitsupport[c] >0) {logfile<<enemypower[c]+eunitsupport[c]<<" [+"<<eunitsupport[c]<<" Sup]"; }
                                      else if (eunitsupport[c] ==0) {logfile<<enemypower[c]; }
                                      logfile<<", dealing "<<damage1<<" [-"<<enemymit[c]<<" Mit] damage.[/color]\n";
                                      if (enemyshield[enemyval[c]] > 0) {enemyshield[enemyval[c]]-=enemymit[enemyval[c]];
                                      if (enemyshield[enemyval[c]] <= 0) {enemymit[enemyval[c]] = 0; logfile<<"[color=red]AI ship "<<enemyval[c]<<"'s shields have collapsed![/color]\n"; } }
                                      if(enemyhp[c] <= 0) {
                                      if(punitsupport[b] > 0) {pgeneralxp[punitgeneral[playerval[b]]]+=1; } 
                                      enemydead[c] = true;
                                      if (enemyshield[enemyval[c]] > 0) {enemymit[enemyval[c]] = 0; logfile<<"[color=red]AI ship "<<enemyval[c]<<"'s shields have collapsed![/color]\n"; } 
                                      logfile<<"[color=blue]AI ship "<<enemyval[c]<<" been destroyed.[/color]\n";
                                      tempval1 = enemyval[c];
                                      temphp1 = enemyhp[c];
                                      temppower1 = enemypower[c];
                                      tempsupport1 = eunitsupport[c];
                                      tempmit1 = enemymit[c];
                                      tempgen1 = eunitgeneral[c];                                     
                                      for (int y=c;y<=originalenemy;y++) {
                                          enemyhp[y] = enemyhp[y+1];
                                          enemypower[y] = enemypower[y+1];
                                          enemyval[y] = enemyval[y+1];
                                          eunitsupport[y] = eunitsupport[y+1];
                                          enemymit[y] = enemymit[y+1]; 
                                          eunitgeneral[y] = eunitgeneral[y+1];}
                                          enemyhp[originalenemy] = temphp1;
                                          enemyval[originalenemy] = tempval1;
                                          enemypower[originalenemy] = temppower1;
                                          eunitsupport[originalenemy] = tempsupport1;
                                          enemymit[originalenemy] = tempmit1;
                                          eunitgeneral[originalenemy] = tempgen1; 
                                          enemynumber = enemynumber - 1;
                                       } } 
               else if (((a+playerpower[b]+punitsupport[b]) < (d+enemypower[c]+eunitsupport[c])) && (enemyhp[c] > 0)) {
                    cout<<"DEBUG 11\n";
                       int damage2 =((d+enemypower[c]+eunitsupport[c])-(a+playerpower[b]+punitsupport[b])-playermit[b]); 
                       if (damage2 < 1) {damage2=0; cout<<damage2<<endl;}
                       playerhp[b]-=damage2;
                       cout<<pactualhp[playerval[b]];
                       cout<<" - "<<damage2<<" = ";
                       pactualhp[playerval[b]]-=damage2;
                       cout<<pactualhp[playerval[b]]<<endl;                       

                                      logfile<<"[color=red]AI ship "<<enemyval[c]<<" rolled "<<d<<" + ";
                                      if (eunitsupport[c] >0) {logfile<<enemypower[c]+eunitsupport[c]<<" [+"<<eunitsupport[c]<<" Sup]"; }
                                      else if (eunitsupport[c] ==0) {logfile<<enemypower[c]; }
                                      logfile<<" vs Player ship "<<playerval[b]<<"'s "<<a<<" + ";
                                      if (punitsupport[b] > 0) {logfile<<playerpower[b]+punitsupport[b]<<" [+"<<punitsupport[b]<<" Sup]"; }
                                      else if (punitsupport[b] == 0) {logfile<<playerpower[b]; }
                                      logfile<<", dealing "<<damage2<<" [-"<<playermit[b]<<" Mit] damage.[/color]\n";
                                      if (playershield[playerval[b]] > 0) {playershield[playerval[b]]-=playermit[playerval[b]];
                                      if (playershield[playerval[b]] <= 0) {playermit[playerval[b]] = 0; logfile<<"[color=green]Player ship "<<playerval[b]<<"'s shields have collapsed![/color]\n"; } }
//                       logfile<<"AI ship "<<enemyval[c]<<" rolled "<<d<<" + "<<enemypower[c]<<" vs Player ship "<<playerval[b]<<"'s "<<a<<" + "<<playerpower[b]<<", dealing "<<((d+enemypower[c])-(a+playerpower[b]))<<" damage.\n";
                       if(playerhp[b] <= 0) {
                       if(eunitsupport[c] > 0) {egeneralxp[eunitgeneral[enemyval[c]]]+=1;} 
                       playerdead[b] = true;
                        if (playershield[playerval[b]] > 0) {playermit[playerval[b]] = 0; logfile<<"[color=green]Player ship "<<playerval[b]<<"'s shields have collapsed![/color]\n"; }
                         logfile<<"[color=blue]Player ship "<<playerval[b]<<" been destroyed.[/color]\n";
                         tempval2 = playerval[b];
                         temphp2 = playerhp[b];
                         temppower2 = playerpower[b];
                         tempmit2 = playermit[b];
                         tempsupport2 = punitsupport[b];
                         tempgen2 = punitgeneral[b];
                         for (int y = b;y<=originalplayer;y++) {
                             playerhp[y] = playerhp[y+1];
                             playerpower[y] = playerpower[y+1];
                             playerval[y] = playerval[y+1];
                             punitsupport[y] = punitsupport[y+1];
                             playermit[y] = playermit[y+1]; 
                             punitgeneral[y] = punitgeneral[y+1];}
                             playerval[originalplayer] = tempval2;
                             playerhp[originalplayer] = temphp2;
                             playerpower[originalplayer] = temppower2;
                             punitsupport[originalplayer] = tempsupport2;
                             playermit[originalplayer] = tempmit2;
                             punitgeneral[originalplayer] = tempgen2;
                             playernumber = playernumber - 1;
                       } }
                       }
//              if ((playerhp[b] <= 0)&&(enemyhp[c] <= 0)) {
                if ((playernumber <= 0) || (enemynumber <= 0)) {
                               cout<<"DEBUG\n";
                               if ((playernumber <=0) && (pgeneralcount > 0)) {
                                                fled = false; 
                                                int q=0;
                                                for (int x=1;x<=pgeneralcount;x++) {if(pgeneralhp[x]>=0){q+=1;}}
                                                int p=(rand()%q+1);
                                                pgeneralhp[p]-=1;
                                                logfile<<"[color=green][b]Due to defeat, Player Command Ship "<<p<<" has taken 1 damage[/color][/b]\n"; 
                                                if (pgeneralhp[p] == -1) {
                                                                  logfile<<"[color=blue][b]Player Command Ship "<<p<<" has been destoyed![/color][/b]\n";
                                                                  int r=0;
                                                                  for (int x=1;x<=egeneralcount;x++) { if(egeneralhp[x] >=0) {r+=1;} }
                                                                  int s = (rand()%r+1);
                                                                  egeneralxp[s] +2;
                                                                  pgeneralxp[p] = 0; } }
                               if ((enemynumber <=0) && (egeneralcount > 0)) {
                                                fled = false;
                                                int q=0;
                                                for (int x=1;x<=egeneralcount;x++) {if(egeneralhp[x]>=0){q+=1;}}
                                                int p=(rand()%q+1);
                                                egeneralhp[p]-=1;
                                                logfile<<"[color=red][b]Due to defeat, AI Command Ship "<<p<<" has taken 1 damage[/color][/b]\n"; 
                                                if (egeneralhp[p] == -1) {
                                                                  logfile<<"[color=blue][b]AI Command Ship "<<p<<" has been destroyed![/color][/b]\n";
                                                                  int r=0;
                                                                  for (int x=1;x<=pgeneralcount;x++) {if(pgeneralhp[x] >=0) {r+=1; } }
                                                                  int s=(rand()%r+1);
                                                                  pgeneralxp[s] +=2;
                                                                  egeneralxp[p] = 0; } } 
                                               
                               
                               break; } 
  //                    cout<<"OPlayer ship "<<orib<<"\nOAI ship "<<oric<<endl;
    //                  cout<<"Player ship "<<playerval[b]<<"\nAI ship "<<enemyval[c]<<endl;
      //                cout<<"Player HP "<<playerhp[b]<<"\nAI HP "<<enemyhp[c]<<endl;          }
  //                  playerdead[b] = true; 
    //                int x = b+1;
      //              while (++x<=playernumber-1) {
        //                  playerhp[x-1] = playerhp[x];
          //                playerpower[x-1] = playerpower[x];}
            //              playernumber-=1; 
              //            logfile<<"Player ship "<<playerval[b]<<" been destroyed.\n";
                //    enemydead[c] = true;
                  //  x = c+1;
                    //while (++x<=enemynumber-1) {
                      //    enemyhp[x-1] = enemyhp[x];
                        //  enemypower[x-1] = enemypower[x];}
                          //enemynumber-=1;
                          //logfile<<"AI ship "<<enemyval[c]<<" been destroyed.\n";  }                   
               }             
               logfile<<"\n\n*****RESULTS*****";
               logfile<<"\n\nPlayer ships Left: "<<playernumber<<endl;
               logfile<<"AI ships Left: "<<enemynumber<<endl;
               if ((playernumber > 0) && (fled == false)) {
               logfile<<"\nPlayer wins!\n"; }
               else {
               logfile<<"\nAI wins!\n\n"; }
               if (pgeneralcount > 0) { for(int x=1;x<=pgeneralcount;x++) {logfile<<"Player Command Ship "<<x<<" gained "<<pgeneralxp[x]<<"XP\n";} }
               if (egeneralcount > 0) { for (int x=1;x<=egeneralcount;x++) {logfile<<"AI Command Ship "<<x<<" gained "<<egeneralxp[x]<<"XP\n";} }              
               logfile<<"\n[Losses]:\n";
               for (int x=1;x<=pgeneralcount;x++) {
                   if (pgeneralhp[x] <= -1) {logfile<<"[b][color=green]Player Command Ship "<<x<<" was destroyed.[/color][/b]\n"; } }
               for (int x=1;x<=originalplayer;x++) {
                   if (pactualhp[playerval[x]] <= 0) { logfile<<"[color=green]Player ship "<<playerval[x]<<" dead.[/color]\n"; } }
               for (int x=1;x<=egeneralcount;x++) {
                   if (egeneralhp[x] <= -1) {logfile<<"[color=red][b]AI Command Ship "<<x<<" was destroyed.[/color][/b]\n"; }}
               for (int x=1;x<=originalenemy;x++) {
                   if (eactualhp[enemyval[x]] <= 0) { logfile<<"[color=red]AI ship "<<enemyval[x]<<" dead.[/color]\n"; } }
               logfile<<"\n[Casualties]";
               for (int x=1;x<=pgeneralcount;x++) {
                   logfile<<"\n[b][color=green]Player Command Ship "<<x<<": HP "<<pgeneralhp[x]<<"[/color][/b]"; }
               for (int x=1;x<=originalplayer;x++) {
                   logfile<<"\n[color=green]Player ship "<<playerval[x]<<": HP "<<pactualhp[playerval[x]]<<"/"<<originalplayerhp[playerval[x]]<<"[/color]"; 
                   if (pounitsupport[playerval[x]] > 0) { logfile<<" [Supported "<<pounitsupport[playerval[x]]<<" by Command Ship "<<pounitgeneral[playerval[x]]<<"]"; }}
               logfile<<endl;
               for (int x=1;x<=egeneralcount;x++) {
                   logfile<<"\n[b][color=red]AI Command Ship "<<x<<": HP "<<egeneralhp[x]<<"[/color][/b]"; }               
               for (int x=1;x<=originalenemy;x++) {
                   logfile<<"\n[color=red]AI ship "<<enemyval[x]<<": HP "<<eactualhp[enemyval[x]]<<"/"<<originalenemyhp[enemyval[x]]<<"[/color]"; 
                   if (eounitsupport[enemyval[x]] > 0) { logfile<<" [Supported "<<eounitsupport[enemyval[x]]<<" by Command Ship "<<eounitgeneral[enemyval[x]]<<"]"; }}
               
               
                   
                   
                   
     logfile.close();}       
       
        
                
                   
}

void simple()
{
     srand((unsigned)time(0));     
     int a,b,c,d;
     cout<<"Enter filename:\n";
     cin>>filename;     
     cout<<"Enter number of player forces.\n";
     cin>>playernumber;
     cout<<"Enter number of AI forces.\n";
     cin>>enemynumber;
     int originalenemy = enemynumber;
     int originalplayer = playernumber;
     int playerpower[playernumber];
     int enemypower[enemynumber];
     int playerhp[playernumber];
     int enemyhp[enemynumber];
     int pactualhp[playernumber];
     int eactualhp[playernumber];
     int playerval[playernumber];
     int enemyval[enemynumber];
     int originalplayerhp[playernumber];
     int originalenemyhp[enemynumber];  
     bool playerdead[playernumber];
     bool enemydead[enemynumber];  
     for (int x=1;x<=playernumber;x++) {
     cout<<"Enter power of player Ship "<<x<<" : ";
     cin>>playerpower[x];
     playerval[x] = x;
     if (playerpower[x] >= 8) {playerpower[x] = 8; } }
     for (int x=1;x<=enemynumber;x++) {
     cout<<"Enter power of AI Ship "<<x<<" : ";
     cin>>enemypower[x];
     enemyval[x] = x;
     if (enemypower[x] >= 8) {enemypower[x] = 8; } }
     for (int x=1;x<=playernumber;x++) {
     cout<<"Enter HP of player Ship "<<x<<" : ";
     cin>>playerhp[x];
     pactualhp[x] = playerhp[x];
     originalplayerhp[x] = playerhp[x]; }
     for (int x=1;x<=enemynumber;x++) {
     cout<<"Enter HP of AI Ship "<<x<<" : ";
     cin>>enemyhp[x];
     eactualhp[x] = enemyhp[x];
     originalenemyhp[x] = enemyhp[x]; }
     cout<<"Confirm Ship information: \n";
     for (int x=1;x<=playernumber;x++) {
         cout<<"Player Ship "<<x<<": HP"<<playerhp[x]<<" Pwr"<<playerpower[x]<<"\n"; }    
     for (int x=1;x<=enemynumber;x++) {
         cout<<"AI Ship "<<x<<": HP"<<enemyhp[x]<<" Pwr"<<enemypower[x]<<"\n"; }         
     cout<<"Confirm?\n";
     string confirm;
     cin>>confirm;
     if (StringToUpper(confirm) == "YES") { }
     else if (StringToUpper(confirm) == "NO") { simple(); }
     else {cout<<"Incorrect Syntax\n"; simple(); }
  //   while ((playernumber>0) && (enemynumber>0)) {
//     a = (rand()%3+1)-2; }
     bool write = false;
     string YN;     
     filename.append(".txt");
     ifstream check(filename.c_str(),ios::in);
     if (check.is_open() ) {
                         cout<<"That file already exists, overwrite? [Y/N]\n";
                         cin>>YN;
                         YN = StringToUpper(YN);
                         if (YN == "Y") { write = true; }
                         else if (YN == "N") { }
                         else { simple(); } }
     else { write = true; }
     if (write == true) {
     ofstream logfile(filename.c_str(),ios::trunc);               
               logfile<<"*****Battle report: "<<filename<<"*****\n\n";
               logfile<<"[Starting Stats]:\n";
               for (int x=1;x<=playernumber;x++) {
                   logfile<<"[color=green]Player ship "<<x<<": HP"<<playerhp[x]<<" Pwr"<<playerpower[x]<<"[/color]\n"; }    
               for (int x=1;x<=enemynumber;x++) {
                   logfile<<"[color=red]AI ship "<<x<<": HP"<<enemyhp[x]<<" Pwr"<<enemypower[x]<<"[/color]\n"; }
               logfile<<"\n[Combat Details]\n\n";
               //for (int count = 0;count<100000000;count++) {
               while ((playernumber > 0) && (enemynumber > 0)) {
               a = 0;
               b = 0;
               c = 0;
               d = 0;
               b = (rand()%(playernumber));
               int orib = b;
               if (b <= 1) { b=1; }
               if (b >= playernumber) {b=playernumber; }
               c = (rand()%(enemynumber));
               int oric = c;
               if (c <= 1) { c=1; }
               if (c >= enemynumber) {c=enemynumber; }
               a = (rand()%8+1)-4;
               if (a >=4) { a=4; }
               if (a <=-4) { a=-4; }
               d = (rand()%8+1)-4;
               if (d >=4) { d=4; }
               if (d <=-4) { d=-4; }
               if ((playerhp[b] > 0) && (enemyhp[c] > 0)) {
               if ((a+playerpower[b]) >= (d+enemypower[c])) {
                                      cout<<"Unit "<<playerval[b]<<"\nUnit "<<enemyval[c]<<endl;
                                      cout<<enemyhp[c]<<endl;
                                      enemyhp[c]-=((a+playerpower[b])-(d+enemypower[c]));
                                      eactualhp[enemyval[c]] -=((a+playerpower[b])-(d+enemypower[c]));
                                      cout<<enemyhp[c]<<endl;
                                      cout<<"Player ship\n";
                                      logfile<<"Player ship "<<playerval[b]<<" rolled "<<a<<" + "<<playerpower[b]<<" vs AI ship "<<enemyval[c]<<"'s "<<d<<" + "<<enemypower[c]<<", dealing "<<((a+playerpower[b])-(d+enemypower[c]))<<" damage.\n";
                                      if(enemyhp[c] <= 0) { 
                                      enemydead[c] = true;
                                      logfile<<"AI ship "<<enemyval[c]<<" been destroyed.\n";
                                      tempval1 = enemyval[c];
                                      temphp1 = enemyhp[c];
                                      temppower1 = enemypower[c];                                      
                                      for (int y=c;y<originalenemy;y++) {
                                          enemyhp[y] = enemyhp[y+1];
                                          enemypower[y] = enemypower[y+1];
                                          enemyval[y] = enemyval[y+1]; }
                                          enemyhp[originalenemy] = temphp1;
                                          enemyval[originalenemy] = tempval1;
                                          enemypower[originalenemy] = temppower1; 
                                          cout<<"AINumber1: "<<enemynumber<<endl;                              
                                          enemynumber = enemynumber - 1;
                                           cout<<"AINumber2: "<<enemynumber<<endl;                                                                    
                                       } }
               else if (((a+playerpower[b]) < (d+enemypower[c])) && (enemyhp[c] > 0)) {
                       playerhp[b]-=((d+enemypower[c])-(a+playerpower[b]));
                       pactualhp[playerval[b]]-=((d+enemypower[c])-(a+playerpower[b]));
                       cout<< ((d+enemypower[c])-(a+playerpower[b]))<<endl;
                       cout<<"AI ship "<<enemyval[c]<<endl;
                       logfile<<"AI ship "<<enemyval[c]<<" rolled "<<d<<" + "<<enemypower[c]<<" vs Player ship "<<playerval[b]<<"'s "<<a<<" + "<<playerpower[b]<<", dealing "<<((d+enemypower[c])-(a+playerpower[b]))<<" damage.\n";
                       if(playerhp[b] <= 0) { 
                       playerdead[b] = true;
                         logfile<<"Player ship "<<playerval[b]<<" been destroyed.\n";
                         tempval2 = playerval[b];
                         temphp2 = playerhp[b];
                         temppower2 = playerpower[b];
                         for (int y = b;y<originalplayer;y++) {
                             playerhp[y] = playerhp[y+1];
                             playerpower[y] = playerpower[y+1];
                             playerval[y] = playerval[y+1]; }
                             playerval[originalplayer] = tempval2;
                             playerhp[originalplayer] = temphp2;
                             playerpower[originalplayer] = temppower2;
                             playernumber = playernumber - 1;
                       } }
                       }
//              if ((playerhp[b] <= 0)&&(enemyhp[c] <= 0)) {
                if ((playernumber <= 0) || (enemynumber <= 0)) {
                               cout<<"DEBUG\n";
                               break; }
  //                    cout<<"OPlayer ship "<<orib<<"\nOAI ship "<<oric<<endl;
    //                  cout<<"Player ship "<<playerval[b]<<"\nAI ship "<<enemyval[c]<<endl;
      //                cout<<"Player HP "<<playerhp[b]<<"\nAI HP "<<enemyhp[c]<<endl;          }
  //                  playerdead[b] = true; 
    //                int x = b+1;
      //              while (++x<=playernumber-1) {
        //                  playerhp[x-1] = playerhp[x];
          //                playerpower[x-1] = playerpower[x];}
            //              playernumber-=1; 
              //            logfile<<"Player ship "<<playerval[b]<<" been destroyed.\n";
                //    enemydead[c] = true;
                  //  x = c+1;
                    //while (++x<=enemynumber-1) {
                      //    enemyhp[x-1] = enemyhp[x];
                        //  enemypower[x-1] = enemypower[x];}
                          //enemynumber-=1;
                          //logfile<<"AI ship "<<enemyval[c]<<" been destroyed.\n";  }                   
               }
               logfile<<"\n\n*****RESULTS*****";
               logfile<<"\nPlayer ships Left: "<<playernumber<<endl;
               logfile<<"AI ships Left: "<<enemynumber<<endl;
               if (playernumber > 0) {
               logfile<<"\nPlayer wins!\n"; }
               else if (playernumber <= 0) {
               logfile<<"\nAI wins!\n"; }
               logfile<<"\n[Losses]:\n";
               for (int x=1;x<=originalplayer;x++) {
                   if (pactualhp[playerval[x]] <= 0) { logfile<<"Player ship "<<playerval[x]<<" dead.\n"; } }
               for (int x=1;x<=originalenemy;x++) {
                   if (eactualhp[enemyval[x]] <= 0) { logfile<<"AI ship "<<enemyval[x]<<" dead.\n"; } }
               logfile<<"\n[Casualties]\n";
               for (int x=1;x<=originalplayer;x++) {
                   cout<<playerval[x]<<":"<<playerhp[x]<<endl;
                   logfile<<"Player ship "<<playerval[x]<<": HP "<<pactualhp[playerval[x]]<<"/"<<originalplayerhp[x]<<endl; }
               for (int x=1;x<=originalenemy;x++) {
                   logfile<<"AI ship "<<enemyval[x]<<": HP "<<eactualhp[enemyval[x]]<<"/"<<originalenemyhp[x]<<endl; }
               
               
                   
                   
                   
     logfile.close();}       
       
       
             
}


       
     

int main()
{
    while (quit == false) {
        commandprompt(); }
}

string StringToUpper(string strToConvert)
{ //change each element of the string to upper case
   for(unsigned int i=0;i<strToConvert.length();i++)
   {
      strToConvert[i] = toupper(strToConvert[i]);
   }
   return strToConvert;//return the converted string
}

string StringToLower(string strToConvert)
{//change each element of the string to lower case
   for(unsigned int i=0;i<strToConvert.length();i++)
   {
      strToConvert[i] = tolower(strToConvert[i]);
   }
   return strToConvert;//return the converted string
}
