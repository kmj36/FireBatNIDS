// DialogFireBat.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FireBat.h"
#include "DialogFireBat.h"


// CDialogFireBat 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDialogFireBat, CDialog)

CDialogFireBat::CDialogFireBat(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogFireBat::IDD, pParent)
{

}

CDialogFireBat::~CDialogFireBat()
{
}

void CDialogFireBat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogFireBat, CDialog)
END_MESSAGE_MAP()


// CDialogFireBat 메시지 처리기입니다.
