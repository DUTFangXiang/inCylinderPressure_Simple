object FormIndicator: TFormIndicator
  Left = 402
  Top = 294
  Width = 416
  Height = 95
  BorderIcons = []
  Caption = '���ݶ�д����ָʾ'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelCurrent: TLabel
    Left = 6
    Top = 14
    Width = 65
    Height = 13
    Caption = '��ǰ�ļ���'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object LabelAll: TLabel
    Left = 6
    Top = 42
    Width = 65
    Height = 13
    Caption = '�����ļ���'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object PBIN: TProgressBar
    Left = 72
    Top = 12
    Width = 331
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 0
  end
  object PBAll: TProgressBar
    Left = 72
    Top = 40
    Width = 331
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 1
  end
end
