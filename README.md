此项目是为了解决将本地公网IP地址上传到云解析服务器。

关于DNSPod.conf文件
此文件是本程序的配置文件，请将相关参数填入到各个字段。否则程序不能正常上传
[
	{
		"Domain" : "网址,注意不带前缀，例如baidu.com",
		"ID" : "dnspod账号",
		"Password" : "dnspod密码",
		"RecordID" : "记录ID",
		"RecordLineId" : "0",
		"RecordType" : "记录类型",
		"SubDomain" : "网址前缀，例如www"
	}
]
