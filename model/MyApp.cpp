//
// Created by araphlen on 07/06/2021.
//

#include "headers/MyApp.h"

//------------------------------------------------------------------------
bool MyApp::OnInit()
//------------------------------------------------------------------------
{
    MyFrame *frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH,APPLICATION_HEIGHT)) ;
    frame->Show(true) ;
    SetTopWindow(frame) ;
    return true ;
}
