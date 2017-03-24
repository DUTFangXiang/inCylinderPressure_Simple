//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "USetupColor.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormSetupColor *FormSetupColor;
const TColor MAIN_CURVECOLOR[16] ={
     (TColor)RGB(80,80,80),
     clMaroon,
     clGreen,
     clOlive,
     clNavy,
     clPurple,
     clTeal,
     clLime,
     (TColor)RGB(100,0,0),
     clYellow,
     (TColor)RGB(0,100,0) ,
     clFuchsia,
     (TColor)RGB(100,100,0),
     clAqua,
     (TColor)RGB(0,100,100),
      clRed
};

//---------------------------------------------------------------------------
__fastcall TFormSetupColor::TFormSetupColor(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSetupColor::LabelTextClick(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
//        LabelText->Color=
        LabelText->Font->Color = ColorDialog1->Color;
        clSetupColor[1]        = ColorDialog1->Color;
        DrawImage();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormSetupColor::PanelBackgroundClick(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
//        LabelText->Color=
        PanelBackground->Color = ColorDialog1->Color;
        clSetupColor[2]        = ColorDialog1->Color;
        DrawImage();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormSetupColor::Image1Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        clSetupColor[0] = ColorDialog1->Color;
        DrawImage();
    }
}

//---------------------------------------------------------------------------


void __fastcall TFormSetupColor::DrawImage(void)
{
    //TODO: Add your source code here
    Image1->Canvas->Pen->Color = clSetupColor[0];
    Image1->Canvas->Pen->Width = 1;
    TRect rect,recta;
    rect = Image1->ClientRect;
    Image1->Canvas->Brush->Color=clSetupColor[2];
    Image1->Canvas->FillRect(rect);
    Image1->Canvas->Rectangle(rect);
    recta.Left   = rect.Left;
    recta.Top    = rect.Top;
    recta.Bottom = rect.Bottom;
    recta.Right  = recta.Bottom;
    int Rotation, PointCount,iXMiddle,iYMiddle,iRadium;

    iXMiddle   = (rect.Left + rect.Right)/2;
    iYMiddle   = (rect.Top  + rect.Bottom)/2;
    iRadium    = rect.Width()>rect.Height()?rect.Height()/2:rect.Width()/2;
    Rotation   = 0;
    PointCount = MaxPoints;
    const float M_2PI = 2*M_PII;
    float StepAngle = M_2PI/PointCount;
    Rotation += M_2PI/PointCount;
    Rotation += M_2PI/32;
    if(Rotation > StepAngle)
    {
        Rotation -= StepAngle;
    }
    float j;
    int i=0;
    for(i=0,j=Rotation;i<MaxPoints;i++,j+=StepAngle)
    {
        Points[i].x = iRadium*cos(j);
        Points[i].y = iRadium*sin(j);
    }

    Image1->Canvas->Ellipse(iXMiddle - iRadium,
                            iYMiddle - iRadium,
                            iXMiddle + iRadium,
                            iYMiddle + iRadium);
    for(int i=0;i<MaxPoints;i++)
    {
        for(int j=0;j<MaxPoints;j++)
        {
            Image1->Canvas->MoveTo(iXMiddle + floor(Points[i].x),
                              iYMiddle + floor(Points[i].y));
            Image1->Canvas->LineTo(iXMiddle + floor(Points[j].x),
                              iYMiddle + floor(Points[j].y));
        }
    }

    Image1->Canvas->MoveTo(rect.Right,rect.Top);
    Image1->Canvas->LineTo(rect.Right,rect.Bottom);
    PanelBackground->Color = clSetupColor[2];
    LabelText->Font->Color = clSetupColor[1];
}
void __fastcall TFormSetupColor::FormActivate(TObject *Sender)
{
    DrawImage();
}
//---------------------------------------------------------------------------
void __fastcall TFormSetupColor::Panel1Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        Panel1->Color = ColorDialog1->Color;
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormSetupColor::Panel2Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        Panel2->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormSetupColor::Panel3Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        Panel3->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormSetupColor::Panel4Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    {
        Panel4->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormSetupColor::Button3Click(TObject *Sender)
{
    PanelCC00->Color = MAIN_CURVECOLOR[0];
    PanelCC01->Color = MAIN_CURVECOLOR[1];
    PanelCC02->Color = MAIN_CURVECOLOR[2];
    PanelCC03->Color = MAIN_CURVECOLOR[3];
    PanelCC04->Color = MAIN_CURVECOLOR[4];
    PanelCC05->Color = MAIN_CURVECOLOR[5];
    PanelCC06->Color = MAIN_CURVECOLOR[6];
    PanelCC07->Color = MAIN_CURVECOLOR[7];
    PanelCC08->Color = MAIN_CURVECOLOR[8];
    PanelCC09->Color = MAIN_CURVECOLOR[9];
    PanelCC10->Color = MAIN_CURVECOLOR[10];
    PanelCC11->Color = MAIN_CURVECOLOR[11];
    PanelCC12->Color = MAIN_CURVECOLOR[12];
    PanelCC13->Color = MAIN_CURVECOLOR[13];
    PanelCC14->Color = MAIN_CURVECOLOR[14];
    PanelCC15->Color = MAIN_CURVECOLOR[15];
}
//---------------------------------------------------------------------------

void __fastcall TFormSetupColor::PanelCC00Click(TObject *Sender)
{
    TColor clTemp;
    ColorDialog1->Color = ((TPanel*)Sender)->Color;
    if(ColorDialog1->Execute())
    {
//        LabelText->Color=
        ((TPanel*)Sender)->Color = ColorDialog1->Color;
        clTemp = clSetupColor[0];
        clSetupColor[0]        = ColorDialog1->Color;
        DrawImage();
        clSetupColor[0] = clTemp;
    }
}
//---------------------------------------------------------------------------

