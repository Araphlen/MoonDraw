//
// Created by araphlen on 07/06/2021.
//

#include <langinfo.h>
#include "headers/MyDrawingPanel.h"

#include "headers/MyFrame.h"
#include "../model/headers/Ellipse.h"
#include "../model/headers/Polygon.h"
#include <iostream>
#include <expat.h>

#define RECT_SHAPE 1
#define CIRCLE_SHAPE 2
#define ELLIPSE_SHAPE 3
#define POLYGONE_SHAPE 4


//************************************************************************
//************************************************************************
// MyDrawingPanel class (where drawings are displayed)
//************************************************************************
//************************************************************************

//------------------------------------------------------------------------
MyDrawingPanel::MyDrawingPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, bind some mouse events and the paint event with the appropriate methods
{
    int w, h ;
    GetParent()->GetClientSize(&w,&h) ;
    SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
    SetBackgroundColour(wxColour(0xFF,0xFF,0xFF)) ;
    Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
    Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
    Bind(wxEVT_LEFT_DCLICK, &MyDrawingPanel::OnMouseLeftDClick,this);
    Bind(wxEVT_LEFT_UP, &MyDrawingPanel::OnMouseLeftUp,this);
    Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;
    m_onePoint.x = (w-WIDGET_PANEL_WIDTH)/2 ;
    m_onePoint.y = h/2 ;
    m_mousePoint = m_onePoint ;
    m_status = STATUS_EDIT;
    m_drawing = Drawing();
    m_currentIndexFigure=0;
    m_isdrawing =false;
    }


void MyDrawingPanel::OnMouseLeftDClick(wxMouseEvent &event) {
    switch (m_status) {
        case STATUS_POLYGON:
            if (m_isdrawing) {
                m_currentIndexFigure++;
                m_isdrawing = false;
                Refresh();
            }
            break;
    }
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
    MyFrame* frame = (MyFrame*)GetParent();

    wxString penColorWxString=frame->GetControlPanel()->GetPenColour().GetAsString(wxC2S_HTML_SYNTAX);
    std::string penColorStr= penColorWxString.ToStdString();
    unsigned char penSize = frame->GetControlPanel()->GetPenSliderValue();

    bool isTransparent = frame->GetControlPanel()->GetCheckBoxValue() ;

    wxString brushColorWxString;
    if (isTransparent)
    {
        brushColorWxString=wxTRANSPARENT_BRUSH->GetColour().GetAsString(wxC2S_HTML_SYNTAX);
    } else{
        brushColorWxString=frame->GetControlPanel()->GetBrushColour().GetAsString(wxC2S_HTML_SYNTAX);
    }
    std::string brushColorStr= brushColorWxString.ToStdString();


    switch (m_status) {
        case STATUS_EDIT :
            Refresh() ; // send an event that calls the OnPaint method
            break;
        case STATUS_RECTANGLE:
            if (m_isdrawing==false) {
                m_drawing.addFigure(new Rectangle(Point(event.m_x, event.m_y), 0, 0,penColorStr,brushColorStr,penSize));
                m_isdrawing = true;
                m_currentFigure = m_drawing[m_currentIndexFigure];
                Refresh();
            }
            break;
        case STATUS_CIRCLE:
            if (m_isdrawing== false){
                m_drawing.addFigure(new Circle(Point(event.m_x, event.m_y), 0,penColorStr,brushColorStr,penSize));
                m_isdrawing =true;
                m_currentFigure = m_drawing[m_currentIndexFigure];
                Refresh();
            }
            break;
        case STATUS_SQUARE:
            if (m_isdrawing== false){
                m_drawing.addFigure(new Rectangle(Point(event.m_x, event.m_y), 0,0,penColorStr,brushColorStr,penSize));
                m_isdrawing =true;
                m_currentFigure = m_drawing[m_currentIndexFigure];
                Refresh();
            }
            break;
        case STATUS_ELLIPSE:
            if (m_isdrawing== false){
                m_drawing.addFigure(new Ellipse(Point(event.m_x, event.m_y), 0,0,penColorStr,brushColorStr,penSize));
                m_isdrawing =true;
                m_currentFigure = m_drawing[m_currentIndexFigure];
                Refresh();
            }
            break;
        case STATUS_POLYGON:
            if (m_isdrawing==false){
                m_drawing.addFigure(new Polygon(Point(event.m_x, event.m_y),penColorStr,brushColorStr,penSize));
                m_isdrawing =true;
                m_currentFigure = m_drawing[m_currentIndexFigure];
                Refresh();
            } else{
                m_currentFigure->addPoint(event.m_x, event.m_y);
                Refresh();
            }
            break;
    }
}




