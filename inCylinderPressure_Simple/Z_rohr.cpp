#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Z_ROHR.h"

#define	PI	3.14159365
#define	SI	1
#define	Rad	PI/180.0
#define	FLTH	14.28894
#define	Ra	287.06
#define	Rb	286.41
#define	Ps0	.101325
#define F	1.003433

void status_line(char *, char *, int);

void Engine::Insert(Engine *p)
{
	p->next=next;
	p->pre=this;
	next->pre=p;
	next=p;
}
Engine* Engine::Del()
{
	pre->next=next;
	next->pre=pre;
	return this;
}

void Engine::put_stru(char **temp,int i)
{
	strcpy(name,*temp);
	float *p=&d;
	for(;i>0;i--)
		*p++=atof(*++temp);
}

void Engine::get_stru(char **temp,int i)
{
	strcpy(*temp,name);
	float *p=&d;
	for(;i>0;i--)
		sprintf(*++temp,"%f",*p++);
}

void Engine::read_stru(FILE *ndi)
{
	fscanf(ndi,"%s%f%f%f%f%f",name,&d,&fl,&rc,&eps,&stroke);
	fscanf(ndi,"%f%f%f",&phiv,&phic,&phio);
}

void Engine::write_stru(FILE *ndi)
{
	fprintf(ndi,"%s\t%f\t%f\t%f\t%f\t%f\t",name,d,fl,rc,eps,stroke);
	fprintf(ndi,"%f\t%f\t%f\n",phiv,phic,phio);
}

Engine* Engine::NEW()
{       int i;
	for(i=0;i<10;i++)name[i]=0;
	float *p=&d;
	for(i=0;i<8;i++) *p++=0;
	return this;
}

void ROHR::read_para(FILE *ndi)
{
	fscanf(ndi,"%f%f%f%f%f",&d,&fl,&rc,&eps,&stroke);
	fscanf(ndi,"%f%f%f%f%f",&phiv,&phic,&phio,&hu,&resir);
	fscanf(ndi,"%f%f%f%f%f",&hop,&pop,&delx,&fkqwc,&pfac);
	fscanf(ndi,"%f%f%f%f%f",&rpm,&fne,&pk0,&tk0,&pr);
	fscanf(ndi,"%f%f%f%f%f",&tr,&gf0,&tw1,&tw2,&tw3);
	fscanf(ndi,"%f%f%f%f%f",&ds,&delpc,&deltc,&step,&rovm);
	fscanf(ndi,"%f%f%f",&trp,&eta_e,&ckap);
}


void ROHR::write_para(FILE *ndi)
{
	fprintf(ndi,"%f\t%f\t%f\t%f\t%f\n",d,fl,rc,eps,stroke);
	fprintf(ndi,"%f\t%f\t%f\t%f\t%f\n",phiv,phic,phio,hu,resir);
	fprintf(ndi,"%f\t%f\t%f\t%f\t%f\n",hop,pop,delx,fkqwc,pfac);
	fprintf(ndi,"%f\t%f\t%f\t%f\t%f\n",rpm,fne,pk0,tk0,pr);
	fprintf(ndi,"%f\t%f\t%f\t%f\t%f\n",tr,gf0,tw1,tw2,tw3);
	fprintf(ndi,"%f\t%f\t%f\t%f\t%f\n",ds,delpc,deltc,step,rovm);
	fprintf(ndi,"%f\t%f\t%f\n",trp,eta_e,ckap);
}
ROHR::ROHR()
{
	d=.4;fl=1.045;rc=.225;eps=12.5;stroke=4;phiv=100;phic=-160;phio=130;
	hu=41868.;resir=.001;hop=1.05;pop=1.4;delx=0.039;fkqwc=1.1;pfac=1.;
	rpm=600.;fne=527.8;pk0=.26;tk0=313.0;pr=0.;tr=775.;gf0=5.29;
	tw1=550.;tw2=560.;tw3=400.;ds=0;delpc=0;deltc=3;step=.703125;rovm=0;
	trp=635;eta_e=.94;ckap=1.33;
}

