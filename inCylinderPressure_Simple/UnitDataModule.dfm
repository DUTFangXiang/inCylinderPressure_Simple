object DM: TDM
  OldCreateOrder = False
  Left = 178
  Top = 222
  Height = 480
  Width = 989
  object ADOConnectionDataInfo: TADOConnection
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 14
    Top = 10
  end
  object ADOQueryTrainType: TADOQuery
    Connection = ADOConnectionDataInfo
    Parameters = <>
    Left = 248
    Top = 344
  end
  object ADODataSetDataInfo: TADODataSet
    Connection = ADOConnectionDataInfo
    CursorType = ctStatic
    CommandText = 'DataTable'
    CommandType = cmdTable
    Parameters = <>
    Left = 140
    Top = 6
    object ADODataSetDataInfoDataID: TAutoIncField
      FieldName = 'DataID'
    end
    object ADODataSetDataInfoTrainType: TWideStringField
      FieldName = 'TrainType'
      Size = 16
    end
    object ADODataSetDataInfoTrainNumber: TWideStringField
      FieldName = 'TrainNumber'
      Size = 8
    end
    object ADODataSetDataInfoDieselNumber: TSmallintField
      FieldName = 'DieselNumber'
    end
    object ADODataSetDataInfoMPerson: TWideStringField
      FieldName = 'MPerson'
    end
    object ADODataSetDataInfoMDate: TDateTimeField
      FieldName = 'MDate'
    end
    object ADODataSetDataInfoAnalysisResult: TWideStringField
      FieldName = 'AnalysisResult'
      Size = 50
    end
    object ADODataSetDataInfobCombustion: TWideStringField
      FieldName = 'bCombustion'
      Size = 10
    end
    object ADODataSetDataInfoDieselSpeed: TWideStringField
      FieldName = 'DieselSpeed'
      Size = 10
    end
    object ADODataSetDataInfoPressureMax: TWideStringField
      FieldName = 'PressureMax'
      Size = 10
    end
    object ADODataSetDataInfoDPDFMax: TWideStringField
      FieldName = 'DPDFMax'
      Size = 10
    end
    object ADODataSetDataInfoCombustionPosi: TWideStringField
      FieldName = 'CombustionPosi'
      Size = 10
    end
    object ADODataSetDataInfoCombustionPeriod: TWideStringField
      FieldName = 'CombustionPeriod'
      Size = 10
    end
    object ADODataSetDataInfoDHDFMax: TWideStringField
      FieldName = 'DHDFMax'
      Size = 10
    end
    object ADODataSetDataInfoHeatAll: TWideStringField
      FieldName = 'HeatAll'
      Size = 10
    end
    object ADODataSetDataInfoCPower: TWideStringField
      FieldName = 'CPower'
      Size = 10
    end
    object ADODataSetDataInfoOilPosi: TWideStringField
      FieldName = 'OilPosi'
      Size = 10
    end
    object ADODataSetDataInfoWavePeriod: TWideStringField
      FieldName = 'WavePeriod'
      Size = 10
    end
    object ADODataSetDataInfoWaveCoef: TWideStringField
      FieldName = 'WaveCoef'
      Size = 10
    end
    object ADODataSetDataInfoFileName: TWideStringField
      FieldName = 'FileName'
      Size = 100
    end
    object ADODataSetDataInfofP0: TWideStringField
      FieldName = 'fP0'
      Size = 10
    end
    object ADODataSetDataInfofOilMax: TWideStringField
      FieldName = 'fOilMax'
      Size = 50
    end
  end
  object DataSourceDataInfo: TDataSource
    DataSet = ADODataSetDataInfo
    Left = 142
    Top = 50
  end
  object ADOTable1: TADOTable
    Connection = ADOConnectionDataInfo
    CursorType = ctStatic
    TableName = 'TypeInfo'
    Left = 342
    Top = 6
    object ADOTable1ID: TAutoIncField
      FieldName = 'ID'
    end
    object ADOTable1DieselType: TWideStringField
      FieldName = 'DieselType'
    end
    object ADOTable1DCylinderDiameter: TFloatField
      FieldName = 'DCylinderDiameter'
    end
    object ADOTable1DPistonStrock: TIntegerField
      FieldName = 'DPistonStrock'
    end
    object ADOTable1DPodLength: TFloatField
      FieldName = 'DPodLength'
    end
    object ADOTable1DCompressRatio: TFloatField
      FieldName = 'DCompressRatio'
    end
    object ADOTable1DCylinderNum: TIntegerField
      FieldName = 'DCylinderNum'
    end
    object ADOTable1DStrockNum: TIntegerField
      FieldName = 'DStrockNum'
    end
    object ADOTable1DInletOpen: TFloatField
      FieldName = 'DInletOpen'
    end
    object ADOTable1DInletClose: TFloatField
      FieldName = 'DInletClose'
    end
    object ADOTable1DOutletOpen: TFloatField
      FieldName = 'DOutletOpen'
    end
    object ADOTable1DOutletClose: TFloatField
      FieldName = 'DOutletClose'
    end
  end
  object ADOQueryDate: TADOQuery
    Connection = ADOConnectionDataInfo
    Parameters = <>
    Left = 244
    Top = 136
  end
  object ADOQueryTrainNumber: TADOQuery
    Connection = ADOConnectionDataInfo
    Parameters = <>
    Left = 248
    Top = 298
  end
  object ADOQuerySpeed: TADOQuery
    Connection = ADOConnectionDataInfo
    Parameters = <>
    Left = 248
    Top = 186
  end
  object ADOQueryTemp: TADOQuery
    Connection = ADOConnectionDataInfo
    Parameters = <>
    Left = 248
    Top = 240
  end
  object DataSourcePipe: TDataSource
    DataSet = ADODataSetPipe
    Left = 244
    Top = 50
  end
  object ADODataSetPipe: TADODataSet
    Connection = ADOConnectionDataInfo
    CursorType = ctStatic
    CommandText = 'PipeInfo'
    CommandType = cmdTable
    Parameters = <
      item
        Name = 'LowSpeed'
        DataType = ftLargeint
        Value = Null
      end
      item
        Name = 'HighSpeed'
        DataType = ftLargeint
        Value = Null
      end>
    Left = 242
    Top = 6
    object ADODataSetPipePipeID: TAutoIncField
      FieldName = 'PipeID'
    end
    object ADODataSetPipeTrainType: TWideStringField
      FieldName = 'TrainType'
      Size = 10
    end
    object ADODataSetPipeDieselSpeed: TFloatField
      FieldName = 'DieselSpeed'
    end
    object ADODataSetPipeFaultType: TWideStringField
      FieldName = 'FaultType'
      Size = 50
    end
    object ADODataSetPipeWavePeak: TWideStringField
      FieldName = 'WavePeak'
      Size = 10
    end
    object ADODataSetPipeWavePeriod: TWideStringField
      FieldName = 'WavePeriod'
      Size = 10
    end
    object ADODataSetPipeWaveCoef: TWideStringField
      FieldName = 'WaveCoef'
      Size = 10
    end
    object ADODataSetPipe_PipeData: TBlobField
      FieldName = 'PipeData'
    end
    object ADODataSetPipeTrainNumber: TWideStringField
      FieldName = 'TrainNumber'
      Size = 6
    end
    object ADODataSetPipeDieselNumber: TWideStringField
      FieldName = 'DieselNumber'
      Size = 4
    end
    object ADODataSetPipeMDate: TDateTimeField
      FieldName = 'MDate'
    end
  end
  object DataSource2: TDataSource
    DataSet = ADOTable2
    Left = 414
    Top = 65
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 412
    Top = 8
  end
  object ADOTable2: TADOTable
    Connection = ADOConnectionDataInfo
    TableName = #20154#21592#20449#24687
    Left = 344
    Top = 61
    object ADOTable2ID: TAutoIncField
      FieldName = #20154#21592'ID'
    end
    object ADOTable2DSDesigner: TWideStringField
      FieldName = #22995#21517
    end
    object ADOTable2DSDesigner2: TWideStringField
      FieldName = #24615#21035
      Size = 6
    end
    object ADOTable2DSDesigner3: TWideStringField
      FieldName = #24180#40836
      Size = 4
    end
    object ADOTable2DSDesigner4: TWideStringField
      FieldName = #32844#31216
    end
    object ADOTablePersonPic: TBlobField
      FieldName = #29031#29255
    end
  end
  object ADOTableMInfo: TADOTable
    Connection = ADOConnectionDataInfo
    TableName = 'MeasureInfo'
    Left = 144
    Top = 102
  end
end
