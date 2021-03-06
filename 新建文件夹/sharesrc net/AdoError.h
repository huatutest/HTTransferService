// AdoError.h: interface for the CAdoError class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOERROR_H__71A3D400_43F7_4057_AB72_4CA8757808D9__INCLUDED_)
#define AFX_ADOERROR_H__71A3D400_43F7_4057_AB72_4CA8757808D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAString;

class CAdoError  
{
public:
	CAdoError();
	virtual ~CAdoError();
protected:
	ADODB::ErrorPtr	m_ptrError;
public:
	void		SetError(ADODB::ErrorPtr ptrError);
	//==============================================
	// 所产生的错误代码
	//==============================================
	long		GetNumber();
	//==============================================
	// 产生错误的应用时式、或物件的名称
	//==============================================
	CAString		GetSource();
	//==============================================
	// 关于该项错误的描述文字
	//==============================================
	CAString		GetDescription();
	//==============================================
	// 这个主题说明文件路径路径
	//==============================================
	CAString		GetHelpFile();
	//==============================================
	// 这是一个长整数，用来搭配该项说明的主题
	//==============================================
	long		GetHelpContext();
	//==============================================
	// 「提供者」所指定的错误代码
	//==============================================
	long		GetNativeError();
	//==============================================
	// 这个错误产生时的 SQL 执行的状态
	//==============================================
	CAString		GetSQLState();
};

#endif // !defined(AFX_ADOERROR_H__71A3D400_43F7_4057_AB72_4CA8757808D9__INCLUDED_)
