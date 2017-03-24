#ifndef lFileHeadH
#define lFileHeadH
//#include "lFileHead.h"
#include "lrwenum.h"
#include <Classes.hpp>
//----------------------------------------------------------------------
//#define SELF_DEBUG
#define PASSAGENUM  3
union lShort
{
	short int iData;
    unsigned char ch[2];
};
union lInt
{
	int iData;
    char ch[4];
};
union lDouble
{
	double dData;
    char ch[8];
};
union lFloat
{
    float fData;
    unsigned char ch[4];
};
union GetData
{
	unsigned short idata;
	unsigned char cdata[2];
};


struct lFileHeadStruct
{
    //原201数据采集器所采集的数据采用二进制存储格式
    //前512个字节的数据是文件头，用于记录采集过程中的一些信息
/*
        0：		标志字节，0FFH=表示一个有效的目录项，00H表示一个空的目录项。
        1：一通道信号类型
        　　　　0：　燃烧压力
                1:   压缩压力
                2：　增压压力
                3：　油管压力
                4：　主发电流
                5：　主发电压
                6：　其它
        2：二通道信号类型
        　　　　0：　燃烧压力
                1:   压缩压力
                2：　增压压力
                3：　油管压力
                4：　主发电流
                5：　主发电压
                6：　其它
        3：三通道信号类型　，只是电压信号，一般为零
        　　　　0：　燃烧压力
                1:   压缩压力
                2：　增压压力
                3：　油管压力
                4：　主发电流
                5：　主发电压
                6：　其它

        4: 柴油机缸号
        5：机车车型
        　　　　0：东风4A
        　　　　1：东风4B
                2：东风4C
                3：东风4D
                4：东风7C
                5：东风8B
                6：东风11
                7：其它
        6：机车车号
        7~15：保留
        16：通道1状态
        　　　　0：关闭
                1：打开
        17：通道2状态
        　　　　0：关闭
                1：打开
        18：通道3状态
        　　　　0：关闭
                1：打开
        19：通道1信号类型
        　　　　0：电荷
                1：电压
        20：通道2信号类型
        　　　　0：电荷
                1：电压
        21：通道3信号类型
        　　　　0：电荷
                1：电压
        22：通道1信号增益
        　　　　0：1倍
                1：2倍
                2：4倍
                3：8倍
                4：16倍
                5：32倍　
                6：128倍
                7：256倍　
        23：通道2信号增益
        　　　　0：1倍
                1：2倍
                2：4倍
                3：8倍
                4：16倍
                5：32倍　
                6：128倍
                7：256倍　
        24：通道3信号增益
        　　　　0：1倍
                1：2倍
                2：4倍
                3：8倍
                4：16倍
                5：32倍　
                6：128倍
                7：256倍　
        25: 通道1的灵敏度整数部分
        26：通道2的灵敏度整数部分
        27：通道3的灵敏度的整数部分
        28：通道1灵敏度的小数部分（实际上是用整数表示）
        29：通道1灵敏度的小数部分（实际上是用整数表示）
        30：通道1灵敏度的小数部分（实际上是用整数表示）
        31：采样频率（实际上是分析频率，2.56*F）
        　　　　0：1K
                1：2K
                2：3K
                3：4K
                4：5K
                5：6K
                6：7K
                7：8K
                8：9K
                9：10K
                10：12K
                11：15K
        32：采样长度　(为每一个通道的实际数据点长度)
        33：年
        34：月
        35：日
        36：时
        37：分
        38：秒
        39~61： 保留
        62：　　本文件在索引表中的第一个地址
        63：数据长度，以K来表示

*/

//--------------------------------------------------------------------
// 以下为仪器提供的参数
	char str902Mark[4];       //写902标志               　4个字节
                              //"902"表示是902数据
    int iHeadLength;          //文件头长度              　4个字节
    short int siSignalSource[3];  //信号源　　　　　　　　6个字节
    short int siDieselNum;        //柴油机缸号          　2个字节
    short int siTrainType;        //机车车型            　2个字节
    int       iTrainNum;          //机车车号　　　　　　　4个字节　　
    short int siPassageStatus[3]; //三个通道的状态      　6个字节
    short int siSignalType[3];    //三个通道的信号类型  　6个字节
    short int siSignalGain[3];    //三个通道的信号增益  　6个字节
    float     fSensitivity[3];    //三个通道的信号灵敏度　12个字节
    int       iLength;      //信号长度                  　4个字节
    short int siFrequency;        //分析频率              2个字节
    short int siYear;         //年                     　 2个字节
    short int siMonth;        //月                      　2个字节
    short int siDate;         //日                      　2个字节
    short int siHour;         //时                      　2个字节
    short int siMinute;       //分                      　2个字节
    short int siSecond;       //秒                      　2个字节   共有 70个字节

//----------------------------------------------------------------------
    char  strTrainType[16];   //字符串形式的机车车型      16个字节
    char  strTrainNum[10];    //                          10个字节
    char  strSignalType[2][8];  //字符串形式的信号类型    16个字节
    short int siGain[3];        //真正的增益数值          6个字节
    short int siRFrequency;     //实际的采样频率（k)      2个字节
    char  strPerson[20];        //检测人员姓名            20个字节
    char  strMTime[40];                               //　40个字节　
    float fTimeInterval;                               // 4个字节
    float fFreqInterval;                               // 4个字节
    short int siPassOpenNum;     //打开的通道数        // 2个字节
    short int iNormalLength;     //                       2个
    float fAngleStep;                                 //  4个
    short int siCombustion;      // = 1 有燃烧过程　= 0 // 2个字节
    float fEngineSpeed;          //柴油机转速           // 4个字节
    float fOilAngle;             //供油提前角              4个字节
    float fCombustionAngle;       //燃烧始点                4个字节     共140个字节
//-----------------------------------------------------------------------
//--------------------------------------------------------------------
// 2005_02_07新增加的内容
    short int siSetSampleNum;  //波形的测量次数                   2
    short int siDataValid;     //是否测量到了有效数据             2
    float     fEn;            //柴油机转速                        4
    float     fP1RMS;         //第一通道的均方根值                4
    float     fCPMax;         //第一通道的压力最大值              4
    int       iAbstractLength;   //如果数据有效，则提出的数据长度  4
    char      chVersion;         // 版本号-     1：版本号为2          1
    int       iRFrequency;         //实际采样频率                  4
    short int siCutoffFreq[2];     //两个通道的低通频率            4
    char      chTogether[2];       //两个通道是否同步              2
    short int siSampleNum;                                  //       2
    char      chCombustion;        //是否是燃烧过程   //9          1

