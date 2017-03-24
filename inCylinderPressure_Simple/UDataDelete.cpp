//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDataDelete.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDeleteData *FormDeleteData;
//---------------------------------------------------------------------------
__fastcall TFormDeleteData::TFormDeleteData(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDeleteData::FormActivate(TObject *Sender)
{
    DateTimePicker1->Date = Now();
}
//---------------------------------------------------------------------------
void __fastcall TFormDeleteData::DateTimePicker1Change(TObject *Sender)
{
    dtDelete = DateTimePicker1->Date;
}
//---------------------------------------------------------------------------