//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
    switch (m_status) {
        case STATUS_EDIT:
            //parcourir la liste des vecteurs en sens inverse et afficher les point qui permettent

            Refresh() ;	// send an event that calls the OnPaint method
            break;
        case STATUS_RECTANGLE:
            if (m_isdrawing) {
                m_drawing.setCurrentRectangle(m_currentIndexFigure, event.m_x, event.m_y);
                Refresh();
            }
            break;
        case STATUS_CIRCLE:
            if (m_isdrawing){
                m_drawing.setCircleCourant(m_currentIndexFigure,event.m_x,event.m_y);
                Refresh();
            }
            break;
        case STATUS_SQUARE:
            if (m_isdrawing){
            int pointerX = event.m_x;
            int pointerY = event.m_y;
            m_drawing.setCurrentRectangle(m_currentIndexFigure, pointerX, pointerY);
            int currentH = m_currentFigure->getH();
            int currentW = m_currentFigure->getW();
            if (currentH>currentW){
                m_currentFigure->setW(currentH);
            }else{
                m_currentFigure->setH(currentW);
            }
            }
            Refresh();
            break;
        case STATUS_ELLIPSE:
            if (m_isdrawing) {
                m_drawing.setCurrentRectangle(m_currentIndexFigure, event.m_x, event.m_y);
                Refresh();
            }
            break;
    }
}


//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftUp(wxMouseEvent &event)
//------------------------------------------------------------------------
{
    if (m_status!=STATUS_POLYGON) {
        if (m_isdrawing) {
            m_currentIndexFigure++;
            m_isdrawing = false;
            Refresh();
        }
    }
}



//------------------------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
//------------------------------------------------------------------------
// called automatically when the panel is shown for the first time or
// when the panel is resized
// You have to call OnPaint with Refresh() when you need to update the panel content
{
    // read the control values
    MyFrame* frame =  (MyFrame*)GetParent() ;
    // then paint
    wxPaintDC dc(this);
    for (int i = 0; i < m_drawing.nbFigures(); ++i) {
        Figure *figToPaint = m_drawing[i];

        wxColour penColor = static_cast<const wxString &>(figToPaint->GetBorderColor());
        dc.SetPen(wxPen(penColor,figToPaint->getPenSize() ));

        wxColour brushColor = static_cast<const wxString &>(figToPaint->GetFillColor());
        dc.SetBrush(wxBrush(brushColor));

        switch (figToPaint->getShape()) {
            case RECT_SHAPE:
                dc.DrawRectangle(wxRect(wxPoint(figToPaint->getTopLeft().getX(), figToPaint->getTopLeft().getY()), wxPoint(
                        figToPaint->getBottomRight().getX(),
                        figToPaint->getBottomRight().getY())));
                break;
            case CIRCLE_SHAPE:
                dc.DrawCircle(wxPoint(figToPaint->getCenter().getX(), figToPaint->getCenter().getY()),
                              wxCoord(figToPaint->getRay()));
                break;
            case ELLIPSE_SHAPE:
                dc.DrawEllipse(wxRect(wxPoint(figToPaint->getTopLeft().getX(), figToPaint->getTopLeft().getY()), wxPoint(
                        figToPaint->getBottomRight().getX(),
                        figToPaint->getBottomRight().getY())));
                break;
            case POLYGONE_SHAPE:
                if (figToPaint->getNbPoints()>1) {
                    for (int p = 1; p < figToPaint->getNbPoints(); ++p) {
                         dc.DrawLine(wxPoint(figToPaint->getPoint(p-1).getX(), figToPaint->getPoint(p-1).getY()),wxPoint(figToPaint->getPoint(p).getX(), figToPaint->getPoint(p).getY()));
                    }
                    dc.DrawLine(wxPoint(figToPaint->getPoint(0).getX(), figToPaint->getPoint(0).getY()),wxPoint(figToPaint->getPoint(figToPaint->getNbPoints()-1).getX(), figToPaint->getPoint(figToPaint->getNbPoints()-1).getY()));
                }
                break;
        }
    }
}

//------------------------------------------------------------------------
void MyDrawingPanel::OpenFile(wxString fileName)
//------------------------------------------------------------------------
{
    // just to open (and close) any file
    FILE* f = fopen(fileName, "r") ;
    if (f)
    {
        wxMessageBox(wxT("The file was opened then closed")) ;
        fclose(f) ;
    }
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
//------------------------------------------------------------------------
{
    // just to create a tiny file
    FILE* f = fopen(fileName, "w") ;
    if (!f)
        wxMessageBox(wxT("Cannot save file"));
    else
    {
        fprintf(f, "S1102 software can create and write a file") ;
        wxMessageBox(wxT("The file was saved")) ;
        fclose(f) ;
    }
}

void MyDrawingPanel::setStatus(int mStatus) {
    m_status = mStatus;
}

void MyDrawingPanel::setCurrentIndexTempsPoint(int mCurrentIndexTempsPoint) {
    m_currentIndexFigure = mCurrentIndexTempsPoint;
}

void MyDrawingPanel::undo() {
    if (!m_drawing.isEmpty()) {
        m_drawing.tempRemoveCurrentFig();
        --m_currentIndexFigure;
    } else{
        wxMessageBox(wxT("you can't go back further !"));
    }
    Refresh();
}

void MyDrawingPanel::redo() {
    if (!m_drawing.isTempFigEmpty()) {
        m_drawing.reDrawFig();
        ++m_currentIndexFigure;
    } else{
        wxMessageBox(wxT("you don't have anything to redo anymore !"));
    }
    Refresh();
}

