#include "pch.h"

__DNSPOD_BEGIN

CThread::CThread()
	: m_isStart(false)
{

}

CThread::~CThread()
{
	Stop();
}

bool CThread::Start()
{
	m_isStart = true;
	m_thread.reset(new std::thread([&] {
		while (m_isStart) {
			Process();
		}
	}));
	m_thread->detach();
	return true;
}

void CThread::Stop()
{
	m_isStart = false;
	m_thread.reset();
}

__DNSPOD_END