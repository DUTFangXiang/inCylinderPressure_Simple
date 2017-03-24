//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAddToBase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPipeBase *FormPipeBase;
//---------------------------------------------------------------------------
__fastcall TFormPipeBase::TFormPipeBase(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPipeBase::Timer1Timer(TObject *Sender)
{
    if(bConvert)
    {
        LabelInfo->Font->Color = clBlue;
    }
    else
    {
        LabelInfo->Font->Color = clRed;
    }
    bConvert = !bConvert;
}
//---------------------------------------------------------------------------

