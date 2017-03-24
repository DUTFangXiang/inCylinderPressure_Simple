#include "DataProcess.h"
#include <math.h>
const double pi=3.1415926;

//===================================================================
//                  数字滤波器的部分函数部分
//===================================================================
void __fastcall lFIR::GenerateFilter(float* h, int& num)
{
	//TODO: Add your source code here
    float fDeltaW,fP,fP1,fTemp;
    int iTemp,iHalfLength;
    switch(iWindowChoice)
    {
    	case 0:   //矩形窗
        	fP=1.0;
            break;
        case 3:  //Blackman窗
        	fP=3.0;
            break;
        default: //Harmming 等
        	fP=2.0;
            break;
    }
	switch(iFilterKind)       //滤波器类型
    {
    	case 0: //低通滤波器
        {
        	if(bAutoLength)
            {
            	iTemp=(int)(2.0*fP*fSampleRate/(fStopFL-fPassFL));
            	if(iTemp%2==0) iTemp++;
            	else iTemp+=2;
            	if(iTemp>iMaxFilterLength) iTemp=iMaxFilterLength;

                iFilterLength=iTemp;
            }
            num=iFilterLength;
            iHalfLength=iFilterLength/2;
            fP=2*pi*fPassFL/fSampleRate;
            for(iTemp=0;iTemp<iFilterLength;iTemp++)
            {
            	if(iTemp==iHalfLength)
                	h[iTemp]=fP/pi*WinFunction(iTemp);
                else
                	h[iTemp]=sin(fP*(iTemp-iHalfLength))/(pi*(iTemp-iHalfLength))
                		 *WinFunction(iTemp);
            }
           	break;
        }
        case 1: //高通滤波器
        {
        	if(bAutoLength)
            {
            	iTemp=(int)(2.0*fP*fSampleRate/(fPassFH-fStopFH));
            	if(iTemp%2==0) iTemp++;
            	else iTemp+=2;
            	if(iTemp>iMaxFilterLength) iTemp=iMaxFilterLength;
            	iFilterLength=iTemp;
            }
            iHalfLength=iFilterLength/2;
            num=iFilterLength;
            fP=2*pi*fPassFH/fSampleRate;
            for(iTemp=0;iTemp<iFilterLength;iTemp++)
            {
            	if(iTemp==iHalfLength)
                	h[iTemp]=(1-fP/pi)*WinFunction(iTemp);
                else
                	h[iTemp]=-sin(fP*(iTemp-iHalfLength))/(pi*(iTemp-iHalfLength))
                		 *WinFunction(iTemp);
            }
           	break;

        }
        case 2: //带通滤波器
        {
        	if(bAutoLength)
            {
        		if((fStopFL-fPassFL)>(fPassFH-fStopFH))
            		fTemp=fPassFH-fStopFH;
            	else
            		fTemp=fStopFL-fPassFL;
            	iTemp=(int)(2.0*fP*fSampleRate/fTemp);
            	if(iTemp%2==0) iTemp++;
            	else iTemp+=2;
            	if(iTemp>iMaxFilterLength) iTemp=iMaxFilterLength;
                iFilterLength=iTemp;
            }
            num=iFilterLength;
            iHalfLength=iFilterLength/2;
            fP=2*pi*fPassFL/fSampleRate;
            fP1=2*pi*fPassFH/fSampleRate;
            for(iTemp=0;iTemp<iFilterLength;iTemp++)
            {
            	if(iTemp==iHalfLength)
                	h[iTemp]=((fP1-fP)/pi)*WinFunction(iTemp);
                else
                	h[iTemp]=(sin(fP1*(iTemp-iHalfLength))-sin(fP*(iTemp-iHalfLength)))/(pi*(iTemp-iHalfLength))
                		 *WinFunction(iTemp);
            }
           	break;
        }
        case 3: //带阻滤波器
        {
        	if(bAutoLength)
            {
	       		if((fStopFL-fPassFL)>(fPassFH-fStopFH))
            		fTemp=fPassFH-fStopFH;
            	else
            		fTemp=fStopFL-fPassFL;
            	iTemp=(int)(2.0*fP*fSampleRate/fTemp);
            	if(iTemp%2==0) iTemp++;
            	else iTemp+=2;
            	if(iTemp>iMaxFilterLength) iTemp=iMaxFilterLength;
             	iFilterLength=iTemp;
            }
            num=iFilterLength;
            iHalfLength=iFilterLength/2;
            fP=2*pi*fPassFL/fSampleRate;
            fP1=2.0*pi*fPassFH/fSampleRate;
            for(iTemp=0;iTemp<iFilterLength;iTemp++)
            {
            	if(iTemp==iHalfLength)
                	h[iTemp]=(1-(fP-fP1)/pi)*WinFunction(iTemp);
                else
                	h[iTemp]=(sin(fP*(iTemp-iHalfLength))-sin(fP1*(iTemp-iHalfLength)))/(pi*(iTemp-iHalfLength))
                		 *WinFunction(iTemp);
            }
        	break;
        }
    }
}

