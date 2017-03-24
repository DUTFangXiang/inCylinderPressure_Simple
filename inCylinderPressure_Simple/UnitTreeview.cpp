//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitTreeview.h"
#include "lFormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTV *FormTV;
//---------------------------------------------------------------------------
__fastcall TFormTV::TFormTV(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormTV::TreeViewDatabaseDblClick(TObject *Sender)
{
    AnsiString strSelected[10];
    TTreeNode* mNode = TreeViewDatabase->Selected;
    int i = 0;
    if(mNode == NULL)
    {
        return;
    }
    if(mNode->Text != "数据库")
    {
        if(mNode != NULL)
        {
            do
            {
                strSelected[i] = mNode->Text;
                mNode = mNode->Parent;
                i++;
            }while( mNode->Text != "数据库");
        }
    }
    FormMain->strMDate        = "";
    FormMain->strDieselSpeed  = "";
    FormMain->strCombustion   = "";

    if(i == 2)
    {
//        Application->MessageBox("选择了车型、车号!","提示",MB_OK|MB_ICONINFORMATION);
        FormMain->iQueryStyle     = 2;                //选择了车型车号进行查询
        FormMain->strTrainType    = strSelected[1];
        FormMain->strTrainNumber  = strSelected[0];
        
    }
    else if(i == 3)
    {
//        Application->MessageBox("选择了车型、车号和测量日期!","提示",MB_OK|MB_ICONINFORMATION);
        FormMain->iQueryStyle     = 3;               //选择了车型车号及测量时间进行查询
        FormMain->strTrainType    = strSelected[2];
        FormMain->strTrainNumber  = strSelected[1];
        FormMain->strMDate        = strSelected[0];
    }
    else if( i == 4)
    {
//        Application->MessageBox("选择了车型、车号、测量日期和转速!","提示",MB_OK|MB_ICONINFORMATION);

        FormMain->iQueryStyle      = 4;
        FormMain->strTrainType     = strSelected[3];
        FormMain->strTrainNumber   = strSelected[2];
        FormMain->strMDate         = strSelected[1];
        FormMain->strDieselSpeed   = strSelected[0];
        FormMain->strDieselSpeed   = FormMain->strDieselSpeed.SubString(1,FormMain->strDieselSpeed.Pos(" ")-1);
    }
    else if( i == 5)
    {
        FormMain->iQueryStyle     = 5;
        FormMain->strTrainType    = strSelected[4];
        FormMain->strTrainNumber  = strSelected[3];
        FormMain->strMDate        = strSelected[2];
        FormMain->strDieselSpeed  = strSelected[1];
        FormMain->strDieselSpeed  = FormMain->strDieselSpeed.SubString(1,FormMain->strDieselSpeed.Pos(" ")-1);
        FormMain->strCombustion   = strSelected[0];
    }
    else
    {
        FormMain->iQueryStyle = 1;     //并不是有效的操作
    }

    if(FormMain->iQueryStyle > 3)    //对于只有车号和测量日期的不再进行查询
    {
        FormMain->iTVLastPosi = 0;
        FormMain->iTVCurrPosi = 0;
        FormMain->QueryDatabasebyTV();
        
        FormMain->iTrainType = FormMain->GetiTrainType(FormMain->strTrainType);
        FormMain->SetDieselInfo(FormMain->iTrainType,false);                //向计算系统设置柴油机参数

        TCursor Save_Cursor = Screen->Cursor;
        Screen->Cursor      = crHourGlass;    // Show hourglass cursor

        try
        {
            Screen->Cursor = crHourGlass;
            if(!FormMain->bAnalysising)
            {
                FormMain->bAnalysising   = true;

                FormMain->FillmyDetectResult(true);          //将各个参数装入信息结构中

                FormMain->AnalysisResultAll(true);           //分析显示结果

                FormMain->bAnalysising   = false;
            }
        }
        __finally
        {
            Screen->Cursor = Save_Cursor;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormTV::N1Click(TObject *Sender)
{
    FormMain->ppmDataDeleteClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFormTV::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = caHide;
}
//---------------------------------------------------------------------------
void __fastcall TFormTV::FormDragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{

    int i = 0;
    i ++;
}
//---------------------------------------------------------------------------
void __fastcall TFormTV::FormUnDock(TObject *Sender, TControl *Client,
      TWinControl *NewTarget, bool &Allow)
{

    int i = 0;
    i ++;

}
//---------------------------------------------------------------------------
