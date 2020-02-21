/************************************************************************/
/*						CURL Development manual:						*/
/*						https://curl.haxx.se/libcurl/c/					*/
/************************************************************************/

#include <iostream>
#include <exception>
#include <string>
#ifdef _WIN32
#else
#include <unistd.h>
#endif 
#include "CHttps.h"
#include "CWork.h"
using namespace std;


size_t Recvice(void * _pData, size_t _nSize, size_t _nMemb, void * _pStream)
{
	RecviceMsg = (char*)_pData;
	return _nMemb;
}
/*
int main0()
{
	const std::string cszUserInfoCurl("https://dnsapi.cn/User.Detail");
	const std::string cszRecordInfoCurl("https://dnsapi.cn/Record.Info");
	const std::string cszRecordListCurl("https://dnsapi.cn/Record.List");
	const std::string cszUpdateRecordCurl("https://dnsapi.cn/Record.Modify");
	const std::string cszQueryIpCurl("http://www.ip138.com/");


	std::string IP;
	std::string ID = "89042";
	std::string Password = "fa2b65887bece4bf8333d667c6159175";
	CHttps http;

	// Get ip address
	std::string szFindStartMsg("<span class=\"F\">IP: ");
	std::string szFindStopMsg("</span>");
	std::list<std::pair<std::string, std::string>> lsQueryIpParam;
	std::string szTempIp = http.SendRecv(cszQueryIpCurl, lsQueryIpParam, false);
	size_t ipStartIndex = szTempIp.find(szFindStartMsg, 0);
	size_t ipStopIndex = szTempIp.find(szFindStopMsg, ipStartIndex + 1);
	char ip[128]{ 0 };
	szTempIp.copy(ip, ipStopIndex - ipStartIndex - szFindStartMsg.length(), ipStartIndex + szFindStartMsg.length());
	IP = ip;
	cout << "Local ip address:" << IP << std::endl;

	// Get user info
	std::list<std::pair<std::string, std::string>> lsUserInfoParam;
	lsUserInfoParam.push_back(std::make_pair<std::string, std::string>("login_token", ID + "," + Password));
	lsUserInfoParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUserInfo = http.SendRecv(cszUserInfoCurl, lsUserInfoParam);
	std::cout << "User info:" << std::endl << szUserInfo << std::endl;

	// Get record list
	std::list<std::pair<std::string, std::string>> lsRecordListParam;
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("login_token", ID + "," + Password));
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("domain", "landytan.com"));
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szRecordList = http.SendRecv(cszRecordListCurl, lsRecordListParam);
	std::cout << "Record list:" << std::endl << szRecordList << std::endl;

	// Get record info
	std::list<std::pair<std::string, std::string>> lsRecordInfoParam;
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("login_token", ID + "," + Password));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("domain", "landytan.com"));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("record_id", "547501386"));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szRecordInfo = http.SendRecv(cszRecordInfoCurl, lsRecordInfoParam);
	std::cout << "Record info:" << std::endl << szRecordInfo << std::endl;

	// Update record
	std::list<std::pair<std::string, std::string>> lsUpdateRecordParam;
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("login_token", ID + "," + Password));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("domain", "landytan.com"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_id", "547501386"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("sub_domain", "www"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_type", "A"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_line_id", "0"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("value", "123.207.75.44"));
	//lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("value", IP.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUpdateRocord = http.SendRecv(cszUpdateRecordCurl, lsUpdateRecordParam);
	std::cout << "Update record:" << std::endl << szUpdateRocord << std::endl;

	system("pause");
	return 0;
}

int main1()
{
	const std::string cszUserInfoCurl("https://dnsapi.cn/User.Detail");
	const std::string cszRecordInfoCurl("https://dnsapi.cn/Record.Info");
	const std::string cszRecordListCurl("https://dnsapi.cn/Record.List");
	const std::string cszUpdateRecordCurl("https://dnsapi.cn/Record.Modify");
	const std::string cszQueryIpCurl("http://www.ip138.com/");


	std::string IP;
	std::string ID = "89042";
	std::string Password = "fa2b65887bece4bf8333d667c6159175";
	CHttps http;

	// Get ip address
	std::string szFindStartMsg("<span class=\"F\">IP: ");
	std::string szFindStopMsg("</span>");
	std::list<std::pair<std::string, std::string>> lsQueryIpParam;
	std::string szTempIp = http.SendRecv(cszQueryIpCurl, lsQueryIpParam, false);
	size_t ipStartIndex = szTempIp.find(szFindStartMsg, 0);
	size_t ipStopIndex = szTempIp.find(szFindStopMsg, ipStartIndex + 1);
	char ip[128]{ 0 };
	szTempIp.copy(ip, ipStopIndex - ipStartIndex - szFindStartMsg.length(), ipStartIndex + szFindStartMsg.length());
	IP = ip;
	cout << "Local ip address:" << IP << std::endl;

	// Get user info
	std::list<std::pair<std::string, std::string>> lsUserInfoParam;
	lsUserInfoParam.push_back(std::make_pair<std::string, std::string>("login_token", ID + "," + Password));
	lsUserInfoParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUserInfo = http.SendRecv(cszUserInfoCurl, lsUserInfoParam);
	std::cout << "User info:" << std::endl << szUserInfo << std::endl;

	// Get record list
	std::list<std::pair<std::string, std::string>> lsRecordListParam;
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("login_token", ID + "," + Password));
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("domain", "misdstudio.com"));
	lsRecordListParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szRecordList = http.SendRecv(cszRecordListCurl, lsRecordListParam);
	std::cout << "Record list:" << std::endl << szRecordList << std::endl;

	// Get record info
	std::list<std::pair<std::string, std::string>> lsRecordInfoParam;
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("login_token", ID + "," + Password));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("domain", "misdstudio.com"));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("record_id", "396453969"));
	lsRecordInfoParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szRecordInfo = http.SendRecv(cszRecordInfoCurl, lsRecordInfoParam);
	std::cout << "Record info:" << std::endl << szRecordInfo << std::endl;

	// Update record
	std::list<std::pair<std::string, std::string>> lsUpdateRecordParam;
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("login_token", ID + "," + Password));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("domain", "misdstudio.com"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_id", "396453969"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("sub_domain", "www"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_type", "A"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("record_line_id", "0"));
	//lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("value", "123.207.75.44"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("value", IP.c_str()));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUpdateRocord = http.SendRecv(cszUpdateRecordCurl, lsUpdateRecordParam);
	std::cout << "Update record:" << std::endl << szUpdateRocord << std::endl;
	
	system("pause");
	return 0;
}

int main2()
{
	// Create CURL instance
	CURL* curl = curl_easy_init();
	CURLcode code;
	code = curl_easy_setopt(curl, CURLOPT_URL, "http://www.ip138.com/");
	//code = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
	code = curl_easy_setopt(curl, CURLOPT_POST, true);
	code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Recvice);
	if (code != CURLE_OK)
		cout << "curl_easy_setopt 执行失败" << endl;
	code = curl_easy_perform(curl);
	if (code != CURLE_OK)
		cout << "curl_easy_perform 执行失败" << endl;
	cout << RecviceMsg << endl;
	system("pause");
	// Free CURL instance.
	curl_easy_cleanup(curl);
	return 0;
}
*/

