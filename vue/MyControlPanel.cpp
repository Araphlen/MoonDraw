//
// Created by araphlen on 07/06/2021.
//

#include "headers/MyControlPanel.h"
#include "headers/MyFrame.h"
#include "headers/MyDrawingPanel.h"


#define STATUS_DEFAULT 0
#define STATUS_RECTANGLE 1
#define STATUS_CIRCLE 2
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
    m_button = new wxButton(this, ID_BUTTON1, wxT("Yo brudah"), wxPoint(10, y) ) ;
    Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON1) ;

    y+= WIDGET_Y_STEP ;
    wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Radius"), wxPoint(10, y)) ;

    y+= 20 ;
    m_slider = new wxSlider(this, ID_SLIDER1, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
    Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;

    y+= WIDGET_Y_STEP ;
    m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(150,30)) ;
    Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;

    y+= WIDGET_Y_STEP;
    m_rectButton = new wxButton(this, ID_RECTBUTTON, wxT("RECTANGLE"), wxPoint(10, y));
    Bind(wxEVT_BUTTON,&MyControlPanel::OnButtonRectangle,this,ID_RECTBUTTON);

    y+= WIDGET_Y_STEP;
    m_circleButton = new wxButton(this,ID_CIRCLEBUTTON, wxT("CERCLE"),wxPoint(10,y));
    Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonCircle,this,ID_CIRCLEBUTTON);
}

//------------------------------------------------------------------------
void MyControlPanel::OnButton(wxCommandEvent &event)
//------------------------------------------------------------------------
{
//	char* s = GetCString() ;
//	wxMessageBox(wxString::FromAscii(s)) ; // call a C function located in the sample.cp module
//	free(s) ;
    wxMessageBox(wxT("You just pressed the button!")) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnSlider(wxScrollEvent &event)
//------------------------------------------------------------------------
{
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
//------------------------------------------------------------------------
{
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;	// update the drawing panel
}

void MyControlPanel::OnButtonRectangle(wxCommandEvent &event) {
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->GetDrawingPanel()->setStatus(STATUS_RECTANGLE);
}

void MyControlPanel::OnButtonCircle(wxCommandEvent &event) {
    MyFrame* frame = (MyFrame*)GetParent();
    frame->GetDrawingPanel()->setStatus(STATUS_CIRCLE);
}
