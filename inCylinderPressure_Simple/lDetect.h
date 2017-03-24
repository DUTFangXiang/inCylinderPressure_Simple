#ifndef  __LDETECT_H__
#define  __LDETECT_H__
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
#include <ExtCtrls.hpp>
#include "MaxInfo.h"
/*
    根据提供的参数(保存在MaxBuffer中)对柴油机各缸的燃烧状态进行分析判断
    2005年8月26日
*/
struct strctDetectInfo
{
    int   iErrorNum;
    float fAverage;
    float fChar[16];
    float fWeight[16];
    bool  bError[16];
    bool  bHigh[16];
};

struct strctMeanInfo //用于怠速状态下柴油机运转的均匀性进行分析判断
{
    int   iNFNums;   //没有着火的缸数
    int   iNFLeftNums;   //1~8缸没有着火的缸数
    int   iNFRightNums;  //9~16缸没有着火的缸数

    int   iNFLIndex[16];  //没有着火的缸号
    float fNFLPressure[16]; //没有着火缸的气缸压力
    float fNFLAngle[16];    //没有着火缸的供油提前角
    float fNFLPower[16];
    int   iNFRIndex[16];  //没有着火的缸号
    float fNFRPressure[16]; //没有着火缸的气缸压力
    float fNFRAngle[16];    //没有着火缸的供油提前角
    float fNFRPower[16];  
};

class lCombustionDetect
{
private:
    float fNoFireLimit;
    float fCompressMin;
    float fCompressMax;
    float fAngleMin;
    float fAngleMax;
    float fPowerLimit;

public:
    strctDetectInfo OilAngleInfo;          //有关供油提前角的信息
    strctDetectInfo CombustionInfo;        //有关燃烧压力方面的信息
    strctDetectInfo CompressInfo;          //有关燃烧压力方面的信息
    strctDetectInfo AveragePressureInfo;   //平均指示压力方面的信息
    strctDetectInfo PowerInfo;
    strctMeanInfo   MeanInfo;              //用于怠速状态下柴油机运转的均匀性进行分析判断
    strctMeanInfo   MCompInfo;             //定量判断压缩压力
    strctMeanInfo   MAngleInfo;            //定量判断供油提前角

    __fastcall lCombustionDetect(void);
    __fastcall ~lCombustionDetect();
    void __fastcall AnalysisAll(MaxBuffer& mbInfo);
    void __fastcall AnalysisOilAngle(MaxBuffer& mbInfo);
    void __fastcall AnalysisCombustion(MaxBuffer& mbInfo);
    void __fastcall AnalysisCompress(MaxBuffer& mbInfo);
    void __fastcall AnalysisAveragePressure(MaxBuffer& mbInfo);
    void __fastcall AnalysisPower(MaxBuffer& mbInfo);
    void __fastcall AnalysisMean(MaxBuffer&  mbInfo);
    void __fastcall AnalysisMOilAngle(MaxBuffer&  mbInfo);
    void __fastcall AnalysisMCompress(MaxBuffer&  mbInfo);
    void __fastcall SetfNoFireLimit(float nfl)    //设置失火极限
    {
        fNoFireLimit = nfl;
    };
    void __fastcall SetfPowerLimit( float spl)
    {
        fPowerLimit = spl;
    };
    void __fastcall SetAngleInfo( float faiMin, float faiMax)
    {
        fAngleMin = faiMin;
        fAngleMax = faiMax;
    };
    void __fastcall SetCompressInfo(float fciMin, float fciMax)
    {
        fCompressMin = fciMin;
        fCompressMax = fciMax;
    };
};
#endif