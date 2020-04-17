
#include "pch.h"

using namespace std;
using namespace __DNSPOD;


void StartUp()
{
	Singleton<CLocalAddress>::Instance().Start();
	Singleton<CWork>::Instance().Start();
	while (1)
	{
#ifdef _WIN32
		Sleep(60 * 1000);
#else
		sleep(60 * 30);
#endif // _WIN32
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		StartUp();
	}
	else if (strcmp(argv[1], "-b") == 0 ||
		strcmp(argv[1], "-B") == 0) 
	{
#ifdef _LINUX
		if (fork() == 0)
		{
			StartUp();
		}
#endif 
	}
	return 0;
}
