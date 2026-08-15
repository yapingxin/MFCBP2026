// SelLang\SelLangDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Main\VehUtil.h"
#include "SelLang\SelLangDlg.h"
#include "afxdialogex.h"


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

    return TRUE;
}


// CSelLangDlg message handlers
