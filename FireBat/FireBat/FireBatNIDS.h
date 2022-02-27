#pragma once
#include <pcap.h>
#define ERROR_UNKNOWN -1
#define ERROR_ALREADY -2
#define ERROR_CANNOT_OPEN_HANDLE -3
#define ERROR_CANNOT_ALLOCATION -4
#define ERROR_STRINGCOPY_FAILED -5
#define ERROR_CANNOT_GET_DEVICE -6
#define ERROR_NULL -7
#define DEVICE_LENGTH 250

class CFireBatNIDS {
private:
	char *m_szDevice;
	char m_szErrBuf[PCAP_ERRBUF_SIZE];
	char m_szLogPath[MAX_PATH];
	char *m_strCurrentRule;
	int m_nLogMode;
	int m_nTimeOut;
	struct bpf_program* m_stcpRuleFilter;
	bpf_u_int32 m_unNetmask;
	pcap_t *m_pPcapHandle;
public:
	CFireBatNIDS(const char* SaveLogpath, const char* Rule);
	~CFireBatNIDS();
public:
	int NIDSStart();
	int NIDSStop();
	int HandleOpen();
	void HandleClose();
	void Handlefunc();
	int SetDevice(const char* szDeviceName);
	int SetDeviceAuto();
	int SaveCurrentRule();
	int LoadRuleofPath(const char* szRulesFilePath);
	int SetRule(const char* szRule);
	void SetLogMode(int nMode);
	char* GetCurrentDevice();
	int GetDeviceList();
	char* GetCurrentRules();
	int GetCurrentLogMode();
};