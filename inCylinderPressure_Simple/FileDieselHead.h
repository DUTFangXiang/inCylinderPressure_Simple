#ifndef __FileDieselHead_H__
#define __FileDieselHead_H__
struct StructDieselInfo
{
    unsigned char chCommandMark;   //ӦΪ0x99
    unsigned char chDieselGroup;   //���
    char  chTemp[2];               //����2���ֽ�
    float fDiameter;               //����ֱ��
	float fStroke;                 //�������
	float fLMDa;                   //�������˱�
	float fCRatio;                 //ѹ����
	float fPodLength;              //���˳���
	float fInCloseAngle;           //�����ſ����Ƕ�
	float fOutOpenAngle;           //�����ŹرսǶ�
	float fCAING;                  //���ͽǶ�
    float fCompressMax;            //ѹ��ѹ�����ֵ��
    float fCompressMin;            //ѹ��ѹ����Сֵ
    float fOilAngleMax;            //������ǰ�����ֵ��
    float fOilAngleMin;            //������ǰ����Сֵ��
    float fCombustionAngleMax;     //ȼ����ǰ�����ֵ��
    float fCombustionAngleMin;     //ȼ����ǰ����Сֵ
    float fDetectLevel;                   //������1��������
};
#endif
 