int ROHR::Get_Data()
{
	int j;
	int but_num=2,flag;
	char *but_name[]={"确定","取消"};
	char *report_dia = "放热率计算参数";
	char *reportBox[]={"转速（ｒｐｍ）","功率（ｋＷ）","进气压力(ＭＰａ)","进气温度(Ｋ)",\
	"排气压力(ＭＰａ)","排气温度(Ｋ)","循环供油量（ｇ）",};
	char *BoxTemp[7],buff[77];
	float *p=&rpm;

	for(int i=0;i<77;i++) buff[i]=0;
	for(i=0;i<7;i++)
	{	BoxTemp[i]=buff+i*11;
		sprintf(BoxTemp[i],"%9.3f",*p++);
	}

//添写文件名
	p=&rpm;
	Dialog *report;
	report = new Dialog(7,but_num,but_name,report_dia,reportBox);
	report->Puttobox(BoxTemp);
	flag=report->DialogControl();
	switch(flag)
	{
		case 0://Yes
			for(j=0;j<7;j++) *p++=atof(report->Getboxcontent(j));
			report->~Dialog();
			break;
		case 1:
		case -1:report->~Dialog();
			return (0);
	}
	return (1);
//	delete report;
}
void ROHR::Get_condition(float Pk,float Tk,float Tr,float Trp)
{
	pk0=Pk;tk0=Tk;tr=Tr;trp=Trp;
}

float ROHR::Cva(float Te)
{return ((20805.721-1.3270110*Te+4.0681743e-3*Te*Te-1.7085206e-6*Te*Te*Te+0.22947513e-9*Te*Te*Te*Te)/28.964);}

float ROHR::Cvb(float Te)
{return ((20720.007+2.1485250*Te+2.4822841e-3*Te*Te-1.2675601e-6*Te*Te*Te+0.17784060e-9*Te*Te*Te*Te)/29.0301);}

float ROHR::dqwc(float Te)
{return (fk7*pow(Te,-0.525)*pow(pm,0.786)*(f1*(Te-tw1)+f2*(Te-tw2)+f3*(Te-tw3)));}

float ROHR::xn(float x)
{return (rc*(1.0-cos(x))+fl*(1.0-sqrt(1.0-pow((rc/fl*sin(x)),2))));}

void ROHR::CA_Cacu()
{
	for(int i=0;i<ndata;i++) CA[i]=(float)(i-ndata/2)*step;
	CA[ndata]=CA[0]+360.0;
}

void ROHR::set_data(float *Ca,float *Y,float *p,float *dp,float *t,float *dq,float *dw,float *q,float *f)
{
	CA=Ca; y=Y; p0=p; dpl=dp; dql=dq; dqwl=dw; ql=q; Fuel_burn=f; T=t;
}

