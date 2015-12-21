

#include "stdafx.h"
#include "Clog.h"

/*********************************************************************
* ��������:Clog()
* ˵��:Ĭ�Ϲ��캯��������Ĭ��ֵ
* �����ߣ���main֮ǰ����Ϊȫ�ֱ���
* �������:��
* �����������
* ����ֵ:��
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
Clog::Clog(){
	SetLevel(0);
	SetAppName("app");
	SetLogRootPath("c:\\Mylog");
	SetLogWriteModel(1);
}


/*********************************************************************
* ��������:Clog(char* rootPath,char* appName,int level,int writeModel)
* ˵��:���ι��캯��
* �����ߣ���main֮ǰ����Ϊȫ�ֱ������������
* �������:
*char *rootPath ��־�ļ�����λ��
*char *appName  Ӧ�ó������ƣ���������־�ļ�ǰ׺
*int levle		��־����:4��:DEBUG(0)/INFO(1)/ERROR(2)/SYSTEM(3)
*int writeModel ��־д��ģʽ��0��ʾ�ָ�д�룬1��ʾд��һ���ļ�����
* �����������
* ����ֵ:��
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
Clog::Clog(TCHAR* rootPath, TCHAR* appName, LOGTYPE level, WRTMOD writeModel){
	SetLogRootPath(rootPath);
	SetAppName(appName);
	SetLevel(level);
	SetLogWriteModel(writeModel);
}
/*********************************************************************
* ��������:void Clog::memory(char * pstrFmt, ...)
* ˵��:��־����ģʽ������֧�ֱ䳤����
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* char *pstrFmt  --  ��־����
* ...            --  �䳤����
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::memory(TCHAR * pstrFmt, ...){
	if (glevel <= 0)
	{
		va_list v1;
		TCHAR strText[MAX_LOGTEXT_LEN];
		va_start(v1, pstrFmt);
#ifdef _UNICODE
		vswprintf_s(strText, pstrFmt, v1);
#else
		_vsnprintf_s(strText, MAX_LOGTEXT_LEN, pstrFmt, v1);
#endif
		va_end(v1);
		Write_Log(LOG_TYPE_MEMORY, strText);
	}
	else{
		return;
	}

}

/*********************************************************************
* ��������:void Clog::debug(char * pstrFmt, ...)
* ˵��:��־����ģʽ������֧�ֱ䳤����
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* char *pstrFmt  --  ��־����
* ...            --  �䳤����
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::debug(TCHAR * pstrFmt, ...){
	if (glevel <= 0)
	{
		va_list v1;
		TCHAR strText[MAX_LOGTEXT_LEN];

		//Write formatted output using a pointer to a list of arguments.
		//int _vsnprintf( char *buffer, size_t count, const char *format, va_list argptr );
		va_start(v1, pstrFmt);
#ifdef _UNICODE
		 vswprintf_s(strText,pstrFmt, v1);
#else
		_vsnprintf_s(strText, MAX_LOGTEXT_LEN, pstrFmt, v1);
#endif
		va_end(v1);
		Write_Log(LOG_TYPE_DEBUG,strText);
	}else{
		return ;
	}
	
}



/*********************************************************************
* ��������:void Clog::info(char * pstrFmt, ...)
* ˵��:��־����ģʽ������֧�ֱ䳤����
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* char *pstrFmt  --  ��־����
* ...            --  �䳤����
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::info(TCHAR * pstrFmt,...){
	if (glevel <= 1)
	{
		va_list v1;
		TCHAR strText[MAX_LOGTEXT_LEN];
		va_start(v1, pstrFmt);
#ifdef _UNICODE
		vswprintf_s(strText, pstrFmt, v1);
#else
		_vsnprintf_s(strText, MAX_LOGTEXT_LEN, pstrFmt, v1);
#endif
		va_end(v1);
		Write_Log(LOG_TYPE_INFO,pstrFmt);
	}else{
		return ;
	}
}



/*********************************************************************
* ��������:void Clog::error(char * pstrFmt, ...)
* ˵��:��־�쳣ģʽ������֧�ֱ䳤����
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* char *pstrFmt  --  ��־����
* ...            --  �䳤����
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::error(TCHAR * pstrFmt,...){
	if (glevel <= 2)
	{
		va_list v1;
		TCHAR strText[MAX_LOGTEXT_LEN];
		va_start(v1, pstrFmt);
#ifdef _UNICODE
		vswprintf_s(strText, pstrFmt, v1);
#else
		_vsnprintf_s(strText, MAX_LOGTEXT_LEN, pstrFmt, v1);
#endif
		va_end(v1);
		Write_Log(LOG_TYPE_ERROR,pstrFmt);
	}else{
		return ;
	}
}


/*********************************************************************
* ��������:void Clog::system(char * pstrFmt, ...)
* ˵��:��־ϵͳģʽ������֧�ֱ䳤����
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* char *pstrFmt  --  ��־����
* ...            --  �䳤����
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::system(TCHAR * pstrFmt,...){
	if (glevel <= 3)
	{
		va_list v1;
		TCHAR strText[MAX_LOGTEXT_LEN];
		va_start(v1, pstrFmt);
#ifdef _UNICODE
		vswprintf_s(strText, pstrFmt, v1);
#else
		_vsnprintf_s(strText, MAX_LOGTEXT_LEN, pstrFmt, v1);
#endif
		va_end(v1);
		Write_Log(LOG_TYPE_SYSTEM,pstrFmt);
	}else{
		return ;
	}
}


/*********************************************************************
* ��������:void SetLogRootPath(char * pStrPath0)
* ˵��:������־�ļ�·������
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* char *pStrPath0  --  ��־�ļ�·��
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::SetLogRootPath(TCHAR * pStrPath0){
	gLogRootPath = pStrPath0;
}


/*********************************************************************
* ��������:void SetAppName(char* appName0)
* ˵��:����Ӧ�ó������ƺ���
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* char *appName0  --  Ӧ�ó�������
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::SetAppName(TCHAR* appName0){
	gszAppName = appName0;
}


/*********************************************************************
* ��������:void SetLogWriteModel(int model)
* ˵��:������־д��ģʽ����
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* int model  --  ģʽ��0��ʾ���ļ��ָ�ģʽ��1��ʾ���ļ�����ģʽ
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::SetLogWriteModel(int model){
	gLogWrtMod = model;
}


/*********************************************************************
* ��������:void SetLevel(int level0)
* ˵��:������־������
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* int level0  --  ���� DEBUG(0)/INFO(1)/ERROR(2)/SYSTEM(3)
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::SetLevel(int level0){
	glevel = level0;
}


/*********************************************************************
* ��������:void Write_Log(unsigned int uiLogType, char *pstrFmt, ...)
* ˵��:��־д������֧�ֱ䳤����
* �����ߣ��κ���Ҫд��־�ĵط�
* �������:
* unsigned iType --  ��־���
* char *pstrFmt  --  ��־����
* ...            --  �䳤����
* ���������
* ��
* ����ֵ:
* void  --
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
void Clog::Write_Log(unsigned int uiLogType, TCHAR *pstrFmt)
{
#if _LOG_WRITE_SWITCH_   /* д��־���ı��뿪��*/
	LOG_DATA data ;
	time_t curTime;

