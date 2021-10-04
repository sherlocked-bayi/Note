
// work4Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "work4.h"
#include "work4Dlg.h"
#include "afxdialogex.h"
#include <afxpriv.h>
#include "winsock2.h"//数据库是通过网络连接的，必须要包含网络相关头文件
#include "mysql.h"//mysql头文件

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cwork4Dlg 对话框



Cwork4Dlg::Cwork4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WORK4_DIALOG, pParent)
	, edit11(_T(""))
	, edit22(_T(""))
	, edit33(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cwork4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, time1);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, time2);
	DDX_Control(pDX, IDC_LIST1, list1);
	DDX_Control(pDX, IDC_LIST2, list2);
	DDX_Control(pDX, IDC_STATIC3, group2);
	DDX_Control(pDX, IDC_STATIC1, static1);
	DDX_Control(pDX, IDC_STATIC2, static2);
	DDX_Control(pDX, IDC_EDIT1, edit1);
	DDX_Control(pDX, IDC_STATIC4, static3);
	DDX_Control(pDX, IDC_STATIC5, static4);
	DDX_Control(pDX, IDC_EDIT2, edit2);
	DDX_Control(pDX, IDC_EDIT3, edit3);
	DDX_Control(pDX, IDC_BUTTON4, button1);
	DDX_Control(pDX, IDC_BUTTON2, button2);
	DDX_Control(pDX, IDC_BUTTON5, button3);
	DDX_Control(pDX, IDC_BUTTON6, button4);
	DDX_Control(pDX, IDC_STATIC10, group1);
	DDX_Control(pDX, IDC_STATIC11, group3);
	DDX_Text(pDX, IDC_EDIT1, edit11);
	DDX_Text(pDX, IDC_EDIT2, edit22);
	DDX_Text(pDX, IDC_EDIT3, edit33);
}

