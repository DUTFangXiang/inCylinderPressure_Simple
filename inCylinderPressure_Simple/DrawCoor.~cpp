
#include <stdio.h>
#include <Printers.hpp>
#include <math.h>
#include <stdlib.h>
#include "DrawCoor.h"
#include "lFileHead.h"
#include "lDetect.h"
const int siHalfWin=7;
int LineType[]={psSolid,       //	A solid line.
                psDash,         //	A line made up of a series of dashes.
                psDot,          //	A line made up of a series of dots.
                psDashDot,      //	A line made up of alternating dashes and dots.
                psDashDotDot     //
                };
int LineWidth[]={1,
                 2,
                 5,
                 10
                };

const int IFONTHEIGHT = -12;
const int IDECREASEHEIGHT = 2;


                            
const float PI            = 3.1415926;
//extern float fGaugeConst[];
void CReadString::GetData(char* str,float * Data,int num)
{
	int i;
	strcpy(DataString,str);
	for(i=0;i<num;i++)
	{
		LTrimLeft();
		GetNextString();
		Data[i]=atof(Temp);
	}
}

void CReadString::GetData(char* str,double * Data,int num)
{
	int i;
	strcpy(DataString,str);
	for(i=0;i<num;i++)
	{
		LTrimLeft();
		GetNextString();
		Data[i]=atof(Temp);
	}
}

void CReadString::LTrimLeft(void)
{
	int i=0,j,len;
	char ch;
	len=strlen(DataString);
	ch=DataString[0];
	while(ch==' '||ch==','||ch==';'||ch=='\t')
	{
		i++;
		ch=DataString[i];
	}
	for(j=0;j<len-i;j++)
		DataString[j]=DataString[j+i];
	DataString[j]='\0';
}

void CReadString::GetNextString(void)
{
	char ch;
	int i=0,j,len;
	ch=DataString[0];
	len=strlen(DataString);
	strcpy(Temp,"");
	while(ch!=' '&&ch!=','&&ch!=';'&&ch!='\n'&&ch!='\t')
	{
	
		Temp[i]=DataString[i];
		i++;
		ch=DataString[i];
	}
	Temp[i]='\0';
	for(j=0;j<len-i;j++)
		DataString[j]=DataString[j+i];
	DataString[j]='\0';
}

__fastcall LDrawCurve::LDrawCurve()
{
		iStartPosi = 1;
        bResult = true;
		bStartLine = false;
        iLineTypeIndex = 0;
        iLineWidthIndex = 0;
        bMemoryAllocated = false;
        bShowTitle = true;
        fYEnlargement = 1000.0;
        strcpy(strXTitle,"采样时间 ( ms )");
        strcpy(strYTitle,"振动加速度 ( g )");
        xPrecision = 0;
        yPrecision = 1;
        clLineColor = clBlack;
        clBkColor = clBtnFace;
        clTextColor = clBlack;
        bFromBegining = false;
        bFixYMax = false;
        bMinZero = true;
//        bPBorPrn=false;
        iDeviceType = 1;
        bDrawText = false;
        bDrawDirection = false; //正常绘图，当为true时，反方向绘图
        bLevel = false;
        iDrawTimes = 0;
        iPrnSign = 1;
        strDrawText = "";
        iFontSize = 8;
        iFontHeight = IFONTHEIGHT;
        bMMValue = false;
		iSymbol = 0;
        ffLevel = 0.8;
        bRealPipe = false;
        iLabelFormat = 0;
        fXPFactor = 1.0;
        fYPFactor = 1.0;
        bDrawGrid = false;
        bShowInfo = false;
        sfPeakLevel = 0.5;
        sbCPeak = false;
        sbCPeriod = false;
        sbCCoef = false;
        sbGaugeAdjust = true;
        bZeroLine = false;
        bXLogValue = false;
        bYLogValue = false;
        bTDCDraw   = false;
        iDrawLineWidth = 1;
        bDifferentColor = true;
        clColor1        = clGray;
        clColor2        = clMaroon;
        clColor3        = clRed;
        clColor4        = clBlack;
        bSolidYMax      = false;
        bXVolumn   = false;
        fXData     = NULL;
        fYData     = NULL;
        fPData     = NULL;
        fCPData    = NULL;
        bDrawPWave = false;
        bDrawCWave = false;
        bShowCut   = false;
        bCompare   = false;
        bMerge      = false;
        iCurveIndex = 0;

        strBasicFontName   = "Arial";
        iBasicFontSize     = 10;
        bBasicFSBold       = true;
        bBasicFSItalic     = false;
        bBasicFSUnderline  = false;
        bBasicFSStrikeOut  = false;
        clBasicFSColor     = clBlack;
        bDrawBasicCurve    = false;
        bPSTDrawAll        = false;   //用于决定是否将图形绘制在一起
        iPSTCurveIndex        = 0;   //用于设置当前绘制的是第几个波形
        CURVECOLOR[0] =   (TColor)RGB(80,80,80);
        CURVECOLOR[0] =   clMaroon;
        CURVECOLOR[0] =   clGreen;
        CURVECOLOR[0] =   clOlive;
        CURVECOLOR[0] =   clNavy;
        CURVECOLOR[0] =   clPurple;
        CURVECOLOR[0] =   clTeal;
        CURVECOLOR[0] =   clLime;
        CURVECOLOR[0] =   (TColor)RGB(100,0,0);
        CURVECOLOR[0] =   clYellow;
        CURVECOLOR[0] =   (TColor)RGB(0,100,0);
        CURVECOLOR[0] =   clFuchsia;
        CURVECOLOR[0] =   (TColor)RGB(100,100,0);
        CURVECOLOR[0] =   clAqua;
        CURVECOLOR[0] =   (TColor)RGB(0,100,100);
        CURVECOLOR[0] =   clRed ;
        fOilGain      =   1.0;
        bDrawDetect   = false;    //不对参数及分析结果进行绘制
}

void __fastcall LDrawCurve::SetstrTime(AnsiString strtt)
{
    strTime = strtt;
}

void __fastcall LDrawCurve::SetfPFactor(float fx,float fy)
{
    fXPFactor = fx;
    fYPFactor = fy;
    float ftemp;
    if(iDeviceType == 0)
    {
        iPrintHeight = iFontHeight + IDECREASEHEIGHT;
    }
    else
    {
        iPrintHeight = iFontHeight;
    }

    ftemp = fabs(fYPFactor);

    if(fXPFactor - ftemp >0.0)
    {
        iPrintHeight = (int)((float)iPrintHeight*ftemp);
    }
    else
    {
        iPrintHeight = (int)((float)iPrintHeight*fXPFactor);
    }
}

void __fastcall LDrawCurve::DrawCoor(TObject *Sender)
{
//确定字体的大小

        if(bLabelSign)
        {   //将每个Y方向的iPrnSign去掉了
      	    iYMax = OuterRect.Top + OuterRect.Height()- 50.0*fYPFactor;
            iXMax = OuterRect.left + OuterRect.Width()-20.0*fXPFactor;
            iXMin = OuterRect.left + 70.0*fXPFactor;
       	    iYMin = OuterRect.Top + 20.0*fYPFactor;
        }
        else
        {
                if(bNumSign)
                {
           	            iYMax=OuterRect.bottom - 30.0*fYPFactor;
               	        iXMax=OuterRect.right - 5.0*fXPFactor;
                       	iXMin=OuterRect.left + 30.0*fXPFactor;
                       	iYMin=OuterRect.Top + 5.0*fYPFactor;
                }
                else
                {
                        if(iDeviceType == 1)
                        {
                            iYMax=OuterRect.bottom - 2.0*fYPFactor;
                        }
                        else
                        {
                            iYMax=OuterRect.bottom - 6.0*fYPFactor;
                        }
             	        iXMax=OuterRect.right - 2.0*fXPFactor;
                       	iXMin=OuterRect.left + 2.0*fXPFactor;
       	                iYMin=OuterRect.Top + 2.0*fYPFactor;
                }
        }

        ptCanvas->Pen->Style = (TPenStyle)LineType[iLineTypeIndex];
        ptCanvas->Pen->Mode  = pmCopy;
        ptCanvas->Pen->Color = clLineColor;
        ptCanvas->Pen->Width = LineWidth[iLineWidthIndex];
        SetBkMode(ptCanvas->Handle,TRANSPARENT);
        ptCanvas->Pen->Width = 1;

	ptCanvas->MoveTo(iXMin,iYMax);
	ptCanvas->LineTo(iXMax,iYMax);
	ptCanvas->LineTo(iXMax,iYMin);
	ptCanvas->LineTo(iXMin,iYMin);
	ptCanvas->LineTo(iXMin,iYMax);
    rectDraw.Left=iXMin;
    rectDraw.Top=iYMin;
    rectDraw.Right=iXMax;
    rectDraw.Bottom=iYMax;
}
void __fastcall LDrawCurve::CalculateCoor(void)
{
   int i,itemp;
   if((!bMMValue)&&(!bTwoInfo))  //在对象外设置绘图坐标
   {
     	fYDataMax  = fYData[iDrawRgStart];
		fYDataMin  = fYData[iDrawRgStart];
        if(bRealPipe)
        {
            fYDataMin  = 0.0;
            fYDataMax  = 100.0;
        }
        else
        {
		    for(i = iDrawRgStart + 1;i<iDrawRgEnd; i++)
		    {
			    if(fYDataMax < fYData[i])
                {
				    fYDataMax = fYData[i];
                }
    			else if(fYDataMin > fYData[i])
                {
	    			fYDataMin = fYData[i];
                }
		    }
    	    if(fabs(fYDataMax-fYDataMin)<0.0000001)
   	    	{
                fYDataMax = 0.0001;
          	    fYDataMin = 0.0;
        	}

            itemp = (int)fYDataMax;
            if((itemp < 10)&&(itemp > 0))
            {
                itemp = fYDataMax*10.2;

                fYDataMax = (float)itemp/10.0;
                itemp     = (int)fYDataMin;
                itemp     = (fYDataMin*10.2);
                fYDataMin = (float)itemp/10.0;
            }
            else
            {
                itemp     = (itemp/10)*10+10;
                fYDataMax = (float)itemp;
                itemp     = (int)fYDataMin;
                itemp     = (itemp/10)*10-10;
                fYDataMin = (float)itemp;
            }
        }
        if(bTwoInfo)
        {
            if(fYDataMin>0.0)
            {
                fYDataMin = 0.0;
            }
        }
    }

    if(bTwoInfo)
    {
        fXDataMin = fXData[iDrawRgStart];
        fXDataMax = fXData[iDrawRgStart];
        for(int m=iDrawRgStart;m<iDrawRgEnd - 1;m++)
        {
            if(fXDataMin >fXData[m])
            {
                fXDataMin = fXData[m];
            }
            else if(fXDataMax < fXData[m])
            {
                fXDataMax = fXData[m];
            }
        }
        if((fXDataMin > 0.0)&&(bFromBegining))
        {
            if(!bXLogValue)
            {
                fXDataMin = 0.0;
            }
        }
        else if(fXDataMax<0.0)
        {
            fXDataMin -= 2.0;
            fXDataMax += 1.0;
        }
        if(!bSolidYMax)  //如果Y方向最大值已固定
        {
            fYDataMin = fYData[0];
            fYDataMax = fYData[0];
            for(int m = 0; m < iPLength;m++)
            {
                if(fYDataMin >fYData[m])
                {
                    fYDataMin = fYData[m];
                }
                else if(fYDataMax < fYData[m])
                {
                    fYDataMax = fYData[m];
                }
            }

            if( fYDataMin>0.0)
            {
                if(!bYLogValue)
                {
                    fYDataMin = 0.0;
                }
            }
            if(fYDataMax < 0.0)
            {
//                fYDataMax += 1.0;
                fYDataMax = 0.0;
            }
            else
            {
//                fYData  += 10.0;
                fYDataMax *= 1.25;
            }

            if( (fYDataMax + fYDataMin) < 0.0 )
            {
                fYDataMin = -fYDataMax/8.0;
            }
        }
        else
        {

            if(fYMin < 0.0)
            {
                fYDataMin = fYMin;
            }
            else
            {
                fYDataMin = 0.0;
            }

            if(fYMax < 0.0)
            {
                fYDataMax = 0.0;
            }
            else
            {
                fYDataMax = fYMax;
            }

        }
    }
    else
    {
    	if(bFromBegining)
        {
    	    fXDataMin=0.0;
        	fXDataMax=(iDrawRgEnd-iDrawRgStart)*fDeltaTime;
        }
        else
        {
          	fXDataMin = iDrawRgStart*fDeltaTime;
        	fXDataMax = iDrawRgEnd*fDeltaTime;
        }
    }
    if(bTwoInfo)
    {
        if(fYDataMax - fYDataMin < 1.0E-7)
        {
            fXStep = 1.0;
            fYStep = 1.0;
        }
        else
        {
	        fXStep = (float)(iXMax-iXMin)/(fXDataMax - fXDataMin);
	        fYStep = (float)(iYMax-iYMin)/(fYDataMax - fYDataMin);
        }
    }
    else
    {

	    fXStep = (float)(iXMax-iXMin)/(iDrawRgEnd-iDrawRgStart+1);
	    fYStep = (float)(iYMax-iYMin)/(fYDataMax-fYDataMin);
    }
}

void __fastcall LDrawCurve::SetsgfFrequency(float* fc,int n)
{
   for(int i=0;i<n;i++)
   {
      sgfFrequency[i]=fc[i];
   }
}

void __fastcall LDrawCurve::SetsfGConst(float* fg,int n)
{
    for(int i=0;i<n;i++)
    {
        sfGConst[i]=fg[i];
    }
}
void __fastcall LDrawCurve::DrawCurve(TObject* Sender)
{
        int i,itemp,ygap;
        char strTemp[100];
        int penwidth;
        int ihalf14,ihalf24,ihalf34;
        AnsiString strSpeed;
        penwidth = ptCanvas->Pen->Width;
        if(iDeviceType == 0)
        {
            ptCanvas->Pen->Width = 2;
        }
        ptCanvas->Font->Height = iPrintHeight;
        int iwidthbackup;
        if(bXVolumn)
        {
            ihalf14 = iDrawRgEnd/4;
            ihalf24 = iDrawRgEnd/2;
            ihalf34 = iDrawRgEnd*3/4;
        }
        if(!bDrawDirection)
        {
        	iX = iXMin + (int)((float)(fXData[iDrawRgStart]-fXDataMin)*fXStep);
	        iY = iYMax - (int)((float)(fYData[iDrawRgStart]-fYDataMin)*fYStep);
        	ptCanvas->MoveTo(iX,iY);
/*
            TColor clbk,clbbk;
            clbk  = ptCanvas->Font->Color;
            clbbk = ptCanvas->Brush->Color;
*/            
            ptCanvas->Font->Color  = clLineColor;
            ptCanvas->Brush->Color = clLineColor;
            ptCanvas->Pen->Color   = clLineColor;
            iwidthbackup           = ptCanvas->Pen->Width;
            ptCanvas->Pen->Width   = iDrawLineWidth;
	        for(i = iDrawRgStart; i < iDrawRgEnd; i ++)
        	{
                if(bDifferentColor)   //如果需要对线条的颜色进行设置
                {
                    if(bPSTDrawAll)
                    {
                        ptCanvas->Pen->Color = CURVECOLOR[iPSTCurveIndex];
                    }
                    else
                    {
                        if(bXVolumn)  //如果横坐标是容积
                        {
                            if( i <= ihalf14)
                            {
                                ptCanvas->Pen->Color = clColor1;
                            }
                            else if((i > ihalf14)&&(i <= ihalf24))
                            {
                                ptCanvas->Pen->Color = clColor2;
                            }
                            else if((i > ihalf24)&&(i <= ihalf34))
                            {
                                ptCanvas->Pen->Color = clColor3;
                            }
                            else if((i > ihalf34))
                            {
                                ptCanvas->Pen->Color = clColor4;
                            }
                        }
                        else
                        {
                            if( (fXData[i] >= -360.0)&&(fXData[i] <= -180.0) )
                            {
                                ptCanvas->Pen->Color = clColor1;
                            }
                            else if((fXData[i] > -180.0)&&(fXData[i] <= 0.0))
                            {
                                ptCanvas->Pen->Color = clColor2;
                            }
                            else if((fXData[i] > 0.0)&&(fXData[i] <= 180.0))
                            {
                                ptCanvas->Pen->Color = clColor3;
                            }
                            else if((fXData[i] > 180.0)&&(fXData[i] <= 360.0))
                            {
                                ptCanvas->Pen->Color = clColor4;
                            }
                        }
                    }
                }
                else
                {
                    if(bPSTDrawAll)
                    {
                        ptCanvas->Pen->Color = CURVECOLOR[iPSTCurveIndex - 1];
                    }
                }

                if(fXData[iDrawRgStart]>0.0)
                {
                    iDrawRgStart = iDrawRgStart;
                }
                if(bTwoInfo)
                {
                   	iX = iXMin + (int)((float)(fXData[i]-fXDataMin)*fXStep);
                }
                else
                {
                   	iX = iXMin + (int)((float)(i-iDrawRgStart)*fXStep);
                }
		        iY = iYMax - (int)((fYData[i] - fYDataMin)*fYStep);
        	    switch(iSymbol)
                {
                	case 1:
                    	ptCanvas->Ellipse(iX-3,iY-3,iX+3,iY+3);
                    	break;
                    case 2:
                    	ptCanvas->Rectangle(iX-3,iY-3,iX+3,iY+3);
                    	break;
                	case 3:
                    	ptCanvas->FillRect(TRect(iX-3,iY-3,iX+3,iY+3));
                    	break;
                    case 4:
                    	ptCanvas->TextOut(iX,iY,"*");
                    	break;
                }
                ptCanvas->LineTo(iX,iY);
            }
            TColor pencolor;
            ptCanvas->Pen->Width = iwidthbackup;
            if(bTwoInfo)
            {
                if(fXDataMin < 0.0)
                {
                    pencolor = ptCanvas->Pen->Color;
                    ptCanvas->Pen->Color = clBlue;
                    iX = iXMin -(int)(fXDataMin*fXStep);
                    iY = iYMax;
                    ptCanvas->MoveTo(iX,iY);
                    iY = iYMin;
                    ptCanvas->LineTo(iX,iY);
  		            iY = iYMax + (int)((fYDataMin)*fYStep);
                    ptCanvas->MoveTo(iXMin,iY);
                    ptCanvas->LineTo(iXMax,iY);
                    ptCanvas->Pen->Color = pencolor;
                }
            }
        }
        else
        {
         	iX = iXMax;
	        iY = iYMax - (int)((float)fYData[iDrawRgStart]*fYStep);
        	ptCanvas->MoveTo(iX,iY);
	        for(i = iDrawRgStart + 1; i < iDrawRgEnd; i ++)
        	{
                if(bTwoInfo)
                {
                    iX = iXMax - (int)((fXData[i]-fXDataMin)*fXStep);
                }
                else
                {
	        	    iX=iXMax-(int)((float)(i-iDrawRgStart)*fXStep);
                }
		        iY = iYMax-(int)(fYData[i]*fYStep);
        		ptCanvas->LineTo(iX,iY);
            }
        }
        if(!bMinZero)
        {
                ptCanvas->Pen->Color = clLime;
                Application->ProcessMessages();
                iY = iYMax+(int)(fYDataMin*fYStep);
                ptCanvas->MoveTo(iXMin,iY);
                ptCanvas->LineTo(iXMax,iY);
                iYMiddle = iY;
        }
        else
        {
            iYMiddle = iYMax;
        }
        if(bStartLine)
        {
		   //	iY=iYMax;
            ptCanvas->Pen->Width = 2;
	        iX = iXMin + (int)((float)(iStartPosi-iDrawRgStart)*fXStep);
            ptCanvas->MoveTo(iX,iYMax);
	        ptCanvas->LineTo(iX,iYMin);
            ptCanvas->Pen->Width = 1;
        }
        ptCanvas->Pen->Color = clLineColor;

//        Application->ProcessMessages();
           int iwidth,iheight;
           int ixx0, iyy0;
           AnsiString strInfo = "";
           SetBkMode(ptCanvas->Handle,TRANSPARENT);           
           if(bShowMax)   //显示高压油管波形参数
           {
               strInfo.printf("波形峰值:%.2f", sfWavePeak);
               iwidth  = ptCanvas->TextWidth(strInfo);
               iheight = ptCanvas->TextHeight(strInfo);
               if( iDeviceType == 0 )
               {
                    ixx0 = iXMax - iwidth*8/7;
               }
               else
               {
                    ixx0 = iXMax - iwidth - 20;
               }
                iyy0 = iYMin + iPrnSign*2;
               
               ptCanvas->TextOut( ixx0, iyy0, strInfo);

               strInfo.printf("波形时间:%.2f", sfWavePeriod);
               iyy0 += iPrnSign*iheight;
               ptCanvas->TextOut(ixx0, iyy0, strInfo);

               strInfo.printf("波形系数:%.2f", sfWaveFormCoef);
               iyy0 += iPrnSign*iheight;
               ptCanvas->TextOut(ixx0, iyy0, strInfo);

               iyy0 += iPrnSign*iheight;
               ptCanvas->TextOut( ixx0, iyy0, strPipeResult);
           }
        if(bShowInfo && (!bShowMax))
        {
           SetBkMode(ptCanvas->Handle,TRANSPARENT);



           
           if(iDeviceType == 0)  //打印机
           {
//               ptCanvas->Font->Height=-12;
                strInfo.printf("最大值:%.2f",fYVDataMax);
                iwidth  = ptCanvas->TextWidth(strInfo);
                iheight = ptCanvas->TextHeight(strInfo);
                ptCanvas->TextOut(iXMax - iwidth - 15,iYMin + iPrnSign*14, strInfo);

           }
           else
           {

               ptCanvas->Font->Color = clTextColor;
               strInfo.printf(" 最大值:%.2f",fYVDataMax);
               iwidth  = ptCanvas->TextWidth(strInfo);
               iheight = ptCanvas->TextHeight(strInfo);
               if(bMerge)
               {
                    strSpeed.printf("转速:%.1f",fEngineSpeed);
                    strInfo = strTime + ";" + strInfo + ";" + strSpeed;
                    iwidth  = ptCanvas->TextWidth(strInfo);
                    ptCanvas->TextOut(iXMax - iwidth - 15,iYMin + iCurveIndex*iheight + 14,strInfo);
               }
               else
               {
                    if(bPSTDrawAll)
                    {
                        TColor clTemp;
                        clTemp = ptCanvas->Font->Color;
                        strInfo.printf("缸号：%02d  最大值: %.2f", iDieselNum, fYVDataMax);
                        ptCanvas->Font->Color = CURVECOLOR[iPSTCurveIndex];
                        iwidth  = ptCanvas->TextWidth(strInfo);
                        ptCanvas->TextOut(iXMax - iwidth - 15,iYMin + (iPSTCurveIndex)*iheight + 14,strInfo);
                        ptCanvas->Font->Color = clTemp;
                    }
                    else
                    {
                        ptCanvas->TextOut(iXMax - iwidth - 15,iYMin + 20,strInfo);
                    }
               }
           }
        }
        if(bShowTitle)
        {
           int iwidth;

           if(iDeviceType == 0)  //打印机
           {
//               ptCanvas->Font->Height=-12;
               iwidth = ptCanvas->TextWidth(strTitle);
               ptCanvas->TextOut((iXMin + iXMax - iwidth)/2 - 30,iYMin + iPrnSign*1,strTitle);
           }
           else
           {
               ptCanvas->Font->Color  = clTextColor;
              // ptCanvas->Brush->Color = clWhite;
               SetBkMode(ptCanvas->Handle,TRANSPARENT);
               iwidth = ptCanvas->TextWidth(strTitle) + 26;
               ptCanvas->TextOut((iXMin + iXMax - iwidth)/2 - 30,iYMin + iPrnSign*1, strTitle);
           }
        }
        ptCanvas->Pen->Width = penwidth;

}