float __fastcall lFIR::WinFunction(int i)
{
	//TODO: Add your source code here
    float fTemp;
    int n;
    n=iFilterLength;
    switch(iWindowChoice)
    {
    	case 0: //Square
        	fTemp=1.0;
            break;
        case 1: //Hanning
	    	fTemp=0.5*(1.0-cos(2.0*pi*i/(n-1)));
            break;
        case 2://Harmming
        	fTemp=0.54-0.46*cos(2.0*pi*i/(n-1));
            break;
        case 3: //Blackman
        	fTemp=0.42-0.5*cos(2.0*pi*i/(n-1))+0.08*cos(4.0*pi*i/(n-1));
			break;
        default:
        	fTemp=0.54-0.46*cos(2.0*pi*i/(n-1));
            break;
    }
    return fTemp;
}


//=============================================================
//                 数据处理的部分函数
//=============================================================

__fastcall lDataProcess::lDataProcess()
{
        bMAFFT=false;
        bMAWAVELET=false;
        bMATIMEWINDOW=false;
        Level=5;
}

/*
void __fastcall lDataProcess::Delete(void)
{
        if(bMAFFT)
        {
            delete []OriginalData;
            delete []xc;
            delete []xs;
            delete []xm;
        }
        else if(bMAWAVELET)
        {
            delete []OriginalData;
            for(int i=0;i<6;i++)
            {
                 delete [] a[i];
                 delete [] b[i];
                 delete [] aa[i];
            }
         }
         else if(bMATIMEWINDOW)
         {
              delete []OriginalData;
              delete []xm;
         }
}
*/
void __fastcall lDataProcess::BeginFFT(bool btf)
{
    double temp1,temp2;
	for(int i=0;i<DataNum;i++)
	{
		xc[i]=OriginalData[i];
		xs[i]=0.0;
	}
	FFT(0);				//付立叶正变换
    for(int i=0;i<DataNum;i++)
	{
		temp1 = sqrt(xc[i]*xc[i]+xs[i]*xs[i]);   //求变换后的模值
		if(fabs(xc[i])<0.000001)
		{
			if(xs[i]>0.0)
				temp2 = pi/2.0;
			else
				temp2 = -pi/2.0;
		}
		else
        {
			temp2 = atan(xs[i]/xc[i]);
        }
		xm[i]=temp1/(float)DataNum/2.0;

	}

}
void __fastcall lDataProcess::BeginWavelet()
{
 	for(int i=0;i<DataNum;i++)
	{
		a[0][i]=OriginalData[i];
    }
    Wavelet();
}

