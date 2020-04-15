/**********************************************************************
 * File name:	CWorkConf.h
 * Author:		LandyTan
 * Create date:	2020年4月15日
 * Description:	配置文件类型及其在文件系统中的操作
 * History:
 * <Date>			<Author>	<Description>
 * 2020年4月15日	LandyTan	创建
 **********************************************************************/

#include "pch.h"

__DNSPOD_BEGIN

typedef struct work_conf 
{
	// DNS帐号
	std::string ID;
	// DNS密码
	std::string Password;
	// 记录ID 
	std::string RecordID;
	// 网址
	std::string Domain;
	// 网址前缀，如www/_dnsauth，默认www
	std::string SubDomain;
	// 记录类型，默认“A”
	std::string RecordType;
	// 记录行ID，默认“0”
	std::string RecordLineId;

	work_conf() { ; }
	work_conf(const std::string &strJson) { FromJson(strJson); }
	Json::Value ToJson();
	std::string ToJsonString();
	void FromJson(const std::string &strJson);
}WORKCONF, *LPWORKCONF;


class CWorkConf
{
public:
	CWorkConf(const std::string &confFile);
	std::shared_ptr<std::vector<std::shared_ptr<WORKCONF>>> ReadConf();
	bool WriteConf(std::shared_ptr<WORKCONF> conf);
	bool WriteConf(std::shared_ptr< std::vector<std::shared_ptr<WORKCONF>>> conf);
private:
	const std::string m_confFile;
};

__DNSPOD_END