#include "stdafx.h"
#include "FireBat.h"
#include "DialogYesNoBox.h"

IMPLEMENT_DYNAMIC(CDialogYesNoBox, CDialog)

CDialogYesNoBox::CDialogYesNoBox(LPCTSTR strSetTitle, LPCTSTR strSetText, CWnd* pParent /*=NULL*/)
	: CDialog(CDialogYesNoBox::IDD, pParent)
	, m_strMainText(_T(""))
{
	SetWindowText(strSetTitle);
	m_strMainText = strSetText;
	UpdateData(FALSE);
}

CDialogYesNoBox::~CDialogYesNoBox()
{
}

void CDialogYesNoBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_YESNO, m_strMainText);
}


BEGIN_MESSAGE_MAP(CDialogYesNoBox, CDialog)
END_MESSAGE_MAP()