void __fastcall LDrawCurve::DrawTwoLabel(TObject * Sender)
{
    //TODO: Add your source code here
    //本函数用绘制曲线的坐标线，网格线
    //影响绘图结果的参数主要有：
    // bXLogValue: false:正常数据  true:为对数值
    // bYLogValue: false:正常数据　true:为对数值
    // bDrawGrid:  false:不绘制网络　true:绘制网络
    // bNumSign:   false:显示数字    true:不显示数字
    // bLabelSign: false:不显示
    // bFromBegining ：表示横坐标起始点是0

    int i,itemp,ygap,ixtemp;
    char strTemp[100];
    float fygap,ftemp,fyenlargement;
    int   imaxwidth = 0;
    float fnstep;
    float fXGrid[400];
    float fYGrid[400];
    float fXXMin,fXXMax,fYYMin;  //,fYYMax;
    int iXGridNum,iYGridNum;
    SetBkMode(ptCanvas->Handle,TRANSPARENT);

    ptCanvas->Font->Height = iPrintHeight;

    GetNewCoorSegment(fXGrid,fYGrid,iXGridNum,iYGridNum);

//--------------------------------------------------
//设置X轴向的坐标信息
//==================================================
    if(bXLogValue)
    {
        ftemp = fXDataMin;
        if(ftemp < 1.0e-10)
        {
            ftemp = 1.0e-5;
        }

        fXXMin = 20.0*log10(ftemp);
        ftemp = fXDataMax;
        if(ftemp < 1.0e-10)
        {
            ftemp = 1.0e-5;
        }
        fXXMax = 20.0*log10(ftemp);
    }
    else
    {
        fXXMin = fXDataMin;
        fXXMax = fXDataMax;
    }

//---------------------------------------
//设置Y方向的坐标信息
//=======================================
    if(bYLogValue)
    {
        ftemp = fYDataMin;
        if(ftemp < 1.0e-10)
        {
            ftemp = 1.0e-5;
        }
        fYYMin = 20.0*log10(ftemp);

        ftemp = fYDataMax;
        if(ftemp < 1.0e-10)
        {
            ftemp = 1.0e-5;
        }
//        fYYMax = 20.0*log10(ftemp);
    }
    else
    {
        fYYMin = fYDataMin;
//        fYYMax = fYDataMax;
    }

    if(bDrawGrid)  //如果要画网格线
    {                       //  TPen

        TLogPen logPen;
        HPEN holdPen;
        HPEN hnewPen;
        ::GetObject(ptCanvas->Pen->Handle,sizeof(logPen),&logPen);
        logPen.lopnStyle = PS_DOT; //psDot;
      //     logPen.lopnWidth = 1;
        logPen.lopnColor = clGray;
//        logPen.lopnColor = clInfoBk;
        logPen.lopnWidth.x = 1;
        logPen.lopnWidth.y = 1;   //实际上决定画笔宽度的值是x，y值不起作用
        hnewPen = ::CreatePenIndirect(&logPen);
        holdPen = ::SelectObject(ptCanvas->Handle,hnewPen);

//        ptCanvas->Pen->Width =1 ;
//        ptCanvas->Pen->Style = psDot ;
//        ptCanvas->Pen->Color = clBlack ;
//        ptCanvas->Pen->Mode = pmCopy ;
/*
        if((fXDataMax<1.0)&&(fXDataMax>0.0))
        {
            for(int i=0;i<iXGridNum;i++)
            {
               fXGrid[i] = fXGrid[i]/1000.0;
            }
        }
*/

       	for(i=0;i<iXGridNum;i++)
	    {
            if(fXGrid[i]-fXXMin < 0.0)
            {
                continue;
            }
            else if(fXGrid[i]>fXXMax)
            {
                continue;
            }
	        itemp= iXMin + (int)((fXGrid[i] - fXXMin)*fXStep);
            if((itemp <= iXMin) || (itemp >= iXMax))
            {
                continue;
            }
            ptCanvas->MoveTo(itemp,iYMax);
            ptCanvas->LineTo(itemp,iYMin);
       	}


        for(i=0;i<iYGridNum;i++)
        {
	   	    itemp= iYMax - (int)((fYGrid[i]-fYYMin)*fYStep);
            if((itemp < iYMin)||(itemp > iYMax))
            {
                continue;
            }
            ptCanvas->MoveTo(iXMin,itemp);
            ptCanvas->LineTo(iXMax,itemp);
        }
//恢复所设置的Pen
        ::SelectObject(ptCanvas->Handle,holdPen);
        ::DeleteObject(hnewPen);
    }
//        ptCanvas->Pen->Style = psSolid ;
   	for(i=0; i < iXGridNum; i ++)
    {
        if(fXGrid[i]-fXDataMin<0.0)
        {
            continue;
        }
        else if(fXGrid[i]>fXXMax)
        {
            continue;
        }
        itemp= iXMin+(int)((fXGrid[i]-fXXMin)*fXStep);
        if((itemp <= iXMin) || (itemp >= iXMax))
        {
            continue;
        }
        ptCanvas->MoveTo(itemp,iYMax);
        ptCanvas->LineTo(itemp,iYMax-iPrnSign*5);
   	}
    for(i=1;i<iYGridNum;i++)
    {
      	itemp= iYMax - (int)(((float)fYGrid[i] - fYYMin)*fYStep);
        if((itemp < iYMin)||(itemp > iYMax))
        {
            continue;
        }
        ptCanvas->MoveTo(iXMin,itemp);
	    ptCanvas->LineTo(iXMin+5,itemp);
    }
                //以上的代码主要用于绘制网格线
//以下代码用于显示数字
    if(bNumSign)
    {
      	for(i=0;i<iXGridNum;i++)
        {
            if(fXGrid[i]-fXXMin<0.0)
            {
                continue;
            }
            else if(fXGrid[i]>fXXMax)
            {
                continue;
            }
            itemp= iXMin+(int)((fXGrid[i]-fXXMin)*fXStep);
            ptCanvas->MoveTo(itemp,iYMax);
            ptCanvas->LineTo(itemp,iYMax-iPrnSign*5);
      	}
        for(i=0;i<iYGridNum;i++)
      	{
        	itemp= iYMax - (int)((fYGrid[i]-fYYMin)*fYStep);
            if((itemp < iYMin)||(itemp > iYMax))
            {
                continue;
            }
            ptCanvas->MoveTo(iXMin,itemp);
            ptCanvas->LineTo(iXMin+5,itemp);
        }
        //以下的代码用于显示坐标值　
       	for(i=0;i<iXGridNum;i++)   //绘制x方向的坐标值　
        {
            if(fXGrid[i]-fXXMin<0.0)
            {
                continue;
            }
            else if(fXGrid[i]>fXXMax)
            {
                continue;
            }
           	itemp= iXMin+(int)((fXGrid[i] - fXXMin)*fXStep);
            switch(xPrecision)
            {
                case 0:
                {
                    sprintf(strTemp,"%d",(int)fXGrid[i]);
                    break;
                }
                case 1:
                {
                    sprintf(strTemp,"%.1f",fXGrid[i]);
                    break;
                }
                case 2:
                {
                     sprintf(strTemp,"%.2f",fXGrid[i]);
                     break;
                }
                case 3:
                {
                     sprintf(strTemp,"%.3f",fXGrid[i]);
                     break;
                }
                case 4:
                {
                     sprintf(strTemp,"%.4f",fXGrid[i]);
                     break;
                }
            }

            int iwidth=ptCanvas->TextWidth(strTemp);
            ptCanvas->TextOut(itemp-iwidth/2,iYMax+iPrnSign*5,strTemp);
        }
        for(i=0;i<iYGridNum;i++)   //绘制Y方向的坐标值　
	    {
          	itemp= iYMax - (int)((fYGrid[i]-fYYMin)*fYStep);
            if((itemp < iYMin)||(itemp > iYMax))
            {
                continue;
            }
            switch(yPrecision)
            {
                case 0:
                {
                     sprintf(strTemp,"%d",(int)fYGrid[i]);
                     break;
                }
                case 1:
                {
                     sprintf(strTemp,"%.1f",fYGrid[i]);
                     break;
                }
                case 2:
                {
                     sprintf(strTemp,"%.2f",fYGrid[i]);
                     break;
                }
                case 3:
                {
                     sprintf(strTemp,"%.3f",fYGrid[i]);
                     break;
                }
                case 4:
                {
                     sprintf(strTemp,"%.4f",fYGrid[i]);
                     break;
                }
            }

            int iwidth  = ptCanvas->TextWidth(strTemp) + 5;
            int iheight = ptCanvas->TextHeight(strTemp);
            if(iwidth > imaxwidth)
            {
                 imaxwidth = iwidth;
            }
            ptCanvas->TextOut(iXMin-iwidth,itemp-iheight*iPrnSign/2,strTemp);
        }
    }
    ptCanvas->Font->Color=clTextColor;
    if(bLabelSign)
    {
        int iheight;
        int iPHeight;
        int iwidth=ptCanvas->TextWidth(strXTitle);
        ptCanvas->TextOut((iXMin+iXMax-iwidth)/2,iYMax+20*fYPFactor,strXTitle);
        try
        {
            TLogFont logFont;
            HFONT holdFont;
            HFONT hnewFont;
            ::GetObject(ptCanvas->Font->Handle,sizeof(logFont),&logFont);
            if(iDeviceType == 0)
            {
                logFont.lfEscapement  = -900;
                logFont.lfOrientation = -900;
            }
            else
            {
                logFont.lfEscapement  = 900;
                logFont.lfOrientation = 900;
            }
            hnewFont = ::CreateFontIndirect(&logFont);
            holdFont = ::SelectObject(ptCanvas->Handle,hnewFont);
            iwidth = ptCanvas->TextHeight(strYTitle);
            iheight = ptCanvas->TextWidth(strYTitle);
//            ptCanvas->TextOut(iXMin-imaxwidth-iwidth-6,((iYMax+iYMin)/2+iPrnSign*iheight/2),strYTitle);
            ptCanvas->TextOut(   iXMin - imaxwidth - iwidth - 6,
                               ((iYMax + iYMin)/2 + iPrnSign*iheight/2),
                               strYTitle
                              );
            ::SelectObject(ptCanvas->Handle,holdFont);
            ::DeleteObject(hnewFont);
        }
        catch(...)
        {
       	    Application->MessageBox("绘图过程出现错误","错误",MB_OK);
            return;
        }
    }
}

void __fastcall LDrawCurve::DrawLabel(TObject* Sender)
{
        int i,itemp,ixtemp;
        char strTemp[100];
        float fygap,ftemp;
//        float fyenlargement;
        int imaxwidth;
        SetBkMode(ptCanvas->Handle,TRANSPARENT);

        if(bNumSign)
        {
        	if(bFromBegining)
            {
        		GetCoorSegment(0,iDrawRgEnd-iDrawRgStart+1,xxseg);
            }
            else
            {
         		GetCoorSegment(iDrawRgStart,iDrawRgEnd,xxseg);
            }
	        xxsegnum=(iDrawRgEnd-iDrawRgStart+1)/xxseg;
 //       	GetCoorSegment(0,(int)(fYEnlargement*fYDataMax),yyseg);
  //	        yysegnum=(int)(fYDataMax*fYEnlargement/yyseg);
            int iPw = ptCanvas->Pen->Width;
            TPenMode Pm;
            Pm = ptCanvas->Pen->Mode;

        	for(i=1;i<=xxsegnum;i++)
	        {
		        itemp= iXMin+(int)((float)(i*xxseg)*fXStep);
                ptCanvas->MoveTo(itemp,iYMax);
                ptCanvas->Pen->Mode = pmCopy;
                if(bDrawGrid)
                {

                    ptCanvas->Pen->Width = 1;
                    ptCanvas->Pen->Color = clGray;
                    if(iDeviceType == 0)
                    {
                        ptCanvas->Pen->Style = psDot;
                    }
                    else
                    {
                        ptCanvas->Pen->Style = psDot;
                    }
                    ptCanvas->MoveTo(itemp,iYMax);
                    ptCanvas->LineTo(itemp,iYMin);
                }
                ptCanvas->Pen->Mode  = Pm;
                ptCanvas->Pen->Width = iPw;
                ptCanvas->Pen->Color = clTextColor;
                ptCanvas->Pen->Style = psSolid;
                ptCanvas->MoveTo(itemp,iYMax);
                ptCanvas->LineTo(itemp,iYMax-iPrnSign*10);

        	}
            fygap=fYDataMax/5.0;
            itemp=(int)fygap;
            if(itemp>100)
            {
            	itemp=(itemp/10)*10+10;
            }
            else if(itemp>10)
            {
            	itemp=((itemp-1)/5)*5+5;
            }
            else if(itemp>1)
            {
            	itemp=((itemp-1)/2)*2+2;
            }
            else
            {
 //               itemp=floor(fYDataMax+1.0);
            }
 //           fyenlargement=1.0;
            fygap=(float)itemp;


            if(itemp==0)
            {
            	fygap=fYDataMax/10.0;
                yysegnum=10;
  			}
            else
	            yysegnum=(int)(fYDataMax/fygap);
            yyseg=fygap;
            int ittt;
            Pm = ptCanvas->Pen->Mode;
            iPw = ptCanvas->Pen->Width ;
            for(i=1;i<yysegnum;i++)
        	{
	        	itemp= iYMiddle-(int)((float)(i*yyseg)*fYStep);
		        ptCanvas->MoveTo(iXMin,itemp);
                if(bDrawGrid)
                {
                    ptCanvas->Pen->Width = 1;
                    ptCanvas->Pen->Mode  = pmCopy;
                    ptCanvas->Pen->Color =clGray;
                    if(iDeviceType == 0)
                        ptCanvas->Pen->Style = psDot;
                    else
                        ptCanvas->Pen->Style = psDot;
                    ptCanvas->MoveTo(iXMin,itemp);
                    ptCanvas->LineTo(iXMax,itemp);
                }
                ptCanvas->Pen->Mode  = Pm;
                ptCanvas->Pen->Color =clTextColor;
                ptCanvas->Pen->Style =psSolid;
                ptCanvas->MoveTo(iXMin,itemp);
                ptCanvas->LineTo(iXMin+10,itemp);

	        }
            if(bDrawGrid)  //恢复原来的设置
            {
                ptCanvas->Pen->Color=clTextColor;
                ptCanvas->Pen->Style=psSolid;
            }
            ittt=-(int)(fYDataMin/fygap);
            for(i=1;i<=ittt;i++)
            {
	        	itemp= iYMiddle+(int)((float)(i*yyseg)*fYStep);
		        ptCanvas->MoveTo(iXMin,itemp);
        		ptCanvas->LineTo(iXMin+10,itemp);

            }
          //  TCanvas
            ptCanvas->Font->Color=clTextColor;

	        for(i=0;i<=xxsegnum;i++)
        	{
	        	itemp= iXMin+(int)((float)(i*xxseg)*fXStep);
                if(bFromBegining)
                {
                	ftemp=fDeltaTime*(i*xxseg);
                }
                else
                {
                   	ftemp=fDeltaTime*(iDrawRgStart+i*xxseg);
                }
                switch(xPrecision)
                {
                    case 0:
                         sprintf(strTemp,"%d",(int)ftemp);
                         break;
                    case 1:
                         sprintf(strTemp,"%.1f",ftemp);
                         break;
                    case 2:
                         sprintf(strTemp,"%.2f",ftemp);
                         break;
                    case 3:
                         sprintf(strTemp,"%.3f",ftemp);
                         break;
                    case 4:
                         sprintf(strTemp,"%.4f",ftemp);
                         break;
                 }
                 if(iDeviceType != 0)
                 {
                    ptCanvas->Font->Color=clTextColor;
                 }
                 int iwidth=ptCanvas->TextWidth(strTemp);
                 ptCanvas->TextOut(itemp-iwidth/2,iYMax+iPrnSign*5,strTemp);
	        }
//            ygap=0;
            sprintf(strTemp,"%.1f",fYDataMax);
            ittt=strlen(strTemp)*8+4;
            sprintf(strTemp,".1f",fYDataMin);
            ixtemp=strlen(strTemp)*8+4;
            if(ittt>ixtemp)	ixtemp=ittt;
//            ygap = ixtemp+4;
/*            int iii;
            float yyseg_backup;
            yyseg_backup=yyseg;
            iii=yyseg*10;
            yyseg=((float)iii/10.0);
*/
            for(i=0;i<=yysegnum;i++)
        	{
	        	itemp= iYMiddle-(int)((float)(i*yyseg)*fYStep);
                switch(yPrecision)
                {
                    case 0:
                        sprintf(strTemp,"%d",(int)(i*yyseg));
                        break;
                    case 1:
                        sprintf(strTemp,"%.1f",(float)i*yyseg);
                        break;
                    case 2:
                         sprintf(strTemp,"%.2f",(float)i*yyseg);
                         break;
                    case 3:
                          sprintf(strTemp,"%.3f",(float)i*yyseg);
                          break;
                    case 4:
                          sprintf(strTemp,"%.4f",(float)i*yyseg);
                          break;
                    }

                 if(iDeviceType != 0)
                 {
                    ptCanvas->Font->Color=clTextColor;
                 }
                 imaxwidth=0;
                 int iwidth=ptCanvas->TextWidth(strTemp)+5;
                 int iheight=ptCanvas->TextHeight(strTemp);
                 if(iwidth>imaxwidth)
                    imaxwidth=iwidth;
                 ptCanvas->TextOut(iXMin-iwidth,itemp-iheight*iPrnSign/2,strTemp);
        	}
            yysegnum=-(int)fYDataMin/fygap;

            for(i=1;i<=yysegnum;i++)
        	{
	        	itemp= iYMiddle+(int)((float)(i*yyseg)*fYStep);
                switch(yPrecision)
                {
                    case 0:
                        sprintf(strTemp,"%d",-(int)(i*yyseg));
                        break;
                    case 1:
                        sprintf(strTemp,"%.1f",-(float)i*yyseg);
                        break;
                    case 2:
                         sprintf(strTemp,"%.2f",-(float)i*yyseg);
                         break;
                    case 3:
                          sprintf(strTemp,"%.3f",-(float)i*yyseg);
                          break;
                    case 4:
                          sprintf(strTemp,"%.4f",-(float)i*yyseg);
                          break;
                    }
//                    ittt=strlen(strTemp)*8+4;
                    int iwidth=ptCanvas->TextWidth(strTemp);
                    int iheight=ptCanvas->TextHeight(strTemp);
                    ptCanvas->TextOut(iXMin-iwidth-5,itemp-iPrnSign*iheight/2,strTemp);
//                    if(ittt>ygap) ygap=ittt;
        	}
            if(bLabelSign)
            {
                int iwidth=ptCanvas->TextWidth(strXTitle);
                ptCanvas->TextOut((iXMin+iXMax-iwidth)/2,iYMax+22*iPrnSign,strXTitle);
                try
                {
                        TFont* pfont;
                        TFont* pbkfont;
                        TLogFont lf;
                        pfont=new TFont;
                        pbkfont=new TFont;
                        pbkfont->Assign(ptCanvas->Font);
                        pfont->Assign(ptCanvas->Font);
                        pfont->Color=clTextColor;
                        ::GetObject(pfont->Handle,sizeof(lf),&lf);
                        lf.lfEscapement=900;
                        lf.lfOrientation=900;
                        pfont->Handle=::CreateFontIndirect(&lf);
                        if(iDeviceType==0)
                        {
                            pfont->Height = iPrintHeight;
                        }
                        ptCanvas->Font->Assign(pfont);
                        iwidth=ptCanvas->TextHeight(strYTitle);
                        int iheight;
                        iheight=ptCanvas->TextWidth(strYTitle);
                        if(iDeviceType>0)
                   	        ptCanvas->TextOut(iXMin-imaxwidth-iwidth-6,((iYMax+iYMin)/2+iPrnSign*iheight/2),strYTitle);

               //         ptCanvas->TextOut(iXMin-ygap-20,(iYMin+iYMax-strlen(strYTitle))/2,strYTitle);
                        ptCanvas->Font->Assign(pbkfont);
                        delete pbkfont;
                        delete pfont;

               }
               catch(...)
               {
                 	Application->MessageBox("绘图过程出现错误","错误",MB_OK);
                    return;
               }
           }
        }
}
void __fastcall LDrawCurve::GetCoorSegment(int imin,int imax,int & iseg)
{
	//TODO: Add your source code here
	int sign[4]={0,0,0,0};
	int segment,segback,pos;
	segment=imax-imin;
	pos=0;
	while((segment=segment/10)>0)
	{
		sign[pos]=1;
		segback=segment;
                pos++;
	}
	segment=1;
	for(pos=1;pos<4;pos++)
	{
		if(sign[pos]==1)
		{
			segment=segment*10;
		}
	}
	iseg=segback*segment;
	if(iseg==0) iseg=1;
    return;
}


