
// AntiAliasDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AntiAlias.h"
#include "AntiAliasDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CAntiAliasDlg �Ի���



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
	ON_BN_CLICKED(IDC_BTN_SVAE, &CAntiAliasDlg::OnBnClickedBtnSvae)
END_MESSAGE_MAP()


// CAntiAliasDlg ��Ϣ�������

BOOL CAntiAliasDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_CBSize.InsertString(0,L"ȡ����");
	m_CBSize.InsertString(1,L"1x1");
	m_CBSize.InsertString(2,L"3x3");
	m_CBSize.SetCurSel(0);

	m_EtToler.SetWindowText(L"32");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAntiAliasDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CAntiAliasDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAntiAliasDlg::OnBnClickedBtnLoad()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CFileDialog dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, _T("All File |*.*|Jpeg File(*.jpg;*.jpeg;*.jpe)|*.jpg;*.jpeg;*.jpe|Windows(*.bmp)|*.bmp|CompuServe GIF(*.gif)|*.gif|Png�ļ�(*.png)|*.png||"), this);
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	m_AdjustHandler.AntiAlias();
}


void CAntiAliasDlg::OnBnClickedBtnSvae()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString defaultDir = _T("C:\\");   //Ĭ�ϴ򿪵��ļ�·��  
	CString fileName = _T("test.bmp");         //Ĭ�ϴ򿪵��ļ���  
	CString filter = _T("�ļ� (*.doc; *.ppt; *.xls)|*.doc;*.ppt;*.xls||");   //�ļ����ǵ���
	CFileDialog dlg(FALSE, NULL, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("All File |*.*|Jpeg File(*.jpg;*.jpeg;*.jpe)|*.jpg;*.jpeg;*.jpe|Windows(*.bmp)|*.bmp|CompuServe GIF(*.gif)|*.gif|Png�ļ�(*.png)|*.png||"), this);
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
			MessageBox(L"��������ͼƬ�ٱ���");
		}

	}
}
