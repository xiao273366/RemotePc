#pragma once
//����һЩ�����Ľṹ���

//����һЩ��,��ʾ���ľ��崦������
//CMD�������� 
#define PACKET_REQ_CMD 10001  //REQ requset CMD ��ʾcmd������������		�ͻ���--->�����
#define PACKET_RLY_CMD 10002  //RLY requset CMD ��ʾcmd���ͻظ�����		�����--->�ͻ���
//������������
#define PACKET_REQ_KEYBOARD 20001  //REQ requset ���� ��ʾ����������������		�ͻ���--->�����
#define PACKET_RLY_KEYBOARD 20002  //RLY requset ���� ��ʾ�������ͻظ�����		�����--->�ͻ���

//���� ��1�ֽڶ���
#pragma  pack(push)		//��ʾԭ�еĽṹ�����ֵ��Сѹջ
#pragma pack(1)
struct MyPacket {
	unsigned int type; //��ʾ������
	unsigned int length; //��ʾ����
	char data[1];		//��ʾ����һ��1�ֽڵ�����,��������

};
#pragma pack(pop)	//��ʾԭ�еĽṹ�����ֵ��С��ջ