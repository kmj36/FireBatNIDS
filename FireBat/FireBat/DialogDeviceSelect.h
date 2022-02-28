#pragma once
#include "afxdialogex.h"


// CDialogDeviceSelect 대화 상자

class CDialogDeviceSelect : public CDialog
{
	DECLARE_DYNAMIC(CDialogDeviceSelect)

public:
	CDialogDeviceSelect(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDialogDeviceSelect();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DEVICE_SELECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
