#include "lDetect.h"
#include <math.h>
const float Oil_Angle_Thres             = 3.0;
const float Combustion_Pressure_Thres   = 0.6;
const float Compress_Pressure_Thres     = 0.15;
const float Angle_Per_MM                = 4.5;
const float Average_Pressure_Thres      = 0.15;   //MPa
const float Power_Thres                 = 0.1 ;

__fastcall lCombustionDetect::lCombustionDetect(void)
{
    fPowerLimit  = 0.0;
    fNoFireLimit = 2.8;
    fAngleMin    = 16.0;
    fAngleMax    = 30.0;
    fCompressMin = 2.5;
    fCompressMax = 3.0;
}

__fastcall lCombustionDetect::~lCombustionDetect()
{

}

void __fastcall lCombustionDetect::AnalysisAll(MaxBuffer& mbInfo)
{
// 根据提供的参数进行分析
// 燃烧与压缩过程的是分开进行的。
// 主要考虑的参数有：
//                (1) 最高燃烧压力     机械负荷
//                (2) 压缩压力　　　　 气缸密封状态
//                (3) 平均指示压力     检验缸内工作过程的效率
//                (4) 压力升率高       粗暴程度和冲击负荷
//                (5) 供油曲轴转角     滞燃期，供油始点是否正常
//                (6) 着火曲轴转角     着火时间是否合适
//                (7) 放热规律         最大值
//                (8) 燃烧持续时间　　 燃烧的完善程度
//-------------------------------------------------------------------
//                (9) 各缸压力最大值　 用于判断各个工作循环是否均衡
//                (10)各缸对外作功     是否均匀
//                (11)各缸累积放热量   是否均匀
//===================================================================
// 另外还有：　　 (12) 气缸压力最大值所在角度
//                (13) 压力升高率最大值所在角度 　

// 第一步：分析供油提前角是否正常
    AnalysisOilAngle(mbInfo);

}

void __fastcall lCombustionDetect::AnalysisOilAngle(MaxBuffer& mbInfo)
{
    float fbuffer[16];
    float ftemp;
    int inum;
    inum = mbInfo.iCyNums;
    for(int i = 0; i < inum; i++)
    {
        fbuffer[i] = mbInfo.farOilAngle[i];
    }

//-------------------------------------------------------------------------------
//  去掉三个最大值再去掉三个最小值后计算平均值
    for( int i = 0; i < inum - 1; i++)
    {
        for( int j = 1; j < inum; j++)
        {
            if( fbuffer[i] < fbuffer[j])
            {
                ftemp      = fbuffer[i];
                fbuffer[i] = fbuffer[j];
                fbuffer[j] = ftemp;
            }
        }
    }
    if(inum > 6)
    {
        ftemp = 0.0;
        for( int i = 3; i < inum - 3; i++)
        {
            ftemp += fbuffer[i];
        }
        OilAngleInfo.fAverage = ftemp/(float)(inum - 6);
    }
    else
    {
        OilAngleInfo.fAverage = fbuffer[inum/2];
    }
//=====================================================================
// 如果各值超过均值4度则应提示
    OilAngleInfo.iErrorNum = 0;
    for(int i = 0; i < inum; i++)
    {
        OilAngleInfo.fWeight[i]   = (mbInfo.farOilAngle[i] - OilAngleInfo.fAverage)
                                        /Angle_Per_MM;
        OilAngleInfo.fChar[i] = (mbInfo.farOilAngle[i] - OilAngleInfo.fAverage)
                                        /Oil_Angle_Thres;
        if( fabs(OilAngleInfo.fChar[i]) >= 1.0)
        {
            OilAngleInfo.bError[i] = true;
            OilAngleInfo.iErrorNum ++;
        }
        else
        {
            OilAngleInfo.bError[i] = false;
        }
    }
}


