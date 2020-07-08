
// MdFileBuilderDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MdFileBuilder.h"
#include "MdFileBuilderDlg.h"
#include "CToolBox.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



CMdFileBuilderDlg::CMdFileBuilderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MDFILEBUILDER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMdFileBuilderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CATEGORY_COMBO, m_Category);
	DDX_Control(pDX, IDC_INPUT_DESCRIPTION_EDIT, m_InputDescription);
	DDX_Control(pDX, IDC_LANG_COMBO2, m_LangComboBox);
}

BEGIN_MESSAGE_MAP(CMdFileBuilderDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_STR_BTN, &CMdFileBuilderDlg::OnBnClickedShowStrBtn)
	ON_BN_CLICKED(IDC_ADD_CODE_BUTTON, &CMdFileBuilderDlg::OnBnClickedAddCodeButton)
	ON_BN_CLICKED(IDC_HORIZONTAL_BUTTON, &CMdFileBuilderDlg::OnBnClickedHorizontalButton)
	ON_BN_CLICKED(IDC_LINK_BUTTON, &CMdFileBuilderDlg::OnBnClickedLinkButton)
	ON_BN_CLICKED(IDC_CANCLE_LINE_BUTTON, &CMdFileBuilderDlg::OnBnClickedCancleLineButton)
	ON_BN_CLICKED(IDC_TILT_BUTTON, &CMdFileBuilderDlg::OnBnClickedTiltButton)
	ON_BN_CLICKED(IDC_STRONG_BUTTON, &CMdFileBuilderDlg::OnBnClickedStrongButton)
	ON_BN_CLICKED(IDC_IMG_BUTTON, &CMdFileBuilderDlg::OnBnClickedImgButton)
	ON_BN_CLICKED(IDC_TEXTHEAD_BUTTON, &CMdFileBuilderDlg::OnBnClickedTextheadButton)
	ON_BN_CLICKED(IDC_ENTER_BUTTON, &CMdFileBuilderDlg::OnBnClickedEnterButton)
END_MESSAGE_MAP()


