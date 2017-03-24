//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lPath.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPath *FormPath;
//---------------------------------------------------------------------------
__fastcall TFormPath::TFormPath(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPath::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Shift.Contains(ssCtrl)&&(Key=='x'||Key=='X'))
    {
        ModalResult = mrOk;
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormPath::EditFilePathExit(TObject *Sender)
{

    if(ModalResult == mrOk)
    {
        AnsiString strTemp;
        int iPosi,ilen;
        char ch;
        strTemp = EditFilePath->Text;
        ilen = strTemp.Length();
        iPosi = strTemp.Pos(":");
        if((iPosi == 0)||(iPosi != 2))
        {
            Application->MessageBox("��������ȷ·����ָ����Ŀ¼!\n\n����: D:\\ѹ��������","��ʾ",MB_OK|MB_ICONINFORMATION);
            EditFilePath->Text = strBackup;
            EditFilePath->SetFocus();
        }
        else
        {
//        char ch;
            ch = strTemp.c_str()[2];
            ilen = strTemp.Length();
            if(ch != '\\')
            {
                Application->MessageBox("��������ȷ·��!\n\n����: D:\\ѹ��������","��ʾ",MB_OK|MB_ICONINFORMATION);
                EditFilePath->Text = strBackup;
                EditFilePath->SetFocus();
            }
            else
            {
                strTemp = strTemp.SubString(4,ilen-3);
                iPosi = strTemp.Pos(":");
                strTemp = ExtractFileDrive(strTemp);
                if((strTemp != "")||(iPosi>0))
                {
                    Application->MessageBox("��������ȷ·��!\n\n����: D:\\ѹ��������","��ʾ",MB_OK|MB_ICONINFORMATION);
                    EditFilePath->Text = strBackup;
                    EditFilePath->SetFocus();
                }
            }
        }
    }
//    ch = strTemp.c_str()[ilen -1];
}
//---------------------------------------------------------------------------

void __fastcall TFormPath::EditFilePathEnter(TObject *Sender)
{
    strBackup = EditFilePath->Text;
}
//---------------------------------------------------------------------------


