/**********************************************************************
 * File name:		Log.h
 * Author:			
 * Create date:		2020年3月30日
 * Description:		Log日志类（抄录自《高性能服务器研究》群主公众号
 * History:
 * <Date>			<Author>	<Description>
 **********************************************************************/

#ifndef __LOG_H__
#define __LOG_H__

#include "pch.h"

#ifndef _WIN32
#define __FUN __FUNCTION__
#else
#define __FUN __FUNCSIG__
#endif 

__DNSPOD_BEGIN

#define LogInfo(...)\
    Log::GetInstance().AddLog("INFO", __FILE__, __LINE__, __FUN, __VA_ARGS__)  
#define LogWarning(...)\
	Log::GetInstance().AddLog("WARNING", __FILE__, __LINE__, __FUN, __VA_ARGS__)  
#define LogError(...)\
	Log::GetInstance().AddLog("ERROR", __FILE__, __LINE__, __FUN, __VA_ARGS__)  

class Log  
{  
public:  
   static Log& GetInstance();  

    bool AddLog(const char* pszLevel,
                 const char* pszFile,
                int lineNo,
                const char* pszFuncSig,
                const char* pszFmt, ...);                                          
private:  
    Log();  
    ~Log();  
   Log(const Log&);  
    Log& operator=(const Log&);  

private:  
    FILE*   m_file;  
};  

__DNSPOD_END

#endif // __LOG_H__