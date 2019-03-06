#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxScmNotifierFrame.h"

#include <wx/msgdlg.h>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat const format)
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


//-----------------------------------------------------------------------------
// Event table: connect the events to the handler functions to process them
//-----------------------------------------------------------------------------

// The event tables connect the wxWidgets events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
// The reason why the menuitems and tools are given the same name in the
// XRC file, is that both a tool (a toolbar item) and a menuitem are designed
// to fire the same kind of event (an EVT_MENU) and thus I give them the same
// ID name to help new users emphasize this point which is often overlooked
// when starting out with wxWidgets.
wxBEGIN_EVENT_TABLE(wxScmNotifierFrame, wxFrame)
	EVT_MENU(wxID_EXIT,  wxScmNotifierFrame::OnExit)
    EVT_MENU(wxID_ABOUT, wxScmNotifierFrame::OnAbout)
wxEND_EVENT_TABLE()

wxScmNotifierFrame::wxScmNotifierFrame(wxWindow* parent)
{
    // Load up this frame from XRC. [Note, instead of making a class's
    // constructor take a wxWindow* parent with a default value of NULL,
    // we could have just had designed MyFrame class with an empty
    // constructor and then written here:
    // wxXmlResource::Get()->LoadFrame(this, (wxWindow* )NULL, "main_frame");
    // since this frame will always be the top window, and thus parentless.
    // However, the current approach has source code that can be recycled
    // for other frames that aren't the top level window.]
    wxXmlResource::Get()->LoadFrame(this, parent, "main_frame");

#if wxUSE_STATUSBAR
    // statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    // statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif

    // As we have created the toolbar and status bar after loading the main
    // frame from resources, we need to readjust its minimal size to fit both
    // its client area contains and the bars.
    GetSizer()->SetSizeHints(this);
}

wxScmNotifierFrame::~wxScmNotifierFrame()
{
}

void wxScmNotifierFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wxScmNotifierFrame::OnExit(wxCommandEvent &event)
{
    // true is to force the frame to close.
    Close(true);
}

void wxScmNotifierFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

