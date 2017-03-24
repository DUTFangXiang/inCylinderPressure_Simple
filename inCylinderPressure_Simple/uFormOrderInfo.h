//---------------------------------------------------------------------------

#ifndef UFormOrderInfoH
#define UFormOrderInfoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TFormOrderInfo : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TSplitter *Splitter1;
    TStringGrid *SGOrder;
    TChart *ChartOrder;
    TBarSeries *Series1;
    TPanel *Panel2;
    TLabel *LabelParameter;
    TLabel *LabelOrder;
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormOrderInfo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOrderInfo *FormOrderInfo;
//---------------------------------------------------------------------------
#endif
