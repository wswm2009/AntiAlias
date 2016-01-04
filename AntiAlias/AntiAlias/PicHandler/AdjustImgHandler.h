#pragma once

#define _BYTE  BYTE
#define _DWORD DWORD
#define _WORD  WORD
#define ___thiscall _cdecl
typedef struct _MyStruct1
{
	int Vtbl;
	int Number_04;
	int Number_08;
	int Number_0C;
	int Number_10;
	int Number_14;
	int Number_18;
	int Number_1C;
	int Number_20;
}MyStruct1,*pMyStruct1;

typedef struct _MyStruct
{
	int Vtbl;
	int Number_04;
	int Number_08;
	int Number_0C;
	int Number_10;
	int Number_14;
	int Number_18;
	int Number_1C;
	int Number_20;
	int Number_24;
	int Number_28;
	int Number_2C;
	int Number_30;
	int Number_34;
	int Number_38;
	int Number_3C;
	int Number_40;
	int Number_44;
	int Number_48;
	int Number_4C;
	int Number_50;
	int Number_54;
	int Number_58;
	int Number_5C;
	int Number_60;
	int Number_64;
	int Number_68;
}MyStruct,*pMyStruct;
typedef struct TagARGBQuad
{
	unsigned char rgbReserved;
	unsigned char rgbRed;
	unsigned char rgbGreen;
	unsigned char rgbBlue;
}ARGBQuad, *PARGBQuad;
typedef struct TagPicBuff
{

	unsigned char *pBuff;
	int  dwHeight;
	int  dwWidth;
	int  dwWidth1;
	int  num;
}PicBuff, *PPicBuff;
typedef struct tagIndex
{
	//int   dwIndex;
	RECT  rc;
	unsigned char *szSrcBuffR;
	unsigned char *szSrcBuffG;
	unsigned char *szSrcBuffB;
	int   dwIndex;
}STINDEX, *PSTINDEX;

/************************************************************************/
/* 提示对图片的处理接口                                                                     */
/************************************************************************/
class CAdjustImgHandler
{
public:
	CAdjustImgHandler(void);
	~CAdjustImgHandler(void);

	//设置父窗口
	void SetParentHwnd(HWND hParent);
	//设置需要处理图片
	bool SetNeedProcessImage(Bitmap* pInputBitmap);
	//返回处理后的结果图
	Bitmap* GetResultImage();

	void OnSaveImage(CString strImgPath);
	void imgSave(BYTE* imgData, int width, int height, int stride, CString fileName, Gdiplus::PixelFormat pixelFormat);
	bool CloseImage(Bitmap *pBitmap);
	void saveMask(BYTE* mask, int width, int height, CString filePath);
	//可处理主图
	Bitmap*  m_pMainBitmap;

	//返回结果图片
	Bitmap* m_pResultBitmap;

    //保存的BYTE*
	BYTE *m_SaveBuff ;
	


public:
	/************************************************************************/
	/*  自定义接口                                                           */
	/************************************************************************/


	//示例：灰度化
	//生成灰度图
//	void Graying(byte* imgData,byte* pGray,int width,int height,int stride);
	
	//亮度和对比度功能入口
	void BrightAndContrast(short ArgBright,short ArgContrast,BOOL ArgIsOld);
	void AutoBrightAndContrast(double *OutValue, long long ArgIsOld);
	
	//消除锯齿 Add By Wm 2015年12月15日 17:26:37
	void AntiAlias();
	DWORD m_Toler;//容差
	BOOL m_Ctn;//连续
	BOOL m_Clear;//消除锯齿
	POINT m_Pt;//点击的坐标
	BOOL m_IsFinish;//是否完成
public:
	/************************************************************************/
	/* 通用调用接口、参数                                                                     */
	/************************************************************************/



private:
	/************************************************************************/
	/* 内部处理函数                                                                     */
	/************************************************************************/

	//函数处理完调用刷新图片
	bool UpdateImageData();

	//
	HWND m_hParentHwnd;
};
int  GetEncoderClsid(const TCHAR* format, CLSID* pClsid);

//Anti-Alias功能核心算法
void MakeValeus100(BYTE * Data100, BYTE byteVal, bool IsClear);
int __stdcall sub_18A4630(unsigned int a1, unsigned int a2, int a3, int a4);
BYTE GetByteValue(BYTE *v24);
__int64 __stdcall sub_18A42D0(int a1, int a2, int a3, int a4);
int __cdecl sub_618350(int a1, int a2, signed int a3, int a4);
char __cdecl sub_6180E0(int a1, int a2, signed int a3, int a4, int a5);


