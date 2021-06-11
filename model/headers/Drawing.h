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

    const int nbFigures();

    void addFigure(Figure *figure);

    Figure* operator[](int i) const;

    //Methode for rectangles
    void setCurrentRectangleBR(int i, int x_br, int y_br);
    void setCurrentRectangleTL(int i, int x_tl, int y_tl);

    void setCircleCourant(int i, wxCoord i1, wxCoord i2);

    bool isEmpty();
    void tempRemoveCurrentFig();

    bool isTempFigEmpty();
    void clearTmpFigures();

    void reDrawFig();
    void unSelectAll();

private:
    std::vector<Figure*> m_figures ;
    std::vector<Figure*> m_tempRemovedFigures; //vector which contain figure that we undo if we want to redo it

};


#endif //MOONDRAW_DRAWING_H