#ifdef _UNICODE
	struct tm mt;
#else
	struct tm *mt=NULL;
#endif
	
	memset(&data, 0, sizeof(LOG_DATA));

	_snprintf_s(data.strText, MAX_LOGTEXT_LEN, pstrFmt);

	data.iType = uiLogType;
	if (LOG_TYPE_MEMORY!=uiLogType)  //����־����Ϊ��ӡ�ڴ�  �Ͳ���Ҫ�ӵ�ǰʱ��
	{
		curTime = time(NULL);
		localtime_s(mt, &curTime);
#ifdef _UNICODE
		wcsftime(data.strDate, sizeof(data.strDate), L"%Y-%m-%d", &mt);
		wcsftime(data.strTime, sizeof(data.strTime), L"%H:%M:%S", &mt);
#else
		strftime(data.strDate, sizeof(data.strDate), "%Y-%m-%d", mt);
		strftime(data.strTime, sizeof(data.strTime), "%H:%M:%S", mt);
#endif // _UNICODE
	}


	Write_Log_Text(&data);
	
#endif _LOG_WRITE_SWITCH_
}


/*********************************************************************
* ��������:int  GetLogPath(char *pStrPath)
* ˵��:��ȡ��־�ļ�·��
* �����ߣ�Write_Log_Text
* �������:
* ��
* ���������
* char *pStrPath
* ����ֵ:
* int  -- LOG_FAILED:  ʧ��
*      -- LOG_SUCCESS: �ɹ�
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
int  Clog::GetLogPath(TCHAR *pStrPath)
{
	if(NULL == pStrPath)
	{
		return LOG_FAILED;
	}
    int iRet = 0;
	time_t curTime = time(NULL);
	struct tm *mt=new struct tm;
	localtime_s(mt,&curTime);
    /* ������������ļ�������*/
