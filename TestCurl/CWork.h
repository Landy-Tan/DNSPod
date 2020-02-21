#ifndef C_WORK_H
#define C_WORK_H

#include "CHttps.h"

class CWork
{
public:
    CWork(std::string _szID, 
        std::string _szPassword, 
        std::string _szRecordID,
        std::string _szDomain , 
        std::string _szSubDomain = "www", 
        std::string _szRocordType = "A", 
        std::string _szRecordLineID = "0");
    virtual ~CWork();
    bool Run();

protected:
    virtual bool GetIpAddress();
    virtual bool GetUserInfo();
    virtual bool GetRecordList();
    virtual bool GetRecordInfo();
    virtual bool UpdateRecord();

protected:
    // HTTP通信
    CHttps http;
    // DNS帐号
    std::string m_szID;
    // DNS密码
    std::string m_szPassword;
    // 当前的地址
    std::string m_szCurrentIpAddress;
    // 新的地址
    std::string m_szNewIpAddress;
    // 记录ID 
    std::string m_szRecordID;
    // 网址
    std::string m_szDomain;
    // 网址前缀，如www/_dnsauth，默认www
    std::string m_szSubDomain;
    // 记录类型，默认“A”
    std::string m_szRecordType;
    // 记录行ID，默认“0”
    std::string m_szRecordLineId;
};

#endif // C_WORK_H