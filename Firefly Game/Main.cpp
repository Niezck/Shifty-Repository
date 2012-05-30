#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    GameWindow *main = new GameWindow(wxT("Cap'n: Adventures in the Firefly Universe"));
    main->Show(true);

    return true;
}

string StringToUpper(string strToConvert)
{ //change each element of the string to upper case
   for(unsigned int i=0;i<strToConvert.length();i++)
   {
      strToConvert[i] = toupper(strToConvert[i]);
   }
   return strToConvert;//return the converted string
}
