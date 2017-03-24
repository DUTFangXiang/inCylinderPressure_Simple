//---------------------------------------------------------------------------

#ifndef lFormStartFaceH
#define lFormStartFaceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormStartFace : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
 
    TTimer *Timer1;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Image1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
     int iStep;
public:		// User declarations
    __fastcall TFormStartFace(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormStartFace *FormStartFace;
//---------------------------------------------------------------------------
#endif
