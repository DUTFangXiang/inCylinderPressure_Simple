//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitOption.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOption *FormOption;
//---------------------------------------------------------------------------
__fastcall TFormOption::TFormOption(TComponent* Owner)
        : TForm(Owner)
{
    bSTrainType  = false;         //机车车型是否发生变化
    bDetectInfo  = false;         //判断参数发生了变化
    bTrainRename = false;        //机型发生了变化
}
void __fastcall TFormOption::SetDieselInfo(StructDieselInfo* dt, int inum)
{
    for(int i = 0; i < inum; i++)
    {
	    myDieselInfo[i].fDiameter             = dt[i].fDiameter;               //气缸直径
	    myDieselInfo[i].fStroke               = dt[i].fStroke;                 //活塞冲程
	    myDieselInfo[i].fLMDa                 = dt[i].fLMDa ;                   //曲柄连杆比
	    myDieselInfo[i].fCRatio               = dt[i].fCRatio;                 //压缩比
	    myDieselInfo[i].fPodLength            = dt[i].fPodLength;              //连杆长度
	    myDieselInfo[i].fInCloseAngle         = dt[i].fInCloseAngle;           //进气门开启角度
	    myDieselInfo[i].fOutOpenAngle         = dt[i].fOutOpenAngle;           //排气门关闭角度
	    myDieselInfo[i].fCAING                = dt[i].fCAING;                  //供油角度
        myDieselInfo[i].fCompressMax          = dt[i].fCompressMax;            //压缩压力最大值　
        myDieselInfo[i].fCompressMin          = dt[i].fCompressMin;            //压缩压力最小值
        myDieselInfo[i].fOilAngleMax          = dt[i].fOilAngleMax;            //供油提前角最大值　
        myDieselInfo[i].fOilAngleMin          = dt[i].fOilAngleMin;            //供油提前角最小值　
        myDieselInfo[i].fCombustionAngleMax   = dt[i].fCombustionAngleMax;     //燃烧提前角最大值　
        myDieselInfo[i].fCombustionAngleMin   = dt[i].fCombustionAngleMin;     //燃烧提前角最小值
        myDieselInfo[i].fDetectLevel          = dt[i].fDetectLevel;            //燃烧提前角最小值

    }

}

void __fastcall TFormOption::GetDieselInfo(StructDieselInfo* dt, int inum)
{
    for(int i = 0; i < inum; i++)
    {
	    dt[i].fDiameter             = myDieselInfo[i].fDiameter;               //气缸直径
	    dt[i].fStroke               = myDieselInfo[i].fStroke;                 //活塞冲程
	    dt[i].fLMDa                 = myDieselInfo[i].fLMDa;                   //曲柄连杆比
	    dt[i].fCRatio               = myDieselInfo[i].fCRatio;                 //压缩比
	    dt[i].fPodLength            = myDieselInfo[i].fPodLength;              //连杆长度
	    dt[i].fInCloseAngle         = myDieselInfo[i].fInCloseAngle;           //进气门开启角度
	    dt[i].fOutOpenAngle         = myDieselInfo[i].fOutOpenAngle;           //排气门关闭角度
	    dt[i].fCAING                = myDieselInfo[i].fCAING;                  //供油角度
        dt[i].fCompressMax          = myDieselInfo[i].fCompressMax;            //压缩压力最大值　
        dt[i].fCompressMin          = myDieselInfo[i].fCompressMin;            //压缩压力最小值
        dt[i].fOilAngleMax          = myDieselInfo[i].fOilAngleMax;            //供油提前角最大值　
        dt[i].fOilAngleMin          = myDieselInfo[i].fOilAngleMin;            //供油提前角最小值　
        dt[i].fCombustionAngleMax   = myDieselInfo[i].fCombustionAngleMax;     //燃烧提前角最大值　
        dt[i].fCombustionAngleMin   = myDieselInfo[i].fCombustionAngleMin;     //燃烧提前角最小值
        dt[i].fDetectLevel          = myDieselInfo[i].fDetectLevel;     //燃烧提前角最小值

    }
}

void __fastcall TFormOption::SetDieselName(AnsiString* st, int inum)
{
    for( int i = 0; i < inum; i++)
    {
        strArrayTrainType[i] = st[i];
    }
}

