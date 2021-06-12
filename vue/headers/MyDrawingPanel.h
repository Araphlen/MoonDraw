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
#define STATUS_RECTANGLE 1
#define STATUS_CIRCLE 2
#define STATUS_SQUARE 3
#define STATUS_ELLIPSE 4
#define STATUS_POLYGON 5

#define MODE_SELECT 90
#define MODE_DRAW 95
#define MODE_EDIT 99
//------------------------------------------------------------------------
class MyDrawingPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
    MyDrawingPanel( wxWindow *parent ) ;
    void OpenFile(wxString fileName) ;
    void SaveFile(wxString fileName) ;
    void setStatus(int mStatus);
    void setMode(int mMode);
    void setCurrentIndexTempsPoint(int mCurrentIndexTempsPoint);
    void undo();
    void redo();
    std::string getModeSTR();

private:
    void OnMouseMove(wxMouseEvent &event) ;
    void OnMouseLeftDClick(wxMouseEvent &event);
    void OnMouseLeftDown(wxMouseEvent &event) ;
    void OnMouseMiddleDown(wxMouseEvent &event) ;
    void OnMouseLeftUp(wxMouseEvent &event);
    void OnPaint(wxPaintEvent &event) ;
    wxPoint m_onePoint ;
    int m_status;
    Drawing m_drawing;
    std::vector<Point> m_tempPoints;
    int m_currentIndexFigure;
    Figure* m_currentFigure;
    bool m_isdrawing;
    int m_mode;
};




#endif //SKELETON_MYDRAWINGPANEL_H
