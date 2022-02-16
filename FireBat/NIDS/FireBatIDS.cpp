#include "stdafx.h"
#include "FireBatIDS.h"

CFireBatIDS::CFireBatIDS()
{
	SetDllDirectory(_T("C:\\Windows\\System32\\Npcap\\"));
	m_hwpcap = LoadLibrary(_T("wpcap.dll"));
}

CFireBatIDS::~CFireBatIDS()
{
	FreeLibrary(m_hwpcap);
}