bool __fastcall LDrawCurve::ReadAllData(String &fn)
{
        //TODO: Add your source code here
    int ilen,iTemp;
    void* strBuffer;


    if((pipeDatafp=fopen(fn.c_str() ,"rb"))==NULL)
	{
	//   Application->MessageBox("文件打开错误","提示",MB_OK);
        return false;
	}
    strBuffer=(void*)(&lfhs);
    lShort ls;
    fread(strBuffer,sizeof(lFileHeadStruct),1,pipeDatafp);
    iTrainType = lfhs.siTrainType;
    ilen=lfhs.iLength;
    if(ilen>8000)
    {
       ilen=8000;
       lfhs.iLength=ilen;
    }
    iDrawRgStart=0;
    iDrawRgEnd=ilen;
//    lfhs.strTrainNum[4]='\0';
    iDataLength=ilen;

    if(!AllocateMemory(iDataLength))
        return false;

    float ftemp1,ftemp2;
    ftemp2=sgfFrequency[lfhs.siFrequency-1];
    if(ftemp2<1.0||ftemp2>100.0) ftemp2=19.2;
    sfTimeInterval=1.0/ftemp2;
//  int igauge = lfhs.siGauge;
    int igauge = 35;
    int itraintype=lfhs.siTrainType;
//归一化处理  2002_09_23
    if(sbGaugeAdjust)
    {
        ftemp1 = (1.0+sfGConst[itraintype])/(1.0+igauge/5.0);
    }
    else
    {
        ftemp1 = 1.0;
    }

    for(iTemp=0;iTemp<ilen;iTemp++)
    {
        fread(ls.ch,2,1,pipeDatafp);
        fYData[iTemp]=ls.iData/1000.0;
        fYData[iTemp]=(fYData[iTemp]-1.23)*ftemp1+1.23;
        if(fYData[iTemp]<0.0) fYData[iTemp]=0.1;
    }
    fclose(pipeDatafp);

    fDeltaTime=1.0/(float)sgfFrequency[lfhs.siFrequency-1];
    AnsiString strrr;
    strrr=lfhs.strTrainNum;
    strrr.c_str()[4]='\0';
    if(iLabelFormat==0)
        sprintf(strTitle,"车号：%s; 缸号：%d",strrr.c_str(),lfhs.siDieselNum);
    else if(iLabelFormat==1)
    {
       sprintf(strTitle,"车号:%s; 缸号:%d",strrr.c_str(),lfhs.siDieselNum);
    }
    else if(iLabelFormat==2)
    {
        sprintf(strTitle,"缸号:%d",lfhs.siDieselNum);
    }
    else if(iLabelFormat==3)  //显示故障类型
    {
        sprintf(strTitle,"%s", strDrawText.c_str());
    }
    else if(iLabelFormat == 4)
    {
        sprintf(strTitle,"车号:%s; 缸号:%d  %s",
                            strrr.c_str(),
                            lfhs.siDieselNum,
                            strDrawText.c_str());
    }
    if(bShowInfo)
        CalculateParameters();
    return true;

}

void __fastcall LDrawCurve::CalculateParameters(void)
{
    //TODO: Add your source code here
    int i,j,imaxposi=0,istartposi=0,iendposi=0,isb;
    float fmax,ftemp,fmother;
    bool bstart=false,bend=false;
    int iLenCal,iLenTest;
    float flArray[400],flNorm[400];
    fmax=0.0;
    FILE* fp;

//在绘定范围内查找最大值及其位置
    siStartPosi=50;
    if(iDataLength<8000)
    {
        iendposi=siStartPosi+200;
    }
    else
    {
        iendposi=siStartPosi+6000;
    }
    if(iendposi>iDataLength)
    {
        iendposi=iDataLength;
    }
    for(i=siStartPosi;i<iendposi;i++)
    {
        if(fmax<fYData[i])
        {
            fmax=fYData[i];
            imaxposi=i;
        }
    }
    sfMainMax=fmax;
    i=imaxposi-80;
    if(i<=0)
    {
        i=0;
    }
    iLenTest = i+399;
    if(iLenTest > iDataLength)
    {
        iLenTest = iDataLength;
    }
    iLenCal = iLenTest - i;
    if(iLenCal <= 0)
    {
        return;
    }
    for(int m=i; m<iLenTest;m++)
    {
        flArray[m-i]=fYData[m];
    }

    ftemp=0.0;
    for(j=3;j<6;j++)
        ftemp+=flArray[j];
    ftemp/=3.0;
//    faverage=ftemp;
//    fBMax=fmax;


//归一化处理   2002_09_23
    sfWavePeak=(fmax-ftemp);
    fmax=ftemp+(fmax-ftemp)*sfPeakLevel;
/*
    if(iDataLength==8000)
    {
        i=imaxposi-80;
        if(i<0) i=5;
        siStartPosi=i;
    }
    else
    {
        siStartPosi=50;
        i=siStartPosi;
    }
    j=i+200;
    if(j>iDataLength) j=iDataLength;
    isb=i;
*/
    fmother=sfMainMax-ftemp;
    if(fmother<0.00001)
    {
        fmother=1.0;
    }

    for(i=0;i<iLenCal;i++)
    {
        flArray[i]=(flArray[i]-ftemp)/fmother;
    }

    for(i=3;i<iLenCal;i++)
    {
         if(flArray[i]>sfPeakLevel)
         {
            if(!bstart)
            {
                istartposi=i;
                bstart=true;
            }

         }
         else if((flArray[i]<sfPeakLevel)&&bstart&&(!bend))
         {
            iendposi=i;
            bend=true;
         }
         if((flArray[i]>sfPeakLevel)&&bend)
         {
            bend=false;
         }
    }
    if(bend==false)
    {
        iendposi = iLenCal - 1;
    }
    sfWavePeriod=(iendposi-istartposi)*sfTimeInterval;
    int isumnum,itempposi;

    for(i=istartposi;i<iLenCal;i++)
    {
        isumnum=0;
        flNorm[i]=0.0;
        for(int m=-siHalfWin;m<siHalfWin+1;m++)
        {
            itempposi=i+m;
            if(itempposi<0) continue;
            if(itempposi>= iLenCal) break;
            flNorm[i]+=flArray[itempposi];
            isumnum++;
        }
        if(isumnum == 0)
        {
            flNorm[i] = 0.0;
        }
        else
        {
            flNorm[i]/=(float)isumnum;
        }
    }
    float flssum=0.0;
    for(i=istartposi;i<iendposi;i++)
    {
        flArray[i]=flNorm[i]-flArray[i];
        flssum+=flArray[i]*flArray[i];
    }
    sfWaveFormCoef=flssum;

    flssum = 0.0;
    itempposi = 2*iendposi - istartposi;
    if(itempposi > iLenCal )
    {
        itempposi = iLenCal;
    }
    for( i = iendposi; i<itempposi; i++)
    {
        flArray[i] = flNorm[i] - flArray[i];
        flssum += flArray[i]*flArray[i];
    }
    sfLastFormCoef = flssum;

    bFault = false;
    if((iTrainType <3)||(iTrainType == 5))
    {
        if(!sbCCoef)
        {
            if(sfWaveFormCoef<flLowCoef||sfWaveFormCoef>flHighCoef) bFault=true;
        }
        if(!sbCPeriod)
        {
            if(sfWavePeriod<flLowPeriod||sfWavePeriod>flHighPeriod) bFault=true;
        }
        if(!sbCPeak)
        {
            if(sfWavePeak<flLowPeak||sfWavePeak>flHighPeak)        bFault=true;
        }
    }
    else if((iTrainType == 3)||(iTrainType == 4))    //东风4D
    {
        if(!sbCCoef)
        {
            if(sfWaveFormCoef>flHighCoef) bFault=true;
        }
        if(!sbCPeriod)
        {
            if(sfWavePeriod<flLowPeriod||sfWavePeriod>flHighPeriod) bFault=true;
        }
        if(!sbCPeak)
        {
            if(sfWavePeak<flLowPeak||sfWavePeak>flHighPeak)        bFault=true;
        }
        if(sfLastFormCoef<flLastFormCoef)
        {
             bFault = true;
        }
    }

}
void __fastcall LDrawCurve::FreeMemory()
{
        //TODO: Add your source code here
        if(bMemoryAllocated)
        {
                delete [] fYData;
      //          delete [] fXData;
                bMemoryAllocated=false;
        }
}
bool __fastcall LDrawCurve::AllocateMemory(int len)
{
        if(!bMemoryAllocated)
        {
              if((fYData=new float[len])==NULL)
                {
                        return false;
                }
/*                if((fXData=new float[len])==NULL)
                {
                        return false;
                }
*/
                bMemoryAllocated=true;
                return true;
        }
        return false;
}
void __fastcall LDrawCurve::SetData(int *data,int len,float fkhz)
{

        if(!AllocateMemory(len))
                return;
        for(int i=0;i<len;i++)
        {
                fYData[i]=(float)data[i]/1000.0;
//                fXData[i]=(float)(i)/fkhz;
        }
        iDataLength=len;
        iDrawRgStart=0;
        iDrawRgEnd=iDataLength;
}

void __fastcall LDrawCurve::SetData(char *data,int len,float fkhz)
{

}
void __fastcall LDrawCurve::SetData(float *data,int len,float fkhz)
{
//        GetData iByteData;
        if(!AllocateMemory(len))
                return;
        if(!sbGaugeAdjust)
        {
            fGauge = 1.0;
        }
        for(int i=0;i<len;i++)
        {
              fYData[i]=(data[i]-1.23)*fGauge+1.23;
              if(fYData[i]<0.0) fYData[i]=0.1;
//                fYData[i]=data[i];
//                fXData[i]=(float)i/fkhz;
        }
        iDataLength=len;
        iDrawRgStart=0;
        iDrawRgEnd=iDataLength;
        sfTimeInterval=1.0/fkhz;
        fDeltaTime=1.0/fkhz;
        if(bShowInfo)
            CalculateParameters();
}
void __fastcall LDrawCurve::SetData(const float& fInt,float*ydata,int istart,int iend)
{
		fDeltaTime=fInt;
        fYData=ydata;
        iDataLength=(iend-istart);
        iDrawRgStart=istart;
        iDrawRgEnd=iend;
}
void __fastcall LDrawCurve::lDrawDetect(TObject* Sender, MaxBuffer& mb,lFileHeadStruct& lfhs)
{
    //TODO: Add your source code here
    GetCanvas(Sender);
    DrawDetect(Sender, mb,lfhs);
}

void __fastcall LDrawCurve::DrawDetect(TObject* Sender, MaxBuffer& mb,lFileHeadStruct& lfhs)
{
    //TODO: 对数据进行显示、分析及给出结论
    float fTTemp[20];
    int iLeft;
    int iTop;
    int iWidth;
    int iHeight;
    int iColNums = 15;
    int iDias    = 5;
    int iystep;
    int ixstep;

    iLeft   = OuterRect.Left     + fXPFactor*10;
    iTop    = OuterRect.Top      + fYPFactor*5;
    iWidth  = OuterRect.Width()  - fXPFactor*20;
    iHeight = OuterRect.Height() - fYPFactor*10;

    ixstep    = fXPFactor*4;
    iystep    = fYPFactor*4;

    iDias        = ixstep / 2;
    AnsiString strColumnTitle[] = { // 第一行
                                    "缸",         //0
                                    "缸压　",       //1
                                    "缸压",       //2
                                    "平均指",       //3
                                    "压升率 ",      //4
                                    "压升率",       //5
                                    "供油　",       //6
                                    "供油　",       //7
                                    "燃烧　",       //8
                                    "燃烧　",       //9
                                    "放热率",       //10
                                    "放热率",       //11
                                    "累积　",       //12
                                    "循环 ",       //13
                                    "柴油机",       //14
                                    //第二行
                                    "号",
                                    "最大值",
                                    "相位",
                                    "示压力",
                                    "最大值",
                                    "相位",
                                    "开始角",
                                    "持续角",
                                    "开始角",
                                    "持续角",
                                    "最大值",
                                    "相位",
                                    "放热量",
                                    "功",
                                    "转速"
                                  };
    AnsiString strColumnUnit[] = {
                                    "",
                                    "(MPa)",
                                    "(CA)",
                                    "(MPa)",
                                    "(MPa/CA)",
                                    "(CA)",
                                    "(CA)",
                                    "(CA)",
                                    "(CA)",
                                    "(CA)",
                                    "(kJ/CA)",
                                    "(CA)",
                                    "(kJ)",
                                    "(kJ)",
                                    "(r/min)"
                                    };
    int iColumnPosi[16];
//第一步：在中间位置显示标题
    ptCanvas->Font->Name = "隶书";
//    ptCanvas->Font->Size = 13;
    AnsiString strTemp, strTemp0;
    if(bCombustion)
    {
        strTemp = "*** 燃烧过程各参数列表 ***";
    }
    else
    {
        strTemp = "*** 压缩过程各参数列表 ***";
    }
    ptCanvas->TextOut(iLeft,iTop,strTemp);
    iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

    ptCanvas->Font->Name = "黑体";
//    ptCanvas->Font->Size = 10;
    strTemp0.printf("平均转速:%.1fr/min; 指示功率:%.1fkW", mb.fESMean, mb.fCCPower);
    if(iDeviceType != 0)
    {
        strTemp  = "车型:" + strTrainType    + "; " ;
        strTemp += "车号:" + strTrainNumber  + "; " ;
        strTemp += "测量时间:" + strMDate        + "; ";
        strTemp += strTemp0;
    }
    else
    {
        strTemp = strTemp0;
    }
    ptCanvas->TextOut(iLeft,iTop,strTemp);
// 应该加上机车车型、机车车号和测量时间

//第二步：显示数据表
    int iFH;
    int inum = mb.iCyNums;
    int iyreal, iy0Backup;
    int ix0,iy0;
    ix0   = iLeft;
    iyreal = iPrnSign*ptCanvas->TextHeight(strTemp);
    iTop += ( iyreal + iystep/2);

    ptCanvas->Font->Name = "宋体";
//    ptCanvas->Font->Size = iBasicFontSize;

    iFH   =  iPrnSign*ptCanvas->TextHeight(strTemp);
    iFH  +=  iystep;
    iy0 = iTop + iystep;

//  先显示表头
    int iwidth = 0;
    for(int i = 0; i < iColNums; i ++)
    {
        iColumnPosi[i] = ix0;
        ptCanvas->TextOut(ix0, iy0 ,         strColumnTitle[i]);
        ptCanvas->TextOut(ix0, iy0 + iyreal, strColumnTitle[i + iColNums]);
        iwidth = ptCanvas->TextWidth(strColumnTitle[i]) + ixstep;
        ix0 += iwidth;
    }
    iColumnPosi[iColNums] = ix0;
// 显示各个量的单位
//    ixstep = 0;
    iwidth = 0;
    iy0 = iTop + iFH + iyreal + iystep/2;
    for(int i = 0; i < iColNums; i ++)
    {
        ptCanvas->TextOut(iColumnPosi[i] - ixstep/2,iy0 , strColumnUnit[i]);
//        iwidth = ptCanvas->TextWidth(strColumnTitle[i]) + ixstep;
    }
// 绘制表头上方的横线
    ptCanvas->MoveTo(iLeft - iDias,                 iTop);
    ptCanvas->LineTo(iColumnPosi[iColNums] - iDias, iTop);
    ptCanvas->Font->Name = strBasicFontName;
    TFontStyles TFS;
    if(bBasicFSBold)
    {
        TFS<<fsBold;
    }
    if(bBasicFSItalic)
    {
        TFS<<fsItalic;
    }
    if(bBasicFSUnderline)
    {
        TFS<<fsUnderline;
    }
    if(bBasicFSStrikeOut)
    {
        TFS<<fsStrikeOut;
    }
    ptCanvas->Font->Style = TFS;
    ptCanvas->Font->Color = clBasicFSColor;

//0 显示缸号
    iy0Backup = iTop + 2*iFH + iystep/2 + iyreal;
    ix0 = iLeft;
    iy0 = iy0Backup;

    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%02d",mb.siarDieselNum[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//1 显示各气缸压力最大值
    ix0 = iColumnPosi[1];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.2f",mb.farPMax[i]);
        ptCanvas->TextOut(ix0, iy0 + i*iFH, strTemp);
    }
