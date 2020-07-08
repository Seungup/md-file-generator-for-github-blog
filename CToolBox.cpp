// CToolBox.cpp: 구현 파일
//

#include "pch.h"
#include "MdFileBuilder.h"
#include "CToolBox.h"
#include "afxdialogex.h"


// CToolBox 대화 상자

IMPLEMENT_DYNAMIC(CToolBox, CDialogEx)

CToolBox::CToolBox(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TOOLBOX_DIALOG, pParent)
{

}

CToolBox::~CToolBox()
{
}

void CToolBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LANG_COMBO, m_LanguageComboBox);
}


BEGIN_MESSAGE_MAP(CToolBox, CDialogEx)
	ON_BN_CLICKED(IDC_ADD_CODE_BUTTON, &CToolBox::OnBnClickedAddCodeButton)
END_MESSAGE_MAP()


// CToolBox 메시지 처리기
void CToolBox::OnBnClickedAddCodeMfcbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

BOOL CToolBox::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	
	m_LanguageComboBox.AddString(L"None");
	m_LanguageComboBox.AddString(L"Python");
	m_LanguageComboBox.AddString(L"C/C++");
	m_LanguageComboBox.AddString(L"Java");
	m_LanguageComboBox.AddString(L"JavaScriptit");
	m_LanguageComboBox.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CToolBox::OnBnClickedAddCodeButton()
{
	CString lang, code;

	m_LanguageComboBox.GetLBText(m_LanguageComboBox.GetCurSel(), lang);
	GetDlgItemText(IDC_INPUT_CODE_EDIT, code);



}
