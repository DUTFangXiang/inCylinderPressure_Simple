//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormOrderInfo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOrderInfo *FormOrderInfo;
//---------------------------------------------------------------------------
__fastcall TFormOrderInfo::TFormOrderInfo(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormOrderInfo::Button1Click(TObject *Sender)
{
    Hide();
}
//---------------------------------------------------------------------------