//2 显示气缸压力相位
    ix0 = iColumnPosi[2];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farMaxPAngle[i]);
        ptCanvas->TextOut(ix0, iy0 + i*iFH, strTemp);
    }
//3 显示各缸平均指示压力
    ix0 = iColumnPosi[3];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.3f",mb.farAverageP[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//4 显示各缸压升率最大值
    ix0 = iColumnPosi[4];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.3f",mb.farDPDFMax[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//5 显示各缸压升率最大值相位
    ix0 = iColumnPosi[5];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farMaxDPAngle[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }

//6 显示各缸供油提前角
    ix0 = iColumnPosi[6];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f", mb.farOilAngle[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//7 显示各缸供油持续时间
    ix0 = iColumnPosi[7];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farWavePeriod[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }

//8 显示各缸燃烧角
    ix0 = iColumnPosi[8];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farCombustionAngle[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//9 显示各缸燃烧持续角
    ix0 = iColumnPosi[9];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farCombustionPeriod[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//10 显示各缸放热率最大值
    ix0 = iColumnPosi[10];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.3f",mb.farDHDFMax[i]/1000.0);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }

//11 显示各缸放热率最大值相位
    ix0 = iColumnPosi[11];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farMaxDHAngle[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//12 显示各缸累积放热量
    ix0 = iColumnPosi[12];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.2f",mb.farCDHDFMax[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }

//13 显示各缸累积放热量

    ix0 = iColumnPosi[13];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.2f",mb.farCPower[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }

//14显示各缸转速
    ix0 = iColumnPosi[14];
    iy0 = iy0Backup;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farEngineSpeed[i] );
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }

// 绘制水平横线
    int iyymax;
    ix0 = iLeft;
    iy0 = iy0Backup;
    for(int i = 0; i < inum + 1; i++)
    {
        ptCanvas->MoveTo(ix0 - iDias,                   iy0 + i*iFH);
        ptCanvas->LineTo(iColumnPosi[iColNums] - iDias, iy0 + i*iFH);
        iyymax = iy0 + i*iFH;
    }

// 绘制竖直线
    ix0 = iLeft;
    iy0 = iy0Backup;
    for(int i = 0; i < iColNums + 1; i++)
    {
        ptCanvas->MoveTo(iColumnPosi[i] - iDias, iTop);
        ptCanvas->LineTo(iColumnPosi[i] - iDias, iyymax);
    }
    TRect rectTemp,rect0;
    TColor colorTemp;
    int isstep = 20;
    rectTemp.Top    = iyymax             + iystep;
    rectTemp.Left   = OuterRect.Left;
    rectTemp.Right  = OuterRect.Right    ;
    rectTemp.Bottom = OuterRect.Bottom;

//第一步：在中间位置显示标题
    ptCanvas->Font->Name  = "隶书";
//    ptCanvas->Font->Size  = 13;
    ptCanvas->Font->Style = TFontStyles();
    iLeft   = rectTemp.Left     + fXPFactor*10;
    iTop    = rectTemp.Top      + fYPFactor*5;
    iWidth  = rectTemp.Width()  - fXPFactor*20;
    iHeight = rectTemp.Height() - fYPFactor*10;
    strTemp = "参数分析结果";

    ptCanvas->TextOut(iLeft,iTop,strTemp);
    iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
    lCombustionDetect myDetect;

//------------------------------------------------------------------
//  11111111111111111111111111     供油提前角分析结果
    if(bCombustion)
    {


        myDetect.AnalysisAll(mb);

        strTemp.printf(" (1)各缸供油提前角分析:   各缸均值为：%5.1fCA；", myDetect.OilAngleInfo.fAverage);
        ptCanvas->Font->Name = "黑体";
//        ptCanvas->Font->Size = 10;
        ptCanvas->TextOut(iLeft,iTop,strTemp);
        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

        ptCanvas->Font->Name = "宋体";
//        ptCanvas->Font->Size = 10;

        if(myDetect.OilAngleInfo.iErrorNum > 0)  //如果有超出范围的，则提示
        {
            for( int i = 0; i < mb.iCyNums; i++)
            {
                if( myDetect.OilAngleInfo.bError[i])
                {
                    if(myDetect.OilAngleInfo.fChar[i] > 0.0)
                    {
                        strTemp.printf("    缸号：%02d；供油提前角：%5.1fCA；供油提前角偏小", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farOilAngle[i] //,
                                            
                                            //myDetect.OilAngleInfo.fChar[i]
                                            );
                    }
                    else
                    {
                        strTemp.printf("    缸号：%02d；供油提前角：%5.1fCA；供油提前角偏大", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farOilAngle[i] //,
                                          //  -myDetect.OilAngleInfo.fWeight[i],
                                          //  myDetect.OilAngleInfo.fChar[i]
                                            );

                    }
                    ptCanvas->TextOut(iLeft,iTop,strTemp);
                    iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
                }
            }
        }
        else
        {
            strTemp = "      各缸供油角度差别不大!" ;
            ptCanvas->TextOut(iLeft,iTop,strTemp);
            iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
        }
//------------------------------------------------------------------
//  22222222222222222     爆发压力分析
        myDetect.AnalysisCombustion(mb);

        strTemp.printf(" (2)各缸最大压力分析:     各缸均值为：%5.2fMPa；", myDetect.CombustionInfo.fAverage);
        ptCanvas->Font->Name = "黑体";
//        ptCanvas->Font->Size = 10;
        ptCanvas->TextOut(iLeft,iTop,strTemp);
        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

        ptCanvas->Font->Name = "宋体";
//        ptCanvas->Font->Size = 10;

        if(myDetect.CombustionInfo.iErrorNum > 0)  //如果有超出范围的，则提示
        {
            for( int i = 0; i < mb.iCyNums; i++)
            {
                if( myDetect.CombustionInfo.bError[i])
                {
                    if(myDetect.CombustionInfo.fChar[i] > 999.0)
                    {
                        strTemp.printf("    缸号：%02d；气缸压力：%5.2fMPa；相位：%5.1fCA；供油提前角：%5.1fCA；缸压偏小", //权重：%5.2f；无着火",
                                            mb.siarDieselNum[i],
                                            mb.farPMax[i],
                                            mb.farMaxPAngle[i],
                                            mb.farOilAngle[i] //,
                                          //  mb.farCombustionLevel[i]
                                            );
                    }
                    else if( myDetect.CombustionInfo.fChar[i] > 0.0 )
                    {
                        strTemp.printf("    缸号：%02d；气缸压力：%5.2fMPa；相位：%5.1fCA；供油提前角：%5.1fCA；缸压偏大", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farPMax[i],
                                            mb.farMaxPAngle[i],
                                            mb.farOilAngle[i] //,
                                            //myDetect.CombustionInfo.fChar[i]
                                            );
                    }
                    else
                    {
                        strTemp.printf("    缸号：%02d；气缸压力：%5.2fMPa；相位：%5.1fCA；供油提前角：%5.1fCA；缸压偏小", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farPMax[i],
                                            mb.farMaxPAngle[i],
                                            mb.farOilAngle[i]
                                        //    ,
                                        //    myDetect.CombustionInfo.fChar[i]
                                            );

                    }
                    ptCanvas->TextOut(iLeft,iTop,strTemp);
                    iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

                }
            }
        }
        else
        {
            strTemp = "      各缸最大压力差别不大!" ;
            ptCanvas->TextOut(iLeft,iTop,strTemp);
            iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
        }
//========================================================================================
/*
//------------------------------------------------------------------
//  3333333333333333333333     平均指示压力分析
        myDetect.AnalysisPower(mb);

        strTemp.printf(" (3)各缸指示效率分析；  各缸均值为：%5.1f%%；", myDetect.PowerInfo.fAverage*100.0);
        ptCanvas->Font->Name = "黑体";
        ptCanvas->Font->Size = 10;
        ptCanvas->TextOut(iLeft,iTop,strTemp);
        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

        ptCanvas->Font->Name = "宋体";
        ptCanvas->Font->Size = 10;

        if(myDetect.PowerInfo.iErrorNum > 0)  //如果有超出范围的，则提示
        {
            for( int i = 0; i < mb.iCyNums; i++)
            {
                if( myDetect.PowerInfo.bError[i])
                {
                    if(myDetect.PowerInfo.fChar[i] > 0.0)
                    {
                        strTemp.printf("    缸号：%02d；循环功：%5.2fkJ；放热量：%5.2fkJ；效率：%5.2%%；权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farCPower[i],
                                            mb.farCDHDFMax[i],
                                            mb.farCPower[i]*100.0/mb.farCDHDFMax[i],
                                            myDetect.PowerInfo.fChar[i]);
                    }
                    else
                    {
                        strTemp.printf("    缸号：%02d；循环功：%5.2fkJ；放热量：%5.2fkJ；效率：%5.2%%；权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farCPower[i],
                                            mb.farCDHDFMax[i],
                                            mb.farCPower[i]*100.0/mb.farCDHDFMax[i],
                                            myDetect.PowerInfo.fChar[i]);

                    }
                    ptCanvas->TextOut(iLeft,iTop,strTemp);
                    iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

                }
            }
        }
        else
        {
            strTemp = "      各缸指示效率基本正常!" ;
            ptCanvas->TextOut(iLeft,iTop,strTemp);
            iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
        }
*/
        myDetect.AnalysisPower(mb);

        strTemp.printf(" (3)各缸对外作功分析:  各缸作功均值为：%5.2fMPa；", myDetect.PowerInfo.fAverage);
        ptCanvas->Font->Name = "黑体";
//        ptCanvas->Font->Size = 10;
        ptCanvas->TextOut(iLeft,iTop,strTemp);
        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

        ptCanvas->Font->Name = "宋体";
//        ptCanvas->Font->Size = 10;

        if(myDetect.PowerInfo.iErrorNum > 0)  //如果有超出范围的，则提示
        {
            for( int i = 0; i < mb.iCyNums; i++)
            {
                if( myDetect.PowerInfo.bError[i])
                {
                    if(myDetect.PowerInfo.bHigh[i] > 0.0)
                    {
                        strTemp.printf("    缸号：%02d；平均指示压力：%5.2fMPa；循环功：%5.2fkW；对外作功大；", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farAverageP[i],
                                            mb.farCPower[i]
                                            //,
                                            //myDetect.AveragePressureInfo.fChar[i]
                                            );
                        ptCanvas->TextOut(iLeft,iTop,strTemp);
                        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
                    }
                    else
                    {
                        strTemp.printf("    缸号：%02d；平均指示压力：%5.2fMPa；循环功：%5.2fkW；对外作功少；", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farAverageP[i],
                                            mb.farCPower[i]
                                            //,
                                            //myDetect.AveragePressureInfo.fChar[i]
                                            );
                        ptCanvas->TextOut(iLeft,iTop,strTemp);
                        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);                    }
                }
            }
        }
        else
        {
            strTemp = "      各缸对外作功差别不大!" ;
            ptCanvas->TextOut(iLeft,iTop,strTemp);
            iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
        }
/*
//  3333333333333333333333     平均指示压力分析
        myDetect.AnalysisAveragePressure(mb);

        strTemp.printf(" (3)各缸平均指示压力分析:  各缸均值为：%5.2fMPa；", myDetect.AveragePressureInfo.fAverage);
        ptCanvas->Font->Name = "黑体";
//        ptCanvas->Font->Size = 10;
        ptCanvas->TextOut(iLeft,iTop,strTemp);
        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

        ptCanvas->Font->Name = "宋体";
//        ptCanvas->Font->Size = 10;

        if(myDetect.AveragePressureInfo.iErrorNum > 0)  //如果有超出范围的，则提示
        {
            for( int i = 0; i < mb.iCyNums; i++)
            {
                if( myDetect.AveragePressureInfo.bError[i])
                {
                    if(myDetect.AveragePressureInfo.fChar[i] > 0.0)
                    {
                    }
                    else
                    {
                        strTemp.printf("    缸号：%02d；平均指示压力：%5.2fMPa；循环功：%5.2fkW；对外作功少；", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farAverageP[i],
                                            mb.farCPower[i]
                                            //,
                                            //myDetect.AveragePressureInfo.fChar[i]
                                            );
                        ptCanvas->TextOut(iLeft,iTop,strTemp);
                        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
                    }
                    

                }
            }
        }
        else
        {
            strTemp = "      各缸平均指示压力差别不大!" ;
            ptCanvas->TextOut(iLeft,iTop,strTemp);
            iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
        }
*/
//========================================================================================
    }
    else     //对压缩过程进行分析
    {
        myDetect.AnalysisCompress(mb);
        strTemp.printf(" (1)各缸压缩压力分析；   各缸均值为：%5.2f MPa；", myDetect.CompressInfo.fAverage);
        ptCanvas->Font->Name = "黑体";
//        ptCanvas->Font->Size = 10;
        ptCanvas->TextOut(iLeft,iTop,strTemp);
        iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

        ptCanvas->Font->Name = "宋体";
//        ptCanvas->Font->Size = 10;

        if(myDetect.CompressInfo.iErrorNum > 0)  //如果有超出范围的，则提示
        {
            for( int i = 0; i < mb.iCyNums; i++)
            {
                if( myDetect.CompressInfo.bError[i])
                {
                    if(myDetect.CompressInfo.fChar[i] > 0.0)
                    {
                        strTemp.printf("    缸号：%02d；压缩压力：%5.2f MPa；", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farPMax[i]
                                            //,
                                            //myDetect.CompressInfo.fChar[i]
                                       );
                    }
                    else
                    {

                        strTemp.printf("    缸号：%02d；压缩压力：%5.2f MPa；", //权重：%5.2f；",
                                            mb.siarDieselNum[i],
                                            mb.farPMax[i]
                                            //,
                                           // myDetect.CompressInfo.fChar[i]
                                       );
                    }
                    ptCanvas->TextOut(iLeft,iTop,strTemp);
                    iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
                }
            }
        }
        else
        {
            strTemp = "      各缸压缩压力基本正常!" ;
            ptCanvas->TextOut(iLeft,iTop,strTemp);
            iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);
        }
    }
}

void __fastcall LDrawCurve::lDrawBasicInfo(TObject* Sender, MaxBuffer& mb,lFileHeadStruct& lfhs)
{
    //TODO: Add your source code here
    GetCanvas(Sender);
    DrawBasicText(Sender, mb,lfhs);
}

void __fastcall LDrawCurve::DrawBasicText(TObject* Sender, MaxBuffer& mb,lFileHeadStruct& lfhs)
{
    //TODO: Add your source code here
    float fTTemp[20];
    int iLeft;
    int iTop;
    int iWidth;
    int iHeight;
    int iColNums = 8;
    int iDias    = 5;
    int iystep;
    int ixstep;

    iLeft   = OuterRect.Left     + fXPFactor*10;
    iTop    = OuterRect.Top      + fYPFactor*5;
    iWidth  = OuterRect.Width()  - fXPFactor*20;
    iHeight = OuterRect.Height() - fYPFactor*10;

    ixstep    = fXPFactor*6;
    iystep    = fYPFactor*4;

    iDias        = ixstep / 2;
    AnsiString strColumnTitle[] = {
                                    "缸号",
                                    "最大缸压",
                                    "最大压升率",
                                    "供油提前角",
                                    "供油持续角",
                                    "燃烧开始角",
                                    "对外作功",
                                    "柴油机转速"
                                    };
    AnsiString strColumnUnit[] = {
                                    "",
                                    "(MPa)",
                                    "(MPa)",
                                    "(CA)",
                                    "(CA)",
                                    "(CA)",
                                    "(kJ)",
                                    "(r/min)"
                                    };
    int iColumnPosi[16];
//第一步：在中间位置显示标题
    ptCanvas->Font->Name = "隶书";
//    ptCanvas->Font->Size = 14;
    AnsiString strTemp = "基本参数表";
    ptCanvas->TextOut(iLeft,iTop,strTemp);
    iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

    ptCanvas->Font->Name = "黑体";
//    ptCanvas->Font->Size = 10;
    if(iDeviceType != 0)
    {
        strTemp  = "机车车型:" + strTrainType    + "; " ;
        strTemp += "机车车号:" + strTrainNumber  + "; " ;
        strTemp += "测量时间:" + strMDate        + ";";
        ptCanvas->TextOut(iLeft,iTop,strTemp);
    }
// 应该加上机车车型、机车车号和测量时间

//第二步：显示数据表
    int iFH;
    int inum = mb.iCyNums;

    int ix0,iy0;
    ix0   = iLeft;
    iTop += (iPrnSign*ptCanvas->TextHeight(strTemp) + iystep/2);

    ptCanvas->Font->Name = "宋体";
//    ptCanvas->Font->Size = iBasicFontSize;

    iFH   =  iPrnSign*ptCanvas->TextHeight(strTemp);
    iFH  +=  iystep;
    iy0 = iTop + iystep;

//  先显示表头
    int iwidth = 0;
    for(int i = 0; i < iColNums; i ++)
    {
        iColumnPosi[i] = ix0;
        ptCanvas->TextOut(ix0, iy0 , strColumnTitle[i]);
        iwidth = ptCanvas->TextWidth(strColumnTitle[i]) + ixstep;
        ix0 += iwidth;
    }
    iColumnPosi[iColNums] = ix0;
// 显示各个量的单位
    ixstep = 0;
    iwidth = 0;
    iy0 = iTop + iFH + iystep/2;
    for(int i = 0; i < iColNums; i ++)
    {
        ptCanvas->TextOut(iColumnPosi[i],iy0 , strColumnUnit[i]);
        iwidth = ptCanvas->TextWidth(strColumnTitle[i]) + ixstep;
    }
// 绘制表头上方的横线
    ptCanvas->MoveTo(iLeft - iDias,                 iTop);
    ptCanvas->LineTo(iColumnPosi[iColNums] - iDias, iTop);
    ptCanvas->Font->Name = strBasicFontName;
    TFontStyles TFS;
    if(bBasicFSBold)
    {
        TFS<<fsBold;
    }
    if(bBasicFSItalic)
    {
        TFS<<fsItalic;
    }
    if(bBasicFSUnderline)
    {
        TFS<<fsUnderline;
    }
    if(bBasicFSStrikeOut)
    {
        TFS<<fsStrikeOut;
    }
    ptCanvas->Font->Style = TFS;
    ptCanvas->Font->Color = clBasicFSColor;

//显示缸号
    ix0 = iLeft;
    iy0 = iTop + 2*iFH + 1;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%02d",mb.siarDieselNum[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//显示各气缸压力最大值
    ix0 = iColumnPosi[1];
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.2f",mb.farPMax[i]);
        ptCanvas->TextOut(ix0, iy0 + i*iFH, strTemp);
    }
//显示各缸压升率最大值
    ix0 = iColumnPosi[2];
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.3f",mb.farDPDFMax[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }

//显示各缸供油提前角
    ix0 = iColumnPosi[3];
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farOilAngle[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//显示各缸供油持续时间
    ix0 = iColumnPosi[4];
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farWavePeriod[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//显示各缸燃烧角
    ix0 = iColumnPosi[5];
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farCombustionAngle[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//显示各缸对外作功
    ix0 = iColumnPosi[6];
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.2f",mb.farCPower[i]);
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }
//显示各缸转速
    ix0 = iColumnPosi[7];
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i =0; i < inum; i ++)
    {
        strTemp.printf("%.1f",mb.farEngineSpeed[i] );
        ptCanvas->TextOut(ix0,iy0 + i*iFH, strTemp);
    }

// 绘制水平横线
    int iyymax;
    ix0 = iLeft;
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i = 0; i < inum + 1; i++)
    {
        ptCanvas->MoveTo(ix0 - iDias,                   iy0 + i*iFH);
        ptCanvas->LineTo(iColumnPosi[iColNums] - iDias, iy0 + i*iFH);
        iyymax = iy0 + i*iFH;
    }