void __fastcall lDataProcess::Wavelet(void)
{
	float p,q;
	int i,j,k;
	float c2;
	int c=1,N,M;

	float c1[]={1.5,1.12,1.03,1.01,1.0,1.0,1.0,1.0};
	float h[]={0.125,0.375,0.375,0.125};
	float g[]={-2.0,2.0};
//	float k1[]={ 0.0078125,0.054685,0.171875,-0.171875,-0.0054685,-0.0078125};
	N=DataNum/2;
	M=Level;

	for(k=1;k<=M;k++)
	{
		c2=1.0/c1[k-1];
		if(k==1)
		{
			for(i=N;i<=N+2*c+1;i++)
				a[k-1][i]=a[k-1][2*N-1-i];
			for(i=0;i<=2;i++)
			{
				p=0;
				q=0;
				for(j=-1;j<=2;j++)
					p=p+h[j+1]*a[0][abs(i-j)];
				for(j=0;j<=1;j++)
					q=q+g[j]*a[0][abs(i-j)];
				a[1][i]=p;
				b[1][i]=-c2*q;
			}
			for(i=3;i<=N;i++)
			{
				p=0;
				q=0;
				for(j=-1;j<=2;j++)
					p=p+h[j+1]*a[0][i-j];
				for(j=0;j<=1;j++)
					q=q+g[j]*a[0][i-j];
				a[1][i]=p;
				b[1][i]=-c2*q;
			}
		}
		else
		{
			for(i=N+1;i<=N+2*c+1;i++)
				a[k-1][i]=a[k-1][2*N-i];
			for(i=c/2;i<=2*c;i++)
			{
				p=0;
				q=0;
				for(j=-1;j<=2;j++)
					p=p+h[j+1]*a[k-1][abs(i-c*j)];
				for(j=0;j<=1;j++)
					q=q+g[j]*a[k-1][abs(i-c*j)];
				a[k][i-c/2]=p;
				b[k][i-c/2]=-c2*q;
			}
			for(i=2*c+1;i<=N+c/2;i++)
			{
				p=0;q=0;
				for(j=-1;j<=2;j++)
					p=p+h[j+1]*a[k-1][i-c*j];
				for(j=0;j<=1;j++)
					q=q+g[j]*a[k-1][i-c*j];
				a[k][i-c/2]=p;
				b[k][i-c/2]=-c2*q;
			}
		}
		c=2*c;
	}

}
void __fastcall lDataProcess::FFT(int inv)
{
    //付立叶正逆变换
    // inv = 0  :为正变换
    // inv != 0 :为逆变换
	double uc,us,wc,ws,tc,ts,uc1;
	double m;
	int nv2,nm1,i,ip,j,k,mm,l,le,le1,c,n;
	n=DataNum;
	m=log((float)n)/log(2.0)+0.1;
	nv2=n/2;
	nm1=n-1;
	j=1;
	for(i=1;i<=nm1;i++)
	{
		if(i>=j)	{	k=nv2;	}
		else
		{
			tc=xc[j-1];
			ts=xs[j-1];
			xc[j-1]=xc[i-1];
			xs[j-1]=xs[i-1];
			xc[i-1]=tc;
			xs[i-1]=ts;
			k=nv2;
		}
		while(k<j)
		{
			j=j-k;
			k=k/2;
		}
		j=j+k;
	}
	mm=(int)m;
	for(l=1;l<=mm;l++)
	{
		le=2;
		for(c=1;c<l;c++) {le=le*2;}
		le1=le/2;
		uc=1.0;
		us=0.0;
		wc=cos(pi/(float)(le1));
		ws=-sin(pi/(float)(le1));
		if(inv!=0)  ws=-ws;
		for(j=1;j<=le1;j++)
		{
			for(i=j;i<=n;i+=le)
			{
				ip=i+le1;
				tc=xc[ip-1]*uc-xs[ip-1]*us;
				ts=xs[ip-1]*uc+xc[ip-1]*us;
				xc[ip-1]=xc[i-1]-tc;
				xs[ip-1]=xs[i-1]-ts;
				xc[i-1]=xc[i-1]+tc;
				xs[i-1]=xs[i-1]+ts;
			}
			uc1=uc*wc-us*ws;
			us=us*wc+uc*ws;
			uc=uc1;
		}
	}
	if(inv==0)  return;
	for(i=0;i<n;i++)
	{
		xc[i]=xc[i]/(float)n;
		xs[i]=xs[i]/(float)n;
		xm[i]=xc[i]+xs[i];
	}
}

