// DialogSetRule.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FireBat.h"
#include "DialogSetRule.h"


// CDialogSetRule 대화 상자입니다.

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


// CDialogSetRule 메시지 처리기입니다.
