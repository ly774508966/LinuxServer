#include "DataRedis.h"
#include "DataServer.h"

extern CDataServer* g_pDataServer;

CDataRedis::CDataRedis(CServices* pService):CRedis(pService)
{
	
}

CDataRedis::~CDataRedis()
{
	
}

int  CDataRedis::GetRedisConfig()
{
	m_dbConfig.szHost = g_pDataServer->GetRedisHost();
	m_dbConfig.nPort = g_pDataServer->GetRedisPort();
	m_dbConfig.szAuth = g_pDataServer->GetRedisAuth();
	return 0;
}

void CDataRedis::RegRedisScript(int nType,const char* szStr)
{
	redisReply* reply = (redisReply*)redisCommand(m_pConn, "SCRIPT LOAD %s", szStr);
	m_RedisPro[nType] = new char[reply->len+1];
	memcpy(m_RedisPro[nType], reply->str, reply->len);
	m_RedisPro[nType][reply->len] = 0;
	freeReplyObject(reply);
}

bool CDataRedis::Connected()
{
	return true;
}

int  CDataRedis::Exec(SERVICEINDEX nSrcIndex,SERVICEINDEX nCsid,uint32 nType,void* pData,DATASIZE nDataSize)
{
	return 0;
}

