#ifndef  _LRWENUM_H_
#define  _LRWENUM_H_
enum enumDrawDevice { ddPaintBox,ddPrinter,ddImage };
enum TCommandState {csCopy,csCut,csNone};
enum drawKind
{
    drawAll,         //ȫ������
    drawPT,          //ԭʼ����
    drawCPT,         //�����������
    drawPV,          //�ݻ�ѹ��ͼ
    drawFFTP,        //ѹ��Ƶ��ͼ
    drawLogVLogP,    //�ݻ�ѹ������ͼ
    drawDPDF,        //ѹ��������
    drawHRR,         //����������
    drawCHRR,        //�ۻ�������
    drawTT,          //�������¶�
    drawOriginal,    //ԭʼ����
    drawW,           //�ۻ���
    drawDW,          //˲ʱ��
    drawMAX,         //���׸�������ֵ
    drawPWave,       //���Ƹ�ѹ�͹�ѹ��
    drawPPWave,      //��������ѹ������ѹ�͹�ѹ��
    drawInfo,        //��ʾ��������
    drawDetect,       //��ʾ�������������
    drawPWaveResult   //��ʾѹ�����ԱȽ��
};

struct l3DInfo
{
    float fMaxValue;
    float fMaxAngle;
    int   iDieselNum;
    int   iTopDeadPosi;
};

#endif
 