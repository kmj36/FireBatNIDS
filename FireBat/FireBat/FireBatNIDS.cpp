#include "stdafx.h"
#include "FireBatNIDS.h"

CFireBatNIDS::CFireBatNIDS():
	m_szDevice(NULL),
	m_pPcapHandle(NULL)
{
	m_szErrBuf[0] = '\0';
}

CFireBatNIDS::~CFireBatNIDS()
{
}