// 绘制竖直线
    ix0 = iLeft;
    iy0 = iTop + 2*iFH + iystep/2;
    for(int i = 0; i < iColNums + 1; i++)
    {
        ptCanvas->MoveTo(iColumnPosi[i] - iDias, iTop);
        ptCanvas->LineTo(iColumnPosi[i] - iDias, iyymax);
    }
    TRect rectTemp,rect0;
    TColor colorTemp;
    int isstep = 20;
    rectTemp.Top    = iyymax             + iystep;
    rectTemp.Left   = OuterRect.Left;
    rectTemp.Right  = OuterRect.Right    ;
    rectTemp.Bottom = OuterRect.Bottom;
    if(bDrawBasicCurve)
    {
        ptCanvas->Font->Name = "隶书";
        ptCanvas->Font->Style = TFontStyles();
//        ptCanvas->Font->Size = 14;
        strTemp   = "各参数相应直方图";
        ptCanvas->TextOut(iLeft,rectTemp.Top,strTemp);

        rectTemp.Top += iPrnSign*ptCanvas->TextHeight(strTemp);
        ptCanvas->Font->Name = "宋体";
//        ptCanvas->Font->Size = iBasicFontSize;
        iystep = rectTemp.Height() / 3;
        ixstep = (rectTemp.Width() - 2*isstep) / 2;

// 绘制最大压力直方图
        strDrawText = "最大缸压";
        rect0.Left   = rectTemp.Left + isstep;
        rect0.Top    = rectTemp.Top;
        rect0.Right  = rect0.Left + ixstep;
        rect0.Bottom = rect0.Top  + iystep;
        colorTemp = clRed;
        iPointPosi  = 2;
        DrawMaxSimple(rect0, mb.siarDieselNum, mb.farPMax, inum, colorTemp);

// 绘制压力升高率直方图
        strDrawText = "最大压升率";
        rect0.Left   = rect0.Right + isstep;
        rect0.Right  = rect0.Left + ixstep;
        colorTemp = clGreen;
        iPointPosi = 3;
        DrawMaxSimple(rect0, mb.siarDieselNum, mb.farDPDFMax, inum, colorTemp);

// 绘制供油提前角直方图
            strDrawText = "供油提前角";
            rect0.Left   = rectTemp.Left + isstep;
            rect0.Top    = rect0.Bottom;
            rect0.Right  = rect0.Left + ixstep;
            rect0.Bottom = rect0.Top  + iystep;
            colorTemp = clAqua;
            iPointPosi = 1;
            for(int i = 0; i < inum; i ++) fTTemp[i] = - mb.farOilAngle[i];
            DrawMaxSimple(rect0, mb.siarDieselNum, fTTemp, inum, colorTemp);

    // 绘制供油持续时间直方图
            strDrawText = "供油持续角";
            rect0.Left   = rect0.Right + isstep;
            rect0.Right  = rect0.Left + ixstep;
            colorTemp = clLime;
            DrawMaxSimple(rect0, mb.siarDieselNum, mb.farWavePeriod, inum, colorTemp);

// 绘制供油提前角直方图
            strDrawText  = "燃烧开始角";

            rect0.Left   = rectTemp.Left + isstep;
            rect0.Top    = rect0.Bottom;
            rect0.Right  = rect0.Left + ixstep;
            rect0.Bottom = rect0.Top  + iystep;
            colorTemp = (TColor)RGB(150,150,255);
            for(int i = 0; i < inum; i ++) fTTemp[i] = - mb.farCombustionAngle[i];
            DrawMaxSimple(rect0, mb.siarDieselNum, fTTemp, inum, colorTemp);

// 绘制供油持续时间直方图
            strDrawText  = "对外作功";
            rect0.Left   = rect0.Right + isstep;
            rect0.Right  = rect0.Left + ixstep;
            colorTemp = clYellow;
            DrawMaxSimple(rect0, mb.siarDieselNum, mb.farCPower, inum, colorTemp);

    }
}

void __fastcall LDrawCurve::DrawMaxSimple(TRect & rect, int * idnum, float* fvalue, int num,TColor color)
{
    //TODO: Add your source code here
    int ixmin,ixmax,iymin,iymax;
    int xposi,yposi,yposibak;
    TRect rtemp;
    TColor cltemp;
    float fymax, fystep, fxstep;
    int iheight,iwidth;
    int istart = 0;
    int ixminbak;
    int ixtemp,ixmiddle;
    char chtemp[50];
    AnsiString strTemp;
    bLabelSign = false;
    bNumSign = false;
    OuterRect = rect;

    DrawCoor(NULL);

    xposi = iXMin + fXPFactor*5;
    yposi = iYMin + fYPFactor*2;

//    ixmin = xposi + fXPFactor*(iwidth + 20);
    ixmin = xposi;
    ixmax = iXMax;
    iheight  = ptCanvas->TextHeight("最大值");
    yposibak = (ixmax - ixmin)/num;
    fxstep   = (float)(ixmax - ixmin)/(float)num;
    ixminbak = iXMin;
    if(iDeviceType == 0)
    {
        iymin = iYMin + fYPFactor*(10.0);
    }
    else
    {
        iymin = iYMin + fYPFactor*(2*iheight + 4.0);
    }
    iymax = iYMax ;
    fymax = fvalue[0];
    for(int i=1;i<num;i++)
    {
        if(fymax < fvalue[i])
        {
            fymax = fvalue[i];
        }
    }
    if(fabs(fymax) < 0.01)
    {
        return;
    }
    fystep = (iymax - iymin)/fymax;
    int itemp;

    for( int i=0; i<num; i++)
    {
        cltemp = ptCanvas->Brush->Color;
        itemp = i%2;
        rtemp.Left   = ixmin      + (int)((float)i*fxstep);
        rtemp.Right  = rtemp.Left + yposibak - fYPFactor;
        rtemp.Bottom = iymax;
        rtemp.Top    = rtemp.Bottom - fvalue[i]*fystep;
        if(iDeviceType == 0)    //如果是打印机
        {
            ptCanvas->Brush->Color = clYellow;
        }
        else
        {
            ptCanvas->Brush->Color = color;
        }

        ptCanvas->Rectangle(rtemp);

    //上面这句用于绘制直方图
        ptCanvas->Brush->Color = cltemp;
        ::SetBkMode(ptCanvas->Handle,TRANSPARENT);
        if(iDeviceType == 1)
        {
            TColor clor = ptCanvas->Font->Color;
            ptCanvas->Font->Color = clPurple;
//            strTemp.printf("%.2f",fvalue[i]);
            switch(iPointPosi)
            {
                case 1:  strTemp.printf("%.1f",fvalue[i]); break;
                case 2:  strTemp.printf("%.2f",fvalue[i]); break;
                case 3:  strTemp.printf("%.3f",fvalue[i]); break;
                default: strTemp.printf("%.2f",fvalue[i]); break;
            }
            ixmiddle = ptCanvas->TextWidth(strTemp);
            ixmiddle = (rtemp.Left + rtemp.Right - ixmiddle)/2;
            ptCanvas->TextOut(ixmiddle,iYMin + fYPFactor*(2+itemp*iheight),strTemp);
            ptCanvas->Font->Color  = clor;
            ptCanvas->MoveTo(rtemp.Left+yposibak/2,rtemp.Top);
            ptCanvas->LineTo(rtemp.Left+yposibak/2,iYMin+fYPFactor*(2+(itemp+1)*iheight));
        }
        strTemp.printf("%02d",idnum[i]);
        ixmiddle = ptCanvas->TextWidth(strTemp);
        iheight  = iPrnSign*ptCanvas->TextHeight(strTemp);
        ixmiddle = (rtemp.Left + rtemp.Right - ixmiddle)/2;
        ptCanvas->TextOut(ixmiddle,iYMax - (fYPFactor*2 + iheight),strTemp);
    }
    if(iDeviceType != 1)
    {
        iwidth  = ptCanvas->TextWidth(strDrawText);
        iheight = ptCanvas->TextHeight(strDrawText);
        ptCanvas->TextOut((ixmin + ixmax-iwidth)/2,(iYMin + fYPFactor*iheight/2),strDrawText);
    }        

    try
    {
        TLogFont logFont;
        HFONT holdFont;
        HFONT hnewFont;
        ::GetObject(ptCanvas->Font->Handle,sizeof(logFont),&logFont);
        if(iDeviceType == 0)
        {
            logFont.lfEscapement  = -900;
            logFont.lfOrientation = -900;
        }
        else
        {
            logFont.lfEscapement  = 900;
            logFont.lfOrientation = 900;
        }
        hnewFont = ::CreateFontIndirect(&logFont);
        holdFont = ::SelectObject(ptCanvas->Handle,hnewFont);
        if(iDeviceType == 1)
        {
            iwidth = ptCanvas->TextHeight(strDrawText);
            iheight = iPrnSign*ptCanvas->TextWidth(strDrawText);
            ptCanvas->TextOut(ixminbak - fXPFactor*(iwidth + 2),( iYMax + iYMin + iheight)/2,strDrawText);
        }
        else
        {
            for( int i=0; i<num; i++)
            {
                itemp = i%2;
                ::SetBkMode(ptCanvas->Handle,TRANSPARENT);
                switch(iPointPosi)
                {
                    case 1:  strTemp.printf("%.1f",fvalue[i]); break;
                    case 2:  strTemp.printf("%.2f",fvalue[i]); break;
                    case 3:  strTemp.printf("%.3f",fvalue[i]); break;
                    default: strTemp.printf("%.2f",fvalue[i]); break;
                }
                
                iwidth  = ptCanvas->TextHeight(strTemp);
                iheight = iPrnSign*ptCanvas->TextWidth(strTemp);
                ptCanvas->TextOut(  ixminbak + (int)((float)i*fxstep) + fXPFactor * 5, // - fXPFactor*(iwidth),
                                   (iYMin + iYMax)/2 + (iheight + fYPFactor*20)/2,
                                   strTemp
                                  );
            }
        }
        ::SelectObject(ptCanvas->Handle,holdFont);
        ::DeleteObject(hnewFont);
   }
   catch(...)
   {
   	    Application->MessageBox("绘图过程出现错误","错误",MB_OK);
        return;
   }
}

void __fastcall LDrawCurve::LDraw(TObject *Sender)
{
        GetCanvas(Sender);
        DrawCoor(Sender);
        CalculateCoor();
        DrawCurve(Sender);
        if(bDrawGrid == false)
        {
            bDrawGrid = bDrawGrid;
        }
        if(bTwoInfo)
        {
            DrawTwoLabel(Sender);
        }
        else
        {
            DrawLabel(Sender);
        }
        DrawCurve(Sender);
        DrawPipeWave(Sender);
/*
        if(bDrawText)
        {
            DrawText(Sender,0);
        }
*/        
        FreeMemory();
}

void __fastcall LDrawCurve::AppendDraw(TObject* Sender, float* fdata, int ilen,float ifre, int inum)
{
    iDrawTimes=inum;
  	SetData(fdata,ilen,ifre);
//    RemoveLevel();
    DrawCurve(Sender);

    if(bDrawText)   DrawText(Sender,inum);
    FreeMemory();
}

void __fastcall LDrawCurve::AppendDraw(TObject* Sender,AnsiString strItem, int iItem)
{
	//TODO: Add your source code here
    iDrawTimes=iItem;
    ReadAllData(strItem);
    DrawCurve(Sender);
    if(bDrawText)   DrawText(Sender,iItem);
    FreeMemory();
}

void __fastcall LDrawCurve::DrawText(TObject* Sender,int iitem)
{
	//TODO: Add your source code here
        int i,itemp,ygap;
        AnsiString strTemp;

        strTemp=IntToStr(iitem+1)+":";
        strTemp+=strDrawText;
        TCanvas* ptCanvas;
        if(iDeviceType==0)
        {
                ptCanvas=((TPrinter*)Sender)->Canvas;
        }
        else  if(iDeviceType==1)
        {
                ptCanvas=((TPaintBox*)Sender)->Canvas;
                ptCanvas->Font->Color=clTextColor;
        }
        else if(iDeviceType==2)
        {
                ptCanvas=((TImage*)Sender)->Canvas;
                ptCanvas->Font->Color=clTextColor;

        }
        ptCanvas->MoveTo(iXMax-180,iYMin+18*iitem+10);
        ptCanvas->LineTo(iXMax-170,iYMin+18*iitem+10);
        ptCanvas->TextOut(iXMax-165,iYMin+18*iitem+4,strTemp.c_str());
}
 __fastcall LDrawCurve::~LDrawCurve()
{
}


void __fastcall LDrawCurve::GetCanvas(TObject* Sender)
{
	//TODO: Add your source code here
        switch(iDeviceType)
        {
            case 0:
                ptCanvas = ((TPrinter*)Sender)->Canvas;
                break;
            case 1:
                ptCanvas = ((TPaintBox*)Sender)->Canvas;
                break;
            case 2:
                ptCanvas = ((TImage*)Sender)->Canvas;
        }

}

void __fastcall LDrawCurve::RemoveLevel(void)
{
    float flevel[3];
    flevel[0]=0.0;
    flevel[1]=0.0;
    flevel[2]=0.0;
    for(int i=10;i<20;i++)
    {
      	flevel[0]+=fYData[i];
        flevel[1]+=fYData[i+515];
        flevel[2]+=fYData[i+770];
    }
    flevel[0]=flevel[0]/10.0-ffLevel;
    flevel[1]=flevel[1]/10.0-ffLevel;
    flevel[2]=flevel[2]/10.0-ffLevel;
    for(int i=0;i<20;i++)
    {
       	fYData[i]=fYData[i]-flevel[0];
        if(fabs(fYData[i]-ffLevel)>0.2) fYData[i]=ffLevel;
        fYData[i+512]=fYData[i+512]-flevel[1];
        if(fabs(fYData[i+512]-ffLevel)>0.2) fYData[i+512]=ffLevel;
        fYData[i+768]=fYData[i+768]-flevel[2];
        if(fabs(fYData[i+768]-ffLevel)>0.2) fYData[i+768]=ffLevel;

    }
    for(int i=20;i<236;i++)
    {
       	fYData[i]=fYData[i]-flevel[0];
        fYData[i+512]=fYData[i+512]-flevel[1];
        fYData[i+768]=fYData[i+768]-flevel[2];
    }
    for(int i=236;i<256;i++)
    {
       	fYData[i]=fYData[i]-flevel[0];
        if(fabs(fYData[i]-ffLevel)>0.2) fYData[i]=ffLevel;
        fYData[i+512]=fYData[i+512]-flevel[1];
        if(fabs(fYData[i+512]-ffLevel)>0.2) fYData[i+512]=ffLevel;
        fYData[i+768]=fYData[i+768]-flevel[2];
        if(fabs(fYData[i+768]-ffLevel)>0.2) fYData[i+768]=ffLevel;
    }
    for(int i=236;i<512;i++)
    {
        if(fabs(fYData[i]-ffLevel)>0.2)
            fYData[i]=ffLevel;
    }

}

void __fastcall LDrawCurve::AppendDraw(TObject* Sender, float * fData, AnsiString stitle,int iItem,int StartNum,int EndNum)
{
	//TODO: Add your source code here
    iDrawTimes=iItem;
//    ReadAllData(strItem);
    SetData(1,fData,StartNum,EndNum);
    DrawCurve(Sender);
    if(bDrawText)   DrawText(Sender,iItem);
//    FreeMemory();
}

__fastcall LSimulationCurveDraw::LSimulationCurveDraw(void)
{
        iMax=104;
        iMin=0;
        iPosi=0; //高压油管压力波的位置
        bShowMode=false;
        if((cData=new char[700])==NULL)
        return;
}
__fastcall LSimulationCurveDraw::~LSimulationCurveDraw()
{
        delete []cData;
}
void __fastcall LSimulationCurveDraw::GetData(AnsiString& filename,int& num,int Col)
{
	CReadString RS;
    float ftemp;
	FILE * fp;
	int j=0;
	if((fp=fopen(filename.c_str(),"r"))==NULL)
	{
		return;
	}

	if(bShowMode==1)
	{
                while(fgets(cData,700,fp)!=NULL)
	        {
		 //       GetColumnData(cData,ftemp,Col+1);
               		j++;
       	        }
                iDataLength=j;
                if(!AllocateMemory(iDataLength))
                        return;
       		j=0;
                fseek(fp,0L,SEEK_SET);
		while(fgets(cData,700,fp)!=NULL)
		{
//			RS.GetData(cData,Data,Col);
			GetColumnData(cData,ftemp,Col+1);
                        fYData[j]=ftemp;
 //                       fXData[j]=(float)j;
//			fData[j]=Data[Col-1];
			j++;
		}
		num=j-1;
/*
		if(filename!="Speed.dat")
		{
			for(j=0;j<num;j++)
				fYData[j]=fYData[j]+50.0;
		}
*/
//		sprintf(tttt,"按时间方式查看: 位置在:%.3f毫米",Col*7.583);
	}
	else
	{
	   	iDataLength=iMax;
        if(!AllocateMemory(iDataLength))
            return;
        for(j=0;j<num;j++)
			fgets(cData,700,fp);
		if(fgets(cData,700,fp)!=NULL)
		{
			RS.GetData(cData,fYData,iMax);
		}

/*
        for(j=0;j<iDataLength;j++)
                {
 //                       fXData[j]=(float)j;
                }
		if(filename!="Speed.dat")
		{
			for(j=0;j<num;j++)
				fYData[j]=fYData[j]+50.0;
		}
*/
//		sprintf(tttt,"按空间方式查看: 油泵转角为:%.3f",15.0+m_edit_begin*0.125);
	}
	fclose(fp);
    iDrawRgStart=0;
    iDrawRgEnd=iDataLength;
    bFixYMax=true;
}

void __fastcall LSimulationCurveDraw::GetColumnData(char* str, float& tData, int num)
{
	char ch;
	char tttt[200];
	int i=0,j=0,inum=1;
//	strcpy(DataString,str);
	ch=str[0];
//	len=strlen(str);
	if(num!=1)
	{
		while(1)
		{
			if((ch==' ')||(ch==',')||(ch==';')||(ch=='\n')||(ch=='\t'))
			{
				inum++;
				if(num==inum)
				{
					i++;
					break;
				}
			}
			i++;
			ch=str[i];
		}
	}
	do
	{
		ch=str[i];
		tttt[j]=ch;
		j++;
		i++;
	}while((ch!=' ')&&(ch!=',')&&(ch!=';')&&(ch!='\n')&&(ch!='\t'));
	tttt[j] = '\0';
	tData = atof(tttt);
}
void __fastcall LSimulationCurveDraw::DrawPumpAndNozzle(TObject * Sender,AnsiString& epump, int num, int column,AnsiString legend)
{
        ReadPipeData(epump,num,column);
        LDraw(Sender);
}

void __fastcall LSimulationCurveDraw::DrawPressure(TObject* Sender,AnsiString& epipe,int num,int posi)
{
        SetiPosi(posi);
        GetData(epipe,num,posi);
        LDraw(Sender);
}

bool __fastcall LSimulationCurveDraw::ReadPipeData(AnsiString& fn,int num,int icol)
{
    char Temp0[400];
    float  yData[20];
	FILE * fileBO;
	CReadString RS;
    int data_num=0;
	if((fileBO=fopen(fn.c_str(),"r"))==NULL)
	{
	       exit(1);
	}
    if(num==0)
    {
         while(fgets(Temp0,400,fileBO)!=NULL)
	    {
//		RS.GetData(Temp0,yData,totalnum);
		        data_num++;
      	}
        iDataLength=data_num;
        if(!AllocateMemory(iDataLength))
             return false;
        fseek(fileBO,0l,SEEK_SET);
        for(int i=0;i<iDataLength;i++)
        {
             fgets(Temp0,400,fileBO);
             RS.GetData(Temp0,yData,icol+1);
//           fXData[i]=yData[0];
             fYData[i]=yData[icol];
       	}
    }
    else
    {
        iDataLength=num;
        if(!AllocateMemory(num))
             return false;
        for(int i=0;i<iDataLength;i++)
        {
            fgets(Temp0,400,fileBO);
            RS.GetData(Temp0,yData,icol+1);
//          fXData[i]=yData[0];
            fYData[i]=yData[icol];
       	}
    }
    fclose(fileBO);
    iDrawRgStart=0;
    iDrawRgEnd=iDataLength;
    bFixYMax=true;
    return true;
}

