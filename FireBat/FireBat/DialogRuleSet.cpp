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
	, m_nSourcePort(0)
	, m_nDestinationPort(0)
	, m_strAnalyzeData(_T(""))
	, m_strFilterRule(_T(""))
{
}

CDialogRuleSet::~CDialogRuleSet()
{
}

void CDialogRuleSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
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
	DDX_Control(pDX, IDC_LIST_RULE_LIST, m_ctrlRuleList);
}


BEGIN_MESSAGE_MAP(CDialogRuleSet, CDialog)
	ON_BN_CLICKED(IDC_CHECK_RULE_SOURCE_ANY_IP, &CDialogRuleSet::OnBnClickedCheckRuleSourceAnyIp)
	ON_BN_CLICKED(IDC_CHECK_RULE_SOURCE_ANY_PORT, &CDialogRuleSet::OnBnClickedCheckRuleSourceAnyPort)
	ON_BN_CLICKED(IDC_CHECK_RULE_DESTINATION_ANY_IP, &CDialogRuleSet::OnBnClickedCheckRuleDestinationAnyIp)
	ON_BN_CLICKED(IDC_CHECK_RULE_DESTINATION_ANY_PORT, &CDialogRuleSet::OnBnClickedCheckRuleDestinationAnyPort)
	ON_BN_CLICKED(IDC_BUTTON_RULE_APPLY, &CDialogRuleSet::OnBnClickedButtonRuleApply)
	ON_BN_CLICKED(IDC_BUTTON_RULE_DELETE, &CDialogRuleSet::OnBnClickedButtonRuleDelete)
	ON_BN_CLICKED(IDOK, &CDialogRuleSet::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_RULE_IMPORT, &CDialogRuleSet::OnBnClickedButtonRuleImport)
	ON_BN_CLICKED(IDC_BUTTON_RULE_EXPORT, &CDialogRuleSet::OnBnClickedButtonRuleExport)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RULE_LIST_CHANGE_NUMBER, &CDialogRuleSet::OnDeltaposSpinRuleListChangeNumber)
	ON_LBN_SELCHANGE(IDC_LIST_RULE_LIST, &CDialogRuleSet::OnLbnSelchangeListRuleList)
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

	if (m_ctrlProtocolComboBox.GetCurSel() == LB_ERR)
		return;

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strRule;
	CString strProtocol, strSrcIp, strSrcPort, strDstIp, strDstPort;
	bool bCheckActive = false;

	m_ctrlProtocolComboBox.GetLBText(m_ctrlProtocolComboBox.GetCurSel(), strProtocol);

	strSrcPort.Format(_T("%u"), m_nSourcePort);
	strDstPort.Format(_T("%u"), m_nDestinationPort);
	GetDlgItemText(IDC_IPADDRESS_RULE_SOURCE_IP, strSrcIp);
	GetDlgItemText(IDC_IPADDRESS_RULE_DESTINATION_IP, strDstIp);

	strRule += strProtocol.MakeLower();

	if (strSrcIp != "0.0.0.0" && !m_ctrlAnySrcIPCheckBox.GetCheck())
	{
		strRule += _T(" src host ") + strSrcIp;
		bCheckActive = true;
	}

	if (strSrcPort != '0' && !m_ctrlAnySrcPortCheckBox.GetCheck())
	{
		if (bCheckActive)
			strRule += _T(" and");
		strRule += _T(" src port ") + strSrcPort;
		bCheckActive = true;
	}

	if (strDstIp != "0.0.0.0" && !m_ctrlAnyDstIPCheckBox.GetCheck())
	{
		if (bCheckActive)
			strRule += _T(" and");
		strRule += _T(" dst host ") + strDstIp;
		bCheckActive = true;
	}

	if (strDstPort != '0' && !m_ctrlAnyDstPortCheckBox.GetCheck())
	{
		if (bCheckActive)
			strRule += _T(" and");
		strRule += _T(" dst port ") + strDstPort;
	}

	if (!m_strAnalyzeData.IsEmpty())
		strRule += _T("->") + m_strAnalyzeData;

	if (m_ctrlRuleList.FindStringExact(-1, strRule) == LB_ERR)
	{
		m_ctrlRuleList.AddString(strRule);
		m_vtAnalyzeDatas.push_back(m_strAnalyzeData);
	}
}


