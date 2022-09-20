#pragma once
#include "afxdialogex.h"
#include "DialogDeviceSelect.h"
#include "DialogRuleSet.h"

// CDialogFireBat 대화 상자

class CDialogFireBat : public CDialog
{
	DECLARE_DYNAMIC(CDialogFireBat)

public:
	CDialogFireBat(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDialogFireBat();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FIREBAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 네트워크 인터페이스 디바이스 지정
	CDialogDeviceSelect *m_DlgDevSel;
	// 패킷 탐지 규칙 지정
	CDialogRuleSet *m_DlgRuleSet;
	// 패킷 파일 저장 위치 컨트롤
	CFileDialog *m_DlgPcapFile;
	// 패킷 로그 출력 리스트 컨트롤
	CListCtrl m_ctrlListLogText;
	// 패킷 출력 인덱스
	UINT m_index;
	// 상태표시줄
	CStatic m_ctrlStaticStateText;
public:
	// 패킷 캡처 핸들
	pcap_t* m_hPcap;
	// 패킷 캡처 핸들러
	static void packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);
	// 캡처 에러 버퍼
	char m_lpszErrbuf[PCAP_ERRBUF_SIZE];
	// 필터 구조체
	struct bpf_program m_fcode;
	// 패킷 덤프 파일
	pcap_dumper_t* m_dumpfile;
	// 패킷 파일 저장 위치
	CString strSavePath;
public:
	// 캡처 스레드 함수
	static UINT CaptureThreadFunc(LPVOID lpParam);
	// 캡처 스레드 클래스
	CWinThread * m_pThread;
	// 크리티컬 섹션
	CCriticalSection m_CS;
	// 스레드 제어 변수
	int m_ThreadStatus;
	// 스레드 상태
	enum Status {
		THREAD_RUNNING,
		THREAD_PAUSE,
		THREAD_STOP
	};
public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonPause();
	virtual BOOL OnInitDialog();
};
