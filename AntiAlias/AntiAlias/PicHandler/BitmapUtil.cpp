#pragma once
#include "StdAfx.h"
#include "BitmapUtil.h"


CBitmapUtil::CBitmapUtil(void)
{
	m_pInputBitmap = NULL;
	m_nWidth = 0;
	m_nHeight = 0;
}
CBitmapUtil::CBitmapUtil(Bitmap* pInputBitmap)
{
	if(pInputBitmap)
	{
		m_pInputBitmap = pInputBitmap;

		m_nWidth = m_pInputBitmap->GetWidth();
		m_nHeight = m_pInputBitmap->GetHeight();
	}
}

CBitmapUtil::~CBitmapUtil(void)
{
	m_pInputBitmap = NULL;
}



int CBitmapUtil::GetWidth()
{
	return m_nWidth;
}
int CBitmapUtil::GetHeight()
{
	return m_nHeight;
}
//LockBits得到BYTE*数据
BYTE* CBitmapUtil::LockToData()
{
	if(m_nWidth == 0 || m_nHeight == 0)
		return NULL;

	Rect rc(0,0,m_nWidth,m_nHeight);

	m_pInputBitmap->LockBits(&rc,ImageLockModeRead|ImageLockModeWrite, PixelFormat32bppARGB,&m_pBmpData);

	return (BYTE*)m_pBmpData.Scan0;

}
void CBitmapUtil::UnLockToData()
{
	if(m_pInputBitmap)
		m_pInputBitmap->UnlockBits(&m_pBmpData);
}