#pragma once

/************************************************************************/
/* Bitmap自定义处理类
	功能1：Lock得到BYTE数据

	示例：
	CBitmapUtil  ComBit(m_pResultBitmap);
	BYTE* pData = ComBit.LockToData();

	BYTE流处理...
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

//操作
	int GetWidth();
	int GetHeight();

	//LockBits得到BYTE*数据
	BYTE* LockToData();
	void    UnLockToData();




//属性
	Bitmap* m_pInputBitmap;
	BitmapData m_pBmpData;

	int	m_nWidth;
	int    m_nHeight;


	
};