    float     fDPDFMax;             // 7,8                        4
    int       iCombustionPosi;     //(10)                         4
    int       iOilPosi;            //(11)                         4
    int       iTDPosi;              //(12)                        4

    float     fHeatAll;           //总放热量                      4
    float     fCPower;            // 循环功                       4
    float     fWavePeriod;        //波形持续时间                  4
    float     fWaveCoef;          //波形系数                      4

//  fAngleStep, fEngineSpeed,  siRFrequency,                         共有 66个字节
//  fTimeInterval,fFrequInterval,siPassOpenNun

//----------------------------------------------------------------------
    float    fDiameter;           //1  气缸直径                    4
    float    fStroke;             //2  冲程                        4
    float    fCRatio;             //3  压缩比                      4
    float    fPodLength;          //4  连杆长度                    4
    float    fLMDa;               //5  冲程/连杆之比               4
    float    fInOpenAngle;        //6  进气门开启角度              4
    float    fInCloseAngle;       //7  进气门关闭角度              4
    float    fOutOpenAngle;       //8  排气门开启角度              4
    float    fOutCloseAngle;      //9  排气门关闭角度              4
    short int siInfoValid;        //10 数据是否有效                2
    int      iNumPerAngle;        //11 每一度提取的点的个数        4
    float    fOilPeak;            //波形峰值                        4
    float    fLocalDPDFMax;       //压力升高率的局部最大值          4
    float    fBarP0;              //进气压力                        4
    char     chOil;               // = 1 有供油过程　= 0 // 1个字节 1     共有55个字节
    char     chtemp;
    float    fCombustionPeriod;
//------------------------------------------------------------------------
//  以下各量用于记录各个部分的最小值和最大值
    float    fMinOldP, fMaxOldP;  //原始数据的最大值和最小值
    float    fOilPMin, fOilPMax;  //油管压力波形的最大值和最小值
    float    fNormalPMin,fNormalPMax;   //修正后的气缸压力最大值和最小值
    float    fDPDFMin;       //压力升高率的最大值和最小值
    float    fHRRMin,   fHRRMax;        //放热率最大值和最小值
    float    fCHRRMax,  fCHRRMin;       //累积放热率最大值和最小值
    float    fMaxFFTP,  fMinFFTP;       //频谱的最大值和最小值
    float    fTMax,     fTMin;          //气缸温度的最大值和最小值
    float    fDWMax,    fDWMin;         //瞬时功的最大值和最小值
    float    fWMax,     fWMin;          //瞬时功的最大值和最小值
    float    fFFFaiMin, fFFFaiMax;
    int      iStartFai, iEndFai;
    int      iFFTLength;
    float    fLogPMin;
    float    fLogPMax;
    float    fLogVMin;
    float    fLogVMax;


