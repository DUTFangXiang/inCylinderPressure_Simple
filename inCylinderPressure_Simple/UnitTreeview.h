//---------------------------------------------------------------------------

#ifndef UnitTreeviewH
#define UnitTreeviewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormTV : public TForm
{
__published:	// IDE-managed Components
    TTreeView *TreeViewDatabase;
    TImageList *ImageList1;
    TPopupMenu *PopupMenu1;
    TMenuItem *N1;
    TMenuItem *ppmQueryByTrainType;
    TMenuItem *ppmQueryByDateTime;
    void __fastcall TreeViewDatabaseDblClick(TObject *Sender);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormDragDrop(TObject *Sender, TObject *Source, int X,
          int Y);
    void __fastcall FormUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
private:	// User declarations
public:		// User declarations
    __fastcall TFormTV(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTV *FormTV;
//---------------------------------------------------------------------------
#endif
