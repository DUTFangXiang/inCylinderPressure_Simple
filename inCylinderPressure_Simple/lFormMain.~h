//---------------------------------------------------------------------------

#ifndef lFormMainH
#define lFormMainH
//---------------------------------------------------------------------------
/*
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <FileCtrl.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include <ActnList.hpp>
#include <Grids.hpp>
*/
#include <StdActns.hpp>
#include <syncobjs.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
#include <Chart.hpp>
#include <DBChart.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Dialogs.hpp>
#include <Series.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
#include <Graphics.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <Mask.hpp>
#include <ExtDlgs.hpp>

#include <FileCtrl.hpp>
#include <winbase.h>
#include <mem.h>
#include <Series.hpp>

#include <ActnList.hpp>

//---------------------------------------------------------------------------
#include "lFileHead.h"
#include "LPPFDRead.h"
#include "DataProcess.h"
#include "lrwenum.h"
#include "MaxInfo.h"
#include "FileDieselHead.h"
#include <OleCtrls.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBChart.hpp>
#include <ExtDlgs.hpp>
#include <DbChart.hpp>

#define iPASSNUM          3   //表示此仪器共有三个通道
#define MAXTRAININFONUMS  40
/*
typedef struct _browseinfo {
    HWND hwndOwner;
    LPCITEMIDLIST pidlRoot;
    LPSTR pszDisplayName;
    LPCSTR lpszTitle;
    UINT ulFlags;
    BFFCALLBACK lpfn;
    LPARAM lParam;
    int iImage;
} BROWSEINFO, *PBROWSEINFO, *LPBROWSEINFO;
*/

struct sctMTrainInfo
{
    bool bSelected;      //表示此车是否已被选择
    int  iStartPosi;     //仪器数据开始的位置
    int  iEndPosi;       //仪器数据结束的位置
    AnsiString strTrainInfo;   //机车信息，如车型车号测量时间等
};

