/**********************************************************************
 * File name:	CThread.h
 * Author:		LandyTan
 * Create date:	2020年4月14日
 * Description:	多线程基类，线程执行过程需重写Process方法
 * History:
 * <Date>			<Author>	<Description>
 * 2020年4月15日	LandyTan	创建
 **********************************************************************/

#ifndef CTHREAD_H
#define CTHREAD_H

#include "pch.h"

__DNSPOD_BEGIN

class CThread
{
public:
	CThread();
	virtual ~CThread();
	bool Start();
	void Stop();

protected:
	virtual void Process() = 0;

private:
	std::shared_ptr<std::thread> m_thread;
	bool m_isStart;
};


__DNSPOD_END

#endif // !CTHREAD_H