void CDialogRuleSet::OnBnClickedButtonRuleDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nSelectIndex;
	if ((nSelectIndex = m_ctrlRuleList.GetCurSel()) == LB_ERR)
		return;

	m_ctrlRuleList.DeleteString(nSelectIndex);
	if (!m_vtAnalyzeDatas.empty())
		m_vtAnalyzeDatas.erase(m_vtAnalyzeDatas.begin() + nSelectIndex);

	m_ctrlRuleList.SetCurSel(nSelectIndex);
}


void CDialogRuleSet::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnOK();

}


void CDialogRuleSet::OnBnClickedButtonRuleImport()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(true, _T("*.ini"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("INI Files(*.ini)|*.ini|"), NULL);

	if (dlg.DoModal() != IDOK)
		return;

	CString strFilePath;
	CStdioFile fileRule;
	CFileException fileEx;

	strFilePath = dlg.GetPathName();

	if (fileRule.Open(strFilePath, CFile::modeReadWrite, &fileEx))
	{
		CString strReadData;
		CString strAnalyzeData;
		int i = 0;

		m_ctrlRuleList.ResetContent();
		m_vtAnalyzeDatas.clear();

		while (fileRule.ReadString(strReadData))
		{
			int nPos = 0;
			strReadData.Tokenize(_T("->"), nPos);
			strAnalyzeData = strReadData.Tokenize(_T("->"), nPos);

			if (m_ctrlRuleList.FindStringExact(-1, strReadData) == LB_ERR)
			{
				m_ctrlRuleList.InsertString(i, strReadData);
				m_vtAnalyzeDatas.push_back(strAnalyzeData);
				i++;
			}
		}

		fileRule.Close();
		UpdateData(FALSE);
	}
	else
		AfxMessageBox(_T("파일을 열 수 없습니다. 에러 = %d\n"), fileEx.m_cause);
}


void CDialogRuleSet::OnBnClickedButtonRuleExport()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(false, _T("*.ini"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("INI Files(*.ini)|*.ini|"), NULL);

	if (dlg.DoModal() != IDOK)
		return;

	CString strFilePath;
	CStdioFile fileRule;
	CFileException fileEx;

	strFilePath = dlg.GetPathName();

	if (fileRule.Open(strFilePath, CFile::modeCreate | CFile::modeReadWrite, &fileEx))
	{
		UpdateData(TRUE);
		CString strRuleValue;

		for (int i = 0, len = m_ctrlRuleList.GetCount(); i < len; i++)
		{
			m_ctrlRuleList.GetText(i, strRuleValue);
			fileRule.WriteString(strRuleValue + "\n");
		}

		fileRule.Close();
		AfxMessageBox(strFilePath + _T(" 저장되었습니다."));
	}
	else
		AfxMessageBox(_T("파일을 열 수 없습니다. 에러 = %d\n"), fileEx.m_cause);
}


void CDialogRuleSet::OnDeltaposSpinRuleListChangeNumber(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	int nSel = m_ctrlRuleList.GetCurSel();
	int nCount = m_ctrlRuleList.GetCount();

	if (nSel != LB_ERR)
	{
		CString strRuleTemp;
		CString strvtTemp;

		if (nCount == 1)
			return;

		if (pNMUpDown->iDelta < 0)
		{
			if (nSel == 0)
				return;

			m_ctrlRuleList.GetText(nSel, strRuleTemp);
			m_ctrlRuleList.DeleteString(nSel); 
			m_ctrlRuleList.InsertString(nSel - 1, strRuleTemp);

			strvtTemp = m_vtAnalyzeDatas[nSel];
			m_vtAnalyzeDatas[nSel] = m_vtAnalyzeDatas[nSel - 1];
			m_vtAnalyzeDatas[nSel - 1] = strvtTemp;

			m_ctrlRuleList.SetCurSel(nSel - 1);
		}
		else
		{
			if (nSel == nCount - 1)
				return;

			m_ctrlRuleList.GetText(nSel, strRuleTemp);
			m_ctrlRuleList.DeleteString(nSel);
			m_ctrlRuleList.InsertString(nSel + 1, strRuleTemp);

			strvtTemp = m_vtAnalyzeDatas[nSel];
			m_vtAnalyzeDatas[nSel] = m_vtAnalyzeDatas[nSel + 1];
			m_vtAnalyzeDatas[nSel + 1] = strvtTemp;

			m_ctrlRuleList.SetCurSel(nSel + 1);
		}
	}
	*pResult = 0;
}


void CDialogRuleSet::OnLbnSelchangeListRuleList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nSel = m_ctrlRuleList.GetCurSel();
	if (nSel != LB_ERR)
	{
		CString strSelData;

		m_ctrlRuleList.GetText(nSel, strSelData);
		AfxMessageBox(strSelData);
	}
}
