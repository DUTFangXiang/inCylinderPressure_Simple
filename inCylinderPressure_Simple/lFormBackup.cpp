//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lFormBackup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormBackup *FormBackup;
//---------------------------------------------------------------------------
__fastcall TFormBackup::TFormBackup(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormBackup::FormActivate(TObject *Sender)
{
    ComboBoxTrainNum->SetFocus();    
}
//---------------------------------------------------------------------------


void __fastcall TFormBackup::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Shift.Contains(ssCtrl)&&(Key=='x'||Key=='X'))
        ModalResult=mrOk;
}
//---------------------------------------------------------------------------