void ROHR::Init(char i)//input data are metric system (0) or SI (1)
{
	unit=i;
	if(unit==SI)
	{
//SI unit:
//Pressure : kgf/cm2     Length : m     Temperature : k     Power : ps
//Engine speed : r.p.m.                 Quantity of Fule : g/cycle
//Crank Angle (CA) : degree   Low Calorific Value of Fule : kcal/kg-fule

		aa=0.0980665;
		bc=4186.8; // j/kcal
		cc=1.35962;//ps convert to kW
	}
	else
	{
//   units : p-mpa , W-kW , q-j , m-g ';
		aa=1.0;
		bc=1000.0;
		cc=1.0;
	}
	pp=1.0e6;
	fk7=fkqwc*bc*265.0*pow(d,-0.214)*pow((rpm*rc/15.0/aa/pp),0.786)/21600.0/rpm;
	Area=0.25*PI*d*d;
	f1=Area*hop+delx*PI/2.0;
	f2=Area*pop+delx*PI/2.0;

	if(pr==0.)
	{/*      caculate pr;	*/
		pr=tr-trp;
//		printf("rc=%f",rc);
		pr=pr/eta_e;
		trp=tr-pr;
		dp0=ckap/(ckap-1);
		pr=pow((tr/trp),dp0)*.101325;
	}

	if(deltc<220.)//deltc<220k,deltc是ΔT计算进气门关时气体温度T,否则是T
	{
		deltc=85.37+5.0/6.0*tk0-20*(pk0-Ps0)+deltc;
		float y=pk0/pr-1.0;
		float ay=fabs(y);
		if(ay>1.0e-30) deltc=deltc-(y/ay)*2.1*sqrt((phiv-8.0)*sqrt(ay));
	}
	ndata=360.0/step+0.01;
}
void ROHR::Press_cacu()
{
	int i;
/*	do
	{	fscanf(ndi,"%f%f",ca,y);
//		printf("%f\t%f\n",ca[0],y[0]);
	}while(ca[0]<-180.0);
	for(i=1;i<ndata;i++)
	{
		fscanf(ndi,"%f%f",&ca[i],&y[i]);
//		printf("%d\t%f\t%f\n",i,ca[i],y[i]);
	}

 //	while(ca[i++]<-180.0);
*/	dp0=0.0;
	for(i=0;i<15;i++) dp0=dp0+y[i]*pfac;
	dp0=pk0-(dp0/15.0)+delpc;
	ntf=512.0/step+0.01;
	for(i=0;i<ndata;i++) p0[i]=aa*(y[i]*pfac+dp0);
}

void ROHR::Get_ds()
{
	printf("t.d.c. should chang ? old delta phi is %f\n:",ds);
	do
	{	printf("\tnew delta phi is ? :");
		scanf("%f",&ds);
		printf("ok  ? [y/n]\n");
	}while(getch()!='y');
}
//(char Unit,float *CA,float *Y,float *P0,float *dp,
  //		float *DQ,float *dqW,float *Q,float *Gf,float *T)
void ROHR::Out(float End_lim/*燃烧结束时的总放热百分比(<1)*/,float *Da)
{

	float pmax=0,T_max=0,dpmax=0,dQ_max=0, Qq;//=ql[ndata-1];
//最大压力,温度,压力升高率,放热率,总绝对放热量
	int i,i_p,i_t,i_dp,i_dq;
//及其曲轴转角,该时刻放热百分比, 	while(ql[i--]>End_lim);
	i=ndata-1;
	while(CA[i]>phio) i--;
	Qq=ql[++i];
	for(;i<ndata-1;i++) ql[i]=100.;

	ql[ndata-1]=Qq;
	for(i=0;i<ndata;i++)
	{
		if((CA[i]-ds)>phio) break;
		ql[i]/=(Qq/100);

		if(p0[i]>pmax)
		{
			pmax=p0[i];
			i_p=i;
		}
		if(T[i]>T_max)
		{
			T_max=T[i];
			i_t=i;
		}
		if(dpl[i]>dpmax)
		{
			dpmax=dpl[i];
			i_dp=i;
		}
		if(dql[i]>dQ_max)
		{
			dQ_max=dql[i];
			i_dq=i;
		}
	}
	*Da++=g0*1000.0;
	*Da++=gf*1000.0;
	*Da++=af;
	*Da++=fne/cc;
	*Da++=fni;
	*Da++=eta_m;
	*Da++=pj;
	*Da++=pk0*aa;
	*Da++=tk0;
	*Da++=pr;
	*Da++=tr;

//	i=ndata;
	while(ql[i--]>End_lim*100.);
	*Da++=CA[i]-ds;//burn end

	while(ql[i--]>0);
	*Da++=CA[i]-ds;//burn star
	*Da++=T[i];//T   温度
	*Da++=p0[i];//p  压力

	*Da++=pmax;//Pz      最高压力
	*Da++=CA[i_p]-ds;//Ca 最高压力对应的曲轴转角
	*Da++=ql[i_p];//Q  最高压力时对应的累积放热率
	*Da++=dpmax;//dp max  　最大压力升高率
	*Da++=CA[i_dp]-ds;//CA   最大压力升高率对应的曲轴转角
	*Da++=ql[i_dp];//Q      最大压力升高率时的累积放热率
	*Da++=T_max;//T max     最高温度
	*Da++=CA[i_t]-ds;//CA   最高温度对应的曲轴转角
	*Da++=ql[i_t];//Q      　最高温度对应的累积放热率
	*Da++=dQ_max;//dq Max   最大放热率
	*Da++=CA[i_dq]-ds;//CA  最大放热率对应的曲轴转角
	*Da=ql[i_dq];//Q        最大放热率对应的累积放热率
}

