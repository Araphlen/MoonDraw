//
// Created by araphlen on 07/06/2021.
//

#ifndef SKELETON_MYFRAME_H
#define SKELETON_MYFRAME_H
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

#include "MyControlPanel.h"
#include "MyFrame.h"
#include "MyDrawingPanel.h"

//------------------------------------------------------------------------
class MyFrame: public wxFrame
//------------------------------------------------------------------------
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    MyControlPanel* GetControlPanel(){return m_controlPanel ;} ;
    void RefreshDrawing(){m_drawingPanel->Refresh() ;} ;

protected:
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
    void OnSaveFile(wxCommandEvent & WXUNUSED(event)) ;
    void OnClose(wxCloseEvent& event) ;
    void OnSize(wxSizeEvent &event) ;

    MyControlPanel *m_controlPanel; // the panel with controls
    MyDrawingPanel *m_drawingPanel; // the panel in which we draw
} ;


#endif //SKELETON_MYFRAME_H
