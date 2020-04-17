TargetName := DNSPod
SourcePath := . jsoncpp/src/lib_json
Sources := $(foreach var, $(SourcePath), $(wildcard $(var)/*.cpp))
Headers := $(shell ls *.cpp)
IncludePath := -I curl/include -I jsoncpp/include
LibPath := -L /usr/bin
Libs := -lcurl -lpthread

$(TargetName) : $(Sources)
	g++ -std=c++11 -g -o $(TargetName) $(Sources) $(IncludePath) $(LibPath) $(Libs)

Sources : 
	echo $(Sources)

SourcePath : 
	echo $(SourcePath)

Wildcard :
	echo $(wildcard $(SourcePath)/*.cpp)
