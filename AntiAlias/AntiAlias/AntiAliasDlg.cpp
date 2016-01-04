
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
	, m_EditX(0)
	, m_EditY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAntiAliasDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_CBSize);
	DDX_Control(pDX, IDC_EDIT1, m_EtToler);
	DDX_Control(pDX, IDC_CHK_CTN, m_ChkCtn);
	DDX_Control(pDX, IDC_CHECK2, m_ClearAlias);
	DDX_Text(pDX,IDC_EDIT2,m_EditX);
	DDX_Text(pDX, IDC_EDIT3, m_EditY);
}

BEGIN_MESSAGE_MAP(CAntiAliasDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOAD, &CAntiAliasDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ANTIALIAS, &CAntiAliasDlg::OnBnClickedBtnAntialias)
	ON_BN_CLICKED(IDC_BTN_SVAE, &CAntiAliasDlg::OnBnClickedBtnSvae)
	ON_BN_CLICKED(IDC_CHK_CTN, &CAntiAliasDlg::OnBnClickedChkCtn)
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
	m_ClearAlias.SetCheck(1);
	m_EtToler.SetWindowText(L"32");

	m_EditX = 0xD2;
	m_EditY = 0x5A;
	UpdateData(FALSE);
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

		CString in_strPath = dlg.GetPathName();
		SAFE_DELETE(m_pBitmap);

		m_pBitmap = new Bitmap(in_strPath);
		if (m_pBitmap == NULL)
			return;
		m_AdjustHandler.SetNeedProcessImage(m_pBitmap);
	}
}


void CAntiAliasDlg::OnBnClickedBtnAntialias()
{
	// TODO:  在此添加控件通知处理程序代码
	if (!m_pBitmap)
	{
		AfxMessageBox(L"请先打开图片再消除锯齿");
	}
	UpdateData();
	m_AdjustHandler.m_Toler = GetDlgItemInt(IDC_EDIT1);
	m_AdjustHandler.m_Ctn = m_ChkCtn.GetCheck();
	m_AdjustHandler.m_Clear = m_ClearAlias.GetCheck();
	m_AdjustHandler.m_Pt.x = m_EditX;
	m_AdjustHandler.m_Pt.y= m_EditY;
	m_AdjustHandler.AntiAlias();
}


void CAntiAliasDlg::OnBnClickedBtnSvae()
{
	// TODO:  在此添加控件通知处理程序代码
	CString defaultDir = _T("C:\\");   //默认打开的文件路径  
	CString fileName = _T("test.bmp");         //默认打开的文件名  
	CString filter = _T("文件 (*.doc; *.ppt; *.xls)|*.doc;*.ppt;*.xls||");   //文件过虑的类
	if (!m_AdjustHandler.m_IsFinish)
	{
		AfxMessageBox(L"请先处理完再保存图片");
		return;
	}
	
	CFileDialog dlg(FALSE, NULL, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("All File |*.*|Jpeg File(*.jpg;*.jpeg;*.jpe)|*.jpg;*.jpeg;*.jpe|Windows(*.bmp)|*.bmp|CompuServe GIF(*.gif)|*.gif|Png文件(*.png)|*.png||"), this);
	dlg.m_ofn.lpstrTitle = L"Save Image";
	if (dlg.DoModal() == IDOK)
	{
		CString strPath = dlg.GetPathName();

		if (m_AdjustHandler.m_pMainBitmap)
		{
			m_AdjustHandler.OnSaveImage(strPath);
		}
		else
		{
			MessageBox(L"请先载入图片再保存");
		}

	}
}


void CAntiAliasDlg::OnBnClickedChkCtn()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_ChkCtn.GetCheck())
	{
		AfxMessageBox(L"勾选连续的情况还未处理");
		m_ChkCtn.SetCheck(BST_UNCHECKED);
	}
}
