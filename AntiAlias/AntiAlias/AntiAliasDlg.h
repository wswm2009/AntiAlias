
// AntiAliasDlg.h : ͷ�ļ�
//

#pragma once

#include "PicHandler/AdjustImgHandler.h"
#include "afxwin.h"
// CAntiAliasDlg �Ի���
class CAntiAliasDlg : public CDialogEx
{
// ����
public:
	CAntiAliasDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ANTIALIAS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


	CAdjustImgHandler m_AdjustHandler;
	Bitmap* m_pBitmap;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	afx_msg void OnBnClickedBtnSvae();
};
