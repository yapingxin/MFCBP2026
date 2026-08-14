
// MainFrame\VehUtilDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Main\VehUtil.h"
#include "MainFrame\VehUtilDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVehUtilDlg 对话框




CVehUtilDlg::CVehUtilDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVehUtilDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVehUtilDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_OPTMSG, m_VerboseMsg);
}

BEGIN_MESSAGE_MAP(CVehUtilDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_SIZING()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CVehUtilDlg 消息处理程序

BOOL CVehUtilDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_VerboseMsg.SetBkColor(BLACK);
    m_VerboseMsg.SetTextColor(LIGHTGREEN);
    m_VerboseMsg.SetWindowText(_T("载机仿真模型已加载。"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CVehUtilDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 在OnSizing事件中，限定窗口最大和最小的尺寸
void CVehUtilDlg::OnSizing(UINT nSide, LPRECT lpRect)
{
    static int SAV_W = 0;
    static int SAV_H = 0;

    int curWidth = lpRect->right - lpRect->left;
    int curHeight = lpRect->bottom - lpRect->top;

    if (SAV_W == 0 && SAV_H == 0)
    {
	    SAV_W = curWidth;
	    SAV_H = curHeight;
    }

    int MIN__WIDTH = SAV_W;
    int MIN_HEIGHT = SAV_H;
    int MAX__WIDTH = (int)(SAV_W * 1.0);
    int MAX_HEIGHT = (int)(SAV_H * 1.0);

    if (curWidth < MIN__WIDTH)
    {
	    if (nSide == WMSZ_LEFT || nSide == WMSZ_TOPLEFT || nSide == WMSZ_BOTTOMLEFT)
	    {
		    lpRect->left = lpRect->right - MIN__WIDTH;
	    }
	    else
	    {
		    lpRect->right = lpRect->left + MIN__WIDTH;
	    }
    }

    if (curHeight < MIN_HEIGHT)
    {
	    if (nSide == WMSZ_TOP || nSide == WMSZ_TOPLEFT || nSide == WMSZ_TOPRIGHT)
	    {
		    lpRect->top = lpRect->bottom - MIN_HEIGHT;
	    }
	    else
	    {
		    lpRect->bottom = lpRect->top + MIN_HEIGHT;
	    }
    }

    if (curWidth > MAX__WIDTH)
    {
	    if (nSide == WMSZ_LEFT || nSide == WMSZ_TOPLEFT || nSide == WMSZ_BOTTOMLEFT)
	    {
		    lpRect->left = lpRect->right - MAX__WIDTH;
	    }
	    else
	    {
		    lpRect->right = lpRect->left + MAX__WIDTH;
	    }
    }

    if (curHeight > MAX_HEIGHT)
    {
	    if (nSide == WMSZ_TOP || nSide == WMSZ_TOPLEFT || nSide == WMSZ_TOPRIGHT)
	    {
		    lpRect->top = lpRect->bottom - MAX_HEIGHT;
	    }
	    else
	    {
		    lpRect->bottom = lpRect->top + MAX_HEIGHT;
	    }
    }

    CDialogEx::OnSizing(nSide, lpRect);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CVehUtilDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CVehUtilDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