void __fastcall lDataProcess::GetFFTResult(float *fr,float *fe,float* fm)
{

    for(int i=0;i<DataNum;i++)
    {
        fr[i]=xc[i];
        fe[i]=xs[i];
        fm[i]=xm[i];
    }
}
void __fastcall lDataProcess::GetWaveletResult(float **fa,float **fb,float **faa)
{
        for(int i=0;i<6;i++)
        {
                for(int j=0;j<DataNum;j++)
                {
                        fa[i][j]=a[i][j];
                        fb[i][j]=b[i][j];
                        faa[i][j]=aa[i][j];
                }
        }
}
void __fastcall lDataProcess::GetTimeAverageResult(float* fmo)
{
        for(int i=0;i<DataNum;i++)
        {
                fmo[i]=xm[i];
        }
}
void __fastcall lDataProcess::BeginTimeAverage(int winlen)
{
        int i,j,halfwin,wholelen;
        float ftemp;
        wholelen=winlen;
        if(wholelen<1) wholelen=1;
        if((wholelen%2)==0) wholelen=winlen+1;
        halfwin=wholelen/2;
        for(i=0;i<halfwin;i++)
        {
                ftemp=0.0;
                for(j=i;j<i+winlen;j++)
                {
                        ftemp+=OriginalData[j];
                }
                xm[i]=ftemp/(float)winlen;
        }
        for(i=halfwin;i<DataNum-halfwin;i++)
        {
                ftemp=0.0;
                for(j=i-halfwin;j<i+halfwin+1;j++)
                {
                        ftemp+=OriginalData[j];
                }
                xm[i]=ftemp/(float)winlen;
        }
        for(i=DataNum-halfwin;i<DataNum;i++)
        {
                ftemp=0.0;
                for(j=i;j>i-winlen;j--)
                {
                        ftemp+=OriginalData[j];
                }
                xm[i]=ftemp/(float)winlen;
        }
}
bool __fastcall lDataProcess::SetData(float* SourceData,int num,int bfw)
{                                  //bfw: false:付立叶变换； true:小波变换
        int i;
        Delete();
/*        if(num<=128) DataNum=128;
        else if(num<=256) DataNum=256;
        else DataNum=512;
*/
        DataNum = num;
        OriginalData=new float[DataNum];
        if(OriginalData==NULL)  return false;
        iCalculationMethod=bfw;
        switch(iCalculationMethod)
        {
        case 0://付立叶变换
            {
                xc=new float[DataNum];
                xs=new float[DataNum];
                xm=new float[DataNum];
                if((xc==NULL)||(xs==NULL)||(xm==NULL))
                {
                        return false;
                }
                bMAFFT=true;
                break;
            }
        case 1: //小波变换处理
            {
                int ilen=2*DataNum;
                for(int i=0;i<6;i++)
                {
                      a[i]=new float[ilen];
                      b[i]=new float[ilen];
                      aa[i]=new float[ilen];
                      if((a[i]==NULL)||(b[i]==NULL)||(aa[i]==NULL))
                        return false;
                }
                bMAWAVELET=true;
                break;
            }
        case 2: //时间窗处理
            {
                xm=new float[DataNum];
                if((xm==NULL))
                {
                        return false;
                }
                bMATIMEWINDOW=true;
                break;
            }
        }
        float ftemp;
        for(i=0;i<num;i++)
        {
                ftemp=SourceData[i];
                OriginalData[i]=ftemp;
        }
        for(i=num;i<DataNum;i++)
        {
                OriginalData[i]=0.0;
        }
        return true;
}


bool __fastcall lDataProcess::LBeginFFT(float * fxc, float * fxs, float * fxm, int ilen, bool binv)
{
    //TODO: Add your source code here
    double temp1,temp2;
    DataNum = ilen;
	for(int i=0;i<DataNum;i++)
	{
		fxs[i]=0.0;
	}
	FFT(fxc,fxs,fxm,binv);				//付立叶正变换
    for(int i=0;i<DataNum;i++)
	{

		temp1=sqrt(fxc[i]*fxc[i]+fxs[i]*fxs[i]);   //求变换后的模值
		if(fabs(fxc[i])<0.000001)
		{
			if(fxs[i]>0.0)
				temp2=pi/2.0;
			else
				temp2=-pi/2.0;
		}
		else
        {
			temp2=atan(fxs[i]/fxc[i]);
        }
		fxm[i]=temp1/(float)DataNum/2.0;
	}
    return true;
}

