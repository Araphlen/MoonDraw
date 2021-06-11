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
#include <search.h>

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
    m_status = STATUS_RECTANGLE;
    m_drawing = Drawing();
    m_currentIndexFigure=0;
    m_isdrawing =false;
    m_mode=MODE_SELECT;
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->GetControlPanel()->SetModeLabel(this->getModeSTR());

}


void MyDrawingPanel::OnMouseLeftDClick(wxMouseEvent &event) {
    switch (m_mode) {
        case MODE_DRAW:
            switch (m_status) {
                case STATUS_POLYGON:
                    if (m_isdrawing) {
                        m_currentIndexFigure++;
                        m_isdrawing = false;
                        Refresh();
                    }
                    break;
            }
            break;
        case MODE_SELECT:
            if (!m_drawing.isEmpty()) {
                std::cout<<"-1"<<std::endl;
                int figindex = m_drawing.nbFigures();
                Figure* figure = m_drawing[figindex-1];
                while (figindex >= 0 && !figure->areCoorInFigure(event.m_x, event.m_y)) {
                    std::cout<<"0"<<std::endl;
                    --figindex;
                    figure = m_drawing[figindex];
                }
                if (figindex >= 0) {
                    std::cout<<"1"<<std::endl;
                    this->setMode(MODE_EDIT);
                    figure->setSelect(true);
                    //We set the current figure to be able to edit it easily
                    m_currentFigure= figure;
                    Refresh();
                } else {
                    std::cout<<"2"<<std::endl;
                    m_drawing.unSelectAll();
                }

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
    wxColour wxPenColour= frame->GetControlPanel()->GetPenColour();
    MyRgb penColor=MyRgb(wxPenColour.Red(),wxPenColour.Green(),wxPenColour.Blue()) ;

    unsigned char penSize = frame->GetControlPanel()->GetPenSliderValue();

    bool isTransparent = frame->GetControlPanel()->GetCheckBoxValue() ;

    wxColour wxBrushColour= frame->GetControlPanel()->GetBrushColour();
    MyRgb brushColor=MyRgb(wxBrushColour.Red(),wxBrushColour.Green(),wxBrushColour.Blue()) ;


    Point tmpTopleft;
    Point tmpBottomRight;
    Point tmpCenterPoint;

    switch (m_mode) {
        case MODE_DRAW:
            switch (m_status) {
                case STATUS_RECTANGLE:
                    if (m_isdrawing == false) {
                        m_drawing.addFigure(new Rectangle(Point(event.m_x, event.m_y), 0, 0, penColor, brushColor, penSize,
                                                          isTransparent));
                        m_isdrawing = true;
                        m_currentFigure = m_drawing[m_currentIndexFigure];
                        m_drawing.clearTmpFigures();
                        Refresh();
                    }
                    break;
                case STATUS_CIRCLE:
                    if (m_isdrawing == false) {
                        m_drawing.addFigure(
                                new Circle(Point(event.m_x, event.m_y), 0, penColor, brushColor, penSize, isTransparent));
                        m_isdrawing = true;
                        m_currentFigure = m_drawing[m_currentIndexFigure];
                        Refresh();
                    }
                    break;
                case STATUS_SQUARE:
                    if (m_isdrawing == false) {
                        m_drawing.addFigure(new Rectangle(Point(event.m_x, event.m_y), 0, 0, penColor, brushColor, penSize,
                                                          isTransparent));
                        m_isdrawing = true;
                        m_currentFigure = m_drawing[m_currentIndexFigure];
                        Refresh();
                    }
                    break;
                case STATUS_ELLIPSE:
                    if (m_isdrawing == false) {
                        m_drawing.addFigure(new Ellipse(Point(event.m_x, event.m_y), 0, 0, penColor, brushColor, penSize,
                                                        isTransparent));
                        m_isdrawing = true;
                        m_currentFigure = m_drawing[m_currentIndexFigure];
                        Refresh();
                    }
                    break;
                case STATUS_POLYGON:
                    if (m_isdrawing == false) {
                        m_drawing.addFigure(
                                new Polygon(Point(event.m_x, event.m_y), penColor, brushColor, penSize, isTransparent));
                        m_isdrawing = true;
                        m_currentFigure = m_drawing[m_currentIndexFigure];
                        Refresh();
                    } else {
                        m_currentFigure->addPoint(event.m_x, event.m_y);
                        Refresh();
                    }
                    break;
            }
            break;
        case MODE_EDIT:
            switch (m_status) {
                case STATUS_RECTANGLE:
                    tmpTopleft = m_currentFigure->getTopLeft();
                    tmpBottomRight = m_currentFigure->getBottomRight();
                    if (event.m_x<tmpTopleft.getX()+10 && event.m_x>tmpTopleft.getX()-10 && event.m_y<tmpTopleft.getY()+10 && event.m_x>tmpTopleft.getY()-10){
                        m_currentFigure->setEditTopLeft(true);
                    }
                    if (event.m_x<tmpBottomRight.getX()+10 && event.m_x>tmpBottomRight.getX()-10 && event.m_y<tmpBottomRight.getY()+10 && event.m_x>tmpBottomRight.getY()-10){
                        m_currentFigure->setEditBottomRight(true);
                    }

                    break;
                case STATUS_CIRCLE:
                    if (m_isdrawing == false) {
                        Refresh();
                    }
                    break;
                case STATUS_SQUARE:
                    if (m_isdrawing == false) {
                        Refresh();
                    }
                    break;
                case STATUS_ELLIPSE:
                    if (m_isdrawing == false) {
                        Refresh();
                    }
                    break;
                case STATUS_POLYGON:
                    if (m_isdrawing == false) {
                        Refresh();
                    }
                    break;
            }
            break;
        default:
            break;
    }
}




//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
    switch (m_mode) {
        case MODE_DRAW:
            switch (m_status) {
                case STATUS_RECTANGLE:
                    if (m_isdrawing) {
                        m_drawing.setCurrentRectangleBR(m_currentIndexFigure, event.m_x, event.m_y);
                        Refresh();
                    }
                    break;
                case STATUS_CIRCLE:
                    if (m_isdrawing) {
                        m_drawing.setCircleCourant(m_currentIndexFigure, event.m_x, event.m_y);
                        Refresh();
                    }
                    break;
                case STATUS_SQUARE:
                    if (m_isdrawing) {
                        int pointerX = event.m_x;
                        int pointerY = event.m_y;
                        m_drawing.setCurrentRectangleBR(m_currentIndexFigure, pointerX, pointerY);
                        int currentH = m_currentFigure->getH();
                        int currentW = m_currentFigure->getW();
                        if (currentH > currentW) {
                            m_currentFigure->setW(currentH);
                        } else {
                            m_currentFigure->setH(currentW);
                        }
                    }
                    Refresh();
                    break;
                case STATUS_ELLIPSE:
                    if (m_isdrawing) {
                        m_drawing.setCurrentRectangleBR(m_currentIndexFigure, event.m_x, event.m_y);
                        Refresh();
                    }
                    break;
            }
            break;
        case MODE_EDIT:
            switch (m_currentFigure->getShape()) {
                case RECT_SHAPE:
                    if (m_currentFigure->isBottomRightEditable()) {
                        m_drawing.setCurrentRectangleBR(m_currentIndexFigure-1, event.m_x, event.m_y);
                        Refresh();
                    } else if (m_currentFigure->isTopLeftEditable()) {
                        m_drawing.setCurrentRectangleTL(m_currentIndexFigure-1, event.m_x, event.m_y);
                        Refresh();
                    }
                    break;
            }

    }
}


//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftUp(wxMouseEvent &event)
//------------------------------------------------------------------------
{
    if (m_mode== MODE_DRAW || m_mode== MODE_EDIT) {
        if (m_status != STATUS_POLYGON) {
            if (m_isdrawing) {
                m_currentIndexFigure++;
                m_isdrawing = false;
                Refresh();
            }
        }


        if (m_currentFigure->isTopLeftEditable()) {
            m_currentFigure->setEditTopLeft(false);
        } else if (m_currentFigure->isBottomRightEditable()) {
            m_currentFigure->setEditBottomRight(false);
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
    Point tmpTopleft;
    Point tmpBottomRight = Point();
    Point tmpCenterPoint= Point();
    Point tmpCirclePoint= Point();

    // then paint
    wxPaintDC dc(this);
/*
//            for (int i = 0; i < m_drawing.nbFigures(); ++i) {
//                Figure *figToPaint = m_drawing[i];
//
//                wxColour penColor = wxColour(figToPaint->getBorderColor().getR(),figToPaint->getBorderColor().getG(),figToPaint->getBorderColor().getB());
//                dc.SetPen(wxPen(penColor,figToPaint->getPenSize() ));
//
//                wxColour brushColor;
//                if (figToPaint->isTransparent()){
//                    dc.SetBrush(*wxTRANSPARENT_BRUSH);
//                } else{
//                    brushColor = wxColour(figToPaint->getFillColor().getR(),figToPaint->getFillColor().getG(),figToPaint->getFillColor().getB());
//                    dc.SetBrush(wxBrush(brushColor));
//                }
//
//                switch (figToPaint->getShape()) {
//                    case RECT_SHAPE:
//                        dc.DrawRectangle(wxRect(wxPoint(figToPaint->getTopLeft().getX(), figToPaint->getTopLeft().getY()), wxPoint(
//                                figToPaint->getBottomRight().getX(),
//                                figToPaint->getBottomRight().getY())));
//                        break;
//                    case CIRCLE_SHAPE:
//                        dc.DrawCircle(wxPoint(figToPaint->getCenter().getX(), figToPaint->getCenter().getY()),
//                                      wxCoord(figToPaint->getRay()));
//                        break;
//                    case ELLIPSE_SHAPE:
//                        dc.DrawEllipse(wxRect(wxPoint(figToPaint->getTopLeft().getX(), figToPaint->getTopLeft().getY()), wxPoint(
//                                figToPaint->getBottomRight().getX(),
//                                figToPaint->getBottomRight().getY())));
//                        break;
//                    case POLYGONE_SHAPE:
//                        if (figToPaint->getNbPoints()>1) {
//                            for (int p = 1; p < figToPaint->getNbPoints(); ++p) {
//                                dc.DrawLine(wxPoint(figToPaint->getPoint(p-1).getX(), figToPaint->getPoint(p-1).getY()),wxPoint(figToPaint->getPoint(p).getX(), figToPaint->getPoint(p).getY()));
//                            }
//                            dc.DrawLine(wxPoint(figToPaint->getPoint(0).getX(), figToPaint->getPoint(0).getY()),wxPoint(figToPaint->getPoint(figToPaint->getNbPoints()-1).getX(), figToPaint->getPoint(figToPaint->getNbPoints()-1).getY()));
//                        }
//                        break;
//                }
//            }
*/
            for (int i = 0; i < m_drawing.nbFigures(); ++i) {
                Figure *figToPaint = m_drawing[i];

                wxColour penColor = wxColour(figToPaint->getBorderColor().getR(),figToPaint->getBorderColor().getG(),figToPaint->getBorderColor().getB());
                dc.SetPen(wxPen(penColor,figToPaint->getPenSize() ));

                wxColour brushColor;
                if (figToPaint->isTransparent()){
                    dc.SetBrush(*wxTRANSPARENT_BRUSH);
                } else{
                    brushColor = wxColour(figToPaint->getFillColor().getR(),figToPaint->getFillColor().getG(),figToPaint->getFillColor().getB());
                    dc.SetBrush(wxBrush(brushColor));
                }

                switch (figToPaint->getShape()) {
                    case RECT_SHAPE:
                        dc.DrawRectangle(wxRect(wxPoint(figToPaint->getTopLeft().getX(), figToPaint->getTopLeft().getY()), wxPoint(
                                figToPaint->getBottomRight().getX(),
                                figToPaint->getBottomRight().getY())));

                        if (figToPaint->isSelected()) {
                            tmpTopleft= figToPaint->getTopLeft();
                            tmpBottomRight = figToPaint->getBottomRight();
                        }

                        break;

                    case CIRCLE_SHAPE:
                        dc.DrawCircle(wxPoint(figToPaint->getCenter().getX(), figToPaint->getCenter().getY()),
                                      wxCoord(figToPaint->getRay()));

                        if (figToPaint->isSelected()) {
                            tmpCenterPoint = figToPaint->getCenter();
                        }

                        break;

                    case ELLIPSE_SHAPE:
                        dc.DrawEllipse(wxRect(wxPoint(figToPaint->getTopLeft().getX(), figToPaint->getTopLeft().getY()), wxPoint(
                                figToPaint->getBottomRight().getX(),
                                figToPaint->getBottomRight().getY())));

                        if (figToPaint->isSelected()) {
                            tmpTopleft= figToPaint->getTopLeft();
                            tmpBottomRight = figToPaint->getBottomRight();
                        }

                        break;

                    case POLYGONE_SHAPE:
                        if (figToPaint->getNbPoints()>1) {
                            for (int p = 1; p < figToPaint->getNbPoints(); ++p) {
                                dc.DrawLine(wxPoint(figToPaint->getPoint(p-1).getX(), figToPaint->getPoint(p-1).getY()),wxPoint(figToPaint->getPoint(p).getX(), figToPaint->getPoint(p).getY()));
                                dc.SetPen(wxPen(*wxRED,5));
                                dc.DrawCircle(wxPoint(figToPaint->getPoint(p).getX(), figToPaint->getPoint(p).getY()),wxCoord(2));
                            }
                            if (figToPaint->isSelected()) {
                                dc.DrawLine(wxPoint(figToPaint->getPoint(0).getX(), figToPaint->getPoint(0).getY()),
                                            wxPoint(figToPaint->getPoint(figToPaint->getNbPoints() - 1).getX(),
                                                    figToPaint->getPoint(figToPaint->getNbPoints() - 1).getY()));
                                dc.SetPen(wxPen(*wxRED, 5));
                                dc.DrawCircle(wxPoint(figToPaint->getPoint(0).getX(), figToPaint->getPoint(0).getY()),
                                              wxCoord(2));
                            }
                        }
                        break;
                }

            }

    dc.SetPen(wxPen(*wxRED, 5));

    if (tmpTopleft.getX()!=-1){
        dc.DrawCircle(wxPoint(tmpTopleft.getX(), tmpTopleft.getY()),
                      wxCoord(2));
    }
    if (tmpBottomRight.getX()!=-1){
        dc.DrawCircle(
                wxPoint(tmpBottomRight.getX(), tmpBottomRight.getY()),
                wxCoord(2));
    }
    if (tmpCenterPoint.getX()!=-1){
        dc.DrawCircle(
                wxPoint(tmpCenterPoint.getX(), tmpCenterPoint.getY()),
                wxCoord(2));
    }
    if (tmpCirclePoint.getX()!=-1){
        dc.DrawCircle(
                wxPoint(tmpCirclePoint.getX(), tmpCirclePoint.getY()),
                wxCoord(2));
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
    m_drawing.unSelectAll();
    m_mode = MODE_DRAW;
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

void MyDrawingPanel::setMode(int mMode) {
    m_mode = mMode;
}

std::string MyDrawingPanel::getModeSTR() {
    switch (m_mode) {
        case MODE_EDIT:
            return "edition";
            break;
        case MODE_DRAW:
            return "draw";
            break;
        case MODE_SELECT:
            return "select";
            break;
    }
}

