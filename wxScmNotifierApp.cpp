#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxScmNotifierApp.h"

#include "wx/xrc/xmlres.h"
#include "wx/msgdlg.h"
#include "wxScmNotifierFrame.h"

IMPLEMENT_APP(wxScmNotifierApp)

bool wxScmNotifierApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	// Initialize all the XRC handlers. Always required (unless you feel like
	// going through and initializing a handler of each control type you will
	// be using (ie initialize the spinctrl handler, initialize the textctrl
	// handler). However, if you are only using a few control types, it will
	// save some space to only initialize the ones you will be using. See
	// wxXRC docs for details.
	wxXmlResource::Get()->InitAllHandlers();

	// Load main frame resource
	boolean const bRet = wxXmlResource::Get()->Load("resource.xrc");

	if (!bRet)
	{
		wxMessageBox(wxT("Error loading resource"));
		return false;
	}

	// Make an instance of your derived frame. Passing NULL (the default value
	// of MyFrame's constructor is NULL) as the frame doesn't have a parent
	// since it is the main application window.
	wxScmNotifierFrame *frame = new wxScmNotifierFrame();

	// Show the frame as it's created initially hidden.
	frame->Show(true);

	// Return true to tell program to continue (false would terminate).
	return true;
}