void __fastcall lDataProcess::FFT(float * fxc, float * fxs, float * fxm, bool inv)
{
    //TODO: Add your source code here
        //付立叶正逆变换
    // inv = 0  :为正变换
    // inv != 0 :为逆变换
	double uc,us,wc,ws,tc,ts,uc1;
	double m;
	int nv2,nm1,i,ip,j,k,mm,l,le,le1,c,n;
    xc = fxc;
    xs = fxs;
    xm = fxm;
	n=DataNum;
	m=log((float)n)/log(2.0)+0.1;
	nv2=n/2;
	nm1=n-1;
	j=1;
	for(i=1;i<=nm1;i++)
	{
		if(i>=j)	{	k=nv2;	}
		else
		{
			tc=xc[j-1];
			ts=xs[j-1];
			xc[j-1]=xc[i-1];
			xs[j-1]=xs[i-1];
			xc[i-1]=tc;
			xs[i-1]=ts;
			k=nv2;
		}
		while(k<j)
		{
			j=j-k;
			k=k/2;
		}
		j=j+k;
	}
	mm=(int)m;
	for(l=1;l<=mm;l++)
	{
		le=2;
		for(c=1;c<l;c++) {le=le*2;}
		le1=le/2;
		uc=1.0;
		us=0.0;
		wc=cos(pi/(float)(le1));
		ws=-sin(pi/(float)(le1));
		if(inv!=0)  ws=-ws;
		for(j=1;j<=le1;j++)
		{
			for(i=j;i<=n;i+=le)
			{
				ip=i+le1;
				tc=xc[ip-1]*uc-xs[ip-1]*us;
				ts=xs[ip-1]*uc+xc[ip-1]*us;
				xc[ip-1]=xc[i-1]-tc;
				xs[ip-1]=xs[i-1]-ts;
				xc[i-1]=xc[i-1]+tc;
				xs[i-1]=xs[i-1]+ts;
			}
			uc1=uc*wc-us*ws;
			us=us*wc+uc*ws;
			uc=uc1;
		}
	}
	if(inv==0)  return;
	for(i=0;i<n;i++)
	{
		xc[i]=xc[i]/(float)n;
		xs[i]=xs[i]/(float)n;
		xm[i]=xc[i]+xs[i];
	}
}

bool __fastcall lDataProcess::LBeginRemoveTendency(float *aa,float *bb,int Num,int iStart,int iEnd,int wnum,int kk)
{
    //剔除测量信号中的趋势项，

    // 输入：
    //　　aa :　原始数据
    //　　bb:   均为零值的缓存区
    //    Num:  数据的个数
    //    iStart: 开始点
    //    iEnd:   结束点
    //　　wnum:　　加窗长度
    //   　kk:　　窗类型

    //输出：
    //  aa: 剔除趋势项后的数据
    //  bb: 趋势项

	N=Num;
    KK=kk;
	IVM=wnum;
    iCStart=iStart;
    if(iCStart==0) iCStart=1;
    iCEnd=iEnd;
    X = aa;
    Y = bb;
    for(int i = iCStart;i<iCEnd;i++)
    {
        Y[i] = X[i];
    }
	float VMAX,FI,V,FV;
	int I,IT,ITL,ITU,IV;
	VMAX=float(IVM);
	A1=1.0;
	A2=0.0;
	A3=0.0;
	if(KK==1)
	{
		A1=A1+2.0*(float)IVM;
		for(I=1;I<=IVM;I++)
		{
			FI=(float)(I);
			A2=A2+2.0*(FI*FI);
			A3=A3+FI*FI*FI*FI;
		}
		COEF();
//		for( IT=IVM+1;IT<=N-IVM;IT++)    //2003_01_03
		for( IT=IVM+1;IT<=N-IVM;IT++)    //2003_01_03
		{
			ITL=IT-IVM;
			ITU=IT+IVM;
			B1=0.0;
			B2=0.0;
			B3=0.0;
//			for(I=ITL;I<=ITU;I++)     //2003_01_03
			for(I=ITL;I<=ITU;I++)     //2003_01_03
			{
				V=(float)(I-IT);
				B1=B1+X[I-1];
				B2=B2+V*X[I-1];
				B3=B3+V*V*X[I-1];
			}
			RESULT(IT);
		}
	}
	else if(KK==2)
	{
		for(I=1;I<=IVM;I++)
		{
			FI=(float)(I);
			FV=1.0-FI/VMAX;
			A1=A1+2.0*FV;
			A2=A2+2.0*FV*(FI*FI);
			A3=A3+FV*(FI*FI*FI*FI);
		}
		COEF();

		for(IT=IVM+1;IT<=N-IVM;IT++)    //
		{
			//DO 121
			ITL=IT-IVM;
			ITU=IT+IVM;
			B1=0.0;
			B2=0.0;
			B3=0.0;
			for(I=ITL;I<=ITU;I++)
			{
		//DO 122 I=ITL,ITU
				IV=I-IT;
				V=(float)(IV);
				FV=1.0-fabs(V)/VMAX;
				B1=B1+FV*X[I-1];
				B2=B2+FV*V*X[I-1];
				B3=B3+FV*V*V*X[I-1];
			}
		//122	CONTINUE
			RESULT(IT);
		}//121	CONTINUE
//	GOTO 14
//13
	}
	else if (KK==3)
	{
		for(I=1;I<=IVM;I++)
		{
		//DO 130 I=I,IVM
			FI=(float)(I);
			FV=0.54+0.46*cos(3.1415926*FI/VMAX);
			A1=A1 + 2.0*FV;
			A2=A2 + 2.0*FV*(FI*FI);
			A3=A3 + FV*(FI*FI*FI*FI);  //这个地方有些疑问FV ?
		//130	CONTINUE
		}
		COEF();
//		for(IT=IVM+1;IT<=N-IVM;IT++)
//		for(IT=iCStart+IVM+1;IT<=iCEnd-IVM;IT++)   //2002_01_03   去除了等号

		for(IT=iCStart+IVM+1;IT<iCEnd-IVM;IT++)
		{
		//DO 131 IT=IVM+1,N-IVM
			ITL=IT-IVM;
			ITU=IT+IVM;
			B1=0.0;
			B2=0.0;
			B3=0.0;
//			for(I=ITL;I<=ITU;I++)      //2002_01_03   去除了等号
            for(I=ITL;I<=ITU;I++)
			{
				//DO 132 I=ITL,ITU
				IV=I-IT;
				V=(float)(IV);
				FV=0.54+0.46*cos(3.1415926*V/VMAX);
				B1=B1+FV*X[I-1];
				B2=B2+FV*V*X[I-1];
				B3=B3+FV*V*V*X[I-1];
				//132	CONTINUE
			}
			RESULT(IT);
			//131	CONTINUE
		}
	}
    return true;
}

