#include "stdafx.h"
#include "function.h"
//ͷ�ļ�
#include <winsock2.h>
#include <windows.h>

//���ļ�
#include <thread>
#pragma comment(lib,"ws2_32.lib")
#include <iostream>			//��׼�������ͷ�ļ�
#define _WINSOCK_DEPRECATED_NO_WARNINGS
SOCKET s;
int InitSocket() {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	//��ʼ������
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return 0;
	}
	//1.socket				�����׽���
	s = socket(
		AF_INET,			//INETЭ��
		SOCK_STREAM,		//��ʾʹ�õ���TCPЭ��
		0);
	if (s == INVALID_SOCKET) {
		return 0;
	}

	//2.bind/listen			��/�����˿�
	sockaddr_in  addr;									//�滻sockaddr�ṹ��
	int nLenght = sizeof(sockaddr_in);
	addr.sin_family = AF_INET;							//д��
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");	//�������ӵ�IP 0.0.0.0��������
	addr.sin_port = htons(19611);						//h:host ti n:network	s:�����ֽ� l:4���ֽ�	����ת����:ntohs	��:�����ֽ���(��β��ʽ) �����ֽ���(Сβ��ʽ)
	return 1;
}
