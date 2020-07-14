#include "stdafx.h"
#include "function.h"
//头文件
#include <winsock2.h>
#include <windows.h>

//库文件
#include <thread>
#pragma comment(lib,"ws2_32.lib")
#include <iostream>			//标准输入输出头文件
#define _WINSOCK_DEPRECATED_NO_WARNINGS
SOCKET s;
int InitSocket() {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	//初始化操作
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return 0;
	}
	//1.socket				创建套接字
	s = socket(
		AF_INET,			//INET协议
		SOCK_STREAM,		//表示使用的是TCP协议
		0);
	if (s == INVALID_SOCKET) {
		return 0;
	}

	//2.bind/listen			绑定/监听端口
	sockaddr_in  addr;									//替换sockaddr结构体
	int nLenght = sizeof(sockaddr_in);
	addr.sin_family = AF_INET;							//写死
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");	//允许连接的IP 0.0.0.0代表所有
	addr.sin_port = htons(19611);						//h:host ti n:network	s:两个字节 l:4个字节	网络转本地:ntohs	坑:网络字节序(大尾方式) 本地字节序(小尾方式)
	return 1;
}
