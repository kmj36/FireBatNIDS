// DialogDeviceSelect.cpp: 구현 파일
//

#include "pch.h"
#include "FireBat.h"
#include "afxdialogex.h"
#include "DialogDeviceSelect.h"


// CDialogDeviceSelect 대화 상자

IMPLEMENT_DYNAMIC(CDialogDeviceSelect, CDialog)

CDialogDeviceSelect::CDialogDeviceSelect(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DEVICE_SELECT, pParent)
{

}

CDialogDeviceSelect::~CDialogDeviceSelect()
{
}

void CDialogDeviceSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogDeviceSelect, CDialog)
END_MESSAGE_MAP()


// CDialogDeviceSelect 메시지 처리기
