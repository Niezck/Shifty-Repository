#include "Includes.h"
#include "wxStuff.h"

extern Ship shipstats[10];

void GameWindow::CreateDealerControls()
{
    shipyardpanel =  new wxPanel(mainbook,-1);

    shipyarddesc = new wxTextCtrl(shipyardpanel,-1,wxT("Foo"),wxDefaultPosition,wxDefaultSize,wxTE_READONLY|wxTE_MULTILINE,wxDefaultValidator,wxT(""));
    shipyarddesc->Show(false);
    
    shipyardvbox = new wxBoxSizer(wxVERTICAL);
    shipyardgsizer = new wxGridSizer(3,2,5,5);
    
    shipsizera = new wxBoxSizer(wxVERTICAL);
    shipsizerb = new wxBoxSizer(wxVERTICAL);
    shipsizerc = new wxBoxSizer(wxVERTICAL);
    shipsizerd = new wxBoxSizer(wxVERTICAL);
    shipsizere = new wxBoxSizer(wxVERTICAL);
    shipsizerf = new wxBoxSizer(wxVERTICAL);
    
    shipa = new wxBitmapButton(shipyardpanel,ID_SHIPBUTTON_A,shipstats[0].shipyardportrait);
    shipb = new wxBitmapButton(shipyardpanel,ID_SHIPBUTTON_B,shipstats[1].shipyardportrait);
    shipc = new wxBitmapButton(shipyardpanel,ID_SHIPBUTTON_C,shipstats[2].shipyardportrait);
    shipd = new wxBitmapButton(shipyardpanel,ID_SHIPBUTTON_D,shipstats[3].shipyardportrait);
    shipe = new wxBitmapButton(shipyardpanel,ID_SHIPBUTTON_E,shipstats[4].shipyardportrait);
    shipf = new wxBitmapButton(shipyardpanel,ID_SHIPBUTTON_F,shipstats[5].shipyardportrait);
    shipback = new wxBitmapButton(shipyardpanel,ID_SHIPBUTTON_BACK,shipstats[0].portrait);
    shipback->SetBitmapHover(back);
    shipback->Show(false);
    shipadvancea = new wxButton(shipyardpanel,ID_SHIPADVANCEA,wxT("That's the ship for me"));
    shipadvanceb = new wxButton(shipyardpanel,ID_SHIPADVANCEB,wxT("That's the ship for me"));
    shipadvancec = new wxButton(shipyardpanel,ID_SHIPADVANCEC,wxT("That's the ship for me"));
    shipadvanced = new wxButton(shipyardpanel,ID_SHIPADVANCED,wxT("That's the ship for me"));
    shipadvancee = new wxButton(shipyardpanel,ID_SHIPADVANCEE,wxT("That's the ship for me"));
    shipadvancef = new wxButton(shipyardpanel,ID_SHIPADVANCEF,wxT("That's the ship for me"));
    shipadvancea->Show(false);
    shipadvanceb->Show(false);
    shipadvancec->Show(false);
    shipadvanced->Show(false);
    shipadvancee->Show(false);
    shipadvancef->Show(false);
    shiptexta = new wxStaticText(shipyardpanel,-1,shipstats[0].name,wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    shiptextb = new wxStaticText(shipyardpanel,-1,shipstats[1].name,wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    shiptextc = new wxStaticText(shipyardpanel,-1,shipstats[2].name,wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    shiptextd = new wxStaticText(shipyardpanel,-1,shipstats[3].name,wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    shiptexte = new wxStaticText(shipyardpanel,-1,shipstats[4].name,wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    shiptextf = new wxStaticText(shipyardpanel,-1,shipstats[5].name,wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    
    shipnamebmp = new wxStaticBitmap(shipyardpanel,-1,wxNullBitmap);
    shipnametext = new wxStaticText(shipyardpanel,-1,wxT("Ship Name:"));
    shipnamectrl = new wxTextCtrl(shipyardpanel,-1,wxT(""));
    shipnamebutton = new wxButton(shipyardpanel,ID_SETSHIPNAME,wxT("That's the one!"));
    shipnamesizer = new wxBoxSizer(wxHORIZONTAL);
    
    shipnamesizer->Add(shipnametext,0,wxALL|wxEXPAND,5);
    shipnamesizer->Add(shipnamectrl,0,wxALL|wxEXPAND,5);
    
    shipnamebmp->Show(false);
    shipnametext->Show(false);
    shipnamectrl->Show(false);
    shipnamebutton->Show(false);
    
    shipsizera->Add(shipa,1,wxALL|wxEXPAND,5);
    shipsizera->Add(shiptexta,0,wxALL|wxEXPAND,5);
    shipsizerb->Add(shipb,1,wxALL|wxEXPAND,5);
    shipsizerb->Add(shiptextb,0,wxALL|wxEXPAND,5);
    shipsizerc->Add(shipc,1,wxALL|wxEXPAND,5);
    shipsizerc->Add(shiptextc,0,wxALL|wxEXPAND,5);
    shipsizerd->Add(shipd,1,wxALL|wxEXPAND,5);
    shipsizerd->Add(shiptextd,0,wxALL|wxEXPAND,5);
    shipsizere->Add(shipe,1,wxALL|wxEXPAND,5);
    shipsizere->Add(shiptexte,0,wxALL|wxEXPAND,5);
    shipsizerf->Add(shipf,1,wxALL|wxEXPAND,5);
    shipsizerf->Add(shiptextf,0,wxALL|wxEXPAND,5);
    
    shipyardgsizer->Add(shipsizera,2,wxALL|wxEXPAND,5);
    shipyardgsizer->Add(shipsizerb,2,wxALL|wxEXPAND,5);
    shipyardgsizer->Add(shipsizerc,2,wxALL|wxEXPAND,5);
    shipyardgsizer->Add(shipsizerd,2,wxALL|wxEXPAND,5);
    shipyardgsizer->Add(shipsizere,2,wxALL|wxEXPAND,5);
    shipyardgsizer->Add(shipsizerf,2,wxALL|wxEXPAND,5);
    
    shipyardvbox->Add(shipback,1,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipyardgsizer,6,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipyarddesc,1,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipadvancea,0,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipadvanceb,0,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipadvancec,0,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipadvanced,0,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipadvancee,0,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipadvancef,0,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipnamebmp,1,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipnamesizer,0,wxALL|wxEXPAND,5);
    shipyardvbox->Add(shipnamebutton,0,wxALL|wxEXPAND,5);
    shipyardpanel->SetSizer(shipyardvbox);
    
    mainbook->AddPage(shipyardpanel,wxT("Shipyard"),false,-1);
}

void GameWindow::ShipyardA(wxCommandEvent &event)
{
    shipa->Show(false);
    shipb->Show(false);
    shipc->Show(false);
    shipd->Show(false);
    shipe->Show(false);
    shipf->Show(false);
    shiptexta->Show(false);
    shiptextb->Show(false);
    shiptextc->Show(false);
    shiptextd->Show(false);
    shiptexte->Show(false);
    shiptextf->Show(false);
    wxString foo = GenerateShipyardText(0);
    shipyarddesc->SetValue(foo);
    shipback->SetBitmapLabel(shipstats[0].portrait);
    shipyardgsizer->Layout();
    shipyarddesc->Show(true);
    shipback->Show(true);
    shipadvancea->Show(true);
    shipyarddesc->Refresh();
    shipyardvbox->Layout();
}

void GameWindow::ShipyardB(wxCommandEvent &event)
{
    shipa->Show(false);
    shipb->Show(false);
    shipc->Show(false);
    shipd->Show(false);
    shipe->Show(false);
    shipf->Show(false);
    shiptexta->Show(false);
    shiptextb->Show(false);
    shiptextc->Show(false);
    shiptextd->Show(false);
    shiptexte->Show(false);
    shiptextf->Show(false);
    wxString foo = GenerateShipyardText(1);
    shipyarddesc->SetValue(foo);
    shipback->SetBitmapLabel(shipstats[1].portrait);
    shipyardgsizer->Layout();
    shipyarddesc->Show(true);
    shipback->Show(true);
    shipadvanceb->Show(true);
    shipyarddesc->Refresh();
    shipyardvbox->Layout();
}

void GameWindow::ShipyardC(wxCommandEvent &event)
{
    shipa->Show(false);
    shipb->Show(false);
    shipc->Show(false);
    shipd->Show(false);
    shipe->Show(false);
    shipf->Show(false);
    shiptexta->Show(false);
    shiptextb->Show(false);
    shiptextc->Show(false);
    shiptextd->Show(false);
    shiptexte->Show(false);
    shiptextf->Show(false);
    wxString foo = GenerateShipyardText(2);
    shipyarddesc->SetValue(foo);
    shipback->SetBitmapLabel(shipstats[2].portrait);
    shipyardgsizer->Layout();
    shipyarddesc->Show(true);
    shipback->Show(true);
    shipadvancec->Show(true);
    shipyarddesc->Refresh();
    shipyardvbox->Layout();
}

void GameWindow::ShipyardD(wxCommandEvent &event)
{
    shipa->Show(false);
    shipb->Show(false);
    shipc->Show(false);
    shipd->Show(false);
    shipe->Show(false);
    shipf->Show(false);
    shiptexta->Show(false);
    shiptextb->Show(false);
    shiptextc->Show(false);
    shiptextd->Show(false);
    shiptexte->Show(false);
    shiptextf->Show(false);
    wxString foo = GenerateShipyardText(3);
    shipyarddesc->SetValue(foo);
    shipback->SetBitmapLabel(shipstats[3].portrait);
    shipyardgsizer->Layout();
    shipyarddesc->Show(true);
    shipback->Show(true);
    shipadvanced->Show(true);
    shipyarddesc->Refresh();
    shipyardvbox->Layout();
}

void GameWindow::ShipyardE(wxCommandEvent &event)
{
    shipa->Show(false);
    shipb->Show(false);
    shipc->Show(false);
    shipd->Show(false);
    shipe->Show(false);
    shipf->Show(false);
    shiptexta->Show(false);
    shiptextb->Show(false);
    shiptextc->Show(false);
    shiptextd->Show(false);
    shiptexte->Show(false);
    shiptextf->Show(false);
    wxString foo = GenerateShipyardText(4);
    shipyarddesc->SetValue(foo);
    shipback->SetBitmapLabel(shipstats[4].portrait);
    shipyardgsizer->Layout();
    shipyarddesc->Show(true);
    shipback->Show(true);
    shipadvancee->Show(true);
    shipyarddesc->Refresh();
    shipyardvbox->Layout();
}

void GameWindow::ShipyardF(wxCommandEvent &event)
{
    shipa->Show(false);
    shipb->Show(false);
    shipc->Show(false);
    shipd->Show(false);
    shipe->Show(false);
    shipf->Show(false);
    shiptexta->Show(false);
    shiptextb->Show(false);
    shiptextc->Show(false);
    shiptextd->Show(false);
    shiptexte->Show(false);
    shiptextf->Show(false);
    wxString foo = GenerateShipyardText(5);
    shipyarddesc->SetValue(foo);
    shipback->SetBitmapLabel(shipstats[5].portrait);
    shipyardgsizer->Layout();
    shipyarddesc->Show(true);
    shipback->Show(true);
    shipadvancef->Show(true);
    shipyarddesc->Refresh();
    shipyardvbox->Layout();
}

void GameWindow::RestoreShipyard(wxCommandEvent &event)
{
    shipyarddesc->Show(false);
    shipback->Show(false);
    shipa->Show(true);
    shipb->Show(true);
    shipc->Show(true);
    shipd->Show(true);
    shipe->Show(true);
    shipf->Show(true);
    shiptexta->Show(true);
    shiptextb->Show(true);
    shiptextc->Show(true);
    shiptextd->Show(true);
    shiptexte->Show(true);
    shiptextf->Show(true);
    shipadvancea->Show(false);
    shipadvanceb->Show(false);
    shipadvancec->Show(false);
    shipadvanced->Show(false);
    shipadvancee->Show(false);
    shipadvancef->Show(false);
    shipyardvbox->Layout();
}

void GameWindow::ShipyardAdvanceA(wxCommandEvent &event)
{
//    wxLogMessage(wxT("Ship - Firefly Class Transport"));
    shipadvancea->Show(false);
    shipadvanceb->Show(false);
    shipadvancec->Show(false);
    shipadvanced->Show(false);
    shipadvancee->Show(false);
    shipadvancef->Show(false);
    shipyarddesc->Show(false);
    shipback->Show(false);
    shipnamebmp->Show(false);
    shipnamebmp->SetBitmap(shipstats[0].portrait);
    shipnametext->Show(true);
    shipnamebmp->Show(true);
    shipnamebutton->Show(true);
    shipnamectrl->Show(true);
    shipyardvbox->Layout();
}

void GameWindow::ShipyardAdvanceB(wxCommandEvent &event)
{

}

void GameWindow::ShipyardAdvanceC(wxCommandEvent &event)
{

}

void GameWindow::ShipyardAdvanceD(wxCommandEvent &event)
{

}

void GameWindow::ShipyardAdvanceE(wxCommandEvent &event)
{

}

void GameWindow::ShipyardAdvanceF(wxCommandEvent &event)
{

}

void GameWindow::SetShipName(wxCommandEvent &event)
{
    wxString foo = wxT("Well, that's decided then. She's called the ")+shipnamectrl->GetValue()+wxT(".");
    wxLogMessage(foo);
    shipnamebutton->Disable();
}

wxString GameWindow::GenerateShipyardText(int sel)
{
    string desc(shipstats[sel].description.mb_str());
    string other[10];
    for (int x=0;x<10;x++)
    {
        other[x] = string(shipstats[sel].otherattribs[x].mb_str());
    }
    stringstream ss;
    ss<<desc<<endl<<endl<<"Class: "<<shipstats[sel].logname<<"\nHull Rating: "<<shipstats[sel].hull<<"\nSpeed Rating: "<<shipstats[sel].speed;
    ss<<"\nMin Crew: "<<shipstats[sel].mincrew<<"\nMax Crew: "<<shipstats[sel].maxcrew<<"\nCargo Hold: "<<shipstats[sel].cargohold;
//    ss<<"\nCargo Per Unused Crew Slot: "<<shipstats[sel].cargopercrew<<
    ss<<"\nMax Cannons: "<<shipstats[sel].cannons<<"\nMax Missiles: "<<shipstats[sel].missiles;
    ss<<"\nOther Attributes: ";
    for (int x=0;x<shipstats[sel].numothers;x++)
    {
        ss<<endl<<other[x];
    }
    wxString ret(ss.str().c_str(),wxConvUTF8);
    return ret;
}
