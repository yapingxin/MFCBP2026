#pragma once

#include "resource.h"
#include "LibDev/MFCLib/include/MfcExtControls/ColorEdit.h"

#define SELANG_ITEMSCOUNT 4
#define LogMessageSZ 1024

class CSelLangDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelLangDlg)

public:
	CSelLangDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelLangDlg();

	enum { IDD = IDD_SELANG_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();
    virtual void OnOK();
	DECLARE_MESSAGE_MAP()

    afx_msg void OnComboSelchangeLangId();

private:
    CComboBox m_cbSelLang;
    CColorEdit m_VerboseMsg;

    TCHAR  m_SelangItemTxt[SELANG_ITEMSCOUNT][MAX_PATH];
    LANGID m_SelangItemIdx[SELANG_ITEMSCOUNT];
    LANGID m_SelLangId;
    TCHAR m_MessageLangTipsCurrent[LogMessageSZ];
    CString m_MessageLangTipsFormat_Change;
};
