// DialogYesNoBox.cpp : 구현 파일입니다.
// TODO

#include "stdafx.h"
#include "FireBat.h"
#include "DialogYesNoBox.h"


// CDialogYesNoBox 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDialogYesNoBox, CDialog)

CDialogYesNoBox::CDialogYesNoBox(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogYesNoBox::IDD, pParent)
{

}

CDialogYesNoBox::~CDialogYesNoBox()
{
}

void CDialogYesNoBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogYesNoBox, CDialog)
END_MESSAGE_MAP()


// CDialogYesNoBox 메시지 처리기입니다.