class TFormMain : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *mnuFile;
    TStatusBar *StatusBarMain;
    TMenuItem *mnuFileExit;
    TPopupMenu *PopupMenuProcess;
    TMenuItem *ppmPFai;
    TMenuItem *ppmPRate;
    TMenuItem *ppmFrequency;
    TMenuItem *ppmBFilter;
    TMenuItem *ppmDZFilter;
    TMenuItem *ppmBackupFilter;
    TMenuItem *ppmTranslatorFunction;
    TMenuItem *ppmHeatRelease;
    TPopupMenu *PopupMenuResult;
    TMenuItem *ppmResultDPDC;
    TMenuItem *ppmResultTemperature;
    TMenuItem *ppmReusltHeatRelease;
    TMenuItem *ppmResultTotalHeatRelease;
    TMenuItem *N2;
    TMenuItem *ppmResultResult;
    TImageList *ImageList1;
    TImageList *ImageList2;
    TOpenDialog *OpenDialog1;
    TMenuItem *mnuOperation;
    TMenuItem *mnuProcess;
    TMenuItem *mnuHelp;
    TMenuItem *mnuOperationSetup;
    TMenuItem *mnuOperationScanDisk;
    TActionList *ActionListOperation;
    TAction *ActionOperationScanDisk;
    TAction *ActionOperationSetup;
    TAction *ActionProcessHeadRelease;
    TAction *ActionOperationReadData;
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TMenuItem *N11;
    TMenuItem *N17;
    TMenuItem *mnuPrePro;
    TMenuItem *mnuPreProAntiFilterSetup;
    TMenuItem *N18;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N7;
    TMenuItem *mnuFileSetupPath;
    TMenuItem *mnuFilePrint;
    TMenuItem *N22;
    TMenuItem *N23;
    TMenuItem *N24;
    TMenuItem *N25;
    TMenuItem *N26;
    TMenuItem *N27;
    TMenuItem *N28;
    TMenuItem *mnuHelpAbout;
    TMenuItem *mnuHelpInstrument;
    TMenuItem *N13;
    TMenuItem *mnuHelpSoftware;
    TMenuItem *N15;
    TMenuItem *N16;
    TPopupMenu *PopupMenu1;
    TMenuItem *ppmEditPST;
    TPopupMenu *PopupMenuAdjust;
    TMenuItem *ppmAdjustPT;
    TMenuItem *ppmAdjustPV;
    TMenuItem *ppmAdjustFFTP;
    TMenuItem *ppmAdjustLogPV;
    TMenuItem *ppmAdjustCPT;
    TMenuItem *ppmAdjustDPDF;
    TMenuItem *ppmAdjustHRR;
    TMenuItem *ppmAdjustCHRR;
    TMenuItem *ppmAdjustTemperature;
    TPopupMenu *PopupMenu2;
    TMenuItem *ppmOriginalDrawMode;
    TPopupMenu *PopupMenuAbstract;
    TMenuItem *ppmAbstractMerge;
    TMenuItem *ppmSaveAbstractData;
    TMenuItem *ppmSaveOriginalData;
    TPanel *Panel10;
    TPageControl *PageControlMain;
    TTabSheet *TabSheetParameter;
    TGroupBox *GroupBox1;
    TGroupBox *GroupBox12;
    TLabel *Label1;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label9;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label28;
    TLabel *LabelfTAU;
    TLabel *Label38;
    TEdit *EditDiameter;
    TEdit *EditSLength;
    TEdit *EditPodLength;
    TEdit *EditCRatio;
    TEdit *EditInOpenAngle;
    TEdit *EditInCloseAngle;
    TEdit *EditOutOpenAngle;
    TEdit *EditOutCloseAngle;
    TEdit *EditfFI;
    TEdit *EditfTAU;
    TEdit *EditfX0;
    TGroupBox *GroupBox13;
    TLabel *Label29;
    TLabel *Label30;
    TLabel *Label31;
    TEdit *EditfHU;
    TEdit *EditfNC;
    TEdit *EditfMH;
    TGroupBox *GroupBox14;
    TLabel *Label8;
    TLabel *Label18;
    TLabel *Label19;
    TLabel *Label20;
    TLabel *Label25;
    TLabel *Label26;
    TEdit *EditTWater;
    TEdit *EditTTop;
    TEdit *EditTWall;
    TEdit *EditTBottom;
    TEdit *EditHRConst;
    TEdit *EditLCoef;
    TGroupBox *GroupBox15;
    TLabel *Label22;
    TLabel *Label2;
    TEdit *EditSpeed;
    TEdit *Edit1;
    TGroupBox *GroupBox16;
    TLabel *Label21;
    TEdit *EditSampleRate;
    TGroupBox *GroupBox17;
    TLabel *Label33;
    TLabel *Label32;
    TLabel *Label27;
    TEdit *EditfTF;
    TEdit *EditfGF;
    TEdit *EditfCAING;
    TGroupBox *GroupBox2;
    TLabel *Label35;
    TLabel *Label37;
    TEdit *EditfALPHA;
    TEdit *EditfGAMA;
    TGroupBox *GroupBox18;
    TLabel *Label23;
    TEdit *EditDFai;
    TGroupBox *GroupBox19;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label34;
    TLabel *Label36;
    TLabel *Label17;
    TLabel *Label24;
    TLabel *Label39;
    TEdit *EditTAir;
    TEdit *EditPAir;
    TEdit *EditfLO;
    TEdit *EditfRMOL;
    TEdit *EditMIndex;
    TEdit *EditKCoef;
    TEdit *EditLowPressure;
    TTabSheet *TabSheetDataBrowse;
    TSplitter *Splitter2;
    TTabSheet *TabSheetDataRecieve;
    TPanel *Panel3;
    TGroupBox *GroupBox5;
    TPanel *Panel4;
    TGroupBox *GroupBox21;
    TBitBtn *BitBtnReadList;
    TBitBtn *BitBtnReadAll;
    TBitBtn *BitBtnReadCurrent;
    TBitBtn *BitBtnCloseUSB;
    TGroupBox *GroupBox22;
    TLabel *Label40;
    TBitBtn *BitBtnSavePosition;
    TEdit *EditPathName;
    TTabSheet *TabSheetOpenFile;
    TSplitter *Splitter3;
    TToolBar *ToolBar2;
    TComboBox *ComboBox1;
    TBitBtn *BitBtn1;
    TToolButton *ToolButton4;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TComboBox *ComboBoxIndex;
    TDriveComboBox *Drive1;
    TListView *ListView1;
    TGroupBox *GroupBox8;
    TListBox *ListBoxPST;
    TImageList *ImageListMainToolbar;
    TAction *ActionOperationAbstractData;
    TAction *ActionOperationAdjustTDC;
    TAction *ActionFileReadPCPFile;
    TAction *ActionFileReadPSTFile;
    TAction *ActionFilePrint;
    TAction *ActionFileReadOriginalFile;
    TMenuItem *N20;
    TMenuItem *N29;
    TPopupMenu *PopupMenuAllDraw;
    TMenuItem *ppmConGrid;
    TPanel *Panel11;
    TPanel *Panel12;
    TSplitter *Splitter8;
    TDriveComboBox *DriveComboBox2;
    TFilterComboBox *FilterComboBox1;
    TDirectoryListBox *DirectoryListBox2;
    TFileListBox *FileListBox2;
    TMenuItem *mnuFileOpenOriginal;
    TPopupMenu *PopupMenuMain;
    TMenuItem *ppMainMenu;
    TMenuItem *ppMainToolbar;
    TMenuItem *mnuOther;
    TMenuItem *mnuOtherHideToolbar;
    TMenuItem *N1;
    TButton *Button1;
    TMenuItem *ppmOriginalNegtive;
    TColorDialog *ColorDialog1;
    TSaveDialog *SaveDialog1;
    TMenuItem *ppmAnalysisAccelerate;
    TMenuItem *N5;
    TMenuItem *N12;
    TMenuItem *ppmPP1;
    TMenuItem *ppmPP2;
    TMenuItem *ppmPP5;
    TTabSheet *TabSheetCurveShow;
    TPageControl *PageControlCurve;
    TSplitter *Splitter9;
    TTabSheet *TabSheetPCP;
    TTabSheet *TabSheetORG;
    TPanel *Panel1;
    TGroupBox *GroupBox7;
    TLabel *LabelCurveShift;
    TLabel *Label45;
    TEdit *EditShift;
    TToolBar *ToolBar3;
    TToolButton *ToolButton39;
    TToolButton *ToolButton40;
    TToolButton *ToolButton41;
    TGroupBox *GroupBox9;
    TCheckBox *CheckBoxAdjustPT;
    TCheckBox *CheckBoxAdjustCPT;
    TCheckBox *CheckBoxAdjustPV;
    TCheckBox *CheckBoxAdjustDPDF;
    TCheckBox *CheckBoxAdjustFFTP;
    TCheckBox *CheckBoxAdjustLogVLogP;
    TCheckBox *CheckBoxAdjustHRR;
    TCheckBox *CheckBoxAdjustCHRR;
    TRadioGroup *RadioGroupDrawMode;
    TBitBtn *BitBtnOneAll;
    TGroupBox *GroupBox6;
    TPanel *PanelSingle;
    TPaintBox *PaintBoxAdjustTDC;
    TScrollBar *ScrollBarAdjust;
    TSplitter *Splitter10;
    TPanel *Panel6;
    TPanel *PanelEngineSpeed;
    TLabel *Label41;
    TLabel *Label42;
    TLabel *Label43;
    TEdit *EditEngineSpeed;
    TEdit *EditOilAngle;
    TEdit *EditCombustionAngle;
    TSplitter *Splitter11;
    TPanel *Panel5;
    TSplitter *Splitter1;
    TGroupBox *GroupBox10;
    TPanel *PanelOriginalBack;
    TPaintBox *PaintBoxOriginal;
    TScrollBar *ScrollBarOriginal;
    TGroupBox *GroupBox11;
    TPanel *PanelSumBack;
    TPaintBox *PaintBoxAbstract;
    TScrollBar *ScrollBarAbstract;
    TTabSheet *TabSheetPST;
    TToolBar *ToolBar1;
    TToolButton *ToolButtonOriginalData;
    TToolButton *ToolButtonModifiedData;
    TToolButton *ToolButtonPV;
    TToolButton *ToolButtonLogPLogV;
    TToolButton *ToolButtonDPDF;
    TToolButton *ToolButtonHRR;
    TToolButton *ToolButtonCHRR;
    TToolButton *ToolButtonDomain;
    TToolButton *ToolButtonPower;
    TToolButton *ToolButtonCPower;
    TToolButton *ToolButtonMMax;
    TPanel *PanelAll;
    TMenuItem *N14;
    TMenuItem *mnuSetupColor;
    TMenuItem *ppmSetupColor;
    TMenuItem *ppmSetupLineWidth;
    TMenuItem *ppmDPI1;
    TMenuItem *ppnDPI2;
    TMenuItem *ppmDPI5;
    TMenuItem *ppmSaveasTextFile;
    TPopupMenu *PopupMenuCalResult;
    TMenuItem *ppmShowResult;
    TMenuItem *ppmPopupResult;
    TToolButton *ToolButtonOilP;
    TMenuItem *ppmDeleteLine;
    TMenuItem *ppmSetCursorColor;
    TPageControl *PageControlBrowse;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TGroupBox *GroupBox20;
    TPanel *Panel7;
    TDriveComboBox *DriveComboBox1;
    TFilterComboBox *FilterComboBoxFile;
    TPanel *Panel8;
    TSplitter *Splitter7;
    TDirectoryListBox *DirectoryListBoxFile;
    TPanel *Panel2;
    TSplitter *Splitter5;
    TGroupBox *GroupBox3;
    TListBox *ListBoxPSTFile;
    TGroupBox *GroupBox4;
    TListBox *ListBoxPCPFile;
    TPopupMenu *PopupMenu3;
    TMenuItem *ppmClearAllList;
    TMenuItem *ppmClearCurrentList;
    TMenuItem *ppmGrid;
    TPopupMenu *PopupMenuOrg;
    TMenuItem *ppmChangeParameters;
    TRadioGroup *RadioGroupSingleCurve;
    TCheckBox *CheckBoxFirst;
    TCheckBox *CheckBoxSecond;
    TCheckBox *CheckBoxHideThree;
    TButton *Button2;
    TMenuItem *ppmFormPCP;
    TImage *ImageAll;
    TPopupMenu *PopupMenu5;
    TMenuItem *ppmShowCut;
    TMenuItem *ppmEnlargement;
    TMenuItem *ppmRestore;
    TMenuItem *ppmEnlarge4;
    TMenuItem *ppmEnlargement8;
    TMenuItem *ppmSetColor;
    TCheckBox *CheckBoxValue;
    TGroupBox *GroupBoxCalibration;
    TLabel *LabelValue;
    TLabel *Label49;
    TEdit *EditReadEnlarge;
    TLabel *Label48;
    TEdit *EditEnlarge;
    TLabel *Label47;
    TEdit *EditVoltage;
    TLabel *Label46;
    TEdit *EditCapicator;
    TLabel *Label50;
    TLabel *LabelRealValue;
    TPanel *Panel9;
    TChart *Chart1;
    TLineSeries *Series1;
    TLineSeries *Series3;
    TLineSeries *Series5;
    TLineSeries *Series8;
    TLineSeries *Series9;
    TLineSeries *Series10;
    TLineSeries *Series11;
    TLineSeries *Series12;
    TSplitter *Splitter4;
    TMemo *MemoMaxValue;
    TPanel *Panel13;
    TChart *Chart2;
    TLineSeries *Series2;
    TLineSeries *Series4;
    TLineSeries *Series6;
    TLineSeries *Series7;
    TLineSeries *Series13;
    TLineSeries *Series14;
    TLineSeries *Series15;
    TLineSeries *Series16;
    TMemo *MemoDPMaxValue;
    TSplitter *Splitter6;
    TMenuItem *ppmSinglePCP;
    TLabel *LabelDetect;
    TTabSheet *TabSheetDatabase;
    TMenuItem *mnuOperationDatabase;
    TMenuItem *mnuDatabase;
    TMenuItem *mnuDatabaseView;
    TMenuItem *mnuDatabaseOutput;
    TSplitter *Splitter17;
    TPopupMenu *PopupMenu6;
    TMenuItem *ppmTVColor;
    TMenuItem *ppmTVFont;
    TImageList *ImageListTrain;
    TSplitter *SplitterTV;
    TPanel *Panel19;
    TSplitter *Splitter12;
    TPanel *Panel15;
    TSplitter *Splitter14;
    TGroupBox *GroupBox26;
    TMemo *MemoResult;
    TGroupBox *GroupBox27;
    TSplitter *Splitter15;
    TChart *ChartCurve;
    TLineSeries *Series18;
    TLineSeries *Series19;
    TLineSeries *Series20;
    TPopupMenu *PopupMenu7;
    TMenuItem *Color1;
    TMenuItem *N19;
    TMenuItem *N31;
    TMenuItem *N32;
    TMenuItem *N33;
    TMenuItem *ppmDataDelete;
    TMenuItem *ppmTVReload;
    TMenuItem *N34;
    TDBChart *DBChart1;
    TBarSeries *Series17;
    TMenuItem *ppmBrowseInsertToDatabase;
    TLineSeries *Series21;
    TLineSeries *Series22;
    TLineSeries *Series23;
    TLineSeries *Series24;
    TLineSeries *Series25;
    TLineSeries *Series26;
    TLineSeries *Series27;
    TLineSeries *Series28;
    TLineSeries *Series29;
    TLineSeries *Series30;
    TLineSeries *Series31;
    TLineSeries *Series32;
    TLineSeries *Series33;
    TLabel *Label52;
    TEdit *EditCPMax;
    TLabel *Label53;
    TEdit *EditDPDFMax;
    TLabel *Label44;
    TEdit *EditTrainType;
    TLabel *Label54;
    TEdit *EditTrainNumber;
    TLabel *Label55;
    TEdit *EditDieselNumber;
    TEdit *EditPipeLast;
    TLabel *Label56;
    TMenuItem *ppmOutOrder;
    TLabel *LabelOil;
    TLabel *LabelDPDF;
    TLabel *Label51;
    TEdit *EditCombustionPeriod;
    TPopupMenu *PopupMenuPrint;
    TMenuItem *ppmMemoPrint;
    TMenuItem *N6;
    TMenuItem *N35;
    TMenuItem *mnuTrace;
    TMenuItem *mnuTraceTwo;
    TMenuItem *mnuTraceThree;
    TMenuItem *mnuTraceFour;
    TMenuItem *mnuTraceMerge;
    TMenuItem *N41;
    TMenuItem *mnuTraceNum02;
    TMenuItem *mnuTraceNum04;
    TMenuItem *mnuTraceNum08;
    TMenuItem *mnuTraceNum16;
    TMenuItem *mnuTraceFive;
    TMenuItem *N36;
    TMenuItem *mnuTraceSeven;
    TMenuItem *mnuTraceEight;
    TMenuItem *N37;
    TAction *ActionTraceTwo;
    TAction *ActionTraceThree;
    TAction *ActionTraceFour;
    TAction *ActionTraceFive;
    TAction *ActionTraceSix;
    TAction *ActionTraceSeven;
    TAction *ActionTraceEight;
    TAction *ActionTraceNumTwo;
    TAction *ActionTraceNumFour;
    TAction *ActionTraceNumEight;
    TAction *ActionTraceNumSixteen;
    TAction *ActionTraceMerge;
    TMenuItem *ppmEnlarge;
    TMenuItem *ppmEnlargeTwo;
    TMenuItem *ppmEnlargeFour;
    TMenuItem *ppmEnlargeEight;
    TMenuItem *ppmEnlargeNormal;
    TMenuItem *N40;
    TAction *ActionEnlargeTwo;
    TAction *ActionEnlargeFour;
    TAction *ActionEnlargeEight;
    TAction *ActionEnlargeNormal;
    TLabel *Label57;
    TEdit *EditWaveCoef;
        TToolButton *ToolButtonBasicInfo;
        TMenuItem *mnuOtherOption;
        TMenuItem *N42;
    TMenuItem *ppmSetupFont;
    TMenuItem *N44;
    TFontDialog *FontDialog1;
    TGroupBox *GroupBox28;
    TCheckBox *CheckBoxComputerTime;
    TCheckBox *CheckBoxAddToDatabase;
    TMenuItem *N43;
    TMenuItem *ppmShowOriginalAll;
    TTimer *Timer1;
    TPopupMenu *PopupMenuLoadPic;
    TMenuItem *ppmLoadPic;
    TMenuItem *ppmDeletePic;
    TMenuItem *ppmStrechPic;
    TOpenPictureDialog *OpenPictureDialog1;
        TPageControl *PageControl3;
        TTabSheet *TabSheet6;
        TTabSheet *TabSheet7;
        TStringGrid *SGDirectory;
        TStringGrid *SGParams;
    TGroupBox *GroupBox30;
    TListBox *ListBoxTrainList;
    TButton *ButtonInfo;
    TMenuItem *N46;
    TTabSheet *TabSheetOilAngle;
    TStringGrid *StringGridOilAngle;
    TCheckBox *CheckBoxbSaveOrig;
    TTabSheet *TabSheetPipe;
    TPanel *PanelPipeBack;
    TSplitter *Splitter19;
    TPanel *Panel20;
    TGroupBox *GroupBox31;
    TPanel *Panel17;
    TSplitter *Splitter20;
    TPanel *Panel21;
    TPanel *Panel22;
    TSplitter *Splitter21;
    TDBGrid *DBGrid3;
    TDBNavigator *DBNavigator4;
    TLabel *Label58;
    TComboBox *ComboBoxPipeTrainType;
    TGroupBox *GroupBox32;
    TSplitter *Splitter22;
    TPanel *PanelCompareBack;
    TScrollBar *ScrollBarPipe;
    TImage *ImagePipe;
    TMemo *MemoPipeResult;
    TChart *ChartPipe;
    TLineSeries *Series34;
    TImageList *ImageList4;
    TImageList *ImageList5;
    TScrollBar *ScrollBarPST;
    TMenuItem *mnuCompareToolbar;
    TImageList *ImageListNew;
    TImageList *ImageListNewHot;
    TPopupMenu *PopupMenu8;
    TMenuItem *ppmDeleteFromList;
    TMenuItem *mnuFileSave;
    TMenuItem *N38;
    TMenuItem *ppmPSTSort;
    TMenuItem *ppmPipeToBase;
    TMenuItem *N48;
    TMenuItem *mnuOperationPipe;
    TLabel *Label59;
    TEdit *EditCompressFactor;
    TMenuItem *N49;
    TTabSheet *TabSheet9;
    TPanel *Panel25;
    TBitBtn *BitBtnArrayMDate;
    TBitBtn *BitBtnArrayTrainType;
    TGroupBox *GroupBoxBrowse;
    TTreeView *TreeViewTrain;
    TPopupMenu *PopupMenuMDatabase;
    TMenuItem *ppmAddToMeassureInfoDatabase;
    TPopupMenu *PopupMenu9;
    TMenuItem *N21;
    TGroupBox *GroupBox23;
    TComboBox *ComboBoxPersonnel;
    TCheckBox *CheckBoxAddMInfo;
    TBitBtn *BitBtnWriteInstrument;
    TMenuItem *ppmSaveOriginal;
    TPanel *Panel23;
    TToolBar *ToolBar4;
    TToolButton *ToolButtonDrawOne;
    TToolButton *ToolButton12;
    TToolButton *ToolButton11;
    TToolButton *ToolButtonPST;
    TToolButton *ToolButtonPCP;
    TToolButton *ToolButtonORG;
    TFileListBox *FileListBoxFile;
    TPopupMenu *PopupMenuSelection;
    TMenuItem *ppmTrainSelection;
    TGroupBox *GroupBoxTrainInfo;
    TLabel *LabelFileSelected;
    TLabel *LabelFileIndex;
    TLabel *LabelTrainInfo;
    TLabel *Label60;
    TLabel *LabelNums;
    TPopupMenu *PopupMenu10;
    TMenuItem *ppmAddType;
    TPopupMenu *PopupMenuCompare;
    TMenuItem *ppmTraceNum02;
    TMenuItem *ppmTraceNum04;
    TMenuItem *ppmTraceNum08;
    TMenuItem *ppmTraceNum16;
    TMenuItem *ppmTraceMerge;
    TPopupMenu *PopupMenuPCP;
    TPopupMenu *PopupMenuPST;
    TMenuItem *ppmViewList;
    TMenuItem *ppmAddToDatabase;
    TMenuItem *ppmChange;
    TMenuItem *ppmCompressCompare;
    TMenuItem *ppmCombustionCompare;
    TMenuItem *N39;
    TMenuItem *ppmTraceEight;
    TMenuItem *ppmTraceSeven;
    TMenuItem *ppmTractSix;
    TMenuItem *ppmTraceFive;
    TMenuItem *ppmTraceFour;
    TMenuItem *ppmTraceThree;
    TMenuItem *ppmTraceTwo;
    TMenuItem *ppmAddToTypicalPipeDatabase;
    TMenuItem *ppmAddToList;
    TMenuItem *ppmAddToMInfoDatabase;
    TMenuItem *N30;
    TMenuItem *N45;
    TMenuItem *N47;
    TMenuItem *N50;
    TMenuItem *ppmAddToDatabaseSecond;
    TGroupBox *GroupBox25;
    TPanel *Panel18;
    TCheckBox *CheckBoxCylinderCompare;
    TComboBox *ComboBoxEnlarge;
    TButton *Button3;
    TCheckBox *CheckBoxShowOrder;
    TButton *ButtonPerson;
    TPageControl *PageControl2;
    TTabSheet *TabSheet3;
    TSplitter *Splitter16;
    TPanel *Panel16;
    TSplitter *Splitter18;
    TDBNavigator *DBNavigator1;
    TPanel *PanelRecordNum;
    TDBGrid *DBGridDataInfo;
    TTabSheet *TabSheet4;
    TDBGrid *DBGrid1;
    TDBNavigator *DBNavigator2;
    TTabSheet *TabSheet5;
    TGroupBox *GroupBox29;
    TDBGrid *DBGrid2;
    TDBNavigator *DBNavigator3;
    TPanel *Panel14;
    TDBImage *DBImage1;
    TPanel *PanelTV;
    TButton *ButtonTV;
    TTabSheet *TabSheet8;
    TPanel *Panel24;
    TPanel *Panel26;
    TSplitter *Splitter13;
    TDriveComboBox *DriveComboBox3;
    TDirectoryListBox *DirectoryListBox1;
    TFileListBox *FileListBox1;
    TButton *ButtonProcess;
    TCoolBar *CoolBar1;
    TToolBar *ToolBarMainMenu;
    TToolButton *ToolButton30;
    TToolButton *ToolButton31;
    TToolButton *ToolButton32;
    TToolButton *ToolButton33;
    TToolButton *ToolButton35;
    TToolButton *ToolButton7;
    TToolButton *ToolButton34;
    TToolButton *ToolButton46;
    TToolBar *ToolBarMainToolBar;
    TToolButton *ToolButton28;
    TToolButton *ToolButton18;
    TToolButton *ToolButton19;
    TToolButton *ToolButtonFileSave;
    TToolButton *ToolButton24;
    TToolButton *ToolButton3;
    TToolButton *ToolButton20;
    TToolButton *ToolButton21;
    TToolButton *ToolButton22;
    TToolButton *ToolButton25;
    TToolButton *ToolButton36;
    TToolButton *ToolButton26;
    TToolButton *ToolButton23;
    TToolButton *ToolButton47;
    TToolButton *ToolButtonPipe;
    TToolButton *ToolButton43;
    TToolButton *ToolButton6;
    TToolButton *ToolButton29;
    TToolButton *ToolButton37;
    TToolButton *ToolButton44;
    TToolButton *ToolButtonProperty;
    TToolButton *ToolButton27;
    TToolButton *ToolButton5;
    TToolButton *ToolButton8;
    TCheckBox *CheckBoxDrawCylinderWave;
    TCheckBox *CheckBoxDrawPipeWave;
    TPopupMenu *PopupMenuInsert;
    TMenuItem *ppmInsertToDatabase;
        TFindDialog *FindDialog1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BitBtn7Click(TObject *Sender);
    void __fastcall BitBtnReadPClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall mnuFileExitClick(TObject *Sender);
    void __fastcall BitBtnPerformenceTestClick(TObject *Sender);
    void __fastcall BitBtnResultClick(TObject *Sender);
    void __fastcall BitBtnSetParametersClick(TObject *Sender);
    void __fastcall BitBtnOperationParametersClick(TObject *Sender);
    void __fastcall BitBtnReadFileClick(TObject *Sender);
    void __fastcall ppmPFaiClick(TObject *Sender);
    void __fastcall ppmPRateClick(TObject *Sender);
    void __fastcall ppmFrequencyClick(TObject *Sender);
    void __fastcall ppmBFilterClick(TObject *Sender);
    void __fastcall ppmDZFilterClick(TObject *Sender);
    void __fastcall ppmTranslatorFunctionClick(TObject *Sender);
    void __fastcall ppmHeatReleaseClick(TObject *Sender);
    void __fastcall Drive1Change(TObject *Sender);
    void __fastcall TreeView1Click(TObject *Sender);
    void __fastcall ListView1DblClick(TObject *Sender);
    void __fastcall ToolButton1Click(TObject *Sender);
    void __fastcall ToolButtonCPowerClick(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall ComboBoxIndexChange(TObject *Sender);
    void __fastcall BitBtn3Click(TObject *Sender);
    void __fastcall ActionOperationScanDiskExecute(TObject *Sender);
    void __fastcall ActionOperationSetupExecute(TObject *Sender);
    void __fastcall ActionProcessHeadReleaseExecute(TObject *Sender);
    void __fastcall ActionOperationReadDataExecute(TObject *Sender);
    void __fastcall PaintBoxAdjustTDCPaint(TObject *Sender);
    void __fastcall RGPosiClick(TObject *Sender);
    void __fastcall ListView1Click(TObject *Sender);
    void __fastcall ToolButtonPVClick(TObject *Sender);
    void __fastcall ToolButtonModifiedDataClick(TObject *Sender);
    void __fastcall ToolButtonDPDFClick(TObject *Sender);
    void __fastcall ToolButtonHRRClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ppmAdjustPTClick(TObject *Sender);
    void __fastcall ppmAdjustPVClick(TObject *Sender);
    void __fastcall ppmAdjustFFTPClick(TObject *Sender);
    void __fastcall ppmAdjustLogPVClick(TObject *Sender);
    void __fastcall LMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,TRect &rect, int X, int Y);
    void __fastcall LMouseMove(TObject * Sender, TShiftState Shift,TRect &rect, int X, int Y);
    void __fastcall LMouseUp(TObject * Sender, TMouseButton Button, TShiftState Shift,TRect &rect, int X, int Y);
    void __fastcall PaintBoxAdjustTDCMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall PaintBoxAdjustTDCMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
    void __fastcall PaintBoxAdjustTDCMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall ToolButtonDomainClick(TObject *Sender);
    void __fastcall ppmAdjustCPTClick(TObject *Sender);
    void __fastcall ppmAdjustDPDFClick(TObject *Sender);
    void __fastcall ppmAdjustHRRClick(TObject *Sender);
    void __fastcall ppmAdjustCHRRClick(TObject *Sender);
    void __fastcall ppmAdjustTemperatureClick(TObject *Sender);
    void __fastcall RadioGroupDrawModeClick(TObject *Sender);
    void __fastcall CheckBoxAdjustPTClick(TObject *Sender);
    void __fastcall ToolButtonOriginalDataClick(TObject *Sender);
    void __fastcall ToolButtonCHRRClick(TObject *Sender);
    void __fastcall BitBtnOneAllClick(TObject *Sender);
    void __fastcall PaintBoxOriginalPaint(TObject *Sender);
    void __fastcall PaintBoxOriginalMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall PaintBoxOriginalMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
    void __fastcall PaintBoxOriginalMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall ScrollBarOriginalChange(TObject *Sender);
    void __fastcall ppmOriginalDrawModeClick(TObject *Sender);
    void __fastcall PaintBoxAbstractPaint(TObject *Sender);
    void __fastcall PaintBoxAbstractMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall PaintBoxAbstractMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
    void __fastcall PaintBoxAbstractMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall ScrollBarAbstractChange(TObject *Sender);
    void __fastcall ppmAbstractMergeClick(TObject *Sender);
    void __fastcall FileListBoxFileDblClick(TObject *Sender);
    void __fastcall BitBtnSavePositionClick(TObject *Sender);
    void __fastcall ScrollBarAdjustChange(TObject *Sender);
    void __fastcall ActionOperationAbstractDataExecute(TObject *Sender);
    void __fastcall ActionOperationAdjustTDCExecute(TObject *Sender);
    void __fastcall ToolButtonLogPLogVClick(TObject *Sender);
    void __fastcall ActionFilePrintExecute(TObject *Sender);
    void __fastcall ActionFileReadPSTFileExecute(TObject *Sender);
    void __fastcall ActionFileReadPCPFileExecute(TObject *Sender);
    void __fastcall ActionFileReadOriginalFileExecute(TObject *Sender);
    void __fastcall ListBoxPSTFileDblClick(TObject *Sender);
    void __fastcall ListBoxPCPFileDblClick(TObject *Sender);
    void __fastcall ToolButtonPowerClick(TObject *Sender);
    void __fastcall ppmConGridClick(TObject *Sender);
    void __fastcall FileListBox2DblClick(TObject *Sender);
    void __fastcall ppMainMenuClick(TObject *Sender);
    void __fastcall ppMainToolbarClick(TObject *Sender);
    void __fastcall mnuOtherHideToolbarClick(TObject *Sender);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall ToolBarMainMenuExit(TObject *Sender);
    void __fastcall ToolBarMainToolBarExit(TObject *Sender);
    void __fastcall mnuHelpAboutClick(TObject *Sender);
    void __fastcall ToolButton22Click(TObject *Sender);
    void __fastcall ToolButton23Click(TObject *Sender);
    void __fastcall ToolButton24Click(TObject *Sender);
    void __fastcall ToolButton26Click(TObject *Sender);
    void __fastcall ToolButton36Click(TObject *Sender);
    void __fastcall ToolButtonMMaxClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