int main()
{
	CWork _dnsauth_misdstudio_com("89042", 
		"fa2b65887bece4bf8333d667c6159175",
		"396453821", // _dnsauth域名
		// "396453969" ,// www域名
		"misdstudio.com", 
		"_dnsauth", 
		// "www",
		"A",
		"0");

		CWork www_misdstudio_com("89042", 
		"fa2b65887bece4bf8333d667c6159175",
		//"396453821", // _dnsauth域名
		"396453969" ,// www域名
		"misdstudio.com", 
		//"_dnsauth", 
		"www",
		"A",
		"0");

		CWork www_landytan_com("89042",
			"fa2b65887bece4bf8333d667c6159175",
			"547501386",// www域名
			"landytan.com",
			//"_dnsauth", 
			"www",
			"A",
			"0");

	while(true){	
	if(_dnsauth_misdstudio_com.Run())
		cout << "_dnsauth.misdstudio.com Update address success." << endl;
	else cout << "_dnsauth.misdstudio.com Update address fail." << endl;

	if(www_misdstudio_com.Run())
		cout << "www.misdstudio.com Update address success." << endl;
	else cout << "www.misdstudio.com Update address fail." << endl;

	if (www_landytan_com.Run())
		cout << "www.landytan.com Update address success." << endl;
	else cout << "www.landytan.com Update address fail." << endl;


#ifdef _WIN32
	Sleep(60 * 1000);
#else
	sleep(60);
#endif 
	}
	return 0;
}