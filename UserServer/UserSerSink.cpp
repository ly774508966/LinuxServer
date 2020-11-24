#include "UserSerSink.h"


extern CUserServer* g_pUserServer;

CUserSerSink::CUserSerSink(CServices* pServices):CNetHandSink(pServices)
{
	
}

CUserSerSink::~CUserSerSink()
{
	
}

bool CUserSerSink::HandTimeMsg(USHORT uTimeID)
{
	
}

bool CUserSerSink::HandNetData(USHORT nSrcIndex, USHORT nMain, USHORT nSub, void* pData, UINT nDataSize)
{
	switch(nMain)
	{
		case MAIN_MSG_GAMESER:
			return HandMainMSgGameSer(nSrcIndex,nSub,pData,nDataSize);
		case MAIN_MSG_CONNECT:
			return HandMainMsgConnSer(nSrcIndex,nSub,pData,nDataSize);
		default:
			break;
	}
	return false;
}

bool CUserSerSink::HandTestNetConn()
{
	m_nNum = 0;
	CNetSinkObj::SendData(m_pNet, m_pNet->GetServiceIndex(), MAIN_MSG_USERSER, US_SUB_MSG_TEST);
	return true;
}


void CUserSerSink::Connect()
{
	ConnSucess conn;
	conn.nSrvNo = g_pCenterServer->GetSerNo();
	conn.nSrvType = g_pCenterServer->GetSerType();
	CNetSinkObj::SendData(m_pNet, m_pNet->GetServiceIndex(), MAIN_MSG_USERSER, US_SUB_MSG_CONN_SUCSS,&conn,sizeof(conn));
}

bool CUserSerSink::HandMainMSgGameSer(USHORT nSrcIndex, USHORT nSub, void* pData, UINT nDataSize)
{
	switch(nSub)
	{
		case GS_SUB_MSG_TEST:
		{
			return HandTestNetConn();
		}
	}
	return true;
}

bool CUserSerSink::HandMainMsgConnSer(USHORT nSrcIndex, USHORT nSub, void* pData, UINT nDataSize)
{
	switch(nSub)
	{
		case CS_SUB_MSG_TEST:
		{
			return HandTestNetConn();
		}
	}
	return true;
}

