//
// Created by araphlen on 08/06/2021.
//

#ifndef MOONDRAW_RECTANGLE_H
#define MOONDRAW_RECTANGLE_H


#include "Figure.h"
#include "Point.h"

class Rectangle : public Figure{
public:
    Rectangle();
    Rectangle(const Point& topLeft, const Point& bottomRight) ;


private:
    Point m_topLeft;
    Point m_bottomRight;

};


#endif //MOONDRAW_RECTANGLE_H