    float    fFaiPMax;      //最大气缸压力所对应的曲轴转角
    float    fFaiDPDFMax;   //最大压力升高率对应的曲轴转角
    float    fFaiDHDFMax;   //最大放热率对应的曲轴转角
    float    fFaiTMax;      //最高温度对应的曲轴转角
    float    fDHDFMax;     //放热率第一峰值
    float    fFaiFirstDHDFMax; //放热率第一峰值的曲轴转角　
    float    fFirstDHDFMax;
//    float    fFaiDHDFMax;  //放热率第一峰值对应的曲轴转角
    float    fAverageP;     //平均指示压力
    float    fCombustionLevel;
    float    COMBUSTION_LEVEL;
    float    fCompressFactor;
//    float    fCPower;
//========================================================================
    char strTemp[2];        // 实际有331个字节
     					      //从第513个字节开始是数据

//---------------------------------------------------------------------------
};

class lDieselStruct       //柴油机结构参数
{
      //柴油机的结构参数  (固定参数)
protected:
    float fDiameter;       //柴油机气缸直径
    float fPodLength;      //连杆长度
    float fStroke;         //柴油机活塞行程
    float fCRatio;         //压缩比  fEE也是压缩比
    float fLMDa;           //曲柄半径与连杆长度之比
    float fC;              // = 1.0/(fEE-1.0);
    float fX0;             //气缸压缩余隙
    float fTAU;            //柴油机行程数
    float fFI;             //柴油机气缸数
    float fInOpenAngle;    //进气门打开角度, 上止点前  50 CA
    float fInCloseAngle;   //进行门关闭角度，下止点后  42 CA
    float fOutOpenAngle;   //排气门打开角度, 下止点前 50 CA
    float fOutCloseAngle;  // 排气门关闭角度，上止点后 50 CA
    float fCAING;          //喷油器提前角
public:
    void SetfCAING(float fl)
    {
        fCAING = fl;
    };
    void SetfOutOpenAngle(float fl)
    {
        fOutOpenAngle = fl;
    };
    void SetfOutCloseAngle(float fl)
    {
        fOutCloseAngle = fl;
    };
    void SetfInOpenAngle(float fl)
    {
        fInOpenAngle = fl;
    };
    void SetfInCloseAngle(float fl)
    {
        fInCloseAngle = fl;
    };
    void SetfFI(float fl)
    {
        fFI = fl;
    };
    void SetfX0(float fl)
    {
        fX0 = fl;
    };
    void SetfTAU(float fl)
    {
        fTAU = fl;
    };

    void SetfDiameter(float fl)
    {
        fDiameter = fl;
    };
    void SetfPodLength(float fl)
    {
        fPodLength = fl;
    };
    void SetfStroke(float fl)
    {
        fStroke = fl;
    };
    void SetfCRatio(float fl)
    {
        fCRatio = fl;
    };
    void SetfLMDa(float fl)
    {
        fLMDa = fl;
    };
//--------------------------------------------
// 返回参数
    float GetfDiameter(void)
    {
        return fDiameter;
    };
    float GetfPodLength(void)
    {
        return fPodLength;
    };
    float GetfStroke(void)
    {
        return fStroke;
    };
    float GetfCRatio(void)
    {
        return fCRatio;
    };
    float GetfLMDa(void)
    {
        return fLMDa;
    };
    float GetfOutOpenAngle(void)
    {
        return fOutOpenAngle;
    };
    float GetfOutCloseAngle(void)
    {
       return fOutCloseAngle;
    };
    float GetfInOpenAngle(void)
    {
        return fInOpenAngle;
    };
    float GetfInCloseAngle(void)
    {
        return fInCloseAngle;
    };
//============================================
};

class lDieselHRBP:public lDieselStruct
{
private:
//其它热力参数 (可变参数)

