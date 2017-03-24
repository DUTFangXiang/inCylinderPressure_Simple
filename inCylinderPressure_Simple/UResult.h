//---------------------------------------------------------------------------

#ifndef UResultH
#define UResultH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormResult : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TPanel *Panel8;
    TGroupBox *GroupBox2;
    TPanel *PanelCStartA;
    TPanel *PanelCEndA;
    TPanel *PanelCPeriod;
    TGroupBox *GroupBox3;
    TPanel *PanelSpeed;
    TPanel *PanelPMax;
    TPanel *PanelDPMax;
    TSplitter *Splitter1;
    TMemo *MemoResult;
    TLabel *LabelSpeed;
    TLabel *LabelPMax;
    TLabel *LabelDPMax;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TGroupBox *GroupBox4;
    TLabel *Label4;
    TPanel *PanelOilAngle;
    TGroupBox *GroupBox5;
    TLabel *Label3;
    TLabel *Label2;
    TPanel *PanelPVPower;
    TPanel *PanelComPower;
    TGroupBox *GroupBox6;
    TLabel *Label8;
    TPanel *PanelHRMax;
    TLabel *Label9;
    TPanel *PanelHRMAngle;
    TLabel *Label10;
    TPanel *PanelPMaxPosi;
    TPanel *PanelDPMaxPosi;
    TLabel *Label11;
    TPanel *PanelPipeLast;
    TLabel *Label1;
    TPanel *PanelDelayAngle;
    TLabel *Label12;
    TPanel *PanelWaveCoef;
private:	// User declarations
public:		// User declarations
    __fastcall TFormResult(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormResult *FormResult;
//---------------------------------------------------------------------------
#endif
