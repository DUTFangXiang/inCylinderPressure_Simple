//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lFormStartFace.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormStartFace *FormStartFace;
//---------------------------------------------------------------------------
__fastcall TFormStartFace::TFormStartFace(TComponent* Owner)
    : TForm(Owner)
{
    iStep = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFormStartFace::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormStartFace::Image1Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TFormStartFace::Timer1Timer(TObject *Sender)
{
    iStep++;
    if (iStep == 10) Close();
}
//---------------------------------------------------------------------------
