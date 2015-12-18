/************************************************************************/
/*
  * �ļ����ƣ�CLog.cpp
  * ժ    Ҫ�����ļ�ʵ������ͨWINDOWS�����е���־����
  *           ��Ҫ�������ص㣺
  *           1. �������ڴ�����־�ļ�Ŀ¼��ÿ�����־�ֱ����ڲ�ͬ����־Ŀ¼�У�
  *           2. ��־���ݷ��������ͣ����ݲ�ͬ��Ҫ��д��ͬ����־���͵���־�ļ���
  *              ����ͨ����־��λ���������⣻
�� "�򵥵ķּ���д��־����" �йصġ�c#��asp.net��c++�����С��ʿ��
strong>FileDateTime(pathname)
���ص�������ʱ�����ڡ�ʱ�䡣
  *           3. ���������ȽϺõķ�װ�����ڸ��ã�
  *           ���Ľ��㣺
  *           1. Ϊ�˷��㣬��־���ݴ�ӡʱʹ����time�������侫ȷ�Ƚϵͣ�
  *           2. �ɽ���Щ������װΪһ����־�࣬���߶�̬�⣬ʹ���ͨ�ã�
  *           3. û�п��ǿ�ƽ̨�龰��Ŀǰֻʹ����WINDOWS�� 
*           4. ��־�ļ����ݻ��ɽ�һ���Ľ��������ӡ����ǰ�ļ������кţ�ʹ����־����
*              ����ʵ�ã�
  *
  * ��ǰ�汾��1.0
  * ��    �ߣ�duanyongxing
  * ������ڣ�2009��10��11��
*/                                                                    
/************************************************************************/
#ifndef __WRITELOG_H__
#define __WRITELOG_H__
//#include <iostream>
#include <time.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>
using namespace std;
#define _LOG_WRITE_SWITCH_ 1            /* �������뿪�أ�1��д��־��0����д��־ */
#define LOG_SUCCESS (0)
#define LOG_FAILED  (-1)
#define LOG_BOOL_TRUE (1)
#define LOG_BOOL_FALSE (0)
#define DWORD_NULL  (0xFFFFFFFF)
#define MAX_LOGTEXT_LEN (2048)         /* ÿ����־����󳤶�*/
#define MAX_FILE_PATH (255)            /* ��־�ļ�·������󳤶�*/
#define MAX_LOG_FILE_SIZE (512 * 1024) /* ��־�ļ����ݵ���󳤶�*/
#define MAX_LOG_FILE_NAME_LEN (256)    /* ��־�ļ�������󳤶�*/

#define LOG_TYPE_DEBUG   0			   /* ��־���: ��������*/
#define LOG_TYPE_INFO    1             /* ��־����: ��Ϣ����*/
#define LOG_TYPE_ERROR   2             /* ��־����: ��������*/
#define LOG_TYPE_SYSTEM  3             /* ��־����: ϵͳ����*/
#define TEST_CASE_MAX_FILE_LEN (1024)  /* ���Ժ������ļ�������󳤶�*/


#define WRITE_MODEL_INSLIPTFILE  0          /* ��־д������: �ָ�д�벻ͬ���ļ�*/
#define WRITE_MODEL_INALLFILE    1          /* ��־д������: д��һ���ļ�����*/


//�Զ���������
typedef int WRTMOD;   //  д������
typedef int LOGTYPE;   // ��־���

static TCHAR *gLogRootPath;	   /*��־�ļ���·�������û�ָ��*/
static TCHAR *gszAppName;		   /* Ӧ�ó������ƣ����û�ָ��*/
static unsigned int gLogWrtMod; /* ��־д��ģʽ��0��ʾ�ָ�д�룬1��ʾд��һ���ļ�����*/
static unsigned int glevel;			 /* ��־����,Ĭ����INFOģʽ */

#pragma pack(push, 1)
typedef struct tagLOG_DATA             /* ��־���ݽṹ��*/
{
	TCHAR             strDate[11];		   /* ����:��ʽΪ��:2012-09-01*/
	TCHAR             strTime[9];         /* ʱ��:��ʽΪ��:16:10:57*/
    unsigned int	  iType;               /* ��־����:4��:DEBUG(0)/INFO(1)/ERROR(2)/SYSTEM(3)*/
    TCHAR             strText[MAX_LOGTEXT_LEN]; /*��־����*/
}LOG_DATA, *LPLOG_DATA;
#pragma pack(pop)
class Clog
{
public:
	Clog();
	Clog(TCHAR *rootPath, TCHAR* appName, LOGTYPE level, WRTMOD writeModel);
//	~Clog();
	void debug(TCHAR* pstrFmt, ...);
	void info(TCHAR* pstrFmt, ...);
	void error(TCHAR* pstrFmt, ...);
	void system(TCHAR* pstrFmt, ...);

	void SetAppName(TCHAR* appName0);
	void SetLogRootPath(TCHAR * pStrPath0);
	void SetLogWriteModel(int model);
	void SetLevel(int level0);

protected:
private:
	int GetLogFileName(int iLogType, const TCHAR *pStrPath, TCHAR *pStrName);
	int Create_LogDir(const TCHAR *pStrPath);
	int Create_LogFile(const TCHAR *pStrFile, int iPos);
	int IsFileExist(const TCHAR *pStrFile);
	int GetLogPath(TCHAR *pStrPath);
	DWORD GetFileLenth(const TCHAR *pFile);
	int Write_Log_Text(LPLOG_DATA lpLogData);
	void Write_Log(unsigned int uiLogType, TCHAR *pstrFmt, ...);

	//�ַ�ת��
	BOOL UnicodeToANSI(const TCHAR* SrcStr, TCHAR * DesStr);

};
#endif