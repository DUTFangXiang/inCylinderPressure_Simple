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
		status_line("�ļ�������,��������������������", "",0);
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
/*b-3-spline smooth p[m]���ߵ���  n�˲�����*/
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
		status_line("�ļ������󣡰����������", "",0);
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
//�����˲���������1,����0
{
	int i;
	int but_num=2,flag;
	char *but_name[]={"ȷ��","ȡ��"};
	char *report_dia = "�����˲�������";
	char *reportBox[]={"��������","��������","������յ�","������յ�","���˥����","��Ƶ˥����"};
	char *BoxTemp[]={"0","0","0","0","0","0"};
	int D_Z[4];
	float b[2];
//��д�ļ���

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
	char *but_name[]={"ȷ��","ȡ��"};
	char *report_dia = "��ѹͨ���ṹ����";
	char *reportBox[]={"ͨ������mm","ͨ���ھ�mm","��ȴˮ�¶�k"};
	char *BoxTemp[]={"0","0","0"};
	float b[3];
//��д�ļ���

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
	status_line("�����봫�ݺ����ļ�����",filename[0],1);
	if((fp=fopen(filename[0],"w"))==NULL)
	{
		status_line("�ļ������������������������أ�","",0);
		getch();
		return;
	}
	fwrite(fr,num*2+4,1,fp);//ʵ����num/2+1����
	fwrite(fi,num*2+4,1,fp);
	fclose(fp);
}

int Back_fil(int num,char flag)//���˲� 0�����봫�ݺ�����
//-1�������봫�ݺ����������Զ���ȡfilename[0]�ļ�
//�ļ��޲��������˲�����0,����1
{
	int i;
	FILE *fp;
	if(flag<=0)//�����ݺ�����fr,fi
	{
		if(flag==0)status_line("�����봫�ݺ����ļ���",filename[0],1);
		if((fp=fopen(filename[0],"r"))==NULL)
		{
			status_line("�ļ��������ļ������ڣ�����������أ�","",0);
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


void analysis()//���ݴ����ֹ��˲�  �������
{

	Frame frame;
	PutHZ puthzs;
	setviewport(0,0,getmaxx(), getmaxy(),1);  //�������ӿڴ�С
	DCu=new Draw_Curve();
	DCu->Set_Data(-360,360,0,16);
	DCu->set_div(18,4);
	DCu->set_window(0,0,640,480);
	unsigned char *ButName[]={"�����ļ���","ʾ��ͼ","ѹ��������","Ƶ��ͼ","�������˲�","�����˲�",\
"���˲�","���ݺ���","�����ݻ���","�����ʼ���","�޸�������","������","�������˵�"};
//	bar(0,0,640,480);
	char *B_image[]={"���������ļ�������ʾʾ��ͼ������ֹ��","��ʾʾ��ͼ������ֹ��","ѹ��������","����\
��ѹ����򴫵ݺ�����Ƶ��ͼ","���ã���������������ѹ�������˲�����ѹͨ��������mm��",\
"���ø��ϴ����˲�����������ѹ�������˲�����ѹͨ��������mm��","���ô��ݺ�����\
������ѹ�������˲�","���㴫�ݺ���","ʹ�������ݻ��������Գ���ͨ��ʾ��ͼ",\
"������ȹ�������","��������ἰ����","ѹ��������","������淵�����˵�",};

	frame.SetData(0,0,640,480,1);

	int key=ESC;
	char Axe_auto=1,buff[20];
	ButtonGroup *MenuBtn=new ButtonGroup(22,17,B_num,ButName,B_image);   // ��ʾ���˵�
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
			status_line("���������ļ����������������", "",0);
			getch();
			status_line("", "", 2);
			continue;
		}
*/
		switch(key)
		{

			case 0:
				status_line("������ʾ��ͼ�����ļ�����",filename[0],1);
				dis_data1(filename[0]);//�����ļ���������Ƶ��
			case 1:

				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);

				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();

				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p);
				for(int i=0;i<20;i++) buff[i]=0;
				status_line("��������ֹ�㣨�س����ı���ֹ�㣩��",buff,1);
				if(strlen(buff)>0)
				{
					Change_tdc(Dot_num,ca,p,atof(buff));
					DCu->Draw_Cur("ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p,BLUE,2);
				}
				break;
			case 2://dp/dca
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);

				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				for(i=1;i<1024;i++) v[i]=p[i]-p[i-1];
				v[0]=p[0]-p[1023];
				if(Axe_auto) DCu->Get_max(Dot_num,ca,v);
				DCu->Draw_Cur("ѹ��������","����ת��","����ѹ��������MPa/CA",Dot_num,ca,v);
				break;
			case 11://dp**2/dca
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
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
				DCu->Draw_Cur("������","����ת��","ѹ�������ףͣУ�",Dot_num,ca,fi);
				break;
			case 3://Ƶ��ͼ
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);
				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				for(i=0;i<513;i++) fr[i]=i;
				if(Axe_auto) DCu->Get_max(513,fr,pr);
				DCu->Draw_Cur("����ѹ���ͣУ�Ƶ��ͼ","г����","",513,fr,pr);
				break;
			case 4://�������˲�
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);
				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p);
			//����������˲��������˲�
				status_line("�������˲�����",buff,1);
				if(strlen(buff)==0) break;
				b3_smoflt(p,1024,atoi(buff));
				DCu->Draw_Cur("ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p,BLUE,2);
				break;
			case 5://�����˲�
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);
				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				for(i=0;i<513;i++) fr[i]=i;
				if(Axe_auto) DCu->Get_max(513,fr,pr);
				DCu->Draw_Cur("����ѹ��Ƶ��ͼ","г����","",513,fr,pr);
			//����������˲��������˲�
