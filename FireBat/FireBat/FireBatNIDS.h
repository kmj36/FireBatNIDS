#pragma once
#include <pcap.h>

class CFireBatNIDS {
private:
	char *m_szDevice;
	char m_szErrBuf[PCAP_ERRBUF_SIZE];
	char m_szLogPath[MAX_PATH];
	char *m_strRule;
	int m_nLogMode;
	struct bpf_program* m_stcpRuleFilter;
	bpf_u_int32 m_unNetmask;
	pcap_t *m_pPcapHandle;
public:
	CFireBatNIDS(const char* SaveLogpath, const char* Rule);
	~CFireBatNIDS();
public:
	NIDSStart();
	NIDSStop();
	HandleOpen();
	HandleClose();
	SetDevice(const char* szDeviceName);
	SetDeviceAuto();
	LoadRulesofPath(const char* szRulesFilePath);
	SetRule(const char* szRule);
	SetLogMode(int nMode);
	GetCurrentDevice();
	GetCurrentDeviceList();
	GetCurrentRules();
	GetCurrentLogMode();
};