object FormPath: TFormPath
  Left = 212
  Top = 171
  Width = 391
  Height = 146
  BorderIcons = []
  Caption = '设置文件保存路径'
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = '宋体'
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
    Caption = '请输入保存气缸压力和高压油管压力波数据文件路径：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '宋体'
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
    Caption = '确  定'
    ModalResult = 1
    TabOrder = 1
  end
  object Button2: TButton
    Left = 224
    Top = 78
    Width = 97
    Height = 25
    Caption = '取  消'
    ModalResult = 2
    TabOrder = 2
  end
end
