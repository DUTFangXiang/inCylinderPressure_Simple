object FormTrainSelection: TFormTrainSelection
  Left = 83
  Top = 123
  Width = 820
  Height = 361
  Caption = '���������ʾ����ѡ����Ҫ����Ļ���'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 732
    Top = 12
    Width = 75
    Height = 35
    Caption = 'ȷ��'
    ModalResult = 1
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 732
    Top = 52
    Width = 75
    Height = 35
    Caption = 'ȡ��'
    ModalResult = 2
    TabOrder = 1
  end
  object GroupBoxMain: TGroupBox
    Left = 6
    Top = 4
    Width = 717
    Height = 321
    Caption = ' �������������б� '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
end
