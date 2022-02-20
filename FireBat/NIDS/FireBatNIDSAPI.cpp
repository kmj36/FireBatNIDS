// NIDS.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include "FireBatNIDSAPI.h"

/* 예제
// 내보낸 변수의 예제입니다.
NIDS_API int nNIDS=0;

// 내보낸 함수의 예제입니다.
NIDS_API int fnNIDS(void)
{
	return 42;
}

// 내보낸 클래스의 생성자입니다.
// 클래스 정의를 보려면 NIDS.h를 참조하십시오.
CNIDS::CNIDS()
{
	return;
}
*/

CFireBatIDS::CFireBatIDS() :
	m_pAlldev(NULL)
	,m_pDevice(NULL)
	,m_hPcapHandle(NULL)
{
	::ZeroMemory(m_pszErrbuf, sizeof(char) * PCAP_ERRBUF_SIZE);
}

CFireBatIDS::~CFireBatIDS()
{
}

int CFireBatIDS::FBinit()
{
	if(pcap_findalldevs(&m_pAlldev, errbuf) == -1)

}

int CFireBatIDS::FBclose()
{

}