void __fastcall lCombustionDetect::AnalysisCombustion(MaxBuffer& mbInfo)
{
    float fbuffer[16];
    float ftemp;
    int inum;
    inum = mbInfo.iCyNums;
    for(int i = 0; i < inum; i++)
    {
        fbuffer[i] = mbInfo.farPMax[i];
    }

//-------------------------------------------------------------------------------
//  去掉三个最大值再去掉三个最小值后计算平均值
    for( int i = 0; i < inum - 1; i++)
    {
        for( int j = 1; j < inum; j++)
        {
            if( fbuffer[i] < fbuffer[j])
            {
                ftemp      = fbuffer[i];
                fbuffer[i] = fbuffer[j];
                fbuffer[j] = ftemp;
            }
        }
    }
    if(inum > 6)
    {
        ftemp = 0.0;
        for( int i = 3; i < inum - 3; i++)
        {
            ftemp += fbuffer[i];
        }
        CombustionInfo.fAverage = ftemp/(float)(inum - 6);
    }
    else
    {
        CombustionInfo.fAverage = fbuffer[inum/2];
    }
//=====================================================================
// 如果各值超过均值4度则应提示
    CombustionInfo.iErrorNum = 0;
    for(int i = 0; i < inum; i++)
    {
        CombustionInfo.fChar[i] = (mbInfo.farPMax[i] - CombustionInfo.fAverage)
                                        /Combustion_Pressure_Thres;
        if( fabs(CombustionInfo.fChar[i]) >= 1.0)
        {
            CombustionInfo.bError[i] = true;
            CombustionInfo.iErrorNum ++;
        }
        else
        {
            if(!(mbInfo.barCombustion[i]))   //如果该缸燃烧压力小于2.9MPa，则提示此该可能有问题
            {
                CombustionInfo.fChar[i] = 1000.0;
                CombustionInfo.bError[i] = true;
                CombustionInfo.iErrorNum ++;
            }
            else
            {
                CombustionInfo.bError[i] = false;
            }
        }
    }
}


void __fastcall lCombustionDetect::AnalysisCompress(MaxBuffer& mbInfo)
{
    float fbuffer[16];
    float ftemp;
    int inum;
    inum = mbInfo.iCyNums;
    for(int i = 0; i < inum; i++)
    {
        fbuffer[i] = mbInfo.farPMax[i];
    }

//-------------------------------------------------------------------------------
//  去掉三个最大值再去掉三个最小值后计算平均值
    for( int i = 0; i < inum - 1; i++)
    {
        for( int j = 1; j < inum; j++)
        {
            if( fbuffer[i] < fbuffer[j])
            {
                ftemp      = fbuffer[i];
                fbuffer[i] = fbuffer[j];
                fbuffer[j] = ftemp;
            }
        }
    }
    if(inum > 6)
    {
        ftemp = 0.0;
        for( int i = 3; i < inum - 3; i++)
        {
            ftemp += fbuffer[i];
        }
        CompressInfo.fAverage = ftemp/(float)(inum - 6);
    }
    else
    {
        CompressInfo.fAverage = fbuffer[inum/2];
    }
//=====================================================================
// 如果各值超过均值4度则应提示
    CompressInfo.iErrorNum = 0;
    for(int i = 0; i < inum; i++)
    {
        CompressInfo.fChar[i] = (mbInfo.farPMax[i] - CompressInfo.fAverage)
                                        /Compress_Pressure_Thres;
        if( fabs(CompressInfo.fChar[i]) >= 1.0)
        {
            CompressInfo.bError[i] = true;
            CompressInfo.iErrorNum ++;
        }
        else
        {
            CompressInfo.bError[i] = false;
        }
    }
}

void __fastcall lCombustionDetect::AnalysisAveragePressure(MaxBuffer& mbInfo)
{
    float fbuffer[16];
    float ftemp;
    int inum;
    inum = mbInfo.iCyNums;
    for(int i = 0; i < inum; i++)
    {
        fbuffer[i] = mbInfo.farAverageP[i] ;
    }

//-------------------------------------------------------------------------------
//  去掉三个最大值再去掉三个最小值后计算平均值
    for( int i = 0; i < inum - 1; i++)
    {
        for( int j = 1; j < inum; j++)
        {
            if( fbuffer[i] < fbuffer[j])
            {
                ftemp      = fbuffer[i];
                fbuffer[i] = fbuffer[j];
                fbuffer[j] = ftemp;
            }
        }
    }
    if(inum > 6)
    {
        ftemp = 0.0;
        for( int i = 3; i < inum - 3; i++)
        {
            ftemp += fbuffer[i];
        }
        AveragePressureInfo.fAverage = ftemp/(float)(inum - 6);
    }
    else
    {
        AveragePressureInfo.fAverage = fbuffer[inum/2];
    }
//=====================================================================
// 如果各值超过均值4度则应提示
    AveragePressureInfo.iErrorNum = 0;
    for(int i = 0; i < inum; i++)
    {
        AveragePressureInfo.fChar[i] = (mbInfo.farAverageP[i] - AveragePressureInfo.fAverage)
                                        /Average_Pressure_Thres;
        if( fabs(AveragePressureInfo.fChar[i]) >= 1.0)
        {
            AveragePressureInfo.bError[i] = true;
            AveragePressureInfo.iErrorNum ++;
        }
        else
        {
            AveragePressureInfo.bError[i] = false;
        }
    }
}


