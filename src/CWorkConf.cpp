#include "pch.h"


__DNSPOD_BEGIN

Json::Value work_conf::ToJson()
{
	Json::Value value;

	value["ID"] = ID;
	value["Password"] = Password;
	value["RecordID"] = RecordID;
	value["Domain"] = Domain;
	value["SubDomain"] = SubDomain;
	value["RecordType"] = RecordType;
	value["RecordLineId"] = RecordLineId;

	return value;
}

std::string work_conf::ToJsonString()
{
	return ToJson().toStyledString();
}

void work_conf::FromJson(const std::string & strJson)
{
	if (strJson.empty())return;
	Json::Value value;
	Json::Reader reader;

	if (!reader.parse(strJson, value))return;
	if (!value["ID"].isString() ||
		!value["Password"].isString() ||
		!value["RecordID"].isString() ||
		!value["Domain"].isString() ||
		!value["SubDomain"].isString() ||
		!value["RecordType"].isString() ||
		!value["RecordLineId"].isString())return;

	ID = value["ID"].asCString();
	Password = value["Password"].asCString();
	RecordID = value["RecordID"].asCString();
	Domain = value["Domain"].asCString();
	SubDomain = value["SubDomain"].asCString();
	RecordType = value["RecordType"].asCString();
	RecordLineId = value["RecordLineId"].asCString();
}

CWorkConf::CWorkConf(const std::string & confFile)
	: m_confFile(confFile)
{
}

std::shared_ptr<std::vector<std::shared_ptr<WORKCONF>>> CWorkConf::ReadConf()
{
	std::shared_ptr<std::vector<std::shared_ptr<WORKCONF>>> rst(new std::vector<std::shared_ptr<WORKCONF>>);
	struct stat st;
	stat(m_confFile.c_str(), &st);
	if (st.st_size <= 0)return rst;
	std::ifstream ifstr(m_confFile, std::ios::binary);
	if (!ifstr.is_open())return rst;
	std::shared_ptr<char> buf(new char[st.st_size + 1], std::default_delete<char[]>());
	ifstr.read(buf.get(), st.st_size);
	ifstr.close();

	Json::Value jsonArray;
	Json::Reader jsonReader;
	if (!jsonReader.parse(buf.get(), jsonArray))return rst;
	for (int i = 0; i < jsonArray.size(); i++)
	{
		rst->push_back(std::shared_ptr<WORKCONF>(new WORKCONF(jsonArray[i].toStyledString())));
	}
	return rst;
}

bool CWorkConf::WriteConf(std::shared_ptr<WORKCONF> conf)
{
	if (!conf.get())return false;
	std::ofstream ofstr(m_confFile, std::ios::binary);
	if (!ofstr.is_open())return false;

	Json::Value jsonArray; 
	jsonArray.append(conf->ToJson());

	ofstr << jsonArray.toStyledString() << std::endl;

	ofstr.close();

}

bool CWorkConf::WriteConf(std::shared_ptr< std::vector<std::shared_ptr<WORKCONF>>> conf)
{
	if (!conf.get())return false;
	std::ofstream ofstr(m_confFile, std::ios::binary);
	if (!ofstr.is_open())return false;

	Json::Value jsonArray;

	for (auto c : *(conf.get()))
	{
		jsonArray.append(c->ToJson());
	}

	ofstr << jsonArray.toStyledString() << std::endl;
	ofstr.close();
	return true;
}

__DNSPOD_END