/***************************************************************
 * Name:      wxScmNotifierMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Günter Schafranek (gschafra@web.de)
 * Created:   2019-02-23
 * Copyright: Günter Schafranek ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxScmNotifierMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


wxScmNotifierFrame::wxScmNotifierFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

wxScmNotifierFrame::~wxScmNotifierFrame()
{
}

void wxScmNotifierFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wxScmNotifierFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void wxScmNotifierFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
