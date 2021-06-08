//
// Created by araphlen on 08/06/2021.
//

#ifndef MOONDRAW_DRAWING_H
#define MOONDRAW_DRAWING_H

#include <vector>
#include <wx/dcclient.h>
#include "Figure.h"
#include "Rectangle.h"

class Drawing {
public:
    Drawing();
    //consrtucteur par copie
    Drawing(const Drawing *pDrawing);

    //Methode for rectangles
    void addRectangle(const Rectangle &rect);
    const int nbRectangles();
    Rectangle getRectangle(int i);
    void setRectangleCourant(int i, int h, int w);

private:
    std::vector<Rectangle> m_rectangles ;
};


#endif //MOONDRAW_DRAWING_H
