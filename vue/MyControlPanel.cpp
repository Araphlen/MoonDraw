//
// Created by araphlen on 07/06/2021.
//

#include <langinfo.h>
#include "headers/MyControlPanel.h"
#include "headers/MyFrame.h"
#include "headers/MyDrawingPanel.h"


#define STATUS_DEFAULT 0
#define STATUS_RECTANGLE 1
#define STATUS_CIRCLE 2
#define STATUS_SQUARE 3
#define STATUS_ELLIPSE 4
#define STATUS_POLYGON 5
//************************************************************************
//************************************************************************
// MyDrawingPanel class (where controls are displayed)
//************************************************************************
//************************************************************************

//------------------------------------------------------------------------
MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, create the controls and associate each of them (bind) a method
{
    int w, h, y ;
    GetParent()->GetSize(&w,&h) ;
    SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
    SetBackgroundColour(*wxLIGHT_GREY) ;

    y = WIDGET_Y0 ;
    m_buttonUndo = new wxButton(this, ID_BUTTONUNDO, wxT("<-"), wxPoint(10, y) ) ;
    Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonUndo, this, ID_BUTTONUNDO) ;

    m_buttonRedo = new wxButton(this, ID_BUTTONREDO, wxT("->"), wxPoint(100, y) ) ;
    Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonRedo, this, ID_BUTTONREDO) ;

    y+= WIDGET_Y_STEP ;
    m_penSizeLegend = new wxStaticText(this, wxID_ANY, wxT("Pen size : "), wxPoint(10, y)) ;
    m_penSizeSlider = new wxSlider(this, ID_PENSIZESLIDER, 10, 0, 100, wxPoint(100, y), wxSize(100, 20)) ;
    Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnPenSizeSlider, this, ID_PENSIZESLIDER) ;
    m_penSizeLegend->SetLabel(wxString("Pen size : "+ std::to_string(m_penSizeSlider->GetValue()) ));

//    y+= WIDGET_Y_STEP ;
//    m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(150,30)) ;
//    Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;

    y+= WIDGET_Y_STEP;
    m_rectButton = new wxButton(this, ID_RECTBUTTON, wxT("RECTANGLE"), wxPoint(10, y));
    Bind(wxEVT_BUTTON,&MyControlPanel::OnButtonRectangle,this,ID_RECTBUTTON);

    y+= WIDGET_Y_STEP;
    m_circleButton = new wxButton(this,ID_CIRCLEBUTTON, wxT("CERCLE"),wxPoint(10,y));
    Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonCircle,this,ID_CIRCLEBUTTON);

    y+= WIDGET_Y_STEP;
    m_squareButton = new wxButton(this,ID_SQUAREBUTTON, wxT("CARRE"),wxPoint(10,y));
    Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonSquare,this,ID_SQUAREBUTTON);

    y+= WIDGET_Y_STEP;
    m_polygonButton = new wxButton(this,ID_POLYGONBUTTON, wxT("POLYGON"),wxPoint(10,y));
    Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonPolygon,this,ID_POLYGONBUTTON);

    y+= WIDGET_Y_STEP;
    m_elipseButton = new wxButton(this, ID_ELIPSEBUTTON, wxT("Elipse"), wxPoint(10, y));
    Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonElipse,this,ID_ELIPSEBUTTON);

    y+= WIDGET_Y_STEP;
    m_penlegend = new wxStaticText(this, ID_PENLEGEND, "Pen : ", wxPoint(10, y + 10));
    m_penColourPicker = new wxColourPickerCtrl(this, ID_PENCOLORPICKER, wxColor(0, 0, 0), wxPoint(100, y));
    Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnPenColorPicker, this, ID_PENCOLORPICKER);

    y+= WIDGET_Y_STEP;
    m_brushLegend = new wxStaticText(this, ID_BRUSHLEGEND, "Brush : ", wxPoint(10, y + 10));
    m_brushColourPicker = new wxColourPickerCtrl(this, ID_BRUSHCOLORPICKER, wxColor(255, 255, 255), wxPoint(100, y));
    Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnBrushColorPicker, this, ID_BRUSHCOLORPICKER);

}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonUndo(wxCommandEvent &event)
//------------------------------------------------------------------------
{
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->GetDrawingPanel()->undo();
}

void MyControlPanel::OnButtonRedo(wxCommandEvent &event) {
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->GetDrawingPanel()->redo();
}

//------------------------------------------------------------------------
void MyControlPanel::OnPenSizeSlider(wxScrollEvent &event)
//------------------------------------------------------------------------
{
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;	// update the drawing panel
    m_penSizeLegend->SetLabel(wxString("Pen size : "+ std::to_string(m_penSizeSlider->GetValue()) ));

}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
//------------------------------------------------------------------------
{
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;	// update the drawing panel
}
//------------------------------------------------------------------------
void MyControlPanel::OnButtonRectangle(wxCommandEvent &event) {
//------------------------------------------------------------------------
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->GetDrawingPanel()->setStatus(STATUS_RECTANGLE);
}
//------------------------------------------------------------------------
void MyControlPanel::OnButtonCircle(wxCommandEvent &event) {
//------------------------------------------------------------------------
    MyFrame* frame = (MyFrame*)GetParent();
    frame->GetDrawingPanel()->setStatus(STATUS_CIRCLE);
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonSquare(wxCommandEvent &event) {
//------------------------------------------------------------------------
    MyFrame* frame = (MyFrame*)GetParent();
    frame->GetDrawingPanel()->setStatus(STATUS_SQUARE);
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonElipse(wxCommandEvent &event) {
//------------------------------------------------------------------------
    MyFrame* frame = (MyFrame*)GetParent();
    frame->GetDrawingPanel()->setStatus(STATUS_ELLIPSE);
}

//------------------------------------------------------------------------
void MyControlPanel::OnButtonPolygon(wxCommandEvent &event) {
//------------------------------------------------------------------------
    MyFrame* frame = (MyFrame*)GetParent();
    frame->GetDrawingPanel()->setStatus(STATUS_POLYGON);

}

//------------------------------------------------------------------------
void MyControlPanel::OnBrushColorPicker(wxColourPickerEvent &event) {
//------------------------------------------------------------------------
    MyFrame* frame = (MyFrame*)GetParent();
    frame->RefreshDrawing();
}
//------------------------------------------------------------------------
void MyControlPanel::OnPenColorPicker(wxColourPickerEvent &event) {
//------------------------------------------------------------------------
    MyFrame* frame = (MyFrame*)GetParent();
    frame->RefreshDrawing();
}



