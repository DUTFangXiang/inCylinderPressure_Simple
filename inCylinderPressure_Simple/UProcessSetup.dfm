object FormProcessSetup: TFormProcessSetup
  Left = 224
  Top = 156
  Width = 557
  Height = 195
  Caption = '设置数据处理方法'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 178
    Top = 4
    Width = 141
    Height = 149
    Caption = '气缸压力处理方法'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ItemIndex = 2
    Items.Strings = (
      '七点光顺'
      'B样条滤波'
      '低通滤波'
      '带阻滤波'
      '逆滤波')
    ParentFont = False
    TabOrder = 0
  end
end
