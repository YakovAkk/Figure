// cs_go.h : main header file for the CS_GO application
//

#if !defined(AFX_CS_GO_H__9F1A0E87_0F64_4B9A_B559_9CCBF37BFA0E__INCLUDED_)
#define AFX_CS_GO_H__9F1A0E87_0F64_4B9A_B559_9CCBF37BFA0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCs_goApp:
// See cs_go.cpp for the implementation of this class
//

class CCs_goApp : public CWinApp
{
public:
	CCs_goApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCs_goApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCs_goApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CS_GO_H__9F1A0E87_0F64_4B9A_B559_9CCBF37BFA0E__INCLUDED_)
