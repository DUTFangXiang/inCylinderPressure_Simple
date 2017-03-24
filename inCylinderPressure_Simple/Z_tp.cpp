#include <math.h>
#include <stdio.h>

#include <stdlib.h>

#include "Z_ROHR.h"

#define FCA 360./512.
#define PI	3.141592653
#define PI2	1.5707963265
#define p2pi	6.283185306

void status_line(char *, char *, int);

void kbfft(float *pr,float *pi,int n,int k,float *fr,float *fi,int l,int il)
{	int it,m,is,i,j,nv,l0;
	double p,q,s,vr,vi,poddr,poddi;
	for(it=0;it<n;it++)
	{	m=it;is=0;
		for(i=0;i<k;i++)
		{	j=m/2;is=2*is+(m-2*j);m=j;
		}
		fr[it]=pr[is];fi[it]=pi[is];
	}
	pr[0]=1.0;pi[0]=0.0;
	p=6.283185306/(1.0*n);
	pr[1]=cos(p);pi[1]=-sin(p);
	if(l!=0)pi[1]=-pi[1];
	for(i=2;i<n;i++)
	{	p=pr[i-1]*pr[1];q=pi[i-1]*pi[1];
		s=(pr[i-1]+pi[i-1])*(pr[1]+pi[1]);
		pr[i]=p-q;pi[i]=s-p-q;
	}
	for(it=0;it<=n-2;it+=2)
	{	vr=fr[it];vi=fi[it];
		fr[it]=vr+fr[it+1];fi[it]=vi+fi[it+1];
		fr[it+1]=vr-fr[it+1];fi[it+1]=vi-fi[it+1];
	}
	m=n/2;nv=2;
	for(l0=k-2;l0>=0;l0--)
	{	m=m/2;nv=2*nv;
		for(it=0;it<=(m-1)*nv;it=it+nv)
		for(j=0;j<=(nv/2)-1;j++)
		{	p=pr[m*j]*fr[it+j+nv/2];
			q=pi[m*j]*fi[it+j+nv/2];
			s=pr[m*j]+pi[m*j];
			s=s*(fr[it+j+nv/2]+fi[it+j+nv/2]);
			poddr=p-q;poddi=s-p-q;
			fr[it+j+nv/2]=fr[it+j]-poddr;
			fi[it+j+nv/2]=fi[it+j]-poddi;
			fr[it+j]=fr[it+j]+poddr;
			fi[it+j]=fi[it+j]+poddi;
		}
	}
	if(l!=0)
		for(i=0;i<n;i++)
		{	fr[i]/=n;
			fi[i]/=n;
		}
	if(il!=0)
		for(i=0;i<n;i++)
		{
			pr[i]=sqrt(fr[i]*fr[i]+fi[i]*fi[i]);
			if(fabs(fr[i])<0.000001*fabs(fi[i]))
			{	if(fi[i]>0) pi[i]=PI2;
				else pi[i]=-PI2;
			}
			else
			{	pi[i]=atan(fi[i]/fr[i]);
				if(fr[i]<0) pi[i]+=PI;
			}
		}
	return;
}

extern char filename[4][20],txt[4][64];
extern int file_Num;
extern ROHR Rohr;
extern float pp[4][6][512],temp,data[4][30];
float ca[1440],p[1440],pr[1024],pi[1024],fr[1024],fi[1024],v[1024];
//char filename[0][20];
int Dot_num;
void data_show();

void rohr1(char flag,char *fname)
{
	int i=0;
	while(ca[i++]<-180.);
	Rohr.Init();
	Rohr.set_data(&ca[i],&p[i],pp[0][0],pp[0][1],pp[0][2],pp[0][3],pp[0][4],pp[0][5],v);
//set_data(float *Ca,float *Y,float *p,float *dp,float *t,float *dq,float *dw,float *q,float *f);
	if(flag=='Y') Rohr.Press_cacu();
	else memcpy(pp[0][0],&p[i],512*4);
	Rohr.rohr();
	Rohr.Out(.95,data[0]);
//	char fname[20];
	FILE *fp;
	if ((fp=fopen(fname,"w")) == NULL) //exit(1);
	{
		status_line("文件名错误,或磁盘满！按任意键返回", "",0);
		getch();
		status_line("", "", 2);
		return;
	}
	for(int ii=0;ii<512;ii++)
	{
		fprintf(fp,"%f",ca[i+ii]);
		for(int j=0;j<6;j++)
			fprintf(fp,"\t%f",pp[0][j][ii]);
		fprintf(fp,"\n");
	}
	for(i=0;i<30;i++)
		fprintf(fp,"%f\t",data[0][i]);
	fprintf(fp,"\n%s",txt[0]);
	fclose(fp);
}

