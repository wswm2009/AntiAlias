
// AntiAlias.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAntiAliasApp: 
// �йش����ʵ�֣������ AntiAlias.cpp
//

class CAntiAliasApp : public CWinApp
{
public:
	CAntiAliasApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAntiAliasApp theApp;