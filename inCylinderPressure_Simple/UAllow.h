//---------------------------------------------------------------------------

#ifndef UAllowH
#define UAllowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormRight : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TButton *Button1;
    TButton *Button2;
    TPanel *Panel2;
    TLabel *LabelInfomation;
    TLabel *LabelInform;
    TPanel *Panel3;
    TImage *ImageRed;
    TPanel *Panel4;
    TEdit *EditRight;
    TLabel *Label4;
    TLabel *LabelHint;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ImageRedDblClick(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall Panel1Click(TObject *Sender);
    void __fastcall Panel3Click(TObject *Sender);
    void __fastcall Panel2Click(TObject *Sender);
    void __fastcall Panel4Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
    int iColor1;
    int iColor2;
    int iSec;
    int iMis;
    AnsiString strNeed;
    bool bClicked;
    int iItems;
    int iKicked[4];
    int ii[4];    
public:		// User declarations
    bool bResult;
    __fastcall TFormRight(TComponent* Owner);      
    void __fastcall SetColor(int ic1,int ic2)
    {
        iColor1 = ic1;
        iColor2 = ic2;
    };
    bool __fastcall GetResult(void)
    {
        return bResult;
    };
    bool DetectCode(void);
    void __fastcall Confirm(void);
    void __fastcall HelpCode(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRight *FormRight;
//---------------------------------------------------------------------------
#endif
