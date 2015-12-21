
#ifndef   FILEHANDLE_H 
#define   FILEHANDLE_H

void LogPrintf(char *FileName, void *logAddr, unsigned int logSize, int logFormat, int logMode);
int WriteLog(char *fmt, ...);
#endif FILEHANDLE_H