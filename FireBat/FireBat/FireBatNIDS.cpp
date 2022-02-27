#include "stdafx.h"
#include "FireBatNIDS.h"

CFireBatNIDS::CFireBatNIDS(const char* SaveLogpath, const char* Rule):
	m_szDevice(NULL),
	m_pPcapHandle(NULL),
	m_strCurrentRule(NULL),
	m_stcpRuleFilter(NULL),
	m_unNetmask(0),
	m_nTimeOut(1000),
	m_nLogMode(0)
{
	m_szErrBuf[0] = '\0';
	m_szLogPath[0] = '\0';
}

CFireBatNIDS::~CFireBatNIDS()
{

}

int CFireBatNIDS::NIDSStart()
{

}

int CFireBatNIDS::NIDSStop()
{

}

int CFireBatNIDS::HandleOpen()
{
	if (m_pPcapHandle)
		return ERROR_ALREADY;

	m_pPcapHandle = pcap_open_live(m_szDevice, 65536, 1, m_nTimeOut, m_szErrBuf);
	
	if (!m_pPcapHandle)
		return ERROR_CANNOT_OPEN_HANDLE;

	return 0;
}

void CFireBatNIDS::HandleClose()
{
	pcap_close(m_pPcapHandle);
}

void CFireBatNIDS::Handlefunc()
{

}

int CFireBatNIDS::SetDevice(const char* szDeviceName)
{
	if (m_szDevice)
	{
		free(m_szDevice);
		m_szDevice = NULL;
	}

	int len = strnlen_s(szDeviceName, DEVICE_LENGTH);

	if(len)
		m_szDevice = (char*)malloc(sizeof(char) * len);

	if (!m_szDevice)
		return ERROR_CANNOT_ALLOCATION;

	if (strcpy_s(m_szDevice, sizeof(char) * len, szDeviceName))
	{
		m_szDevice = NULL;
		return ERROR_STRINGCOPY_FAILED;
	}

	return 0;
}

int CFireBatNIDS::SetDeviceAuto()
{
	if (m_szDevice)
	{
		free(m_szDevice);
		m_szDevice = NULL;
	}

	int len = strnlen_s(pcap_lookupdev(m_szErrBuf), DEVICE_LENGTH);
	if(len)
		m_szDevice = (char*)malloc(sizeof(char) * len);

	if (!m_szDevice)
		return ERROR_CANNOT_ALLOCATION;

	if (strcpy_s(m_szDevice, sizeof(char) * len, pcap_lookupdev(m_szErrBuf)))
	{
		m_szDevice = NULL;
		return ERROR_CANNOT_GET_DEVICE;
	}

	return 0;
}

int CFireBatNIDS::LoadRuleofPath(const char* szRulesFilePath)
{
	if (!szRulesFilePath)
		return ERROR_UNKNOWN;

	WCHAR lpwszRulePath[MAX_PATH];
	size_t rv = 0;

	if (mbstowcs_s(&rv, lpwszRulePath, MAX_PATH, szRulesFilePath, MAX_PATH) == -1)
		return ERROR_STRINGCOPY_FAILED;

	HANDLE hRuleFile = CreateFile(lpwszRulePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hRuleFile == INVALID_HANDLE_VALUE)
		return ERROR_CANNOT_OPEN_HANDLE;
	
	DWORD dwRead;
	char FileRule[1025];
	if (ReadFile(hRuleFile, FileRule, 1024, &dwRead, NULL))
		return ERROR_UNKNOWN;

	CloseHandle(hRuleFile);
	SetRule(FileRule);

	return 0;
}

int CFireBatNIDS::SetRule(const char* szRule)
{
	if (m_strCurrentRule)
	{
		free(m_strCurrentRule);
		m_strCurrentRule = NULL;
	}

	int len = strnlen_s(szRule, 1024);

	if (len)
		m_strCurrentRule = (char*)malloc(sizeof(char) * len);

	if (!m_strCurrentRule)
		return ERROR_CANNOT_ALLOCATION;

	if (strcpy_s(m_strCurrentRule, sizeof(char) * len, szRule))
	{
		m_strCurrentRule = NULL;
		return ERROR_STRINGCOPY_FAILED;
	}

	return 0;
}

void CFireBatNIDS::SetLogMode(int nMode)
{
	m_nLogMode = nMode;
}

char* CFireBatNIDS::GetCurrentDevice()
{
	return m_szDevice;
}

int CFireBatNIDS::GetDeviceList()
{

}

char* CFireBatNIDS::GetCurrentRules()
{
	return m_strCurrentRule;
}

int CFireBatNIDS::GetCurrentLogMode()
{
	return m_nLogMode;
}