
#include "stdafx.h"
#include "FireBat.h"
#include "DialogSetRule.h"

IMPLEMENT_DYNAMIC(CDialogSetRule, CDialog)

CDialogSetRule::CDialogSetRule(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSetRule::IDD, pParent)
{

}

CDialogSetRule::~CDialogSetRule()
{
}

void CDialogSetRule::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogSetRule, CDialog)
END_MESSAGE_MAP()