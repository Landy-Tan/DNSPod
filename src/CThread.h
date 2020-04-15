/**********************************************************************
 * File name:	CThread.h
 * Author:		LandyTan
 * Create date:	2020��4��14��
 * Description:	���̻߳��࣬�߳�ִ�й�������дProcess����
 * History:
 * <Date>			<Author>	<Description>
 * 2020��4��15��	LandyTan	����
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
