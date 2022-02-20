// DialogFireBat.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FireBat.h"
#include "DialogFireBat.h"


// CDialogFireBat 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDialogFireBat, CDialog)

CDialogFireBat::CDialogFireBat(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogFireBat::IDD, pParent)
	, m_hIDSThread(NULL)
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
	ON_BN_CLICKED(IDC_BUTTON_LOG_SETTING, &CDialogFireBat::OnBnClickedButtonLogSetting)
	ON_MESSAGE(UM_UPDATEDATA, &CDialogFireBat::OnUpdateDataFalse)
END_MESSAGE_MAP()


// CDialogFireBat 메시지 처리기입니다.

BOOL CDialogFireBat::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.	
}

void CDialogFireBat::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}



void CDialogFireBat::OnBnClickedButtonCaptureStart()
{
	if(m_hIDSThread)
	{
		CDialogYesNoBox Dlgyesnobox;
		INT Result = Dlgyesnobox.DoModal();
		return;
	}

	m_hIDSThread = AfxBeginThread((AFX_THREADPROC)TestThreadFunc, this);

	if(!m_hIDSThread)
	{
		AfxMessageBox(_T("스레드를 초기화할 수 없습니다."));
		return;
	}

	m_hIDSThread->m_bAutoDelete = FALSE;
		
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

void CDialogFireBat::OnBnClickedButtonLogSetting()
{
	
}

void CDialogFireBat::OnBnClickedButtonClear()
{

}

LRESULT CDialogFireBat::OnUpdateDataFalse(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	return 0;
}

LRESULT CDialogFireBat::TestThreadFunc(LPVOID pArg)
{
	return 0xDEADBEEF;
}