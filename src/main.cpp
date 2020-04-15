
#include "pch.h"

using namespace std;
using namespace __DNSPOD;

int main()
{
	Singleton<CLocalAddress>::Instance();
	Singleton<CWork>::Instance();
	while (1)
	{
#ifdef _WIN32
		Sleep(60 * 1000);
#else
		sleep(60 * 30);
#endif // _WIN32
	}
	return 0;
}