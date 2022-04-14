#pragma once
#include "afxdialogex.h"
#include "DialogDeviceSelect.h"
#include "DialogRuleSet.h"
#include <vector>


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
	CDialogDeviceSelect m_DlgDevSel;
	// 패킷 탐지 규칙 지정
	CDialogRuleSet m_DlgRuleSet;
	// 화면 표시 문자열
	CString m_strDisplay;
public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
};