#ifdef _UNICODE
	swprintf_s(pStrPath, MAX_FILE_PATH, L"%s\\%d%02d%02d", gLogRootPath, mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);
#else
	sprintf_s(pStrPath, MAX_FILE_PATH, "%s\\%d%02d%02d", gLogRootPath, mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday);
#endif
	
    iRet = Create_LogDir(pStrPath);

	delete[] mt;
	return iRet;
}


/*********************************************************************
* ��������:int GetLogFileName(int iLogType, const char *pStrPath, char *pStrName)
* ˵��:��ȡ��־�ļ���
* �����ߣ�Write_Log_Text
* �������:
* int iLogType         -- ��־���� 3��:INFO(0)/ERROR(1)/SYSTEM(2)
* const char *pStrPath -- ��־·�� ��GetLogPath�õ�
* ���������
* char *pStrName       -- ��־�ļ���
* ����ֵ:
* int  -- LOG_FAILED:  ʧ��
*      -- LOG_SUCCESS: �ɹ�
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
int Clog::GetLogFileName(int iLogType, const TCHAR *pStrPath, TCHAR *pStrName)
{
	if(NULL == pStrPath)
	{
		return LOG_FAILED;
	}
	
	
	TCHAR szLogName[MAX_FILE_PATH];
	FILE *pFile = NULL;
	memset(szLogName, 0, MAX_FILE_PATH);
	
	if(gLogWrtMod){
#ifdef _UNICODE
		swprintf_s(szLogName, L"%s\\%s", pStrPath, gszAppName);
#else
		sprintf_s(szLogName, MAX_FILE_PATH, "%s\\%s", pStrPath, gszAppName);
#endif
		
		goto __BRK;
	}
	
	switch (iLogType)
	{
	case LOG_TYPE_DEBUG:
#ifdef _UNICODE
		swprintf_s(szLogName, L"%s\\%s_debug", pStrPath, gszAppName);
#else
		sprintf_s(szLogName, MAX_FILE_PATH,"%s\\%s_debug", pStrPath, gszAppName);
#endif	
		break;
	case LOG_TYPE_INFO:
#ifdef _UNICODE
		swprintf_s(szLogName, L"%s\\%s_info", pStrPath, gszAppName);
#else
		sprintf_s(szLogName, MAX_FILE_PATH,  "%s\\%s_info", pStrPath, gszAppName);
#endif
		break;
	case LOG_TYPE_ERROR:
#ifdef _UNICODE
		swprintf_s(szLogName, L"%s\\%s_error", pStrPath, gszAppName);
#else
		sprintf_s(szLogName, MAX_FILE_PATH, "%s\\%s_error", pStrPath, gszAppName);
#endif
		break;
	case LOG_TYPE_SYSTEM:
#ifdef _UNICODE
		swprintf_s(szLogName, L"%s\\%s_system", pStrPath, gszAppName);
#else
		sprintf_s(szLogName, MAX_FILE_PATH, "%s\\%s_system", pStrPath, gszAppName);
#endif
		break;
	default:
		return LOG_FAILED;
		break;
	}
	
__BRK:
#ifdef _UNICODE
	wcscat_s(szLogName, L".log");
#else
	strcat_s(szLogName, ".log");
#endif
	if(IsFileExist(szLogName))
	{
		/* ����ļ����ȴ���ָ������󳤶ȣ����´���һ�ļ�������ԭ�ļ�*/
        if((int)GetFileLenth(szLogName) + 256 >= MAX_LOG_FILE_SIZE)
		{
			Create_LogFile(szLogName, 0);
		}
	}
	else
	{
		Create_LogFile(szLogName, 0);
	}
#ifdef _UNICODE
	swprintf_s(pStrName,MAX_FILE_PATH, L"%s", szLogName);
