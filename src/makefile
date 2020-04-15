TargetName := DNSPod
Sources := $(shell ls *.cpp)
Headers := $(shell ls *.cpp)
IncludePath := /usr/include/curl
LibPath := /usr/bin
Libs := curl

DNS : $(Sources)
	g++ -std=c++11 -g -o $(TargetName) $(Sources) -I$(IncludePath) -l$(Libs)
