/**********************************************************************
 * File name:	CHttps.h
 * Author:		LandyTan
 * Create date:	2020年4月15日
 * Description:	HTTP请求类
 * History:
 * <Date>			<Author>	<Description>
 * 2020年4月15日	LandyTan	创建
 **********************************************************************/

#ifndef C_HTTPS_H
#define C_HTTPS_H

#include "pch.h"

__DNSPOD_BEGIN

extern std::string RecviceMsg;

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

public:
	static size_t Recvice(
		void* _pData, 
		size_t _nSize, 
		size_t _nMemb, 
		void* _pStream);
};

__DNSPOD_END

#endif // !C_HTTPS_H

