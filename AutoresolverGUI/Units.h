#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

class Ship
{
    public:
        string name;
        int maxhp;
        int currenthp;
        int maxshp;
        int currentshp;
        int power;
        int shieldmit;
        int shieldstr;
        int commandedby;
        int commanded;
        int exchanges;
        int temppower;
        int tempduration;
        int shieldstrpower;
        int shieldstrduration;
        int shieldmitpower;
        int shieldmitduration;
        int shieldstrdropped[100];
        int shieldstrdroppedduration[100];
        int shieldstrdroppednum;
        int shieldmitdropped[100];
        int shieldmitdroppedduration[100];
        int shieldmitdroppednum;
        int shpdamage;
        bool shielddrop;
        int shielddropdur;
        bool used;
        bool alive;
        Ship();
        ~Ship();
        void Destroy();
};

class CommandShip: public Ship {
  public:
        int xp;
        int rating;
        int bonus;
        void SetBonus();
};

void Cleanup();
