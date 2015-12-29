
#ifndef   FILEHANDLE_H 
#define   FILEHANDLE_H

/************************************************************************/
/* ��ӡ��־����:
����1:�ļ���(��Ϊ��ʱ����ӡ����ͬ���ļ���)
����2:��ӡ��ַ
����3:��ӡ��С
����4:��ӡ��ʽ(ÿ�����ٻس�)
����5:��ӡģʽ(0:��LogAddr��16���ƴ�ӡ,1:��LogAddr���ı���ӡ)*/
/************************************************************************/
void LogPrintf(char *FileName, void *logAddr, unsigned int logSize, int logFormat, int logMode);

int WriteLog(char *fmt, ...);

/************************************************************************/
/* ����:�ڴ�ӳ�䷽ʽ�����ļ������ļ�����ָ��
   lpFilename: �ļ�·��*/
/************************************************************************/
void * LoadFile(LPTSTR lpFilename);


extern int  GetEncoderClsid(const TCHAR* format, CLSID* pClsid);

//
/************************************************************************/
/*  ����:��Buff����ʽ������image
    pBuff: Ҫ�����buff
	strImgPath: �����·����C:\\test.bmp
	nWidth:ͼƬ���
	nHeight:ͼƬ�߶�
	isMask:�Ƿ񱣴���ǵ�ͨ��*/
/************************************************************************/
void MySaveImage(BYTE *pbuff, CString strImgPath, DWORD nWidth, DWORD nHeight, bool isMask);
#endif FILEHANDLE_H