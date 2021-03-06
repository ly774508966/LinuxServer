#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "MemDataBaseEnger.h"
#include "MemSink.h"
#include "MemDataBaseService.h"
#include <unistd.h>
#include "../include/Core.h"
#include "../NetSinkObj.h"

//Single_Init(CMemDataBaseEnginer)

CMemDataBaseEnginer::CMemDataBaseEnginer() : m_nServiceNum(0), m_pIndex(NULL)
{
	
}

CMemDataBaseEnginer::~CMemDataBaseEnginer()
{
	SAFE_DELTEARRAY(m_pIndex)
}

void CMemDataBaseEnginer::SetServiceNum(int nNum)
{
	if(nNum <= 0)
		return;
	
	m_nServiceNum = nNum;
	m_pIndex = new SERVICEINDEX[m_nServiceNum];

	for (int i = 0; i < m_nServiceNum; i++)
	{
		CMemDataBaseService* pService = new CMemDataBaseService;
		assert(pService != NULL);
		if (!Single_Get(CCore)->AddService(pService))
		{
			printf("MemDataBaseService Create Failer\n");
			exit(0);
		}
		
		if(!pService->Init())
		{
			printf("MemDataBaseService Init Failer\n");
			exit(0);
		}

		m_pIndex[i] = pService->GetServiceIndex();
	}
}

SERVICEINDEX CMemDataBaseEnginer::GetIndex(SERVICEINDEX nRand)
{
	if(m_nServiceNum == 0)
		return 0;

	return m_pIndex[nRand%m_nServiceNum];
}

/*

void CMemDataBaseEnginer::PostMemDataBaseReq(CServices* pServices,void* pData, DATASIZE uDataSize)
{
	SERVICEINDEX nIndex = GetIndex(pServices->GetServiceIndex());
	if(nIndex == INVALID_SERIVCE_INDEX)
		return;
	pServices->PostData(nIndex, MEM_DATA_BASE_REQ, pData, uDataSize);
}

void CMemDataBaseEnginer::PostMemDataBaseRet(CServices* pServices,SERVICEINDEX nIndex,SERVICEINDEX nCsid, uint32 uTypeId, void* pData, DATASIZE uDataSize)
{
	static DATASIZE nHeadSize = sizeof(DataCenter) + sizeof(uint32);
	char* buff[MAX_MSG_SIZE] = {0};
	DataCenter* pCenter = (DataCenter*)buff;
	pCenter->nCsid = nCsid;
	uint32* pType = (uint32*)(pCenter+1);
	*pType = uTypeId;
	if (uDataSize > 0)
	{
		memcpy(pType+1, pData, uDataSize);
	}
	//CNetSinkObj::SendData(pServices,  nIndex, MAIN_MSG_USERSER, SUB_MSG_MEM_DATA_BASE_RET,buff, nHeadSize + uDataSize);
}

*/

