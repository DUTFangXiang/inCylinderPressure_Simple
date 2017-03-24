//---------------------------------------------------------------------------

#ifndef USetupH
#define USetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSetup : public TForm
{
__published:	// IDE-managed Components
    TColorDialog *ColorDialog1;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TPanel *Panel4;
    TButton *Button1;
    TButton *Button2;
    void __fastcall Panel1Click(TObject *Sender);
    void __fastcall Panel2Click(TObject *Sender);
    void __fastcall Panel3Click(TObject *Sender);
    void __fastcall Panel4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormSetup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSetup *FormSetup;
//---------------------------------------------------------------------------
#endif
