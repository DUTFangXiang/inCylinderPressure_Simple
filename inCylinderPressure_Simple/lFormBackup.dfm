object FormBackup: TFormBackup
  Left = 313
  Top = 184
  Width = 307
  Height = 194
  Caption = '删除数据库内数据'
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = '宋体'
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
    Caption = '删除方式'
    ItemIndex = 0
    Items.Strings = (
      '按车号（所有缸）'
      '按时间'
      '全部数据')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 56
    Top = 134
    Width = 65
    Height = 21
    Caption = '确 定'
    ModalResult = 1
    TabOrder = 1
  end
  object Button2: TButton
    Left = 186
    Top = 133
    Width = 65
    Height = 21
    Caption = '取 消'
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
