#ifndef WXSCMNOTIFIERFRAME_H_
#define WXSCMNOTIFIERFRAME_H_

#include "wxScmNotifierApp.h"

#include <wx/frame.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/frame.h>

#define idMenuQuit 1000
#define idMenuAbout 1001

class wxScmNotifierFrame: public wxFrame
{
public:
	wxScmNotifierFrame(wxWindow* parent=(wxWindow *)NULL);
	virtual ~wxScmNotifierFrame();

private:
    virtual void OnClose(wxCloseEvent& event);
    virtual void OnExit(wxCommandEvent& event);
    virtual void OnAbout(wxCommandEvent& event);

    // Any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();
};

#endif /* WXSCMNOTIFIERFRAME_H_ */
