//---------------------------------------------------------------------------

#ifndef UGoBackH
#define UGoBackH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormGoBack : public TForm
{
__published:	// IDE-managed Components
    TBitBtn *BitBtn1;
    void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
protected:
    BEGIN_MESSAGE_MAP
        MESSAGE_HANDLER(WM_LBUTTONDOWN,TMessage,WMLBUTTONDOWN)
    END_MESSAGE_MAP(TForm)
public:		// User declarations
    void __fastcall CreateParams(TCreateParams &Params);
    __fastcall TFormGoBack(TComponent* Owner);
    void __fastcall WMLBUTTONDOWN(TMessage &Msg);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormGoBack *FormGoBack;
//---------------------------------------------------------------------------
#endif