    float fEn;  //柴油机转速
    float fDFai;  //计算步长
    float fKConst; //比热比
    float fKCoef;  //比热比系数
    float fK;
    float fTWater;         //冷却水温度
    float fTAir;           //空气温度
    float fPAir;           //空气压力
    float fTTop;            // 气缸顶面温度    可近似取冷却水温度   80
    float fTWall;           //气缸套外温度     可近似取为冷却水温度 80
    float fTBottom;         //活塞底温度       可近似取为曲轴箱温度 70
    float fALPHA;                  //过量空气系数
    float fGAMA;                   //废气残余系数

    float fHRConst;   //传热系数
    float fAverSpeed;  //柴油机平均速度　
    float fLCoef;      //漏气系数
    float fR;          //气体状态常数
    float fTw;         //壁面温度
    float fA;          //热功当量
    float fG;          //气缸内的空气的质量
    float fV;          //气缸的瞬时容积
    float fGG;         //重力加速度
    bool bAbsolute;     //绝热与实际过程的
    float fRMOL;                  // 气体摩尔数
    float fU[7][7];               //用于保存气体的热力学属性
    float fLO;                    //理论空气量 mol/kg燃料
//　燃油参数
    float fNC;                    //燃料中的碳原子数
    float fMH;                    //燃料中的氢原子数
    float fHU;                    //燃料的低热值(J/kg)
    float fGF;                    //一次喷油的燃油重量
    float fRealFuel;        //实际喷油量   fGF 为估计喷油量
    float fTF;                    //一次喷油的持续时间

//　计算开始时的状态参数
    float fP0;           //进气门关闭时的进气压力
    float fT0;           //进气门关闭时的进气温度
    float fV0;           //进气关闭时的气缸容积
    float fFai;          //开始时间时的曲轴转角
    float fEndFai;       //结束计算时的曲轴转角
    float fLowPressure;     //低压修正值

//结果参数
    float fATM;                  //机械效率
    float fATE;                   //有效效率

//计算时应用的参数

    float fPDeltaT;               //测量压力时的时间间隔
    float fCA;              //当前柴油机曲轴转角
    float fAREA[3];         //散热面积
    float fTW[3];           //壁面温度
    float fSP[1000];
    int iIteration;
    int iDisp;           //上止点位置移动的位置
    int iTopDeadPosi;    //上止点所在数据的位置
    int iposi;

    int iCycleNum;       //每一个循环的采集点数
    int IHALFLENGTH;     //从最大值向前所数的数据点数
    drawKind lsAllDrawKind;
    float fEnlarge;

public:
    float fFaiDHDFMax;
    float fOilGain;
    int   iOilShiftNum;
    int   iNumPerAngle;
    float fLevelStart;
    float fLevelEnd;
    float fDelta;
    float fDetect;
    int   iMaxPosi;
    float fDPDFLocalMax;
    float fNegtive;
    int   iShiftNumber;
    bool  bCombustion;
    bool  bOilSupply;
    float fEngineSpeed;
    int   iaStartPosi;      //提取数据时的第一个起始点位置
    bool     bOrgFileOpened;
    lFileHeadStruct LFHS;  //气缸压力的文件头
    unsigned char *strTempData;
    float  fAbMax;
    float fAbMMax[100];           //用来保存所采集的各个波形的峰值 .
    int iAbStartPosi;
    float fAllAngle;              //数据模板距离上止点的角度  4D为35度，11为34.5度
//    float fDeltaAngle;
    bool bPLog;                   //当需要对值幅值时，bPLog = true;
    bool bTDPosiCalculated;
    AnsiString strTrainType;            //
    AnsiString strTrainNumber;
    AnsiString strDieselNumber;
//数据处理时需要的变量
//--------------------------------------------------------------------
    float *fQL;
    float *Fuel_burn;             //燃油消耗率
    float *fAQ;                   //散热率
    float *fTT;                   //缸内气体温度
    float *fOldP;                 //最原始的压力值 ,测量值的叠加值
    float *fNewP;                 //测量得到的气缸压力
    float *fPBuffer;              //用于消除通道效应的数据缓冲区
    float *fCDHDF;                //累积放热率
    float *fDHDF;                 //计算所得的放热率
    float *fFFFai;                //压力值所对应的曲轴转角
    float *farDVDF;               //绝热过程的容积变化过程
    float *farDPDF;                 //压力升高率
    float *farV;                    //气缸容积
    float *farLogP;                 //气缸压力对数值
    float *farLogV;                 //气缸容积对数值
    float *farFFTPr;                //压力FFT的实部
    float *farFFTPi;                //压力FFT的虚部
    float *farW;                    //所作的功
    float *farDW;                   //瞬时功
    float *farQW;                   //散热量
    float *farDQW;                  //瞬时散热量
    float *farQA;                   //总放热率
    float *farDQA;                  //瞬时放热率
    float *farQE;                   //内能+功
    float *farDQE;                  //瞬时 内能+功
//=========================================================================

//预处理时需要的数据
//-------------------------------------------------------------------------
    int * ipACData[PASSAGENUM];     //作为累加数据的缓冲     ,最大长度8K
    int * ipAData[PASSAGENUM];      //用于保存提取出来的数据，  最大长度8K, 共有空间56K,占去了24K
    int * ipOData[PASSAGENUM];      //用于保存三个通道的采样值，最大长度为64K
    int * fOBuffer;
    float *fpFData;                 //用于保存滤波以后的数据
    float *fpSMData;                //光顺后的数据
    float *fpSMDPDF;                //用光顺数据计算出来的压力升高率
    float *fpDPDF;                  //用于保存压力升高率的缓存区
    float *fpOilP;                  //用于保存燃油压力
    float fDeltaP;
    int * ipData;
    int * ipa;
    int * ipac;
    short int *siConvertBuffer[PASSAGENUM]; //以原始数据格式保存提取出来的数据
    int     iCylinderNum;
    float   fStartAngle;
    l3DInfo my3DInfo[16];
    float** f3DData;          //用于保存绘制3D图形的空间
//=========================================================================
//各物理量的最大值
//-------------------------------------------------------------------------
    int iDeleteNum;               //剔除的数据样本个数
    int iSampleNum;               //提取出来的数据样本个数
    int iNormalLength;            //按角度提取出来的数据长度
    int iPLength;                 //气缸压力数据的长度
    int iOriginalLength;          //原始数据的长度
    int iAbstractLength;          //提取的数据的长度
    int iFFTLength;               //FFT变换后的数据长度

