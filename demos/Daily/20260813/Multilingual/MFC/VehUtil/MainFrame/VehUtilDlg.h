
// MainFrame\VehUtilDlg.h : 头文件
//

#pragma once


// CVehUtilDlg 对话框
class CVehUtilDlg : public CDialogEx
{
// 构造
public:
	CVehUtilDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_VEHUTIL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	virtual afx_msg void OnSizing(UINT nSide, LPRECT lpRect);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
