//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UGoBack.h"
#include "lFormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGoBack *FormGoBack;
//---------------------------------------------------------------------------
__fastcall TFormGoBack::TFormGoBack(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormGoBack::CreateParams(TCreateParams &Params)
{
    TForm::CreateParams(Params);
    Params.Style &= (~WS_CAPTION);
    FormGoBack->Refresh();
}
void __fastcall TFormGoBack::BitBtn1Click(TObject *Sender)
{
    FormMain->CoolBar1->Visible = true;
    FormMain->BorderStyle = bsSingle;
    if(FormMain->bShowAll)
    {
        FormMain->ToolBarMainMenu->Visible = true;
        FormMain->ToolBarMainToolBar->Visible = true;
        FormMain->bShowAll = false;
    }
    Hide();
}
void __fastcall TFormGoBack::WMLBUTTONDOWN(TMessage &Msg)
{
    Perform(WM_NCLBUTTONDOWN,HTCAPTION,NULL);
}
//---------------------------------------------------------------------------