void __fastcall LSimulationCurveDraw::SimpleDraw(TObject* Sender,AnsiString& fn,int num,int icol)
{
        ReadPipeData(fn,num,icol);
        DrawCurve(Sender);
        FreeMemory();
}
/*
void __fastcall LDrawCurve::AppendDraw(TObject* Sender, float* fdata, int ilen,int ifre, int inum)
{
    iDrawTimes=inum;
  	SetData(fdata,ilen,ifre);
    RemoveLevel();
    DrawCurve(Sender);

    if(bDrawText)   DrawText(Sender,inum);
    FreeMemory();
}

void __fastcall LDrawCurve::AppendDraw(TObject* Sender,AnsiString strItem, int iItem)
{
	//TODO: Add your source code here
    iDrawTimes=iItem;
    ReadAllData(strItem);
    DrawCurve(Sender);
    if(bDrawText)   DrawText(Sender,iItem);
    FreeMemory();
}

void __fastcall LDrawCurve::DrawText(TObject* Sender,int iitem)
{
	//TODO: Add your source code here
        int i,itemp,ygap;
        AnsiString strTemp;

        strTemp=IntToStr(iitem+1)+":";
        strTemp+=strDrawText;
        TCanvas* pbCanvas;
        if(bPBorPrn)
        {
                pbCanvas=((TPrinter*)Sender)->Canvas;
        }
        else
        {
                pbCanvas=((TPaintBox*)Sender)->Canvas;
        }
        pbCanvas->MoveTo(iXMax-140,iYMin+18*iitem+9);
        pbCanvas->LineTo(iXMax-120,iYMin+18*iitem+9);
        pbCanvas->TextOut(iXMax-110,iYMin+18*iitem,strTemp.c_str());
}

  */

void __fastcall LDrawCurve::DrawPT(TObject * Sender, float* fDataX, float * fDataY, int iNum)
{
    //TODO: Add your source code here
}

void __fastcall LDrawCurve::SetData(float * fdatax, float * fdatay, int istart, int iend,bool btwo)
{
    //TODO: Add your source code here
//    fDeltaTime=fInt;
    fYData       = fdatay;
    fXData       = fdatax;
    iDataLength  = (iend-istart);
    iDrawRgStart = istart;
    iDrawRgEnd   = iend;
    bTwoInfo     = btwo;
}

void __fastcall LDrawCurve::GetNewCoorSegment(float *fxgrid, float *fygrid, int &ixgridnum, int &iygridnum)
{
    //TODO: Add your source code here
    if((!bXLogValue)&&(!bYLogValue))
    {
        GetXYGrid(fxgrid,ixgridnum,true);
        GetXYGrid(fygrid,iygridnum,false);
    }
    else if((!bXLogValue)&&bYLogValue)
    {
        GetXYGrid(fxgrid,ixgridnum,true);
        GetXYLogGrid(fygrid,iygridnum,false);
    }
    else if(bXLogValue&&(!bYLogValue))
    {
        GetXYLogGrid(fxgrid,ixgridnum,true);
        GetXYGrid(fygrid,iygridnum,false);
    }
    else
    {
        GetXYLogGrid(fxgrid,ixgridnum,true);
        GetXYLogGrid(fygrid,iygridnum,false);
    }

}

void __fastcall LDrawCurve::GetXYGrid(float *idata, int& num,bool bxgrid)
{
    //TODO: Add your source code here
    int imin,imax;
    int istep;
    int imod,ileft;
    float fmin,fmax;
    float fallstep;
    int iOrig;
    int iLeft[10];
    int iMod[10];
    int iNum = 0;

    if(bxgrid)
    {
        fmin = fXDataMin;
        fmax = fXDataMax;
    }
    else
    {
        fmin = fYDataMin;
        fmax = fYDataMax;
    }
    fallstep = fmax - fmin;
    fallstep /= 10.0;
    iOrig = (int)(fallstep);
    if(iOrig > 1)
    {
        while(iOrig != 0)
        {
            iLeft[iNum] = iOrig / 10;
            iMod[iNum]  = iOrig % 10;
            iOrig /= 10;
            iNum ++;
        }
        if(iNum > 2)  //仅有一位
        {
            if((iMod[iNum - 2]>3)&&(iMod[iNum -2] < 7))
            {
                fallstep = (float)iMod[iNum-1]*pow(10,float(iNum-1)) + 5.0*pow(10,(float)(iNum - 2));
            }
            else
            {
                fallstep = (float)iMod[iNum-1]*pow(10.0,(float)(iNum-1));
            }
        }
        else if(iNum == 2)
        {
            if( (iMod[0]>3)&&(iMod[0]<7 ))
            {
                fallstep = (float)iMod[1]*10.0 + 5.0;
            }
            else
            {
                fallstep = (float)iMod[1]*10.0;
            }
        }
        else
        {
            if((iMod[0] > 3)&&(iMod[0] < 7))
            {
                fallstep = 5.0;
            }
            else
            {
                fallstep = iMod[0];
            }
        }
    }
    else
    {
        int imn = 0;
        while(fallstep < 10.0)
        {
             ++imn;
             fallstep *= 10.0;
        }
        istep = fallstep;
        fallstep = istep;
        while(imn > 0)
        {
            --imn;
            fallstep /= 10.0;
        }
    }

    int ixtemp ;
    int ixtemp2;
    ixtemp = fmin/fallstep;
    ixtemp2 = fmax/fallstep;
    for(int i = ixtemp; i <= ixtemp2; i++)
    {
        idata[i-ixtemp] = (float)i*fallstep;
    }
    num = (ixtemp2 - ixtemp + 1);
}

void __fastcall LDrawCurve::GetXYLogGrid(float *idata, int& num, bool bxgrid)
{
    //TODO: Add your source code here
    int i;
    GetXYGrid(idata,num,bxgrid);
    for( i = 0; i< num; i++)
    {
        if(idata[i] > 0.000001)
        {
            idata[i] = 20.0*log10(idata[i]);
        }
    }
/*
    int imin,imax;
    int istep;
    bool bEnlarge = false;
    if(bxgrid)
    {
        imin = (int)fXMin;
        if(fXMax>1.0)
        {
            imax = (int)fXMax;
        }
        else
        {
            imax = (int)(fXMax*1000.0);
            bEnlarge = true;
        }
    }
    else
    {
        imin = (int)fYMin;
        imax = (int)fYMax;
    }
    if(imin > 0)
    {
        imin = 0;
    }

    if(imax<15)
    {
        istep = 1;
    }
    else if(imax <50)
    {
        istep = 5;
    }
    else if(imax<100)
    {
        istep = 10;
    }
    else if(imax<200)
    {
        istep = 20;
    }
    else
    {
        istep = 50;
    }
    int ixtemp ;
    int ixtemp2;
    if(imin<0)
    {
        ixtemp = (-imin)/istep;
        ixtemp2 = -((-imin)/istep)*istep;
        for(int i=0;i<ixtemp;i++)
        {
            idata[i] = (i*istep + ixtemp2);
        }
    }
    else
    {
        ixtemp = 0;
    }
    ixtemp2 = imax/istep + ixtemp;
    for(int i=ixtemp;i<ixtemp+ixtemp2;i++)
    {
        idata[i] = istep*(i-ixtemp+1);
    }
    num = ixtemp2+2;
    for(int i=num-1;i>=2;i--)
    {
        idata[i] = idata[i-2];
    }
    if(bEnlarge)
    {
        idata[0] = 10.0;
        idata[1] = 100.0;
        for(int i=0;i<num;i++)
        {
            idata[i] = 20.0*log10(idata[i]/1000.0);
        }
    }
    else
    {
        idata[0] = 0.01;
        idata[1] = 0.1;
        for(int i=0;i<num;i++)
        {
            idata[i] = 20.0*log10(idata[i]);
        }
    }
*/
}

void __fastcall LDrawCurve::iDrawOriginal(TObject* Sender,int * iP, int istart,int iend,TColor& linecolor)
{
    GetCanvas(Sender);
    //TODO: Add your source code here
    iYMax=OuterRect.bottom-iPrnSign*5;
    iXMax=OuterRect.right-5;
  	iXMin=OuterRect.left+2;
    iYMin=OuterRect.Top+iPrnSign*2;
    ptCanvas->Pen->Style = (TPenStyle)LineType[iLineTypeIndex];
    ptCanvas->Pen->Mode=pmCopy;
    ptCanvas->Pen->Color=clBlack;
    ptCanvas->Pen->Width = 2;
    SetBkMode(ptCanvas->Handle,TRANSPARENT);
	ptCanvas->MoveTo(iXMin,iYMax);
	ptCanvas->LineTo(iXMax,iYMax);
	ptCanvas->LineTo(iXMax,iYMin);
	ptCanvas->LineTo(iXMin,iYMin);
	ptCanvas->LineTo(iXMin,iYMax);

    iYMax -= 4;
    iYMin += 4;

    rectDraw.Left=iXMin;
    rectDraw.Top=iYMin;
    rectDraw.Right=iXMax;
    rectDraw.Bottom=iYMax;
    if(iP == NULL) //如果指针是空则退出
    {
        return;
    }
    iDrawRgEnd = iend;
    iDrawRgStart = istart;
    int i,itemp;
    if(!bMMValue)
    {
        fYDataMax = iP[iDrawRgStart];
        fYDataMin = iP[iDrawRgStart];
        for(i = iDrawRgStart + 1; i < iDrawRgEnd; i+=2)
        {
   	        if(fYDataMax<iP[i])
            {
	    	    fYDataMax = iP[i];
            }
        	else if(fYDataMin > iP[i])
            {
	            fYDataMin = iP[i];
            }
        }
    }
    if(fabs(fYDataMax-fYDataMin)<0.0000001)
   	{
        fYDataMax = 0.0001;
        fYDataMin = 0.0;
    }
    fXDataMin = istart;
    fXDataMax = iend;

    if( iDrawRgEnd == iDrawRgStart )
    {
        iDrawRgEnd = iDrawRgStart + 1;
    }
    fXStep=(float)(iXMax-iXMin)/(iDrawRgEnd - iDrawRgStart + 1 );
	fYStep=(float)(iYMax-iYMin)/(fYDataMax-fYDataMin);

    iX = iXMin;
    iY = iYMax-(int)((float)(iP[iDrawRgStart]-fYDataMin)*fYStep);
  	ptCanvas->MoveTo(iX,iY);
    TColor clbk,clbbk,clpc;
    clbk  = ptCanvas->Font->Color;
    clbbk = ptCanvas->Brush->Color;
    clpc  = ptCanvas->Pen->Color;
    ptCanvas->Font->Color  = linecolor;
    ptCanvas->Brush->Color = linecolor;
    ptCanvas->Pen->Color   = linecolor;
    ptCanvas->Pen->Width   = 1;
    for(i=iDrawRgStart; i<iDrawRgEnd; i += 2)
  	{
       	iX = iXMin+(int)((float)(i-iDrawRgStart)*fXStep);
        iY = iYMax-(int)((iP[i]-fYDataMin)*fYStep);
        ptCanvas->LineTo(iX,iY);
    }

    if(bTDCDraw)   //绘制上止点位置 ,燃烧始点，供油始点
    {
        TColor cl;
        cl  = ptCanvas->Pen->Color;

        iX = iXMin + (int)((float)(iTDCPosi-iDrawRgStart)*fXStep);
        ptCanvas->Pen->Color = clGreen;
        ptCanvas->MoveTo(iX,iYMax);
        ptCanvas->LineTo(iX,iYMin);

        iX = iXMin + (int)((float)(iOilPosi-iDrawRgStart)*fXStep);
        iY = iYMax - (int)((iP[iOilPosi]-fYDataMin)*fYStep);
        ptCanvas->Pen->Color = clBlue;
        ptCanvas->MoveTo(iX,iYMax);
        ptCanvas->LineTo(iX,iY);

        iX = iXMin + (int)((float)(iCombustionPosi-iDrawRgStart)*fXStep);
        iY = iYMax - (int)((iP[iCombustionPosi] - fYDataMin)*fYStep);
        ptCanvas->Pen->Color = clRed;
        ptCanvas->MoveTo(iX,iYMax);
        ptCanvas->LineTo(iX,iY);

        ptCanvas->Pen->Color = cl;
    }
    if( (fYDataMin <0.0)&&(fYDataMax>0.0) )
    {
        ptCanvas->Pen->Color = clGreen;
        iY = iYMax + (int)(fYDataMin*fYStep);
        ptCanvas->MoveTo(iXMin,iY);
        ptCanvas->LineTo(iXMax,iY);
    }
    ptCanvas->Font->Color = clbk;
    ptCanvas->Brush->Color = clbbk;
    ptCanvas->Pen->Color = clpc;
}

void __fastcall LDrawCurve::DrawOriginal(TObject* Sender,float * fP, int istart,int iend,TColor& linecolor)
{
    GetCanvas(Sender);
    //TODO: Add your source code here
    iYMax=OuterRect.bottom-iPrnSign*5;
    iXMax=OuterRect.right-5;
  	iXMin=OuterRect.left+2;
    iYMin=OuterRect.Top+iPrnSign*2;
    ptCanvas->Pen->Style = (TPenStyle)LineType[iLineTypeIndex];
    ptCanvas->Pen->Mode=pmCopy;
    ptCanvas->Pen->Color=clBlack;
    ptCanvas->Pen->Width = 2;
    SetBkMode(ptCanvas->Handle,TRANSPARENT);
	ptCanvas->MoveTo(iXMin,iYMax);
	ptCanvas->LineTo(iXMax,iYMax);
	ptCanvas->LineTo(iXMax,iYMin);
	ptCanvas->LineTo(iXMin,iYMin);
	ptCanvas->LineTo(iXMin,iYMax);

    iYMax -= 4;
    iYMin += 4;

    rectDraw.Left=iXMin;
    rectDraw.Top=iYMin;
    rectDraw.Right=iXMax;
    rectDraw.Bottom=iYMax;
    if(fP == NULL) //如果指针是空则退出
    {
        return;
    }
    fYData = fP;    //将数据指针指向所需数据
    iDrawRgEnd = iend;
    iDrawRgStart = istart;
    int i,itemp;
    if(!bMMValue)
    {
        fYDataMax = fYData[iDrawRgStart];
        fYDataMin = fYData[iDrawRgStart];
        for(i = iDrawRgStart+1;i < iDrawRgEnd; i += 2)
        {
   	        if(fYDataMax<fYData[i])
            {
	    	    fYDataMax=fYData[i];
            }
        	else if(fYDataMin>fYData[i])
            {
	            fYDataMin=fYData[i];
            }
        }
    }
    if(fabs(fYDataMax-fYDataMin)<0.0000001)
   	{
        fYDataMax=0.0001;
        fYDataMin=0.0;
    }
    fXDataMin = istart;
    fXDataMax = iend;

    fXStep=(float)(iXMax-iXMin)/(iDrawRgEnd-iDrawRgStart+1);
	fYStep=(float)(iYMax-iYMin)/(fYDataMax-fYDataMin);

   	iX=iXMin;
    iY=iYMax-(int)((float)(fYData[iDrawRgStart]-fYDataMin)*fYStep);
  	ptCanvas->MoveTo(iX,iY);
    TColor clbk,clbbk,clpc;
    clbk=ptCanvas->Font->Color;
    clbbk=ptCanvas->Brush->Color;
    clpc = ptCanvas->Pen->Color;
    ptCanvas->Font->Color=linecolor;
    ptCanvas->Brush->Color=linecolor;
    ptCanvas->Pen->Color=linecolor;
    ptCanvas->Pen->Width = 1;
    for(i=iDrawRgStart;i<iDrawRgEnd;i+= 2)
  	{
       	iX=iXMin+(int)((float)(i-iDrawRgStart)*fXStep);
        iY=iYMax-(int)((fYData[i]-fYDataMin)*fYStep);
        ptCanvas->LineTo(iX,iY);
    }

    if(bTDCDraw)   //绘制上止点位置
    {
        iX = iXMin + (int)((float)(iTDCPosi-iDrawRgStart)*fXStep);
        ptCanvas->MoveTo(iX,iYMax);
        ptCanvas->LineTo(iX,iYMin);
    }
    if( (fYDataMin <0.0)&&(fYDataMax>0.0) )
    {
        ptCanvas->Pen->Color = clGreen;
        iY = iYMax + (int)(fYDataMin*fYStep);
        ptCanvas->MoveTo(iXMin,iY);
        ptCanvas->LineTo(iXMax,iY);
    }
    ptCanvas->Font->Color = clbk;
    ptCanvas->Brush->Color = clbbk;
    ptCanvas->Pen->Color = clpc;
}

void __fastcall LDrawCurve::lDrawMax(TObject* Sender, MaxInfo* maxinfo, int inum)
{
    //TODO: Add your source code here
    int idieselNum[30];
    float fFai[30];
    float fValue[30];
    GetCanvas(Sender);
//    DrawCoor(Sender);
//    CalculateCoor();
//    DrawCurve(Sender);
    int i,j;
    TRect rect;
    TColor color;
    int ystep;

    ystep = (OuterRect.bottom - OuterRect.top)/5;
    rect.left = OuterRect.left;
    rect.right = OuterRect.right;
    rect.top = OuterRect.top;

    for(j=0;j<inum;j++)
    {
        idieselNum[j] = maxinfo[j].iDieselNum;
    }
    for(i=0;i<5;i++)
    {
        rect.bottom = rect.top + ystep;
        switch(i)
        {
            case 0:  //最大气缸压力
            {
                strDrawText = "最大气缸压力";
                for(j=0; j<inum;j++)
                {
                    fFai[j]   = maxinfo[j].fFaiPMax;
                    fValue[j] = maxinfo[j].fPMax;
                }
                color = clRed;
                break;
            }
            case 1:  //最大压力升高率
            {
                strDrawText = "最大压力升高率";
                for(j=0; j<inum;j++)
                {
                    fFai[j]   = maxinfo[j].fFaiDPDFMax;
                    fValue[j] = maxinfo[j].fDPDFMax;
                }
                color = clAqua;
                break;
            }
            case 2:  //最大气缸温度
            {
                strDrawText = "放热率第一峰值";
                for(j=0; j<inum;j++)
                {
                    fFai[j]   = maxinfo[j].fFDHDFMaxFai;
                    fValue[j] = maxinfo[j].fFDHDFMax;
                }
               // color = clBlue;
                color = (TColor)RGB(150,150,255);
                break;
            }
            case 3:  //最大放热率
            {
                strDrawText = "最大放热率";
                for(j=0; j<inum;j++)
                {
                    fFai[j]   = maxinfo[j].fFaiDHDFMax;
                    fValue[j] = maxinfo[j].fDHDFMax;
                }
                color = clLime;
                break;
            }
            case 4:  //对外作功
            {
                strDrawText = "对外作功";
                for(j=0; j<inum;j++)
                {
                    fFai[j]   = 8;
                    fValue[j] = maxinfo[j].fWMax;
                }
                color = clYellow;
                break;
            }
        }
        DrawMaxDetail(rect,idieselNum,fFai,fValue,inum,color);
        rect.top = rect.bottom;
    }
}