/*
float vol(float ca)
{   float x;
	ca=ca/180.*PI;
	x=rc*(1.-cos(ca))+fl*(1.-sqrt(1.-pow((rc/fl*sin(ca)),2)));
	return (x*s);
}
*/
/* caculate Ni */
/*
float Ni(float *ca,float *p,int Num)
{
	float ni=0,v0,v1;
	v0=vol(ca[0]);
	for(i=1;i<Num;i++)
	{	v1=vol(ca[i]);
		ni+=(p[i]+p[i-1])*(v1-v0)/2.;
		v0=v1;
	}
	ni*=rpm/60.
	return(ni);
}
*/

void b3_smoflt(float *p,int m,int n)
/*b-3-spline smooth p[m]曲线点数  n滤波次数*/
{   float t0,t1,t2;
	m--;
	for(;n>0;n--)
	{	t0=p[m]/6.+p[0]*2./3.+p[1]/6.;
		t2=p[m-1]/6.+p[m]*2./3.+p[0]/6.;
		for(int j=1;j<m;j++)
			{	t1=p[j-1]/6.+p[j]*2./3.+p[j+1]/6.;
				p[j-1]=t0;
				t0=t1;
			}
		p[m]=t2;
	}
}

void sea_fil()
{
	char command[20];
	window(1,1,80,25);
	clrscr();
	printf("input dos command\n");
	gets(command);
	system(command);
	getch();
	clrscr();
}



Draw_Curve *DCu;

void Change_tdc(int num,float *Ca,float *P,float tdc)
{
	int i,k,j;
	float temp=0;
	for(i=0;i<num;i++)
	{	Ca[i]-=tdc;
	/* find peak */
		if(temp<P[i])
		{	temp=P[i];
			k=i;
		}
		while(Ca[i]>360.) Ca[i]-=720.;
		while(Ca[i]<-360.) Ca[i]+=720.;
	}

	if((Ca[k]<-180.0)||(Ca[k]>180))
		for(i=0;i<num;i++)
		{
			Ca[i]+=360;
			while(Ca[i]>360.) Ca[i]-=720.;
			while(Ca[i]<=-360.) Ca[i]+=720.;
		}

	for(i=0;i<num;i++)
		for(j=i+1;j<num;j++)
			if(Ca[i]>Ca[j])
			{
				temp=Ca[i];
				Ca[i]=Ca[j];
				Ca[j]=temp;
				temp=P[i];
				P[i]=P[j];
				P[j]=temp;
			}
/*caculat p_off*/
//	for(i=380;i<400;i++) temp+=ca[1][i];
//	temp/=20.;
}



float lqa_3(float t,int m)
{   int i;
	float x[3],y[3],u,v,w,a;
	{	if(m==0)if((720.-ca[1439])<ca[0]) m=1438;
				else m=1439;
		else if(abs(t-ca[m-1])<fabs(t-ca[m])) m-=2;
			else m--;
	}
	for(i=0;i<3;i++)
	{	x[i]=ca[m];
		y[i]=p[m];
		if(++m>1439) m-=1440;
	}
	u=(t-x[1])*(t-x[2])/(x[0]-x[1])/(x[0]-x[2]);
	v=(t-x[0])*(t-x[2])/(x[1]-x[0])/(x[1]-x[2]);
	w=(t-x[0])*(t-x[1])/(x[2]-x[0])/(x[2]-x[1]);
	a=u*y[0]+v*y[1]+w*y[2];
	return (a);
}

void P_1440_1024()
{
/* 1440 change to 1024 */
	float temp;
	int n=0;
//	printf("now change 1440 to 1024");
	for(int j=0;j<1024;j++)
	{	temp=FCA*j-360.;
		n--;
		while(ca[++n]<temp);
		if(n>1440) n=0;
		pr[j]=lqa_3(temp,n);
	}
	for(j=0;j<1024;j++)
	{
		p[j]=pr[j];
		ca[j]=FCA*j-360;
	}
	for(;j<1440;j++)
	{
		p[j]=0;
		ca[j]=0;
	}
}
/*fft*/
void P_fft()
{
	for(int j=0;j<1024;j++)
	{
		pr[j]=p[j];
		pi[j]=0;
	}
	kbfft(pr,pi,1024,10,ca,v,0,1);
	for(j=0;j<513;j++)	pr[j]=log10(pr[j]);
	for(j=0;j<1024;j++)	ca[j]=FCA*j-360;
}


