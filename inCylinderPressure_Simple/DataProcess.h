#ifndef LDATAPROCESSH
#define LDATAPROCESSH
#include <Graphics.hpp>
#include <ExtCtrls.hpp>
#include <stdio.h>
const int iMaxFilterLength = 99;
class lFIR
{   //有限冲击响应数字滤波器
	int iFilterLength;    // 滤波器长度
    int iWindowChoice;    //窗函数类型选择
    int iFilterKind;      //滤波器类型　
    float fPassFL,fPassFH,fStopFL,fStopFH; //频带参数
    float fSampleRate;    //采样频率
    bool bAdvanced,bAutoLength;
public:
      __fastcall lFIR(void)
      {
      		bAdvanced=false;
            bAutoLength=false;
      }
	void __fastcall SetbAutoLength(bool al,int len)
    {
    	bAutoLength=al;
        iFilterLength=len;
    };
    void __fastcall SetbAdvanced(bool ba)
    {
    	bAdvanced=ba;
    };
	void __fastcall SetiWindowChoice(int wc)
    {
    	iWindowChoice=wc;
    };
    void __fastcall SetiFilterKind(int fk)
    {
    	iFilterKind=fk;
    };
    void __fastcall SetfSampleRate(float sr)
    {
      	fSampleRate=sr;
    };
    void __fastcall SetFrequency(float pfl,float pfh,float sfl,float sfh)
    {
    	fPassFL=pfl;
        fPassFH=pfh;
        fStopFL=sfl;
        fStopFH=sfh;
    };
	void __fastcall GenerateFilter(float* h, int& num);
	float __fastcall WinFunction(int i);

};


class lDataProcess
{
private:
	float m_trainerror,m_studyrate;
	bool m_showtraining;
	int m_waveletselection;
	double m_cc;
	String FileName;
	int m_column,m_data_column,m_uunum;
	float *OriginalData;
	float *xc,*xs,*xm;
    float *a[6],*b[6],*aa[6];
	int DataNum;
	bool FileOpenHD,DFileOpenHD;
	int Level;
    int iCalculationMethod;
	float ChValue[18];
	int m_faultcase;
    bool bMAFFT,bMAWAVELET,bMATIMEWINDOW;


//剔除趋势项时使用的变量
	float A1,A2,A3,A11,A22,A33,A31;
	float B1,B2,B3;
    int N,KK,IVM;
    int iCStart,iCEnd;
    float *X,*Y;
  	float F[4];
public:
    void __fastcall ReadBPData(void);
	void __fastcall Wavelet(void);
	void __fastcall FFT(int inv);
    void __fastcall BeginFFT(bool btf);
    void __fastcall BeginWavelet(void);
	void __fastcall ReadData(void);
    void __fastcall GetTimeAverageResult(float* fmo);
    bool  __fastcall SetData(float* SourceData,int num,int bfw);
    __fastcall lDataProcess();
    __fastcall ~lDataProcess()
    {
    };
    void __fastcall Delete(void);
    void __fastcall GetFFTResult(float *fr,float *fe,float* fm);
    void __fastcall GetWaveletResult(float **fa,float **fb,float **faa);
    void __fastcall BeginTimeAverage(int winlen);
    bool __fastcall LBeginFFT(float * fxc, float * fxs, float * fxm, int ilen, bool binv);
    void __fastcall FFT(float * fxc, float * fxs, float * fxm, bool inv);
    bool __fastcall LBeginRemoveTendency(float *aa,float *bb,int Num,int iStart,int iEnd,int wnum,int kk);
    void __fastcall COEF(void);
    void __fastcall RESULT(int IT);
    bool __fastcall lFilterData(int * fodata,int *fddata,int ilen,float *h, int ihlen);
    bool __fastcall lFilterData(float * fodata, float *fddata,int ilen,float *h,int ihlen);
    bool __fastcall LWaveletProcess(float * fdata, float ** fa, float ** fb, float ** fwa, int ilen);
    void __fastcall IntegralData(float * fodata, int idatalen, float finterval, int * iPhase, int iPhnum, float * fresult);
    void __fastcall MaxAndAverage(float * fodata, int ilen, float & fmax, float & faverage, float & fgv);
    void __fastcall GetWaveletParameter(float * fodata, float ** fa, int ilen, float* fresult);
//        void __fastcall A
};

#endif  LDATAPROCESSH
