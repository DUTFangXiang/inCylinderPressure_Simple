#ifndef MAX_INFO_H
#define MAX_INFO_H
//---------------------------------------------------------------------------
struct MaxBuffer
{
    int iCyNums;         //一共测了几个缸
    bool bCombustion;    //是否是燃烧状态
    float COMBUSTION_LEVEL;
//----------------------------------------------
    float fESMax;        //转速最大值
    float fESMin;        //转速最小值
    float fESMean;       //转速平均值
    float fCCPower;      //指示功率

    float fPMax;         //最大气缸压力
    float fPMin;         //最小气缸压力
    float fDPDFMax;      //最大压力升高率
    float fDPDFMin;      //最小压力升高率
    float fDHDFMax;      //最大放热率
    float fDHDFMin;      //最小放热率　
    float fCDHDFMax;
    float fCDHDFMin;
    float fTMax;         //最高温度
    float fTMin;         //最低温度

    float fDWMax;
    float fDWMin;

    float fWMax;         //对外所做的功
    float fWMin;         //对外做功的最小值

    float fOilPMax;       //油管压力波的最大值
    float fOilPMin;       //油管压力波的最小值

    float fOPMax;        //原始数据最大值
    float fOPMin;        //原始数据最小值
    float fVMax;         //容积最大值
    float fVMin;         //容积最小值

    float fLogVMax;
    float fLogVMin;

    float fLogPMax;
    float fLogPMin;

    float fFFTMax;
    float fFFTMin;

    float fCPowerMax;
    float fCPowerMin;
//==============================================
    float farEngineSpeed[16];

    int siarDieselNum[16];

    float farMaxPAngle[16];        //最大燃烧压力所在曲轴转角
    float farMaxDPAngle[16];       //最大压升率所在曲轴转角
    float farMaxDHAngle[16];       //最大放热率对应的曲轴转角
    float farCombustionAngle[16];  //燃烧开始角度
    float farOilAngle[16];         //供油开始角度　
    float farWavePeriod[16];
    float farCPower[16];           //对外最功

    float farCDHDFMax[16];
    float farCDHDFMin[16];
    float farPMax[16];         //最大气缸压力
    float farPMin[16];         //最小气缸压力
    float farDPDFMax[16];      //最大压力升高率
    float farDPDFMin[16];      //最小压力升高率
    float farDHDFMax[16];      //最大放热率
    float farDHDFMin[16];      //最小放热率　
    float farTMax[16];         //最高温度
    float farTMin[16];         //最低温度
    float farDWMax[16];
    float farDWMin[16];
    float farWMax[16];         //对外所做的功
    float farWMin[16];         //对外做功的最小值
    float farOilPMax[16];       //油管压力波的最大值
    float farOilPMin[16];       //油管压力波的最小值
    float farOPMax[16];        //原始数据最大值
    float farOPMin[16];        //原始数据最小值
    float farVMax[16];         //容积最大值
    float farVMin[16];         //容积最小值
    float farLogVMax[16];
    float farLogVMin[16];
    float farLogPMax[16];
    float farLogPMin[16];
    float farFFTMax[16];
    float farFFTMin[16];
    
//-----------------------------------------------------------
    float farCombustionPeriod[16];  //燃烧持续时间
    float farAverageP[16];          //平均指示压力
    float farFlexP[16];             //气缸压力的波动情况
    float farCombustionLevel[16];
    bool  barCombustion[16];
//===========================================================
    void __fastcall SetbCombustion(void)
    {
        int iComNums = 0;
        for( int i = 0; i < iCyNums; i ++)
        {
            if( barCombustion[i])
            {
                iComNums ++;
            }
        }
        bCombustion = (bool)iComNums;
    }
    void _fastcall GetMinMax(void)
    {
        GetMin(farOPMin, fOPMin ,true);
        GetMax(farOPMax, fOPMax ,true);

        GetMin(farPMin, fPMin ,true);
        GetMax(farPMax, fPMax ,true);

        GetMin(farDPDFMin, fDPDFMin ,true);
        GetMax(farDPDFMax, fDPDFMax ,true);

        GetMin(farDHDFMin, fDHDFMin ,true);
        GetMax(farDHDFMax, fDHDFMax ,true);

        GetMin(farCDHDFMin, fCDHDFMin ,true);
        GetMax(farCDHDFMax, fCDHDFMax ,true);

        GetMin(farTMin, fTMin ,true);
        GetMax(farTMax, fTMax ,true);

        GetMin(farWMin,  fWMin ,true);
        GetMax(farWMax,  fWMax ,true);
        GetMin(farDWMin, fDWMin ,true);
        GetMax(farDWMax, fDWMax ,true);

        GetMin(farOilPMin, fOilPMin ,true);
        GetMax(farOilPMax, fOilPMax ,true);

//        GetMin(farVMin, fVMin);
//        GetMax(farVMax, fVMax);

        GetMin(farLogVMin, fLogVMin ,true);
        GetMax(farLogVMax, fLogVMax ,true);

        GetMin(farLogPMin, fLogPMin ,true);
        GetMax(farLogPMax, fLogPMax ,true);

        GetMin(farFFTMin, fFFTMin ,true);
        GetMax(farFFTMax, fFFTMax ,true);

        GetMin(farCPower, fCPowerMin, true);
        GetMax(farCPower, fCPowerMax, true);
        
        GetMax(farEngineSpeed,fESMax, false);        //转速最大值
        GetMin(farEngineSpeed,fESMin, false);        //转速最小值
        GetMean(farEngineSpeed, fESMean);
        CalculatePower();                            //计算柴油机的指示功率
    };
    void __fastcall CalculatePower(void)
    {
        fCCPower = 0.0;
        for(int i = 0; i < iCyNums; i++)
        {
            fCCPower += farCPower[i];
        }
        if(iCyNums == 0)
        {
            fCCPower = 0.0;
        }
        else
        {
            fCCPower = fCCPower*(fESMean/120.0);
        }
    };

