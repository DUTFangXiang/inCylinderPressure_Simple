#include "LPPFDRead.h"
#include <stdio.h>
//#include "FileHead.h"
#include "lFormMain.h"
__fastcall cPPWFDRead::cPPWFDRead(void)
{
    iListFileNum = 0;
    iStepNum = 0;
}
void __fastcall cPPWFDRead::SetFilePath(char* fp)
{
//TODO: Add your source code here
    strFilePath.printf("%s",fp);
}
void __fastcall cPPWFDRead::SetTrainInfo(AnsiString& strTT,AnsiString& strTN)
{
    strTrainType = strTT;
    strTrainNum  = strTN;
}
void __fastcall cPPWFDRead::SetptListBox(TListBox* tlb)
{
    ptListBox = tlb;
}
void __fastcall cPPWFDRead::ResetCylinder(void)
{
    for(int i=0;i<16;i++)
    {
        iCylinderRead[i]=0;
    }
}
void __fastcall cPPWFDRead::GenerateFileList(void)
{
    int iCount,iIndex;
    int iTTLen,iTNLen;
//    FormMain->ListBoxFile->ItemIndex = 0;
    iCount = ptListBox->Items->Count;
    if(iCount <= 0)
    {
        return;
    }
    FILE * ListFile;
    bool bHave;
    int iCylinder;
    String strFileFore,strFileBack,strTemp,strTemp1,strTemp2,strListName;
    iStepNum ++;
//    ResetCylinder();
    for( int i = iIPosi; i < iINum; i ++)
    {
        strFileName = ptListBox->Items->Strings[i];
        strFileFore = strFilePath;
        strFileBack = ExtractFileName(strFileName);  //获取文件名，无路径
        strFileBack = strFileBack.SubString(1,strFileBack.Length()-4);
        strFileBack += strFileExtend;
        iTTLen  = strTrainType.Length();
        iTNLen  = strTrainNum.Length();
        strTemp = strFileBack.SubString( iTTLen + iTNLen + 1,2);  //提取缸号
        iCylinder = StrToInt(strTemp);                        //将缸号转换为数字
        if( iCylinder < 1 )
        {
             iCylinder = 1;
        }
        else if( iCylinder > 16 )
        {
            iCylinder = 16;
        }
        strTemp     = strTrainType + strTrainNum
                      + AnsiString(" ")
                      + strFileBack.SubString(iTTLen + iTNLen +4,10);
        strListName = strFileFore + strTemp + ".pst";
        if(i != 0)
        {
            strTemp = strListName;
            bHave = false;
            for( int j = 0; j<iListFileNum; j++)
            {
                 if(strTemp == strFileListName[j])
                 {
                     bHave = true;
                     break;
                 }
            }
            if(!bHave)
            {
                 strFileListName[iListFileNum] = strTemp;
                 iListFileNum ++;
            }
        }
        else
        {
             strFileListName[0] = strListName;
             iListFileNum ++;
        }
        if(!FileExists(strListName))
        {
            if((ListFile = fopen(strListName.c_str(),"w")) == NULL)
            {
                return ;
            }
            strTemp = strFileBack.SubString(iTTLen + iTNLen + 1, 2);
            iCylinder=StrToInt(strTemp);
            fprintf(ListFile,"%s%s\n",strFilePath.c_str(),strFileBack.c_str());
            fclose(ListFile);
        }
        else
        {
            ResetCylinder();  //各缸号置零
            if((ListFile = fopen(strListName.c_str(),"r")) == NULL)
            {
                return ;
            }
            int iposi = 0;
            char strTT[200];
            while(fgets(strTT,200,ListFile) != NULL)
            {
                strTemp1 = strTT;
                strTemp1 = ExtractFileName(strTemp1);
                strTemp1 = strTemp1.SubString( iTTLen + iTNLen + 1 , 2 );
                iposi = StrToInt(strTemp1);
                iCylinderRead[iposi - 1] = 1;
            }
            fclose(ListFile);
            strTemp   = strFileBack.SubString( iTTLen + iTNLen + 1,2);
            iCylinder = StrToInt(strTemp);
            if( iCylinderRead[iCylinder-1] == 0 )
            {
                 if((ListFile = fopen(strListName.c_str(),"a")) == NULL)
                 {
                     return ;
                 }
                 fprintf(ListFile,"%s%s\n",strFilePath.c_str(),strFileBack.c_str());
                 fclose(ListFile);
            }
        }
    }
    if(iStepNum == iAllNum)
    {
        String strExeFileName = ::ParamStr(0);
        String strNowPath     = ::ExtractFilePath(strExeFileName);
        strNowPath           += "llist.buf";
        strListBuffer = strNowPath;
        FILE *fpback;
        if((fpback = fopen(strNowPath.c_str(),"w")) == NULL)
        {
             return;
        }
        for(int i=0; i < iListFileNum; i ++)
        {
            if(i < iListFileNum)
            {
                fprintf(fpback,"%s\n",strFileListName[i].c_str());
            }
            else
            {
                fprintf(fpback,"%s\n",strFileListName[i].c_str());
            }
        }
        fclose(fpback);
    }
}