//				status_line("����������˲�������",buff,1);
				if((get_D_Z(513,fr,fi))==NULL) break;
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);
				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p);
				Back_fil(1024,1);//���˲�
				DCu->Draw_Cur("ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p,BLUE,2);
				break;
			case 6://���˲�
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);
				puthzs.SetData(40,0,2, 0,BLUE,txt[0]);
				puthzs.Show_hz();
				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p);
			//���봫�ݺ�����fr,fi���˲�,ʾ��ͼƵ��pr,pi
				if(Back_fil(1024,0)==0) break;//���˲� 0�����봫�ݺ�����
				b3_smoflt(p,1024,8);
				DCu->Draw_Cur("ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p,BLUE,2);
				break;
			case 7://���ݺ���
			//��¼ԭʾ��ͼƵ����fr,fi��������ʾ��ͼ������pr,pi
			//���ݺ���log(fr)-log(pr),fi-pi����pr,fi
				memcpy(fr,pr,4*513);
				memcpy(fi,pi,4*513);
				status_line("������ʾ��ͼ�����ļ�����",filename[0],1);
				dis_data1(filename[0]);//�����ļ���������Ƶ��
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);
				if(Axe_auto) DCu->Get_max(Dot_num,ca,p);
				DCu->Draw_Cur("��ͨ��ʾ��ͼ","����ת��","����ѹ���ͣУ�",Dot_num,ca,p,BLUE,2);
				for(i=0;i<513;i++) {pr[i]=fr[i]-pr[i];fi[i]-=pi[i];fr[i]=i;}
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
				bar(0,0,640,480);
				if(Axe_auto) DCu->Get_max(513,fr,pr);
				DCu->Draw_Cur("���ݺ���Ƶ��ͼ","г����","",513,fr,pr);
				save(1024,pr,fi);//
				break;
			case 8://  �����ݻ�
				lim_v();
				status_line("ϵͳ����,�����������", "",0);
				getch();
				break;
			case 9://�����ʼ���
				if(Rohr.Get_Data()==0) break;
				char yes[2];
				status_line("����ѹ����ֵ��?", yes,1);
				status_line("������������ļ�����", filename[0],1);
				rohr1(toupper(yes[0]),filename[0]);
				data_show();
				file_Num=1;
				break;
			case 10://�޸�������
				DCu->Change_Axe();//��������
				Axe_auto=0;
				break;
			case 12://�������˵�"
				setfillstyle(SOLID_FILL,WHITE);               // ״̬�����LIGHTGRAY
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




