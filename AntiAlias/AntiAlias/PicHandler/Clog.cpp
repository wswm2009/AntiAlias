

#include "stdafx.h"
#include "Clog.h"

/*********************************************************************
* 函数名称:Clog()
* 说明:默认构造函数，带有默认值
* 调用者：在main之前声明为全局变量
* 输入参数:无
* 输出参数：无
* 返回值:无
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
*********************************************************************/
Clog::Clog(){
	SetLevel(0);
	SetAppName("app");
	SetLogRootPath("c:\\Mylog");
	SetLogWriteModel(1);
}


/*********************************************************************
* 函数名称:Clog(char* rootPath,char* appName,int level,int writeModel)
* 说明:带参构造函数
* 调用者：在main之前声明为全局变量，输入参数
* 输入参数:
*char *rootPath 日志文件保存位置
*char *appName  应用程序名称，用来做日志文件前缀
*int levle		日志类型:4种:DEBUG(0)/INFO(1)/ERROR(2)/SYSTEM(3)
*int writeModel 日志写入模式，0表示分割写入，1表示写在一个文件里面
* 输出参数：无
* 返回值:无
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
*********************************************************************/
Clog::Clog(TCHAR* rootPath, TCHAR* appName, LOGTYPE level, WRTMOD writeModel){
	SetLogRootPath(rootPath);
	SetAppName(appName);
	SetLevel(level);
	SetLogWriteModel(writeModel);
}
/*********************************************************************
* 函数名称:void Clog::memory(char * pstrFmt, ...)
* 说明:日志调试模式函数，支持变长参数
* 调用者：任何需要写日志的地方
* 输入参数:
* char *pstrFmt  --  日志内容
* ...            --  变长参数
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
* 函数名称:void Clog::debug(char * pstrFmt, ...)
* 说明:日志调试模式函数，支持变长参数
* 调用者：任何需要写日志的地方
* 输入参数:
* char *pstrFmt  --  日志内容
* ...            --  变长参数
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
* 函数名称:void Clog::info(char * pstrFmt, ...)
* 说明:日志正常模式函数，支持变长参数
* 调用者：任何需要写日志的地方
* 输入参数:
* char *pstrFmt  --  日志内容
* ...            --  变长参数
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
* 函数名称:void Clog::error(char * pstrFmt, ...)
* 说明:日志异常模式函数，支持变长参数
* 调用者：任何需要写日志的地方
* 输入参数:
* char *pstrFmt  --  日志内容
* ...            --  变长参数
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
* 函数名称:void Clog::system(char * pstrFmt, ...)
* 说明:日志系统模式函数，支持变长参数
* 调用者：任何需要写日志的地方
* 输入参数:
* char *pstrFmt  --  日志内容
* ...            --  变长参数
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
* 函数名称:void SetLogRootPath(char * pStrPath0)
* 说明:设置日志文件路径函数
* 调用者：任何需要写日志的地方
* 输入参数:
* char *pStrPath0  --  日志文件路径
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
*********************************************************************/
void Clog::SetLogRootPath(TCHAR * pStrPath0){
	gLogRootPath = pStrPath0;
}


/*********************************************************************
* 函数名称:void SetAppName(char* appName0)
* 说明:设置应用程序名称函数
* 调用者：任何需要写日志的地方
* 输入参数:
* char *appName0  --  应用程序名称
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
*********************************************************************/
void Clog::SetAppName(TCHAR* appName0){
	gszAppName = appName0;
}


/*********************************************************************
* 函数名称:void SetLogWriteModel(int model)
* 说明:设置日志写入模式函数
* 调用者：任何需要写日志的地方
* 输入参数:
* int model  --  模式，0表示多文件分割模式，1表示单文件汇总模式
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
*********************************************************************/
void Clog::SetLogWriteModel(int model){
	gLogWrtMod = model;
}


