//---------------------------------------------------------------------------

#ifndef UDataDeleteH
#define UDataDeleteH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDeleteData : public TForm
{
__published:	// IDE-managed Components
    TRadioGroup *RadioGroupDeleteMode;
    TDateTimePicker *DateTimePicker1;
    TButton *Button1;
    TButton *Button2;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall DateTimePicker1Change(TObject *Sender);
private:	// User declarations
    TDate dtDelete;
public:		// User declarations
     __fastcall TFormDeleteData(TComponent* Owner);
    void __fastcall GetDeleteDate(TDate& dt)
    {
        dt = dtDelete;
    };

};
//---------------------------------------------------------------------------
extern PACKAGE TFormDeleteData *FormDeleteData;
//---------------------------------------------------------------------------
#endif
