/************************************************************************/
/*
  * 文件名称：CLog.cpp
  * 摘    要：此文件实现了普通WINDOWS程序中的日志功能
  *           主要有以下特点：
  *           1. 根据日期创建日志文件目录，每天的日志分别存放在不同的日志目录中；
  *           2. 日志内容分三种类型，根据不同需要，写不同的日志类型的日志文件，
  *              方便通过日志定位、分析问题；
和 "简单的分级别写日志程序" 有关的　c#、asp.net、c++　编程小帖士：
strong>FileDateTime(pathname)
传回档案建立时的日期、时间。
  *           3. 函数经过比较好的封装，便于复用；
  *           待改进点：
  *           1. 为了方便，日志内容打印时使用了time函数，其精确度较低；
  *           2. 可将这些函数封装为一个日志类，或者动态库，使其更通用；
  *           3. 没有考虑跨平台情景，目前只使用于WINDOWS下 
*           4. 日志文件内容还可进一步改进，比如打印出当前文件名与行号，使用日志功能
*              更加实用；
  *
  * 当前版本：1.0
  * 作    者：duanyongxing
  * 完成日期：2009年10月11日
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
#define _LOG_WRITE_SWITCH_ 1            /* 条件编译开关，1：写日志，0：不写日志 */
#define LOG_SUCCESS (0)
#define LOG_FAILED  (-1)
#define LOG_BOOL_TRUE (1)
#define LOG_BOOL_FALSE (0)
#define DWORD_NULL  (0xFFFFFFFF)
#define MAX_LOGTEXT_LEN (2048)         /* 每行日志的最大长度*/
#define MAX_FILE_PATH (255)            /* 日志文件路径的最大长度*/
#define MAX_LOG_FILE_SIZE (512 * 1024) /* 日志文件内容的最大长度*/
#define MAX_LOG_FILE_NAME_LEN (256)    /* 日志文件名的最大长度*/

#define LOG_TYPE_DEBUG   0			   /* 日志类别: 调试类型*/
#define LOG_TYPE_INFO    1             /* 日志类型: 信息类型*/
#define LOG_TYPE_ERROR   2             /* 日志类型: 错误类型*/
#define LOG_TYPE_SYSTEM  3             /* 日志类型: 系统类型*/
#define LOG_TYPE_MEMORY  4             /* 日志类型: 内存类型*/

#define TEST_CASE_MAX_FILE_LEN (1024)  /* 测试函数中文件内容最大长度*/


#define WRITE_MODEL_INSLIPTFILE  0          /* 日志写入类型: 分割写入不同的文件*/
#define WRITE_MODEL_INALLFILE    1          /* 日志写入类型: 写在一个文件里面*/


//自定义新类型
typedef int WRTMOD;   //  写入类型
typedef int LOGTYPE;   // 日志类别

static TCHAR *gLogRootPath;	   /*日志文件根路径，由用户指定*/
static TCHAR *gszAppName;		   /* 应用程序名称，由用户指定*/
static unsigned int gLogWrtMod; /* 日志写入模式，0表示分割写入，1表示写在一个文件里面*/
static unsigned int glevel;			 /* 日志级别,默认是INFO模式 */

#pragma pack(push, 1)
typedef struct tagLOG_DATA             /* 日志内容结构体*/
{
	TCHAR             strDate[11];		   /* 日期:格式为如:2012-09-01*/
	TCHAR             strTime[9];         /* 时间:格式为如:16:10:57*/
    unsigned int	  iType;               /* 日志类型:4种:DEBUG(0)/INFO(1)/ERROR(2)/SYSTEM(3)*/
	TCHAR             strFileMode[5];      /*日志输入到文件类型: ASCII/HEX/等等*/
    TCHAR             strText[MAX_LOGTEXT_LEN]; /*日志内容*/
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

	void memory(TCHAR *pstrFmt, ...);
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
	void Write_Log(unsigned int uiLogType, TCHAR *pstrFmt);

	//字符转换
	BOOL UnicodeToANSI(const TCHAR* SrcStr, TCHAR * DesStr);

};




#endif