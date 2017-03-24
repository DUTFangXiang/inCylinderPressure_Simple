//---------------------------------------------------------------------------

#ifndef USetupColorH
#define USetupColorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------

#define M_PII       3.1415926
#define MaxPoints   20

class TFormSetupColor : public TForm
{
__published:	// IDE-managed Components
    TPanel *PanelBackground;
    TLabel *LabelText;
    TImage *Image1;
    TButton *Button1;
    TButton *Button2;
    TColorDialog *ColorDialog1;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TPanel *Panel4;
    TButton *Button3;
    TGroupBox *GroupBox2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TPanel *PanelCC00;
    TPanel *PanelCC01;
    TPanel *PanelCC02;
    TPanel *PanelCC03;
    TPanel *PanelCC04;
    TPanel *PanelCC05;
    TPanel *PanelCC06;
    TPanel *PanelCC07;
    TPanel *PanelCC08;
    TPanel *PanelCC09;
    TPanel *PanelCC10;
    TPanel *PanelCC11;
    TPanel *PanelCC12;
    TPanel *PanelCC13;
    TPanel *PanelCC14;
    TPanel *PanelCC15;
    void __fastcall LabelTextClick(TObject *Sender);
    void __fastcall PanelBackgroundClick(TObject *Sender);
    void __fastcall Image1Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall Panel1Click(TObject *Sender);
    void __fastcall Panel2Click(TObject *Sender);
    void __fastcall Panel3Click(TObject *Sender);
    void __fastcall Panel4Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall PanelCC00Click(TObject *Sender);
	// User declarations

private:
public:		// User declarations
    TColor clSetupColor[3]; // [0] is for Image;  [1] is for text  [2] is for background
    TPoint Points[MaxPoints];
    __fastcall TFormSetupColor(TComponent* Owner);
    void __fastcall DrawImage(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSetupColor *FormSetupColor;
//---------------------------------------------------------------------------
#endif
