#include "pch.h"

__DNSPOD_BEGIN

std::string RecviceMsg;

CHttps::CHttps()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

CHttps::~CHttps()
{
	curl_global_cleanup();
}

std::string CHttps::SendRecv(const std::string & _szCurl, const std::list<std::pair<std::string, std::string>> &_liParam, const bool _SSLVerifypeer)
{
	CURL* pCurl = curl_easy_init();
	CURLcode code;
	code = curl_easy_setopt(pCurl, CURLOPT_URL, _szCurl.c_str());
	if(_SSLVerifypeer)code = curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, false);
	code = curl_easy_setopt(pCurl, CURLOPT_POST, true);
	code = curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, Recvice);

	// Set comm param
	curl_httppost *pFormPos = NULL;
	curl_httppost *pLastPtr = NULL;
	for (std::pair<std::string, std::string> pairs : _liParam)
	{
		if (!SetParam(&pFormPos, &pLastPtr, std::get<0>(pairs), std::get<1>(pairs)))
		{
			throw "Set param error.";
			return std::string();
		}
	}
	code = curl_easy_setopt(pCurl, CURLOPT_HTTPPOST, pFormPos);
	RecviceMsg = "";
	code = curl_easy_perform(pCurl);
	curl_easy_cleanup(pCurl);

	if (code != CURLE_OK)
		return curl_easy_strerror(code);
	return RecviceMsg;
}

bool CHttps::SetParam(curl_httppost ** _pFormPos, curl_httppost ** _pLastPtr, std::string & _szName, std::string & _szContents)
{
	if (!_pFormPos || !_pLastPtr)return false;
	CURLFORMcode code = curl_formadd(_pFormPos, _pLastPtr,
		CURLFORM_COPYNAME, _szName.c_str(),
		CURLFORM_COPYCONTENTS, _szContents.c_str(),
		CURLFORM_END);
	
	return code == CURL_FORMADD_OK ? true : false;
}

size_t CHttps::Recvice(void * _pData, size_t _nSize, size_t _nMemb, void * _pStream)
{
	RecviceMsg += (char*)_pData;
	return _nMemb;
}

__DNSPOD_END