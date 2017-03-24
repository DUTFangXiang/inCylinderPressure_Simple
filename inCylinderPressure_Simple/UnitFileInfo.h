//---------------------------------------------------------------------------

#ifndef UnitFileInfoH
#define UnitFileInfoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormFileInfo : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TGroupBox *GroupBox2;
    TGroupBox *GroupBox3;
    TGroupBox *GroupBox4;
    TLabel *Label1;
    TPanel *PanelTrainType;
    TLabel *Label2;
    TPanel *PanelTrainNum;
    TLabel *Label3;
    TPanel *PanelDieselNum;
    TPanel *PanelFileName;
    TLabel *Label4;
    TPanel *PanelSampleFre;
    TLabel *Label5;
    TPanel *PanelSampleNum;
    TLabel *LabelSampleLen;
    TPanel *PanelSampleLen;
    TLabel *Label7;
    TPanel *PanelfCPMax;
    TLabel *Label8;
    TPanel *PanelfCPMin;
    TLabel *Label9;
    TPanel *PanelSensitivity;
    TLabel *Label10;
    TPanel *PanelGain;
    TLabel *Label6;
    TPanel *PanelfEn;
    TLabel *Label11;
    TPanel *PanelPercentage;
        TLabel *Label12;
        TPanel *PanelCutoffFreq;
    TLabel *Label13;
    TPanel *PanelCutoffFreq1;
private:	// User declarations
public:		// User declarations
    __fastcall TFormFileInfo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFileInfo *FormFileInfo;
//---------------------------------------------------------------------------
#endif
