//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "lAbout.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
/*
    THandle hRegion;
    hRegion=::CreateEllipticRgn(0, -Height,Width,Height);
    ::SetWindowRgn(Handle,hRegion,true);
*/
    ViewMemory();
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormResize(TObject *Sender)
{
/*    THandle hRegion;
hRegion=::CreateEllipticRgn(  0,
                                -Height,Width,Height);
    ::SetWindowRgn(Handle,hRegion,true);
*/
}
//---------------------------------------------------------------------------


void __fastcall TAboutBox::ViewMemory(void)
{
    //TODO: Add your source code here
    MEMORYSTATUS MS;
    MS.dwLength=sizeof(MS);
    GlobalMemoryStatus(&MS);
    AnsiString strTemp;
    strTemp=Label2->Caption;
    strTemp+=FormatFloat((AnsiString)"#,###' KB'",MS.dwTotalPhys/1024);
    Label2->Caption=strTemp;

    strTemp=Label3->Caption;
    strTemp+=IntToStr(MS.dwMemoryLoad)+"%";
    Label3->Caption=strTemp;

    int use,free,total;
    total=(int)(MS.dwTotalPhys/1024);
    free=int(MS.dwAvailPhys/1024);
    use=total-free;
    Chart1->Series[0]->Clear();
    Chart1->Series[0]->Add(free,"",clAqua);
    Chart1->Series[0]->Add(use,"",clBlue);

    strTemp=Label4->Caption;
    strTemp+=FormatFloat((AnsiString)"#,###' KB'",free);
    Label4->Caption=strTemp;
}



