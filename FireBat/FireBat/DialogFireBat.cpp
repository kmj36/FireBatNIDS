#include "stdafx.h"
#include "FireBat.h"
#include "DialogFireBat.h"

IMPLEMENT_DYNAMIC(CDialogFireBat, CDialog)

CDialogFireBat::CDialogFireBat(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogFireBat::IDD, pParent)
	, m_strDisplay(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CDialogFireBat::~CDialogFireBat()
{
}

void CDialogFireBat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SHOW_RESULT, m_strDisplay);
}

BEGIN_MESSAGE_MAP(CDialogFireBat, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CDialogFireBat::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_SETTING_RULES, &CDialogFireBat::OnBnClickedButtonSettingRules)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE_START, &CDialogFireBat::OnBnClickedButtonCaptureStart)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE_STOP, &CDialogFireBat::OnBnClickedButtonCaptureStop)
END_MESSAGE_MAP()

BOOL CDialogFireBat::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	
	UpdateData(FALSE);
	return TRUE;  
	
}

void CDialogFireBat::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}



void CDialogFireBat::OnBnClickedButtonCaptureStart()
{

}

void CDialogFireBat::OnBnClickedButtonCaptureStop()
{

}

void CDialogFireBat::OnBnClickedButtonSettingRules()
{
	CDialogSetRule Dlg;
	INT nDlgResult = Dlg.DoModal();

	if(nDlgResult == IDOK)
	{
		
	}
}

void CDialogFireBat::OnBnClickedButtonClear()
{

}