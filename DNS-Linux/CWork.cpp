#include "CWork.h"
#include <iostream>

using namespace std;

CWork::CWork(std::string _szID, 
        std::string _szPassword, 
        std::string _szRecordID,
        std::string _szDomain , 
        std::string _szSubDomain, 
        std::string _szRocordType, 
        std::string _szRecordLineID)
    : m_szID(_szID)
    , m_szPassword(_szPassword)
    , m_szRecordID(_szRecordID)//  396453969   396453821
    , m_szDomain(_szDomain)
    , m_szSubDomain(_szSubDomain)
    , m_szRecordType(_szRocordType)
    , m_szRecordLineId(_szRecordLineID)
{

}

CWork::~CWork()
{

}

bool CWork::Run()
{
    if(!GetIpAddress())return false;
    if(m_szCurrentIpAddress == m_szNewIpAddress)return true;
    if(!GetUserInfo())return false;
    if(!GetRecordList())return false;
    if(!GetRecordInfo())return false;
    if(!UpdateRecord())return false;
    m_szCurrentIpAddress = m_szNewIpAddress;
    return true;
}

bool CWork::GetIpAddress()
{
    const std::string cszQueryIpCurl("http://www.ip138.com/");
	std::string szFindStartMsg("<span class=\"F\">IP: ");
	std::string szFindStopMsg("</span>");
	std::list<std::pair<std::string, std::string>> lsQueryIpParam;
	std::string szTempIp = http.SendRecv(cszQueryIpCurl, lsQueryIpParam, false);
	size_t ipStartIndex = szTempIp.find(szFindStartMsg, 0);
	size_t ipStopIndex = szTempIp.find(szFindStopMsg, ipStartIndex + 1);
	char ip[128]{ 0 };
	szTempIp.copy(ip, ipStopIndex - ipStartIndex - szFindStartMsg.length(), ipStartIndex + szFindStartMsg.length());
	m_szNewIpAddress = ip;
	cout << "Local ip address:" << m_szNewIpAddress << std::endl;
    return true;
}
bool CWork::GetUserInfo()
{
    const std::string cszUserInfoCurl("https://dnsapi.cn/User.Detail");
    std::list<std::pair<std::string, std::string>> lsUserInfoParam;
	lsUserInfoParam.push_back(std::make_pair<std::string, std::string>("login_token", m_szID + "," + m_szPassword));
	lsUserInfoParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUserInfo = http.SendRecv(cszUserInfoCurl, lsUserInfoParam);
	std::cout << "User info:" << std::endl << szUserInfo << std::endl;
    return true;
}
bool CWork::GetRecordList()
{
	const std::string cszRecordListCurl("https://dnsapi.cn/Record.List");
    	std::list<std::pair<std::string, std::string>> lsRecordListParam;
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("login_token", m_szID + "," + m_szPassword));
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("domain", m_szDomain.c_str()));
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szRecordList = http.SendRecv(cszRecordListCurl, lsRecordListParam);
	std::cout << "Record list:" << std::endl << szRecordList << std::endl;
    return true;
}
bool CWork::GetRecordInfo()
{
	const std::string cszRecordInfoCurl("https://dnsapi.cn/Record.Info");
    	std::list<std::pair<std::string, std::string>> lsRecordInfoParam;
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("login_token", m_szID + "," + m_szPassword));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("domain", m_szDomain.c_str()));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("record_id", m_szRecordID.c_str()));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szRecordInfo = http.SendRecv(cszRecordInfoCurl, lsRecordInfoParam);
	std::cout << "Record info:" << std::endl << szRecordInfo << std::endl;
    return true;
}
bool CWork::UpdateRecord()
{
	const std::string cszUpdateRecordCurl("https://dnsapi.cn/Record.Modify");
    std::list<std::pair<std::string, std::string>> lsUpdateRecordParam;
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("login_token", m_szID + "," + m_szPassword));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("domain", m_szDomain.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_id", m_szRecordID.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("sub_domain", m_szSubDomain.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_type", m_szRecordType.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_line_id", m_szRecordLineId.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("value", m_szNewIpAddress.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUpdateRocord = http.SendRecv(cszUpdateRecordCurl, lsUpdateRecordParam);
	std::cout << "Update record:" << std::endl << szUpdateRocord << std::endl;
    return true;
}