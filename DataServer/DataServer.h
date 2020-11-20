#pragma once

#include "Server.h"
#include <string>

class CDataServer : public CServer
{
public:
	CDataServer(CServices* pServices);
	~CDataServer();
public:
	int	 Initialize();
public:
	const char* GetRedisHost() const;
	const unsigned short GetRedisPort() const;
	const char* GetRedisAuth() const;

	const char* GetDbHost() const;
	const unsigned short GetDbPort() const;
	const char* GetDbName() const;
	const char* GetDbUserName() const;
	const char* GetDbPass() const;
private:
	int  ReadConfig(const char* szConfigFile);
	
private:
	std::string m_szIp;
	unsigned short m_nPort;

	std::string m_szCenterIp;
	unsigned short m_nCenterPort;

	std::string m_szRedisHost;
	unsigned short m_nRedisPort;
	std::string m_szAuth;

	std::string m_szDbHost;
	USHORT 		m_nDbPort;
	std::string m_szDbName;
	std::string m_szDbUserName;
	std::string m_szDbPass;

	CMemDataBaseEnginer* m_pMem;
	CDataBaseEnginer*    m_pData;
};