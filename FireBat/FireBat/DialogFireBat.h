#pragma once
#include "DialogSetRule.h"
#include "DialogYesNoBox.h"
#include "FireBatNIDS.h"
#include "afxwin.h"
#define UM_UPDATEDATA (WM_USER+1)

// CDialogFireBat 대화 상자입니다.

class CDialogFireBat : public CDialog
{
	DECLARE_DYNAMIC(CDialogFireBat)

public:
	CDialogFireBat(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDialogFireBat();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_FIREBAT };

protected:
	HICON m_hIcon;
	CWinThread* m_hIDSThread;
	enum ThreadStatus
	{
		RUNNING = 0,
		PAUSE = 1,
		STOP = 2
	};
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 화면에 현재 캡처 상황을 보여주는 문자열
	CString m_strDisplay;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	// 패킷 분석 결과를 출력하는 Edit 컨트롤 문자열 변수
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonSettingRules();
	afx_msg void OnBnClickedButtonCaptureStart();
	afx_msg void OnBnClickedButtonCaptureStop();
	afx_msg void OnBnClickedButtonLogSetting();
	afx_msg LRESULT OnUpdateDataFalse(WPARAM wParam, LPARAM lParam);
	static LRESULT TestThreadFunc(LPVOID pArg);
};
