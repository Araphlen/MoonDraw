//
// Created by araphlen on 07/06/2021.
//

#ifndef SKELETON_MYDRAWINGPANEL_H
#define SKELETON_MYDRAWINGPANEL_H
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
class MyDrawingPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
    MyDrawingPanel( wxWindow *parent ) ;
    void OpenFile(wxString fileName) ;
    void SaveFile(wxString fileName) ;

private:
    void OnMouseMove(wxMouseEvent &event) ;
    void OnMouseLeftDown(wxMouseEvent &event) ;
    void OnMouseLeftUp(wxMouseEvent &event);
    void OnPaint(wxPaintEvent &event) ;
    wxPoint m_mousePoint ;
    wxPoint m_onePoint ;
};




#endif //SKELETON_MYDRAWINGPANEL_H
