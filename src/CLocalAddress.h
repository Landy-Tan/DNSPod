/**********************************************************************
 * File name:	CLocalAddress.h
 * Author:		LandyTan
 * Create date:	2020年4月15日
 * Description:	定时更新本机公网IP地址
 * History:
 * <Date>			<Author>	<Description>
 * 2020年4月15日	LandyTan	创建
 **********************************************************************/

#ifndef CLOCALADDRESS_H
#define CLOCALADDRESS_H

#include "pch.h"

__DNSPOD_BEGIN

class CLocalAddress :
	public CThread
{
public:
	CLocalAddress();
	const std::string& GetIP()const;

protected:
	virtual void Process();

private:
	std::shared_ptr<std::string> m_ip;
	std::shared_ptr<CURL> m_curl;
};

__DNSPOD_END

#endif // CLOCALADDRESS_H