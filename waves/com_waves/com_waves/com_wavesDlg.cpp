
// com_wavesDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "com_waves.h"
#include "com_wavesDlg.h"
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


// CCom_wavesDlg 对话框



CCom_wavesDlg::CCom_wavesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCom_wavesDlg::IDD, pParent)
	,isworking(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCom_wavesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox_serial_name);
	DDX_Control(pDX, IDC_COMBO2, m_combox_baud_rate);
	DDX_Control(pDX, IDC_COMBO3, m_combox_stop_bit);
	DDX_Control(pDX, IDC_COMBO4, m_combox_parity_bit);
	DDX_Control(pDX, IDC_COMBO5, m_combox_byte_size);
	DDX_Control(pDX, IDC_BUTTON1, m_btn_btn1);
}

BEGIN_MESSAGE_MAP(CCom_wavesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCom_wavesDlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CCom_wavesDlg 消息处理程序

BOOL CCom_wavesDlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCom_wavesDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCom_wavesDlg::OnPaint()
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
HCURSOR CCom_wavesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



bool CCom_wavesDlg::startwork()
{
	

	if (recv_data() == false)
	{
		return false;
	}
	if (parse_data() == false)
	{
		return false;
	}


	return true;
}
bool CCom_wavesDlg::stopwork()
{
	
	return true;
}

bool CCom_wavesDlg::recv_data()
{
	if (get_ctrl_info() == false)
	{
		return false;
	}
	return true;
}

bool CCom_wavesDlg::get_ctrl_info()
{
	return true;
}

void CCom_wavesDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	if (isworking == false)
	{
		if (startwork() == 1)
		{
			isworking == true;
		}
	}
	else
	{
		if (stopwork() == 1)
		{
			isworking == false;
		}
	}
	/*
		判断操作需求 

		1开始工作:

			1收集 控件信息
			2判断端口是否可用
			是：3
			否：4
			3：
				接受数据，处理数据
			4： 
				直接返回
		2停止工作：
			

	*/
	


}


void CCom_wavesDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	// 读取数据并绘图

	CDialogEx::OnTimer(nIDEvent);
}
