//
// Created by araphlen on 07/06/2021.
//

#include <langinfo.h>
#include "headers/MyDrawingPanel.h"

#include "headers/MyFrame.h"
#include <iostream>

#define RECT_SHAPE 1
#define CIRCLE_SHAPE 2



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
    Bind(wxEVT_LEFT_UP, &MyDrawingPanel::OnMouseLeftUp,this);
    Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;
    m_onePoint.x = (w-WIDGET_PANEL_WIDTH)/2 ;
    m_onePoint.y = h/2 ;
    m_mousePoint = m_onePoint ;
    m_status = STATUS_DEFAULT;
    m_drawing = Drawing();
    m_currentIndexRect=0;
    m_isdrawing =false;
    }



//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
    switch (m_status) {
        case STATUS_DEFAULT :
            m_onePoint.x = event.m_x ;
            m_onePoint.y = event.m_y ;
            Refresh() ; // send an event that calls the OnPaint method
            break;
        case STATUS_RECTANGLE:
            if (m_isdrawing==false) {
                m_drawing.addRectangle(Rectangle(Point(event.m_x, event.m_y), 100, 200));
                m_isdrawing = true;
                std::cout << "J'ai initilaliser un noveau Rectangle a "<<event.m_x << " " << event.m_y << std::endl;
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
        case 0:
            m_mousePoint.x = event.m_x ;
            m_mousePoint.y = event.m_y ;
            Refresh() ;	// send an event that calls the OnPaint method
            break;
        case 1:
            if (m_isdrawing) {
                std::cout << "JE DESSINE UN RECTANGLE" << std::endl;
                m_drawing.setRectangleCourant(m_currentIndexRect, event.m_x,event.m_y);
                Refresh();
            }
            std::cout<<m_isdrawing<<std::endl;

            break;
    }
}


//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftUp(wxMouseEvent &event)
//------------------------------------------------------------------------
{
    switch (m_status) {
        case STATUS_DEFAULT:
            Refresh();
            break;
        case STATUS_RECTANGLE:
            std::cout<<"je suis dans OnMouseLeftUp"<<std::endl;

            m_currentIndexRect++;
            m_isdrawing= false;
            break;
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

//    
            int radius = frame->GetControlPanel()->GetSliderValue() ;
            bool check = frame->GetControlPanel()->GetCheckBoxValue() ;
//
//            // then paint
            wxPaintDC dc(this);
//
//            dc.DrawLine(m_mousePoint, m_onePoint) ;
            dc.DrawRectangle(wxPoint(m_onePoint.x, m_onePoint.y), wxSize(100,100)) ;
            dc.DrawCircle(wxPoint(m_mousePoint), radius/2) ;
//
            if (check)
            {
                wxString coordinates ;
                coordinates.sprintf(wxT("(%d,%d)"), m_mousePoint.x, m_mousePoint.y) ;
                dc.DrawText(coordinates, wxPoint(m_mousePoint.x, m_mousePoint.y+20)) ;
            }



    for (int i = 0; i < m_drawing.nbRectangles(); ++i) {
        Rectangle rectToPaint = m_drawing.getRectangle(i);
        std::cout<<"---------------------------------------------------------------------------"<<std::endl;
        std::cout<<"m_xtl ="<< rectToPaint.getMTopLeft().getMX()<<std::endl;
        std::cout<<"m_ytl ="<< rectToPaint.getMTopLeft().getMY()<<std::endl;
        std::cout<<"---------------------------------------------------------------------------"<<std::endl;
        std::cout<<"m_xbr ="<< rectToPaint.getMBottomRight().getMX()<<std::endl;
        std::cout<<"m_ybr ="<< rectToPaint.getMBottomRight().getMY()<<std::endl;
        std::cout<<"---------------------------------------------------------------------------"<<std::endl;
        std::cout<<"m_h ="<< rectToPaint.getMH()<<std::endl;
        std::cout<<"m_w ="<< rectToPaint.getMW()<<std::endl;
        std::cout<<"---------------------------------------------------------------------------"<<std::endl;
        std::cout<<"size de m_rectangles ="<< m_drawing.nbRectangles()<<std::endl;
        dc.DrawRectangle(wxRect(wxPoint(rectToPaint.getMTopLeft().getMX(),rectToPaint.getMTopLeft().getMY()),wxPoint(rectToPaint.getMBottomRight().getMX(),rectToPaint.getMBottomRight().getMY())));
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

void MyDrawingPanel::setMStatus(int mStatus) {
    m_status = mStatus;
}

void MyDrawingPanel::setMCurrentIndexTempsPoint(int mCurrentIndexTempsPoint) {
    m_currentIndexRect = mCurrentIndexTempsPoint;
}