/*********************************************************************
* 函数名称:void SetLevel(int level0)
* 说明:设置日志级别函数
* 调用者：任何需要写日志的地方
* 输入参数:
* int level0  --  级别 DEBUG(0)/INFO(1)/ERROR(2)/SYSTEM(3)
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
*********************************************************************/
void Clog::SetLevel(int level0){
	glevel = level0;
}


/*********************************************************************
* 函数名称:void Write_Log(unsigned int uiLogType, char *pstrFmt, ...)
* 说明:日志写函数，支持变长参数
* 调用者：任何需要写日志的地方
* 输入参数:
* unsigned iType --  日志类别
* char *pstrFmt  --  日志内容
* ...            --  变长参数
* 输出参数：
* 无
* 返回值:
* void  --
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
*********************************************************************/
void Clog::Write_Log(unsigned int uiLogType, TCHAR *pstrFmt)
{
#if _LOG_WRITE_SWITCH_   /* 写日志与否的编译开关*/
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
	if (LOG_TYPE_MEMORY!=uiLogType)  //当日志类型为打印内存  就不需要加当前时间
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
* 函数名称:int  GetLogPath(char *pStrPath)
* 说明:获取日志文件路径
* 调用者：Write_Log_Text
* 输入参数:
* 无
* 输出参数：
* char *pStrPath
* 返回值:
* int  -- LOG_FAILED:  失败
*      -- LOG_SUCCESS: 成功
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
    /* 根据日期组成文件夹名称*/
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
* 函数名称:int GetLogFileName(int iLogType, const char *pStrPath, char *pStrName)
* 说明:获取日志文件名
* 调用者：Write_Log_Text
* 输入参数:
* int iLogType         -- 日志类型 3种:INFO(0)/ERROR(1)/SYSTEM(2)
* const char *pStrPath -- 日志路径 由GetLogPath得到
* 输出参数：
* char *pStrName       -- 日志文件名
* 返回值:
* int  -- LOG_FAILED:  失败
*      -- LOG_SUCCESS: 成功
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
		/* 如果文件长度大于指定的最大长度，重新创建一文件，覆盖原文件*/
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
* 函数名称:int Create_LogDir(const char *pStrPath)
* 说明:创建日志存放路径
* 调用者：GetLogPath
* 输入参数:
* const char *pStrPath --用户指定的根路径
* 输出参数：
* 无
* 返回值:
* int  -- LOG_FAILED:  失败
*      -- LOG_SUCCESS: 成功
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
	
	/* 逐层创建目录*/
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
* 函数名称:int Create_LogFile(const char *pStrFile, int iPos)
* 说明:创建日志文件
* 调用者：GetLogFileName
* 输入参数:
* const char *pStrFile --文件名
* int iPos             --文件指针位置
* 输出参数：
* 无
* 返回值:
* int  -- LOG_FAILED:  失败
*      -- LOG_SUCCESS: 成功
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
* 函数名称:int IsFileExist(const char *pStrFile)
* 说明:判断指定的文件是否存在
* 调用者：GetLogFileName
* 输入参数:
* const char *pStrFile --文件名
* 输出参数：
* 无
* 返回值:
* int  -- LOG_BOOL_FALSE:  不存在
*      -- LOG_BOOL_TRUE: 存在
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
* 函数名称:DWORD GetFileLenth(const char *pFile)
* 说明:判断指定的文件大小
* 调用者：GetLogFileName
* 输入参数:
* const char *pFile --文件名
* 输出参数：
* 无
* 返回值:
* DWORD -- 文件大小
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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
* 函数名称:int Write_Log_Text(LPLOG_DATA lpLogData)
* 说明:写日志内容
* 调用者：Write_Log
* 输入参数:
* LPLOG_DATA lpLogData --日志内容结构体量
* 输出参数：
* 无
* 返回值:
* int  -- LOG_FAILED:  失败
*      -- LOG_SUCCESS: 成功
* 作者: wswm2009@163.com
* 时间: 2015年12月18日
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