BOOL CMdFileBuilderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	// 카테고리 콤보박스 초기화
	m_Category.AddString(_T("Other"));
	m_Category.AddString(_T("Study"));
	m_Category.AddString(_T("Project"));
	m_Category.SetCurSel(0);

	// 언어 콤포박스 초기화
	m_LangComboBox.AddString(L"None");
	m_LangComboBox.AddString(L"Python");
	m_LangComboBox.AddString(L"C");
	m_LangComboBox.AddString(L"C++");
	m_LangComboBox.AddString(L"Java");
	m_LangComboBox.AddString(L"JavaScript");
	m_LangComboBox.SetCurSel(0);

	// 툴팁 초기화
	m_tip_ctrl.Create(this);
	m_tip_ctrl.AddTool(GetDlgItem(IDC_TAGS_EDIT), _T("태그를 입력해주세요, 공백으로 구분합니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_ADD_CODE_BUTTON), _T("코드를 삽입할 수 있는 행을 추가합니다."));

	m_tip_ctrl.AddTool(GetDlgItem(IDC_HORIZONTAL_BUTTON), _T("수평선을 삽입합니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_LINK_BUTTON), _T("하이퍼링크를 삽입합니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_CANCLE_LINE_BUTTON), _T("취소선을 삽입합니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_TILT_BUTTON), _T("기울임체를 삽입합니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_STRONG_BUTTON), _T("굵은 폰드를 가진 텍스트를 삽입합니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_IMG_BUTTON), _T("이미지를 삽입합니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_TEXTHEAD_BUTTON), _T("순서가 없는 형식을 추가합니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_ENTER_BUTTON), _T("한칸를 띄웁니다."));
	m_tip_ctrl.AddTool(GetDlgItem(IDC_SHOW_STR_BTN), _T("파일을 생성합니다."));

	m_InputDescription.LineScroll(m_InputDescription.GetLineCount());
	return TRUE;
}


void CMdFileBuilderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMdFileBuilderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMdFileBuilderDlg::OnBnClickedShowStrBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString title, category, tags, des;
	// Get Title
	GetDlgItemText(IDC_INPUT_TITLE_EDIT, title);
	GetDlgItemText(IDC_TAGS_EDIT, tags);
	GetDlgItemText(IDC_INPUT_TITLE_EDIT, des);
	// Get Category
	m_Category.GetLBText(m_Category.GetCurSel(), category);

	if (title.GetLength()) {
		if (tags.GetLength()) {
			if (des.GetLength()) {
				BuildFile(title, des, category, tags);
			}
			else
			{
				MessageBox(L"본문이 비어있습니다.");
			}
		}
		else
		{
			MessageBox(L"태그가 비어있습니다.");
		}
	}
	else {
		MessageBox(L"제목이 비어있습니다.");
	}
}


void CMdFileBuilderDlg::OnBnClickedAddCodeButton()
{
	CString lang;
	m_LangComboBox.GetLBText(m_LangComboBox.GetCurSel(), lang);

	

	m_InputDescription.SetSel(-2, -1);
	m_InputDescription.ReplaceSel(L"\r\n```" + lang.MakeLower()+"\r\n\r\n\r\n"+ L"```");
}


void CMdFileBuilderDlg::OnBnClickedHorizontalButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_InputDescription.SetSel(-2, -1);
	m_InputDescription.ReplaceSel(L"\r\n* * *\r\n");
}


void CMdFileBuilderDlg::OnBnClickedLinkButton()
{
	m_InputDescription.ReplaceSel(L"[title](https://)");
}


void CMdFileBuilderDlg::OnBnClickedCancleLineButton()
{
	m_InputDescription.ReplaceSel(L"~~canceline~~");
}


void CMdFileBuilderDlg::OnBnClickedTiltButton()
{
	m_InputDescription.ReplaceSel(L"*tilt text*");
}


void CMdFileBuilderDlg::OnBnClickedStrongButton()
{
	m_InputDescription.ReplaceSel(L"**strong text**");
}


void CMdFileBuilderDlg::OnBnClickedImgButton()
{
	m_InputDescription.ReplaceSel(L"\r\n![Alt Text](/img/sample.jpg \"Optional Title\")\r\n");
}


void CMdFileBuilderDlg::OnBnClickedTextheadButton()
{
	m_InputDescription.ReplaceSel(L"* 1단계\r\n");
	m_InputDescription.ReplaceSel(L"   - 2단계\r\n");
	m_InputDescription.ReplaceSel(L"      + 3단계\r\n");
}


void CMdFileBuilderDlg::OnBnClickedEnterButton()
{
	m_InputDescription.SetSel(-2, -1);
	m_InputDescription.ReplaceSel(L"   \r\n");
}

void CMdFileBuilderDlg::BuildFile(CString title, CString des, CString category, CString tag)
{
	time_t now = time(NULL);
	struct tm pLocal;
	localtime_s(&pLocal, &now);

	CString pszYear(std::to_string(pLocal.tm_year + 1900).c_str());
	CString pszMon(std::to_string(pLocal.tm_mon + 1).c_str());
	CString pszDay(std::to_string(pLocal.tm_mday).c_str());
	CString pszHour(std::to_string(pLocal.tm_hour).c_str());
	CString pszMin(std::to_string(pLocal.tm_hour).c_str());
	CString pszSec(std::to_string(pLocal.tm_sec).c_str());

	// 들어갈 수 없는 캐릭터 제거
	CString tempTitle = title;
	tempTitle.Remove('\\');
	tempTitle.Remove('?');
	tempTitle.Remove('|');
	tempTitle.Remove(':');
	tempTitle.Remove('"');
	tempTitle.Remove('<');
	tempTitle.Remove('>');

	// 공백은 언더바로 치환
	tempTitle.Replace(' ', '_');

	CString lpzDate = pszYear + "-" + pszMon + "-" + pszDay;
	CString lpzTime = pszHour + ":" + pszMin + ":" + pszSec;

	CString fname = lpzDate + "-" + tempTitle + "-post.md";



	CString lpzInitHori, lpzInitTitle, lpzInitDate, lpzInitCategory, lpzInitTags;

	lpzInitHori = "---\n";
	lpzInitTitle.Format(_T("title: %s\n"), title);
	lpzInitDate.Format(_T("date: %s %s\n"), lpzDate, lpzTime);
	lpzInitCategory.Format(_T("categories: %s\n"), category);
	lpzInitTags.Format(_T("tags: %s\n"), tag);

	try
	{
		CFile file;

		file.Open(fname, CFile::modeCreate | CFile::modeWrite, NULL);

		// init md file
		file.Write(lpzInitHori, lpzInitHori.GetLength() * sizeof(TCHAR));
		file.Write(lpzInitTitle, lpzInitTitle.GetLength() * sizeof(TCHAR));
		file.Write(lpzInitDate, lpzInitDate.GetLength() * sizeof(TCHAR));
		file.Write(lpzInitCategory, lpzInitCategory.GetLength() * sizeof(TCHAR));
		file.Write(lpzInitTags, lpzInitTags.GetLength() * sizeof(TCHAR));
		file.Write(lpzInitHori, lpzInitHori.GetLength() * sizeof(TCHAR));

		// write description
		file.Write(des, des.GetLength() * sizeof(TCHAR));
		file.Close();
		MessageBox(fname + " was created.");
	}
	catch (const std::exception&)
	{
		MessageBox(L"Error");
	}
}



BOOL CMdFileBuilderDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_tip_ctrl.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}