#else
	sprintf_s(pStrName, MAX_FILE_PATH, "%s", szLogName);
#endif
	return LOG_SUCCESS;
}


/*********************************************************************
* ��������:int Create_LogDir(const char *pStrPath)
* ˵��:������־���·��
* �����ߣ�GetLogPath
* �������:
* const char *pStrPath --�û�ָ���ĸ�·��
* ���������
* ��
* ����ֵ:
* int  -- LOG_FAILED:  ʧ��
*      -- LOG_SUCCESS: �ɹ�
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
int Clog::Create_LogDir(const TCHAR *pStrPath)
{
	if(NULL == pStrPath)
	{
		return LOG_FAILED;
	}
	int iRet = 0;
	TCHAR szSub[MAX_FILE_PATH];
	TCHAR *pSub = NULL;
	int iIndex = 0;
	int iLen = 0;
	int bFind = 0;
	DWORD dwNum = 0;
	memset(szSub, 0, sizeof(MAX_FILE_PATH));
	
	/* ��㴴��Ŀ¼*/
	while(1)
	{
#ifdef _UNICODE
		pSub = (TCHAR *)wcschr(pStrPath + iLen, L'\\');
#else
		pSub = (TCHAR *)strchr(pStrPath + iLen, '\\');
#endif
		
		if(NULL == pSub)
		{
			if(iLen == 0)
			{
				return LOG_FAILED;
			}
			iRet = CreateDirectory(pStrPath, NULL);
			if(0 == iRet)
			{
				iRet = GetLastError();
				if(ERROR_ALREADY_EXISTS == iRet)
				{
					return LOG_SUCCESS;
				}
				return LOG_FAILED;
			}
			return LOG_SUCCESS;
		}
		else
		{
			if (!bFind)
			{
				bFind = 1;
			}
			else
			{
				memset(szSub, 0, sizeof(szSub));
#ifdef _UNICODE
				wcsncpy_s(szSub, pStrPath, pSub - pStrPath);
#else
				strncpy_s(szSub, pStrPath, pSub - pStrPath);
#endif		
				CreateDirectory(szSub, NULL);
			}
			iLen = pSub - pStrPath + 1;
		}
	}
	return LOG_SUCCESS;
}


