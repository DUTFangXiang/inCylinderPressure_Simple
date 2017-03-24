#ifndef DLL__H__
#define DLL__H__

//---------------------------------------------------------------------------
extern "C"  __declspec(dllimport)
void  __stdcall  CloseUsb(void);

extern "C" __declspec(dllimport)
int  __stdcall OpenUsb(void);

extern "C" __declspec(dllimport)
int  __stdcall ReadUsb(int readnum,unsigned char *buf);

extern "C" __declspec(dllimport)
int  __stdcall WriteUsb(int writenum,unsigned char *buf);

#endif
