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


#define WIDGET_Y0			10
#define WIDGET_Y_STEP		50
#define WIDGET_PANEL_WIDTH	200

enum{
ID_BUTTON1,
ID_SLIDER1,
ID_CHECKBOX1
};
//------------------------------------------------------------------------
class MyControlPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
    MyControlPanel( wxWindow *parent ) ;
    int GetSliderValue() {return m_slider->GetValue() ;} ;
    bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;

private:
    void OnButton(wxCommandEvent &event) ;
    void OnSlider(wxScrollEvent &event) ;
    void OnCheckBox(wxCommandEvent &event) ;
    wxButton* m_button ;
    wxSlider* m_slider ;
    wxCheckBox* m_checkBox ;
};



#endif //SKELETON_MYCONTROLPANEL_H
