//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UAllow.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRight *FormRight;
//---------------------------------------------------------------------------
__fastcall TFormRight::TFormRight(TComponent* Owner)
    : TForm(Owner)
{
    bResult = false;
    iItems  = 0;
    iKicked[0] = 0;
    iKicked[1] = 0;
    iKicked[2] = 0;
    iKicked[3] = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFormRight::Button1Click(TObject *Sender)
{
//    bResult = DetectCode();
    Confirm();
}
//---------------------------------------------------------------------------


bool TFormRight::DetectCode(void)
{
    //TODO: Add your source code here
    int imis1,imis2,isec1,isec2;
    AnsiString strTemp,strTemp2;
    int itemp1,itemp2;
    float ftemp;
    for(int i=0;i<4;i++)
    {
        if( iKicked[i] != ii[i] )
        {
            return false;
        }
    }
    strNeed = LabelInform->Caption;
    if(strNeed == "")
    {
        return false;
    }
    int iLength = strNeed.Length();
    if(iLength != 20)
    {
        return false;
    }
    strTemp = strNeed.SubString(1,4);
    itemp1 = StrToInt(strTemp);
    imis1 = itemp1 - 8038;

    strTemp = strNeed.SubString(15,4);
    itemp1 =  StrToInt(strTemp);
    itemp1 -= 171;
    ftemp = sqrt(float(itemp1)) + 0.5;
    itemp1 = floor(ftemp);

    strTemp = strNeed.SubString(19,2);
    itemp2 =  StrToInt(strTemp);
    itemp2 -= 11;
    ftemp = sqrt(float(itemp2)) + 0.5;
    itemp2 = floor(ftemp);
    imis2 =  itemp2*100 + itemp1;
    if(imis1 != imis2)
    {
        return false;
    }
    strTemp = strNeed.SubString(8,4);
    itemp2 =  StrToInt(strTemp);
    itemp2 -= 1971;
    ftemp = sqrt(float(itemp2)) + 0.5;
    isec1 = floor(ftemp);

    strTemp = strNeed.SubString(12,2);
    itemp2 =  StrToInt(strTemp);
    itemp2 -= 25;
    ftemp = sqrt(float(itemp2)) + 0.5;
    itemp2 = floor(ftemp);

    strTemp = strNeed.SubString(5,2);
    itemp1 =  StrToInt(strTemp);
    itemp1 -= 3;
    ftemp = sqrt(float(itemp1)) + 0.5;
    itemp1 = floor(ftemp);
    isec2 =  itemp1*10 + itemp2;
    if(isec1 != isec2)
    {
        return false;
    }


//Éú³ÉÊÚÈ¨Âë
    int iST,iSG,iMB,iMT,iMG;
    int iST1,iSG1,iMB1,iMT1,iMG1;
    int ir0,ir1,ir2,ir3,ir4;
    int iLeft;
    iST = isec1/10;
    iSG = isec1 - iST*10;
    iMB = imis1/100;
    iLeft = imis1 - iMB*100;
    iMT = iLeft/10;
    iMG = iLeft - iMT*10;
    randomize();
    ir0 = random(10);
    ir1 = random(10);
    ir2 = random(10);
    ir3 = random(10);
    ir4 = random(10);
    strTemp.printf("6%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
                    iSG,ir0,iMG,ir1,iMG,iST,ir4,iMT,
                    iMB,iMT,ir2,iST,iSG,ir3,iMB);
    EditRight->Text = strTemp;
    bResult = true;
    return true;
}

void __fastcall TFormRight::Confirm(void)
{
    //TODO: Add your source code here
    int iST,iSG,iMB,iMT,iMG;
    int iST1,iSG1,iMB1,iMT1,iMG1;
    int iLeft;
    AnsiString strTemp,strTemp2;
    strTemp = EditRight->Text;
    iLeft = strTemp.Length();
    if(iLeft != 16)
    {
        bResult = false;
        return;
    }
    strTemp2 = strTemp.SubString(2,1);
    iSG = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(4,1);
    iMG = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(6,1);
    iMG1 = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(7,1);
    iST = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(9,1);
    iMT = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(10,1);
    iMB = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(11,1);
    iMT1 = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(13,1);
    iST1 = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(14,1);
    iSG1 = StrToInt(strTemp2);
    strTemp2 = strTemp.SubString(16,1);
    iMB1 = StrToInt(strTemp2);
    if(   (iMG != iMG1)
        ||(iMT != iMT1)
        ||(iMB != iMB1)
        ||(iST != iST1)
        ||(iSG != iSG1)
      )
    {
        bResult = false;
        return;
    }
    iMB = iMB*100 + iMT*10 + iMG;
    iST = iST*10 + iSG;
    if( (iMB != iMis)
        ||(iST != iSec))
    {
        bResult = false;
        return;
    }
    bResult = true;

}

void __fastcall TFormRight::ImageRedDblClick(TObject *Sender)
{
    AnsiString strTemp;
    int iNumber1,iNumber2;

    int iYear,iMonth,iDate,iHour,iMinute,iSecond;
    unsigned short usYear,usMonth,usDate,usHour,usMinute,usSecond,usMiSecond;

    if(bClicked)
    {
        return;
    }

    TDateTime dtNow = Now();
    dtNow.DecodeDate(&usYear,&usMonth,&usDate);
    dtNow.DecodeTime(&usHour,&usMinute,&usSecond,&usMiSecond);

    iYear    = usYear;
    iMonth   = usMonth;
    iDate    = usDate;
    iHour    = usHour;
    iMinute  = usMonth;
    iSecond  = usSecond;
    iSec     = usSecond;
    iMis     = usMiSecond;
    iNumber1 = iYear*71 + 3*iMonth + 25*iDate;
    iNumber2 = iHour*71 + 3*iMinute + 25*iSecond;
    iNumber1 *=iNumber2;
    strNeed = "";

    strTemp.printf("%04d",usMiSecond + 8038);
    strNeed += strTemp;

    iDate  = usSecond / 10;
    iSecond = (usSecond - iDate*10);

    strTemp.printf("%02d",iDate*iDate + 3);
    strNeed += strTemp;
    strNeed += "-";

    strTemp.printf("%04d",usSecond*usSecond + 1971);
    strNeed += strTemp;

    strTemp.printf("%02d",iSecond*iSecond + 25);
    strNeed += strTemp;
    strNeed += "-";

    iYear  = usMiSecond % 100;
    strTemp.printf("%04d",iYear*iYear + 171);
    strNeed += strTemp;


    iYear  = usMiSecond/100;
    strTemp.printf("%02d",iYear*iYear + 11);
    strNeed += strTemp;
    LabelInform->Caption = strNeed;
    LabelInform->Visible = true;
//    DetectCode();
    bClicked = true;
     
}
//---------------------------------------------------------------------------


void __fastcall TFormRight::HelpCode(void)
{
    //TODO: Add your source code here

    int iNum = 0;
    bool bHave = false;
    AnsiString strTemp,strShow = "";
    randomize();
    do
    {
        ii[iNum] = random(5);
        if(ii[iNum] == 0)
        {
            continue;
        }
        for(int j=0;j<iNum;j++)
        {
            if((ii[j] == ii[iNum]))
            {
                bHave = true;
                break;
            }
            else
            {
                bHave = false;
            }
        }
        if(!bHave)
        {
            iNum ++;
        }
    }while( iNum != 4);
    strTemp.printf("%03d",ii[0]*ii[0]+25);
    strShow += strTemp;
    strTemp.printf("%03d",ii[1]*ii[1]+3);
    strShow += strTemp;
    strShow += "-";
    strTemp.printf("%03d",ii[2]*ii[2]+71);
    strShow += strTemp;
    strTemp.printf("%03d",ii[3]*ii[3]+19);
    strShow += strTemp;
    LabelHint->Caption = strShow;


}
void __fastcall TFormRight::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(bClicked)
    {
        if(Shift.Contains(ssCtrl))
        if((Key == 'R')||(Key == 'r'))
        {
            HelpCode();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormRight::Panel1Click(TObject *Sender)
{
    if(iItems>3)
    {
        return;
    }
    iKicked[iItems] = 1;
    iItems ++;
    if(iItems == 4)
    {
        DetectCode();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormRight::Panel3Click(TObject *Sender)
{
    if(iItems>3)
    {
        return;
    }
    iKicked[iItems] = 2;
    iItems ++;
    if(iItems == 4)
    {
        DetectCode();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormRight::Panel2Click(TObject *Sender)
{
    if(iItems>3)
    {
        return;
    }
    iKicked[iItems] = 3;
    iItems ++;
    if(iItems == 4)
    {
        DetectCode();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormRight::Panel4Click(TObject *Sender)
{
    if(iItems>3)
    {
        return;
    }
    iKicked[iItems] = 4;
    iItems ++;
    if(iItems == 4)
    {
        DetectCode();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormRight::Button2Click(TObject *Sender)
{
    bResult = false;
}
//---------------------------------------------------------------------------

