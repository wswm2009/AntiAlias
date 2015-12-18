
// AntiAliasDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AntiAlias.h"
#include "AntiAliasDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAntiAliasDlg 对话框



CAntiAliasDlg::CAntiAliasDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAntiAliasDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAntiAliasDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_CBSize);
	DDX_Control(pDX, IDC_EDIT1, m_EtToler);
}

BEGIN_MESSAGE_MAP(CAntiAliasDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOAD, &CAntiAliasDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ANTIALIAS, &CAntiAliasDlg::OnBnClickedBtnAntialias)
END_MESSAGE_MAP()


// CAntiAliasDlg 消息处理程序

BOOL CAntiAliasDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO:  在此添加额外的初始化代码
	m_CBSize.InsertString(0,L"取样点");
	m_CBSize.InsertString(1,L"1x1");
	m_CBSize.InsertString(2,L"3x3");
	m_CBSize.SetCurSel(0);

	m_EtToler.SetWindowTextW(L"32");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAntiAliasDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAntiAliasDlg::OnPaint()
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
HCURSOR CAntiAliasDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAntiAliasDlg::OnBnClickedBtnLoad()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	
	CFileDialog dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, _T("All File |*.*|Jpeg File(*.jpg;*.jpeg;*.jpe)|*.jpg;*.jpeg;*.jpe|Windows(*.bmp)|*.bmp|CompuServe GIF(*.gif)|*.gif|Png文件(*.png)|*.png||"), this);
	dlg.m_ofn.lpstrTitle = _T("Open Image");

	if (dlg.DoModal() == IDOK)
	{

		CString strPath = dlg.GetPathName();
		SAFE_DELETE(m_pBitmap);
		m_pBitmap = new Bitmap(strPath);
		if (m_pBitmap == NULL)
			return;
		m_AdjustHandler.SetNeedProcessImage(m_pBitmap);
	}
	Clog log(L"C:\\Mylog", L"app", 0, WRITE_MODEL_INALLFILE);
	log.debug(L"debug test kk ll%s;", L"1234");
	log.info(L"223123232");

}


void CAntiAliasDlg::OnBnClickedBtnAntialias()
{
	// TODO:  在此添加控件通知处理程序代码
	
	m_AdjustHandler.AntiAlias();
}
