object FormDirectory: TFormDirectory
  Left = 309
  Top = 105
  Width = 419
  Height = 470
  Caption = '����ļ���'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 6
    Top = 14
    Width = 72
    Height = 13
    Caption = '��ǰ�ļ��У�'
  end
  object EditCurrentDir: TEdit
    Left = 88
    Top = 8
    Width = 315
    Height = 21
    TabOrder = 0
    Text = 'EditCurrentDir'
  end
  object TreeView1: TTreeView
    Left = 6
    Top = 34
    Width = 399
    Height = 371
    Indent = 19
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 192
    Top = 412
    Width = 107
    Height = 25
    Caption = 'ȷ ��'
    ModalResult = 1
    TabOrder = 2
  end
  object BitBtn2: TBitBtn
    Left = 304
    Top = 412
    Width = 101
    Height = 25
    Caption = 'ȡ ��'
    TabOrder = 3
  end
  object Drive1: TDriveComboBox
    Left = 6
    Top = 412
    Width = 179
    Height = 19
    TabOrder = 4
    Visible = False
  end
end
