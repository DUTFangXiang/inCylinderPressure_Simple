//---------------------------------------------------------------------------

#ifndef lFormReportH
#define lFormReportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <Qrctrls.hpp>
//---------------------------------------------------------------------------
class TFormReportOut : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRBand *PageHeaderBand1;
    TQRBand *ColumnHeaderBand1;
    TQRBand *DetailBand1;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel7;
    TQRLabel *QRLabel8;
    TQRLabel *QRLabel10;
    TQRLabel *QRLabel11;
    TQRDBText *QRDBText1;
    TQRDBText *QRDBText3;
    TQRDBText *QRDBText5;
    TQRDBText *QRDBText8;
    TQRDBText *QRDBText12;
    TQRDBText *QRDBText4;
    TQRLabel *QRLabel3;
    TQRDBText *QRDBText2;
    TQRLabel *QRLabel5;
    TQRDBText *QRDBText7;
    TQRLabel *QRLabel6;
    TQRDBText *QRDBText9;
    TQRLabel *QRLabel12;
    TQRDBText *QRDBText10;
    TQRLabel *QRLabel13;
    TQRDBText *QRDBText11;
    TQRLabel *QRLabel14;
    TQRLabel *QRLabel15;
    TQRLabel *QRLabel16;
    TQRDBText *QRDBText13;
    TQRDBText *QRDBText14;
    TQRLabel *QRLabel17;
    TQRLabel *QRLabel18;
    TQRLabel *QRLabel19;
    TQRDBText *QRDBText15;
    TQRDBText *QRDBText16;
    TQRDBText *QRDBText17;
    TQRLabel *QRLabel20;
    TQRDBText *QRDBText18;
    TQRLabel *QRLabel4;
    TQRDBText *QRDBText6;
    TQRChildBand *QRChildBand1;
private:	// User declarations
public:		// User declarations
    __fastcall TFormReportOut(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReportOut *FormReportOut;
//---------------------------------------------------------------------------
#endif