void ROHR::rohr()
{
	float qb=0,gg,pc,x1,bb,Rg,df,v1,fx,fx2,FJL[]={0.5,0.5,1.0,1.0,0.5};
	float p2,p1,dW,gl,t1,t2,c1,dg,caid,v2,gm,g,c2,tm,dqw,ai;//,gfe;//,p2p;
	int i,k,ca,kk;
//	printf("during running , print ca. t. p. dp. gf. gg. qw. dqb/da. ? [y/n]");
	gf=0.0;
	qw=0.0;
	W=0.0;
	gg=0.0;
	ica=0;
	for(i=0;i<ndata;i++) if((fabs(CA[i]-ds-phic))<=(step/2.)) {ica=i; break;}
	pc=pp*p0[ica];


//	printf("deltc=%f  tk0=%f  pr=%f",deltc,tk0,pr);
	x1=2.0*rc/(eps-1.0);
	bb=Rad*(CA[ica]-ds);
	Rg=Ra*(1.0-resir)+Rb*resir;
/*
	float xxxx;
	printf("Rg=%f pc=%f bb=%f ca=%f\n",Rg,pc,bb,ca[ica]);
	xxxx=rc/fl*sin(bb);
	printf("rc=%f fl=%f xxx=%f\n",rc,fl,xxxx);
	xxxx=pow((rc/fl*sin(bb)),2);
	printf("rc=%f fl=%f xxx=%f\n",rc,fl,xxxx);
	xxxx=1.0-pow((rc/fl*sin(bb)),2);
	printf("rc=%f fl=%f xxx=%f\n",rc,fl,xxxx);
	xxxx=1.0-sqrt(1.0-pow((rc/fl*sin(bb)),2));
	printf("rc=%f fl=%f xxx=%f\n",rc,fl,xxxx);
*/	g0=Area*(xn(bb)+x1)*pc/deltc/Rg;
	af0=g0/FLTH/gf0*1000.0;
	df=CA[1]-CA[0];

	bb=Rad*(CA[0]-ds);
	v1=Area*(xn(bb)+x1);
	fx=PI*d*(xn(bb)+x1-delx);
	fx2=fx;
	p1=pp*p0[0];
	t1=p1*v1/g0/Rg;
	t2=t1;
	c1=Cva(t1)*(1.0-resir-gg)+Cvb(t1)*(resir+gg);
	dg=0.0;
	for(i=0;i<ndata;i++)
	{
		df=CA[i+1]-CA[i];
		caid=CA[i+1]-ds;
		bb=Rad*caid;
		v2=Area*(xn(bb)+x1);
		fx=PI*d*(xn(bb)+x1-delx);
		p2=pp*p0[i+1];
		pm=0.5*(p1+p2);
		dW=pm*(v2-v1);
		W=W+dW;
		gl=gf;

		kk=4;
		if((caid<-20.0)||(caid>130.0)) kk=1;
		for(k=0;k<kk;k++)       //实际为龙格库塔法计算
		{	if(caid>=130.0) dg=0.0;
			if(caid<=-20.0) dg=0.0;
			gm=gl+FJL[k]*dg;
			gf+=FJL[k+1]*dg/3.0;
			if(gf<0.0) gf=0.0;
			g=g0+gm;
			gg=gm*(FLTH+1.0)/g;
			Rg=Ra*(1.0-resir-gg)+Rb*(resir+gg);
			t2=p2*v2/g/Rg;
			c2=Cva(t2)*(1.0-resir-gg)+Cvb(t2)*(resir+gg);
			f3=0.5*(fx+fx2);
			tm=0.5*(t1+t2);
			dqw=dqwc(tm);
			ai=dqw+g*(c2*t2-c1*t1)+dW;
			if(caid>-20.0) dg=ai/hu/bc;
		}
		dg=gf-gl;
		qb=gf*hu*bc;
		g=g0+gf;
		gg=gf*(FLTH+1.0)/g;
		Rg=Ra*(1.0-resir-gg)+Rb*(resir+gg);
		t1=p2*v2/g/Rg;
		qw=qw+dqw;
		dql[i]=ai/df;
		dqwl[i]=dqw/df;
		T[i]=t1;
		ql[i]=qb;
		Fuel_burn[i]=gf;
		dpl[i]=(p2-p1)/pp;
		p1=p2;
		v1=v2;
		c1=c2;
		fx2=fx;

//printf("%f\n",CA[i]);

//		p2p=p2/pp;
//		gfe=gf*1000.0;
/*		if(yn.eq.yes) printf("95) caid,t2,p2p,dpl[i],gfe,gg,qw,ai;
95    formaT[2f8.1,4f9.4,2e13.4];
*/
	}
	if(gf!=.0) af=g0/gf/FLTH;
	fni=rpm/stroke/3.0e4*W;
	pe=stroke/rpm*3.0e4*fne/Area/rc/2.0/pp/cc;
	pj=stroke/rpm*3.0e4*fni/Area/rc/2.0/pp;
	eta_m=fne/fni/cc;
}

