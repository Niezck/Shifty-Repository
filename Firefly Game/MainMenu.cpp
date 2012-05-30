#include "wxStuff.h"
#include "Includes.h"

void GameWindow::MainMenu()
{
    wxBitmap pic;
    pic.LoadFile(wxT("Data\\Images\\Misc\\Menu.png"),wxBITMAP_TYPE_PNG);
//    SetWindowStyle(wxBORDER_NONE);
//    menubackground = new wxStaticBitmap(this,-1,pic);
    newgame = new wxBitmapButton(this,ID_NEWGAME,pic);
    newgame->SetBitmapFocus(pic);
    newgame->SetBitmapSelected(pic);
//    loadgame = new wxButton(this,ID_LOADGAME,wxT("Load Game"));
    mainmenuhbox = new wxBoxSizer(wxHORIZONTAL);
    vbox = new wxBoxSizer(wxVERTICAL);
    
//    loadgame->Disable();
    
    mainmenuhbox->Add(newgame,1,wxALL|wxEXPAND,0);
//    mainmenuhbox->Add(loadgame,0,wxALL|wxEXPAND,5);
//    vbox->Add(menubackground,1,wxALL|wxEXPAND,5);
    vbox->Add(mainmenuhbox,1,wxALL|wxEXPAND,0);
    SetSizer(vbox);
    vbox->Layout();
}

void GameWindow::NewGame(wxCommandEvent &event)
{
//    SetWindowStyle(0);
//    menubackground->Show(false);
    newgame->Show(false);
//    loadgame->Show(false);
    CreateStartingControls();
    CreateFirstCaptainControl();
    CreateCaptainControls();
}