void __fastcall lDataProcess::COEF()
{
	float AA;
	AA=1.0/(A1*A3-A2*A2/2.0);
	A11=AA*A3;
	A22=1.0/A2;
	A31=-A2*AA;
	A33=A1*AA;
}

void __fastcall lDataProcess::RESULT(int IT)
{
	F[1]=A11*B1+A31*B3/2.0;
	F[2]=A22*B2;
	F[3]=A31*B1+A33*B3;
	Y[IT]=X[IT]-F[1];
/*
	WRITE(*,101) IT,X(IT),F(1),Y(IT)
	WRITE(4,1111) Y(IT)
101	FORMAT(2X,I3,6X,F10.3,8X,F10.3,8X,F10.3)
1111	FORMAT(2X,F10.3)
	RETURN
	END
*/
}

bool __fastcall lDataProcess::lFilterData(float * fodata,float *fddata,int ilen,float *h, int ihlen)
{
    //TODO: Add your source code here
    //对输入数据fodata进行滤波处理，
    //输入：
    //　fodata 原始数据
    //　fddata 保存滤波后的数据
    //  h      滤波器数据
    //　ilen   原始数据长度
    //  ihlen  滤波器长度
    //输出：
    //　fddata　为滤波处理后的数据
 	int ib,id;
    float fb;
    iCStart = 0;
    iCEnd   = ilen;
    for(id=iCStart;id<iCEnd;id++)
    {
    	fb=0.0;
        for(ib=0;ib<ihlen;ib++)
        {
        	if((id-ib-iCStart)<0) break;
        	fb+=h[ib]*fodata[id-ib];
        }
        fddata[id]=fb;
    }
/*
    for(id=iCStart;id<iCEnd;id++)
    {
    	Y[id]=X[id];
    }
*/
    return true;
}

