object FormOption: TFormOption
  Left = 336
  Top = 93
  Width = 506
  Height = 386
  Caption = '选项设置'
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 498
    Height = 321
    ActivePage = TabSheet4
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = '使用单位'
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 490
        Height = 291
        Align = alClient
        Caption = ' 单位名称 '
        TabOrder = 0
        object EditUserName: TEdit
          Left = 8
          Top = 48
          Width = 407
          Height = 29
          Font.Charset = GB2312_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = '隶书'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = '数据保存'
      ImageIndex = 1
      object CheckBoxbSaveOrig: TCheckBox
        Left = 10
        Top = 20
        Width = 107
        Height = 17
        Caption = '保留原始数据'
        TabOrder = 0
      end
      object CheckBoxExcel: TCheckBox
        Left = 10
        Top = 52
        Width = 263
        Height = 17
        Caption = '数据分析结果时生成EXCEL报表'
        TabOrder = 1
      end
      object RadioGroupAnalysisMethod: TRadioGroup
        Left = 8
        Top = 88
        Width = 433
        Height = 81
        Caption = ' 数据分析方法 '
        ItemIndex = 0
        Items.Strings = (
          '定量分析（利用判断标准进行分析）'
          '定性分析（同一台车数据离散分析）')
        TabOrder = 2
      end
    end
    object TabSheet3: TTabSheet
      Caption = '机车参数'
      ImageIndex = 2
      object ComboBoxTrainType: TComboBox
        Left = 10
        Top = 16
        Width = 145
        Height = 23
        Style = csDropDownList
        ItemHeight = 15
        TabOrder = 0
        OnChange = ComboBoxTrainTypeChange
        Items.Strings = (
          '东风4A'
          '东风4B'
          '东风4C'
          '东风4D'
          '东风8B'
          '东风11'
          '东风5'
          '东风7'
          '东风7C'
          '其它A'
          '其它B')
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 50
        Width = 409
        Height = 187
        Caption = ' 柴油机参数 '
        TabOrder = 1
        object Label1: TLabel
          Left = 14
          Top = 28
          Width = 99
          Height = 15
          Caption = '气缸直径(m)：'
        end
        object Label2: TLabel
          Left = 14
          Top = 59
          Width = 99
          Height = 15
          Caption = '活塞行程(m)：'
        end
        object Label3: TLabel
          Left = 14
          Top = 91
          Width = 99
          Height = 15
          Caption = '连杆长度(m)：'
        end
        object Label4: TLabel
          Left = 14
          Top = 122
          Width = 60
          Height = 15
          Caption = '压缩比：'
        end
        object Label5: TLabel
          Left = 212
          Top = 24
          Width = 120
          Height = 15
          Caption = '进气门关闭角度：'
        end
        object Label6: TLabel
          Left = 212
          Top = 58
          Width = 120
          Height = 15
          Caption = '排气门开启角度：'
        end
        object Label7: TLabel
          Left = 212
          Top = 91
          Width = 120
          Height = 15
          Caption = '喷油泵供油角度：'
        end
        object EditDiameter: TEdit
          Left = 110
          Top = 22
          Width = 71
          Height = 23
          TabOrder = 0
          OnChange = EditDiameterChange
        end
        object EditStroke: TEdit
          Left = 110
          Top = 53
          Width = 71
          Height = 23
          TabOrder = 1
          OnChange = EditDiameterChange
        end
        object EditPodLength: TEdit
          Left = 110
          Top = 85
          Width = 71
          Height = 23
          TabOrder = 2
          OnChange = EditDiameterChange
        end
        object EditCRation: TEdit
          Left = 110
          Top = 116
          Width = 71
          Height = 23
          TabOrder = 3
          OnChange = EditDiameterChange
        end
        object EditInCloseAngle: TEdit
          Left = 330
          Top = 20
          Width = 71
          Height = 23
          TabOrder = 4
          OnChange = EditDiameterChange
        end
        object EditOutOpenAngle: TEdit
          Left = 330
          Top = 53
          Width = 71
          Height = 23
          TabOrder = 5
          OnChange = EditDiameterChange
        end
        object EditFuelSupplyAngle: TEdit
          Left = 330
          Top = 85
          Width = 71
          Height = 23
          TabOrder = 6
          OnChange = EditDiameterChange
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = ' 判断标准 '
      ImageIndex = 3
      object ComboBoxTrainTypeStandard: TComboBox
        Left = 10
        Top = 16
        Width = 145
        Height = 23
        Style = csDropDownList
        ItemHeight = 15
        TabOrder = 0
        OnChange = ComboBoxTrainTypeStandardChange
        Items.Strings = (
          '东风4A'
          '东风4B'
          '东风4C'
          '东风4D'
          '东风8B'
          '东风11'
          '东风5'
          '东风7'
          '东风7C'
          '其它A'
          '其它B')
      end
      object GroupBox3: TGroupBox
        Left = 8
        Top = 50
        Width = 477
        Height = 151
        Caption = ' 怠速时参数范围 '
        TabOrder = 1
        object Label8: TLabel
          Left = 14
          Top = 56
          Width = 75
          Height = 15
          Caption = '压缩压力：'
        end
        object Label9: TLabel
          Left = 14
          Top = 88
          Width = 105
          Height = 15
          Caption = '供油提前角度：'
        end
        object Label10: TLabel
          Left = 14
          Top = 120
          Width = 105
          Height = 15
          Caption = '燃烧开始角度：'
        end
        object Label11: TLabel
          Left = 146
          Top = 20
          Width = 45
          Height = 15
          Caption = '最小值'
        end
        object Label12: TLabel
          Left = 306
          Top = 22
          Width = 45
          Height = 15
          Caption = '最大值'
        end
        object EditCompressMin: TEdit
          Left = 144
          Top = 50
          Width = 71
          Height = 23
          TabOrder = 0
          OnChange = EditCompressMinChange
        end
        object EditOilAngleMin: TEdit
          Left = 144
          Top = 81
          Width = 71
          Height = 23
          TabOrder = 1
          OnChange = EditCompressMinChange
        end
        object EditCombustionAngleMin: TEdit
          Left = 144
          Top = 112
          Width = 71
          Height = 23
          TabOrder = 2
          OnChange = EditCompressMinChange
        end
        object EditCompressMax: TEdit
          Left = 290
          Top = 50
          Width = 71
          Height = 23
          TabOrder = 3
          OnChange = EditCompressMinChange
        end
        object EditOilAngleMax: TEdit
          Left = 290
          Top = 81
          Width = 71
          Height = 23
          TabOrder = 4
          OnChange = EditCompressMinChange
        end
        object EditCombustionAngleMax: TEdit
          Left = 290
          Top = 112
          Width = 71
          Height = 23
          TabOrder = 5
          OnChange = EditCompressMinChange
        end
      end
      object GroupBox4: TGroupBox
        Left = 8
        Top = 208
        Width = 477
        Height = 77
        Caption = ' 高压油管压力波数据分析门限值 '
        TabOrder = 2
        object Label13: TLabel
          Left = 96
          Top = 40
          Width = 376
          Height = 15
          Caption = '说明：压力波分析时计算结果大于此值后认为不再相似!!'
          Color = clYellow
          ParentColor = False
        end
        object EditDetectLevel: TEdit
          Left = 10
          Top = 32
          Width = 79
          Height = 23
          TabOrder = 0
          Text = '5.0'
          OnChange = EditDetectLevelChange
        end
      end
    end
    object TabSheet5: TTabSheet
      Caption = '车型配置'
      ImageIndex = 4
      object Label22: TLabel
        Left = 26
        Top = 28
        Width = 215
        Height = 15
        Caption = '车型编号："其它A"  对应 =-->'
      end
      object Label26: TLabel
        Left = 26
        Top = 54
        Width = 215
        Height = 15
        Caption = '车型编号："其它B"  对应 =-->'
        Visible = False
      end
      object Label30: TLabel
        Left = 20
        Top = 258
        Width = 414
        Height = 15
        Caption = '命名规则：由4到5位字母或数字组成；5位时最后一位应为字母'
        Color = clYellow
        ParentColor = False
      end
      object EditOtherA: TEdit
        Left = 260
        Top = 24
        Width = 121
        Height = 23
        TabOrder = 0
        OnChange = EditOtherAChange
      end
      object EditOtherB: TEdit
        Left = 260
        Top = 50
        Width = 121
        Height = 23
        TabOrder = 1
        Visible = False
        OnChange = EditOtherBChange
      end
      object ButtonRefreshTrainType: TButton
        Left = 260
        Top = 168
        Width = 121
        Height = 37
        Caption = '刷新机车信息'
        TabOrder = 2
        OnClick = ButtonRefreshTrainTypeClick
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 321
    Width = 498
    Height = 38
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 408
      Top = 8
      Width = 75
      Height = 25
      Caption = '确 定'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = '宋体'
      Font.Style = []
      ModalResult = 1
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 324
      Top = 8
      Width = 75
      Height = 25
      Caption = '取 消'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = '宋体'
      Font.Style = []
      ModalResult = 2
      ParentFont = False
      TabOrder = 1
    end
  end
end
