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
#include <wx/clrpicker.h>
#include <vector>
#include "../../model/headers/Drawing.h"
#include "../../model/headers/Point.h"

#define WIDGET_PANEL_WIDTH	200
#define STATUS_DEFAULT 0
#define STATUS_RECTANGLE 1
#define STATUS_CIRCLE 2
#define STATUS_SQUARE 3
#define STATUS_ELLIPSE 4

//------------------------------------------------------------------------
class MyDrawingPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
    MyDrawingPanel( wxWindow *parent ) ;
    void OpenFile(wxString fileName) ;
    void SaveFile(wxString fileName) ;
    void setStatus(int mStatus);
    void setMCurrentIndexTempsPoint(int mCurrentIndexTempsPoint);

private:
    void OnMouseMove(wxMouseEvent &event) ;
    void OnMouseLeftDown(wxMouseEvent &event) ;
    void OnMouseLeftUp(wxMouseEvent &event);
    void OnPaint(wxPaintEvent &event) ;
    wxPoint m_mousePoint ;
    wxPoint m_onePoint ;
    int m_status;
    Drawing m_drawing;
    std::vector<Point> m_tempPoints;
    int m_currentIndexFigure;
    Figure* m_currentFigure;
    bool m_isdrawing;
};




#endif //SKELETON_MYDRAWINGPANEL_H
