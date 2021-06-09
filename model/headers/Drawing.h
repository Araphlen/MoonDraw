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

    //Methode for rectangles
    void addRectangle(const Rectangle &rect);
    const int nbRectangles();
    Rectangle& accessRectangle(int i);
    void setRectangleCourant(int i, int x_br, int y_br);

    //methode for Circles
    int nbCircles();

    Circle &accessCircle(int i);

    void addCircle(const Circle &circle);

    void setCircleCourant(int i, wxCoord i1, wxCoord i2);

private:
    std::vector<Rectangle> m_rectangles ;
    std::vector<Circle> m_circles;
};


#endif //MOONDRAW_DRAWING_H
