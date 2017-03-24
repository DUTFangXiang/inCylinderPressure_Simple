#ifndef LPPWFDREAD__H
#define LPPWFDREAD__H
#include "lfilehead.h"
#define IFILEHEADLENGTH 32
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
class cPPWFDRead    //Pipe Pressure  Wave Form
{
private:
//        int iFileHead[IFILEHEADLENGTH];
        String strFilePath,strFileListName[100],strFileName,strFileExtend;
        int iCylinderRead[16];
        int iListFileNum;
        int iIPosi;
        int iINum;
        int iAllNum;
        int iStepNum;
        TListBox* ptListBox;
        AnsiString strTrainType;  //³µÐÍ
        AnsiString strTrainNum;   //³µºÅ


public:
        AnsiString strListBuffer;
        __fastcall cPPWFDRead(void);
        void __fastcall SetTrainInfo(AnsiString& strTT,AnsiString& strTN);
        void __fastcall ResetCylinder(void);
        void __fastcall SetFilePath(char *fp);
        void __fastcall SetptListBox(TListBox* tlb);
        void __fastcall GenerateFileList(void);
        void __fastcall ReadDataFile(void);
        void __fastcall SetstrFileExtend(String& fe)
        {
            strFileExtend = fe;
        };
        void __fastcall SetPosiAndNum(int ip,int in)
        {
            iIPosi = ip;
            iINum = in;
        };
        void __fastcall SetiAllNum(int ian)
        {
            iAllNum = ian;
        };
        bool __fastcall ReadPipeWaveData(char* fn, lFileHeadStruct& lfhs, float* fxdata, float* fydata);
        bool __fastcall ReadPipeWaveData(char* fn, lFileHeadStruct& lfhs,float* iydata);
        bool __fastcall ReadPipeFileHead(char* fn,lFileHeadStruct& lfhs);
};
#endif

 