void __fastcall LDrawCurve::DrawMaxDetail(TRect & rect, int * idnum, float* ffai, float* fvalue, int num,TColor color)
{
    //TODO: Add your source code here
    int ixmin,ixmax,iymin,iymax;
    int xposi,yposi,yposibak;
    TRect rtemp;
    TColor cltemp;
    float fymax,fystep;
    int iheight,iwidth;
    int istart = 0;
    int ixminbak;
    int ixtemp,ixmiddle;
    int iyys = 0;
    char chtemp[50];
    AnsiString strTemp;
    if(iDeviceType < 2)
    {
        iyys = 4;
    }
    else
    {
        iyys = -1;
    }
    bLabelSign = false;
    bNumSign = false;
    OuterRect = rect;
    DrawCoor(NULL);
    xposi = iXMin + fXPFactor*5;
    yposi = iYMin + fYPFactor*2;
    yposibak = yposi;
    strTemp = "缸号 曲轴转角 最大值";
    iheight = ptCanvas->TextHeight(strTemp);
    iwidth = ptCanvas->TextWidth( strTemp);
    ptCanvas->TextOut(xposi,yposi,strTemp);
    ixminbak = iXMin;
    yposi +=  (fYPFactor > 0.0? 1.0:-1.0)*abs(iyys);
    for(;istart<8;istart++)
    {
        if(istart == num )
        {
            break;
        }

        yposi += (fYPFactor > 0.0? 1.0:-1.0)*(iheight + iyys);

        sprintf(chtemp," %02d  %5.1f  %8.2f",idnum[istart],ffai[istart],fvalue[istart]);
        strTemp = AnsiString(chtemp);
        ptCanvas->TextOut(xposi,yposi,strTemp);

    }
    ixtemp = xposi + (iwidth +5);
    ptCanvas->MoveTo(ixtemp,iYMin);
    ptCanvas->LineTo(ixtemp,iYMax);
    strTemp = "缸号 曲轴转角 最大值";
    iheight = ptCanvas->TextHeight(strTemp);
    iwidth = ptCanvas->TextWidth( strTemp);
    xposi = xposi + (iwidth+10);
    yposi = yposibak;
    ptCanvas->TextOut(xposi,yposi,strTemp);
    
    yposi +=  (fYPFactor > 0.0? 1.0:-1.0)*(abs(iyys));
    for(;istart<num;istart++)
    {
        if(istart == num )
        {
            break;
        }
        yposi += (fYPFactor > 0.0? 1.0:-1.0)*(iheight + iyys);

        sprintf(chtemp," %02d  %5.1f  %8.2f",idnum[istart],ffai[istart],fvalue[istart]);
        strTemp = AnsiString(chtemp);

//        strTemp.printf(" %02d  %.1f   %.2f",idnum[istart],ffai[istart],fvalue[istart]);
        ptCanvas->TextOut(xposi,yposi,strTemp);
    }

    strTemp = "缸号 曲轴转角 最大值";
    iheight = ptCanvas->TextHeight(strTemp);
    iwidth = ptCanvas->TextWidth( strTemp);
    ixmin = xposi + (iwidth + 40);// fXPFactor* ;
    ixmax = iXMax;
    ixtemp = xposi + (iwidth+15); //fXPFactor*;

    int iy;
    iy =  iYMin + (fYPFactor > 0.0? 1.0 : -1.0)*(iheight + abs(iyys));
    iy +=  (fYPFactor > 0.0? 1.0:-1.0)*(abs(iyys));

    ptCanvas->MoveTo(iXMin,iy);
    ptCanvas->LineTo(ixtemp,iy);

    ptCanvas->MoveTo(ixtemp,iYMin);
    ptCanvas->LineTo(ixtemp,iYMax);

    ixminbak = ixmin;
    if(iDeviceType == 0)
    {
        iymin = iYMin + (fYPFactor > 0.0? 1.0:-1.0)*(10.0);
    }
    else
    {
        iymin = iYMin + (fYPFactor > 0.0? 1.0:-1.0)*(2*iheight+2.0);
    }
    iymax = iYMax ;
    yposibak = (ixmax - ixmin )/num;

    fymax = fvalue[0];
    for(int i=1;i<num;i++)
    {
        if(fymax < fvalue[i])
        {
            fymax = fvalue[i];
        }
    }
    if( fabs(fymax) < 0.0000001)
    {
        fystep = 1.0;
    }
    else
    {
        fystep = (iymax - iymin)/fymax;
    }
    int itemp;
//    TColor color;
    for( int i=0; i<num; i++)
    {
        cltemp = ptCanvas->Brush->Color;
        itemp = i%2;
        rtemp.Left = ixmin + i*yposibak;
        rtemp.Right = rtemp.Left + yposibak-fYPFactor;
        rtemp.Bottom = iymax;
        rtemp.Top = rtemp.Bottom - fvalue[i]*fystep;
        ptCanvas->Brush->Color = color;

        ptCanvas->Rectangle(rtemp);
//        ::ExtFloodFill(
//上面这句用于绘制直方图
        ptCanvas->Brush->Color = cltemp;
        ::SetBkMode(ptCanvas->Handle,TRANSPARENT);
        if(iDeviceType == 1)
        {
            strTemp.printf("%.2f",fvalue[i]);
            ixmiddle = ptCanvas->TextWidth(strTemp);
            ixmiddle = (rtemp.Left + rtemp.Right - ixmiddle)/2;
            ptCanvas->TextOut(ixmiddle,iYMin + fYPFactor*(2+itemp*iheight),strTemp);
 //           if(itemp == 0)
 //           {
                ptCanvas->MoveTo(rtemp.Left+yposibak/2,rtemp.Top);
                ptCanvas->LineTo(rtemp.Left+yposibak/2,iYMin+fYPFactor*(2+(itemp+1)*iheight));
 //           }
        }
        strTemp.printf("%02d",idnum[i]);
        ixmiddle = ptCanvas->TextWidth(strTemp);
        ixmiddle = (rtemp.Left + rtemp.Right - ixmiddle)/2;
        ptCanvas->TextOut(ixmiddle,iYMax - fYPFactor*(2+iheight),strTemp);
    }
    if(iDeviceType != 1)
    {
        iwidth = ptCanvas->TextWidth(strDrawText);
        iheight = ptCanvas->TextHeight(strDrawText);
        ptCanvas->TextOut((ixmin+ixmax-iwidth)/2,(iYMin + fYPFactor*iheight/2),strDrawText);
    }        

    try
    {
            TLogFont logFont;
            HFONT holdFont;
            HFONT hnewFont;
            ::GetObject(ptCanvas->Font->Handle,sizeof(logFont),&logFont);
            if(iDeviceType == 0)
            {
                logFont.lfEscapement  = -900;
                logFont.lfOrientation = -900;
            }
            else
            {
                logFont.lfEscapement  = 900;
                logFont.lfOrientation = 900;
            }
            hnewFont = ::CreateFontIndirect(&logFont);
            holdFont = ::SelectObject(ptCanvas->Handle,hnewFont);
            if(iDeviceType == 1)
            {
                iwidth = ptCanvas->TextHeight(strDrawText);
                iheight = ptCanvas->TextWidth(strDrawText);
                ptCanvas->TextOut(ixminbak - fXPFactor*(iwidth + 2),( iYMax + iYMin + iheight)/2,strDrawText);
            }
            else
 //           if((iDeviceType == 0)||(iDeviceType == 2))
            {
                for( int i=0; i<num; i++)
                {
                    itemp = i%2;
                    ::SetBkMode(ptCanvas->Handle,TRANSPARENT);
                    strTemp.printf("%.2f",fvalue[i]);
                    iwidth = ptCanvas->TextHeight(strTemp);
                    iheight = ptCanvas->TextWidth(strTemp);
                    ptCanvas->TextOut(ixminbak+(i+1)*yposibak - (iwidth + 5),
                                      (iYMin + iYMax)/2 + (fYPFactor > 0.0? 1.0:-1.0)*(iheight + 40)/2,strTemp);
                }
            }
            ::SelectObject(ptCanvas->Handle,holdFont);
            ::DeleteObject(hnewFont);
   }
   catch(...)
   {
        Application->MessageBox("绘图过程出现错误","错误",MB_OK);
        return;
   }
}

void __fastcall LDrawCurve::SetbDifferentColor(bool bDColor, TColor& cl1, TColor& cl2, TColor& cl3, TColor& cl4)
{
    //TODO: Add your source code here
    bDifferentColor = bDColor;
    clColor1        = cl1;
    clColor2        = cl2;
    clColor3        = cl3;
    clColor4        = cl4;
}

void __fastcall LDrawCurve::DrawPipeWave(TObject* Sender)
{
    float fYStepBackup;
    TColor clBackup;
    int iWBackup;
    fYStepBackup = fYStep;
    clBackup = ptCanvas->Pen->Color;
    iWBackup  = ptCanvas->Pen->Width;
    if(bDrawPWave)   //如果绘制油管压力波形，则绘制.
    {
        if((fPOilMax - fPOilMin)<10)
        {
            return;
        }
        fPOilMax = 32768.0/fOilGain;
	    fYStep = (float)(iYMax-iYMin)/(fPOilMax - fPOilMin)*3.0/2.0;
      	iX = iXMin + (int)((float)(fXData[iDrawRgStart]-fXDataMin)*fXStep);
        iY = iYMax-(int)((float)(fPData[iDrawRgStart] - fPOilMin)*fYStep);
        ptCanvas->Pen->Color = clPurple;
       	ptCanvas->MoveTo(iX,iY);
        for(int i = iDrawRgStart; i < iDrawRgEnd; i ++)
      	{
           	iX = iXMin + (int)((float)(fXData[i]-fXDataMin)*fXStep);
            iY = iYMax - (int)((fPData[i] - fPOilMin)*fYStep);
            ptCanvas->LineTo(iX,iY);
        }
    }
    if(bDrawCWave)   //如果绘制气缸压力波形，true则绘制.
    {
        if((fCylinderPMax - fCylinderPMin)<1)
        {
            return;
        }
	    fYStep = (float)(iYMax-iYMin - 20)/(fCylinderPMax);
      	iX = iXMin + (int)((float)(fXData[iDrawRgStart]-fXDataMin)*fXStep);
        iY = iYMax-(int)((float)(fCPData[iDrawRgStart])*fYStep);
        ptCanvas->Pen->Color = clGreen;
        ptCanvas->Pen->Width = 2;
       	ptCanvas->MoveTo(iX,iY);
        for(int i = iDrawRgStart; i < iDrawRgEnd; i ++)
      	{
           	iX = iXMin + (int)((float)(fXData[i]-fXDataMin)*fXStep);
            iY = iYMax - (int)((fCPData[i])*fYStep);
            ptCanvas->LineTo(iX,iY);
        }
    }
    ptCanvas->Pen->Color = clBackup;
    ptCanvas->Pen->Width = iWBackup;
    fYStep = fYStepBackup;
}


