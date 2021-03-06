#pragma once
#include "types.h"

class CServices;

enum SOCK_CONN_TYPE
{
	SOCK_CONN_SER,    	//被动连接
	SOCK_CONN_CLI,		//主动连接
};

class CNetSink
{
public:
	CNetSink();
	virtual ~CNetSink();
	static CNetSink* CreateNetSink(CServices* pServices,int nType);
	static void DestroyNetSink(CNetSink* pSink);
public:
	virtual void Init(const char* szIp) = 0;
	virtual void Connect() = 0;
	virtual bool DisConnect() = 0;
	virtual int  HandNetMsg(SERVICEINDEX nIndex, const char* pData, unsigned uDataSize) = 0;
	virtual bool HandTimeMsg(TIMEERID uTimeID) = 0;
	virtual bool HandUserMsg(int nType, void* pData, DATASIZE uDataSize) = 0;
	virtual void Close() = 0;
};

