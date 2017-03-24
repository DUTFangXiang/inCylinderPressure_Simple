#include <math.h>
class Engine
{
private:
	Engine *next,*pre;
protected:
	char  name[10];
	float d,fl,rc,eps,stroke,phiv,phic,phio;
//The Diameter of Cylinder Bore;The Length of ConnectingRod;
//A Half of Stroke Length;The Compression Ratio;The Number of Stroke Cycle .
//The Overlap Angle of Inlet Valve and Exhaust Valve ;The Angle of Inlet
//Valve Closed ; The Angle of Exhaust Valve Open ;
public:
	Engine(){pre=next=NULL;};
	Engine * Next(){return next;};
	Engine * Pre(){return pre;};
	void read_stru(FILE *ndi);
	void write_stru(FILE *ndi);
	char* Engine_Name(){return name+1;};
	void get_stru(char **temp,int i=8);
	void put_stru(char **temp,int i=8);
	void Insert(Engine *p);
	Engine * Del();
	Engine * NEW();
};


class ROHR:public Engine
{
//Notation    : The T.D.C of Compression Stroke is 0 deg CA , The Range
//	      of Pressure Data is from -180 deg CA to < +180 deg CA
//	      (without +180 deg CA) .
protected:
// Low Calorific Value of Fule ; The Coefficient of Residual Gas .
//The Ratio of Cylinder Head Surface to Cylinder Cross sectional Area;
//The Ratio of Piston Surface to Cylinder Cross-sectional Area;
//The Clearance between Cylinder Head and Piston at T.D.C ;
//The Modified Coefficient for Heat Transfer (Woschni's Formula);
//Proportional Factor to Modify Pressure ; Engine Speed; Effective Power.
//Pressure in Inlet Pipe ; Temperature in Inlet Pipe ; Pressure in Exhaust Pipe;
	float hu,resir,hop,pop,delx,fkqwc,pfac,rpm,fne,pk0,tk0,pr,tr,gf0;
	float tw1,tw2,tw3,ds,delpc,deltc,step,rovm,trp,eta_e,ckap;
	float pe,pj,gf,fni,fk7,qw,W,g0,dp0,af0,af,eta_m,pi,aa,bc,pp,b,cc;
	float g1,dp1,gf1,fne1,pk1,ntf,pm,f1,f2,f3,Area;//
	float *CA,*y,*p0,*dpl,*dql,*dqwl,*ql,*Fuel_burn,*T;
	int ndata;char unit;
/*
friend
void smoflt(float *x,float *y,float *q,float *T,int n,int nt);
void phuw(float *x,int nx,int isi);
void FFT(float *xreal,float *ximag,int n,int isi);
void spsm1(float *x,float *y,int n,int m);
void Window(float *x,float *y,int n,float fm,float fn,int l5,int l6,int l7,int l8);
*/
public:
	ROHR();
	void Get_condition(float,float,float,float);
	void write_para(FILE *ndi);
	int Get_Data();
	void read_para(FILE *ndi);
	void Init(char i=0);//input data are metric system (0) or SI (1)
	void Press_cacu();
//	void Main(char Unit,float *CA,float *Y,float *P0,float *dp,
//		float *DQ,float *dqW,float *Q,float *Gf,float *T);
	void CA_Cacu();
	void Main(float *Ca,float *Y,float *p,float *dp,float *dq,float *q,float *f,float *t,float *dw);
	void set_data(float *Ca,float *Y,float *p,float *dp,float *dq,float *q,float *f,float *t,float *dw);
	void Get_ds();
	void Out(float,float *);
	float Cva(float Te);
	float Cvb(float Te);
	float dqwc(float Te);
	float xn(float x);
	void rohr();
};
