#pragma once


// CSelLangDlg dialog

#pragma once

#include "resource.h"

class CSelLangDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelLangDlg)

public:
	CSelLangDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelLangDlg();

	enum { IDD = IDD_SELANG_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
