#pragma once

/************************************************************************/
/* Bitmap�Զ��崦����
	����1��Lock�õ�BYTE����

	ʾ����
	CBitmapUtil  ComBit(m_pResultBitmap);
	BYTE* pData = ComBit.LockToData();

	BYTE������...
	...

	ComBit.UnLockToData();
*/
/************************************************************************/
class CBitmapUtil
{
public:
	CBitmapUtil(void);
	CBitmapUtil(Bitmap* pInputBitmap);
	~CBitmapUtil(void);

//����
	int GetWidth();
	int GetHeight();

	//LockBits�õ�BYTE*����
	BYTE* LockToData();
	void    UnLockToData();




//����
	Bitmap* m_pInputBitmap;
	BitmapData m_pBmpData;

	int	m_nWidth;
	int    m_nHeight;


	
};

