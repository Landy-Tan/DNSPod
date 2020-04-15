/**********************************************************************
 * File name:	CWork.h
 * Author:		LandyTan
 * Create date:	2020年4月15日
 * Description:	主流程
 * History:
 * <Date>			<Author>	<Description>
 * 2020年4月15日	LandyTan	创建
 **********************************************************************/

#ifndef C_WORK_H
#define C_WORK_H

#include "pch.h"

__DNSPOD_BEGIN

class CWork : public CThread
{
public:
    CWork();
    virtual ~CWork();

protected:
	virtual void Process();
    virtual bool GetUserInfo(std::shared_ptr<WORKCONF> conf);
    virtual bool GetRecordList(std::shared_ptr<WORKCONF> conf);
    virtual bool GetRecordInfo(std::shared_ptr<WORKCONF> conf);
    virtual bool UpdateRecord(std::shared_ptr<WORKCONF> conf);

protected:
    // HTTP通信
    CHttps http;
	// 当前的地址
	std::string m_szCurrentIpAddress;
	// 新的地址
	std::string m_szNewIpAddress;
	std::shared_ptr<std::vector<std::shared_ptr<WORKCONF>>> m_Conf;
};

__DNSPOD_END

#endif // C_WORK_H
