/**********************************************************************
 * File name:	CWorkConf.h
 * Author:		LandyTan
 * Create date:	2020��4��15��
 * Description:	�����ļ����ͼ������ļ�ϵͳ�еĲ���
 * History:
 * <Date>			<Author>	<Description>
 * 2020��4��15��	LandyTan	����
 **********************************************************************/

#include "pch.h"

__DNSPOD_BEGIN

typedef struct work_conf 
{
	// DNS�ʺ�
	std::string ID;
	// DNS����
	std::string Password;
	// ��¼ID 
	std::string RecordID;
	// ��ַ
	std::string Domain;
	// ��ַǰ׺����www/_dnsauth��Ĭ��www
	std::string SubDomain;
	// ��¼���ͣ�Ĭ�ϡ�A��
	std::string RecordType;
	// ��¼��ID��Ĭ�ϡ�0��
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