void __fastcall lCombustionDetect::AnalysisPower(MaxBuffer& mbInfo)
{
    float fbuffer[16];
    float ftemp, fsum;
    int inum;
    inum = mbInfo.iCyNums;
    for(int i = 0; i < inum; i++)
    {
        fbuffer[i] = mbInfo.farCPower[i];
    }

//-------------------------------------------------------------------------------
//  去掉三个最大值再去掉三个最小值后计算平均值
    for( int i = 0; i < inum - 1; i++)
    {
        for( int j = 1; j < inum; j++)
        {
            if( fbuffer[i] < fbuffer[j])
            {
                ftemp      = fbuffer[i];
                fbuffer[i] = fbuffer[j];
                fbuffer[j] = ftemp;
            }
        }
    }
    if(inum > 6)
    {
        ftemp = 0.0;
        for( int i = 3; i < inum - 3; i++)
        {
            ftemp += fbuffer[i];
        }
        PowerInfo.fAverage = ftemp/(float)(inum - 6);
    }
    else
    {
        PowerInfo.fAverage = fbuffer[inum/2];
    }
    fsum = 0.0;
    for( int i = 0; i < inum; i ++)
    {
        ftemp = mbInfo.farCPower[i] - PowerInfo.fAverage;
        fsum += ftemp*ftemp;
    }
    fsum = sqrt( fsum / (float)inum );
    if(fsum < 0.0000001)
    {
        fsum = 1.0;
    }
//=====================================================================
// 如果各值超过均值4度则应提示
    PowerInfo.iErrorNum = 0;
    for( int i = 0; i < inum; i ++)
    {
        fPowerLimit += mbInfo.farCPower[i];
    }
    fPowerLimit /= (float)inum;
    fPowerLimit *= 0.25;
    for(int i = 0; i < inum; i++)
    {
        PowerInfo.fChar[i] = (mbInfo.farCPower[i] - PowerInfo.fAverage)
                                        /fsum;
        if( fabs(PowerInfo.fChar[i]) >= 3.0)
        {
            PowerInfo.bHigh[i]  = true;
            PowerInfo.bError[i] = true;
            PowerInfo.iErrorNum ++;
        }
        else if(mbInfo.farCPower[i] < fPowerLimit )
        {
            PowerInfo.bError[i] = true;
            PowerInfo.bHigh[i]  = false;
            PowerInfo.iErrorNum ++;
        }
        else
        {
            PowerInfo.bError[i] = false;
        }
    }
}
//==================================

void __fastcall lCombustionDetect::AnalysisMean(MaxBuffer&  mbInfo)
{
// 用于统计不着火缸的个数及分布，即位于柴油机左侧还是右侧
    float fbuffer[16];
    float ftemp;
    int inum;
    int iPosi;
    inum = mbInfo.iCyNums;
    MeanInfo.iNFNums  = 0;   //没有着火的缸数
    MeanInfo.iNFLeftNums  = 0;   //1~8缸没有着火的缸数
    MeanInfo.iNFRightNums = 0;  //9~16缸没有着火的缸数
    fPowerLimit = 0.0;
    for( int i = 0; i < inum; i ++)
    {
        fPowerLimit += mbInfo.farCPower[i];
    }
    fPowerLimit /= (float)inum;
    fPowerLimit *= 0.25;
    for(int i = 0; i < inum; i ++)
    {
        if(   (!mbInfo.barCombustion[i])  //如果没有处于燃烧状态
            ||(mbInfo.farCPower[i] <= fPowerLimit)  //压力值很小,用对外作功来控制
        )
        {
            MeanInfo.iNFNums ++;  //使没有着火的缸数加1

            iPosi = mbInfo.siarDieselNum[i];
            if( (iPosi >= 1)&&(iPosi <= 8))  //在左侧
            {
                MeanInfo.iNFLIndex[MeanInfo.iNFLeftNums]    = mbInfo.siarDieselNum[i];
                MeanInfo.fNFLPressure[MeanInfo.iNFLeftNums] = mbInfo.farPMax[i];
                MeanInfo.fNFLAngle[MeanInfo.iNFLeftNums]    = mbInfo.farOilAngle[i];
                MeanInfo.fNFLPower[MeanInfo.iNFLeftNums]    = mbInfo.farCPower[i];
                MeanInfo.iNFLeftNums ++;
            }
            else
            {
                MeanInfo.iNFRIndex[MeanInfo.iNFRightNums]    = mbInfo.siarDieselNum[i];
                MeanInfo.fNFRPressure[MeanInfo.iNFRightNums] = mbInfo.farPMax[i];
                MeanInfo.fNFRAngle[MeanInfo.iNFRightNums]    = mbInfo.farOilAngle[i];
                MeanInfo.fNFRPower[MeanInfo.iNFRightNums]    = mbInfo.farCPower[i];
                MeanInfo.iNFRightNums ++;
            }
        }
    }
}

