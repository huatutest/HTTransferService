// VirtualMemFile.cpp: implementation of the CVirtualMemFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VirtualMemFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVirtualMemFile::CVirtualMemFile()
{
	m_btContent = NULL;
	m_nCurrentPointer = 0;
	m_nEndPointer = 0;
	m_nAutoGrow = FALSE;
	m_nTotalMemory = 0;
	//yl20120112�޸�����ò���ظ���
	//m_btContent = NULL;
}

CVirtualMemFile::CVirtualMemFile(int nMemorySize)
{	
	if (nMemorySize > 0)
	{
		m_btContent = new BYTE[nMemorySize];
		memset(m_btContent, 0, nMemorySize);
	}
	else
	{
		m_btContent = NULL;
	}
	m_nCurrentPointer = 0;
	m_nEndPointer = 0;
	//�Զ������ڴ�
	m_nAutoGrow = TRUE;
	m_nTotalMemory = nMemorySize;
}

CVirtualMemFile::~CVirtualMemFile()
{
	if (m_btContent)
	{
		delete[] m_btContent;
	}
}

BOOL CVirtualMemFile::AttachMem(LPBYTE btData,int nSize)
{
	if (nSize <= 0)
		return FALSE;
	if (m_btContent)
	{
		delete[] m_btContent;
		m_btContent = NULL;
	}
	
	m_nCurrentPointer = 0;
	m_nEndPointer = 0;
	m_nTotalMemory = 0;

	m_btContent = new BYTE[nSize];
	memset(m_btContent, 0, nSize);
	if (NULL == m_btContent)
		return FALSE;

	memcpy(m_btContent, btData, nSize);
	m_nTotalMemory = nSize;

	return TRUE;
}

LPBYTE CVirtualMemFile::DetachMem()
{
	//���������DetachMem�������������
	//������ڴ�й¶-------------------yl 20120112����ע��
	LPBYTE bt = m_btContent;
	m_btContent = NULL;
	return bt;
}

