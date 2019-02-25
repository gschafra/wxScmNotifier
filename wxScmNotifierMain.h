/***************************************************************
 * Name:      wxScmNotifierMain.h
 * Purpose:   Defines Application Frame
 * Author:    Günter Schafranek (gschafra@web.de)
 * Created:   2019-02-23
 * Copyright: Günter Schafranek ()
 * License:
 **************************************************************/

#ifndef WXSCMNOTIFIERMAIN_H
#define WXSCMNOTIFIERMAIN_H



#include "wxScmNotifierApp.h"


#include "GUIFrame.h"

class wxScmNotifierFrame: public GUIFrame
{
    public:
        wxScmNotifierFrame(wxFrame *frame);
        ~wxScmNotifierFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // WXSCMNOTIFIERMAIN_H