int dis_data1(char *fname)
/* display file name */
{
/* read file and deal data[k] */
	FILE *fp;
	if ((fp=fopen(fname,"r+")) == NULL) //exit(1);
	{
		status_line("文件名错误！按任意键返回", "",0);
		getch();
		status_line("", "", 2);
		return(0);
	}

	for(int j=0;j<2;j++)
	{
		fscanf(fp,"%f",&ca[j]);
		fscanf(fp,"%f",&p[j]);
	}
	if((ca[1]-ca[0])==0.5) Dot_num=1440;
	else if((ca[1]-ca[0])==1.) Dot_num=720;
		else Dot_num=1024;
	for(j=2;j<Dot_num;j++)
	{
		fscanf(fp,"%f",&ca[j]);
		fscanf(fp,"%f",&p[j]);
	}
	fscanf(fp,"%s",txt[0]);
	fclose(fp);
	float b;
	int a;
	if(Dot_num==1440) P_1440_1024();
	else	if(Dot_num==720)
		{
			for(int i=1;i<1024;i++)
			{
				b=(float)i*720./1024.;
				a=(int)b;
				pr[i]=p[a]*(b-(float)a)+p[b]*((float)a+1.-b);
			}
			b=ca[0];
			for(i=1;i<1024;i++)
			{
				p[i]=pr[i];
				ca[i]=i*FCA+b;
			}
		}
	Dot_num=1024;
	Change_tdc(Dot_num,ca,p,0);
	P_fft();
	return (1);
}

int get_D_Z(int num,float *fr,float *fi)
//生成滤波函数返回1,否则0
{
	int i;
	int but_num=2,flag;
	char *but_name[]={"确定","取消"};
	char *report_dia = "带阻滤波器参数";
	char *reportBox[]={"付阻带起点","主阻带起点","主阻带终点","付阻带终点","阻带衰减率","高频衰减率"};
	char *BoxTemp[]={"0","0","0","0","0","0"};
	int D_Z[4];
	float b[2];
//添写文件名

	Dialog *report;
	report = new Dialog(6,but_num,but_name,report_dia,reportBox);
	report->Puttobox(BoxTemp);
	flag=report->DialogControl();
	switch(flag)
	{
		case 0://Yes
			for(i=0;i<4;i++) D_Z[i]=atoi(report->Getboxcontent(i));
			for(i=0;i<2;i++) b[i]=atof(report->Getboxcontent(i+4));
			report->~Dialog();
			break;
		case 1:
		case -1:report->~Dialog();
			return(NULL);
	}

	for(i=D_Z[3];i<num;i++)	{fr[i]=b[1];fi[i]=0;}
	for(i=D_Z[1];i<D_Z[2];i++){fr[i]=b[0];fi[i]=0;}

	for(i=0;i<2;i++) b[i]=pow(10,-(b[i]/2.));

//	delete report;
	for(i=0;i<D_Z[0];i++)	{fr[i]=0;fi[i]=0;}
	for(;i<D_Z[1];i++)
	{
		fr[i]=(1-b[0])/2.*(1+cos((i-D_Z[0])/(D_Z[1]-D_Z[0])*PI))+b[0];
		fr[i]=-log10(fr[i]);
		fi[i]=0;
	}
	for(i=D_Z[2];i<D_Z[3];i++)
	{
		fr[i]=(b[1]-b[0])/2*(1-cos((i-D_Z[0])/(D_Z[1]-D_Z[0])*PI))+b[0];
		fr[i]=-log10(fr[i]);
		fi[i]=0;
	}
	return(1);
}

void lim_v()
{
	int i;
	int but_num=2,flag;
	char *but_name[]={"确定","取消"};
	char *report_dia = "测压通道结构参数";
	char *reportBox[]={"通道长度mm","通道内径mm","冷却水温度k"};
	char *BoxTemp[]={"0","0","0"};
	float b[3];
//添写文件名

	Dialog *report;
	report = new Dialog(3,but_num,but_name,report_dia,reportBox);
	report->Puttobox(BoxTemp);
	flag=report->DialogControl();
	switch(flag)
	{
		case 0://Yes
			for(i=0;i<3;i++) b[i]=atof(report->Getboxcontent(i));
			report->~Dialog();
			break;
		case 1:
		case -1:report->~Dialog();
			return;
	}

}


