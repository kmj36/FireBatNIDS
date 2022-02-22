#pragma once

class CDialogYesNoBox : public CDialog
{
	DECLARE_DYNAMIC(CDialogYesNoBox)

public:
	CDialogYesNoBox(LPCTSTR strSetTitle, LPCTSTR strSetText, CWnd* pParent = NULL);
	virtual ~CDialogYesNoBox();

	enum { IDD = IDD_DIALOG_YESNOBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMainText;
};
