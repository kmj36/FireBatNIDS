#pragma once

class CDialogSetRule : public CDialog
{
	DECLARE_DYNAMIC(CDialogSetRule)

public:
	CDialogSetRule(CWnd* pParent = NULL);
	virtual ~CDialogSetRule();

	enum { IDD = IDD_DIALOG_SET_RULE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
};
