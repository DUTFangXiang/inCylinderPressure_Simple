//---------------------------------------------------------------------------

#ifndef UAnalysisResultH
#define UAnalysisResultH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormAnalysisResult : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox2;
    TSplitter *Splitter1;
    TMemo *MemoResult;
    TPanel *Panel1;
    TPanel *Panel2;
    TGroupBox *GroupBox1;
    TStringGrid *StringGridParams;
    TLabel *Label1;
    TPanel *PanelTrainType;
    TLabel *Label2;
    TPanel *PanelTrainNumber;
    TLabel *Label3;
    TPanel *PanelMTime;
    TLabel *Label4;
    TPanel *PanelSpeed;
    TLabel *Label5;
    TPanel *PanelPower;
private:	// User declarations
public:		// User declarations
    __fastcall TFormAnalysisResult(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAnalysisResult *FormAnalysisResult;
//---------------------------------------------------------------------------
#endif