    float fFirstDHDFMax;            //放热率的第一个峰值大小
    float fFaiFirstDHDFMax;         //放热率的第一个峰值的角度
    float fDHDFMax;

    float fCPMin,fCPMax,fCPMaxPosi; //缸压最小值及最大值、最大值所在角度
    float fMaxOldP,fMinOldP,fMaxOldPPosi;        //原始数据中的最大值及最小值
    float fCVMin,fCVMax;            //气缸容积最小值及最大值
    float fMinFFTP,fMaxFFTP;        //FFT变换后的最大值及最小值
    float fDPDFMin,fDPDFMax,fDPDFMaxPosi; //压力升高率最小值及最大值、最大值位置
    float fNormalPMin,fNormalPMax,fNormalPMaxPosi;  //提取出来的数据压力最小值、最大值
    float fLogPMin,fLogPMax;
    float fLogVMin,fLogVMax;
    float fFFFaiMin,fFFFaiMax;
    float fDVDFMin,fDVDFMax;         //气缸容积的变化率的
    float fHRRMin,fHRRMax;           //放热率的最大值及最小值
    float fCHRRMin,fCHRRMax;         //累积放热率的最大值及最小值
    float fOilPMin,fOilPMax;         //油管压力检测数据的最小值及最大值
    float fOilPMinPosi,fOilPMaxPosi;
    float fTMin,fTMax;               //缸内气体温度的最大值及最小值
    float fWMin,fWMax;               //累积功的最大值及最小值　
    float fDWMin,fDWMax;             //作功的最大值　及最小值
    float fPMaxFai;
    float fTMaxFai;
    float fDPDFMaxFai;
    float fDHDFMaxFai;
    float fCDHDFMaxFai;
    float fWMaxFai;
    int iStartFai,iEndFai;
//=========================================================================
    int icStartPosi,icEndPosi;    //进气门关和排气门开的位置
    float fcStartP;
    bool  bPP0;                   //true:设置了数据 false:没有设置数据
    float fST0;                   //通道1的标定系数
    int   iTopPosi[50];
    int   iTopNum;
    float fPpm;
    float fBarP0;
    int   iTDPosiBackup;
    int   iTDCStep;

    float fAngleStep;             //曲轴转角间隔
    float fDeltaAngle;            //从上止点到纯压缩压力变化率最大值的曲轴转角的估计值(暂时定为16度)
    bool  bPP1;                   //意义同上
    bool  bPP2;                   //意义同上
    int iDieselNum;               //气缸编号
    float fTimeInterval;             //信号的采样频率
    float fPressureLevel;         // 增压器的出口压力(Pa)

