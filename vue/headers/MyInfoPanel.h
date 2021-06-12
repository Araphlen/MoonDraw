//
// Created by araphlen on 12/06/2021.
//

#ifndef MOONDRAW_MYINFOPANEL_H
#define MOONDRAW_MYINFOPANEL_H
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


class MyInfoPanel : public wxPanel{
public:
    MyInfoPanel(wxWindow *parent);
    void SetModeLabel(std::string modestr);

private:
    wxStaticText* m_currentMode ;

};


#endif //

