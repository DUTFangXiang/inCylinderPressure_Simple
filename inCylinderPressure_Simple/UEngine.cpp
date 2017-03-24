//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UEngine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEngine *FormEngine;
//---------------------------------------------------------------------------
__fastcall TFormEngine::TFormEngine(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
