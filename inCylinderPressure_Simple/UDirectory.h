//---------------------------------------------------------------------------

#ifndef UDirectoryH
#define UDirectoryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TFormDirectory : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *EditCurrentDir;
    TTreeView *TreeView1;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TDriveComboBox *Drive1;
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations

public:		// User declarations
    AnsiString strCurrentDir;
    __fastcall TFormDirectory(TComponent* Owner);
    void __fastcall FillTreeList(void);
    void __fastcall AddDirectory(AnsiString path, TTreeNode * fNode);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDirectory *FormDirectory;
//---------------------------------------------------------------------------
#endif
