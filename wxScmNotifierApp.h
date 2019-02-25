/***************************************************************
 * Name:      wxScmNotifierApp.h
 * Purpose:   Defines Application Class
 * Author:    Günter Schafranek (gschafra@web.de)
 * Created:   2019-02-23
 * Copyright: Günter Schafranek ()
 * License:
 **************************************************************/

#ifndef WXSCMNOTIFIERAPP_H
#define WXSCMNOTIFIERAPP_H

#include <wx/app.h>

class wxScmNotifierApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WXSCMNOTIFIERAPP_H
