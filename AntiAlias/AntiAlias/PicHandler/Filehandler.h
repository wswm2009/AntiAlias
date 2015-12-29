
#ifndef   FILEHANDLE_H 
#define   FILEHANDLE_H

/************************************************************************/
/* 打印日志函数:
参数1:文件名(因为有时候会打印到不同的文件名)
参数2:打印地址
参数3:打印大小
参数4:打印格式(每隔多少回车)
参数5:打印模式(0:将LogAddr以16进制打印,1:将LogAddr以文本打印)*/
/************************************************************************/
void LogPrintf(char *FileName, void *logAddr, unsigned int logSize, int logFormat, int logMode);

int WriteLog(char *fmt, ...);

/************************************************************************/
/* 功能:内存映射方式加载文件返回文件数据指针
   lpFilename: 文件路径*/
/************************************************************************/
void * LoadFile(LPTSTR lpFilename);


extern int  GetEncoderClsid(const TCHAR* format, CLSID* pClsid);

//
/************************************************************************/
/*  功能:以Buff的形式来保存image
    pBuff: 要保存的buff
	strImgPath: 保存的路径如C:\\test.bmp
	nWidth:图片宽度
	nHeight:图片高度
	isMask:是否保存的是单通道*/
/************************************************************************/
void MySaveImage(BYTE *pbuff, CString strImgPath, DWORD nWidth, DWORD nHeight, bool isMask);
#endif FILEHANDLE_H