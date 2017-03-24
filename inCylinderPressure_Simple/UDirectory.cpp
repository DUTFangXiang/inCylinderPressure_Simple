//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDirectory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDirectory *FormDirectory;
//---------------------------------------------------------------------------
__fastcall TFormDirectory::TFormDirectory(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormDirectory::FillTreeList(void)
{
    //TODO: Add your source code here
    AnsiString strTemp;

    TreeView1->Items->Clear();
    TTreeNode *rNode,*mNode;
    rNode = TreeView1->Items->Add(TreeView1->Selected,"我的电脑");  //加入根节点
    rNode->ImageIndex = 0;
    rNode->SelectedIndex = 0;
    strTemp = ::ExtractFileDrive(strCurrentDir);
    mNode = TreeView1->Items->AddChild(rNode,"A:");
    mNode->ImageIndex = 4;
    mNode->SelectedIndex = 4;
    for(int i=1;i<Drive1->Items->Count;i++)
    {
        mNode = TreeView1->Items->AddChild(rNode,AnsiString(char('B'+i))+":");
        mNode->ImageIndex = 3;
        mNode->SelectedIndex = 3;
        AddDirectory(AnsiString(char('B'+i))+":",mNode);
    }
}


void __fastcall TFormDirectory::AddDirectory(AnsiString path, TTreeNode * fNode)
{
    //TODO: Add your source code here
    TSearchRec sr;
    TTreeNode *mNode;
    if(FindFirst(path + "\\*.*",faDirectory,sr) == 0)
    {
        if(sr.Attr == faDirectory)
        {
            if((sr.Name != ".") && (sr.Name != ".."))
            {
                mNode = TreeView1->Items->AddChild(fNode,sr.Name);
                mNode->ImageIndex = 1;
                mNode->SelectedIndex = 2;
  //              AddDirectory(path +"\\"+sr.Name,mNode);
            }
        }
    }
    while(FindNext(sr) == 0)
    {
        if(sr.Attr == faDirectory)
        {
            if((sr.Name != ".")&&(sr.Name != ".."))
            {
                mNode = TreeView1->Items->AddChild(fNode,sr.Name);
                mNode->ImageIndex = 1;
                mNode->SelectedIndex = 2;
    //            AddDirectory(path+"\\"+sr.Name,mNode);
            }
        }
    }
    FindClose(sr);
}
void __fastcall TFormDirectory::FormCreate(TObject *Sender)
{
    EditCurrentDir->Text = strCurrentDir;
    FillTreeList();
}
//---------------------------------------------------------------------------

