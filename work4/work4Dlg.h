
// work4Dlg.h: 头文件
//

#pragma once
#pragma comment(lib,"libmySQL.lib")//附加依赖项



// Cwork4Dlg 对话框
class Cwork4Dlg : public CDialogEx
{
// 构造
public:
	Cwork4Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WORK4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	void Cwork4Dlg::SetVisible();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CDateTimeCtrl time1;
	afx_msg void OnBnClickedButton3();
	CDateTimeCtrl time2;
	CListCtrl list1;
	CListCtrl list2;
	afx_msg void OnBnClickedButton7();
	CStatic group2;
	CStatic static1;
	CStatic static2;
	CEdit edit1;
	CStatic static3;
	CStatic static4;
	CEdit edit2;
	CEdit edit3;
	CButton button1;
	CButton button2;
	CButton button3;
	CButton button4;
	CStatic group1;
	CStatic group3;
	CString edit11;
	CString edit22;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CString edit33;
	afx_msg void OnBnClickedButton6();
};
