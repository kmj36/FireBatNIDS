#pragma once
#include "DialogSetRule.h"
#include "DialogYesNoBox.h"
#include "FireBatNIDS.h"
#include "afxwin.h"
#define UM_UPDATEDATA (WM_USER+1)

class CDialogFireBat : public CDialog
{
	DECLARE_DYNAMIC(CDialogFireBat)

public:
	CDialogFireBat(CWnd* pParent = NULL);
	virtual ~CDialogFireBat();

	enum { IDD = IDD_DIALOG_FIREBAT };

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
public:
	CString m_strDisplay;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonSettingRules();
	afx_msg void OnBnClickedButtonCaptureStart();
	afx_msg void OnBnClickedButtonCaptureStop();
};
