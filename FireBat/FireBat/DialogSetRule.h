#pragma once


// CDialogSetRule 대화 상자입니다.

class CDialogSetRule : public CDialog
{
	DECLARE_DYNAMIC(CDialogSetRule)

public:
	CDialogSetRule(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDialogSetRule();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_SET_RULE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
