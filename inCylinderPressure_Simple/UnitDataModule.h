//---------------------------------------------------------------------------

#ifndef UnitDataModuleH
#define UnitDataModuleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
    TADOConnection *ADOConnectionDataInfo;
    TADOQuery *ADOQueryTrainType;
    TADODataSet *ADODataSetDataInfo;
    TDataSource *DataSourceDataInfo;
    TADOTable *ADOTable1;
    TAutoIncField *ADOTable1ID;
    TWideStringField *ADOTable1DieselType;
    TFloatField *ADOTable1DCylinderDiameter;
    TIntegerField *ADOTable1DPistonStrock;
    TFloatField *ADOTable1DPodLength;
    TFloatField *ADOTable1DCompressRatio;
    TIntegerField *ADOTable1DCylinderNum;
    TIntegerField *ADOTable1DStrockNum;
    TFloatField *ADOTable1DInletOpen;
    TFloatField *ADOTable1DInletClose;
    TFloatField *ADOTable1DOutletOpen;
    TFloatField *ADOTable1DOutletClose;
    TADOQuery *ADOQueryDate;
    TADOQuery *ADOQueryTrainNumber;
    TADOQuery *ADOQuerySpeed;
    TADOQuery *ADOQueryTemp;
    TDataSource *DataSourcePipe;
    TADODataSet *ADODataSetPipe;
    TDataSource *DataSource2;
    TDataSource *DataSource1;
    TADOTable *ADOTable2;
    TAutoIncField *ADOTable2ID;
    TWideStringField *ADOTable2DSDesigner;
    TWideStringField *ADOTable2DSDesigner2;
    TWideStringField *ADOTable2DSDesigner3;
    TWideStringField *ADOTable2DSDesigner4;
    TBlobField *ADOTablePersonPic;
    TAutoIncField *ADODataSetPipePipeID;
    TWideStringField *ADODataSetPipeTrainType;
    TWideStringField *ADODataSetPipeFaultType;
    TBlobField *ADODataSetPipe_PipeData;
    TWideStringField *ADODataSetPipeWavePeak;
    TWideStringField *ADODataSetPipeWavePeriod;
    TWideStringField *ADODataSetPipeWaveCoef;
    TWideStringField *ADODataSetPipeTrainNumber;
    TWideStringField *ADODataSetPipeDieselNumber;
    TDateTimeField *ADODataSetPipeMDate;
    TADOTable *ADOTableMInfo;
    TAutoIncField *ADODataSetDataInfoDataID;
    TWideStringField *ADODataSetDataInfoTrainType;
    TWideStringField *ADODataSetDataInfoTrainNumber;
    TSmallintField *ADODataSetDataInfoDieselNumber;
    TWideStringField *ADODataSetDataInfoMPerson;
    TDateTimeField *ADODataSetDataInfoMDate;
    TWideStringField *ADODataSetDataInfoAnalysisResult;
    TWideStringField *ADODataSetDataInfobCombustion;
    TWideStringField *ADODataSetDataInfoDieselSpeed;
    TWideStringField *ADODataSetDataInfoPressureMax;
    TWideStringField *ADODataSetDataInfoDPDFMax;
    TWideStringField *ADODataSetDataInfoCombustionPosi;
    TWideStringField *ADODataSetDataInfoCombustionPeriod;
    TWideStringField *ADODataSetDataInfoDHDFMax;
    TWideStringField *ADODataSetDataInfoHeatAll;
    TWideStringField *ADODataSetDataInfoCPower;
    TWideStringField *ADODataSetDataInfoOilPosi;
    TWideStringField *ADODataSetDataInfoWavePeriod;
    TWideStringField *ADODataSetDataInfoWaveCoef;
    TWideStringField *ADODataSetDataInfoFileName;
    TWideStringField *ADODataSetDataInfofP0;
    TWideStringField *ADODataSetDataInfofOilMax;
    TFloatField *ADODataSetPipeDieselSpeed;
private:	// User declarations
public:		// User declarations
    __fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