void ROHR::Main(float *Ca,float *Y,float *p,float *dp,float *dq,float *q,float *f,float *t,float *dw)
{
	int i;//,j,k;
FILE *ndi,*ndo;
CA=Ca;y=Y;p0=p;dpl=dp;dql=dq;dqwl=dw;ql=q;Fuel_burn=f;T=t;

char fname[30];
	printf("caculate rohr only for 135\n");

	scanf("%s",fname);
	if((ndi=fopen(fname,"r"))==NULL)
	{	printf("File not found");exit(0);}

	read_para(ndi);
	Init();

	fclose(ndi);

	printf("input presure file as [.dat]");
	scanf("%s",fname);
	if((ndi=fopen(fname,"r"))==NULL)
	{	printf("File %s not found",fname);exit(0);}
//	printf("rc=%f",rc);
	Press_cacu();
	CA_Cacu();
	fclose(ndi);
	for(;;)
	{
		printf("smoothing the pressure ? [y/n] ");
//		if(getch()=='y') smoflt(p0,dpl,ql,T,ndata,ntf);
		rohr();
		printf("smoothing the rate of heat release ?[y/n]\n");
		if(getch()=='y')
		{
			for(i=0;i<ndata;i++) p0[i]=dql[i];
//			smoflt(p0,dpl,ql,T,ndata,ntf);
			printf("the smoothed rohr is saved in file ? [.smq]\n");
			scanf("%s",fname);
			if((ndo=fopen(fname,"w"))==NULL)
			{	printf("File %s not found",fname);exit(0);}
			for(i=0;i<ndata;i++)
				fprintf(ndo,"%f\t%e\n",CA[i]-ds,p0[i]);
			fclose(ndo);
		}
		printf("ok  ? [y/n]\n");
		if(getch()=='y') break;
		Get_ds();
	}
}
