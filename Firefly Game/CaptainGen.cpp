#include "Includes.h"
#include "wxStuff.h"

void GameWindow::CreateFirstCaptainControl()
{
    captainpanel = new wxPanel(mainbook,-1);
    
    captainvbox = new wxBoxSizer(wxVERTICAL);
    
    name = new wxTextCtrl(captainpanel,-1,wxT("Malcolm Reynolds"));
    gender = new wxChoice(captainpanel,-1);
    age = new wxChoice(captainpanel,-1);
    hair = new wxChoice(captainpanel,-1);
    eyes = new wxChoice(captainpanel,-1);

    nametext = new wxStaticText(captainpanel,-1,wxT("Name: "));
    agetext = new wxStaticText(captainpanel,-1,wxT("Age: "));
    gendertext = new wxStaticText(captainpanel,-1,wxT("Gender: "));
    hairtext = new wxStaticText(captainpanel,-1,wxT("Hair Colour: "));
    eyestext = new wxStaticText(captainpanel,-1,wxT("Eye Colour: "));

    captainadvance = new wxButton(captainpanel,ID_CAPTAINADVANCE,wxT("Looks good"));
    
    gender->Append(wxT("Male"));
    gender->Append(wxT("Female"));

    hair->Append(wxT("Black"));
    hair->Append(wxT("Brown"));
    hair->Append(wxT("Blonde"));
    hair->Append(wxT("Ginger"));
    hair->Append(wxT("Grey"));
    hair->Append(wxT("Bald"));

    eyes->Append(wxT("Blue"));
    eyes->Append(wxT("Green"));
    eyes->Append(wxT("Grey"));
    eyes->Append(wxT("Brown"));

    gender->SetSelection(0);
    hair->SetSelection(1);
    eyes->SetSelection(0);

    for (int x=0;x<=35;x++)
    {
        stringstream ss;
        ss<<20+x;
        wxString foo(ss.str().c_str(),wxConvUTF8);
        age->Append(foo);
    }

    age->SetSelection(16);

    captainfirstvbox = new wxBoxSizer(wxVERTICAL);
    captainfirsthbox1 = new wxBoxSizer(wxHORIZONTAL);
    captainfirsthbox2 = new wxBoxSizer(wxHORIZONTAL);
    captainfirsthbox3 = new wxBoxSizer(wxHORIZONTAL);
    captainfirsthbox4 = new wxBoxSizer(wxHORIZONTAL);
    captainfirsthbox5 = new wxBoxSizer(wxHORIZONTAL);

    captainfirsthbox1->Add(nametext,0,wxALL|wxEXPAND,5);
    captainfirsthbox1->Add(name,1,wxALL|wxEXPAND,5);
    captainfirsthbox2->Add(gendertext,0,wxALL|wxEXPAND,5);
    captainfirsthbox2->Add(gender,1,wxALL|wxEXPAND,5);
    captainfirsthbox3->Add(agetext,0,wxALL|wxEXPAND,5);
    captainfirsthbox3->Add(age,1,wxALL|wxEXPAND,5);
    captainfirsthbox4->Add(hairtext,0,wxALL|wxEXPAND,5);
    captainfirsthbox4->Add(hair,1,wxALL|wxEXPAND,5);
    captainfirsthbox5->Add(eyestext,0,wxALL|wxEXPAND,5);
    captainfirsthbox5->Add(eyes,1,wxALL|wxEXPAND,5);

    captainfirstvbox->Add(captainfirsthbox1,2,wxALL|wxEXPAND,5);
    captainfirstvbox->Add(captainfirsthbox2,2,wxALL|wxEXPAND,5);
    captainfirstvbox->Add(captainfirsthbox3,2,wxALL|wxEXPAND,5);
    captainfirstvbox->Add(captainfirsthbox4,2,wxALL|wxEXPAND,5);
    captainfirstvbox->Add(captainfirsthbox5,2,wxALL|wxEXPAND,5);
    captainfirstvbox->Add(captainadvance,0,wxALL|wxEXPAND,5);
    
    captainvbox->Add(captainfirstvbox,5,wxALL|wxEXPAND,5);

    captainpanel->SetSizer(captainvbox);

    mainbook->AddPage(captainpanel,wxT("Character Creation"),false,-1);
}

