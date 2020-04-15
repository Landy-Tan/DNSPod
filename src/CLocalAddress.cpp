#include "pch.h"


__DNSPOD_BEGIN


CLocalAddress::CLocalAddress()
	: m_ip(new std::string)
	, m_curl(curl_easy_init(), [](CURL *curl) {curl_easy_cleanup(curl); })
{
	curl_easy_setopt(m_curl.get(), CURLOPT_CUSTOMREQUEST, "GET");
	curl_easy_setopt(m_curl.get(), CURLOPT_URL, "ipinfo.io/json");
	curl_easy_setopt(m_curl.get(), CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(m_curl.get(), CURLOPT_DEFAULT_PROTOCOL, "https");
	curl_easy_setopt(m_curl.get(), CURLOPT_HTTPHEADER, NULL);
	curl_easy_setopt(m_curl.get(), CURLOPT_WRITEFUNCTION, CHttps::Recvice);

	Start();
}

const std::string & CLocalAddress::GetIP() const
{
	return *m_ip;
}

void CLocalAddress::Process()
{
	CURLcode res;
	if (m_curl)
	{
		res = curl_easy_perform(m_curl.get());
	}
	Json::Value value;
	Json::Reader reader;
	if (reader.parse(RecviceMsg, value) &&
		value["ip"].isString()) 
	{
		std::string ip = value["ip"].toStyledString();
		*m_ip = ip.substr(1, ip.length() - 3);
	}

#ifdef _WIN32
	Sleep(60 * 1000);
#else
	sleep(60 * 30);
#endif // _WIN32


}

__DNSPOD_END