bool __fastcall lDataProcess::lFilterData(int * fodata,int *fddata,int ilen,float *h, int ihlen)
{
    //TODO: Add your source code here
    //对输入数据fodata进行滤波处理，
    //输入：
    //　fodata 原始数据
    //　fddata 保存滤波后的数据
    //  h      滤波器数据
    //　ilen   原始数据长度
    //  ihlen  滤波器长度
    //输出：
    //　fddata　为滤波处理后的数据
 	int ib,id;
    float fb;
    iCStart = 0;
    iCEnd   = ilen;
    for(id=iCStart;id<iCEnd;id++)
    {
    	fb=0.0;
        for(ib=0;ib<ihlen;ib++)
        {
        	if((id-ib-iCStart)<0) break;
        	fb+=h[ib]*fodata[id-ib];
        }
        fddata[id]=fb;
    }
/*
    for(id=iCStart;id<iCEnd;id++)
    {
    	Y[id]=X[id];
    }
*/
    return true;
}
bool __fastcall lDataProcess::LWaveletProcess(float * fdata, float ** fa, float ** fb, float ** fwa, int ilen)
{
    //TODO: Add your source code here
    //对原始数据进行小波变换
    //输入:　
    // fdata :为保存原始数据的数组
    // fa:    为小波变换所需的中间变量，输出为滤波后的结果
    // fb:    为小波变换所需的中间变量，输出为被滤波掉的信号
    // fwa:   为小波变换所需的中间变量，输出为小波模数
    // ilen:  为原始数据的长度的一半
    // 输出：
    // fa:
    // fb:
    // fwa:


     DataNum = ilen;
     OriginalData = fdata;
     for(int i=0;i<6;i++)
     {
         a[i]  = fa[i];
         b[i]  = fb[i];
         aa[i] = fwa[i];
     }
     BeginWavelet();
     return true;
}

void __fastcall lDataProcess::IntegralData(float * fodata, int idatalen, float finterval,int * iPhase, int iPhnum, float * fresult)
{

    //TODO: Add your source code here
    //对数据进行积分
    // 输入：
    //　fodata 　　待积分的原始数据
    //  idatalen   原始数据的长度
    //　finterval  原始数据之间的间隔
    //　iPhase     间隔划分
    //  iPhnum     间隔点数，等于间隔数加上1
    //  fresult    每个间隔的积分值

    //输出：
    //  fresult   其内保存着积分的结果

    int i;
    int j;
    int iRPhase[20];
    float ftemp;
    int m;
    for(m = 0; m<=iPhnum; m++)
    {
        iRPhase[m] =(int)((float)iPhase[m]/finterval);
    }
    for(i=0; i<iPhnum; i++)
    {
        ftemp=0.0;
        for(j=iRPhase[i]; j<iRPhase[i+1]; j++)
        {
            ftemp+=(fodata[j]+fodata[j+1])/2.0;
        }
        fresult[i] = ftemp*finterval;
    }
}

void __fastcall lDataProcess::MaxAndAverage(float * fodata, int ilen, float & fmax, float & faverage, float & fgv)
{
    //TODO: Add your source code here
    //用于计算原始数据的最大值及有效值
    //输入
    // fodata    待处理的原始数据
    // ilen      原始数据长度
    // 输出
    // fmax      最大值  （数据的绝对值）
    // faverage  有效值
    // fgv　　   峭度系数 （暂没有计算）

    int i;
	float ftemp1,ftemp2;
    fmax=fodata[0];
    ftemp1=0.0;
  	for(i=0;i<ilen;i++)
   	{
   		ftemp1+=fodata[i]*fodata[i];
        ftemp2 = fabs(fodata[i]);
       	if(fmax<ftemp2)
        {
            fmax=ftemp2;
        }
    }
    faverage = sqrt(ftemp1/(float)ilen);
    fgv = 0.0;
}

void __fastcall lDataProcess::GetWaveletParameter(float * fodata, float ** fa, int ilen, float* fresult)
{
    //TODO: Add your source code here
    int i;
    fresult[4] = 0.0;
    float ftemp;
    for(i = 0; i<ilen; i++)
    {
        ftemp = fodata[i] - fa[1][i];
        fresult[4] += ftemp*ftemp;
    }
    fresult[4] = sqrt(fresult[4]/float(ilen));
    for(int j=0;j<4;j++)
    {
        fresult[3-j]=0.0;
        for(i=0;i<ilen;i++)
        {
            ftemp = fa[5-j][i]-fa[4-j][i];
            fresult[3-j]+= ftemp*ftemp;
        }
        fresult[3-j] = sqrt(fresult[3-j]/float(ilen));
    }
}