void GameWindow::CreateCaptainControls()
{

    
    dice[0].LoadFile(wxT("Data\\Images\\Gen\\Dice64.png"),wxBITMAP_TYPE_PNG);
    dice[1].LoadFile(wxT("Data\\Images\\Gen\\Dice128.png"),wxBITMAP_TYPE_PNG);
    money[0].LoadFile(wxT("Data\\Images\\Gen\\Money64.png"),wxBITMAP_TYPE_PNG);
    money[1].LoadFile(wxT("Data\\Images\\Gen\\Money128.png"),wxBITMAP_TYPE_PNG);
    ship[0].LoadFile(wxT("Data\\Images\\Gen\\Ship64.png"),wxBITMAP_TYPE_PNG);
    ship[1].LoadFile(wxT("Data\\Images\\Gen\\Ship128.png"),wxBITMAP_TYPE_PNG);
    friends[0].LoadFile(wxT("Data\\Images\\Gen\\Friends64.png"),wxBITMAP_TYPE_PNG);
    friends[1].LoadFile(wxT("Data\\Images\\Gen\\Friends128.png"),wxBITMAP_TYPE_PNG);
    
    criminal[0].LoadFile(wxT("Data\\Images\\Gen\\criminal64.png"),wxBITMAP_TYPE_PNG);
    criminal[1].LoadFile(wxT("Data\\Images\\Gen\\criminal128.png"),wxBITMAP_TYPE_PNG);
    shepherd[0].LoadFile(wxT("Data\\Images\\Gen\\shepherd64.png"),wxBITMAP_TYPE_PNG);
    shepherd[1].LoadFile(wxT("Data\\Images\\Gen\\shepherd128.png"),wxBITMAP_TYPE_PNG);
    companion[0].LoadFile(wxT("Data\\Images\\Gen\\companion64.png"),wxBITMAP_TYPE_PNG);
    companion[1].LoadFile(wxT("Data\\Images\\Gen\\companion128.png"),wxBITMAP_TYPE_PNG);
    jack[0].LoadFile(wxT("Data\\Images\\Gen\\jack64.png"),wxBITMAP_TYPE_PNG);
    jack[1].LoadFile(wxT("Data\\Images\\Gen\\jack128.png"),wxBITMAP_TYPE_PNG);
    trader[0].LoadFile(wxT("Data\\Images\\Gen\\trader64.png"),wxBITMAP_TYPE_PNG);
    trader[1].LoadFile(wxT("Data\\Images\\Gen\\trader128.png"),wxBITMAP_TYPE_PNG);
    soldier[0].LoadFile(wxT("Data\\Images\\Gen\\soldier64.png"),wxBITMAP_TYPE_PNG);
    soldier[1].LoadFile(wxT("Data\\Images\\Gen\\soldier128.png"),wxBITMAP_TYPE_PNG);
    
    allianceflag[0].LoadFile(wxT("Data\\Images\\Gen\\alliance64.png"),wxBITMAP_TYPE_PNG);
    allianceflag[1].LoadFile(wxT("Data\\Images\\Gen\\alliance128.png"),wxBITMAP_TYPE_PNG);
    indepsflag[0].LoadFile(wxT("Data\\Images\\Gen\\indeps64.png"),wxBITMAP_TYPE_PNG);
    indepsflag[1].LoadFile(wxT("Data\\Images\\Gen\\indeps128.png"),wxBITMAP_TYPE_PNG);
    neutralflag[0].LoadFile(wxT("Data\\Images\\Gen\\neutral64.png"),wxBITMAP_TYPE_PNG);
    neutralflag[1].LoadFile(wxT("Data\\Images\\Gen\\neutral128.png"),wxBITMAP_TYPE_PNG);
    
    perk1[0] = locked64;
    perk1[1] = locked128;
    perk2[0] = locked64;
    perk2[1] = locked128;
    perk3[0] = locked64;
    perk3[1] = locked128;
    perk4[0] = locked64;
    perk4[1] = locked128;
    perk5[0] = locked64;
    perk5[1] = locked128;
    perk6[0] = locked64;
    perk6[1] = locked128;
    
    perka = new wxBitmapButton(captainpanel,ID_PERKA,perk1[0]);
    perkb = new wxBitmapButton(captainpanel,ID_PERKB,perk2[0]);
    perkc = new wxBitmapButton(captainpanel,ID_PERKC,perk3[0]);
    perkd = new wxBitmapButton(captainpanel,ID_PERKD,perk4[0]);
    perke = new wxBitmapButton(captainpanel,ID_PERKE,perk5[0]);
    perkf = new wxBitmapButton(captainpanel,ID_PERKF,perk6[0]);
    perka->Show(false);
    perkb->Show(false);
    perkc->Show(false);
    perkd->Show(false);
    perke->Show(false);
    perkf->Show(false);
    perktexta = new wxStaticText(captainpanel,-1,wxT("Perk 1"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    perktextb = new wxStaticText(captainpanel,-1,wxT("Perk 2"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    perktextc = new wxStaticText(captainpanel,-1,wxT("Perk 3"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    perktextd = new wxStaticText(captainpanel,-1,wxT("Perk 4"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    perktexte = new wxStaticText(captainpanel,-1,wxT("Perk 5"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    perktextf = new wxStaticText(captainpanel,-1,wxT("Perk 6"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    perktexta->Show(false);
    perktextb->Show(false);
    perktextc->Show(false);
    perktextd->Show(false);
    perktexte->Show(false);
    perktextf->Show(false);
    perkadvancea = new wxButton(captainpanel,ID_ADVANCEPERKA,wxT("That's me"));
    perkadvanceb = new wxButton(captainpanel,ID_ADVANCEPERKB,wxT("That's me"));
    perkadvancec = new wxButton(captainpanel,ID_ADVANCEPERKC,wxT("That's me"));
    perkadvanced = new wxButton(captainpanel,ID_ADVANCEPERKD,wxT("That's me"));
    perkadvancee = new wxButton(captainpanel,ID_ADVANCEPERKE,wxT("That's me"));
    perkadvancef = new wxButton(captainpanel,ID_ADVANCEPERKF,wxT("That's me"));
    perkadvancea->Show(false);
    perkadvanceb->Show(false);
    perkadvancec->Show(false);
    perkadvanced->Show(false);
    perkadvancee->Show(false);
    perkadvancef->Show(false);
    perkbmp = new wxBitmapButton(captainpanel,ID_PERKBACK,wxNullBitmap);
    perkdesc = new wxTextCtrl(captainpanel,-1,wxT("Foo"),wxDefaultPosition,wxDefaultSize,wxTE_READONLY|wxTE_MULTILINE,wxDefaultValidator,wxT(""));
    perkbmp->SetBitmapHover(back);
    perkbmp->Show(false);
    perkdesc->Show(false);
    
    joba = new wxBitmapButton(captainpanel,ID_JOBA,soldier[0]);
    jobb = new wxBitmapButton(captainpanel,ID_JOBB,companion[0]);
    jobc = new wxBitmapButton(captainpanel,ID_JOBC,trader[0]);
    jobd = new wxBitmapButton(captainpanel,ID_JOBD,criminal[0]);
    jobe = new wxBitmapButton(captainpanel,ID_JOBE,shepherd[0]);
    jobf = new wxBitmapButton(captainpanel,ID_JOBF,jack[0]);
    joba->Show(false);
    jobb->Show(false);
    jobc->Show(false);
    jobd->Show(false);
    jobe->Show(false);
    jobf->Show(false); 
    jobadvancea = new wxButton(captainpanel,ID_ADVANCEJOBA,wxT("That was me"));
    jobadvanceb = new wxButton(captainpanel,ID_ADVANCEJOBB,wxT("That was me"));
    jobadvancec = new wxButton(captainpanel,ID_ADVANCEJOBC,wxT("That was me"));
    jobadvanced = new wxButton(captainpanel,ID_ADVANCEJOBD,wxT("That was me"));
    jobadvancee = new wxButton(captainpanel,ID_ADVANCEJOBE,wxT("That was me"));
    jobadvancef = new wxButton(captainpanel,ID_ADVANCEJOBF,wxT("That was me"));
    jobadvancea->Show(false);
    jobadvanceb->Show(false);
    jobadvancec->Show(false);
    jobadvanced->Show(false);
    jobadvancee->Show(false);
    jobadvancef->Show(false);
    jobbmp = new wxBitmapButton(captainpanel,ID_BACKJOB,wxNullBitmap);
    jobdesc = new wxTextCtrl(captainpanel,-1,wxT("Foo"),wxDefaultPosition,wxDefaultSize,wxTE_READONLY|wxTE_MULTILINE,wxDefaultValidator,wxT(""));
    jobbmp->SetBitmapHover(back);
    jobbmp->Show(false);
    jobdesc->Show(false); 
    jobtexta = new wxStaticText(captainpanel,-1,wxT("Soldier"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    jobtextb = new wxStaticText(captainpanel,-1,wxT("Companion"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    jobtextc = new wxStaticText(captainpanel,-1,wxT("Trader"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    jobtextd = new wxStaticText(captainpanel,-1,wxT("Criminal"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    jobtexte = new wxStaticText(captainpanel,-1,wxT("Shepherd"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    jobtextf = new wxStaticText(captainpanel,-1,wxT("Jack of All Trades"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    jobtexta->Show(false);
    jobtextb->Show(false);
    jobtextc->Show(false);
    jobtextd->Show(false);
    jobtexte->Show(false);
    jobtextf->Show(false); 
    
    backgrounda = new wxBitmapButton(captainpanel,ID_BACKGROUNDA,money[0]);
    backgroundb = new wxBitmapButton(captainpanel,ID_BACKGROUNDB,dice[0]);
    backgroundc = new wxBitmapButton(captainpanel,ID_BACKGROUNDC,friends[0]);
    backgroundd = new wxBitmapButton(captainpanel,ID_BACKGROUNDD,ship[0]);
    backgrounde = new wxBitmapButton(captainpanel,ID_BACKGROUNDE,locked64);
    backgroundf = new wxBitmapButton(captainpanel,ID_BACKGROUNDF,locked64);
    
    backtexta = new wxStaticText(captainpanel,-1,wxT("New Start"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    backtextb = new wxStaticText(captainpanel,-1,wxT("Lucky Roll"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    backtextc = new wxStaticText(captainpanel,-1,wxT("Helping Hands"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    backtextd = new wxStaticText(captainpanel,-1,wxT("Sole Inheritance"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    backtexte = new wxStaticText(captainpanel,-1,wxT("Locked"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    backtextf = new wxStaticText(captainpanel,-1,wxT("Locked"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    
    alliance = new wxBitmapButton(captainpanel,ID_ALLEGIANCEA,allianceflag[0]);
    indeps = new wxBitmapButton(captainpanel,ID_ALLEGIANCEI,indepsflag[0]);
    neutral = new wxBitmapButton(captainpanel,ID_ALLEGIANCEN,neutralflag[0]);
    allegiancebmp = new wxBitmapButton(captainpanel,ID_ALLEGIANCEBACK,wxNullBitmap);
    allegiancebmp->SetBitmapHover(back);
    allegiancedesc = new wxTextCtrl(captainpanel,-1,wxT("Foo"),wxDefaultPosition,wxDefaultSize,wxTE_READONLY|wxTE_MULTILINE,wxDefaultValidator,wxT(""));
    allegianceadvancea = new wxButton(captainpanel,ID_ALLEGIANCEADVANCEA,wxT("That was me"));
    allegianceadvancei = new wxButton(captainpanel,ID_ALLEGIANCEADVANCEI,wxT("That was me"));
    allegianceadvancen = new wxButton(captainpanel,ID_ALLEGIANCEADVANCEN,wxT("That was me"));
    alliancetext = new wxStaticText(captainpanel,-1,wxT("Alliance"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    indepstext = new wxStaticText(captainpanel,-1,wxT("Independents"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    neutraltext = new wxStaticText(captainpanel,-1,wxT("Neutral"),wxDefaultPosition,wxDefaultSize,wxALIGN_CENTRE,wxT(""));
    allegianceadvancea->Show(false);
    allegianceadvancei->Show(false);
    allegianceadvancen->Show(false);
    allegiancebmp->Show(false);
    allegiancedesc->Show(false);
    alliance->Show(false);
    indeps->Show(false);
    neutral->Show(false);
    alliancetext->Show(false);
    indepstext->Show(false);
    neutraltext->Show(false);
    
    pathbmp = new wxBitmapButton(captainpanel,ID_BACKGROUND_BACK,wxNullBitmap);
    pathdesc = new wxTextCtrl(captainpanel,-1,wxT("Foo"),wxDefaultPosition,wxDefaultSize,wxTE_READONLY|wxTE_MULTILINE,wxDefaultValidator,wxT(""));
    pathbmp->Show(false);
    pathdesc->Show(false);
    pathbmp->SetBitmapHover(back);
    
    backgroundadvancea = new wxButton(captainpanel,ID_BACKGROUNDADVANCEA,wxT("That's how I got my cash!"));
    backgroundadvanceb = new wxButton(captainpanel,ID_BACKGROUNDADVANCEB,wxT("That's how I got my cash!"));
    backgroundadvancec = new wxButton(captainpanel,ID_BACKGROUNDADVANCEC,wxT("That's how I got my cash!"));
    backgroundadvanced = new wxButton(captainpanel,ID_BACKGROUNDADVANCED,wxT("That's how I got my cash!"));
    backgroundadvancee = new wxButton(captainpanel,ID_BACKGROUNDADVANCEE,wxT("That's how I got my cash!"));
    backgroundadvancef = new wxButton(captainpanel,ID_BACKGROUNDADVANCEF,wxT("That's how I got my cash!"));
    backgroundadvancea->Show(false);
    backgroundadvanceb->Show(false);
    backgroundadvancec->Show(false);
    backgroundadvanced->Show(false);
    backgroundadvancee->Show(false);
    backgroundadvancef->Show(false);
    
    captainbacksizera = new wxBoxSizer(wxVERTICAL);
    captainbacksizerb = new wxBoxSizer(wxVERTICAL);
    captainbacksizerc = new wxBoxSizer(wxVERTICAL);
    captainbacksizerd = new wxBoxSizer(wxVERTICAL);
    captainbacksizere = new wxBoxSizer(wxVERTICAL);
    captainbacksizerf = new wxBoxSizer(wxVERTICAL);
    
    alliancesizer = new wxBoxSizer(wxVERTICAL);
    indepssizer = new wxBoxSizer(wxVERTICAL);
    neutralsizer = new wxBoxSizer(wxVERTICAL);
    
    jobsizera = new wxBoxSizer(wxVERTICAL);
    jobsizerb = new wxBoxSizer(wxVERTICAL);
    jobsizerc = new wxBoxSizer(wxVERTICAL);
    jobsizerd = new wxBoxSizer(wxVERTICAL);
    jobsizere = new wxBoxSizer(wxVERTICAL);
    jobsizerf = new wxBoxSizer(wxVERTICAL);
    
    perksizera = new wxBoxSizer(wxVERTICAL);
    perksizerb = new wxBoxSizer(wxVERTICAL);
    perksizerc = new wxBoxSizer(wxVERTICAL);
    perksizerd = new wxBoxSizer(wxVERTICAL);
    perksizere = new wxBoxSizer(wxVERTICAL);
    perksizerf = new wxBoxSizer(wxVERTICAL);
    
    captaingsizer = new wxGridSizer(3,2,5,5);
    jobgsizer = new wxGridSizer(3,2,5,5);
    perkgsizer = new wxGridSizer(3,2,5,5);
    
    perksizera->Add(perka,1,wxALL|wxEXPAND,5);
    perksizera->Add(perktexta,0,wxALL|wxEXPAND,5);
    perksizerb->Add(perkb,1,wxALL|wxEXPAND,5);
    perksizerb->Add(perktextb,0,wxALL|wxEXPAND,5);
    perksizerc->Add(perkc,1,wxALL|wxEXPAND,5);
    perksizerc->Add(perktextc,0,wxALL|wxEXPAND,5);
    perksizerd->Add(perkd,1,wxALL|wxEXPAND,5);
    perksizerd->Add(perktextd,0,wxALL|wxEXPAND,5);
    perksizere->Add(perke,1,wxALL|wxEXPAND,5);
    perksizere->Add(perktexte,0,wxALL|wxEXPAND,5);
    perksizerf->Add(perkf,1,wxALL|wxEXPAND,5);
    perksizerf->Add(perktextf,0,wxALL|wxEXPAND,5);
    perkgsizer->Add(perksizera,2,wxALL|wxEXPAND,5);
    perkgsizer->Add(perksizerb,2,wxALL|wxEXPAND,5);
    perkgsizer->Add(perksizerc,2,wxALL|wxEXPAND,5);
    perkgsizer->Add(perksizerd,2,wxALL|wxEXPAND,5);
    perkgsizer->Add(perksizere,2,wxALL|wxEXPAND,5);
    perkgsizer->Add(perksizerf,2,wxALL|wxEXPAND,5);
    
    jobsizera->Add(joba,1,wxALL|wxEXPAND,5);
    jobsizera->Add(jobtexta,0,wxALL|wxEXPAND,5);
    jobsizerb->Add(jobb,1,wxALL|wxEXPAND,5);
    jobsizerb->Add(jobtextb,0,wxALL|wxEXPAND,5);
    jobsizerc->Add(jobc,1,wxALL|wxEXPAND,5);
    jobsizerc->Add(jobtextc,0,wxALL|wxEXPAND,5);
    jobsizerd->Add(jobd,1,wxALL|wxEXPAND,5);
    jobsizerd->Add(jobtextd,0,wxALL|wxEXPAND,5);
    jobsizere->Add(jobe,1,wxALL|wxEXPAND,5);
    jobsizere->Add(jobtexte,0,wxALL|wxEXPAND,5);
    jobsizerf->Add(jobf,1,wxALL|wxEXPAND,5);
    jobsizerf->Add(jobtextf,0,wxALL|wxEXPAND,5);
    jobgsizer->Add(jobsizera,2,wxALL|wxEXPAND,5);
    jobgsizer->Add(jobsizerb,2,wxALL|wxEXPAND,5);
    jobgsizer->Add(jobsizerc,2,wxALL|wxEXPAND,5);
    jobgsizer->Add(jobsizerd,2,wxALL|wxEXPAND,5);
    jobgsizer->Add(jobsizere,2,wxALL|wxEXPAND,5);
    jobgsizer->Add(jobsizerf,2,wxALL|wxEXPAND,5);
    
    alliancesizer->Add(alliance,1,wxALL|wxEXPAND,5);
    alliancesizer->Add(alliancetext,0,wxALL|wxEXPAND,5);
    indepssizer->Add(indeps,1,wxALL|wxEXPAND,5);
    indepssizer->Add(indepstext,0,wxALL|wxEXPAND,5);
    neutralsizer->Add(neutral,1,wxALL|wxEXPAND,5);
    neutralsizer->Add(neutraltext,0,wxALL|wxEXPAND,5);

    captainbacksizera->Add(backgrounda,1,wxALL|wxEXPAND,1);
    captainbacksizera->Add(backtexta,0,wxALL|wxEXPAND,1);
    captainbacksizerb->Add(backgroundb,1,wxALL|wxEXPAND,1);
    captainbacksizerb->Add(backtextb,0,wxALL|wxEXPAND,1);
    captainbacksizerc->Add(backgroundc,1,wxALL|wxEXPAND,1);
    captainbacksizerc->Add(backtextc,0,wxALL|wxEXPAND,1);
    captainbacksizerd->Add(backgroundd,1,wxALL|wxEXPAND,1);
    captainbacksizerd->Add(backtextd,0,wxALL|wxEXPAND,1);
    captainbacksizere->Add(backgrounde,1,wxALL|wxEXPAND,1);
    captainbacksizere->Add(backtexte,0,wxALL|wxEXPAND,1);
    captainbacksizerf->Add(backgroundf,1,wxALL|wxEXPAND,1);
    captainbacksizerf->Add(backtextf,0,wxALL|wxEXPAND,1);
    
    captaingsizer->Add(captainbacksizera,2,wxALL|wxEXPAND,5);
    captaingsizer->Add(captainbacksizerb,2,wxALL|wxEXPAND,5);
    captaingsizer->Add(captainbacksizerc,2,wxALL|wxEXPAND,5);
    captaingsizer->Add(captainbacksizerd,2,wxALL|wxEXPAND,5);
    captaingsizer->Add(captainbacksizere,2,wxALL|wxEXPAND,5);
    captaingsizer->Add(captainbacksizerf,2,wxALL|wxEXPAND,5);
    
    captainvbox->Add(perkgsizer,6,wxALL|wxEXPAND,5);
    captainvbox->Add(perkbmp,1,wxALL|wxEXPAND,5);
    captainvbox->Add(perkdesc,1,wxALL|wxEXPAND,5);
    captainvbox->Add(perkadvancea,0,wxALL|wxEXPAND,5);
    captainvbox->Add(perkadvanceb,0,wxALL|wxEXPAND,5);
    captainvbox->Add(perkadvancec,0,wxALL|wxEXPAND,5);
    captainvbox->Add(perkadvanced,0,wxALL|wxEXPAND,5);
    captainvbox->Add(perkadvancee,0,wxALL|wxEXPAND,5);
    captainvbox->Add(perkadvancef,0,wxALL|wxEXPAND,5);
    captainvbox->Add(jobgsizer,6,wxALL|wxEXPAND,5);
    captainvbox->Add(jobbmp,1,wxALL|wxEXPAND,5);
    captainvbox->Add(jobdesc,1,wxALL|wxEXPAND,5);
    captainvbox->Add(jobadvancea,0,wxALL|wxEXPAND,5);
    captainvbox->Add(jobadvanceb,0,wxALL|wxEXPAND,5);
    captainvbox->Add(jobadvancec,0,wxALL|wxEXPAND,5);
    captainvbox->Add(jobadvanced,0,wxALL|wxEXPAND,5);
    captainvbox->Add(jobadvancee,0,wxALL|wxEXPAND,5);
    captainvbox->Add(jobadvancef,0,wxALL|wxEXPAND,5);
    captainvbox->Add(allegiancebmp,1,wxALL|wxEXPAND,5);
    captainvbox->Add(allegiancedesc,1,wxALL|wxEXPAND,5);
    captainvbox->Add(allegianceadvancea,0,wxALL|wxEXPAND,5);
    captainvbox->Add(allegianceadvancei,0,wxALL|wxEXPAND,5);
    captainvbox->Add(allegianceadvancen,0,wxALL|wxEXPAND,5);
    captainvbox->Add(alliancesizer,2,wxALL|wxEXPAND,5);
    captainvbox->Add(indepssizer,2,wxALL|wxEXPAND,5);
    captainvbox->Add(neutralsizer,2,wxALL|wxEXPAND,5);
    captainvbox->Add(pathbmp,1,wxALL|wxEXPAND,5);
    captainvbox->Add(pathdesc,1,wxALL|wxEXPAND,5);
    captainvbox->Add(backgroundadvancea,0,wxALL|wxEXPAND,5);
    captainvbox->Add(backgroundadvanceb,0,wxALL|wxEXPAND,5);
    captainvbox->Add(backgroundadvancec,0,wxALL|wxEXPAND,5);
    captainvbox->Add(backgroundadvanced,0,wxALL|wxEXPAND,5);
    captainvbox->Add(backgroundadvancee,0,wxALL|wxEXPAND,5);
    captainvbox->Add(backgroundadvancef,0,wxALL|wxEXPAND,5);
    captainvbox->Add(captaingsizer,6,wxALL|wxEXPAND,5);
    
    backgrounda->Show(false);
    backgroundb->Show(false);
    backgroundc->Show(false);
    backgroundd->Show(false);
    backgrounde->Show(false);
    backgroundf->Show(false);
    backtexta->Show(false);
    backtextb->Show(false);
    backtextc->Show(false);
    backtextd->Show(false);
    backtexte->Show(false);
    backtextf->Show(false);
}

void GameWindow::BackgroundA(wxCommandEvent &event)
{
    backgrounda->Show(false);
    backgroundb->Show(false);
    backgroundc->Show(false);
    backgroundd->Show(false);
    backgrounde->Show(false);
    backgroundf->Show(false);
    backtexta->Show(false);
    backtextb->Show(false);
    backtextc->Show(false);
    backtextd->Show(false);
    backtexte->Show(false);
    backtextf->Show(false);
    pathdesc->ChangeValue(wxT(""));
    pathdesc->WriteText(wxT("I left for a new start out in the 'verse, selling off or just leaving behind most pieces of the life I'd led before. A man can be anything he chooses when he starts over - miner, soldier, preacher... even Cap'n of a ship, if he has the coin.  That's the plan. Find a ship, find a crew, find work.  Maybe, just maybe, find some peace of mind. All of my worldly goods been replaced by one softly clinking pouch - I ought to have just barely the coin to make it happen."));
    pathdesc->Show(true);
    pathbmp->SetBitmapLabel(money[1]);
    pathbmp->Show(true);
    backgroundadvancea->Show(true);
    captainvbox->Layout();
}

void GameWindow::BackgroundB(wxCommandEvent &event)
{
    backgrounda->Show(false);
    backgroundb->Show(false);
    backgroundc->Show(false);
    backgroundd->Show(false);
    backgrounde->Show(false);
    backgroundf->Show(false);
    backtexta->Show(false);
    backtextb->Show(false);
    backtextc->Show(false);
    backtextd->Show(false);
    backtexte->Show(false);
    backtextf->Show(false);
    pathdesc->ChangeValue(wxT(""));
    pathdesc->WriteText(wxT("It ain't often that the deed to a ship gets wagered. I'd been on a right streak of lucky though, and ended up with a whole pile of the man's money in the most honest of fashions. The stupid sah gwa couldn't let it go, reachin' for the last thing he had - but when the chips were down, my luck stayed sweet on me. The hottest night of my life ended up with a ship's deed in my hand and a 'Cap'n' in front of my name."));
    pathdesc->Show(true);
    pathbmp->SetBitmapLabel(dice[1]);
    pathbmp->Show(true);
    backgroundadvanceb->Show(true);
    captainvbox->Layout();
}

void GameWindow::BackgroundC(wxCommandEvent &event)
{
    backgrounda->Show(false);
    backgroundb->Show(false);
    backgroundc->Show(false);
    backgroundd->Show(false);
    backgrounde->Show(false);
    backgroundf->Show(false);
    backtexta->Show(false);
    backtextb->Show(false);
    backtextc->Show(false);
    backtextd->Show(false);
    backtexte->Show(false);
    backtextf->Show(false);
    pathdesc->ChangeValue(wxT(""));
    pathdesc->WriteText(wxT("I've somehow managed to come up with no small number of people who know me and don't feel much inclined to kill me. A few even had the notion to not laugh in my face when I asked on borrowing coin to buy a ship.  Still, I had to meet some folk I'd have rather not before I had enough in the way of credits to call a ship my own.  Did it though, my name on the deed to prove it, but no time for lollygaggin' - even the best of those friends will be wanting their money back sooner than later..."));
    pathdesc->Show(true);
    pathbmp->SetBitmapLabel(friends[1]);
    pathbmp->Show(true);
    backgroundadvancec->Show(true);
    captainvbox->Layout();
}

void GameWindow::BackgroundD(wxCommandEvent &event)
{
    backgrounda->Show(false);
    backgroundb->Show(false);
    backgroundc->Show(false);
    backgroundd->Show(false);
    backgrounde->Show(false);
    backgroundf->Show(false);
    backtexta->Show(false);
    backtextb->Show(false);
    backtextc->Show(false);
    backtextd->Show(false);
    backtexte->Show(false);
    backtextf->Show(false);
    pathdesc->ChangeValue(wxT(""));
    pathdesc->WriteText(wxT("I'd always expected to one day be Cap'n of my father's ship, when it was time, but it happened sooner than I'd ever hoped. Not in a way that's healthy to think on, neither. Dwell on that overmuch though, and I'm liable end up in the bughouse - or worse, on the drift. Can't let the crew be getting wrong notions, now. I'm their new Cap'n, even if I'm not the old hand Pa was. Might be just a greenhorn, but Pa taught me the most important bit like it were carved into my bones.\n\nKeep flying."));
    pathdesc->Show(true);
    pathbmp->SetBitmapLabel(ship[1]);
    pathbmp->Show(true);
    backgroundadvanced->Show(true);
    captainvbox->Layout();
}

void GameWindow::BackgroundE(wxCommandEvent &event)
{
    backgrounda->Show(false);
    backgroundb->Show(false);
    backgroundc->Show(false);
    backgroundd->Show(false);
    backgrounde->Show(false);
    backgroundf->Show(false);
    backtexta->Show(false);
    backtextb->Show(false);
    backtextc->Show(false);
    backtextd->Show(false);
    backtexte->Show(false);
    backtextf->Show(false);
    pathdesc->ChangeValue(wxT(""));
    pathdesc->WriteText(wxT("Not Available."));
    pathdesc->Show(true);
    pathbmp->SetBitmapLabel(locked128);
    pathbmp->Show(true);
    backgroundadvancee->Show(true);
    backgroundadvancee->Disable();
    captainvbox->Layout();
}

void GameWindow::BackgroundF(wxCommandEvent &event)
{
    backgrounda->Show(false);
    backgroundb->Show(false);
    backgroundc->Show(false);
    backgroundd->Show(false);
    backgrounde->Show(false);
    backgroundf->Show(false);
    backtexta->Show(false);
    backtextb->Show(false);
    backtextc->Show(false);
    backtextd->Show(false);
    backtexte->Show(false);
    backtextf->Show(false);
    pathdesc->ChangeValue(wxT(""));
    pathdesc->WriteText(wxT("Not Available."));
    pathdesc->Show(true);
    pathbmp->SetBitmapLabel(locked128);
    pathbmp->Show(true);
    backgroundadvancef->Show(true);
    backgroundadvancef->Disable();
    captainvbox->Layout();
}

void GameWindow::RestoreBackgrounds(wxCommandEvent &event)
{
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    backgroundadvancea->Show(false);
    backgroundadvanceb->Show(false);
    backgroundadvancec->Show(false);
    backgroundadvanced->Show(false);
    backgroundadvancee->Show(false);
    backgroundadvancef->Show(false);
    pathdesc->Show(false);
    pathbmp->Show(false);
}

void GameWindow::AdvanceCaptain(wxCommandEvent &event)
{
    name->Show(false);
    nametext->Show(false);
    gender->Show(false);
    gendertext->Show(false);
    age->Show(false);
    agetext->Show(false);
    hair->Show(false);
    hairtext->Show(false);
    eyes->Show(false);
    eyestext->Show(false); 
    captainadvance->Show(false);
    
    alliance->Show(true);
    indeps->Show(true);
    neutral->Show(true);
    alliancetext->Show(true);
    indepstext->Show(true);
    neutraltext->Show(true);
    captainvbox->Layout();
    stringstream ss;
    ss<<"Name: Captain "<<(name->GetValue()).mb_str();
    ss<<"\nGender - "<<(gender->GetString(gender->GetSelection())).mb_str();
    ss<<"\nAge - "<<(age->GetString(age->GetSelection())).mb_str();
    ss<<"\nHair Colour - "<<(hair->GetString(hair->GetSelection())).mb_str();
    ss<<"\nEye Colour - "<<(eyes->GetString(eyes->GetSelection())).mb_str();
    wxString foo(ss.str().c_str(),wxConvUTF8);
    wxLogMessage(foo);
}

void GameWindow::AdvanceBackgroundA(wxCommandEvent &event)
{
    wxLogMessage(wxT("Background - New Start\n"));
    stringstream ss;
    ss<<shiptime.TimeString()<<"\nStopped by the shipyard. Fat man in a suit tried to sell me on some oversized brick, but I knew my ship the moment I laid eyes on her. She needs some work, and she won't ever be winning any beauty contests, but she's something special. Reliable. I already know what I'm going to call her... got a name all picked out.";
    wxString foo(ss.str().c_str(),wxConvUTF8);
    wxLogMessage(foo);
    mainbook->DeletePage(0);
    CreateDealerControls();
}

void GameWindow::AdvanceBackgroundB(wxCommandEvent &event)
{
    wxLogMessage(wxT("Background - Lucky Roll\n"));
    stringstream ss;
    ss<<shiptime.TimeString()<<"\nGot to the docks, and the weedy excuse for an overseer wouldn't release the lock on my ship, on account he forgot which one it was. How anyone could forget a ship like this, I haven't the foggiest notion.";
    wxString foo(ss.str().c_str(),wxConvUTF8);
    wxLogMessage(foo);
    mainbook->DeletePage(0);
    CreateDealerControls();
}

void GameWindow::AdvanceBackgroundC(wxCommandEvent &event)
{
    wxLogMessage(wxT("Background - Helping Hands\n"));
    stringstream ss;
    ss<<shiptime.TimeString()<<"\nStopped by the shipyard. Fat man in a suit tried to sell me on some oversized brick, but I knew my ship the moment I laid eyes on her. She needs some work, and she won't ever be winning any beauty contests, but she's something special. Reliable. I already know what I'm going to call her... got a name all picked out.";
    wxString foo(ss.str().c_str(),wxConvUTF8);
    wxLogMessage(foo);
    mainbook->DeletePage(0);
    CreateDealerControls();
}

void GameWindow::AdvanceBackgroundD(wxCommandEvent &event)
{
    wxLogMessage(wxT("Background - Sole Inheritance\n"));
    stringstream ss;
    ss<<shiptime.TimeString()<<"\nGot to the docks, and the weedy excuse for an overseer wouldn't release the lock on my ship, on account he forgot which one it was. How anyone could forget a ship like this, I haven't the foggiest notion.";
    wxString foo(ss.str().c_str(),wxConvUTF8);
    wxLogMessage(foo);
    mainbook->DeletePage(0);
    CreateDealerControls();
}

void GameWindow::AdvanceBackgroundE(wxCommandEvent &event)
{
}

void GameWindow::AdvanceBackgroundF(wxCommandEvent &event)
{
}

void GameWindow::AllegianceA(wxCommandEvent &event)
{
    alliance->Show(false);
    indeps->Show(false);
    neutral->Show(false);
    alliancetext->Show(false);
    indepstext->Show(false);
    neutraltext->Show(false);
    allegiancebmp->Show(true);
    allegiancedesc->Show(true);
    allegianceadvancea->Show(true);
    allegiancebmp->SetBitmapLabel(allianceflag[1]);
    allegiancedesc->ChangeValue(wxT(""));
    allegiancedesc->WriteText(wxT("Loyalty. Some folks don't know the meaning of the word. Like a bunch of unruly kids, the Independents thought they'd just throw all the goodwill that the Alliance had shown back in our faces. Well, we showed those ingrates. I supported Unification then, and I support it now. The central planets are going to bring civility to these people, and eventually, maybe, they'll stop whining about it."));
    captainvbox->Layout();
}

void GameWindow::AllegianceI(wxCommandEvent &event)
{
    alliance->Show(false);
    indeps->Show(false);
    neutral->Show(false);
    alliancetext->Show(false);
    indepstext->Show(false);
    neutraltext->Show(false);
    allegiancebmp->Show(true);
    allegiancedesc->Show(true);
    allegianceadvancei->Show(true);
    allegiancebmp->SetBitmapLabel(indepsflag[1]);
    allegiancedesc->ChangeValue(wxT(""));
    allegiancedesc->WriteText(wxT("The central planets' government, the Alliance, was always trying to meddle in our affairs. Their meddling got worse and worse and finally some of us lost our stomach for it. When the Unification War broke out, I was for the side that believed a man should be able to live his life pretty much as he wants, so long as he doesn't take to harming others, with no one havin' the right to tell him what to think or how to think it. Our side was called many things, 'Independents,' 'Browncoats.' Our side lost."));
    captainvbox->Layout();
}

void GameWindow::AllegianceN(wxCommandEvent &event)
{
    alliance->Show(false);
    indeps->Show(false);
    neutral->Show(false);
    alliancetext->Show(false);
    indepstext->Show(false);
    neutraltext->Show(false);
    allegiancebmp->Show(true);
    allegiancedesc->Show(true);
    allegianceadvancen->Show(true);
    allegiancebmp->SetBitmapLabel(neutralflag[1]);
    allegiancedesc->ChangeValue(wxT(""));
    allegiancedesc->WriteText(wxT("Lotta folks got real riled up about who could boss around who. I didn't hold much truck with that. What does it matter who's calling the shots at the top? Not like any of them is better than the next. What I care about is the folks I deal with. The whole war just meant a few years where some times I had to keep my head down, some times I could see a chance to make a lot of coin if I had the notion... but sure as shooting the whole thing eventually was over, and there I was."));
    captainvbox->Layout();
}

void GameWindow::AdvanceAllegianceA(wxCommandEvent &event)
{
    allegiancebmp->Show(false);
    allegiancedesc->Show(false);
    allegianceadvancea->Show(false);
    joba->Show(true);
    jobb->Show(true);
    jobc->Show(true);
    jobd->Show(true);
    jobe->Show(true);
    jobf->Show(true);
    jobtexta->Show(true);
    jobtextb->Show(true);
    jobtextc->Show(true);
    jobtextd->Show(true);
    jobtexte->Show(true);
    jobtextf->Show(true);
    captainvbox->Layout();
    wxLogMessage(wxT("Allegiance - Alliance"));
}

void GameWindow::AdvanceAllegianceI(wxCommandEvent &event)
{
    allegiancebmp->Show(false);
    allegiancedesc->Show(false);
    allegianceadvancei->Show(false);
    joba->Show(true);
    jobb->Show(true);
    jobc->Show(true);
    jobd->Show(true);
    jobe->Show(true);
    jobf->Show(true);
    jobtexta->Show(true);
    jobtextb->Show(true);
    jobtextc->Show(true);
    jobtextd->Show(true);
    jobtexte->Show(true);
    jobtextf->Show(true);
    captainvbox->Layout();
    wxLogMessage(wxT("Allegiance - Independents"));
}

void GameWindow::AdvanceAllegianceN(wxCommandEvent &event)
{
    allegiancebmp->Show(false);
    allegiancedesc->Show(false);
    allegianceadvancen->Show(false);
    joba->Show(true);
    jobb->Show(true);
    jobc->Show(true);
    jobd->Show(true);
    jobe->Show(true);
    jobf->Show(true);
    jobtexta->Show(true);
    jobtextb->Show(true);
    jobtextc->Show(true);
    jobtextd->Show(true);
    jobtexte->Show(true);
    jobtextf->Show(true);
    captainvbox->Layout();
    wxLogMessage(wxT("Allegiance - None"));
}

void GameWindow::RestoreAllegiances(wxCommandEvent &event)
{
    allegiancebmp->Show(false);
    allegiancedesc->Show(false);
    allegianceadvancea->Show(false);
    allegianceadvancei->Show(false);
    allegianceadvancen->Show(false);
    alliance->Show(true);
    indeps->Show(true);
    neutral->Show(true);
    alliancetext->Show(true);
    indepstext->Show(true);
    neutraltext->Show(true);
    captainvbox->Layout();
}

void GameWindow::JobA(wxCommandEvent &event)
{
    joba->Show(false);
    jobb->Show(false);
    jobc->Show(false);
    jobd->Show(false);
    jobe->Show(false);
    jobf->Show(false);
    jobtexta->Show(false);
    jobtextb->Show(false);
    jobtextc->Show(false);
    jobtextd->Show(false);
    jobtexte->Show(false);
    jobtextf->Show(false);
    jobdesc->ChangeValue(wxT(""));
    jobdesc->WriteText(wxT("When the war kicked off, it didn't take long for me to get involved. Seemed like the thing to do, thought I had some notion what I was getting in to. I didn't.  Got through somehow, but it still left its mark on me. A mother's worry for her missing kid has nothing on the caring I have for where my gun is, and I can speechify for hours on the different tastes of mud.  War might be over, but some things stay with a man no matter how hard he tries to forget."));
    jobdesc->Show(true);
    jobbmp->SetBitmapLabel(soldier[1]);
    jobbmp->Show(true);
    jobadvancea->Show(true);
    captainvbox->Layout();
}

void GameWindow::JobB(wxCommandEvent &event)
{
    joba->Show(false);
    jobb->Show(false);
    jobc->Show(false);
    jobd->Show(false);
    jobe->Show(false);
    jobf->Show(false);
    jobtexta->Show(false);
    jobtextb->Show(false);
    jobtextc->Show(false);
    jobtextd->Show(false);
    jobtexte->Show(false);
    jobtextf->Show(false);
    jobdesc->ChangeValue(wxT(""));
    jobdesc->WriteText(wxT("I was once an active member of the Companion's Guild, registered and licensed. I spent my time with a significant number of the upper class, and that personal network is something that will undoubtably be of assistance when captaining a ship. If any potential crew think they're going to get 'service', however, they're in for severe disappointment."));
    jobdesc->Show(true);
    jobbmp->SetBitmapLabel(companion[1]);
    jobbmp->Show(true);
    jobadvanceb->Show(true);
    captainvbox->Layout();
}

void GameWindow::JobC(wxCommandEvent &event)
{
    joba->Show(false);
    jobb->Show(false);
    jobc->Show(false);
    jobd->Show(false);
    jobe->Show(false);
    jobf->Show(false);
    jobtexta->Show(false);
    jobtextb->Show(false);
    jobtextc->Show(false);
    jobtextd->Show(false);
    jobtexte->Show(false);
    jobtextf->Show(false);
    jobdesc->ChangeValue(wxT(""));
    jobdesc->WriteText(wxT("Not too many folks think on where the stuff they need for living came from. It came from somewhere else, mosttimes, and someone like me brought it to them. Food, meds, hammers, wobbly-headed geisha dolls, if it needed moving I was helping to bring it there. I knew the markets well, who to buy from, where and when to sell. Things happened though, and that life's just a piece of the past for me - not that it might not come in handy now and again."));
    jobdesc->Show(true);
    jobbmp->SetBitmapLabel(trader[1]);
    jobbmp->Show(true);
    jobadvancec->Show(true);
    captainvbox->Layout();
}

void GameWindow::JobD(wxCommandEvent &event)
{
    joba->Show(false);
    jobb->Show(false);
    jobc->Show(false);
    jobd->Show(false);
    jobe->Show(false);
    jobf->Show(false);
    jobtexta->Show(false);
    jobtextb->Show(false);
    jobtextc->Show(false);
    jobtextd->Show(false);
    jobtexte->Show(false);
    jobtextf->Show(false);
    jobdesc->ChangeValue(wxT(""));
    jobdesc->WriteText(wxT("I learned about the wrong side of the law when I was just a young'un. Learned all manner of different ways to do wrong by it, too. Most important to learn was how to do it and keep the law far away from me. Can't be predictable. Times are hard, and in times like these, a naughty sort like me finds no shortage of opportunity."));
    jobdesc->Show(true);
    jobbmp->SetBitmapLabel(criminal[1]);
    jobbmp->Show(true);
    jobadvanced->Show(true);
    captainvbox->Layout();
}

void GameWindow::JobE(wxCommandEvent &event)
{
    joba->Show(false);
    jobb->Show(false);
    jobc->Show(false);
    jobd->Show(false);
    jobe->Show(false);
    jobf->Show(false);
    jobtexta->Show(false);
    jobtextb->Show(false);
    jobtextc->Show(false);
    jobtextd->Show(false);
    jobtexte->Show(false);
    jobtextf->Show(false);
    jobdesc->ChangeValue(wxT(""));
    jobdesc->WriteText(wxT("Not a soul in the 'verse is born a Shepherd, they get called to it. My calling came not so many years back. The Shepherd's path is a simple one. Go out among the salt of the 'verse, help them find the way to goodness. Bring the Word to them that need it. The Shepherd's path is simple, but the road winds and curves. A Shepherd is meant to follow that path in his own way best as he is able, so long as he does not stray from righteousness while he does. I was struck by a new road on that path recently, and can only pray for success."));
    jobdesc->Show(true);
    jobbmp->SetBitmapLabel(shepherd[1]);
    jobbmp->Show(true);
    jobadvancee->Show(true);
    captainvbox->Layout();
}

void GameWindow::JobF(wxCommandEvent &event)
{
    joba->Show(false);
    jobb->Show(false);
    jobc->Show(false);
    jobd->Show(false);
    jobe->Show(false);
    jobf->Show(false);
    jobtexta->Show(false);
    jobtextb->Show(false);
    jobtextc->Show(false);
    jobtextd->Show(false);
    jobtexte->Show(false);
    jobtextf->Show(false);
    jobdesc->ChangeValue(wxT(""));
    jobdesc->WriteText(wxT("I've done well enough at whatever I turned my hand to, but I never could settle on just any one thing. Never could settle on much in life, come to think of it. As soon as things start to get regular, I start to get an itch in the back of my brainpan, and I'm off to something else. There's always work to be had though, for someone with steady hands who ain't afraid to get them dirty time to time."));
    jobdesc->Show(true);
    jobbmp->SetBitmapLabel(jack[1]);
    jobbmp->Show(true);
    jobadvancef->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvanceJobA(wxCommandEvent &event)
{
    wxLogMessage(wxT("Job - Soldier"));
    jobdesc->Show(false);
    jobbmp->Show(false);
    jobadvancea->Show(false);
    /*
    perka->Show(true);
    perkb->Show(true);
    perkc->Show(true);
    perkd->Show(true);
    perke->Show(true);
    perkf->Show(true);
    perktexta->Show(true);
    perktextb->Show(true);
    perktextc->Show(true);
    perktextd->Show(true);
    perktexte->Show(true);
    perktextf->Show(true);
*/
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvanceJobB(wxCommandEvent &event)
{
    wxLogMessage(wxT("Job - Retired Companion"));
    jobdesc->Show(false);
    jobbmp->Show(false);
    jobadvanceb->Show(false);
    /*
    perka->Show(true);
    perkb->Show(true);
    perkc->Show(true);
    perkd->Show(true);
    perke->Show(true);
    perkf->Show(true);
    perktexta->Show(true);
    perktextb->Show(true);
    perktextc->Show(true);
    perktextd->Show(true);
    perktexte->Show(true);
    perktextf->Show(true);
*/
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvanceJobC(wxCommandEvent &event)
{
    wxLogMessage(wxT("Job - Trader"));
    jobdesc->Show(false);
    jobbmp->Show(false);
    jobadvancec->Show(false);
    /*
    perka->Show(true);
    perkb->Show(true);
    perkc->Show(true);
    perkd->Show(true);
    perke->Show(true);
    perkf->Show(true);
    perktexta->Show(true);
    perktextb->Show(true);
    perktextc->Show(true);
    perktextd->Show(true);
    perktexte->Show(true);
    perktextf->Show(true);
*/
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvanceJobD(wxCommandEvent &event)
{
    wxLogMessage(wxT("Job - Criminal"));
    jobdesc->Show(false);
    jobbmp->Show(false);
    jobadvanced->Show(false);
    /*
    perka->Show(true);
    perkb->Show(true);
    perkc->Show(true);
    perkd->Show(true);
    perke->Show(true);
    perkf->Show(true);
    perktexta->Show(true);
    perktextb->Show(true);
    perktextc->Show(true);
    perktextd->Show(true);
    perktexte->Show(true);
    perktextf->Show(true);
*/

    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvanceJobE(wxCommandEvent &event)
{
    wxLogMessage(wxT("Job - Shepherd"));
    jobdesc->Show(false);
    jobbmp->Show(false);
    jobadvancee->Show(false);
    /*
    perka->Show(true);
    perkb->Show(true);
    perkc->Show(true);
    perkd->Show(true);
    perke->Show(true);
    perkf->Show(true);
    perktexta->Show(true);
    perktextb->Show(true);
    perktextc->Show(true);
    perktextd->Show(true);
    perktexte->Show(true);
    perktextf->Show(true);
*/

    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvanceJobF(wxCommandEvent &event)
{
    wxLogMessage(wxT("Job - Jack of All Trades"));
    jobdesc->Show(false);
    jobbmp->Show(false);
    jobadvancef->Show(false);
    /*
    perka->Show(true);
    perkb->Show(true);
    perkc->Show(true);
    perkd->Show(true);
    perke->Show(true);
    perkf->Show(true);
    perktexta->Show(true);
    perktextb->Show(true);
    perktextc->Show(true);
    perktextd->Show(true);
    perktexte->Show(true);
    perktextf->Show(true);
*/

    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::RestoreJobs(wxCommandEvent &event)
{
    jobdesc->Show(false);
    jobbmp->Show(false);
    jobadvancea->Show(false);
    jobadvanceb->Show(false);
    jobadvancec->Show(false);
    jobadvanced->Show(false);
    jobadvancee->Show(false);
    jobadvancef->Show(false);
    joba->Show(true);
    jobb->Show(true);
    jobc->Show(true);
    jobd->Show(true);
    jobe->Show(true);
    jobf->Show(true);
    jobtexta->Show(true);
    jobtextb->Show(true);
    jobtextc->Show(true);
    jobtextd->Show(true);
    jobtexte->Show(true);
    jobtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::PerkA(wxCommandEvent &event)
{
    perka->Show(false);
    perkb->Show(false);
    perkc->Show(false);
    perkd->Show(false);
    perke->Show(false);
    perkf->Show(false);
    perktexta->Show(false);
    perktextb->Show(false);
    perktextc->Show(false);
    perktextd->Show(false);
    perktexte->Show(false);
    perktextf->Show(false);
    perkbmp->SetBitmapLabel(perk1[1]);
    perkdesc->ChangeValue(wxT(""));
    perkdesc->WriteText(wxT(""));
    perkbmp->Show(true);
    perkdesc->Show(true);
    perkadvancea->Show(true);
    captainvbox->Layout();
}

void GameWindow::PerkB(wxCommandEvent &event)
{
    perka->Show(false);
    perkb->Show(false);
    perkc->Show(false);
    perkd->Show(false);
    perke->Show(false);
    perkf->Show(false);
    perktexta->Show(false);
    perktextb->Show(false);
    perktextc->Show(false);
    perktextd->Show(false);
    perktexte->Show(false);
    perktextf->Show(false);
    perkbmp->SetBitmapLabel(perk2[1]);
    perkdesc->ChangeValue(wxT(""));
    perkdesc->WriteText(wxT(""));
    perkbmp->Show(true);
    perkdesc->Show(true);
    perkadvanceb->Show(true);
    captainvbox->Layout();
}

void GameWindow::PerkC(wxCommandEvent &event)
{
    perka->Show(false);
    perkb->Show(false);
    perkc->Show(false);
    perkd->Show(false);
    perke->Show(false);
    perkf->Show(false);
    perktexta->Show(false);
    perktextb->Show(false);
    perktextc->Show(false);
    perktextd->Show(false);
    perktexte->Show(false);
    perktextf->Show(false);
    perkbmp->SetBitmapLabel(perk3[1]);
    perkdesc->ChangeValue(wxT(""));
    perkdesc->WriteText(wxT(""));
    perkbmp->Show(true);
    perkdesc->Show(true);
    perkadvancec->Show(true);
    captainvbox->Layout();
}

void GameWindow::PerkD(wxCommandEvent &event)
{
    perka->Show(false);
    perkb->Show(false);
    perkc->Show(false);
    perkd->Show(false);
    perke->Show(false);
    perkf->Show(false);
    perktexta->Show(false);
    perktextb->Show(false);
    perktextc->Show(false);
    perktextd->Show(false);
    perktexte->Show(false);
    perktextf->Show(false);
    perkbmp->SetBitmapLabel(perk4[1]);
    perkdesc->ChangeValue(wxT(""));
    perkdesc->WriteText(wxT(""));
    perkbmp->Show(true);
    perkdesc->Show(true);
    perkadvanced->Show(true);
    captainvbox->Layout();
}

void GameWindow::PerkE(wxCommandEvent &event)
{
    perka->Show(false);
    perkb->Show(false);
    perkc->Show(false);
    perkd->Show(false);
    perke->Show(false);
    perkf->Show(false);
    perktexta->Show(false);
    perktextb->Show(false);
    perktextc->Show(false);
    perktextd->Show(false);
    perktexte->Show(false);
    perktextf->Show(false);
    perkbmp->SetBitmapLabel(perk5[1]);
    perkdesc->ChangeValue(wxT(""));
    perkdesc->WriteText(wxT(""));
    perkbmp->Show(true);
    perkdesc->Show(true);
    perkadvancee->Show(true);
    captainvbox->Layout();
}

void GameWindow::PerkF(wxCommandEvent &event)
{
    perka->Show(false);
    perkb->Show(false);
    perkc->Show(false);
    perkd->Show(false);
    perke->Show(false);
    perkf->Show(false);
    perktexta->Show(false);
    perktextb->Show(false);
    perktextc->Show(false);
    perktextd->Show(false);
    perktexte->Show(false);
    perktextf->Show(false);
    perkbmp->SetBitmapLabel(perk6[1]);
    perkdesc->ChangeValue(wxT(""));
    perkdesc->WriteText(wxT(""));
    perkbmp->Show(true);
    perkdesc->Show(true);
    perkadvancef->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvancePerkA(wxCommandEvent &event)
{
    perkdesc->Show(false);
    perkbmp->Show(false);
    perkadvancea->Show(false);
    wxLogMessage(wxT("Perk - "));
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvancePerkB(wxCommandEvent &event)
{
    perkdesc->Show(false);
    perkbmp->Show(false);
    perkadvanceb->Show(false);
    wxLogMessage(wxT("Perk - "));
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvancePerkC(wxCommandEvent &event)
{
    perkdesc->Show(false);
    perkbmp->Show(false);
    perkadvancec->Show(false);
    wxLogMessage(wxT("Perk - "));
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvancePerkD(wxCommandEvent &event)
{
    perkdesc->Show(false);
    perkbmp->Show(false);
    perkadvanced->Show(false);
    wxLogMessage(wxT("Perk - "));
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvancePerkE(wxCommandEvent &event)
{
    perkdesc->Show(false);
    perkbmp->Show(false);
    perkadvancee->Show(false);
    wxLogMessage(wxT("Perk - "));
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::AdvancePerkF(wxCommandEvent &event)
{
    perkdesc->Show(false);
    perkbmp->Show(false);
    perkadvancef->Show(false);
    wxLogMessage(wxT("Perk - "));
    backgrounda->Show(true);
    backgroundb->Show(true);
    backgroundc->Show(true);
    backgroundd->Show(true);
    backgrounde->Show(true);
    backgroundf->Show(true);
    backtexta->Show(true);
    backtextb->Show(true);
    backtextc->Show(true);
    backtextd->Show(true);
    backtexte->Show(true);
    backtextf->Show(true);
    captainvbox->Layout();
}

void GameWindow::RestorePerks(wxCommandEvent &event)
{
    perka->Show(true);
    perkb->Show(true);
    perkc->Show(true);
    perkd->Show(true);
    perke->Show(true);
    perkf->Show(true);
    perktexta->Show(true);
    perktextb->Show(true);
    perktextc->Show(true);
    perktextd->Show(true);
    perktexte->Show(true);
    perktextf->Show(true);
    perkbmp->Show(false);
    perkdesc->Show(false);
    perkadvancea->Show(false);
    perkadvanceb->Show(false);
    perkadvancec->Show(false);
    perkadvanced->Show(false);
    perkadvancee->Show(false);
    perkadvancef->Show(false);
    captainvbox->Layout();
}
