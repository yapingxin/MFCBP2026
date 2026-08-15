#pragma once

#include "resource.h"
#include "LibDev/MFCLib/include/MfcExtControls/ColorEdit.h"

#define SELANG_ITEMSCOUNT 4

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
	DECLARE_MESSAGE_MAP()

private:
    CComboBox m_cbSelLang;
    CColorEdit m_VerboseMsg;

    TCHAR  m_SelangItemTxt[SELANG_ITEMSCOUNT][MAX_PATH];
    LANGID m_SelangItemIdx[SELANG_ITEMSCOUNT];
};
