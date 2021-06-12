//************************************************************************
//************************************************************************
//
// created: June 2021
// How to ..
// use 2 panels (one for controls, one for drawings)
// - manage basic events (so that controls impact drawings)
//
// ... with wxWidgets (3.0.2)\n\nMARTIN Mickael : DUT info AS
    //  pro.martin.mickael@gmail.com

// TULLI Eliot : DUT info AS
    //  eliot.tulli@netcourrier.com"),
//
//
// tested with xWidget 3.0.2 under Linux
// Under Linux, lunch as follows (with g++):
//./MoonDraw.sh
//************************************************************************
//************************************************************************


// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "../vue/headers/MyApp.h"

IMPLEMENT_APP(MyApp) // macro that contains the main() function