    void __fastcall GetMean(float* fp, float& fmean)
    {
        fmean = 0.0;
        for(int i = 0; i < iCyNums; i ++)
        {
            fmean += fp[i];
        }
        fmean /= (float)iCyNums;
    };

    void __fastcall GetMin(float* fp, float& fmin, bool benlarge)
    {
        fmin = fp[0];
        for(int i = 0; i < iCyNums; i ++)
        {
            if(fmin > fp[i])
            {
                fmin = fp[i];
            }
        }
        if(benlarge)
        {
            fmin = fmin;
        }
    };

    void __fastcall GetMax(float* fp, float& fmax, bool benlarge)
    {
        fmax = fp[0];
        for(int i = 0; i < iCyNums; i ++)
        {
            if(fmax < fp[i])
            {
                fmax = fp[i];
            }
        }
        if(benlarge)
        {
            fmax *= 1.2;
        }
    };
};

struct MaxInfo
{
    int iDieselNum;      //缸号
    float fPMax;         //最大气缸压力
    float fDPDFMax;      //最大压力升高率
    float fDHDFMax;      //最大放热率
    float fTMax;         //最高温度
    float fWMax;         //对外所做的功

    float fFDHDFMax;     //放热率第一峰值
    float fFaiPMax;      //最大气缸压力所对应的曲轴转角
    float fFaiDPDFMax;   //最大压力升高率对应的曲轴转角
    float fFaiDHDFMax;   //最大放热率对应的曲轴转角
    float fFaiTMax;      //最高温度对应的曲轴转角
    float fFDHDFMaxFai;  //放热率第一峰值对应的曲轴转角
};

struct Parameters
{
    float fLowPressure;
    float fSetfP0;
    float fPAir;
    float fT0;
    float fTAir;
    float fDFai;
    float fKConst;
    float fKCoef;
    float fHRConst;
    float fLCoef;
    float fNC;
    float fMH;
    float fFI;
    float fTAU;
    float fHU;
    float fGF;
    float fCAING;
    float fTF;
    float fLO;
    float fALPHA;
    float fRMOL;
    float fGAMA;
    float fX0;
    float ft[3];
};

//此结构的数据用于数据分析
struct structDetect
{
    bool  bDataValid;         //这一数据是否
    int   iDieselNum;         //柴油机缸号
    float fDieselSpeed;       //柴油机转速

    float fCPMax;             //最大压力
    float fDPDFMax;           //压力升高率最大值
    float fInletPressure;     //当量进气压力

    float fOilAngle;          //供油提前角
    float fOilPeak;           //波表峰值
    float fOilPeriod;         //供油持续角
    float fOilCoef;           //波形系数

    float fCombustionAngle;   //燃烧始点
    float fCombustionPeriod;  //燃烧持续时间
    float fDHDFMax;           //放热率最大值
    float fHAll;              //累积放热量
    float fCPower;            //循环功

    float fComPressure;       //这一缸的压缩压力
    
    bool  bComValid;          //压缩压力是否有效  true:有效  false:无效
    short int siPower;        //对外作功　1：过大　0：正常　－1：过小
    short int siPMax;         //气缸压力　1：过大　0：正常　－1：过小
    short int siComPressure;  //压缩压力　1：过大　0：正常　－1：过小
    short int siOilAngle;     //1：过大　0：正常　－1：过小
    short int siOilPeriod;    //1：过大　0：正常　－1：过小

    AnsiString strResult;     //分析结论
};
#endif
