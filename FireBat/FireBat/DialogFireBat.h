#pragma once
#include "DialogSetRule.h"

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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	// 패킷 분석 결과를 출력하는 Edit 컨트롤 문자열 변수
	CString m_cstrAnalysisResult;
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonSettingRules();
	CDialogSetRule * m_pDlg;
};
