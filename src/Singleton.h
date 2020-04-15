/**********************************************************************
 * File name:	Singleton.h
 * Author:		
 * Create date:	2020年4月14日
 * Description:	单例模板类，抄录自开源项目《flamingo》
 * History:
 * <Date>			<Author>	<Description>
 **********************************************************************/

#ifndef SINGLETON_H
#define SINGLETON_H

#include "pch.h"

__DNSPOD_BEGIN

template<typename T>
class Singleton
{
public:
	static T& Instance()
	{
		if (nullptr == value_)
		{
			value_ = new T();
		}
		return *value_;
	}

private:
	Singleton();
	~Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static void init()
	{
		value_ = new T();
	}

	static void destroy()
	{
		delete value_;
	}

private:
	static T*             value_;
};

template<typename T>
T* Singleton<T>::value_ = nullptr;

__DNSPOD_END

#endif // !SINGLETON_H