void __fastcall lCombustionDetect::AnalysisMOilAngle(MaxBuffer&  mbInfo)
{
// 用于定量分析判断各缸的供油提前角

    float fbuffer[16];
    float ftemp;
    int inum;
    int iPosi;
    inum = mbInfo.iCyNums;
    MAngleInfo.iNFNums  = 0;   //没有着火的缸数
    MAngleInfo.iNFLeftNums  = 0;   //1~8缸没有着火的缸数
    MAngleInfo.iNFRightNums = 0;  //9~16缸没有着火的缸数
    for(int i = 0; i < inum; i ++)
    {
        if( mbInfo.farOilAngle[i] < fAngleMax )
        {
            MAngleInfo.iNFNums ++;  //使有故障缸加1
            MAngleInfo.iNFLIndex[MAngleInfo.iNFLeftNums]    = mbInfo.siarDieselNum[i];
            MAngleInfo.fNFLPressure[MAngleInfo.iNFLeftNums] = mbInfo.farPMax[i];
            MAngleInfo.fNFLAngle[MAngleInfo.iNFLeftNums]    = mbInfo.farOilAngle[i];
            MAngleInfo.iNFLeftNums ++;
        }
        else if((mbInfo.farOilAngle[i] > fAngleMin)) //供油提前角不正常
        {
            MAngleInfo.iNFNums ++;
            MAngleInfo.iNFRIndex[MAngleInfo.iNFRightNums]    = mbInfo.siarDieselNum[i];
            MAngleInfo.fNFRPressure[MAngleInfo.iNFRightNums] = mbInfo.farPMax[i];
            MAngleInfo.fNFRAngle[MAngleInfo.iNFRightNums]    = mbInfo.farOilAngle[i];
            MAngleInfo.iNFRightNums ++;
        }
    }
}

void __fastcall lCombustionDetect::AnalysisMCompress(MaxBuffer&  mbInfo)
{
// 用于定量分析判断各缸的压缩压力

    float fbuffer[16];
    float ftemp;
    int inum;
    int iPosi;
    inum = mbInfo.iCyNums;
    MCompInfo.iNFNums  = 0;   //没有着火的缸数
    MCompInfo.iNFLeftNums  = 0;   //1~8缸没有着火的缸数
    MCompInfo.iNFRightNums = 0;  //9~16缸没有着火的缸数
    for(int i = 0; i < inum; i ++)
    {
        if( (mbInfo.farPMax[i]  < fCompressMin))  //供油提前角不正常
        {
            MCompInfo.iNFNums ++;  //使有故障缸加1
            MCompInfo.iNFLIndex[MCompInfo.iNFLeftNums]    = mbInfo.siarDieselNum[i];
            MCompInfo.fNFLPressure[MCompInfo.iNFLeftNums] = mbInfo.farPMax[i];
            MCompInfo.fNFLAngle[MCompInfo.iNFLeftNums]    = mbInfo.farOilAngle[i];
            MCompInfo.iNFLeftNums ++;
        }
        else if( mbInfo.farPMax[i]    > fCompressMax)  //
        {
            MCompInfo.iNFNums ++;  //使有故障缸加1
            MCompInfo.iNFRIndex[MCompInfo.iNFRightNums]    = mbInfo.siarDieselNum[i];
            MCompInfo.fNFRPressure[MCompInfo.iNFRightNums] = mbInfo.farPMax[i];
            MCompInfo.fNFRAngle[MCompInfo.iNFRightNums]    = mbInfo.farOilAngle[i];
            MCompInfo.iNFRightNums ++;
        }
    }
}
