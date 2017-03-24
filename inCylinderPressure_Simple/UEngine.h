//---------------------------------------------------------------------------

#ifndef UEngineH
#define UEngineH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormEngine : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *EditDieselSpeed;
    TLabel *Label2;
    TEdit *EditTrainType;
    TLabel *Label3;
    TEdit *EditTrainNumber;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *EditPower;
    TEdit *EditOilConsume;
private:	// User declarations
public:		// User declarations
    __fastcall TFormEngine(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEngine *FormEngine;
//---------------------------------------------------------------------------
#endif
