object FormFileInfo: TFormFileInfo
  Left = 90
  Top = 110
  Width = 593
  Height = 355
  Caption = 'FormFileInfo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 72
    Width = 185
    Height = 249
    Caption = ' 机车参数 '
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 49
      Height = 13
      AutoSize = False
      Caption = '车型:'
    end
    object Label2: TLabel
      Left = 8
      Top = 80
      Width = 45
      Height = 13
      AutoSize = False
      Caption = '车号:'
    end
    object Label3: TLabel
      Left = 8
      Top = 136
      Width = 53
      Height = 13
      AutoSize = False
      Caption = '缸号:'
    end
    object Label6: TLabel
      Left = 8
      Top = 192
      Width = 93
      Height = 13
      AutoSize = False
      Caption = ' 柴油机转速: '
    end
    object PanelTrainType: TPanel
      Left = 8
      Top = 40
      Width = 169
      Height = 33
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object PanelTrainNum: TPanel
      Left = 8
      Top = 96
      Width = 169
      Height = 33
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object PanelDieselNum: TPanel
      Left = 8
      Top = 152
      Width = 169
      Height = 33
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object PanelfEn: TPanel
      Left = 8
      Top = 208
      Width = 169
      Height = 33
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 8
    Width = 569
    Height = 57
    Caption = ' 文件名 '
    TabOrder = 1
    object PanelFileName: TPanel
      Left = 8
      Top = 16
      Width = 553
      Height = 33
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
  end
  object GroupBox3: TGroupBox
    Left = 200
    Top = 72
    Width = 185
    Height = 249
    Caption = ' 采样设置 '
    TabOrder = 2
    object Label4: TLabel
      Left = 8
      Top = 32
      Width = 61
      Height = 13
      AutoSize = False
      Caption = '采样频率: '
    end
    object Label5: TLabel
      Left = 8
      Top = 125
      Width = 65
      Height = 13
      AutoSize = False
      Caption = '采集次数:'
    end
    object LabelSampleLen: TLabel
      Left = 8
      Top = 156
      Width = 61
      Height = 13
      AutoSize = False
      Caption = '数据长度:'
    end
    object Label9: TLabel
      Left = 8
      Top = 187
      Width = 61
      Height = 13
      AutoSize = False
      Caption = '灵敏度:'
    end
    object Label10: TLabel
      Left = 8
      Top = 218
      Width = 49
      Height = 13
      AutoSize = False
      Caption = '增益:'
    end
    object Label12: TLabel
      Left = 8
      Top = 63
      Width = 65
      Height = 13
      AutoSize = False
      Caption = '低通频率:'
    end
    object Label13: TLabel
      Left = 8
      Top = 94
      Width = 65
      Height = 13
      AutoSize = False
      Caption = '低通频率:'
    end
    object PanelSampleFre: TPanel
      Left = 72
      Top = 18
      Width = 105
      Height = 27
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object PanelSampleNum: TPanel
      Left = 72
      Top = 113
      Width = 105
      Height = 27
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object PanelSampleLen: TPanel
      Left = 72
      Top = 145
      Width = 105
      Height = 27
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object PanelSensitivity: TPanel
      Left = 72
      Top = 176
      Width = 105
      Height = 27
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object PanelGain: TPanel
      Left = 72
      Top = 208
      Width = 105
      Height = 27
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object PanelCutoffFreq: TPanel
      Left = 72
      Top = 50
      Width = 105
      Height = 27
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
    object PanelCutoffFreq1: TPanel
      Left = 72
      Top = 81
      Width = 105
      Height = 27
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
  end
  object GroupBox4: TGroupBox
    Left = 392
    Top = 72
    Width = 185
    Height = 249
    Caption = ' 测试结果 '
    TabOrder = 3
    object Label7: TLabel
      Left = 8
      Top = 24
      Width = 73
      Height = 13
      AutoSize = False
      Caption = '压力峰值:'
    end
    object Label8: TLabel
      Left = 8
      Top = 80
      Width = 81
      Height = 13
      AutoSize = False
      Caption = '峰值偏差:'
    end
    object Label11: TLabel
      Left = 8
      Top = 144
      Width = 89
      Height = 13
      AutoSize = False
      Caption = '偏差百分比:'
    end
    object PanelfCPMax: TPanel
      Left = 8
      Top = 40
      Width = 169
      Height = 33
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object PanelfCPMin: TPanel
      Left = 8
      Top = 96
      Width = 169
      Height = 33
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object PanelPercentage: TPanel
      Left = 8
      Top = 160
      Width = 169
      Height = 33
      BevelInner = bvLowered
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
end
