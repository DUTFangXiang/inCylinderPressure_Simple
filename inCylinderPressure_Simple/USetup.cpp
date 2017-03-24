//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USetup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSetup *FormSetup;
//---------------------------------------------------------------------------
__fastcall TFormSetup::TFormSetup(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::Panel1Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        Panel1->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::Panel2Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        Panel2->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::Panel3Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        Panel3->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::Panel4Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        Panel4->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------
