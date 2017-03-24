object FormDeleteData: TFormDeleteData
  Left = 244
  Top = 184
  Width = 313
  Height = 262
  Caption = '数据库删除方式设置'
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
    Caption = ' 删除时间 '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '宋体'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      '一个月以前'
      '三个月以前'
      '半年以前'
      '一年以前'
      '全部删除'
      '定制时间')
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
    Font.Name = '宋体'
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
    Caption = '确 定'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '宋体'
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
    Caption = '取 消'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '宋体'
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 3
  end
end
