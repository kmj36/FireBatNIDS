// DialogFireBat.cpp: 구현 파일
//

#include "stdafx.h"
#include "FireBat.h"
#include "afxdialogex.h"
#include "DialogFireBat.h"


// CDialogFireBat 대화 상자

IMPLEMENT_DYNAMIC(CDialogFireBat, CDialog)

CDialogFireBat::CDialogFireBat(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_FIREBAT, pParent)
	, m_strDisplay(_T(""))
{

}

CDialogFireBat::~CDialogFireBat()
{
}

void CDialogFireBat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DISPLAY, m_strDisplay);
}


BEGIN_MESSAGE_MAP(CDialogFireBat, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_START, &CDialogFireBat::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CDialogFireBat::OnBnClickedButtonStop)
END_MESSAGE_MAP()


// CDialogFireBat 메시지 처리기


void CDialogFireBat::OnBnClickedButtonStart()
{
	int nResult = m_DlgDevSel.DoModal();
	if (nResult == IDCANCEL)
		return;

	
	int nResult2 = m_DlgRuleSet.DoModal();
	if (nResult2 == IDCANCEL)
		return;
}


void CDialogFireBat::OnBnClickedButtonStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
