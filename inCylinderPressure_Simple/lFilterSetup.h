//---------------------------------------------------------------------------

#ifndef lFilterSetupH
#define lFilterSetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormFilterSetup : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TGroupBox *GroupBox1;
	TComboBox *ComboBoxWindowChoice;
	TGroupBox *GroupBox2;
	TComboBox *ComboBoxFilterKind;
	TRadioGroup *RadioGroupMethod;
	TGroupBox *GroupBox3;
	TLabel *Label1;
	TEdit *EditFPL;
	TLabel *Label2;
	TEdit *EditFSL;
	TLabel *Label3;
	TEdit *EditFPH;
	TLabel *Label4;
	TEdit *EditFSH;
	TCheckBox *CheckBoxSelf;
	TLabel *Label5;
	TEdit *EditFilterOrder;
	TBevel *Bevel1;
	TLabel *Label6;
	TButton *Button3;
	TGroupBox *GroupBox4;
	TMemo *MemoResult;
	TButton *ButtonCalculation;
    TEdit *EditMaxFrequency;
	void __fastcall EditFPLExit(TObject *Sender);
	void __fastcall EditFSLExit(TObject *Sender);
	void __fastcall EditFPHExit(TObject *Sender);
	void __fastcall EditFSHExit(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ComboBoxFilterKindChange(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall CheckBoxSelfClick(TObject *Sender);
	void __fastcall RadioGroupMethodClick(TObject *Sender);
	void __fastcall ButtonCalculationClick(TObject *Sender);
private:	// User declarations
	int iFilterLen;
	float fFilter[100];
public:		// User declarations
	float fmax;
	__fastcall TFormFilterSetup(TComponent* Owner);
	void __fastcall Verification(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormFilterSetup *FormFilterSetup;
//---------------------------------------------------------------------------
#endif
