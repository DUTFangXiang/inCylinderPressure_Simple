//---------------------------------------------------------------------------

#ifndef UnitEnlargeH
#define UnitEnlargeH
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
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormEnlargeView : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TBitBtn *BitBtn1;
    TPanel *Panel2;
    TSplitter *Splitter1;
    TChart *ChartEnlarge;
    TLineSeries *Series1;
    TLineSeries *Series2;
    TLineSeries *Series3;
    TLineSeries *Series4;
    TLineSeries *Series5;
    TLineSeries *Series6;
    TLineSeries *Series7;
    TLineSeries *Series8;
    TLineSeries *Series9;
    TLineSeries *Series10;
    TLineSeries *Series11;
    TLineSeries *Series12;
    TLineSeries *Series13;
    TLineSeries *Series14;
    TLineSeries *Series15;
    TLineSeries *Series16;
    void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormEnlargeView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEnlargeView *FormEnlargeView;
//---------------------------------------------------------------------------
#endif
