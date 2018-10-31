
// com_wavesDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCom_wavesDlg 对话框
class CCom_wavesDlg : public CDialogEx
{
// 构造
public:
	CCom_wavesDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_COM_WAVES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//标志位
	bool isworking;


	bool startwork();
	bool stopwork();
	bool recv_data();
	bool get_ctrl_info();
	bool parse_data();


public:
	afx_msg void OnBnClickedButton1();
	CComboBox m_combox_serial_name;
	CComboBox m_combox_baud_rate;
	CComboBox m_combox_stop_bit;
	CComboBox m_combox_parity_bit;
	CComboBox m_combox_byte_size;
	CButton m_btn_btn1;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
