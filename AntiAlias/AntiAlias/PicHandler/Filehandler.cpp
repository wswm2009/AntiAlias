
#include "StdAfx.h"
#ifndef   FILEHANDLE_CPP 
#define   FILEHANDLE_CPP 

#include "Filehandler.h"

//将内存里面的00 11 22 33 44 转成“00 11 22 33 44”buff
void MyHex2Str(UCHAR* Des,int DesLen,UCHAR *Src, int len)
{
	int j = 0;
	bool isret = false;
	for (int i = 0; i < len;i++)
	{
		if (0==i%0x10 && i!=0)
		{
			sprintf_s((char *)(Des + j), DesLen, "\n");
			isret = true;
		}
		if (isret)
		{
			++j;
			sprintf_s((char *)(Des + j), DesLen, "%02x ", *(Src + i));
			isret = false;
		}
		else
		{
			sprintf_s((char *)(Des + j), DesLen, "%02x ", *(Src + i));
		}
		
		j += 3;
	}
}
/************************************************************************/
/* 打印日志函数:
参数1:文件名(因为有时候会打印到不同的文件名)
参数2:打印地址
参数3:打印大小
参数4:打印格式(每隔多少回车)
参数5:打印模式(0:将LogAddr以16进制打印,1:将LogAddr以文本打印)*/
/************************************************************************/
void LogPrintf(char *FileName, void *logAddr, unsigned int logSize, int logFormat, int logMode)
{
	char buff[MAX_PATH];
	memset(buff, 0, MAX_PATH);
	FILE *pFile = NULL;
	int num = 0;
	switch (logMode)
	{
	case 0://将LogAddr以16进制打印
		fopen_s(&pFile,FileName, "ab+");
		fwrite(logAddr, logSize, 1, pFile);
		break;
	case 1://将LogAddr以文本打印
		fopen_s(&pFile, FileName, "a+");
		MyHex2Str((UCHAR *)buff,MAX_PATH,(UCHAR *)logAddr, logSize);
		//vsnprintf_s(buff, MAX_PATH, 0x10,"%02x", ()logAddr);
		num = fwrite(buff, 1, strlen(buff), pFile);
		fflush(pFile);
		num = fwrite("\n\n", 1 , strlen("\n\n"), pFile);
		fflush(pFile);
// 		if (logFormat % 0x33 == 0)
// 		{
// 			fwrite("\n", strlen("\n"), 1, pFile);
// 		}
		break;
	default:
		break;
	}
	fclose(pFile);
}

int WriteLog(char *fmt, ...)
{
	int n = 0;
	FILE *fp = NULL;
	va_list args = NULL;
	char sprint_buf[1024] = { 0 };
	_wfopen_s(&fp, L"C:\\MyLog\\DesData2.txt", L"a+");
	va_start(args, fmt);
	n = vfprintf(fp, fmt, args);
	va_end(args);
	fclose(fp);
	return n;
}

//通过文件映射加载文件
void * LoadFile(LPTSTR lpFilename)
{
	HANDLE hFile;
	HANDLE hMapping;
	void *ImageBase;

	hFile = CreateFile(lpFilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, 0);

	if (!hFile)
		return FALSE;

	hMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (!hMapping)
	{
		CloseHandle(hFile);
		return FALSE;
	}
	ImageBase = MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0);
	if (!ImageBase)
	{
		CloseHandle(hMapping);
		CloseHandle(hFile);
		return NULL;
	}

	return ImageBase;

}

void imgSave(BYTE* imgData, int width, int height, int stride, CString fileName, Gdiplus::PixelFormat pixelFormat = PixelFormat32bppARGB)
{
	CLSID Clsid;
	GetEncoderClsid(L"image/bmp", &Clsid);
	Gdiplus::Bitmap saveImg(width, height, stride, pixelFormat, imgData);
	saveImg.Save(fileName.AllocSysString(), &Clsid);
}
//************************************
// Method:    saveMask
// FullName:  saveMask
// Access:    public static 
// Returns:   void
// Qualifier: 保存单通道mask
// Parameter: BYTE * mask     //mask数据
// Parameter: int width       //mask宽，高
// Parameter: int height     
// Parameter: WCHAR * filePath //保存路径
//************************************
void saveMask(BYTE* mask, int width, int height, CString filePath)
{
	int size = width*height;
	BYTE* imgData = new BYTE[size * 4];

	BYTE* tmpImg = imgData;
	BYTE* tmpMask = mask;
	for (int i = 0; i < size; ++i, tmpImg += 4, ++tmpMask)
	{
		tmpImg[MT_ALPHA] = 255;
		tmpImg[MT_RED] = tmpImg[MT_GREEN] = tmpImg[MT_BLUE] = *tmpMask;
	}
	imgSave(imgData, width, height, width * 4, filePath);

	SAFE_DELETE_ARRAY(imgData);
}
void MySaveImage( BYTE *pbuff,CString strImgPath,DWORD nWidth,DWORD nHeight,bool isMask)
{
	if (isMask)
	{
		saveMask(pbuff, nWidth, nHeight, strImgPath);
	}
	else
	{
		imgSave(pbuff, nWidth, nHeight, nWidth * 4, strImgPath);
	}
	
	return;
}

#endif     //   FILEHANDLE_CPP 