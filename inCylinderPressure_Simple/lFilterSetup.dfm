object FormFilterSetup: TFormFilterSetup
  Left = 218
  Top = 188
  Width = 575
  Height = 364
  Caption = '�˲������á�'
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
  object Label5: TLabel
    Left = 184
    Top = 200
    Width = 83
    Height = 15
    Caption = '�˲�������:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 8
    Top = 264
    Width = 377
    Height = 10
    Shape = bsBottomLine
  end
  object Label6: TLabel
    Left = 8
    Top = 240
    Width = 145
    Height = 15
    Caption = '������Ƶ�� (Hz)��'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 128
    Top = 280
    Width = 113
    Height = 33
    Caption = 'ȷ����'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    TabOrder = 0
  end
  object Button2: TButton
    Left = 248
    Top = 280
    Width = 121
    Height = 33
    Caption = 'ȡ����'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 160
    Width = 137
    Height = 57
    Caption = '����������'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object ComboBoxWindowChoice: TComboBox
      Left = 8
      Top = 24
      Width = 121
      Height = 23
      Style = csDropDownList
      ItemHeight = 15
      TabOrder = 0
      Items.Strings = (
        '���δ�'
        '������'
        '������'
        '����������')
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 88
    Width = 137
    Height = 57
    Caption = '�˲�������'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object ComboBoxFilterKind: TComboBox
      Left = 8
      Top = 24
      Width = 121
      Height = 23
      Style = csDropDownList
      ItemHeight = 15
      TabOrder = 0
      OnChange = ComboBoxFilterKindChange
      Items.Strings = (
        '��ͨ�˲���'
        '��ͨ�˲���'
        '��ͨ�˲���'
        '�����˲���')
    end
  end
  object RadioGroupMethod: TRadioGroup
    Left = 8
    Top = 8
    Width = 137
    Height = 65
    Caption = '�˲������÷�ʽ'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      '������'
      'ϸ������')
    ParentFont = False
    TabOrder = 4
    OnClick = RadioGroupMethodClick
  end
  object GroupBox3: TGroupBox
    Left = 160
    Top = 8
    Width = 225
    Height = 153
    Caption = 'Ƶ������ (hz)'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    object Label1: TLabel
      Left = 8
      Top = 32
      Width = 105
      Height = 15
      Caption = '��Ƶ��ֹƵ�ʣ�'
    end
    object Label2: TLabel
      Left = 8
      Top = 64
      Width = 105
      Height = 15
      Caption = '��Ƶ����Ƶ�ʣ�'
    end
    object Label3: TLabel
      Left = 8
      Top = 96
      Width = 105
      Height = 15
      Caption = '��Ƶ��ֹƵ�ʣ�'
    end
    object Label4: TLabel
      Left = 8
      Top = 128
      Width = 105
      Height = 15
      Caption = '��Ƶ����Ƶ�ʣ�'
    end
    object EditFPL: TEdit
      Left = 112
      Top = 24
      Width = 97
      Height = 23
      TabOrder = 0
      Text = '0.0'
      OnExit = EditFPLExit
    end
    object EditFSL: TEdit
      Left = 112
      Top = 56
      Width = 97
      Height = 23
      Enabled = False
      TabOrder = 1
      Text = '0.0'
      OnExit = EditFSLExit
    end
    object EditFPH: TEdit
      Left = 112
      Top = 88
      Width = 97
      Height = 23
      TabOrder = 2
      Text = '0.0'
      OnExit = EditFPHExit
    end
    object EditFSH: TEdit
      Left = 112
      Top = 120
      Width = 97
      Height = 23
      Enabled = False
      TabOrder = 3
      Text = '0.0'
      OnExit = EditFSHExit
    end
  end
  object CheckBoxSelf: TCheckBox
    Left = 160
    Top = 168
    Width = 209
    Height = 17
    Caption = '�Զ������˲�������'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = CheckBoxSelfClick
  end
  object EditFilterOrder: TEdit
    Left = 272
    Top = 192
    Width = 97
    Height = 21
    TabOrder = 7
    Text = '55'
  end
  object Button3: TButton
    Left = 248
    Top = 232
    Width = 121
    Height = 33
    Caption = 'У����'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = Button3Click
  end
  object GroupBox4: TGroupBox
    Left = 392
    Top = 8
    Width = 161
    Height = 313
    Caption = '������'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    object MemoResult: TMemo
      Left = 2
      Top = 17
      Width = 157
      Height = 294
      Align = alClient
      ScrollBars = ssBoth
      TabOrder = 0
    end
  end
  object ButtonCalculation: TButton
    Left = 8
    Top = 280
    Width = 105
    Height = 33
    Caption = '�ơ���'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = ButtonCalculationClick
  end
  object EditMaxFrequency: TEdit
    Left = 154
    Top = 236
    Width = 83
    Height = 21
    TabOrder = 11
    Text = '16000'
  end
end
