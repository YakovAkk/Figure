// cs_goDlg.h : header file
//

#if !defined(AFX_CS_GODLG_H__65178518_B366_4F0B_8742_B17869FF2E70__INCLUDED_)
#define AFX_CS_GODLG_H__65178518_B366_4F0B_8742_B17869FF2E70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCs_goDlg dialog

class CCs_goDlg : public CDialog
{
// Construction
public:
	CCs_goDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCs_goDlg)
	enum { IDD = IDD_CS_GO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCs_goDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCs_goDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton3();
	afx_msg void OnButton2();
	virtual void OnCancel();
	virtual void OnOK();
	//afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CS_GODLG_H__65178518_B366_4F0B_8742_B17869FF2E70__INCLUDED_)
