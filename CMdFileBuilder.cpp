
// mdFileBuilder.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "mdFileBuilder.h"
#include "mdFileBuilderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmdFileBuilderApp

BEGIN_MESSAGE_MAP(CmdFileBuilderApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CmdFileBuilderApp 생성

CmdFileBuilderApp::CmdFileBuilderApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CmdFileBuilderApp 개체입니다.

CmdFileBuilderApp theApp;


// CmdFileBuilderApp 초기화

BOOL CmdFileBuilderApp::InitInstance()
{
	CWinApp::InitInstance();

	CmdFileBuilderDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

