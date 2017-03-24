//---------------------------------------------------------------------------

#ifndef UnitAddToBaseH
#define UnitAddToBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TFormPipeBase : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TChart *ChartPipe;
    TLineSeries *Series1;
    TGroupBox *GroupBox2;
    TButton *Button1;
    TButton *Button2;
    TBevel *Bevel1;
    TEdit *EditFaultType;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TPanel *PanelTrainType;
    TPanel *PanelTrainNumber;
    TPanel *PanelDieselSpeed;
    TPanel *PanelOilAngle;
    TPanel *PanelWavePeak;
    TPanel *PanelWavePeriod;
    TPanel *PanelWaveCoef;
    TLabel *Label8;
    TPanel *PanelDieselNumber;
    TLabel *LabelInfo;
    TTimer *Timer1;
    void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
    bool bConvert;
public:		// User declarations
    __fastcall TFormPipeBase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPipeBase *FormPipeBase;
//---------------------------------------------------------------------------
#endif