//////////////////////////////////////////////////////////////////////////
//����:[in]LPVOID lpData,��m_currentPointer��д��dwDataSize���ֽ�		//
//����:[in]dwDataSize��д����ֽ���										//
//ע��:���ڴ治��ʱ�Զ��������ڴ����ڴ�								//
//	  Ϊ(m_nCurrentPointer + dwDataSize) * 2							//
//////////////////////////////////////////////////////////////////////////
BOOL CVirtualMemFile::WriteData(LPVOID lpData, int dwDataSize)
{
	//�ڴ治��
	if (m_nCurrentPointer + dwDataSize > m_nTotalMemory)
	{
		if (m_nAutoGrow)
		{
			//�Զ������ڴ�
			LPBYTE btNewContent = new BYTE[(m_nCurrentPointer + dwDataSize) * 2];
			memset(btNewContent, 0, (m_nCurrentPointer + dwDataSize) * 2);

			memcpy(btNewContent, m_btContent, m_nCurrentPointer);
			delete[] m_btContent;
			m_btContent = btNewContent;
			
			m_nTotalMemory = (m_nCurrentPointer + dwDataSize) * 2;
		}
		else
		{
			return FALSE;
		}
	}	
	
	memcpy(m_btContent + m_nCurrentPointer, lpData, dwDataSize);
	m_nCurrentPointer += dwDataSize;

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//����:[out]LPVOID lpData,��ȡ�����ݴ�������buffer					//
//����:[in]dwDataSize,��ȡ���ֽ���										//
//ע��:�ú����Ὣm_CurrentPointer������ԭ��λ�ú���dwDataSize			//
//////////////////////////////////////////////////////////////////////////
BOOL CVirtualMemFile::ReadData(LPVOID lpData, int dwDataSize)
{
	if (m_nCurrentPointer + dwDataSize > m_nTotalMemory)
		return FALSE;

	memcpy(lpData, m_btContent + m_nCurrentPointer, dwDataSize);
	m_nCurrentPointer += dwDataSize;

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//����:[in]int offset,m_CurrentPointerƫ����							//
//����:[in]int Mode,ΪFILE_BEGIN��FILE_CURRENT��FILE_END				//
//ע��:����mode����m_currentPointer										//
//////////////////////////////////////////////////////////////////////////
DWORD CVirtualMemFile::Seek(int offset, int Mode)
{
	switch(Mode)
	{
		//�ļ���ʼ��
	case FILE_BEGIN:
		{
			if (offset >= m_nTotalMemory)
			{
				m_nCurrentPointer = m_nTotalMemory;
			}
			else
			{
				m_nCurrentPointer = offset;
			}
		}
		break;
		//�ļ���ǰָ��
	case FILE_CURRENT:
		{
			if (m_nCurrentPointer + offset >= m_nTotalMemory)
			{
				m_nCurrentPointer = m_nTotalMemory;
			}
			else
			{
				m_nCurrentPointer += offset;
			}
		}
		break;
		//�ļ�β��
	case FILE_END:
		{
			if (offset >= 0)
			{
				m_nCurrentPointer = m_nTotalMemory;
			}
			else
			{
				m_nCurrentPointer = m_nTotalMemory + offset;
			}
		}
		break;
	}
	return m_nCurrentPointer;
}

//////////////////////////////////////////////////////////////////////////
//Parameter:[in]LPTSTR strData,д����ַ���								//
//Return:BOOL ����ֵ����TRUE											//
//Note:��д���ַ���Ϊ��ʱ����0д�룻��д���ַ������ȣ���д���ַ���		//
//////////////////////////////////////////////////////////////////////////
BOOL CVirtualMemFile::WriteString(LPTSTR strData)
{
	int Length = 0;
	if (strData == NULL)
	{
		WriteData(&Length, sizeof(int));
		return TRUE;
	}
	
	Length = _tcslen(strData);
	WriteData(&Length, sizeof(int));
	if (Length == 0)
		return TRUE;
	WriteData(strData, sizeof(TCHAR) * Length);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//Parameter:[in]LPTSTR strData,д����ַ���								//
//Return:BOOL ����ֵ����TRUE											//
//Note:��д���ַ���Ϊ��ʱ����0д�룻��д���ַ������ȣ���д���ַ���		//
//////////////////////////////////////////////////////////////////////////
BOOL CVirtualMemFile::WriteStringW(LPTSTR strData)
{
	USES_CONVERSION;
	int Length = 0;
	if (strData == NULL)
	{
		WriteData(&Length, sizeof(int));
		return TRUE;
	}
	
	Length = _tcslen(strData);
	WriteData(&Length, sizeof(int));
	if (Length == 0)
		return TRUE;
	WriteData(T2W(strData), sizeof(WCHAR)*Length);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//Parameter:															//
//Return:LPTSTR������ȡ�ĳ���Ϊ��ʱ������NULL							//
//Note:��д���ַ���Ϊ��ʱ����0д�룻��д���ַ������ȣ���д���ַ���		//
//////////////////////////////////////////////////////////////////////////
LPTSTR CVirtualMemFile::ReadString()
{
	int Length = 0;
	ReadData(&Length, sizeof(int));

	if (Length == 0)
		return NULL;
	LPTSTR strData = new TCHAR[Length+1];
	memset(strData, 0, (Length + 1) * sizeof(TCHAR));
	
	ReadData(strData, sizeof(TCHAR)*Length);
	
	return strData;
}

//////////////////////////////////////////////////////////////////////////
//Parameter:															//
//Return:LPTSTR������ȡ�ĳ���Ϊ��ʱ������NULL							//
//Note:��д���ַ���Ϊ��ʱ����0д�룻��д���ַ������ȣ���д���ַ���		//
//////////////////////////////////////////////////////////////////////////
LPWSTR CVirtualMemFile::ReadStringW()
{
	int Length = 0;
	ReadData(&Length,sizeof(int));

	if (Length == 0)
		return NULL;
	LPWSTR strData = new WCHAR[Length + 1];
	memset(strData, 0, (Length + 1) * sizeof(WCHAR));
	
	ReadData(strData, sizeof(WCHAR) * Length);
	
	return strData;
}

//////////////////////////////////////////////////////////////////////////
//Parameter:															//
//Return:int,m_nCurrentPointer											//
//Note:																	//
//////////////////////////////////////////////////////////////////////////
int CVirtualMemFile::GetDataSize()
{
	return m_nCurrentPointer;
}

/************************************************************************/
/* ����m_btContent                                                      */
/************************************************************************/
LPBYTE CVirtualMemFile::GetData()
{
	return m_btContent;
}