bool __fastcall cPPWFDRead::ReadPipeWaveData(char* fn, lFileHeadStruct& lfhs, float* fxdata, float* fydata)
{
    //TODO: Add your source code here
/*
    int ilen,iTemp;
    void* strBuffer;
    FILE* pipeDatafp;
    if((pipeDatafp=fopen(fn,"rb"))==NULL)
	{
	//   Application->MessageBox("文件打开错误","提示",MB_OK);
        return false;
	}
    strBuffer=(void*)(&lfhs);
    lShort ls;
    fread(strBuffer,sizeof(lFileHeadStruct),1,pipeDatafp);

    ilen=lfhs.siLength;
    if(ilen>8000)
    {
       ilen=8000;
       lfhs.siLength=ilen;
    }
//    lfhs.strTrainNum[4]='\0';
    float ftemp1,ftemp2;
    ftemp2=lfhs.siFrequency;
    for(iTemp=0;iTemp<ilen;iTemp++)
    {
        fread(ls.ch,2,1,pipeDatafp);
        ftemp1=ls.iData;
        fxdata[iTemp]=float(iTemp)/ftemp2;
        fydata[iTemp]=ftemp1/1000.0;
    }
    fclose(pipeDatafp);
*/
    return true;

}

bool __fastcall cPPWFDRead::ReadPipeWaveData(char* fn, lFileHeadStruct& lfhs,float * fydata)
{
    //TODO: Add your source code here
/*
    int ilen,iTemp;
    void* strBuffer;
    FILE* pipeDatafp;
    if((pipeDatafp=fopen(fn,"rb"))==NULL)
	{
	//   Application->MessageBox("文件打开错误","提示",MB_OK);
        return false;
	}
    strBuffer=(void*)(&lfhs);
    lShort ls;
    fread(strBuffer,sizeof(lFileHeadStruct),1,pipeDatafp);

    ilen=lfhs.siLength;
    if(ilen>8000)
    {
       ilen=8000;
       lfhs.siLength=ilen;
    }
//    lfhs.strTrainNum[4]='\0';
     float ftemp1,ftemp2;
    ftemp2=lfhs.siFrequency;
    for(iTemp=0;iTemp<ilen;iTemp++)
    {
        fread(ls.ch,2,1,pipeDatafp);
        fydata[iTemp]=ls.iData/1000.0;
    }
    fclose(pipeDatafp);
*/
    return true;

}

bool __fastcall  cPPWFDRead::ReadPipeFileHead(char* fn,lFileHeadStruct& lfhs)
{
    int ilen,iTemp;
    void* strBuffer;
    FILE* pipeDatafp;
    if(fn == "")
    {
        return false;
    }
    if((pipeDatafp=fopen(fn,"rb"))==NULL)
	{
	//   Application->MessageBox("文件打开错误","提示",MB_OK);
        return false;
	}
    strBuffer=(void*)(&lfhs);
    lShort ls;
    fread(strBuffer,sizeof(lFileHeadStruct),1,pipeDatafp);
    fclose(pipeDatafp);
    return true;
}