void __fastcall LDrawCurve::Draw3D(TObject* Sender,float * fX,
                                    float * fY,
                                    float** fZ,
                                    int iXN,
                                    int iYN,

                                    l3DInfo* myinfo
                                    )
{
    //TODO: Add your source code here
    GetCanvas(Sender);
    Draw3DCoor();
    TPoint point[5];
    int x0,y0;
    int xp,yp,xlength,xbk,ybk;
    float xstep,ystep,zstep;
    float xx,yy,zz;
    float x00,y00;
    float zposi;

    TRect rectTemp;
    float fValueStep;
    int isize;
    int iheight,iwidth;
    AnsiString strTemp;
    int ixmiddle;

    fXDataMin = 0.0;
    fXDataMax = 16.0;
    fYDataMin = (float)iDrawRgStart;
    fYDataMax = (float)iDrawRgEnd;

//    fZDataMin = 0.0;
//    fZDataMax = 18.0;

    fZData    = fZ;

//-------------------------------------------------------------------
// 以下先绘制时间平面图

    strTemp.printf("%.3f",fZDataMax);
    iwidth  = ptCanvas->TextWidth(strTemp) + 4;
    iheight = ptCanvas->TextHeight(strTemp);

    xstep = (float)iXTimeInterval/(fYDataMax - fYDataMin);
    ystep = (float)(iYTimeInterval - 5)/(fZDataMax );
    zstep = (float)(rectTime.Width() - iwidth - iXTimeInterval)/17.0;
    if(bYAxisHalf)
    {
        x0 = rectTime.Left + iwidth;
        y0 = rectTime.Top + (rectTime.Bottom - rectTime.Top)*2/3;
    }
    else
    {
        x0 = rectTime.Left + iwidth;
        y0 = rectTime.Bottom - 16;
    }

 //  fXValueStep = (iDrawRgEnd - iDrawRgStart)*0.5/6.0;

    fValueStep  = fZDataMax/5.0;
    ptCanvas->Brush->Style = bsClear;
    for(int i = 0; i < 6; i++)
    {
        ptCanvas->Pen->Color = clWhite;
        y00 = y0 - (float)i*fValueStep*ystep;
        ptCanvas->MoveTo(x0,y00);
        ptCanvas->LineTo(rectTime.Right - 4,y00);
        ptCanvas->Pen->Color = clBlack;

        strTemp.printf("%.3f",(float)i*fValueStep);
        ptCanvas->TextOut(rectTime.Left + 3,y00 - iheight/2 ,strTemp);
    }
    
    ptCanvas->TextOut(rectTime.Left + 3, y0 - iheight/2 ,"0.0");

    ptCanvas->Brush->Style = bsSolid;

    ptCanvas->Pen->Color = clWhite;
    ptCanvas->MoveTo(rectTime.Right - 4, y00);
    ptCanvas->LineTo(rectTime.Right - 4, y0);
    ptCanvas->MoveTo(x0, y0 - (int)(5.0*fValueStep*ystep));
    ptCanvas->LineTo(x0, y0);

    for(int i=0; i < iXN; i++)
    {
        ptCanvas->Pen->Color   = CURVECOLOR[i];

        y00 = (float)myinfo[i].iDieselNum;
        x00 = x0 + y00*zstep;
        y00 = y0 - fZData[i][0]*ystep;

        strTemp.printf("%02d",myinfo[i].iDieselNum);
        ptCanvas->Brush->Style = bsClear; //TBrush
        ptCanvas->TextOut(x00 - 6, y0, strTemp);


        ptCanvas->MoveTo(x00,y00);
        for(int j = iDrawRgStart + 1; j<iDrawRgEnd; j++ )
        {
            xx = (float)(j -iDrawRgStart);
            zposi = xx*xstep;
            xp = x00   + xx * xstep;
            yp = y0    - fZData[i][j]*ystep;
            ptCanvas->LineTo(xp,yp);
        }
        if(bShowCut)
        {   ptCanvas->Brush->Style = bsSolid;
            xx = (float)(iCutPosi - iDrawRgStart);
            zposi = xx*xstep;
            xp = x00   + xx * xstep;
            yp = y0 - fZData[i][iCutPosi]*ystep;
            ptCanvas->Pen->Mode = pmNot;
            ptCanvas->MoveTo(xp,y0);
            ptCanvas->LineTo(xp,yp);
            ptCanvas->Ellipse(xp - 3,yp - 3, xp + 3, yp + 3);
            ptCanvas->Pen->Mode = pmCopy;
        }
     }
//---------------------------------------------------------
        ptCanvas->Pen->Color   = CURVECOLOR[iSelectedItem];
        ptCanvas->Pen->Width   = 2;
        y00 = (float)myinfo[iSelectedItem].iDieselNum;
        x00 = x0 + y00*zstep;
        y00 = y0 - fZData[iSelectedItem][0]*ystep;

        strTemp.printf("%02d",myinfo[iSelectedItem].iDieselNum);
        ptCanvas->Brush->Style = bsClear; //TBrush
        ptCanvas->TextOut(x00 - 6, y0, strTemp);


        ptCanvas->MoveTo(x00,y00);
        for(int j = iDrawRgStart + 1; j<iDrawRgEnd; j++ )
        {
            xx = (float)(j -iDrawRgStart);
            zposi = xx*xstep;
            xp = x00   + xx * xstep;
            yp = y0    - fZData[iSelectedItem][j]*ystep;
            ptCanvas->LineTo(xp,yp);
        }
        if(bShowCut)
        {   ptCanvas->Brush->Style = bsSolid;
            xx = (float)(iCutPosi - iDrawRgStart);
            zposi = xx*xstep;
            xp = x00   + xx * xstep;
            yp = y0 - fZData[iSelectedItem][iCutPosi]*ystep;
            ptCanvas->Pen->Mode = pmNot;
            ptCanvas->MoveTo(xp,y0);
            ptCanvas->LineTo(xp,yp);
            ptCanvas->Ellipse(xp - 3,yp - 3, xp + 3, yp + 3);
            ptCanvas->Pen->Mode = pmCopy;
        }
        ptCanvas->Pen->Width   = 1;
//==================================================================
// rectMaxValue 此处在窗体上显示各缸的最大值，对应角度，
    ptCanvas->Brush->Style = bsClear;
    isize = ptCanvas->Font->Size;
    ptCanvas->Font->Size = 11;
    ptCanvas->Font->Name = "Arial";
    strTemp = "缸号 角度 最大值";

    iheight = ptCanvas->TextHeight(strTemp);
    iwidth  = ptCanvas->TextWidth(strTemp);
    iheight = (int)((float)iheight - 4);
    ptCanvas->TextOut( rectMaxValue.Left + 2, rectMaxValue.Top + 4 ,strTemp);
    strTemp = AnsiString("　　 /CA　/MPa");
//    ptCanvas->MoveTo(rectMaxValue.Left + 2, rectMaxValue.Top + 2 + iheight );
//    ptCanvas->LineTo(rectMaxValue.Left + 2 + iwidth, rectMaxValue.Top + 2 + iheight);
    ptCanvas->TextOut( rectMaxValue.Left + 2, rectMaxValue.Top + iheight + 4 ,strTemp);
    for(int i=0; i < iXN; i++)
    {
        strTemp.printf(" %02d %7.1f %8.3f",
                                           myinfo[i].iDieselNum,
                                           myinfo[i].fMaxAngle,
                                           myinfo[i].fMaxValue
                                           );
        ptCanvas->TextOut( rectMaxValue.Left + 2,
                           rectMaxValue.Top + 4 + (i + 2)*iheight,
                           strTemp);
    }

    ptCanvas->Font->Color   =         CURVECOLOR[iSelectedItem];
    strTemp.printf(" %02d %7.1f %8.3f",myinfo[iSelectedItem].iDieselNum,
                                          myinfo[iSelectedItem].fMaxAngle,
                                          myinfo[iSelectedItem].fMaxValue);
    ptCanvas->TextOut( rectMaxValue.Left + 2,
                       rectMaxValue.Top  + 4 + (iSelectedItem + 2)*iheight,
                       strTemp);
    ptCanvas->Font->Color   = clBlack;

//=============================================================================
// 绘制断面平面图
// rectCutValue:　在窗体上显示各个断面的数值及对应角度
    ptCanvas->Font->Color   = clBlack;
    strTemp = AnsiString("缸号 角度  数值");

    iheight = ptCanvas->TextHeight(strTemp);
    iwidth  = ptCanvas->TextWidth(strTemp);
    iheight = (int)((float)iheight - 4);
    ptCanvas->TextOut(rectCutValue.Left + 2, rectCutValue.Top + 4 ,strTemp);
    strTemp = AnsiString("　 　/CA    /MPa");
    ptCanvas->TextOut(rectCutValue.Left + 2, rectCutValue.Top + iheight + 4 ,strTemp);
    for(int i=0; i < iXN; i++)
    {
        strTemp.printf(" %02d %7.1f %7.3f",myinfo[i].iDieselNum, fStartAngle + 0.2*(float)(iCutPosi),  fZData[i][iCutPosi]);
        ptCanvas->TextOut( rectCutValue.Left + 2, rectCutValue.Top + 4 + (i + 2)*iheight,strTemp);
    }

    ptCanvas->Font->Color   = CURVECOLOR[iSelectedItem];
    strTemp.printf(" %02d %7.1f %7.3f",
                            myinfo[iSelectedItem].iDieselNum,
                            fStartAngle + 0.2*(float)(iCutPosi),
                            fZData[iSelectedItem][iCutPosi]);
    ptCanvas->TextOut( rectCutValue.Left + 2,
                       rectCutValue.Top + 4 + (iSelectedItem + 2)*iheight,
                       strTemp);
    ptCanvas->Font->Color   = clBlack;
//=========================================================================

//---------------------------------------------------------------------
// 以下用于绘制切面图

    ptCanvas->Font->Size = isize;
    strTemp.printf("%.3f",fZDataMax);
    iwidth  = ptCanvas->TextWidth(strTemp) + 4;
    iheight = ptCanvas->TextHeight(strTemp);
    ystep = (float)(iYTimeInterval - 5)/(fZDataMax );
    xstep = (float)(rectValue.Width() - iwidth)/17.0;

    if(bYAxisHalf)
    {
        x0 = rectValue.Left + iwidth;
        y0 = rectValue.Top + (rectValue.Bottom - rectValue.Top)*2/3;
    }
    else
    {
        x0 = rectValue.Left + iwidth;
        y0 = rectValue.Bottom - 16;
    }
// 绘制网格线

    fValueStep = fZDataMax/5.0;

    for(int i = 1; i < 6; i++)
    {
        ptCanvas->Pen->Color = clWhite;
        y00 = y0 - (float)i*fValueStep*ystep;
        ptCanvas->MoveTo(x0,y00);
        ptCanvas->LineTo(rectValue.Right - 4,y00);
        ptCanvas->Pen->Color = clBlack;
        strTemp.printf("%.3f",(float)i*fValueStep);
        ptCanvas->TextOut(rectValue.Left + 3,y00 - iheight/2 ,strTemp);
    }
    ptCanvas->TextOut(rectValue.Left + 3, y0 - iheight/2 ,"0.0");
    ptCanvas->Pen->Color = clWhite;

    ptCanvas->MoveTo(rectValue.Right - 4, y00);
    ptCanvas->LineTo(rectValue.Right - 4, y0);

//    ptCanvas->Pen->Color = clBlack;
    ptCanvas->MoveTo(x0,y0);
    ptCanvas->LineTo(x0, y0 - (int)(5.0*fValueStep*ystep));
    ptCanvas->MoveTo(x0,y0);
    ptCanvas->LineTo(rectValue.Right - 2, y0);

    for(int i = 0; i < iXN; i++)
    {
        ptCanvas->Pen->Color   = CURVECOLOR[i];
        ptCanvas->Brush->Color = CURVECOLOR[i];
        ptCanvas->Brush->Style = bsSolid;
        strTemp.printf("%02d",myinfo[i].iDieselNum);
        y00 = (float)myinfo[i].iDieselNum;
        x00 = x0 + y00*xstep;
        y00 = y0 - fZData[i][iCutPosi]*ystep;

        rectTemp.Left  = x00 - 6;
        rectTemp.Right = x00 + 6;
        rectTemp.Top   = y00;
        rectTemp.Bottom = y0;
        ptCanvas->Rectangle(rectTemp);
        ptCanvas->Brush->Style = bsClear; //TBrush
        ptCanvas->TextOut(x00 - 6, y0, strTemp);
        strTemp.printf("%.3f",fZData[i][iCutPosi]);
        ixmiddle = ptCanvas->TextWidth(strTemp);
        ixmiddle = (rectTemp.Left + rectTemp.Right - ixmiddle)/2;

        if(i % 2 == 0)
        {
            ptCanvas->TextOut(ixmiddle,rectTemp.Top - 35,strTemp);
            ptCanvas->MoveTo(x00, rectTemp.Top);
            ptCanvas->LineTo(x00, rectTemp.Top - 35 + iheight);
        }
        else
        {
            ptCanvas->TextOut(ixmiddle,rectTemp.Top - 20,strTemp);
            ptCanvas->MoveTo(x00, rectTemp.Top);
            ptCanvas->LineTo(x00, rectTemp.Top - 20 + iheight);
        }
    }
//================================================================
//----------------------------------------------------------------
// 绘制单个的图形
//===========================================================
    ptCanvas->Font->Size = isize;
    strTemp.printf("%.3f",fZDataMax);
    iwidth  = ptCanvas->TextWidth(strTemp) + 4;
    iheight = ptCanvas->TextHeight(strTemp);

    ystep = (float)(iYTimeInterval - 5)/(fZDataMax );
    xstep = (float)(rectSingle.Width() - iwidth)/(iDrawRgEnd - iDrawRgStart);
    
    if(bYAxisHalf)
    {
        x0 = rectSingle.Left + iwidth;
        y0 = rectSingle.Top + rectTime.Height()*2/3;
    }
    else
    {
        x0 = rectSingle.Left + iwidth;
        y0 = rectSingle.Bottom - 16;
    }

    for(int i = 0; i < 6; i++)
    {
        ptCanvas->Pen->Color = clWhite;
        y00 = y0 - (float)i*fValueStep*ystep;
        ptCanvas->MoveTo(x0,y00);
        ptCanvas->LineTo(rectSingle.Right - 4,y00);
        ptCanvas->Pen->Color = clBlack;
        strTemp.printf("%.3f",(float)i*fValueStep);
        ptCanvas->TextOut(rectSingle.Left + 3,y00 - iheight/2 ,strTemp);
    }
    ptCanvas->Pen->Color = clWhite;

        

    ptCanvas->MoveTo(rectSingle.Right - 4, y00);
    ptCanvas->LineTo(rectSingle.Right - 4, y0);


    ptCanvas->MoveTo(x0,y0);
    ptCanvas->LineTo(x0, y0 - (int)(5.0*fValueStep*ystep));
    ptCanvas->MoveTo(x0,y0);
    ptCanvas->LineTo(rectSingle.Right - 2, y0);

// 绘制X坐标 myinfo[iXN - 1].iTopDeadPosi;//上止点的位置
    int itemp;
    itemp = x0 + (myinfo[iXN - 1].iTopDeadPosi - iDrawRgStart)*xstep ;
    ptCanvas->Pen->Color = clBlack;
    ptCanvas->MoveTo( itemp,y0);
    ptCanvas->LineTo( itemp, y0 - 5.0*fValueStep*ystep) ;
    strTemp.printf("0.0");
    ptCanvas->TextOut( itemp - 8,y0,strTemp);

/*
    for( int i = 0; i < 6; i++)
    {
        fStartAngle + 0.5*(float)(iCutPosi);
    }
*/

    ptCanvas->Pen->Color = CURVECOLOR[iSelectedItem];
    x00 = x0;
    y00 = y0 - fZData[iSelectedItem][iDrawRgStart]*ystep;

    ptCanvas->MoveTo(x00,y00);
    for(int j = iDrawRgStart + 1; j<iDrawRgEnd; j++ )
    {
        xx = (float)(j -iDrawRgStart);
        xp = x0   + xx * xstep;
        yp = y0   - fZData[iSelectedItem][j]*ystep;
        ptCanvas->LineTo(xp,yp);
    }
    if(bShowCut)
    {   ptCanvas->Brush->Style = bsSolid;
        xx = (float)(iCutPosi - iDrawRgStart);
        xp = x00   + xx * xstep;
        yp = y0 - fZData[iSelectedItem][iCutPosi]*ystep;
        ptCanvas->Pen->Mode = pmNot;
        ptCanvas->MoveTo(xp,y0);
        ptCanvas->LineTo(xp,yp);
        ptCanvas->Ellipse(xp - 3,yp - 3, xp + 3, yp + 3);
        ptCanvas->Pen->Mode = pmCopy;
    }
    ptCanvas->Pen->Width   = 1;

//==================================================================


// 以下绘制3D图形
    xstep = (float)(iXLength)/(fYDataMax - fYDataMin);
    if(fXDataMax > 1.0)
    {
        ystep = (float)(iYLength)/(fXDataMax - fXDataMin - 1.0);
    }
    else
    {
        return;
    }
    zstep = (float)(iZMax - iZMin)/(fZDataMax - fZDataMin);

    int itempp;
    itempp  = (int)(fAlpha)%360;

    if(  (itempp > -90) && (itempp < 90)
       ||(itempp > 270)
       ||(itempp < -270)
       )
    {
        for(int i=0; i < iXN; i++)
        {
            ptCanvas->Pen->Color   = CURVECOLOR[i];
            ptCanvas->Brush->Color = CURVECOLOR[i];
            ptCanvas->Brush->Style = bsSolid;
            y00 = (float)(myinfo[i].iDieselNum - 1);
            x00 = iX0Posi + y00*ystep*cos(PI/180.0*fBata);
            y00 = iY0Posi - y00*ystep*sin(PI/180.0*fBata);

            xp = x00 + xx * xstep*cos(PI/180.0*fAlpha);

            yp = y00 - fZData[i][0]*zstep;
            point[0].x = x00;
            point[0].y = y00;

            point[1].x = x00;
            point[1].y = yp;
            ptCanvas->MoveTo(x00,y00);
            ptCanvas->LineTo(x00,yp);

            for(int j = iDrawRgStart + 1; j<iDrawRgEnd; j++)
            {
                ptCanvas->Pen->Color   = CURVECOLOR[i];
                ptCanvas->Brush->Color = CURVECOLOR[i];
                xx = (float)(j -iDrawRgStart);

                zposi = xx*xstep*sin(PI/180.0*fAlpha);
                xp = x00 + xx * xstep*cos(PI/180.0*fAlpha);

                yp = y00 - fZData[i][j]*zstep - zposi;
                point[2].x = xp;
                point[2].y = y00 - zposi;
                point[3].x = xp;
                point[3].y = yp;
                point[4].x = point[0].x;
                point[4].y = point[0].y;
                ptCanvas->Polygon((TPoint*)(&point),3);

                point[0].x = point[3].x;
                point[0].y = point[3].y;
                point[1].x = point[2].x;
                point[1].y = point[2].y;
                point[4].x = point[0].x;
                point[4].y = point[0].y;

            }
            if(bShowCut)
            {
                xx = (float)(iCutPosi - iDrawRgStart);

                zposi = xx*xstep*sin(PI/180.0*fAlpha);
                xp = x00 + xx * xstep*cos(PI/180.0*fAlpha);
                yp = y00 - fZData[i][iCutPosi]*zstep - zposi;

                ptCanvas->Pen->Mode = pmNot;
                ptCanvas->MoveTo(xp,y00 - zposi);
                ptCanvas->LineTo(xp,yp);
                ptCanvas->Ellipse(xp - 3,yp - 3, xp + 3, yp + 3);
                ptCanvas->Pen->Mode = pmCopy;
            }
        }
//重新画一次被选中的图形

        if(iSelectedItem != (iXN - 1))
        {
            ptCanvas->Pen->Color   = CURVECOLOR[iSelectedItem];
            ptCanvas->Brush->Color = CURVECOLOR[iSelectedItem];
            ptCanvas->Brush->Style = bsSolid;
            y00 = (float)(myinfo[iSelectedItem].iDieselNum - 1);
            x00 = iX0Posi + y00*ystep*cos(PI/180.0*fBata);
            y00 = iY0Posi - y00*ystep*sin(PI/180.0*fBata);

            xp = x00 + xx * xstep*cos(PI/180.0*fAlpha);

            yp = y00 - fZData[iSelectedItem][0]*zstep;
            point[0].x = x00;
            point[0].y = y00;

            point[1].x = x00;
            point[1].y = yp;
            ptCanvas->MoveTo(x00,y00);
            ptCanvas->LineTo(x00,yp);

            for(int j = iDrawRgStart + 1; j<iDrawRgEnd; j++)
            {
                xx = (float)(j -iDrawRgStart);

                zposi = xx*xstep*sin(PI/180.0*fAlpha);
                xp = x00 + xx * xstep*cos(PI/180.0*fAlpha);

                yp = y00 - fZData[iSelectedItem][j]*zstep - zposi;
                point[2].x = xp;
                point[2].y = y00 - zposi;
                point[3].x = xp;
                point[3].y = yp;
                point[4].x = point[0].x;
                point[4].y = point[0].y;
                ptCanvas->Polygon((TPoint*)(&point),3);

                point[0].x = point[3].x;
                point[0].y = point[3].y;
                point[1].x = point[2].x;
                point[1].y = point[2].y;
                point[4].x = point[0].x;
                point[4].y = point[0].y;

            }
            if(bShowCut)
            {
                xx = (float)(iCutPosi - iDrawRgStart);

                zposi = xx*xstep*sin(PI/180.0*fAlpha);
                xp = x00 + xx * xstep*cos(PI/180.0*fAlpha);
                yp = y00 - fZData[iSelectedItem][iCutPosi]*zstep - zposi;

                ptCanvas->Pen->Mode = pmNot;
                ptCanvas->MoveTo(xp,y00 - zposi);
                ptCanvas->LineTo(xp,yp);
                ptCanvas->Ellipse(xp - 3,yp - 3, xp + 3, yp + 3);
                ptCanvas->Pen->Mode = pmCopy;
            }
        }

    }
    else
    {
        for(int i = iXN - 1; i <= 0 ; i--)
//    for(int i=0; i < 1; i++)
        {
            ptCanvas->Pen->Color   = CURVECOLOR[i];
            ptCanvas->Brush->Color = CURVECOLOR[i];
            ptCanvas->Brush->Style = bsSolid;
            y00 = (float)(myinfo[i].iDieselNum - 1);
            x00 = iX0Posi + y00*ystep*cos(PI/180.0*fBata);
            y00 = iY0Posi - y00*ystep*sin(PI/180.0*fBata);

            xp = x00 + xx * xstep*cos(PI/180.0*fAlpha);

            yp = y00 - fZData[i][0]*zstep;

            point[0].x = x00;
            point[0].y = y00;

            point[1].x = x00;
            point[1].y = yp;

            for(int j = iDrawRgStart + 1; j<iDrawRgEnd; j++)
            {
                ptCanvas->Pen->Color   = CURVECOLOR[i];
                ptCanvas->Brush->Color = CURVECOLOR[i];
                xx = (float)(j - iDrawRgStart);

                zposi = xx*xstep*sin(PI/180.0*fAlpha);
                xp = x00
                   + xx * xstep*cos(PI/180.0*fAlpha);
           //        - fZData[i][j]*zstep *sin(PI/180.0*fAlpha);

                yp = y00 - fZData[i][j]*zstep - zposi;

                point[2].x = xp;
                point[2].y = y00 - zposi;
                point[3].x = xp;
                point[3].y = yp;
                point[4].x = point[0].x;
                point[4].y = point[0].y;
                ptCanvas->Polygon((TPoint*)(&point),3);
                point[0].x = point[3].x;
                point[0].y = point[3].y;
                point[1].x = point[2].x;
                point[1].y = point[2].y;
                point[4].x = point[0].x;
                point[4].y = point[0].y;
            }
            if(bShowCut)
            {
                xx = (float)(iCutPosi - iDrawRgStart);
                zposi = xx*xstep*sin(PI/180.0*fAlpha);
                xp = x00 + xx * xstep*cos(PI/180.0*fAlpha);
                yp = y00 - fZData[i][iCutPosi]*zstep - zposi;

                ptCanvas->Pen->Mode = pmNot;
                ptCanvas->MoveTo(xp,y00 - zposi);
                ptCanvas->LineTo(xp,yp);
                ptCanvas->Ellipse(xp - 3,yp - 3, xp + 3, yp + 3);
                ptCanvas->Pen->Mode = pmCopy;
           }
        }
    }
}

void __fastcall LDrawCurve::Draw3DCoor(void)
{
    //TODO: Add your source code here
    TPoint point[5];
    ptCanvas->Pen->Color = clBlack;
    rectDraw.Left        = iXMin;
    rectDraw.Top         = iYMin;
    rectDraw.Right       = iXMax;
    rectDraw.Bottom      = iYMax;

// 在这个矩形内绘制随时间变化的曲线
    DrawBack(rectTime,     (TColor)RGB(220,220,220), clGray, 3);
    DrawBack(rectValue,    (TColor)RGB(220,220,220), clGray, 3);
    DrawBack(rectMaxValue, (TColor)RGB(220,220,220), clGray, 3);
    DrawBack(rectCutValue, (TColor)RGB(220,220,220), clGray, 3);
    DrawBack(rectSingle,   (TColor)RGB(220,220,220), clGray, 3);
    
    ShrinkRect(rectTime,     3,3);
    ShrinkRect(rectValue,    3,3);
    ShrinkRect(rectMaxValue, 3,3);
    ShrinkRect(rectCutValue, 3,3);
    ShrinkRect(rectSingle,   3,3);

//    float ftemp;
    int xp,yp,zp,x0,y0,z0;
    x0 = iX0Posi;
    y0 = iY0Posi;

//    ftemp = tan(PI/180.0*fAlpha);

    xp = x0 + iXLength*cos(PI/180.0*fAlpha);
    yp = y0 - iXLength*sin(PI/180.0*fAlpha);
    point[0].x = x0;
    point[0].y = y0;

    iXMax = xp;
    ptCanvas->MoveTo(x0,y0);
    ptCanvas->LineTo(xp,yp);
    point[1].x = xp;
    point[1].y = yp;
    x0 = xp;
    y0 = yp;
    xp = x0 + iYLength*cos(PI/180.0*fBata);
    yp = y0 - iYLength*sin(PI/180.0*fBata);
    ptCanvas->LineTo(xp,yp);
    point[2].x = xp;
    point[2].y = yp;
    x0 = xp;
    y0 = yp;

    xp = x0 + iXLength*cos(PI/180.0*(180.0 + fAlpha));
    yp = y0 - iXLength*sin(PI/180.0*(180.0 + fAlpha));
    ptCanvas->LineTo(xp,yp);
    iYMin = yp;
    point[3].x = xp;
    point[3].y = yp;
    xp = iX0Posi;
    yp = iY0Posi;
    x0 = xp;
    y0 = yp;
    ptCanvas->LineTo(xp,yp);
    point[4].x = xp;
    point[4].y = yp;
    ptCanvas->Pen->Color   = (TColor)RGB(220,220,220);
    ptCanvas->Brush->Color = (TColor)RGB(220,220,220);
    ptCanvas->Brush->Style = bsSolid;
    ptCanvas->Polygon((TPoint*)(&point),4);
    iZMax = iY3DInterval;
    iZMin = 0;
}

void __fastcall LDrawCurve::SetbTwoInfo(bool bti)
{
    //TODO: Add your source code here
    bTwoInfo = bti;
}

void __fastcall LDrawCurve::DrawBack(TRect& rect, TColor clface, TColor clback, int shift)
{
    //TODO: Add your source code here
    TColor  clpc,clbc;
    rect.Left   += shift;
    rect.Right  += shift;
    rect.Top    += shift;
    rect.Bottom += shift;
    clpc = ptCanvas->Pen->Color;
    clbc = ptCanvas->Brush->Color;
    ptCanvas->Pen->Color   = clback;
    ptCanvas->Brush->Color = clback;
    ptCanvas->Brush->Style = bsSolid;
    ptCanvas->Rectangle(rect);
    rect.Left   -= shift;
    rect.Right  -= shift;
    rect.Top    -= shift;
    rect.Bottom -= shift;
    ptCanvas->Pen->Color   = clface;
    ptCanvas->Brush->Color = clface;
    ptCanvas->Brush->Style = bsSolid;
    ptCanvas->Rectangle(rect);
    ptCanvas->Pen->Color   = clpc;
    ptCanvas->Brush->Color = clbc;

}

void __fastcall LDrawCurve::ShrinkRect(TRect& rect, int ixsize,int iysize)
{
    //TODO: Add your source code here
    TColor clPen,clBrush;
    clPen   = ptCanvas->Pen->Color;
    clBrush = ptCanvas->Brush->Color;
    ptCanvas->Pen->Color   = clGray;
  
    rect.Left   += ixsize;
    rect.Right  -= ixsize;
    rect.Top    += iysize;
    rect.Bottom -= iysize;

    ptCanvas->MoveTo(rect.Right, rect.Top);
    ptCanvas->LineTo(rect.Left,  rect.Top);
    ptCanvas->LineTo(rect.Left,  rect.Bottom);
    ptCanvas->Pen->Color   = clWhite;

    ptCanvas->MoveTo(rect.Left,rect.Bottom);
    ptCanvas->LineTo(rect.Right,rect.Bottom);
    ptCanvas->LineTo(rect.Right, rect.Top);
    ptCanvas->Pen->Color   = clPen;
    ptCanvas->Brush->Color = clBrush;
}

void __fastcall LDrawCurve::GetTrainInfo(AnsiString& str)
{
    //TODO: Add your source code here
    AnsiString strTemp;
    strTemp = ExtractFileName( str );
    
}

void __fastcall LDrawCurve::SetCurveColor(TColor* cl, int inum)
{
    //TODO: Add your source code here
    for(int i = 0; i < inum; i++)
    {
        CURVECOLOR[i] = cl[i];
    }
}
