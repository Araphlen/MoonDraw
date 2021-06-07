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

#include "contantes.h"
#include "enum.h"

#include "MyFrame.h"
//------------------------------------------------------------------------
class MyApp: public wxApp
//------------------------------------------------------------------------
{
    virtual bool OnInit() ;
};



#endif //SKELETON_MYAPP_H
