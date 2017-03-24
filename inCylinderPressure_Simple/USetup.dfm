object FormSetup: TFormSetup
  Left = 214
  Top = 237
  Width = 568
  Height = 118
  Caption = 'FormSetup'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 16
    Top = 22
    Width = 109
    Height = 39
    Caption = '进气线颜色'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Panel1Click
  end
  object Panel2: TPanel
    Left = 125
    Top = 22
    Width = 109
    Height = 39
    Caption = '进气线颜色'
    Color = clMaroon
    Font.Charset = GB2312_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Panel2Click
  end
  object Panel3: TPanel
    Left = 234
    Top = 22
    Width = 109
    Height = 39
    Caption = '进气线颜色'
    Color = clRed
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Panel3Click
  end
  object Panel4: TPanel
    Left = 343
    Top = 22
    Width = 109
    Height = 39
    Caption = '进气线颜色'
    Color = clWindowText
    Font.Charset = GB2312_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Panel4Click
  end
  object Button1: TButton
    Left = 476
    Top = 14
    Width = 75
    Height = 25
    Caption = '确 定'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    TabOrder = 4
  end
  object Button2: TButton
    Left = 476
    Top = 42
    Width = 75
    Height = 25
    Caption = '取 消'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 5
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 454
    Top = 6
  end
end
