#include <iostream>
#include <exception>
#include <string>
#include "CHttps.h"

int main()
{
	const std::string cszUserInfoCurl("https://dnsapi.cn/User.Detail");
	const std::string cszRecordInfoCurl("https://dnsapi.cn/Record.Info");
	const std::string cszRecordListCurl("https://dnsapi.cn/Record.List");
	const std::string cszUpdateRecordCurl("https://dnsapi.cn/Record.Modify");

	std::string ID = "89042";
	std::string Password = "fa2b65887bece4bf8333d667c6159175";
	CHttps http;

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
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("value", "123.207.75.44"));
	lsUpdateRecordParam.push_back(std::make_pair<std::string, std::string>("format", "json"));
	std::string szUpdateRocord = http.SendRecv(cszUpdateRecordCurl, lsUpdateRecordParam);
	std::cout << "Update record:" << std::endl << szUpdateRocord << std::endl;
	
	system("pause");
	return 0;
}