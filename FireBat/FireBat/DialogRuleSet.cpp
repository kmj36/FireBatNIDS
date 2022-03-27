// DialogRuleSet.cpp: 구현 파일
//

#include "stdafx.h"
#include "FireBat.h"
#include "afxdialogex.h"
#include "DialogRuleSet.h"


// CDialogRuleSet 대화 상자

IMPLEMENT_DYNAMIC(CDialogRuleSet, CDialog)

CDialogRuleSet::CDialogRuleSet(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_RULE_SET, pParent)
	, m_nRadio(0)
	, m_nSourcePort(0)
	, m_nDestinationPort(0)
	, m_strAnalyzeData(_T(""))
{

}

CDialogRuleSet::~CDialogRuleSet()
{
}

void CDialogRuleSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_RULE_STRING, m_nRadio);
	DDX_Control(pDX, IDC_COMBO_RULE_PROTOCOL_SEL, m_ctrlProtocolComboBox);
	DDX_Control(pDX, IDC_IPADDRESS_RULE_SOURCE_IP, m_ctrlSourceIP);
	DDX_Text(pDX, IDC_EDIT_RULE_SOURCE_PORT, m_nSourcePort);
	DDX_Control(pDX, IDC_IPADDRESS_RULE_DESTINATION_IP, m_ctrlDestinationIP);
	DDX_Text(pDX, IDC_EDIT_RULE_DESTINATION_PORT, m_nDestinationPort);
	DDX_Control(pDX, IDC_CHECK_RULE_SOURCE_ANY_IP, m_ctrlAnySrcIPCheckBox);
	DDX_Control(pDX, IDC_CHECK_RULE_SOURCE_ANY_PORT, m_ctrlAnySrcPortCheckBox);
	DDX_Control(pDX, IDC_CHECK_RULE_DESTINATION_ANY_IP, m_ctrlAnyDstIPCheckBox);
	DDX_Control(pDX, IDC_CHECK_RULE_DESTINATION_ANY_PORT, m_ctrlAnyDstPortCheckBox);
	DDV_MinMaxInt(pDX, IDC_EDIT_RULE_SOURCE_PORT, 0, USHORT_MAX);
	DDV_MinMaxInt(pDX, IDC_EDIT_RULE_DESTINATION_PORT, 0, USHORT_MAX);
	DDX_Text(pDX, IDC_EDIT_RULE_ANALYZE_VALUE, m_strAnalyzeData);
}


BEGIN_MESSAGE_MAP(CDialogRuleSet, CDialog)
	ON_BN_CLICKED(IDC_CHECK_RULE_SOURCE_ANY_IP, &CDialogRuleSet::OnBnClickedCheckRuleSourceAnyIp)
	ON_BN_CLICKED(IDC_CHECK_RULE_SOURCE_ANY_PORT, &CDialogRuleSet::OnBnClickedCheckRuleSourceAnyPort)
	ON_BN_CLICKED(IDC_CHECK_RULE_DESTINATION_ANY_IP, &CDialogRuleSet::OnBnClickedCheckRuleDestinationAnyIp)
	ON_BN_CLICKED(IDC_CHECK_RULE_DESTINATION_ANY_PORT, &CDialogRuleSet::OnBnClickedCheckRuleDestinationAnyPort)
	ON_BN_CLICKED(IDC_BUTTON_RULE_APPLY, &CDialogRuleSet::OnBnClickedButtonRuleApply)
	ON_BN_CLICKED(IDC_BUTTON_RULE_DELETE, &CDialogRuleSet::OnBnClickedButtonRuleDelete)
END_MESSAGE_MAP()


// CDialogRuleSet 메시지 처리기


BOOL CDialogRuleSet::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctrlProtocolComboBox.AddString(_T("TCP"));
	m_ctrlProtocolComboBox.AddString(_T("UDP"));
	m_ctrlProtocolComboBox.AddString(_T("ICMP"));
	m_ctrlProtocolComboBox.AddString(_T("ARP"));
	m_ctrlProtocolComboBox.SetCurSel(0);

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDialogRuleSet::OnBnClickedCheckRuleSourceAnyIp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_ctrlAnySrcIPCheckBox.GetCheck())
		m_ctrlSourceIP.EnableWindow(FALSE);
	else
		m_ctrlSourceIP.EnableWindow(TRUE);
}


void CDialogRuleSet::OnBnClickedCheckRuleSourceAnyPort()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_ctrlAnySrcPortCheckBox.GetCheck())
		GetDlgItem(IDC_EDIT_RULE_SOURCE_PORT)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_EDIT_RULE_SOURCE_PORT)->EnableWindow(TRUE);
}


void CDialogRuleSet::OnBnClickedCheckRuleDestinationAnyIp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_ctrlAnyDstIPCheckBox.GetCheck())
		m_ctrlDestinationIP.EnableWindow(FALSE);
	else
		m_ctrlDestinationIP.EnableWindow(TRUE);
}


void CDialogRuleSet::OnBnClickedCheckRuleDestinationAnyPort()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_ctrlAnyDstPortCheckBox.GetCheck())
		GetDlgItem(IDC_EDIT_RULE_DESTINATION_PORT)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_EDIT_RULE_DESTINATION_PORT)->EnableWindow(TRUE);
}

void CDialogRuleSet::OnBnClickedButtonRuleApply()
{ 
	UpdateData(TRUE);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strProtocol, strSrcIp, strSrcPort, strDstIp, strDstPort, strRadio;
	if (m_ctrlProtocolComboBox.GetCurSel() != LB_ERR)
		m_ctrlProtocolComboBox.GetLBText(m_ctrlProtocolComboBox.GetCurSel(), strProtocol);

	GetDlgItemText(IDC_IPADDRESS_RULE_SOURCE_IP, strSrcIp);
	strSrcPort.Format(_T("%u"), m_nSourcePort);
	GetDlgItemText(IDC_IPADDRESS_RULE_DESTINATION_IP, strDstIp);
	strDstPort.Format(_T("%u"), m_nDestinationPort);
	strRadio.Format(_T("%d"), m_nRadio);

	AfxMessageBox(strProtocol);

	if (m_ctrlAnySrcIPCheckBox.GetCheck())
		AfxMessageBox(_T("ALL"));
	else
		AfxMessageBox(strSrcIp);

	if (m_ctrlAnySrcPortCheckBox.GetCheck())
		AfxMessageBox(_T("ALL"));
	else
		AfxMessageBox(strSrcPort);

	if (m_ctrlAnyDstIPCheckBox.GetCheck())
		AfxMessageBox(_T("ALL"));
	else
		AfxMessageBox(strDstIp);

	if (m_ctrlAnyDstPortCheckBox.GetCheck())
		AfxMessageBox(_T("ALL"));
	else
		AfxMessageBox(strDstPort);

	AfxMessageBox(strRadio);
	AfxMessageBox(m_strAnalyzeData);
}


void CDialogRuleSet::OnBnClickedButtonRuleDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}
