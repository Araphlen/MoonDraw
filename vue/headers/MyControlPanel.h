//
// Created by araphlen on 07/06/2021.
//

#ifndef SKELETON_MYCONTROLPANEL_H
#define SKELETON_MYCONTROLPANEL_H
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

#define WIDGET_Y0			10
#define WIDGET_Y_STEP		50
#define WIDGET_PANEL_WIDTH	200

enum{
ID_BUTTON1,
ID_SLIDER1,
ID_CHECKBOX1,
ID_RECTBUTTON,
ID_CIRCLEBUTTON,
ID_SQUAREBUTTON,
ID_ELIPSEBUTTON,
ID_BRUSHCOLORPICKER,
ID_PENLEGEND,
ID_BRUSHLEGEND,
ID_PENCOLORPICKER,

};
//------------------------------------------------------------------------
class MyControlPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
    MyControlPanel( wxWindow *parent ) ;
    int GetSliderValue() {return m_slider->GetValue() ;} ;
    bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;
    wxColour GetPenColour() {return m_penColourPicker->GetColour();};
    wxColour GetBrushColour() {return m_brushColourPicker->GetColour();};

private:
    void OnButton(wxCommandEvent &event) ;
    void OnButtonRectangle(wxCommandEvent &event);
    void OnButtonCircle(wxCommandEvent &event);
    void OnButtonSquare(wxCommandEvent &event);
    void OnButtonElipse(wxCommandEvent &event);
    void OnSlider(wxScrollEvent &event) ;
    void OnCheckBox(wxCommandEvent &event) ;
    void OnPenColorPicker(wxColourPickerEvent &event);
    void OnBrushColorPicker(wxColourPickerEvent& event);
    wxButton* m_button ;
    wxButton* m_rectButton;
    wxButton* m_circleButton;
    wxButton* m_squareButton;
    wxButton* m_elipseButton;
    wxStaticText* m_penlegend;
    wxColourPickerCtrl* m_penColourPicker;
    wxStaticText* m_brushLegend;
    wxColourPickerCtrl* m_brushColourPicker;
    wxSlider* m_slider ;
    wxCheckBox* m_checkBox ;

};



#endif //SKELETON_MYCONTROLPANEL_H
