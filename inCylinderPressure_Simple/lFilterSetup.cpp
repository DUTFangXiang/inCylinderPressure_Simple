//---------------------------------------------------------------------------

#include <vcl.h>
#include "DataProcess.h"
#include <Stdio.h>
#pragma hdrstop

#include "lFilterSetup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFilterSetup *FormFilterSetup;
//---------------------------------------------------------------------------
__fastcall TFormFilterSetup::TFormFilterSetup(TComponent* Owner)
	: TForm(Owner)
{
	ComboBoxFilterKind->ItemIndex = 0;
    ComboBoxWindowChoice->ItemIndex = 2;
}
//---------------------------------------------------------------------------


void __fastcall TFormFilterSetup::Verification(void)
{
	//TODO: Add your source code here
    int iSimple,iFKind;
    iSimple = RadioGroupMethod->ItemIndex;
    iFKind  = ComboBoxFilterKind->ItemIndex;
    if(iSimple == 0)
    {
    	if(iFKind > 1)
        {
        	float fl,fh;
            fl = StrToFloat(EditFPL->Text);
            fh = StrToFloat(EditFPH->Text);
            if(fl > fh)
            {
            	Application->MessageBox("高频截止频率应大于低频截止频率","提示",MB_OK);
                EditFPL->SetFocus();
                return;
            }
        }
    }
    else
    {
    	float fl,fh,sl,sh;
        try
        {
         	fl=StrToFloat(EditFPL->Text);
           	sl=StrToFloat(EditFSL->Text);
           	fh=StrToFloat(EditFPH->Text);
           	sh=StrToFloat(EditFSH->Text);
        }
        catch(...)
        {
           	Application->MessageBox("请正确输入频率","提示",MB_OK);
            EditFPL->SetFocus();
            return;
        }
        if(iFKind==0)
        {
            if(fl>sl)
            {
            	Application->MessageBox("低频截止频率应小于低频过渡频率","提示",MB_OK);
                EditFPL->SetFocus();
                return;
            }
        }
        else if(iFKind==1)
        {
        	if(sh>fh)
            {
            	Application->MessageBox("高频截止频率应大于高频过渡频率","提示",MB_OK);
                EditFPH->SetFocus();
                return;

            }
        }
        else if(iFKind==2)
        {
        	if((sl>fl)||(sh<fh)||(fl>fh))
            {
            	Application->MessageBox("频带设置有错误，请重新设置","提示",MB_OK);
                EditFPL->SetFocus();
                return;

            }
        }
        else
        {
        	if((sl<fl)||(sh>fh)||(fl>fh))
            {
            	Application->MessageBox("频带设置有错误，请重新设置","提示",MB_OK);
                EditFPL->SetFocus();
                return;

            }

        }
    }
}
void __fastcall TFormFilterSetup::EditFPLExit(TObject *Sender)
{
	float ft;
    try
    {
    	ft=StrToFloat(EditFPL->Text);
    }
    catch(...)
    {
    	Application->MessageBox("请输入合法浮点数","提示",MB_OK);
        EditFPL->SetFocus();
        return;
    }
    if(ft>fmax)
    {
    	Application->MessageBox("输入的频率值太大\n\n应小于最大分析频率","提示",MB_OK);
        EditFPL->SetFocus();
        return;
    }
//	Verification();
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::EditFSLExit(TObject *Sender)
{
	float ft;
    try
    {
    	ft=StrToFloat(EditFSL->Text);
    }
    catch(...)
    {
    	Application->MessageBox("请输入合法浮点数","提示",MB_OK);
        EditFSL->SetFocus();
        return;
    }
    if(ft>fmax)
    {
    	Application->MessageBox("输入的频率值太大\n\n应小于最大分析频率","提示",MB_OK);
        EditFSL->SetFocus();
        return;
    }
//	Verification();
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::EditFPHExit(TObject *Sender)
{
	float ft;
    try
    {
    	ft=StrToFloat(EditFPH->Text);
    }
    catch(...)
    {
    	Application->MessageBox("请输入合法浮点数","提示",MB_OK);
        EditFPH->SetFocus();
        return;
    }
    if(ft>fmax)
    {
    	Application->MessageBox("输入的频率值太大\n\n应小于最大分析频率","提示",MB_OK);
        EditFPH->SetFocus();
        return;
    }
//	Verification();
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::EditFSHExit(TObject *Sender)
{
  	float ft;
    try
    {
    	ft=StrToFloat(EditFSH->Text);
    }
    catch(...)
    {
    	Application->MessageBox("请输入合法浮点数","提示",MB_OK);
        EditFSH->SetFocus();
        return;
    }
    if(ft>fmax)
    {
    	Application->MessageBox("输入的频率值太大\n\n应小于最大分析频率","提示",MB_OK);
        EditFSH->SetFocus();
        return;
    }
//	Verification();
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::FormActivate(TObject *Sender)
{
	AnsiString strTemp;
    strTemp.printf("%.1f",fmax);
    EditMaxFrequency->Text = strTemp;
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::ComboBoxFilterKindChange(TObject *Sender)
{
//	Verification();
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::Button3Click(TObject *Sender)
{
	Verification();	
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::CheckBoxSelfClick(TObject *Sender)
{
	if(CheckBoxSelf->Checked)
    {
    	EditFilterOrder->Enabled=false;
    }
    else
    	EditFilterOrder->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::RadioGroupMethodClick(TObject *Sender)
{
	if(RadioGroupMethod->ItemIndex==0)
    {
    	EditFSL->Enabled=false;
        EditFSH->Enabled=false;
    }
    else
    {
    	EditFSL->Enabled=true;
        EditFSH->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterSetup::ButtonCalculationClick(TObject *Sender)
{
	float fpl=0.0,fph=0.0,fsl=0.0,fsh=0.0;
    int ifilterkind,iwindowchoice,iNum;
    bool bautolen;
    int idetail;
    lFIR lfir;
    FILE *fp;
    String strExeFileName=::ParamStr(0);
	String strNowPath=::ExtractFilePath(strExeFileName);
    strExeFileName=strNowPath+"filter.dat";
    fpl=StrToFloat(EditFPL->Text);
    fph=StrToFloat(EditFPH->Text);
    fsl=StrToFloat(EditFSL->Text);
    fsh=StrToFloat(EditFSH->Text);
    idetail=RadioGroupMethod->ItemIndex;
    ifilterkind=ComboBoxFilterKind->ItemIndex;
    iwindowchoice=ComboBoxWindowChoice->ItemIndex;
    iNum=StrToInt(EditFilterOrder->Text);
    bautolen=CheckBoxSelf->Checked;
    if(idetail==0)
    {
		switch(ifilterkind)
        {
        	case 0: //低通滤波器
            	fsl=fpl*1.1;
                break;
            case 1: //高通滤波器
            	fsh=0.9*fph;
                break;
            case 2:
            	fsl=fpl*0.9;
                fsh=fph*1.1;
                break;
            case 3:
            	fsl=fpl*1.1;
                fsh=fph*0.9;
                break;
        }
    }
    if(bautolen)
    {
    	lfir.SetbAutoLength(true,iNum);
    }
    else	lfir.SetbAutoLength(false,iNum);

   	lfir.SetiWindowChoice(iwindowchoice);
    lfir.SetiFilterKind(ifilterkind);
    float ianalysisFre;
    ianalysisFre = StrToFloat(EditMaxFrequency->Text);
    lfir.SetfSampleRate(ianalysisFre*2.56);
    lfir.SetFrequency(fpl,fph,fsl,fsh);
    lfir.GenerateFilter(fFilter, iFilterLen);
    if((fp=fopen(strExeFileName.c_str(),"w"))!=NULL)
    {
    	for(int i=0;i<iFilterLen;i++)
        {
            if( (i+1)%5== 0)
            {
        	    fprintf(fp,"\n%.8f,",fFilter[i]);
            }
            else
            {
        	    fprintf(fp,"%.8f,",fFilter[i]);
            }
        }
        fclose(fp);
        MemoResult->Lines->LoadFromFile(strExeFileName);
        Application->MessageBox("滤波器生成结束","提示",MB_OK);
    }
}
//---------------------------------------------------------------------------



