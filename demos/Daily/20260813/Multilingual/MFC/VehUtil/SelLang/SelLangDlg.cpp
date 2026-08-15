// SelLang\SelLangDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Main\VehUtil.h"
#include "SelLang\SelLangDlg.h"
#include "afxdialogex.h"

// ======================================================================
// Private (Static) data declaration
// ======================================================================

// ======================================================================
// Functions implementation
// ======================================================================

// CSelLangDlg dialog

IMPLEMENT_DYNAMIC(CSelLangDlg, CDialogEx)

CSelLangDlg::CSelLangDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelLangDlg::IDD, pParent)
{

}

CSelLangDlg::~CSelLangDlg()
{
}

void CSelLangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_LANGS, m_cbSelLang);
    DDX_Control(pDX, IDC_EDIT_MSG, m_VerboseMsg);
}


BEGIN_MESSAGE_MAP(CSelLangDlg, CDialogEx)
    ON_CBN_SELCHANGE(IDC_COMBO_LANGS, OnComboSelchangeLangId)
END_MESSAGE_MAP()


BOOL CSelLangDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    m_VerboseMsg.SetBkColor(BLACK);
    m_VerboseMsg.SetTextColor(LIGHTGREEN);

    CString langItem0;
    langItem0.LoadString(IDS_SEL_LANGID_USER_DEFAULT);
    lstrcpy(m_SelangItemTxt[0],langItem0);

    CString langItem1;
    langItem1.LoadString(IDS_SEL_LANGID_CHINESE_SIMPLIFIED);
    lstrcpy(m_SelangItemTxt[1], langItem1);

    CString langItem2;
    langItem2.LoadString(IDS_SEL_LANGID_ENGLISH_US);
    lstrcpy(m_SelangItemTxt[2], langItem2);

    CString langItem3;
    langItem3.LoadString(IDS_SEL_LANGID_JAPANESE_JAPAN);
    lstrcpy(m_SelangItemTxt[3], langItem3);

    m_cbSelLang.InsertString(0, m_SelangItemTxt[0]);
    m_cbSelLang.InsertString(1, m_SelangItemTxt[1]);
    m_cbSelLang.InsertString(2, m_SelangItemTxt[2]);
    m_cbSelLang.InsertString(3, m_SelangItemTxt[3]);

    m_SelangItemIdx[0] = LANG_USER_DEFAULT;
    m_SelangItemIdx[1] = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_DEFAULT);
    m_SelangItemIdx[2] = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);
    m_SelangItemIdx[3] = MAKELCID(MAKELANGID(LANG_JAPANESE, SUBLANG_JAPANESE_JAPAN), SORT_DEFAULT);

    m_cbSelLang.SetCurSel(0);
    int idxCurLang;
    for(idxCurLang = 0; idxCurLang < SELANG_ITEMSCOUNT; idxCurLang++)
    {
        if (m_SelangItemIdx[idxCurLang] == theApp.m_LangId)
        {
            m_cbSelLang.SetCurSel(idxCurLang);
            break;
        }
    }

    CString strTipsDefault;
    strTipsDefault.LoadString(IDS_LANGSELTIPS_CURRENT);

    _stprintf_s(m_MessageLangTipsCurrent, LogMessageSZ - 1, strTipsDefault, m_SelangItemTxt[idxCurLang]);
    m_VerboseMsg.SetWindowText(m_MessageLangTipsCurrent);

    m_MessageLangTipsFormat_Change.LoadString(IDS_LANGSELTIPS_CHANGE);

    return TRUE;
}

void CSelLangDlg::OnComboSelchangeLangId()
{
    static TCHAR message[LogMessageSZ] = { 0 };

    int selIdx = m_cbSelLang.GetCurSel();
    if (selIdx >= 0 && selIdx < SELANG_ITEMSCOUNT)
    {
        CButton* bnOK = (CButton*)GetDlgItem(IDOK);

        m_SelLangId = m_SelangItemIdx[selIdx];
        if (m_SelLangId != theApp.m_LangId)
        {
            bnOK->EnableWindow(TRUE);

            _stprintf_s(message, LogMessageSZ - 1, m_MessageLangTipsFormat_Change, m_SelangItemTxt[selIdx]);
            m_VerboseMsg.SetWindowText(message);
        }
        else
        {
            bnOK->EnableWindow(FALSE);
            m_VerboseMsg.SetWindowText(m_MessageLangTipsCurrent);
        }
    }
}

void CSelLangDlg::OnOK()
{
    theApp.ChangeDisplayLang(m_SelLangId);

    /*
    int rc = MessageBox(_T("新的界面显示语言设置将在程序重新启动后生效。现在关闭程序吗？"), _T("是否关闭程序"), MB_YESNO | MB_ICONWARNING);
    if (rc == IDYES)
    {
        // ::PostMessage(this->GetSafeHwnd(), WM_CLOSE, 0, 0);
        // theApp.ExitInstance();
    }
    */
    
    CDialogEx::OnOK();
}

// CSelLangDlg message handlers
