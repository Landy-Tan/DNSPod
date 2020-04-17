#include "pch.h"
using namespace std;

__DNSPOD_BEGIN

extern std::string RecviceMsg;

CWork::CWork()
{
	m_Conf = CWorkConf("DNSPod.conf").ReadConf();
	if (m_Conf->size() <= 0)
	{
		LogError("Work config error");
		return;
	}
}

CWork::~CWork()
{

}

void CWork::Process()
{
	m_szNewIpAddress = Singleton<CLocalAddress>::Instance().GetIP();
	LogInfo((std::string("Current IP address is :") + m_szCurrentIpAddress + std::string(". New IP address is :") + m_szNewIpAddress).c_str());
	if (m_szCurrentIpAddress != m_szNewIpAddress &&
		!m_szNewIpAddress.empty()) {
		LogInfo("Update IP address.");
		for (std::shared_ptr<WORKCONF> conf : *(m_Conf.get())) {
			if (!GetUserInfo(conf)) { LogError("Failed GetUserInfo function."); return; }
			if (!GetRecordList(conf)) { LogError("Failed GetRecordList function."); return; }
			if (!GetRecordInfo(conf)) { LogError("Failed GetRecordInfo function."); return; }
			if (!UpdateRecord(conf)) { LogError("Failed UpdateRecord function."); return; }
			m_szCurrentIpAddress = m_szNewIpAddress;
		}
		LogInfo("Finish update ip address.");
	}
#ifdef _WIN32
	Sleep(60 * 1000);
#else
	sleep(60);
#endif // _WIN32

    return;
}

bool CWork::GetUserInfo(std::shared_ptr<WORKCONF> conf)
{
    const static std::string cszUserInfoCurl("https://dnsapi.cn/User.Detail");
    std::list<std::pair<std::string, std::string>> lsUserInfoParam;
	lsUserInfoParam.push_back(std::make_pair<std::string, std::string>("login_token", conf->ID + "," + conf->Password));
	lsUserInfoParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUserInfo = http.SendRecv(cszUserInfoCurl, lsUserInfoParam);
	LogInfo(szUserInfo.c_str());
	// TODO: 此处应检查http.SendRecv的返回结果
    return true;
}
bool CWork::GetRecordList(std::shared_ptr<WORKCONF> conf)
{
	const static std::string cszRecordListCurl("https://dnsapi.cn/Record.List");
    	std::list<std::pair<std::string, std::string>> lsRecordListParam;
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("login_token", conf->ID + "," + conf->Password));
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("domain", conf->Domain.c_str()));
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szRecordList = http.SendRecv(cszRecordListCurl, lsRecordListParam);
	LogInfo(szRecordList.c_str());
	// TODO: 此处应检查http.SendRecv的返回结果
    return true;
}
bool CWork::GetRecordInfo(std::shared_ptr<WORKCONF> conf)
{
	const static std::string cszRecordInfoCurl("https://dnsapi.cn/Record.Info");
    	std::list<std::pair<std::string, std::string>> lsRecordInfoParam;
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("login_token", conf->ID + "," + conf->Password));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("domain", conf->Domain.c_str()));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("record_id", conf->RecordID.c_str()));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szRecordInfo = http.SendRecv(cszRecordInfoCurl, lsRecordInfoParam);
	LogInfo(szRecordInfo.c_str());
	// TODO: 此处应检查http.SendRecv的返回结果
    return true;
}
bool CWork::UpdateRecord(std::shared_ptr<WORKCONF> conf)
{
	const static std::string cszUpdateRecordCurl("https://dnsapi.cn/Record.Modify");
    std::list<std::pair<std::string, std::string>> lsUpdateRecordParam;
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("login_token", conf->ID + "," + conf->Password));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("domain", conf->Domain.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_id", conf->RecordID.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("sub_domain", conf->SubDomain.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_type", conf->RecordType.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_line_id", conf->RecordLineId.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("value", m_szNewIpAddress.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUpdateRocord = http.SendRecv(cszUpdateRecordCurl, lsUpdateRecordParam);
	LogInfo(szUpdateRocord.c_str());
	// TODO: 此处应检查http.SendRecv的返回结果
    return true;
}

__DNSPOD_END
