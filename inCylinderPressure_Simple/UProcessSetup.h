//---------------------------------------------------------------------------

#ifndef UProcessSetupH
#define UProcessSetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormProcessSetup : public TForm
{
__published:	// IDE-managed Components
    TRadioGroup *RadioGroup1;
private:	// User declarations
public:		// User declarations
    __fastcall TFormProcessSetup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProcessSetup *FormProcessSetup;
//---------------------------------------------------------------------------
#endif
