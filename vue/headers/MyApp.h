//
// Created by araphlen on 07/06/2021.
//

#ifndef SKELETON_MYAPP_H
#define SKELETON_MYAPP_H
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "MyFrame.h"

#define APPLICATION_WIDTH	1080
#define APPLICATION_HEIGHT	720


//------------------------------------------------------------------------
class MyApp: public wxApp
//------------------------------------------------------------------------
{
    virtual bool OnInit() ;
};



#endif //SKELETON_MYAPP_H
