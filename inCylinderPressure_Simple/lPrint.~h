//---------------------------------------------------------------------------

#ifndef lPrintH
#define lPrintH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <Printers.hpp>
#include <Buttons.hpp>

/*
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <Printers.hpp>
#include <Buttons.hpp>
*/

const int iDrawHeight  = 950;
const int iDrawWidth   = 650;
const int iWBorder     = 30;
const int iHBorder     = 25;
const int iHTextPosi   = 45;
const int iWTextPosi   = 80;
const int iHStep       = 60;
const int iHCurvePosi  = 80;
//---------------------------------------------------------------------------
class TFormPrint : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *StatusBar1;
    TPrintDialog *PrintDialog1;
    TPrinterSetupDialog *PrinterSetupDialog1;
    TImageList *ImageList1;
    TPanel *PanelBackground;
    TScrollBar *ScrollBarDraw;
    TPanel *PanelDraw;
    TImage *ImageBottom;
    TImage *ImageMain;
    TImage *ImageRight;
    TImage *ImageBackground;
    TCoolBar *CoolBar1;
    TToolBar *ToolBar1;
    TToolButton *ToolButtonZoomIn;
    TToolButton *ToolButtonPrinterSetup;
    TToolButton *ToolButtonPrint;
    TToolButton *ToolButtonExit;
    TComboBox *ComboBoxPercent;
    TComboBox *ComboBoxPrintContent;
    TToolBar *ToolBar2;
    TComboBox *ComboBoxList;
    TComboBox *ComboBoxFile;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TListBox *ListBoxBuffer;
    TPopupMenu *PopupMenu1;
    TMenuItem *N1;
    TToolButton *ToolButton6;
    TToolButton *ToolButtonZoomOut;
    TToolButton *ToolButton7;
    void __fastcall ToolButtonExitClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ToolButtonPrinterSetupClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall ScrollBarDrawChange(TObject *Sender);
    void __fastcall ToolButtonZoomInClick(TObject *Sender);
    void __fastcall ToolButtonZoomOutClick(TObject *Sender);
    void __fastcall ComboBoxPercentChange(TObject *Sender);
    void __fastcall ToolButtonPrintClick(TObject *Sender);
    void __fastcall ComboBoxPrintContentChange(TObject *Sender);
    void __fastcall ComboBoxListChange(TObject *Sender);
    void __fastcall ComboBoxFileChange(TObject *Sender);
    void __fastcall ImageMainMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall ImageMainMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ImageMainMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ToolButton7Click(TObject *Sender);
private:	// User declarations
    bool  bDrawBasicCurve;
    float fFontHeight;
    float psfFrequency[22];
    float psfGConst[9];
    int iSizeCoef;
    int iXStep,iYStep;
    int iHeightBackup,iWidthBackup;
    char charDriver;
    bool bPrint;
    int iDrawType;
    bool bLibCompareBackup,bAnalysisResultBackup;
    bool bDrag;
    int iscrollPosi;
    TPoint pointOriginal;
    TCursor nowCursor,OldCursor;
    int iImagePosi;
    int iImagePosiMax;
    int iIPFactor;
    float fXPPfactor,fYPPfactor;
    float fFontSize;

//    float fFontHeight;
    int iPrintHeight;
    bool bPrintDrawGrid;
    bool bFirstPage;
    bool bListChanged;
    bool bpCPeak;
    bool bpCPeriod;
    bool bpCCoef;
    TPrinter* Prntr;
public:		// User declarations
   int iLibPosi;
   AnsiString strPersonName;
    __fastcall TFormPrint(TComponent* Owner);
    void __fastcall SetbDrawBasicCurve( bool bDBC)
    {
        bDrawBasicCurve = bDBC;
    };
    void __fastcall SetbpC(bool bpk,bool bpd,bool bcf)
    {
        bpCPeak = bpk;
        bpCPeriod = bpd;
        bpCCoef = bcf;
    };
    void __fastcall SetbPrintDrawGrid(bool bb)
    {
        bPrintDrawGrid = bb;
    };
    bool __fastcall GetbPrintDrawGrid(void)
    {
        return bPrintDrawGrid;
    }
    void __fastcall SetiDrawType(int itype)
    {
        iDrawType = itype;
    };
    void __fastcall SetpsfFrequency(float* fc,int n);
    void __fastcall SetpsfGConst(float* fc,int n);
    void __fastcall DrawCurve(void);
    void __fastcall ZoomOutDraw(void);
    void __fastcall DrawContent(TObject* Sender,TRect& rect);
    void __fastcall DrawResultText(TObject* Sender,TRect& rect);
    void __fastcall DrawCurrentCurve(TObject* Sender,TRect& rect);
    void __fastcall ClearBackground(TObject* Sender, TRect& rect);
    void __fastcall DrawListCurve(TObject* Sender, TRect& rect);
    void __fastcall DrawCompareCurve(TObject* Sender, TRect& rect);
    void __fastcall DrawResultCurve(TObject* Sender, TRect& rect);
    void __fastcall DrawTitle(TCanvas * myCanvas,TRect& rect);
    void __fastcall AdjustDrawRect(TRect& rect);
    void __fastcall DrawNewListCurve(TObject* Sender, TRect& rect);
    void __fastcall DrawNewCurrentCurve(TObject* Sender, TRect& rect);
    void __fastcall DrawFirstCCurve(void);
    void __fastcall PrintContent(TObject* Sender, TRect& rect);
    float __fastcall fSign(float fvalue);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrint *FormPrint;
//---------------------------------------------------------------------------
#endif
