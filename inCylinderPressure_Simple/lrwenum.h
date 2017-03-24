#ifndef  _LRWENUM_H_
#define  _LRWENUM_H_
enum enumDrawDevice { ddPaintBox,ddPrinter,ddImage };
enum TCommandState {csCopy,csCut,csNone};
enum drawKind
{
    drawAll,         //全部数据
    drawPT,          //原始数据
    drawCPT,         //修正后的数据
    drawPV,          //容积压力图
    drawFFTP,        //压力频谱图
    drawLogVLogP,    //容积压力对数图
    drawDPDF,        //压力升高率
    drawHRR,         //放热率曲线
    drawCHRR,        //累积放热率
    drawTT,          //气缸内温度
    drawOriginal,    //原始数据
    drawW,           //累积功
    drawDW,          //瞬时功
    drawMAX,         //各缸各项的最大值
    drawPWave,       //绘制高压油管压力
    drawPPWave,      //绘制气缸压力及高压油管压力
    drawInfo,        //显示基本参数
    drawDetect,       //显示参数及分析结果
    drawPWaveResult   //显示压力波对比结果
};

struct l3DInfo
{
    float fMaxValue;
    float fMaxAngle;
    int   iDieselNum;
    int   iTopDeadPosi;
};

#endif
 