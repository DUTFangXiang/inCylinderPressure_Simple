//---------------------------------------------------------------------------

#ifndef UnitOptionH
#define UnitOptionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "FileDieselHead.h"
class TFormOption : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TPanel *Panel1;
    TTabSheet *TabSheet1;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TGroupBox *GroupBox1;
    TEdit *EditUserName;
    TTabSheet *TabSheet2;
    TCheckBox *CheckBoxbSaveOrig;
    TTabSheet *TabSheet3;
    TComboBox *ComboBoxTrainType;
    TGroupBox *GroupBox2;
    TLabel *Label1;
    TEdit *EditDiameter;
    TLabel *Label2;
    TEdit *EditStroke;
    TLabel *Label3;
    TEdit *EditPodLength;
    TLabel *Label4;
    TEdit *EditCRation;
    TLabel *Label5;
    TEdit *EditInCloseAngle;
    TLabel *Label6;
    TEdit *EditOutOpenAngle;
    TLabel *Label7;
    TEdit *EditFuelSupplyAngle;
    TTabSheet *TabSheet4;
    TComboBox *ComboBoxTrainTypeStandard;
    TGroupBox *GroupBox3;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TEdit *EditCompressMin;
    TEdit *EditOilAngleMin;
    TEdit *EditCombustionAngleMin;
    TEdit *EditCompressMax;
    TEdit *EditOilAngleMax;
    TEdit *EditCombustionAngleMax;
    TLabel *Label11;
    TLabel *Label12;
    TTabSheet *TabSheet5;
    TLabel *Label22;
    TEdit *EditOtherA;
    TLabel *Label26;
    TEdit *EditOtherB;
    TLabel *Label30;
    TButton *ButtonRefreshTrainType;
    TCheckBox *CheckBoxExcel;
    TRadioGroup *RadioGroupAnalysisMethod;
    TGroupBox *GroupBox4;
    TEdit *EditDetectLevel;
    TLabel *Label13;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall ComboBoxTrainTypeChange(TObject *Sender);
    void __fastcall ComboBoxTrainTypeStandardChange(TObject *Sender);
    void __fastcall EditDiameterChange(TObject *Sender);
    void __fastcall EditCompressMinChange(TObject *Sender);
    void __fastcall EditOtherAChange(TObject *Sender);
    void __fastcall ButtonRefreshTrainTypeClick(TObject *Sender);
    void __fastcall EditOtherBChange(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall EditDetectLevelChange(TObject *Sender);
private:	// User declarations
    int              iSTrainType;
    int              iSDetectInfo;
    bool             bSTrainType;         //机车车型是否发生变化
    bool             bDetectInfo;         //判断参数发生了变化
    bool             bTrainRename;        //机型发生了变化

    StructDieselInfo myDieselInfo[11];    //用于保存机车参数信息
    AnsiString       strArrayTrainType[6];
public:		// User declarations
    void __fastcall SetDieselInfo(StructDieselInfo* dt, int inum);
    void __fastcall GetDieselInfo(StructDieselInfo* dt, int inum);
    void __fastcall SetDieselName(AnsiString* st, int inum);
    void __fastcall GetDieselName(AnsiString* st, int inum);
        __fastcall TFormOption(TComponent* Owner);
    void __fastcall RefreshControl(int itraintype, bool bshow);
    void __fastcall RefreshDetectInfo(int iTrainType, bool bCombox);
    void __fastcall FlushDetectInfo(void);   //从控件获取判断参数
    void __fastcall FlushDieselInfo(void);   //从控件获取柴油机参数


};
//---------------------------------------------------------------------------
extern PACKAGE TFormOption *FormOption;
//---------------------------------------------------------------------------
#endif
