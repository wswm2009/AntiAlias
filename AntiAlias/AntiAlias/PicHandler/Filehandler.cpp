
#include "StdAfx.h"
#ifndef   FILEHANDLE_CPP 
#define   FILEHANDLE_CPP 

#include "Filehandler.h"

//���ڴ������00 11 22 33 44 ת�ɡ�00 11 22 33 44��buff
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
/* ��ӡ��־����:
����1:�ļ���(��Ϊ��ʱ����ӡ����ͬ���ļ���)
����2:��ӡ��ַ
����3:��ӡ��С
����4:��ӡ��ʽ(ÿ�����ٻس�)
����5:��ӡģʽ(0:��LogAddr��16���ƴ�ӡ,1:��LogAddr���ı���ӡ)*/
/************************************************************************/
void LogPrintf(char *FileName, void *logAddr, unsigned int logSize, int logFormat, int logMode)
{
	char buff[MAX_PATH];
	memset(buff, 0, MAX_PATH);
	FILE *pFile = NULL;
	int num = 0;
	switch (logMode)
	{
	case 0://��LogAddr��16���ƴ�ӡ
		fopen_s(&pFile,FileName, "wb");
		fwrite(logAddr, logSize, 1, pFile);
		break;
	case 1://��LogAddr���ı���ӡ
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