/*********************************************************************
* ��������:int Create_LogFile(const char *pStrFile, int iPos)
* ˵��:������־�ļ�
* �����ߣ�GetLogFileName
* �������:
* const char *pStrFile --�ļ���
* int iPos             --�ļ�ָ��λ��
* ���������
* ��
* ����ֵ:
* int  -- LOG_FAILED:  ʧ��
*      -- LOG_SUCCESS: �ɹ�
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
int Clog::Create_LogFile(const TCHAR *pStrFile, int iPos)
{
	HANDLE hd = 0;
	int iRet = 0;
	if(NULL == pStrFile)
	{
		return LOG_FAILED;
	}
	hd = CreateFile(pStrFile,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
		);
	if(INVALID_HANDLE_VALUE == hd)
	{
		return LOG_FAILED;
	}
    if(DWORD_NULL == SetFilePointer(hd, iPos, NULL, FILE_BEGIN))
	{
		return LOG_FAILED;
	}
	iRet = SetEndOfFile(hd);
	CloseHandle(hd);
	return iRet;
}


/*********************************************************************
* ��������:int IsFileExist(const char *pStrFile)
* ˵��:�ж�ָ�����ļ��Ƿ����
* �����ߣ�GetLogFileName
* �������:
* const char *pStrFile --�ļ���
* ���������
* ��
* ����ֵ:
* int  -- LOG_BOOL_FALSE:  ������
*      -- LOG_BOOL_TRUE: ����
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
int Clog::IsFileExist(const TCHAR *pStrFile)
{
	int iLen = 0;
	WIN32_FIND_DATA finddata;
	memset(&finddata, 0, sizeof(WIN32_FIND_DATA));
	HANDLE hd = FindFirstFile(pStrFile, &finddata);
	if(INVALID_HANDLE_VALUE == hd)
	{
		DWORD dwRet = GetLastError();
		if(ERROR_FILE_NOT_FOUND == dwRet || ERROR_PATH_NOT_FOUND == dwRet)
		{
			return LOG_BOOL_FALSE;
		}
	}
	FindClose(hd);
	return LOG_BOOL_TRUE;
}


/*********************************************************************
* ��������:DWORD GetFileLenth(const char *pFile)
* ˵��:�ж�ָ�����ļ���С
* �����ߣ�GetLogFileName
* �������:
* const char *pFile --�ļ���
* ���������
* ��
* ����ֵ:
* DWORD -- �ļ���С
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
DWORD Clog::GetFileLenth(const TCHAR *pFile)
{
	WIN32_FIND_DATA buff;
	HANDLE hd = NULL;
	memset(&buff, 0, sizeof(WIN32_FIND_DATA));
	hd = FindFirstFile(pFile, &buff);
	FindClose(hd);
	return (buff.nFileSizeHigh * MAXDWORD) + buff.nFileSizeLow;
}


/*********************************************************************
* ��������:int Write_Log_Text(LPLOG_DATA lpLogData)
* ˵��:д��־����
* �����ߣ�Write_Log
* �������:
* LPLOG_DATA lpLogData --��־���ݽṹ����
* ���������
* ��
* ����ֵ:
* int  -- LOG_FAILED:  ʧ��
*      -- LOG_SUCCESS: �ɹ�
* ����: wswm2009@163.com
* ʱ��: 2015��12��18��
*********************************************************************/
int Clog::Write_Log_Text(LPLOG_DATA lpLogData)
{
    TCHAR szFilePath[MAX_FILE_PATH];
	TCHAR szFileName[MAX_LOG_FILE_NAME_LEN];
	FILE *pFile = NULL;
	TCHAR szLogText[MAX_LOGTEXT_LEN];
	TCHAR szDesLogText[MAX_LOGTEXT_LEN];
	DWORD dwLen = 0;
	memset(szFilePath, 0, MAX_FILE_PATH);
	memset(szFileName, 0, MAX_LOG_FILE_NAME_LEN);
	memset(szLogText, 0, MAX_LOGTEXT_LEN);
	memset(szDesLogText, 0, MAX_LOGTEXT_LEN);
	GetLogPath(szFilePath);
	GetLogFileName(lpLogData->iType, szFilePath, szFileName);



	
   
	
	if(gLogWrtMod)
	{
		TCHAR *logType;
		switch(lpLogData->iType)
		{
		case 0:
			logType = "DEBUG";
			wsprintf(lpLogData->strFileMode, "a+");
			break;
		case 1:
			wsprintf(lpLogData->strFileMode, "a+");
			logType = "INFO";
			break;
		case 2:
			wsprintf(lpLogData->strFileMode, "a+");
			logType ="ERROR";
			break;
		case 3:
			wsprintf(lpLogData->strFileMode, "a+");
			logType = "SYSTEM";
			break;
		case 4:
			logType = "MEMORY";
			wsprintf(lpLogData->strFileMode, "a+");
			wsprintf(szLogText, "%s", lpLogData->strText);
			goto LabelOpen;
			break;
		default:
			logType = "UNKNOW";
			
		}
		wsprintf(szLogText, "%s\t| %s %s | %s\n", logType, lpLogData->strDate, lpLogData->strTime, lpLogData->strText);
		
	}else{
		wsprintf(szLogText, "%s %s | %s\n", lpLogData->strDate, lpLogData->strTime,lpLogData->strText);
		
	}
LabelOpen:
#ifdef _UNICODE
	_wfopen_s(&pFile, szFileName, lpLogData->strFileMode);
#else
	fopen_s(&pFile ,szFileName, lpLogData->strFileMode);
#endif

	if (NULL == pFile)
	{
		return LOG_FAILED;
	}
	
#ifdef _UNICODE
	UnicodeToANSI(szLogText, szDesLogText);
#else
	strcpy_s(szDesLogText,szLogText);
#endif
	dwLen = lstrlen(szDesLogText);
	fwrite(szDesLogText, sizeof(BYTE), dwLen, pFile);
	fclose(pFile);
	return LOG_SUCCESS;
}
BOOL Clog::UnicodeToANSI(const TCHAR* SrcStr,TCHAR * DesStr)
{
#ifdef _UNICODE
	int nLen = wcslen(SrcStr) + 1;
	WideCharToMultiByte(CP_ACP, 0, SrcStr, nLen, (LPSTR)DesStr, 2 * nLen, NULL, NULL);
#endif
	return TRUE;
}