    float fOilAngle;              // 供油始点
    float fCombustionAngle;       // 燃烧始点
    float fCombustionPeriod;      // 燃烧持续时间

    bool  bParameterAbstracted;   //用于标识是否对各个参数进行了计算
    int   iTDPosi;                  //上止点位置
    int   iCombustionPosi;          //燃烧始点
    int   iOilPosi;                 //供油始点
    float fBarToPa;               //由Bar向Pa转换时的常量
    float fCPower;

    __fastcall lDieselHRBP(void);
    __fastcall ~lDieselHRBP(void);
    void __fastcall OnlyPressCalc(void);
    void __fastcall OnlyPress(void);
    void __fastcall OnlyPressFun(int l, double * yy, double * f,double fai,double dfai);
    void __fastcall OnlyPress(int n, double * yy, double fai, double dfai);


    //使用天津大学的放热率计算方法
    void __fastcall TJHeatRelease(void);
    void __fastcall SmoothCurve(float &fp,int iposi);
    float __fastcall CalculateTENB(float fT, float * fA);
    float __fastcall CalculateFDQ(float fp, float ft, float fx);
    void __fastcall  GetArea(float ffai,float& farea );
    bool __fastcall  SetRealPressure(float* fp,float*ffai,int ilen);
    bool __fastcall  SetRealPressure(char *fname);
//    void __fastcall  SmoothCurve(float &fp,int iposi);
    bool __fastcall  GetfU(char *strfilename);
    float __fastcall GetVolumn(float fai, float & fv);
    float __fastcall GetfX(float ffai);
    float __fastcall Cva(float Te);
    float __fastcall Cvb(float Te);
    void  __fastcall SetDrawKind( int idrawkind)
    {
         lsAllDrawKind = (drawKind)idrawkind;
    };
    bool  __fastcall GetbCombustion(void)
    {
        return bCombustion;
    };
    void  __fastcall SetiTopDeadPosi(int fl)
    {
         iTopDeadPosi = fl;
    };
    void  __fastcall SetfDisp(int fl)
    {
        iDisp = fl;
    };
    void  __fastcall SetiIteration(int ii)
    {
        iIteration = ii;
    };
    void  __fastcall SetfTW(float *ft)
    {
        fTW[0] = ft[0];
        fTW[1] = ft[1];
        fTW[2] = ft[2];
    };
    void  __fastcall SetfEn(float fe)
    {
        fEn = fe;  //柴油机转速
    };
    void  __fastcall SetfDFai(float fd)
    {
        fDFai = fd;  //计算步长
    };
    void  __fastcall SetfKConst(float fk)
    {
        fKConst = fk; //比热比
    };
    void  __fastcall SetfKCoef(float fk)
    {
        fKCoef = fk;  //比热比系数
    };
    void  __fastcall SetfK(float fk)
    {
        fK = fk;
    };
    void  __fastcall SetfTWater(float ft)
    {
        fTWater = ft;         //冷却水温度
    };
    void __fastcall SetfTAir(float ft)
    {
        fTAir = ft ;           //空气温度
    };
    void __fastcall SetfPAir(float fp)
    {
        fPAir = fp;           //空气压力
    };
    void __fastcall SetfTTop(float ft)
    {
        fTTop = ft;            // 气缸顶面温度    可近似取冷却水温度   80
    };
    void __fastcall SetfTWall(float ft)
    {
        fTWall = ft;           //气缸套外温度     可近似取为冷却水温度 80
    };
    void __fastcall SetfTBottom(float ft)
    {
        fTBottom = ft;         //活塞底温度       可近似取为曲轴箱温度 70
    };
    void __fastcall SetfALPHA(float fa)
    {
        fALPHA = fa;                  //过量空气系数
    };
    void __fastcall SetfGAMA( float  fg)
    {
        fGAMA = fg;                   //废气残余系数
    };
    void __fastcall SetfHRConst(float fh)
    {
        fHRConst = fh;   //传热系数
    };
    void __fastcall SetfAverSpeed(float fa)
    {
        fAverSpeed = fa;  //柴油机平均速度　
    };
    void __fastcall SetfLCoef(float fl)
    {
        fLCoef = fl;      //漏气系数
    };
    void __fastcall SetfR(float fr)
    {
        fR = fr;          //气体状态常数
    };
    void __fastcall SetfTW(float ft)
    {
        fTw = ft;         //壁面温度
    };
    void __fastcall SetfA(float fa)
    {
        fA = fa;          //热功当量
    };
    void __fastcall SetfGG(float fg)
    {
        fGG = fg;         //重力加速度
    };
    void __fastcall SetbAbsolute(bool ba)
    {
        bAbsolute = ba;     //绝热与实际过程的
    };
    void __fastcall SetfRMOL(float fr)
    {
        fRMOL = fr;                  // 气体摩尔数
    };
    void __fastcall SetfLO(float fl)
    {
        fLO = fl;                    //理论空气量 mol/kg燃料
    }
//　燃油参数
    void __fastcall SetfNC(float fn)
    {
        fNC = fn;                    //燃料中的碳原子数
    };
    void __fastcall SetfMH(float fm)
    {
        fMH = fm;                    //燃料中的氢原子数
    };
    void __fastcall SetfHU(float fh)
    {
        fHU = fh;                    //燃料的低热值(J/kg)
    };
    void __fastcall SetfGF(float fg)
    {
        fGF = fg;                    //一次喷油的燃油重量
    };
    void __fastcall SetfTF(float ft)
    {
        fTF = ft;                    //一次喷油的持续时间
    };

//　计算开始时的状态参数
    void __fastcall SetfP0(float fp)
    {
        fP0 = fp;           //进气门关闭时的进气压力
    };
    void __fastcall SetfT0(float ft)
    {
        fT0 = ft;           //进气门关闭时的进气温度
    };
    void __fastcall SetfLowPressure(float flp)
    {
        fLowPressure = flp;     //低压修正值
    };
    float __fastcall getSpeed( void )
    {
        return fEn;
    };
    float __fastcall getPower(void)
    {
        return fCPower;
    }
    float __fastcall getOil(void)
    {
        return fCHRRMax*1000000.0/fHU;   //克
    }
    void __fastcall ProcessPressure(int iMethod);
//争取将张延峰的程序修改一下，对实际的数据进行模拟
    void __fastcall ZYFHeatRelease(void);
    void __fastcall DetectTopDeadPosi(void);
    bool __fastcall AllocateMemory(int inum);
    void __fastcall DeleteMemory(void);
    void __fastcall CalculateCHRR(void);
    bool __fastcall ReadOriginalData(char *strfileName,bool bCalculate);
    bool __fastcall AllocateOriginalMemory(int inum);
    bool __fastcall AllocateAbstractMemory(int inum);    
    void __fastcall DeleteOriginalMemory(void);
    void __fastcall DeleteAbstractMemory(void);
    bool __fastcall AbstractData(void);
    int __fastcall DetectPosi(void);
    bool __fastcall AbstractFromFile(char* filename);
    bool __fastcall SaveAbstractedData(char * sfilename);
    float __fastcall dqwc(float ft,float *faa,float *tw);
    bool __fastcall AnEveryMemory(float * fPointer,int ilen);
    void __fastcall DeEveryMemory(float* fPointer);
    void __fastcall CalculateDPDF(void);
    bool __fastcall CalculateFFTP(void);
    void __fastcall CalculateLogVLogP();
    void __fastcall GetMinMax(float * fdata, int ilen, float& fmin, float & fmax,float &fmaxfai,bool bAngle);
    void __fastcall ModifyPressure(float* fp,int inum); //修正低压部分

    

//  FX： 后加上，主要计算第二通道的提取长度
   int __fastcall GetfEn2_length(bool bFrom,int iP,float fFre);



// 以下各函数是铁科院机辆所严志强提供的    
//=====================================================
    void __fastcall CarsSMOOTH(void);
    float __fastcall CarsLAQ(float fai);
    void __fastcall CarsRTDC(void);
    void __fastcall CarsFW(void);
    void __fastcall CarsFV(void);
    void __fastcall CarsFT(void);
    void __fastcall CarsCHH(void);
    void __fastcall CarsPDS(void);
    void __fastcall CarsSUB(void);
    void __fastcall CarsGS(void);
    void __fastcall CarsLSN(void);
    void __fastcall CarsFJM(void);
    void __fastcall CarsFXM(void);
    void __fastcall CarsCHP(void);
    void __fastcall CarsMUC(void);
    void __fastcall CarsHeatRelease(void);
    void __fastcall DetectCPosi(void);
    void __fastcall LrwHeatRelease(void);
    void __fastcall GetFirstPeak(float * fdata, int ilen, float & fmax, float & ffai);

//以下处理函数来自于　测试仪系统软件，主要用数据处理及计算
//----------------------------------------------------------------------------------
    float __fastcall GetfEn(bool bFrom,int iP,float fFre);
    void __fastcall AccuratePosi(int ip, int& iposi1, int & iposi2);
    void __fastcall GetParameters(void); //用于获得供油始点，燃烧始点等
    void __fastcall lFilterData(float* fhh, int ihlen);
    void __fastcall CalibrateData(float *fnew, float* fold, int ilen);
    void __fastcall LocatePeak(void);     //用于确定数据位置并且提取
    void __fastcall GetfST0(int ip);
    void __fastcall lDPDF(int *ip,int *idpdf,int ilen);   //用于计算整型数的变化量
    void __fastcall lDPDF(float *fp,float* fdpdf,float* fang,int ilen);  //用于计算
    void __fastcall lDPDF(float *fp,float*fdpdf,int ilen);
    void __fastcall GetLogPLogV(void);  //用于获取压力与容积的对数据值
    void __fastcall AbstractNormalP(void); //从压力数据中提取压力值每隔0.5度，取出一个点
    void __fastcall CalculatePower(void);      //计算此循环的功
    int __fastcall DetectPosi(int * ipa, int *ipac);
    void __fastcall ModifyTDC();
    void __fastcall lDirectData(void);
    void __fastcall lSmoothCurve(float * forig, float * fnew, int ilen);
    void __fastcall lFilterData(float* fold, float* fnew, int ilen,int iH);
    bool __fastcall ConverToPCP(AnsiString& strFileName);
    bool __fastcall LoadPCPFile(char * strfilename);
    void __fastcall iGetMinMax(int* idata, int ilen, int& imin, int& imax, int& imaxposi);
    void __fastcall SetArrayZero(float* fdata, int idatalen, int izlen);
    bool __fastcall ChangeSensitivity(char * strfilename);
    void __fastcall Set3DData(int ipart, int idrawkind);
    bool __fastcall Allocate3DMemory(void);
    void __fastcall Delete3DMemory(void);
    void __fastcall NormalData(void);
    int __fastcall GetTopDead(void);
    void __fastcall lFilterOriginal(float * fhh, int ihlen, int ip);
    void __fastcall CalibrationData(void);
    bool __fastcall ReadOriginalData_New(char* strfileName, bool bCalculate);
    bool __fastcall ReadOriginalDataHead(char* strfileName);
    bool __fastcall ReadOriginal(char* strfileName, bool bCalculated);
    float __fastcall GetFrequency(short int iindex);
    void __fastcall DetectTopDeadPosi_New(void);
    void __fastcall GetCPMinMax(float * fdata, int ilen, float& fmin, float& fmax);
    void __fastcall GetDrawSlope(int &istart, int &iend);
    void __fastcall CorrectOilPosi(void);
    float __fastcall GetPressureAngle(float fangle);
    void __fastcall HeatRelease(void);
    float __fastcall AnalysisOilAngle(int istart);
//    bool __fastcall IsCombustionExists(void);
    bool __fastcall GetPCPHead(AnsiString& strfilename);
    bool __fastcall DetectTopDeadPosi_New_Two(void);
    void __fastcall SetTrainInfo(void);
    void __fastcall GetValidPipe(float* fp, int istart, int ilen);
    bool __fastcall LoadPCPFromRAM(TMemoryStream* pms);
    void __fastcall GetHeatPeak(float* fdata, int ilen, float& fmax, float& ffai);
    void __fastcall CalculateFactor(void);
    float __fastcall CalculateOilPosi(void);
    void __fastcall CalculateOilParameters(void);
        void __fastcall CompressData(void);   //上止点后的数据调整
//=======================================================
//获取的数据中有三个参数，初步将它定为第一通道为气缸压力，第二通道为油管压力，第三通道为上止点信号

};

class lCPressure
{
private:
    lFileHeadStruct LFHS;  //气缸压力的文件头
    int iPLength;          //气缸压力的数据长度
    float *fNewP;
    float *fFFFai;
    float fLowPressure;    //修正的低压部分
public:

    __fastcall lCPressure(void);
    __fastcall ~lCPressure(void);
    bool __fastcall GetRealPressure(char *strfilename);
    void __fastcall SmoothCurve(float &fp,int iposi);
};
#endif

