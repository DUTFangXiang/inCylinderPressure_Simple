object FormPath: TFormPath
  Left = 212
  Top = 171
  Width = 391
  Height = 146
  BorderIcons = []
  Caption = '�����ļ�����·��'
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = '����'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 8
    Top = 14
    Width = 360
    Height = 15
    Caption = '�����뱣������ѹ���͸�ѹ�͹�ѹ���������ļ�·����'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object EditFilePath: TEdit
    Left = 18
    Top = 38
    Width = 355
    Height = 23
    TabOrder = 0
    OnEnter = EditFilePathEnter
    OnExit = EditFilePathExit
  end
  object Button1: TButton
    Left = 68
    Top = 78
    Width = 97
    Height = 25
    Caption = 'ȷ  ��'
    ModalResult = 1
    TabOrder = 1
  end
  object Button2: TButton
    Left = 224
    Top = 78
    Width = 97
    Height = 25
    Caption = 'ȡ  ��'
    ModalResult = 2
    TabOrder = 2
  end
end