void save(int num,float *fr,float *fi)
{
	FILE *fp;
	status_line("请输入传递函数文件名：",filename[0],1);
	if((fp=fopen(filename[0],"w"))==NULL)
	{
		status_line("文件名错，或磁盘满，按任意键返回！","",0);
		getch();
		return;
	}
	fwrite(fr,num*2+4,1,fp);//实际是num/2+1个数
	fwrite(fi,num*2+4,1,fp);
	fclose(fp);
}

int Back_fil(int num,char flag)//逆滤波 0需输入传递函数名
//-1不需输入传递函数名程序自动读取filename[0]文件
//文件无不进行逆滤波返回0,否则1
{
	int i;
	FILE *fp;
	if(flag<=0)//读传递函数到fr,fi
	{
		if(flag==0)status_line("请输入传递函数文件名",filename[0],1);
		if((fp=fopen(filename[0],"r"))==NULL)
		{
			status_line("文件名错，或文件不存在，按任意键返回！","",0);
			getch();
			return(0);
		}
		fread(fr,num*2+4,1,fp);
		fread(fi,num*2+4,1,fp);
		fclose(fp);
	}

	for(i=0;i<=(num/2);i++)
	{	pr[i]-=fr[i];pi[i]-=fi[i];
		v[i]=pr[i];
		pr[i]=pow(10,pr[i]);
		fr[i]=pr[i]*cos(pi[i]);
		fi[i]=pr[i]*sin(pi[i]);
		pr[i]=v[i];
		if(i==0) continue;
		fi[num-i]=-fi[i];
		fr[num-i]=fr[i];
	}
	kbfft(fr,fi,1024,10,p,ca,1,0);
	for(i=0;i<num;i++) ca[i]=i*FCA-360.;
	return(1);
}


void analysis()//数据处理手工滤波  算放热率
{

	Frame frame;
	PutHZ puthzs;
	setviewport(0,0,getmaxx(), getmaxy(),1);  //工作区视口大小
	DCu=new Draw_Curve();
	DCu->Set_Data(-360,360,0,16);
	DCu->set_div(18,4);
	DCu->set_window(0,0,640,480);
	unsigned char *ButName[]={"输入文件名","示功图","压力升高率","频谱图","Ｂ样条滤波","带阻滤波",\
"逆滤波","传递函数","有限容积法","放热率计算","修改坐标轴","复倒谱","返回主菜单"};
//	bar(0,0,640,480);
	char *B_image[]={"输入数据文件名，显示示功图调整上止点","显示示功图调整上止点","压力升高率","气缸\
内压力ｐ或传递函数的频谱图","采用Ｂ样条法对气缸内压力进行滤波（测压通道〈５０mm）",\
"采用复合带阻滤波法对气缸内压力进行滤波（测压通道〈９０mm）","采用传递函数对\
气缸内压力进行滤波","计算传递函数","使用有限容积法修正对超长通道示功图",\
"计算放热规律曲线","清除坐标轴及曲线","压力复倒谱","清除画面返回主菜单",};

	frame.SetData(0,0,640,480,1);

	int key=ESC;
	char Axe_auto=1,buff[20];
	ButtonGroup *MenuBtn=new ButtonGroup(22,17,B_num,ButName,B_image);   // 显示主菜单
	do{

		frame.DrawFrame();
		frame.SetData(1,1,638,478,0);
		frame.DrawFrame();
		setfillstyle(SOLID_FILL,WHITE);
		bar(2,2,637,477);
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(12,2,158,32+26*B_num);
		frame.SetData(12,2,146,30+26*B_num,1);
		frame.DrawFrame();
		frame.SetData(22,17,126,26*B_num,0);
		frame.DrawFrame();

		MenuBtn->DrawButtonGroup();
		key =0;
		while(key != CRKEY)
		{
			MenuBtn->ControlButtonGroup(key);
			key= _bios_keybrd(_KEYBRD_READ);
		}
		key=MenuBtn->GetChoice();

//		     else continue;
/*		if(dis_data1(1)==0)
		{
			status_line("请先输入文件名！按任意键返回", "",0);
			getch();
			status_line("", "", 2);
			continue;
		}
*/
		switch(key)
		{

			case 0:
				status_line("请输入示功图数据文件名：",filename[0],1);
				dis_data1(filename[0]);//输入文件名，计算频谱
			case 1:

				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);

				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();

				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p);
				for(int i=0;i<20;i++) buff[i]=0;
				status_line("输入新上止点（回车不改变上止点）：",buff,1);
				if(strlen(buff)>0)
				{
					Change_tdc(Dot_num,ca,p,atof(buff));
					DCu->Draw_Cur("示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p,BLUE,2);
				}
				break;
			case 2://dp/dca
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);

				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				for(i=1;i<1024;i++) v[i]=p[i]-p[i-1];
				v[0]=p[0]-p[1023];
				if(Axe_auto) DCu->Get_max(Dot_num,ca,v);
				DCu->Draw_Cur("压力升高率","曲轴转角","气缸压力升高率MPa/CA",Dot_num,ca,v);
				break;
			case 11://dp**2/dca
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);

				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				v[0]=p[0]-p[1023];
				for(i=1;i<1024;i++)
				{	v[i]=p[i]-p[i-1];
					fi[i]=v[i]-v[i-1];
				}
				fi[0]=v[0]-v[1023];
				if(Axe_auto) DCu->Get_max(Dot_num,ca,fi);
				DCu->Draw_Cur("复倒谱","曲轴转角","压力复倒谱ＭＰａ",Dot_num,ca,fi);
				break;
			case 3://频谱图
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);
				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				for(i=0;i<513;i++) fr[i]=i;
				if(Axe_auto) DCu->Get_max(513,fr,pr);
				DCu->Draw_Cur("气缸压力ＭＰａ频谱图","谐波数","",513,fr,pr);
				break;
			case 4://Ｂ样条滤波
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);
				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p);
			//输入Ｂ样条滤波参数并滤波
				status_line("请输入滤波次数",buff,1);
				if(strlen(buff)==0) break;
				b3_smoflt(p,1024,atoi(buff));
				DCu->Draw_Cur("示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p,BLUE,2);
				break;
			case 5://带阻滤波
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);
				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				for(i=0;i<513;i++) fr[i]=i;
				if(Axe_auto) DCu->Get_max(513,fr,pr);
				DCu->Draw_Cur("气缸压力频谱图","谐波数","",513,fr,pr);
			//输入带阻器滤波参数并滤波
