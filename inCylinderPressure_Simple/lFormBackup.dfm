object FormBackup: TFormBackup
  Left = 313
  Top = 184
  Width = 307
  Height = 194
  Caption = 'ɾ�����ݿ�������'
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = '����'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = FormActivate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroupBackMode: TRadioGroup
    Left = 9
    Top = 12
    Width = 272
    Height = 111
    Caption = 'ɾ����ʽ'
    ItemIndex = 0
    Items.Strings = (
      '�����ţ����иף�'
      '��ʱ��'
      'ȫ������')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 56
    Top = 134
    Width = 65
    Height = 21
    Caption = 'ȷ ��'
    ModalResult = 1
    TabOrder = 1
  end
  object Button2: TButton
    Left = 186
    Top = 133
    Width = 65
    Height = 21
    Caption = 'ȡ ��'
    ModalResult = 2
    TabOrder = 2
  end
  object ComboBoxTrainNum: TComboBox
    Left = 182
    Top = 30
    Width = 91
    Height = 21
    ItemHeight = 13
    TabOrder = 3
  end
  object DTPDate: TDateTimePicker
    Left = 88
    Top = 64
    Width = 186
    Height = 21
    CalAlignment = dtaLeft
    Date = 38414.5767364699
    Time = 38414.5767364699
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 4
  end
end
