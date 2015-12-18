
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
		fopen_s(&pFile,FileName, "wb");
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


#endif     //   FILEHANDLE_CPP 