//				status_line("请输入带阻滤波器参数",buff,1);
				if((get_D_Z(513,fr,fi))==NULL) break;
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);
				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p);
				Back_fil(1024,1);//逆滤波
				DCu->Draw_Cur("示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p,BLUE,2);
				break;
			case 6://逆滤波
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);
				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p);
			//输入传递函数到fr,fi并滤波,示功图频谱pr,pi
				if(Back_fil(1024,0)==0) break;//逆滤波 0需输入传递函数名
				b3_smoflt(p,1024,8);
				DCu->Draw_Cur("示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p,BLUE,2);
				break;
			case 7://传递函数
			//记录原示功图频谱于fr,fi重新输入示功图并计算pr,pi
			//传递函数log(fr)-log(pr),fi-pi存入pr,fi
				memcpy(fr,pr,4*513);
				memcpy(fi,pi,4*513);
				status_line("请输入示功图数据文件名：",filename[0],1);
				dis_data1(filename[0]);//输入文件名，计算频谱
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);
				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("无通道示功图","曲轴转角","气缸压力ＭＰａ",Dot_num,ca,p,BLUE,2);
				for(i=0;i<513;i++) {pr[i]=fr[i]-pr[i];fi[i]-=pi[i];fr[i]=i;}
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,640,480);
				if(Axe_auto) DCu->Get_max(513,fr,pr);
				DCu->Draw_Cur("传递函数频谱图","谐波数","",513,fr,pr);
				save(1024,pr,fi);//
				break;
			case 8://  有限容积
				lim_v();
				status_line("系统错误,按任意键返回", "",0);
				getch();
				break;
			case 9://放热率计算
				if(Rohr.Get_Data()==0) break;
				char yes[2];
				status_line("调整压力基值吗?", yes,1);
				status_line("请输入放热率文件名：", filename[0],1);
				rohr1(toupper(yes[0]),filename[0]);
				data_show();
				file_Num=1;
				break;
			case 10://修改坐标轴
				DCu->Change_Axe();//改坐标轴
				Axe_auto=0;
				break;
			case 12://返回主菜单"
				setfillstyle(SOLID_FILL,WHITE);               // 状态行填充LIGHTGRAY
				bar(0,0,700,500);
				key++;
				break;
		}
		status_line(txt[0],"",0);
	}while(key<B_num);
	MenuBtn->EraseButtonGroup();
	delete MenuBtn;
	delete DCu;
}




