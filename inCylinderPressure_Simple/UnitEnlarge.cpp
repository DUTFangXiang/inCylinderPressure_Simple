//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitEnlarge.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEnlargeView *FormEnlargeView;
//---------------------------------------------------------------------------
__fastcall TFormEnlargeView::TFormEnlargeView(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEnlargeView::BitBtn1Click(TObject *Sender)
{
    this->Visible = false;
}
//---------------------------------------------------------------------------
