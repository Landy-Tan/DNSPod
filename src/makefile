TargetName := DNSPod
SourcePath := . jsoncpp/src/lib_json
Sources := $(foreach var, $(SourcePath), $(wildcard $(var)/*.cpp))
Headers := $(shell ls *.cpp)
IncludePath := curl/include jsoncpp/include
LibPath := /usr/bin
Libs := curl

$(TargetName) : $(Sources)
	g++ -std=c++11 -g -o $(TargetName) $(Sources) -I curl/include -I jsoncpp/include -L$(LibPath) -l$(Libs)

Sources : 
	echo $(Sources)

SourcePath : 
	echo $(SourcePath)

Wildcard :
	echo $(wildcard $(SourcePath)/*.cpp)
