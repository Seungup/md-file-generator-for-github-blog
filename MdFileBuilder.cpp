
// MdFileBuilder.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "MdFileBuilder.h"
#include "MdFileBuilderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMdFileBuilderApp

BEGIN_MESSAGE_MAP(CMdFileBuilderApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMdFileBuilderApp 생성

CMdFileBuilderApp::CMdFileBuilderApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CMdFileBuilderApp 개체입니다.

CMdFileBuilderApp theApp;


// CMdFileBuilderApp 초기화

BOOL CMdFileBuilderApp::InitInstance()
{
	CWinApp::InitInstance();

	CMdFileBuilderDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