void __fastcall TFormOption::GetDieselName(AnsiString* st, int inum)
{
    for( int i = 0; i < inum; i++)
    {
        st[i] = strArrayTrainType[i];
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormOption::FormActivate(TObject *Sender)
{
    EditOtherA->Text = strArrayTrainType[0];
//    EditOtherB->Text = strArrayTrainType[1];
/*
    EditOtherC->Text = strArrayTrainType[2];
    EditOtherD->Text = strArrayTrainType[3];
    EditOtherE->Text = strArrayTrainType[4];
*/
    for( int i = 0; i < 1; i++)
    {
        ComboBoxTrainType->Items->Strings[i + 10] = strArrayTrainType[i];
        ComboBoxTrainTypeStandard->Items->Strings[i + 10] = strArrayTrainType[i];
    }

}
//---------------------------------------------------------------------------


void __fastcall TFormOption::RefreshControl(int itraintype, bool bCombox)
{
    //TODO: Add your source code here
    AnsiString strTemp;
    iSTrainType          = itraintype;
    if(bCombox)
    {
        ComboBoxTrainType->Items->Clear();
        ComboBoxTrainType->Items->Add("东风4A");
        ComboBoxTrainType->Items->Add("东风4B");
        ComboBoxTrainType->Items->Add("东风4C");
        ComboBoxTrainType->Items->Add("东风4D");
        ComboBoxTrainType->Items->Add("东风8B");
        ComboBoxTrainType->Items->Add("东风11");
        ComboBoxTrainType->Items->Add("东风5");
        ComboBoxTrainType->Items->Add("东风7");
        ComboBoxTrainType->Items->Add("东风7C");
        ComboBoxTrainType->Items->Add("东风11G");
        ComboBoxTrainType->Items->Add(strArrayTrainType[0]);

        ComboBoxTrainType->ItemIndex = iSTrainType;
    }
    //气缸直径
    strTemp.printf("%.3f",myDieselInfo[iSTrainType].fDiameter);
    EditDiameter->Text  = strTemp;
    //活塞行程
    strTemp.printf("%.3f",myDieselInfo[iSTrainType].fStroke);
    EditStroke->Text    = strTemp;
    //连杆长度
    strTemp.printf("%.3f",myDieselInfo[iSTrainType].fPodLength);
    EditPodLength->Text  = strTemp;
    //压缩比
    strTemp.printf("%.3f",myDieselInfo[iSTrainType].fCRatio);
    EditCRation->Text    = strTemp;
    //进气门关闭角度
    strTemp.printf("%.2f",myDieselInfo[iSTrainType].fInCloseAngle);
    EditInCloseAngle->Text    = strTemp;
    //排气门开启角度
    strTemp.printf("%.2f",myDieselInfo[iSTrainType].fOutOpenAngle);
    EditOutOpenAngle->Text    = strTemp;
    //喷油泵供油角度
    strTemp.printf("%.2f",myDieselInfo[iSTrainType].fCAING);
    EditFuelSupplyAngle->Text    = strTemp;
}

void __fastcall TFormOption::ComboBoxTrainTypeChange(TObject *Sender)
{
    int iIndex;
    iIndex = ComboBoxTrainType->ItemIndex;
    FlushDetectInfo();
    FlushDieselInfo();
    iSTrainType          = iIndex;
    RefreshControl(iIndex, false);
}
//---------------------------------------------------------------------------


void __fastcall TFormOption::RefreshDetectInfo(int itraintype, bool bCombox)
{
    //TODO: Add your source code here
    AnsiString strTemp;
    iSDetectInfo = itraintype;
    if(bCombox)
    {
        ComboBoxTrainTypeStandard->Items->Clear();
        ComboBoxTrainTypeStandard->Items->Add("东风4A");
        ComboBoxTrainTypeStandard->Items->Add("东风4B");
        ComboBoxTrainTypeStandard->Items->Add("东风4C");
        ComboBoxTrainTypeStandard->Items->Add("东风4D");
        ComboBoxTrainTypeStandard->Items->Add("东风8B");
        ComboBoxTrainTypeStandard->Items->Add("东风11");
        ComboBoxTrainTypeStandard->Items->Add("东风5");
        ComboBoxTrainTypeStandard->Items->Add("东风7");
        ComboBoxTrainTypeStandard->Items->Add("东风7C");
        ComboBoxTrainTypeStandard->Items->Add("东风11G");
        ComboBoxTrainTypeStandard->Items->Add(strArrayTrainType[0]);

        ComboBoxTrainTypeStandard->ItemIndex = iSDetectInfo;
    }
    //压缩压力最小值　
    strTemp.printf("%.2f",myDieselInfo[iSDetectInfo].fCompressMin);
    EditCompressMin->Text    = strTemp;
    //压缩压力最大值　
    strTemp.printf("%.2f",myDieselInfo[iSDetectInfo].fCompressMax);
    EditCompressMax->Text    = strTemp;

    //供油角度最小值　
    strTemp.printf("%.2f",myDieselInfo[iSDetectInfo].fOilAngleMin);
    EditOilAngleMin->Text    = strTemp;
    //供油角度最大值　
    strTemp.printf("%.2f",myDieselInfo[iSDetectInfo].fOilAngleMax);
    EditOilAngleMax->Text    = strTemp;

    //供油角度最小值　
    strTemp.printf("%.2f",myDieselInfo[iSDetectInfo].fCombustionAngleMin);
    EditCombustionAngleMin->Text    = strTemp;

    //供油角度最大值　
    strTemp.printf("%.2f",myDieselInfo[iSDetectInfo].fCombustionAngleMax);
    EditCombustionAngleMax->Text    = strTemp;

    //压力波对比分析门限值　
    strTemp.printf("%.2f",myDieselInfo[iSDetectInfo].fDetectLevel);
    EditDetectLevel->Text    = strTemp;

}

void __fastcall TFormOption::ComboBoxTrainTypeStandardChange(
      TObject *Sender)
{
    int iIndex;
    iIndex = ComboBoxTrainTypeStandard->ItemIndex;
    FlushDetectInfo();
    FlushDieselInfo();
    iSDetectInfo          = iIndex;
    RefreshDetectInfo(iSDetectInfo, false);
}
//---------------------------------------------------------------------------

void __fastcall TFormOption::EditDiameterChange(TObject *Sender)
{
    bSTrainType  = true;         //机车车型是否发生变化
}
//---------------------------------------------------------------------------

void __fastcall TFormOption::EditCompressMinChange(TObject *Sender)
{
    bDetectInfo  = true;         //判断参数发生了变化
}
//---------------------------------------------------------------------------

void __fastcall TFormOption::EditOtherAChange(TObject *Sender)
{
    bTrainRename = true;        //机型发生了变化
    strArrayTrainType[0] = EditOtherA->Text;
}
//---------------------------------------------------------------------------

void __fastcall TFormOption::ButtonRefreshTrainTypeClick(TObject *Sender)
{
    RefreshControl(iSTrainType, true);
    RefreshDetectInfo(iSDetectInfo, true);
}
//---------------------------------------------------------------------------

void __fastcall TFormOption::EditOtherBChange(TObject *Sender)
{
    strArrayTrainType[1] = EditOtherB->Text;
}
//---------------------------------------------------------------------------




void __fastcall TFormOption::BitBtn1Click(TObject *Sender)
{
    FlushDetectInfo();
    FlushDieselInfo();
}
//---------------------------------------------------------------------------


void __fastcall TFormOption::FlushDetectInfo(void)
{
    if(bDetectInfo)
    {
    //压缩压力最小值　
        myDieselInfo[iSDetectInfo].fCompressMin = StrToFloat(EditCompressMin->Text);
    //压缩压力最大值　
        myDieselInfo[iSDetectInfo].fCompressMax = StrToFloat(EditCompressMax->Text);
    //供油角度最小值　
        myDieselInfo[iSDetectInfo].fOilAngleMin = StrToFloat(EditOilAngleMin->Text);
    //供油角度最大值　
        myDieselInfo[iSDetectInfo].fOilAngleMax = StrToFloat(EditOilAngleMax->Text);
    //供油角度最小值　
        myDieselInfo[iSDetectInfo].fCombustionAngleMin = StrToFloat(EditCombustionAngleMin->Text);
    //供油角度最大值　
        myDieselInfo[iSDetectInfo].fCombustionAngleMax = StrToFloat(EditCombustionAngleMax->Text);
    //压力波对比分析门限值　
        myDieselInfo[iSDetectInfo].fDetectLevel = StrToFloat(EditDetectLevel->Text);

        bDetectInfo = false;
    }
}

void __fastcall TFormOption::FlushDieselInfo(void)
{
    //TODO: Add your source code here
    if(bSTrainType)
    {
    //气缸直径
        myDieselInfo[iSTrainType].fDiameter     = StrToFloat(EditDiameter->Text);
    //活塞行程
        myDieselInfo[iSTrainType].fStroke       = StrToFloat(EditStroke->Text);
    //连杆长度
        myDieselInfo[iSTrainType].fPodLength    = StrToFloat(EditPodLength->Text);
    //压缩比
        myDieselInfo[iSTrainType].fCRatio       = StrToFloat(EditCRation->Text);
    //进气门关闭角度
        myDieselInfo[iSTrainType].fInCloseAngle = StrToFloat(EditInCloseAngle->Text);
    //排气门开启角度
        myDieselInfo[iSTrainType].fOutOpenAngle = StrToFloat(EditOutOpenAngle->Text);
    //喷油泵供油角度
        myDieselInfo[iSTrainType].fCAING        = StrToFloat(EditFuelSupplyAngle->Text);
        bSTrainType = false;
    }
}
void __fastcall TFormOption::EditDetectLevelChange(TObject *Sender)
{
    bDetectInfo  = true;         //判断参数发生了变化    
}
//---------------------------------------------------------------------------

