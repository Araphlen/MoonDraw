//
// Created by araphlen on 08/06/2021.
//

#ifndef MOONDRAW_DRAWING_H
#define MOONDRAW_DRAWING_H

#include <vector>
#include <wx/dcclient.h>
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"

class Drawing {
public:
    Drawing();

    const int nbFormes();

    Figure* operator[](int i) const;
    //Methode for rectangles
    void addRectangle(Rectangle *rect);
    void setCurrentRectangle(int i, int x_br, int y_br);

    //methode for Circles

    void addFigure(Figure *figure);
    void setCircleCourant(int i, wxCoord i1, wxCoord i2);

private:
    std::vector<Figure*> m_figures ;
};


#endif //MOONDRAW_DRAWING_H
