/***************************************************************
 * Name:      wxScmNotifierApp.cpp
 * Purpose:   Code for Application Class
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

#include "wxScmNotifierApp.h"
#include "wxScmNotifierMain.h"
#include "wx/xrc/xmlres.h"

IMPLEMENT_APP(wxScmNotifierApp);

bool wxScmNotifierApp::OnInit()
{
    wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load("resource.xrc");

    wxScmNotifierFrame* frame = new wxScmNotifierFrame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();

    return true;
}
