//---------------------------------------------------------------------------

#ifndef lFormBackupH
#define lFormBackupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormBackup : public TForm
{
__published:	// IDE-managed Components
    TRadioGroup *RadioGroupBackMode;
    TButton *Button1;
    TButton *Button2;
    TComboBox *ComboBoxTrainNum;
        TDateTimePicker *DTPDate;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
    bool bClose;
public:		// User declarations
    __fastcall TFormBackup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBackup *FormBackup;
//---------------------------------------------------------------------------
#endif
