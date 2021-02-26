// cs_goDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cs_go.h"
#include "cs_goDlg.h"
#include "headfile.h"
#include <fstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;
	    int i,size,*size2,countMax,x,y;
		
		Point *lp_point ;


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCs_goDlg dialog

CCs_goDlg::CCs_goDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCs_goDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCs_goDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCs_goDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCs_goDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCs_goDlg, CDialog)
	//{{AFX_MSG_MAP(CCs_goDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCs_goDlg message handlers

BOOL CCs_goDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCs_goDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCs_goDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		using namespace std;
			CPaintDC dc(this);
		CPen pen(PS_SOLID,1,RGB(200,5,0)); 

		HWND f_hWnd=::GetActiveWindow();

			
	/*	int i,size,*countMax,x,y;
		countMax = new int;
		*countMax=0;
		Point *lp_point ;*/
		
		ifstream input("File_Point.txt");
		char ch;
		if (input.is_open()){
			while(input>>ch)
				if (ch == '=')
					countMax++;

				input.clear();
				input.seekg(0);
				size = countMax;
				countMax =size/2;

				lp_point = new Point [countMax];

					if (!lp_point) {
					//printf error terminate
	
					}

					for (i=0;i<countMax; i++){
						input.ignore(1000,'=');
						input >> lp_point[i].x;
						input.ignore(1000,'=');
						input >> lp_point[i].y;
					
					}
					input.close();
		
					for (i=0;i<countMax; i++){
					 x=lp_point[i].x;
					 y=lp_point[i].y;
					}
					
		}
	size2=new int;

	*size2 = countMax;
	size = countMax+1;
		
     
int *lpi_TWO_pointCounter = new int [size+2];
		 
	 //1st
 DrawFigure(dc,lp_point,size2,lpi_TWO_pointCounter);
		CorrectDraw( dc,lp_point,size2,lpi_TWO_pointCounter);
		diagonally(dc, f_hWnd,lpi_TWO_pointCounter, size,lp_point);
		
		
		
	
	// 	dc.Arc(10,10,200,200, 10,10, 10, 10);
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCs_goDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCs_goDlg::OnButton3() 
{

    CPaintDC dc(this);
	int *lpi_TWO_pointCounter = new int [size+2];
	CorrectDraw( dc,lp_point,size2,lpi_TWO_pointCounter);
	Invalidate();
	

	// TODO: Add your control notification handler code here
	
}

void CCs_goDlg::OnButton2() 
{
	
	



	// TODO: Add your control notification handler code here
	
}

void CCs_goDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CCs_goDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