void __cdecl sub_618240(int a1, signed int a2, int a3, int a4);
void __cdecl sub_617F40(int a1, signed int a2, int a3, int a4, int a5);
_BYTE *__cdecl sub_1AF6100(int a1, _BYTE *a2, int a3, int a4);
int __cdecl sub_619320(int pRBuff, int pGBuff, int pBBuff, int pOutBuff, int PicHeight, int PicWidth, int _PicWidth, int __PicWidth, int pTempInBuff);
int __cdecl sub_616990(int pRBuff, int pGBuff, int pBBuff, __int16 *a4, int hSize, int vSzie, int Width, int a8, __int16 a9, int pOutBuff);
int  sub_EFCE70(void *_this, int a2, void *Dst, int a4, int a5);
int  sub_EFCFE0(int _this, int a2, void *Dst);
void __cdecl MakeArg1AndArg2(int a1, float a2, float a3, char a4, int a5, int a6);
void MakeMidValue(UCHAR *ArgValue, short ArgBright, short ArgContrast, long long ArgIsOld);
int  sub_1AF61A0(int Arg_SrcOffset, signed int Arg_DecOffset,  int Arg_Height, int Arg_Width, int a5, int a6, int valuesBuff);
int  sub_14014A0(int _this);
int  sub_1162910(int _this);
void *  sub_1404A80(void *_this, int a2, int a3);  //构造函数
int  sub_141DC40(void *_this, int a2, int a3, char a4);
void __cdecl sub_C3EBC0(int a1, int a2, int arg8, __int64 a8);
void __cdecl sub_194F5D0(void **_this, void *a2);
void  sub_15D8340(void **_this);
long double __cdecl sub_C3EAD0(int a1, int a2, int a3, int a4);
double  sub_196C870(int a2, const void *a3, int a5, int a6, double a7, __int64 a8);
int __cdecl sub_196C360(const void *a1, const void *a2);
void __cdecl sub_196C3A0(int a1, int a2, int a3, int a4, double a5, double a6);
void *__cdecl unknown_libname_68(unsigned int a1);
void MakeBrightAndContrastValue(int buuf1, int buff2, int OutValue, __int64 IsOldVer);
int  sub_D29330(int _this, double a2);
int  sub_D29410(int _this, double a2);
__int16  CalcMidValue(void *_this, signed int a2, int a3, int a4, unsigned int IsOldVer);
int  sub_7047A0(int _this, int a2);
void  sub_C3E000(int _this, unsigned int a2, float *a3);
void *__stdcall sub_94F7C0(unsigned int a1);
int __cdecl sub_7027B0(int a1, int a2, int a3, int a4);
float *__cdecl sub_46BF40(int a1, float *a2, float *a3);
void * sub_61B5F0(int _this, unsigned int a2);
void  sub_D652E0(int _this, int a2);
void  sub_164EC20(void *_this, unsigned int a2);
int __cdecl sub_DF08E0(float *a1, float *a2, float *a3, signed int a4, int a5, signed int a6, int a7, float *a8, int a9, signed int a10);
int  sub_14032C0(void *_this, int a2, int a3, int a4, int a5);
int  sub_1402260(int _this, int a2);
int  sub_14022A0(int _this, int a2, __int16 *a3, int a4, __int16 a5);
int  sub_170C000(int _this, int a2, int a3);
void * sub_170C040(void *_this, int a2);
int  sub_170C240(int _this, int a2, int a3);
int  sub_170BFC0(int _this, int a2, int a3);
void __cdecl sub_DFBD70(int a1, int a2, int a3, int a4, int a5, int a6, int a7, float a8, float a9, float a10);
void __cdecl sub_DF9B60(void *Src, int a2, int a3);
int __cdecl sub_58BEB0(int a1, int a2, int a3);
void ___thiscall sub_1616600(void *_this, unsigned int a2);
int MyNew(unsigned int iSize);
int __cdecl sub_DF77A0(int a1, unsigned int a2, unsigned int a3);
void __cdecl sub_DF3FF0(float *a1, float *a2, float *a3);
void __cdecl sub_DF69B0(int a1, int a2, int a3);
void __cdecl sub_DF3F50(void *Src, int a2);
void __cdecl sub_DF3EC0(float a1, int a2);
void __cdecl sub_DEF700(int a1, int a2, int a3, float *a4);
int __cdecl sub_DF7AF0(float *a1, int a2);
void __cdecl sub_DF0D80(int a1, int a2, int a3, float *a4);
void *__stdcall sub_41FC00(unsigned int a1);
void __cdecl sub_DFC340(int a1, int a2, int a3, int a4, int a5, int a6);
int ___thiscall sub_DFC070(int _this, unsigned int a2);
void ___thiscall sub_44DC50(int _this, int a2);
void ___thiscall sub_1648E60(void *_this, unsigned int a2);
void *__stdcall sub_7AB7B0(unsigned int a1);
int __cdecl sub_56A9A0(int a1, int a2, int a3, int a4);
int __cdecl sub_5193A0(int a1, int a2, int a3);
int __cdecl sub_18B83D0(int a1, int a2, int a3, int a4);
int ___thiscall sub_91B980(int _this, int a2, int a3, int a4);
void __cdecl sub_DFAFD0(int a1, int a2, int a3, signed int a4, int a5, int a6, int a7);
int __cdecl sub_1778CE0(int a1, char a2);
BOOL __cdecl sub_17769D0(unsigned int a1);
float __cdecl sub_1799BB0(float a1, char a2);
BOOL __cdecl sub_1798AA0(float a1);
double __cdecl sub_4F6450(double a1, float a2);
int __cdecl sub_DF7D30(int a1, int a2, int a3, int a4, float a5, float a6, int a7);
void ___thiscall sub_DF6940(int _this, unsigned int a2, float *a3);
int __cdecl sub_4E17C0(double a1, char a2);
BOOL __cdecl sub_4E1020(double a1);
void __cdecl sub_DF9270(int a1, int a2, int a3, signed int a4, unsigned int a5, int a6, int a7);
void __cdecl sub_DFB4D0(int a1, int a2, int a3, signed int a4, int a5, int a6);
int __cdecl sub_524340(float a1, char a2);
BOOL __cdecl sub_522FA0(float a1);
int __cdecl sub_DEF580(int a1, int a2, int a3, signed int a4, int a5, signed int a6);
void  sub_DFE850(int a2, int a3, signed int a4, signed int a5, unsigned int a6, char *a7);
unsigned int ___thiscall sub_DFDDE0(int _this, unsigned int a2);
void ___thiscall sub_726CC0(int _this, int a2);
int __cdecl sub_718360(int a1, int a2, int a3, int a4);
int __cdecl sub_706080(int a1, int a2, int a3);
void ___thiscall sub_710820(void *_this, int a2, int a3);
void __cdecl sub_718400(int a1, int a2);
void __cdecl sub_5C3860(int a1, unsigned int a2, int a3, int a4);
_DWORD *___thiscall sub_5C3AF0(void *_this, _DWORD *a2, int a3, int a4);
int __cdecl sub_189AAC0(int a1, int a2, int a3);
double __cdecl sub_4F6970(signed int a1, char a2);
BOOL __cdecl sub_E018D0(int a1);
void __cdecl sub_DF96E0(int a1, float *a2, int a3, int a4, signed int a5, signed int a6, unsigned int a7, int a8, int a9);
void __cdecl sub_DFC3D0(int a1, int a2, int a3, signed int a4, int a5, int a6, int a7);
int ___thiscall sub_51A070(int _this, int a2);
void ___thiscall sub_6E1340(int _this, int a2);
int __cdecl sub_1AE7400(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void *__cdecl sub_1AF50E0(void *Dst, size_t Size, char a3);
int __cdecl sub_5CC640(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
int *___thiscall sub_C2DB50(int a2, signed int *a3, int *a4);
int __cdecl sub_1AE6FA0(int a1, int a2, int a3, signed int a4, signed int a5, int a6, int a7);
void *__cdecl sub_1AF4DA0(void *Src, void *Dst, size_t Size);
int __cdecl sub_1AF4EB0(void *Src, void *Dst, int a3, size_t Size, int a5, int a6);
float *__cdecl sub_1AFE150(void *Src, void *Dst, int a3, int a4, int a5, int a6, int a7, int a8);
void DataConvert(void *pDes, void *pSrc, int dwWidth, int dwHeight, int dwTempValue,int MagicNum);
int __cdecl sub_1AFE420(int pSrcBuff, int DesBuff1, int DesBuff2, int DesBuff3, int Height, int Width, unsigned int OutPutvalue, unsigned int Stride);
PBYTE _stdcall ChangePosition(PBYTE pSrc, __out PBYTE pOutput, int dwSize);
int __cdecl sub_1AF8730(int a1, int a2, int a3, int a4);
void SliptRGB(const BYTE * pSrcByte, BYTE *pBuffB, BYTE *pBuffG, BYTE *pBuffR, DWORD dwSize,DWORD dwTongDao);
void ZoomHanlder(STINDEX *pIndex, int iCount);
void ExtARGBPic(const BYTE *pSrcBuff, BYTE *pDesBuff, DWORD dwSize);
int GetZoomRatio(STINDEX *stInx, RECT &rcSrc, RECT &rcDes);
unsigned int __cdecl ComposeRGB(unsigned char *pbuff_R, unsigned char *pbuff_G, unsigned char *pbuff_B, unsigned char *OutBuff, int dwHeight, int dwWidth, int dwWidth1, int dwStride);