BEGIN_MESSAGE_MAP(Cwork4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cwork4Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cwork4Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cwork4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &Cwork4Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &Cwork4Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cwork4Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cwork4Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// Cwork4Dlg 消息处理程序

BOOL Cwork4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码.
	list1.SetExtendedStyle(list1.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	list2.SetExtendedStyle(list2.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	CRect rect;
	list1.GetClientRect(&rect);
	list1.InsertColumn(1, _T("ID"), LVCFMT_CENTER, rect.Width() / 4, 1);
	list1.InsertColumn(2, _T("日期"), LVCFMT_CENTER, rect.Width() / 4, 1);
	list1.InsertColumn(3, _T("内容"), LVCFMT_CENTER, rect.Width() / 2, 2);
	list2.GetClientRect(&rect);
	list2.InsertColumn(1, _T("ID"), LVCFMT_CENTER, rect.Width() / 4, 1);
	list2.InsertColumn(2, _T("日期"), LVCFMT_CENTER, rect.Width() / 4, 1);
	list2.InsertColumn(3, _T("内容"), LVCFMT_CENTER, rect.Width() / 2, 2);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cwork4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cwork4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cwork4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

MYSQL m_sqlCon;
MYSQL_RES *res;
MYSQL_ROW row;

void Cwork4Dlg::SetVisible() {//设置所有控件不可见
	group1.ShowWindow(FALSE);
	static1.ShowWindow(FALSE);
	static2.ShowWindow(FALSE);
	edit1.ShowWindow(FALSE);
	button1.ShowWindow(FALSE);
	time1.ShowWindow(FALSE);
	group2.ShowWindow(FALSE);
	static3.ShowWindow(FALSE);
	static4.ShowWindow(FALSE);
	edit2.ShowWindow(FALSE);
	edit3.ShowWindow(FALSE);
	button2.ShowWindow(FALSE);
	button3.ShowWindow(FALSE);
	button4.ShowWindow(FALSE);
	time2.ShowWindow(FALSE);
	list1.ShowWindow(FALSE);
	group3.ShowWindow(FALSE);
	list2.ShowWindow(FALSE);
}

void Cwork4Dlg::OnBnClickedButton1()//新建标签
{
	SetVisible();
	edit11 = "";
	group1.ShowWindow(TRUE);
	static1.ShowWindow(TRUE);
	static2.ShowWindow(TRUE);
	edit1.ShowWindow(TRUE);	
	button1.ShowWindow(TRUE);
	time1.ShowWindow(TRUE);
	UpdateData(FALSE);
}


void Cwork4Dlg::OnBnClickedButton2()//查询
{
	// TODO: 在此添加控件通知处理程序代码
	mysql_init(&m_sqlCon);//初始化数据库对象
	mysql_real_connect(&m_sqlCon, "localhost", "root", "123456", "note", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");//设置数据库字符格式，解决中文乱码问题
	list1.DeleteAllItems();
    UpdateData(true);
	CString search;
	CTime tm;
	time2.GetTime(tm);
	CString date = tm.Format("%Y-%m-%d");//获取时间
	search.Format(_T("SELECT * FROM note WHERE 日期='%s' AND 内容 LIKE '%%%s%%';"), date, edit22); //sql操作语句，按时间和便签内容查询数据
	USES_CONVERSION;
	LPCSTR lpstr = (LPCSTR)T2A(search);
	mysql_query(&m_sqlCon, lpstr);
	res = mysql_store_result(&m_sqlCon);//得到存储结果集 
	int listrow = 0;
	while (row = mysql_fetch_row(res))//重复读取行，把数据放入list1中，直到row为NULL ，显示查询到的数据
	{
		CString str;
		str.Format(L"%d", (int)listrow + 1);
		list1.InsertItem(listrow, str);//添加第一列便签数据
		for (int rols = 0; rols < 2; rols++)
		{
			CString myreaddata(row[rols]);
			list1.SetItemText(listrow, rols + 1, myreaddata);
		}
		listrow++;
	}
	mysql_close(&m_sqlCon);//关闭Mysql连接
}


void Cwork4Dlg::OnBnClickedButton3()//查询便签
{
	SetVisible();
	edit22 = "";
	group2.ShowWindow(TRUE);
	static3.ShowWindow(TRUE);
	static4.ShowWindow(TRUE);
	edit2.ShowWindow(TRUE);
	button2.ShowWindow(TRUE);
	time2.ShowWindow(TRUE);
	list1.ShowWindow(TRUE);
	list1.DeleteAllItems();
	UpdateData(FALSE);
}



void Cwork4Dlg::OnBnClickedButton7()//显示便签
{
	// TODO: 在此添加控件通知处理程序代码3
	SetVisible();
	edit33 = "";
	UpdateData(FALSE);
	list2.DeleteAllItems();
	edit3.ShowWindow(TRUE);
	button3.ShowWindow(TRUE);
	button4.ShowWindow(TRUE);
	group3.ShowWindow(TRUE);
	list2.ShowWindow(TRUE);
	mysql_init(&m_sqlCon);//初始化数据库对象
	mysql_real_connect(&m_sqlCon, "localhost", "root", "123456", "note", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");//设置数据库字符格式，解决中文乱码问题
	if (mysql_real_query(&m_sqlCon, "SELECT * FROM note", (unsigned long)strlen("SELECT * FROM note")))// 查询数据库中的note表 ，把所有数据显示出来
	{
		return;
	}
	res = mysql_store_result(&m_sqlCon);//得到存储结果集 
	if (NULL == res)//如果为空则返回
	{
		return;
	}
	int listrow = 0;
	while (row = mysql_fetch_row(res))//重复读取行，把数据放入list2中，直到row为NULL 
	{
		CString str;
		str.Format(L"%d", (int)listrow+1);
		list2.InsertItem(listrow, str);//添加第一列便签数据
		for (int rols = 0; rols < 2; rols++)
		{
			CString myreaddata(row[rols]);
			list2.SetItemText(listrow, rols+1, myreaddata);
		}
		listrow++;
	}
	mysql_close(&m_sqlCon);//关闭Mysql连接
}


void Cwork4Dlg::OnBnClickedButton4()//保存便签
{
	// TODO: 在此添加控件通知处理程序代码
	mysql_init(&m_sqlCon);//初始化数据库对象
	mysql_real_connect(&m_sqlCon, "localhost", "root", "123456", "note", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");//设置数据库字符格式，解决中文乱码问题
	CString insert;
	CTime tm;
	time1.GetTime(tm);
	CString date = tm.Format("%Y-%m-%d");//获取时间
	UpdateData(true);
	if (edit11 == "") {
		AfxMessageBox(_T("请输入内容!"));
	}
	else {
		insert.Format(_T( "INSERT INTO note.note values('%s', '%s');"), date, edit11); //sql操作语句，插入数据
		USES_CONVERSION;
		LPCSTR lpstr = (LPCSTR)T2A(insert);
		if (mysql_query(&m_sqlCon, lpstr) == 0)
		{
			MessageBox(_T("保存成功!"));
		}
		else {
			AfxMessageBox(_T("保存失败!"));
		}
	}	
	mysql_close(&m_sqlCon);//关闭Mysql连接
}


void Cwork4Dlg::OnBnClickedButton5()//修改,通过选中listctrl中的一行进行修改
{
	// TODO: 在此添加控件通知处理程序代码
	mysql_init(&m_sqlCon);//初始化数据库对象
	mysql_real_connect(&m_sqlCon, "localhost", "root", "123456", "note", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");//设置数据库字符格式，解决中文乱码问题
	CString search;
	UpdateData(true);
	int count;//获取选中行
	int i;
	for (i = 0; i < list2.GetItemCount(); i++)//选中listctrl中的一行数据，获取选中行
	{
		if (list2.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			count = i;
			break;
		}
	}
	if (i == list2.GetItemCount()) {//判断是否选择了listctrl中的数据
		AfxMessageBox(_T("你未选择任何数据!"));
	}
	else if (edit33 == "") {
		AfxMessageBox(_T("请输入修改的内容!"));
	}
	else {
		CString content = list2.GetItemText(count, 2);//获取选中行的第三列的数据，通过这个数据确定我要修改的数据库内容
		search.Format(_T("UPDATE note SET 内容='%s' WHERE 内容='%s';"), edit33, content); //sql操作语句，修改数据库中的数据
		USES_CONVERSION;
		LPCSTR lpstr = (LPCSTR)T2A(search);
		if (mysql_query(&m_sqlCon, lpstr) == 0)
		{
			MessageBox(_T("修改成功!"));
		}
		else {
			AfxMessageBox(_T("修改失败!"));
		}
	}
	mysql_close(&m_sqlCon);//关闭Mysql连接
}


void Cwork4Dlg::OnBnClickedButton6()//删除,通过选中listctrl中的一行进行删除
{
	// TODO: 在此添加控件通知处理程序代码
	mysql_init(&m_sqlCon);//初始化数据库对象
	mysql_real_connect(&m_sqlCon, "localhost", "root", "123456", "note", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");//设置数据库字符格式，解决中文
	CString search;
	int count;//获取选中行
	int i;
	for (i = 0; i < list2.GetItemCount(); i++)//选中listctrl中的一行数据，获取选中行
	{
		if (list2.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			count = i;
			break;
		}
	}
	if (i == list2.GetItemCount()) {//判断是否选择了listctrl中的数据
		AfxMessageBox(_T("你未选择任何数据!"));
	}
	else {	
		list2.DeleteItem(count);
		CString content = list2.GetItemText(count, 2);//获取选中行的第三列的数据，通过这个数据确定我要删除的数据库内容
		search.Format(_T("DELETE FROM note WHERE 内容='%s';"), content); //sql操作语句，删除数据库中的数据
		USES_CONVERSION;
		LPCSTR lpstr = (LPCSTR)T2A(search);
		if (mysql_query(&m_sqlCon, lpstr) == 0)
		{
			MessageBox(_T("删除成功!"));
		}
		else
		{
			AfxMessageBox(_T("删除失败!"));
		}
	}
	mysql_close(&m_sqlCon);//关闭Mysql连接
}
