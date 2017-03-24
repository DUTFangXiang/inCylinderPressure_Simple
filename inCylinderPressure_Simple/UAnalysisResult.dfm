object FormAnalysisResult: TFormAnalysisResult
  Left = 146
  Top = 59
  Width = 748
  Height = 682
  Caption = '数据分析结果'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 381
    Width = 740
    Height = 3
    Cursor = crVSplit
    Align = alTop
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 384
    Width = 740
    Height = 271
    Align = alClient
    Caption = ' 结论 '
    TabOrder = 0
    object MemoResult: TMemo
      Left = 2
      Top = 15
      Width = 736
      Height = 254
      Align = alClient
      TabOrder = 0
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 740
    Height = 381
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 740
      Height = 33
      Align = alTop
      BevelInner = bvLowered
      TabOrder = 0
      object Label1: TLabel
        Left = 8
        Top = 10
        Width = 36
        Height = 13
        Caption = '车型：'
      end
      object Label2: TLabel
        Left = 116
        Top = 10
        Width = 36
        Height = 13
        Caption = '车号：'
      end
      object Label3: TLabel
        Left = 215
        Top = 10
        Width = 60
        Height = 13
        Caption = '测量时间：'
      end
      object Label4: TLabel
        Left = 385
        Top = 10
        Width = 36
        Height = 13
        Caption = '转速：'
      end
      object Label5: TLabel
        Left = 535
        Top = 12
        Width = 60
        Height = 13
        Caption = '指示功率：'
      end
      object PanelTrainType: TPanel
        Left = 43
        Top = 6
        Width = 62
        Height = 21
        BevelInner = bvLowered
        Color = clNavy
        Font.Charset = ANSI_CHARSET
        Font.Color = clAqua
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object PanelTrainNumber: TPanel
        Left = 153
        Top = 6
        Width = 53
        Height = 21
        BevelInner = bvLowered
        Color = clNavy
        Font.Charset = ANSI_CHARSET
        Font.Color = clAqua
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object PanelMTime: TPanel
        Left = 272
        Top = 6
        Width = 101
        Height = 21
        BevelInner = bvLowered
        Color = clNavy
        Font.Charset = ANSI_CHARSET
        Font.Color = clAqua
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object PanelSpeed: TPanel
        Left = 418
        Top = 6
        Width = 99
        Height = 21
        BevelInner = bvLowered
        Color = clNavy
        Font.Charset = ANSI_CHARSET
        Font.Color = clAqua
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object PanelPower: TPanel
        Left = 594
        Top = 8
        Width = 81
        Height = 21
        BevelInner = bvLowered
        Color = clNavy
        Font.Charset = ANSI_CHARSET
        Font.Color = clAqua
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
    end
    object GroupBox1: TGroupBox
      Left = 0
      Top = 33
      Width = 740
      Height = 348
      Align = alClient
      Caption = ' 各缸参数 '
      TabOrder = 1
      object StringGridParams: TStringGrid
        Left = 2
        Top = 15
        Width = 736
        Height = 331
        Align = alClient
        Color = clInfoBk
        ColCount = 14
        DefaultColWidth = 50
        DefaultRowHeight = 18
        RowCount = 2
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
    end
  end
end
