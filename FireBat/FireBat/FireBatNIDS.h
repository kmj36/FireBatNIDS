#pragma once
#include <pcap.h>

class CFireBatNIDS {
private:
	char *m_szDevice;
	char m_szErrBuf[PCAP_ERRBUF_SIZE];
	pcap_t *m_pPcapHandle;
public:
	CFireBatNIDS();
	~CFireBatNIDS();
public:
	
};