#pragma once


// CToolBox 대화 상자

class CToolBox : public CDialogEx
{
	DECLARE_DYNAMIC(CToolBox)

public:
	CToolBox(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CToolBox();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOOLBOX_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddCodeMfcbutton();
	CComboBox m_LanguageComboBox;

private:
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddCodeButton();
};
