#include "NetSink.h"
#include "Services.h"
#include "NetSinkObj.h"

CNetSink::CNetSink()
{
	
}

CNetSink::~CNetSink()
{
	
}

CNetSink* CNetSink::CreateNetSink(CServices* pServices,int nType)
{
	return new CNetSinkObj(pServices,nType);
}
