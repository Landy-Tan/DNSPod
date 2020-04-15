
#include "pch.h"

__DNSPOD_BEGIN

 Log& Log::GetInstance()  
 {  
     static Log log;  
     return log;  
 }  
 
 bool Log::AddLog(const char* pszLevel,
                  const char* pszFile,
                  int lineNo,
                  const char* pszFuncSig,
                  const char* pszFmt, ...)  
 {  
     if (m_file == NULL)  
         return false;  
 
     char tmp[8192*10] = { 0 };  
     va_list va;
           //定义一个va_list型的变量,这个变量是指向参数的指针.  
     va_start(va, pszFmt);
           //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参数,是一个固定的参数  
     sprintf(tmp, pszFmt, va);
           //注意,不要漏掉前面的_  
     va_end(va);  
 
     time_t now = time(NULL);  
     struct tm* tmstr = localtime(&now);  
     char content[8192 * 10 + 256] = {0};  
     sprintf(content, 
                "[%04d-%02d-%02d %02d:%02d:%02d][%s][0x%04x][%s:%d %s]%s\r\n",  
                 tmstr->tm_year + 1900,  
                 tmstr->tm_mon + 1,  
                 tmstr->tm_mday,  
                 tmstr->tm_hour,  
                 tmstr->tm_min,  
                 tmstr->tm_sec,  
                 pszLevel,  
                 //GetCurrentThreadId(),  
                 std::this_thread::get_id(),
                 pszFile,  
                 lineNo,  
                 pszFuncSig,  
                 tmp);  
 
#ifdef _DEBUG
	 std::cout << content;
#endif // _DEBUG


     if (fwrite(content, strlen(content), 1, m_file) != 1)  
         return false;  
 
    fflush(m_file);  

    return true;  
}  

Log::Log()  
{  
    time_t now = time(NULL);  
    struct tm* tmstr = localtime(&now);  
    char filename[256];  
   sprintf(filename, 
                     "%04d%02d%02d%02d%02d%02d.runlog",   
                tmstr->tm_year + 1900,   
                tmstr->tm_mon + 1,   
                tmstr->tm_mday,   
                tmstr->tm_hour,   
                tmstr->tm_min,   
                tmstr->tm_sec);  

    m_file = fopen(filename, "at+");  
	if(m_file)printf("打开文件成功\n");
	else printf("打开文件失败\n");
}  

Log::~Log()  
{  
    if (m_file != NULL)  
        fclose(m_file);  
} 

__DNSPOD_END