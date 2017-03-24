//---------------------------------------------------------------------------

#ifndef lPathH
#define lPathH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormPath : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *EditFilePath;
    TButton *Button1;
    TButton *Button2;
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall EditFilePathExit(TObject *Sender);
    void __fastcall EditFilePathEnter(TObject *Sender);
private:	// User declarations
    AnsiString strBackup;
public:		// User declarations
    __fastcall TFormPath(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPath *FormPath;
//---------------------------------------------------------------------------
#endif
