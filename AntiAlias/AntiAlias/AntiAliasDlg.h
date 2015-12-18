
// AntiAliasDlg.h : 头文件
//

#pragma once

#include "PicHandler/AdjustImgHandler.h"
#include "afxwin.h"
// CAntiAliasDlg 对话框
class CAntiAliasDlg : public CDialogEx
{
// 构造
public:
	CAntiAliasDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ANTIALIAS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	CAdjustImgHandler m_AdjustHandler;
	Bitmap* m_pBitmap;
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
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnAntialias();
protected:
	CComboBox m_CBSize;
public:
	CEdit m_EtToler;
};
