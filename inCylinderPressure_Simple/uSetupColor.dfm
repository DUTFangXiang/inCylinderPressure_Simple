object FormSetupColor: TFormSetupColor
  Left = 339
  Top = 196
  Width = 483
  Height = 420
  Caption = '������ɫ'
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
  object PanelBackground: TPanel
    Left = 164
    Top = 2
    Width = 305
    Height = 309
    BevelOuter = bvNone
    Color = clHighlightText
    TabOrder = 0
    OnClick = PanelBackgroundClick
    object LabelText: TLabel
      Left = 18
      Top = 284
      Width = 64
      Height = 16
      Caption = '��ͼʾ��'
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = '����'
      Font.Style = []
      ParentFont = False
      Transparent = True
      OnClick = LabelTextClick
    end
    object Image1: TImage
      Left = 26
      Top = 6
      Width = 269
      Height = 265
      OnClick = Image1Click
    end
  end
  object Button1: TButton
    Left = 204
    Top = 358
    Width = 120
    Height = 25
    Caption = 'ȷ ��'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    TabOrder = 1
  end
  object Button2: TButton
    Left = 336
    Top = 358
    Width = 120
    Height = 25
    Caption = 'ȡ ��'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 18
    Top = 318
    Width = 110
    Height = 35
    BevelInner = bvLowered
    Caption = '������ɫ'
    Color = clBtnText
    Font.Charset = GB2312_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Panel1Click
  end
  object Panel2: TPanel
    Left = 128
    Top = 318
    Width = 110
    Height = 35
    BevelInner = bvLowered
    Caption = 'ѹ����ɫ'
    Color = clGreen
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Panel2Click
  end
  object Panel3: TPanel
    Left = 238
    Top = 318
    Width = 110
    Height = 35
    BevelInner = bvLowered
    Caption = 'ȼ����ɫ'
    Color = clRed
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Panel3Click
  end
  object Panel4: TPanel
    Left = 348
    Top = 318
    Width = 110
    Height = 35
    BevelInner = bvLowered
    Caption = '������ɫ'
    Color = clBlack
    Font.Charset = GB2312_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Panel4Click
  end
  object Button3: TButton
    Left = 18
    Top = 358
    Width = 109
    Height = 25
    Caption = 'ȱʡ��ɫ'
    TabOrder = 7
    OnClick = Button3Click
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 2
    Width = 155
    Height = 311
    Caption = ' ������ɫ '
    TabOrder = 8
    object Label1: TLabel
      Left = 12
      Top = 20
      Width = 30
      Height = 13
      Caption = '��1��'
    end
    object Label2: TLabel
      Left = 12
      Top = 272
      Width = 36
      Height = 13
      Caption = '��15��'
    end
    object Label3: TLabel
      Left = 12
      Top = 56
      Width = 30
      Height = 13
      Caption = '��3��'
    end
    object Label4: TLabel
      Left = 12
      Top = 38
      Width = 30
      Height = 13
      Caption = '��2��'
    end
    object Label5: TLabel
      Left = 12
      Top = 74
      Width = 30
      Height = 13
      Caption = '��4��'
    end
    object Label6: TLabel
      Left = 12
      Top = 92
      Width = 30
      Height = 13
      Caption = '��5��'
    end
    object Label7: TLabel
      Left = 12
      Top = 110
      Width = 30
      Height = 13
      Caption = '��6��'
    end
    object Label8: TLabel
      Left = 12
      Top = 128
      Width = 30
      Height = 13
      Caption = '��7��'
    end
    object Label9: TLabel
      Left = 12
      Top = 146
      Width = 30
      Height = 13
      Caption = '��8��'
    end
    object Label10: TLabel
      Left = 12
      Top = 164
      Width = 30
      Height = 13
      Caption = '��9��'
    end
    object Label11: TLabel
      Left = 12
      Top = 182
      Width = 36
      Height = 13
      Caption = '��10��'
    end
    object Label12: TLabel
      Left = 12
      Top = 200
      Width = 36
      Height = 13
      Caption = '��11��'
    end
    object Label13: TLabel
      Left = 12
      Top = 218
      Width = 36
      Height = 13
      Caption = '��12��'
    end
    object Label14: TLabel
      Left = 12
      Top = 236
      Width = 36
      Height = 13
      Caption = '��13��'
    end
    object Label15: TLabel
      Left = 12
      Top = 254
      Width = 36
      Height = 13
      Caption = '��14��'
    end
    object Label16: TLabel
      Left = 12
      Top = 290
      Width = 36
      Height = 13
      Caption = '��16��'
    end
    object PanelCC00: TPanel
      Left = 52
      Top = 16
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 0
      OnClick = PanelCC00Click
    end
    object PanelCC01: TPanel
      Tag = 1
      Left = 52
      Top = 34
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 1
      OnClick = PanelCC00Click
    end
    object PanelCC02: TPanel
      Tag = 2
      Left = 52
      Top = 52
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 2
      OnClick = PanelCC00Click
    end
    object PanelCC03: TPanel
      Tag = 3
      Left = 52
      Top = 70
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 3
      OnClick = PanelCC00Click
    end
    object PanelCC04: TPanel
      Tag = 4
      Left = 52
      Top = 89
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 4
      OnClick = PanelCC00Click
    end
    object PanelCC05: TPanel
      Tag = 5
      Left = 52
      Top = 107
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 5
      OnClick = PanelCC00Click
    end
    object PanelCC06: TPanel
      Tag = 6
      Left = 52
      Top = 125
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 6
      OnClick = PanelCC00Click
    end
    object PanelCC07: TPanel
      Tag = 7
      Left = 52
      Top = 143
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 7
      OnClick = PanelCC00Click
    end
    object PanelCC08: TPanel
      Tag = 8
      Left = 52
      Top = 161
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 8
      OnClick = PanelCC00Click
    end
    object PanelCC09: TPanel
      Tag = 9
      Left = 52
      Top = 179
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 9
      OnClick = PanelCC00Click
    end
    object PanelCC10: TPanel
      Tag = 10
      Left = 52
      Top = 197
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 10
      OnClick = PanelCC00Click
    end
    object PanelCC11: TPanel
      Tag = 11
      Left = 52
      Top = 215
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 11
      OnClick = PanelCC00Click
    end
    object PanelCC12: TPanel
      Tag = 12
      Left = 52
      Top = 234
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 12
      OnClick = PanelCC00Click
    end
    object PanelCC13: TPanel
      Tag = 13
      Left = 52
      Top = 252
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 13
      OnClick = PanelCC00Click
    end
    object PanelCC14: TPanel
      Tag = 14
      Left = 52
      Top = 270
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 14
      OnClick = PanelCC00Click
    end
    object PanelCC15: TPanel
      Tag = 15
      Left = 52
      Top = 288
      Width = 90
      Height = 17
      Alignment = taLeftJustify
      TabOrder = 15
      OnClick = PanelCC00Click
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 380
    Top = 34
  end
end
