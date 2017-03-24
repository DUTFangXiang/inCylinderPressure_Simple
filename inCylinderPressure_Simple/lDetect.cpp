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
// �����ṩ�Ĳ������з���
// ȼ����ѹ�����̵��Ƿֿ����еġ�
// ��Ҫ���ǵĲ����У�
//                (1) ���ȼ��ѹ��     ��е����
//                (2) ѹ��ѹ���������� �����ܷ�״̬
//                (3) ƽ��ָʾѹ��     ������ڹ������̵�Ч��
//                (4) ѹ�����ʸ�       �ֱ��̶Ⱥͳ������
//                (5) ��������ת��     ��ȼ�ڣ�����ʼ���Ƿ�����
//                (6) �Ż�����ת��     �Ż�ʱ���Ƿ����
//                (7) ���ȹ���         ���ֵ
//                (8) ȼ�ճ���ʱ�䡡�� ȼ�յ����Ƴ̶�
//-------------------------------------------------------------------
//                (9) ����ѹ�����ֵ�� �����жϸ�������ѭ���Ƿ����
//                (10)���׶�������     �Ƿ����
//                (11)�����ۻ�������   �Ƿ����
//===================================================================
// ���⻹�У����� (12) ����ѹ�����ֵ���ڽǶ�
//                (13) ѹ�����������ֵ���ڽǶ� ��

// ��һ��������������ǰ���Ƿ�����
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
//  ȥ���������ֵ��ȥ��������Сֵ�����ƽ��ֵ
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
// �����ֵ������ֵ4����Ӧ��ʾ
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
//  ȥ���������ֵ��ȥ��������Сֵ�����ƽ��ֵ
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
// �����ֵ������ֵ4����Ӧ��ʾ
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
            if(!(mbInfo.barCombustion[i]))   //����ø�ȼ��ѹ��С��2.9MPa������ʾ�˸ÿ���������
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
//  ȥ���������ֵ��ȥ��������Сֵ�����ƽ��ֵ
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
// �����ֵ������ֵ4����Ӧ��ʾ
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
//  ȥ���������ֵ��ȥ��������Сֵ�����ƽ��ֵ
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
// �����ֵ������ֵ4����Ӧ��ʾ
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
//  ȥ���������ֵ��ȥ��������Сֵ�����ƽ��ֵ
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
// �����ֵ������ֵ4����Ӧ��ʾ
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
// ����ͳ�Ʋ��Ż�׵ĸ������ֲ�����λ�ڲ��ͻ���໹���Ҳ�
    float fbuffer[16];
    float ftemp;
    int inum;
    int iPosi;
    inum = mbInfo.iCyNums;
    MeanInfo.iNFNums  = 0;   //û���Ż�ĸ���
    MeanInfo.iNFLeftNums  = 0;   //1~8��û���Ż�ĸ���
    MeanInfo.iNFRightNums = 0;  //9~16��û���Ż�ĸ���
    fPowerLimit = 0.0;
    for( int i = 0; i < inum; i ++)
    {
        fPowerLimit += mbInfo.farCPower[i];
    }
    fPowerLimit /= (float)inum;
    fPowerLimit *= 0.25;
    for(int i = 0; i < inum; i ++)
    {
        if(   (!mbInfo.barCombustion[i])  //���û�д���ȼ��״̬
            ||(mbInfo.farCPower[i] <= fPowerLimit)  //ѹ��ֵ��С,�ö�������������
        )
        {
            MeanInfo.iNFNums ++;  //ʹû���Ż�ĸ�����1

            iPosi = mbInfo.siarDieselNum[i];
            if( (iPosi >= 1)&&(iPosi <= 8))  //�����
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
// ���ڶ��������жϸ��׵Ĺ�����ǰ��

    float fbuffer[16];
    float ftemp;
    int inum;
    int iPosi;
    inum = mbInfo.iCyNums;
    MAngleInfo.iNFNums  = 0;   //û���Ż�ĸ���
    MAngleInfo.iNFLeftNums  = 0;   //1~8��û���Ż�ĸ���
    MAngleInfo.iNFRightNums = 0;  //9~16��û���Ż�ĸ���
    for(int i = 0; i < inum; i ++)
    {
        if( mbInfo.farOilAngle[i] < fAngleMax )
        {
            MAngleInfo.iNFNums ++;  //ʹ�й��ϸ׼�1
            MAngleInfo.iNFLIndex[MAngleInfo.iNFLeftNums]    = mbInfo.siarDieselNum[i];
            MAngleInfo.fNFLPressure[MAngleInfo.iNFLeftNums] = mbInfo.farPMax[i];
            MAngleInfo.fNFLAngle[MAngleInfo.iNFLeftNums]    = mbInfo.farOilAngle[i];
            MAngleInfo.iNFLeftNums ++;
        }
        else if((mbInfo.farOilAngle[i] > fAngleMin)) //������ǰ�ǲ�����
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
// ���ڶ��������жϸ��׵�ѹ��ѹ��

    float fbuffer[16];
    float ftemp;
    int inum;
    int iPosi;
    inum = mbInfo.iCyNums;
    MCompInfo.iNFNums  = 0;   //û���Ż�ĸ���
    MCompInfo.iNFLeftNums  = 0;   //1~8��û���Ż�ĸ���
    MCompInfo.iNFRightNums = 0;  //9~16��û���Ż�ĸ���
    for(int i = 0; i < inum; i ++)
    {
        if( (mbInfo.farPMax[i]  < fCompressMin))  //������ǰ�ǲ�����
        {
            MCompInfo.iNFNums ++;  //ʹ�й��ϸ׼�1
            MCompInfo.iNFLIndex[MCompInfo.iNFLeftNums]    = mbInfo.siarDieselNum[i];
            MCompInfo.fNFLPressure[MCompInfo.iNFLeftNums] = mbInfo.farPMax[i];
            MCompInfo.fNFLAngle[MCompInfo.iNFLeftNums]    = mbInfo.farOilAngle[i];
            MCompInfo.iNFLeftNums ++;
        }
        else if( mbInfo.farPMax[i]    > fCompressMax)  //
        {
            MCompInfo.iNFNums ++;  //ʹ�й��ϸ׼�1
            MCompInfo.iNFRIndex[MCompInfo.iNFRightNums]    = mbInfo.siarDieselNum[i];
            MCompInfo.fNFRPressure[MCompInfo.iNFRightNums] = mbInfo.farPMax[i];
            MCompInfo.fNFRAngle[MCompInfo.iNFRightNums]    = mbInfo.farOilAngle[i];
            MCompInfo.iNFRightNums ++;
        }
    }
}
