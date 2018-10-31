
// com_wavesDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCom_wavesDlg �Ի���
class CCom_wavesDlg : public CDialogEx
{
// ����
public:
	CCom_wavesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_COM_WAVES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//��־λ
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
