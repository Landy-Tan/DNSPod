/**********************************************************************
 * File name:	pch.h
 * Author:		Landy
 * Create date:	2020��4��15��
 * Description:	��Ŀ����ͷ�ļ�
 * History:
 * <Date>			<Author>	<Description>
 * 2020��4��15��	LandyTan	����
 **********************************************************************/

#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS

#ifndef __DNSPOD
#define __DNSPOD tlproj::DNSPod
#endif // __DNSPOD

#ifndef __DNSPOD_BEGIN
#define __DNSPOD_BEGIN namespace tlproj { \
namespace DNSPod { 
#endif // __DNSPOD_BEGIN

#ifndef __DNSPOD_END 
#define __DNSPOD_END } }
#endif // __DNSPOD_END

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>  
#include <thread>
#include <memory>
#include <tuple>
#include <list>
#include <vector>

// ����ͷ�ļ���Ҫע��˳��
#include "jsoncpp/include/json/json.h"
#include "curl/include/curl/curl.h"
#include "Log.h"
#include "Singleton.h"
#include "CWorkConf.h"
#include "CThread.h"
#include "CLocalAddress.h"
#include "CHttps.h"
#include "CWork.h"

#ifdef _WIN32
#include <Windows.h>
#pragma comment(lib, "LIBCURL.lib")
#else
#include <unistd.h>
#endif _WIN32


extern std::string RecviceMsg;


#endif // PCH_H