//    void __fastcall BitBtnReadListClick(TObject *Sender);
    void __fastcall BitBtnReadCurrentClick(TObject *Sender);
    void __fastcall BitBtnCloseUSBClick(TObject *Sender);
    void __fastcall BitBtnReadListClick(TObject *Sender);
    void __fastcall BitBtnReadAllClick(TObject *Sender);
    void __fastcall ppmOriginalNegtiveClick(TObject *Sender);
    void __fastcall ppmSaveOriginalDataClick(TObject *Sender);
    void __fastcall mnuPreProAntiFilterSetupClick(TObject *Sender);
    void __fastcall ppmAnalysisAccelerateClick(TObject *Sender);
    void __fastcall ppmSaveAbstractDataClick(TObject *Sender);
    void __fastcall EditDiameterChange(TObject *Sender);
    void __fastcall EditShiftKeyPress(TObject *Sender, char &Key);
    void __fastcall ToolButton39Click(TObject *Sender);
    void __fastcall ToolButton40Click(TObject *Sender);
    void __fastcall ToolButton41Click(TObject *Sender);
    void __fastcall ppmPP1Click(TObject *Sender);
    void __fastcall ppmPP2Click(TObject *Sender);
    void __fastcall ppmPP5Click(TObject *Sender);
    void __fastcall FilterComboBoxFileChange(TObject *Sender);
    void __fastcall mnuSetupColorClick(TObject *Sender);
    void __fastcall ppmDPI1Click(TObject *Sender);
    void __fastcall ppnDPI2Click(TObject *Sender);
    void __fastcall ppmDPI5Click(TObject *Sender);
    void __fastcall ppmSaveasTextFileClick(TObject *Sender);
    void __fastcall ppmPopupResultClick(TObject *Sender);
    void __fastcall ppmShowResultClick(TObject *Sender);
    void __fastcall ToolButtonOilPClick(TObject *Sender);
    void __fastcall CheckBoxDrawPipeWaveClick(TObject *Sender);
    void __fastcall ppmDeleteLineClick(TObject *Sender);
    void __fastcall ppmSetCursorColorClick(TObject *Sender);
    void __fastcall ppmClearAllListClick(TObject *Sender);
    void __fastcall ppmClearCurrentListClick(TObject *Sender);
    void __fastcall ppmChangeParametersClick(TObject *Sender);
    void __fastcall RadioGroupSingleCurveClick(TObject *Sender);
    void __fastcall CheckBoxFirstClick(TObject *Sender);
    void __fastcall CheckBoxSecondClick(TObject *Sender);
    void __fastcall CheckBoxHideThreeClick(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall ppmFormPCPClick(TObject *Sender);
    void __fastcall ImageAllDblClick(TObject *Sender);
    void __fastcall ppmShowCutClick(TObject *Sender);
    void __fastcall ppmSetColorClick(TObject *Sender);
    void __fastcall CheckBoxValueClick(TObject *Sender);
    void __fastcall ppmSinglePCPClick(TObject *Sender);
    void __fastcall ToolButtonPropertyClick(TObject *Sender);
    void __fastcall mnuOperationDatabaseClick(TObject *Sender);
    void __fastcall ppmAddToDatabaseClick(TObject *Sender);
    void __fastcall mnuDatabaseOutputClick(TObject *Sender);
    void __fastcall mnuDatabaseViewClick(TObject *Sender);
    void __fastcall TreeViewDatabaseDblClick(TObject *Sender);
    void __fastcall ListBoxTrainListDblClick(TObject *Sender);
    void __fastcall Color1Click(TObject *Sender);
    void __fastcall DBGridDataInfoDrawColumnCell(TObject *Sender,
          const TRect &Rect, int DataCol, TColumn *Column,
          TGridDrawState State);
    void __fastcall N19Click(TObject *Sender);
    void __fastcall ppmDataDeleteClick(TObject *Sender);
    void __fastcall ppmTVReloadClick(TObject *Sender);
    void __fastcall DBGridDataInfoCellClick(TColumn *Column);
    void __fastcall ppmBrowseInsertToDatabaseClick(TObject *Sender);
    void __fastcall ToolButton47Click(TObject *Sender);
    void __fastcall CheckBoxCylinderCompareClick(TObject *Sender);
    void __fastcall ComboBoxEnlargeChange(TObject *Sender);
    void __fastcall Panel6DblClick(TObject *Sender);
    void __fastcall ppmChangeClick(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall DBGridDataInfoTitleClick(TColumn *Column);
    void __fastcall ppmOutOrderClick(TObject *Sender);
    void __fastcall CheckBoxShowOrderClick(TObject *Sender);
    void __fastcall ppmViewListClick(TObject *Sender);
    void __fastcall ToolBar1Click(TObject *Sender);
    void __fastcall ppmMemoPrintClick(TObject *Sender);
    void __fastcall ppmEditPSTClick(TObject *Sender);
    void __fastcall mnuHelpInstrumentClick(TObject *Sender);
    void __fastcall ppmEditListClick(TObject *Sender);
    void __fastcall Splitter9Moved(TObject *Sender);
    void __fastcall ActionTraceTwoExecute(TObject *Sender);
    void __fastcall ActionTraceThreeExecute(TObject *Sender);
    void __fastcall ActionTraceFourExecute(TObject *Sender);
    void __fastcall ActionTraceFiveExecute(TObject *Sender);
    void __fastcall ActionTraceSixExecute(TObject *Sender);
    void __fastcall ActionTraceSevenExecute(TObject *Sender);
    void __fastcall ActionTraceEightExecute(TObject *Sender);
    void __fastcall ToolButton37Click(TObject *Sender);
    void __fastcall ToolButton29Click(TObject *Sender);
    void __fastcall ActionEnlargeTwoExecute(TObject *Sender);
    void __fastcall ActionEnlargeFourExecute(TObject *Sender);
    void __fastcall ActionEnlargeEightExecute(TObject *Sender);
    void __fastcall ActionEnlargeNormalExecute(TObject *Sender);
        void __fastcall mnuOtherOptionClick(TObject *Sender);
    void __fastcall ToolButtonBasicInfoClick(TObject *Sender);
    void __fastcall ppmSetupFontClick(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall ButtonPersonClick(TObject *Sender);
    void __fastcall ppmLoadPicClick(TObject *Sender);
    void __fastcall ppmDeletePicClick(TObject *Sender);
    void __fastcall ppmStrechPicClick(TObject *Sender);
    void __fastcall ComboBoxPersonnelEnter(TObject *Sender);
    void __fastcall ComboBoxPersonnelChange(TObject *Sender);
    void __fastcall ButtonInfoClick(TObject *Sender);
    void __fastcall N46Click(TObject *Sender);
    void __fastcall ppmAddToTypicalPipeDatabaseClick(TObject *Sender);
    void __fastcall ComboBoxPipeTrainTypeEnter(TObject *Sender);
    void __fastcall ComboBoxPipeTrainTypeChange(TObject *Sender);
    void __fastcall DBGrid3CellClick(TColumn *Column);
    void __fastcall DBNavigator4Click(TObject *Sender,
          TNavigateBtn Button);
    void __fastcall ToolButtonPSTClick(TObject *Sender);
    void __fastcall ToolButtonPipeClick(TObject *Sender);
    void __fastcall ToolButton5Click(TObject *Sender);
    void __fastcall PanelCompareBackResize(TObject *Sender);
    void __fastcall ScrollBarPipeChange(TObject *Sender);
    void __fastcall ToolButtonDrawOneClick(TObject *Sender);
    void __fastcall ScrollBarPSTChange(TObject *Sender);
    void __fastcall ppmCombustionCompareClick(TObject *Sender);
    void __fastcall ppmCompressCompareClick(TObject *Sender);
    void __fastcall mnuCompareToolbarClick(TObject *Sender);
    void __fastcall ImageAllMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ImageAllMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ppmGridClick(TObject *Sender);
    void __fastcall ImageAllMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall PanelAllResize(TObject *Sender);
    void __fastcall ppmAddToListClick(TObject *Sender);
    void __fastcall ppmDeleteFromListClick(TObject *Sender);
    void __fastcall mnuFileSaveClick(TObject *Sender);
    void __fastcall ppmPSTSortClick(TObject *Sender);
    void __fastcall ppmPipeToBaseClick(TObject *Sender);
    void __fastcall mnuHelpSoftwareClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall BitBtnWriteInstrumentClick(TObject *Sender);
    void __fastcall BitBtnArrayMDateClick(TObject *Sender);
    void __fastcall BitBtnArrayTrainTypeClick(TObject *Sender);
    void __fastcall ppmAddToMeassureInfoDatabaseClick(TObject *Sender);
    void __fastcall N21Click(TObject *Sender);
    void __fastcall TreeViewTrainDblClick(TObject *Sender);
    void __fastcall PageControlBrowseChange(TObject *Sender);
    void __fastcall ppmAddToMInfoDatabaseClick(TObject *Sender);
    void __fastcall ppmTrainSelectionClick(TObject *Sender);
    void __fastcall ppmAddTypeClick(TObject *Sender);
    void __fastcall ppmTraceNum02Click(TObject *Sender);
    void __fastcall ppmTraceNum04Click(TObject *Sender);
    void __fastcall ppmTraceNum08Click(TObject *Sender);
    void __fastcall ppmTraceNum16Click(TObject *Sender);
    void __fastcall ppmTraceMergeClick(TObject *Sender);
    void __fastcall FileListBoxFileChange(TObject *Sender);
    void __fastcall PanelTVUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
    void __fastcall PanelTVDockOver(TObject *Sender,
          TDragDockObject *Source, int X, int Y, TDragState State,
          bool &Accept);
    void __fastcall ButtonTVClick(TObject *Sender);
    void __fastcall PanelTVDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
    void __fastcall ChartCurveDblClick(TObject *Sender);
    void __fastcall ButtonProcessClick(TObject *Sender);
    void __fastcall ppmInsertToDatabaseClick(TObject *Sender);
//    void __fastcall mnuTraceMergeClick(TObject *Sender);

private:	// User declarations
//-------------------------------------------------------
    bool bPipeCompared;
//    float fDetectLevel;         //压力波分析时相似性的门限值
    bool bAnalysisMethod;
    bool bExcel;                //在分析时生成Excel报表
    bool bCurveModi;            //表示是否在调整了显示范围，每次读入文件时置为false
    bool bProcessing;
    AnsiString strTimeShort;
//  软件加密用常量
    TDateTime dtSStartTime;  //软件的安装日期
    TDateTime dtLLastTime;   //最后一次使用的日期
// 生成列表时的时间差变量
//    TDateTime dtLevel;
    TColor clBorderColor;
//    String strNSecret;
//    String strMSecret;
//    String strLibSecret;
    String strSoftTarget;
    String strSoftInstall;

    int    iNowSelectTrainType;
    int    iNowDetectInfo;
    int    iListNumber;
    int    iSSoftNumbers;
    int    iSListNumber;
    int    iSBorderColor;
    int    iDeleteOld;
    int    iSoftNum;
    int    iSoftRNum;
    int    iSoftINum;
    int    iiGridLineColor;
    unsigned short usiHour,usiMinute,usiSecond;
    bool   bFInstalled;
    bool   bFirstTime;
//    bool   bSaveSecret;
    bool   bSecondTime;
    bool   bOperateFirst;
    bool   bSEnabled;
    bool   bSInformed;
    bool   bSInformedBK;
    bool   bExitOut;
//========================================================

//以下是树形浏览所需的变化
//--------------------------------------------------------
    bool    bBrowseOperated;
    bool    bDateBrowseStyle;
    bool    bAddMInfo;
    int     iMainTrainType;
    AnsiString  strQMDate;
    AnsiString  strQDieselSpeed;
    AnsiString  strQTrainType;
    AnsiString  strQTrainNumber;
    AnsiString  strQCombustionMode;
//========================================================
    
    bool    bGridFilled;
    bool    bPCPEntered;
    bool    bDrawDetect; //用于决定是否绘制参数及分析结果
    float   faverSpeed;
    float   faverPower;
    float   faverOil;
    int     iaverNumber;
    TMemoryStream *pArrayMS[32];
    bool      bPSTDrawed;
    bool      bPSTDrawOne;
    bool      bPSTChanged;
    TColor mainCurveColor[32];
    float     fXPSTStep;
//-----------------------------------------------------------
//显示参数时的字体设置
    int       iDieselNum;
    TStringList * strLibResult;
    bool      bInstrumentRead;
    bool      bDrawBasicCurve;
    AnsiString strBasicFontName;
    int        iBasicFontSize;
    bool       bBasicFSBold;
    bool       bBasicFSItalic;
    bool       bBasicFSUnderline;
    bool       bBasicFSStrikeOut;
    TColor     clBasicFSColor;
    bool       bSaveOrig;
//------------------------------------------
// 跟踪数据时的一些变量
//   查询时的变化
    float fDrawConst;
    TColor clListCurveColor[8];
    int iListDrawKind;
    int iListPage,iListPageNum;
    bool bListTogether;
    AnsiString strSelectListName[8];
//==========================================
    float *fdatax,*fdatay;
    int    iEnlargeSize;
    float  fTVStart, fTVEnd;
    bool   bChartFilled;
    TColor colorTV;
    TColor clDatabaseColor;
    AnsiString strFontSet;
    int   iFontHeight;
    int   iFontSize;
    int   iiNowPosi;
    int   iLastPosi;
    TColor colorFont;
    bool  bTVLoaded;
    bool  bTVQuery ;



    TStringList *ListPath;
    TStringList *ListList;
    int   iListNum[800];
    int   iTrainTimes;
    bool bDataBackup;
    int  iDeletePosi;
    int  iBackupMode;
    TDate dtDeleteDate;
    AnsiString strBackupTrainNum;
    THitTests HT;
//===========================================================
    bool bAddToDatabaseResult;    //用于决定是否将数据添入数据库
    bool bCombustion;
    bool bOilSupply;
    bool bCursorLine;
    bool bCursorLineChanged;
    int  iXMin,iXMax,iYMin,iYMax;
    bool bDrawPWave;
    bool bDrawCWave;
    TColor clInletColor,clCompressColor,clCombustionColor,clOutletColor;
    TColor clBackground;
    TColor clLineColor,clTextColor;
    AnsiString strSoftTitle;
    float fstartrt,fendrt;
//  --------------------------------------------------
//　以是用于与仪器通信所需的变量
    int  iDrawLineWidth;
    bool bUSBOpened;
    bool bUSBWorking;
    bool bReadAll;

    bool bITF;
    unsigned char *strData;
    unsigned char strComPart[65];
    unsigned char *strTempData;
    int iFileNum;
    int iReadTime;
    int iFileLength;
    float fT10,fT20,fT30;


    float * fPassData[iPASSNUM];



    AnsiString strPPSignalType[3];
//    AnsiString strP2SignalType;
    AnsiString strFrequency;
    AnsiString strSampleLength;
    AnsiString strMTime;
    AnsiString strFileDirectory;
    
    lFileHeadStruct LFHS;
//-----------------------------------------------------
    MaxBuffer maxBuffer;
    MaxInfo maxInfo[20];
    int   iOriginalStart;
    int   iOriginalEnd;
    bool  bOriginalDrawAll;
    bool  bAbstractDrawAll;
    bool  bAbstractDrawFF;
    bool  bDrawModePressed;
    float fXOriginalStep;
    float fXAbstractStep;
    int   iAbstractStart;
    int   iAbstractEnd;
//    bool bAbstractDrawAll;


    drawKind adjustDrawKind;

    int iHRRLength;
    AnsiString gstrFileName;
    TColor clGridLineColor;
    int iGridLineTypeIndex;
    int iMiddle;
    float fTimeInterval;
    TPoint pointMouseBackup;
    TPoint pointMouseOrigin;
    TPoint pointMouseOld;
    bool bPBMouseDragging;
    bool bDrawed;
    bool bBackMousePoint;
    bool bButtonPressed;
    bool bAllHRR;
    bool bAdjustHRR;
    bool bLoadOriginal;

    bool bPLog;
    bool bControlFromPrinter;
    bool bFirstMove;

    lCPressure lCP;
    TRect rectA;
    TRect *prectAdjust;
    TRect rectAdjust[10];
    int iCircleDim;
    float fXStep;
    float fYStep;
    float *fYData; //指向当前纵坐标数据的指针
    float *fXData; //指向当前横坐标数据的指针

    bool bFileOpened;
    int iMainPrnSign;
    bool bLeftShift;
    int iDataLength;

    AnsiString CurrentDir;
    AnsiString CurrentIndex;
    bool bDriveInited;
    TCommandState ComState;

    AnsiString strOriginalName;
    AnsiString strOneOfAll;

    bool bParameterInited; //用于标识是否对柴油机参数进行了初始化
    bool bStarted;

    int iChoicedNum;
    int iPreProMethod;
    int iCurrentDraw;
    int iCalculateMethod;
//---------------------------------------------------
//  滤波处理用到的变量
    bool bFilter,bAutolen,bFiltered;      //用于标识是否设置了滤波处理
    float fPl,fPh,fSl,fSh;
    int iDetail;
    int iFilterKind;
    int iWindowChoice;
    int iNum;          //

	int iFilterLen;
	float fFilter[100];
    lFIR lfir;

//---------------------------------------------------
//以下变量用于生成列表
    int iMINum[200];
    TStringList * ListStringList;
    cPPWFDRead * ppr;
    int iListCount;
    AnsiString strPSTFileDirectory;    //上一次打开文件的路径
    AnsiString strPresetPath;          //保存文件的路径
    int  iFileExt;                     //后缀类型
//---------------------------------------------------
    bool bRegHave;                    //用于表明键值是否存在
    int  iKeyPressPosi;                   //用于表明是在哪个图上按的键
    float fMaxMax;

//----------------------------------------------------
// 以下参数用于三维绘图
    float fXAngle;
    float fYAngle;
    int   iXALength;
    int   iYALength;
    int   iX0Step;
    int   iY0Step;
    int   iX0Position;
    int   iY0Position;
    bool  bMouseDown;
    TPoint ptOriginal;
    bool  bFileChanged;
    int   iPSTFileNum;
    bool  bRightButton;
    TRect rectTime,rectValue,rect3D,rectMaxValue,rectCutValue,rectSingle;
    int   iXTimeInterval, iYTimeInterval, iY3DInterval;
    int   iCutPosi;
    bool  bShowCut;
    TColor clSelectedColor;
    int   iSelectedItem;
    bool  bMouseMoving;
    bool  bDataShowAll;
    int   iOriginalEnd_Backup;
    AnsiString strTrainType_Backup;
    AnsiString strTitle_Backup;
    AnsiString strValidPath;
//==================================================
//-------------------------------------
// 以下用于操纵EXCEL表
    Variant    vExcelApp;
    Variant    vWorkBook;
    Variant    vSheet;
    Variant    vChart; //指向图表
    Variant    vRange;
    Variant    vBorder;
//=======================================

public:		// User declarations
    AnsiString strPipeDetectResult[16];
    bool  bTVOuter;
    int   iTVHeight,   iTVWidth;
    int   iTVCurrPosi, iTVLastPosi;
    int   iQueryStyle;
    AnsiString strMDate;
    AnsiString strTrainType;            //
    AnsiString strTrainNumber;
    AnsiString strDieselNumber;
    int   iTrainType;
    bool  bAnalysising ;

    AnsiString strCombustion;
    AnsiString strDieselSpeed;
    AnsiString strPerson;

    //为了与打印模块通信，不得不设置这些公有变量
    int              iMTrainInfoNums;
    sctMTrainInfo    myMTrainInfo[MAXTRAININFONUMS];    //用于保存
    StructDieselInfo myDieselInfo[11];    //用于保存机车参数信息
    AnsiString       strArrayTrainType[6];
    AnsiString       strExeFilePath;
//-----------与打印机通信的公有变量-----------------------------------------
    structDetect myDetect[16];      //用于记录16个缸的计算结果
    bool bFromPrinter;              // 用于绘图控制
    bool bShowAll;
    bool bDrawStyle;
    bool bPCPGridLine;
    bool bPSTGridLine;
    bool bOneOfAll;
    bool bPSTOpened;
    bool bLoadList;
    bool bRectSelected[10];
    bool bDrawPart;

    int iAdjustDrawNum;
    int iCurveShift;
    int iChoiceStart,iChoiceEnd;
    int iCCStart,iCCEnd;
    int iCommonStart,iCommonEnd;
    int iPrintHeight;

    AnsiString strUserTitle;
    AnsiString strStatusInfo;
    AnsiString strPSTName;
    AnsiString strPCPName;
    lDieselHRBP lDS;
    enumDrawDevice emDDevice;    //  0:TPaintBox  1:TPrinter    2: TImage
    drawKind AllDrawKind;
    drawKind PCPDrawKind;
    float fXFactor,fYFactor;
//--------------------------------------------------------------------------
    __fastcall TFormMain(TComponent* Owner);
    void __fastcall SetbGridLine(bool bgl)
    {
        bPCPGridLine = bgl;
        bPSTGridLine = bgl;
    }
    void __fastcall SetbDrawBasicCurve(bDBC)
    {
        bDrawBasicCurve = bDBC;
    };
    bool __fastcall GetbDrawBasicCurve(void)
    {
        return bDrawBasicCurve;
    };
    void __fastcall MoveButton(int iPosi,bool bUpOrDown);
    bool __fastcall InitParameters(void);
    void __fastcall UpdateTreeView(void);
    void __fastcall AddDirectory(AnsiString path, TTreeNode * fNode);
    void __fastcall UpdateListView(void);
    void __fastcall ListViewAddDirectory(void);
    void __fastcall ListViewAddFile(void);
    void __fastcall FillListClick(void);
    void __fastcall FunHeatRelease(void);
    void __fastcall ShiftCurve(int iNum);
    void __fastcall DeleteMemory(void);
    void __fastcall FFTAnalysis(void);
    void __fastcall RefreshStatus(AnsiString str);
    void __fastcall PBDrawRect(TObject* Sender,TPoint& LT, TPoint& TB);
    void __fastcall RefreshDrawMode(void);
    void __fastcall DrawAdjustCurve(TObject* Sender,TRect& rect);
    void __fastcall LoadCurrentPCP(void);
    void __fastcall LoadCurrentPST(void);
    bool __fastcall DetectPSTStatus(void);
    bool __fastcall LoadCurrentOriginal(void);
    void __fastcall PPMAdjustSingleMode(int icindex);
    void __fastcall GetMinMax(float * fdata, int ilen, float& fmin, float & fmax);
    void __fastcall DrawPSTAll(TObject* Sender,TRect rect);
    void __fastcall DrawPSTAll3D(TObject* Sender,TRect rect);
    void __fastcall DisplayHint(TObject* Sender);
    bool __fastcall InitMouseData(void);
    bool __fastcall AllDrawed(TObject * Sender, drawKind drawkind);
    bool __fastcall BrowseForFolder(AnsiString Title, WideString Root, AnsiString & Driectory);
//------------------------------------------------------------
//  以下函数用于检测仪通信
    void __fastcall FillGrid(void);
    int  __fastcall  ReadSingleFile(int iIndex);
    bool __fastcall SaveSingleFile(int iIndex);
    bool __fastcall LIntToFloat(void);
    bool __fastcall FillChart(void);
    bool __fastcall GetFileHead(int iIndex);
    int  __fastcall AutoInsertDatabase(void);
    bool __fastcall ReadFileList(void);
    void __fastcall ReadCurrentList(void);
    void __fastcall ReadAllList(void);
    void __fastcall OriginalDPDF(void);
    void __fastcall RefreshPChart(void);
    bool __fastcall FormPSTList(void);
    void __fastcall FillPSTInfo(void);
    bool __fastcall ConvertOrgToPCP(int i);
    bool __fastcall LoadCurrentBinPCP(bool bdatabase);
    void __fastcall LoadCurrentBinPST(void);
    void __fastcall LoadCurrentBinORG(void);
    void __fastcall RegSaveInfo(void);
    bool __fastcall RegReadInfo(void);
    void __fastcall RefreshResultControl(void);
    float __fastcall ConvertToIEEE(lFloat& lf);
    void __fastcall SetTrainType(short int itype);
    bool __fastcall SetDieselInfo(int itype ,bool bFromDatabase);
    void __fastcall DatabaseOpen(void);
    void __fastcall DatabaseClose(void);
    void __fastcall UpdateTreeViewDatabase(void);
    bool __fastcall AddToDatabase(bool bFromFile);
    bool __fastcall InsertDatabaseResult(bool bFromFile);
    bool __fastcall HaveTrainList();

//-------------------------------------------------------------
    bool __fastcall TVAddTrainType(void);
    void __fastcall QueryDatabasebyTV(void);
    void __fastcall RefreshStatusBar(AnsiString strInfo, int iPosi);
    void __fastcall GetDateFromString(AnsiString& strdate, unsigned short & uy, unsigned short & um, unsigned short& ud);
    void __fastcall TVDrawCurve(void);
    void __fastcall RefreshTV(void);
    int  __fastcall GetiTrainType(AnsiString & strTrain);
    bool __fastcall FormPSTList_New(void);
    void __fastcall DeleteFromDatabase(void);
    void __fastcall MainInsertToDatabase(AnsiString strNameTemp);
    void __fastcall FillCompareChart(AnsiString stry);
    int __fastcall GetiCurrPosi(AnsiString stry);
    void __fastcall InitDieselInfo(void);
    bool __fastcall SetParameters(void);
    void __fastcall InitEngineSpeed(float fen);
    void __fastcall ChangeToTxt(void);
    void __fastcall FillmyDetectResult(bool bFromDatabase);
    void __fastcall AnalysismyDetectResult(bool bShow, int iItem);
    void __fastcall AnalysisResultAll(bool bShow);
    int __fastcall NormalizeSpeed(int itraintype, float fee);
    void __fastcall FillSingleCompareChart(AnsiString stry);
    void __fastcall AnalysisCombustionStatus(bool bShow);
    void __fastcall AnalysisMiFengXing(bool bShow);
    void __fastcall AnalysisOilAngle(bool bShow);
    void __fastcall AnalysisOilPeriod(bool bShow);
    void __fastcall AnalysisCPower(bool bShow);
    void __fastcall AnalysisAll(bool bShow);
    void __fastcall GetListPageNum(void);
    void __fastcall DrawListDirect(void);
    void __fastcall SetMenuChecked(int iposi);
    void __fastcall ShowCompareList(int inum, bool bAlone);
    void __fastcall FillPcpInfo(void);
    bool __fastcall InsertTypicalPipeToDatabase(AnsiString& strfileName);
    void __fastcall FillPipeData(void);
    void __fastcall AnalysisPipe(void);
    bool __fastcall DetectPipeByBase(void);
    void __fastcall NormalizeData(float* fp, int ilen);
    void __fastcall ReadPipeDataFromDatabase(float* fdata, int ilen);
    float __fastcall DetectModal(float * fmodal, float* foriginal, int istart, int icnum);
    void __fastcall FillAndCopyChart(float* fdata, int ilen, int ix, int iy, AnsiString& strinfo);
    void __fastcall GetTrainInfo(AnsiString& str);
    void __fastcall FillPSTSingle(int inum, float* ffai, float* fvalue, int istart, int iend);
    void __fastcall DeleteRamFile(void);
    void __fastcall DrawImageAll(void);
    void __fastcall InsertToPipeBase(AnsiString& strNameTemp);
    void __fastcall Params_Save(void);
    void __fastcall Params_Load(void);
    void __fastcall IniFileWrite(void);
    bool __fastcall IniFileRead(void);
//------------------------------------------------------------
//  以下函数用于加密函数
    int __fastcall isSoftwareValid(void);
    void __fastcall AddCode(AnsiString& strsecret);
    void __fastcall DeleteCode(AnsiString& strsecret);
    bool __fastcall FormAdd(void);
    void __fastcall FormDelete(void);
    void __fastcall SoftRestrict(void);
    bool __fastcall RegSoftwareValid(void);
    void __fastcall RefreshTViewByDate(void);
    void __fastcall RefreshTViewByTrainType(void);
    void __fastcall AddToMeasureInfo(AnsiString& strlist);
    void __fastcall LoadBrowseList(void);
    void __fastcall ReformDate(AnsiString& strdate);
    void __fastcall FormDate(AnsiString& strdate);
    int __fastcall GetiDieselNum(AnsiString& str);
    bool __fastcall PleaseReadIt(int iIndex, int& iposi);
    bool __fastcall ListFileValid(AnsiString& strTemp);
    void __fastcall DataAnalysis(void);
    void __fastcall SaveToExcels(void);
    bool __fastcall FormTVAddTrainType(void);
    bool __fastcall ProcessData(AnsiString& str);
//============================================================
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
