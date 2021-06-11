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
ID_BUTTONUNDO,
ID_BUTTONREDO,
ID_PENSIZESLIDER,
ID_CHECKBOX1,
ID_SELECTBUTTON,
ID_RECTBUTTON,
ID_CIRCLEBUTTON,
ID_SQUAREBUTTON,
ID_ELIPSEBUTTON,
ID_POLYGONBUTTON,
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
    int GetPenSliderValue() {return m_penSizeSlider->GetValue() ;} ;
    bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;
    wxColour GetPenColour() {return m_penColourPicker->GetColour();};
    wxColour GetBrushColour() {return m_brushColourPicker->GetColour();};

private:
    void OnButtonUndo(wxCommandEvent &event) ;
    void OnButtonRedo(wxCommandEvent &event);
    void OnPenSizeSlider(wxScrollEvent &event) ;
    void OnButtonSelect(wxCommandEvent &event);
    void OnButtonRectangle(wxCommandEvent &event);
    void OnButtonCircle(wxCommandEvent &event);
    void OnButtonSquare(wxCommandEvent &event);
    void OnButtonElipse(wxCommandEvent &event);
    void OnButtonPolygon(wxCommandEvent &event);
    void OnCheckBox(wxCommandEvent &event) ;
    void OnPenColorPicker(wxColourPickerEvent &event);
    void OnBrushColorPicker(wxColourPickerEvent& event);


    wxButton* m_buttonUndo ;
    wxButton* m_buttonRedo ;
    wxStaticText* m_penSizeLegend;
    wxSlider* m_penSizeSlider ;
    wxButton* m_selectButton;
    wxButton* m_rectButton;
    wxButton* m_circleButton;
    wxButton* m_squareButton;
    wxButton* m_elipseButton;
    wxButton* m_polygonButton;
    wxStaticText* m_penlegend;
    wxColourPickerCtrl* m_penColourPicker;
    wxStaticText* m_brushLegend;
    wxColourPickerCtrl* m_brushColourPicker;
    wxCheckBox* m_checkBox ;

};



#endif //SKELETON_MYCONTROLPANEL_H
