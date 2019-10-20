#ifndef C_HTTPS_H
#define C_HTTPS_H

#include "curl.h"
#include <string>
#include <tuple>
#include <list>
//#pragma comment(lib, "LIBCURL.lib")

static std::string RecviceMsg;

class CHttps
{
public:
	CHttps();
	virtual ~CHttps();

	std::string SendRecv(
		const std::string& _szCurl, 
		const std::list<std::pair<std::string, std::string>>& _liParam, 
		const bool _SSLVerifypeer = true);

protected:
	bool SetParam(
		curl_httppost** _pFormPos, 
		curl_httppost** _pLastPtr,
		std::string& _szName, 
		std::string& _szContents);

	static size_t Recvice(
		void* _pData, 
		size_t _nSize, 
		size_t _nMemb, 
		void* _pStream);
};


#endif // !C_HTTPS_H

