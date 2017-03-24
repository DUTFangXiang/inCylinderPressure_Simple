#ifndef MAX_INFO_H
#define MAX_INFO_H
//---------------------------------------------------------------------------
struct MaxBuffer
{
    int iCyNums;         //һ�����˼�����
    bool bCombustion;    //�Ƿ���ȼ��״̬
    float COMBUSTION_LEVEL;
//----------------------------------------------
    float fESMax;        //ת�����ֵ
    float fESMin;        //ת����Сֵ
    float fESMean;       //ת��ƽ��ֵ
    float fCCPower;      //ָʾ����

    float fPMax;         //�������ѹ��
    float fPMin;         //��С����ѹ��
    float fDPDFMax;      //���ѹ��������
    float fDPDFMin;      //��Сѹ��������
    float fDHDFMax;      //��������
    float fDHDFMin;      //��С�����ʡ�
    float fCDHDFMax;
    float fCDHDFMin;
    float fTMax;         //����¶�
    float fTMin;         //����¶�

    float fDWMax;
    float fDWMin;

    float fWMax;         //���������Ĺ�
    float fWMin;         //������������Сֵ

    float fOilPMax;       //�͹�ѹ���������ֵ
    float fOilPMin;       //�͹�ѹ��������Сֵ

    float fOPMax;        //ԭʼ�������ֵ
    float fOPMin;        //ԭʼ������Сֵ
    float fVMax;         //�ݻ����ֵ
    float fVMin;         //�ݻ���Сֵ

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

    float farMaxPAngle[16];        //���ȼ��ѹ����������ת��
    float farMaxDPAngle[16];       //���ѹ������������ת��
    float farMaxDHAngle[16];       //�������ʶ�Ӧ������ת��
    float farCombustionAngle[16];  //ȼ�տ�ʼ�Ƕ�
    float farOilAngle[16];         //���Ϳ�ʼ�Ƕȡ�
    float farWavePeriod[16];
    float farCPower[16];           //�����

    float farCDHDFMax[16];
    float farCDHDFMin[16];
    float farPMax[16];         //�������ѹ��
    float farPMin[16];         //��С����ѹ��
    float farDPDFMax[16];      //���ѹ��������
    float farDPDFMin[16];      //��Сѹ��������
    float farDHDFMax[16];      //��������
    float farDHDFMin[16];      //��С�����ʡ�
    float farTMax[16];         //����¶�
    float farTMin[16];         //����¶�
    float farDWMax[16];
    float farDWMin[16];
    float farWMax[16];         //���������Ĺ�
    float farWMin[16];         //������������Сֵ
    float farOilPMax[16];       //�͹�ѹ���������ֵ
    float farOilPMin[16];       //�͹�ѹ��������Сֵ
    float farOPMax[16];        //ԭʼ�������ֵ
    float farOPMin[16];        //ԭʼ������Сֵ
    float farVMax[16];         //�ݻ����ֵ
    float farVMin[16];         //�ݻ���Сֵ
    float farLogVMax[16];
    float farLogVMin[16];
    float farLogPMax[16];
    float farLogPMin[16];
    float farFFTMax[16];
    float farFFTMin[16];
    
//-----------------------------------------------------------
    float farCombustionPeriod[16];  //ȼ�ճ���ʱ��
    float farAverageP[16];          //ƽ��ָʾѹ��
    float farFlexP[16];             //����ѹ���Ĳ������
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
        
        GetMax(farEngineSpeed,fESMax, false);        //ת�����ֵ
        GetMin(farEngineSpeed,fESMin, false);        //ת����Сֵ
        GetMean(farEngineSpeed, fESMean);
        CalculatePower();                            //������ͻ���ָʾ����
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
    int iDieselNum;      //�׺�
    float fPMax;         //�������ѹ��
    float fDPDFMax;      //���ѹ��������
    float fDHDFMax;      //��������
    float fTMax;         //����¶�
    float fWMax;         //���������Ĺ�

    float fFDHDFMax;     //�����ʵ�һ��ֵ
    float fFaiPMax;      //�������ѹ������Ӧ������ת��
    float fFaiDPDFMax;   //���ѹ�������ʶ�Ӧ������ת��
    float fFaiDHDFMax;   //�������ʶ�Ӧ������ת��
    float fFaiTMax;      //����¶ȶ�Ӧ������ת��
    float fFDHDFMaxFai;  //�����ʵ�һ��ֵ��Ӧ������ת��
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

//�˽ṹ�������������ݷ���
struct structDetect
{
    bool  bDataValid;         //��һ�����Ƿ�
    int   iDieselNum;         //���ͻ��׺�
    float fDieselSpeed;       //���ͻ�ת��

    float fCPMax;             //���ѹ��
    float fDPDFMax;           //ѹ�����������ֵ
    float fInletPressure;     //��������ѹ��

    float fOilAngle;          //������ǰ��
    float fOilPeak;           //�����ֵ
    float fOilPeriod;         //���ͳ�����
    float fOilCoef;           //����ϵ��

    float fCombustionAngle;   //ȼ��ʼ��
    float fCombustionPeriod;  //ȼ�ճ���ʱ��
    float fDHDFMax;           //���������ֵ
    float fHAll;              //�ۻ�������
    float fCPower;            //ѭ����

    float fComPressure;       //��һ�׵�ѹ��ѹ��
    
    bool  bComValid;          //ѹ��ѹ���Ƿ���Ч  true:��Ч  false:��Ч
    short int siPower;        //����������1������0����������1����С
    short int siPMax;         //����ѹ����1������0����������1����С
    short int siComPressure;  //ѹ��ѹ����1������0����������1����С
    short int siOilAngle;     //1������0����������1����С
    short int siOilPeriod;    //1������0����������1����С

    AnsiString strResult;     //��������
};
#endif
