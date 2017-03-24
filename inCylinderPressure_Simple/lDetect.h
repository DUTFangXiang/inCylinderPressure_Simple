#ifndef  __LDETECT_H__
#define  __LDETECT_H__
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
#include <ExtCtrls.hpp>
#include "MaxInfo.h"
/*
    �����ṩ�Ĳ���(������MaxBuffer��)�Բ��ͻ����׵�ȼ��״̬���з����ж�
    2005��8��26��
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

struct strctMeanInfo //���ڵ���״̬�²��ͻ���ת�ľ����Խ��з����ж�
{
    int   iNFNums;   //û���Ż�ĸ���
    int   iNFLeftNums;   //1~8��û���Ż�ĸ���
    int   iNFRightNums;  //9~16��û���Ż�ĸ���

    int   iNFLIndex[16];  //û���Ż�ĸ׺�
    float fNFLPressure[16]; //û���Ż�׵�����ѹ��
    float fNFLAngle[16];    //û���Ż�׵Ĺ�����ǰ��
    float fNFLPower[16];
    int   iNFRIndex[16];  //û���Ż�ĸ׺�
    float fNFRPressure[16]; //û���Ż�׵�����ѹ��
    float fNFRAngle[16];    //û���Ż�׵Ĺ�����ǰ��
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
    strctDetectInfo OilAngleInfo;          //�йع�����ǰ�ǵ���Ϣ
    strctDetectInfo CombustionInfo;        //�й�ȼ��ѹ���������Ϣ
    strctDetectInfo CompressInfo;          //�й�ȼ��ѹ���������Ϣ
    strctDetectInfo AveragePressureInfo;   //ƽ��ָʾѹ���������Ϣ
    strctDetectInfo PowerInfo;
    strctMeanInfo   MeanInfo;              //���ڵ���״̬�²��ͻ���ת�ľ����Խ��з����ж�
    strctMeanInfo   MCompInfo;             //�����ж�ѹ��ѹ��
    strctMeanInfo   MAngleInfo;            //�����жϹ�����ǰ��

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
    void __fastcall SetfNoFireLimit(float nfl)    //����ʧ����
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