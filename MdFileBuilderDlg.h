#pragma once

class CMdFileBuilderDlg : public CDialogEx
{
public:
	CMdFileBuilderDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MDFILEBUILDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);


protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_Category;
	afx_msg void OnBnClickedShowStrBtn();
	CEdit m_InputDescription;
	CComboBox m_LangComboBox;
	CToolTipCtrl m_tip_ctrl;
	afx_msg void OnBnClickedAddCodeButton();
	afx_msg void OnBnClickedHorizontalButton();
	afx_msg void OnBnClickedLinkButton();
	afx_msg void OnBnClickedCancleLineButton();
	afx_msg void OnBnClickedTiltButton();
	afx_msg void OnBnClickedStrongButton();
	afx_msg void OnBnClickedImgButton();
	afx_msg void OnBnClickedTextheadButton();
	afx_msg void OnBnClickedEnterButton();

public:
	void BuildFile(CString title, CString des, CString category, CString tag);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
