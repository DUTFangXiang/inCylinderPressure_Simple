object FormDeleteData: TFormDeleteData
  Left = 244
  Top = 184
  Width = 313
  Height = 262
  Caption = '���ݿ�ɾ����ʽ����'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroupDeleteMode: TRadioGroup
    Left = 12
    Top = 12
    Width = 281
    Height = 175
    Caption = ' ɾ��ʱ�� '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      'һ������ǰ'
      '��������ǰ'
      '������ǰ'
      'һ����ǰ'
      'ȫ��ɾ��'
      '����ʱ��')
    ParentFont = False
    TabOrder = 0
  end
  object DateTimePicker1: TDateTimePicker
    Left = 108
    Top = 156
    Width = 173
    Height = 24
    CalAlignment = dtaLeft
    Date = 38209.8984298958
    Time = 38209.8984298958
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = '����'
    Font.Style = []
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 1
    OnChange = DateTimePicker1Change
  end
  object Button1: TButton
    Left = 196
    Top = 200
    Width = 75
    Height = 25
    Caption = 'ȷ ��'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    TabOrder = 2
  end
  object Button2: TButton
    Left = 32
    Top = 202
    Width = 75
    Height = 25
    Caption = 'ȡ ��'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 3
  end
end
