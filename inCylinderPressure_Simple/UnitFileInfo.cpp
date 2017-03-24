//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFileInfo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFileInfo *FormFileInfo;
//---------------------------------------------------------------------------
__fastcall TFormFileInfo::TFormFileInfo(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
