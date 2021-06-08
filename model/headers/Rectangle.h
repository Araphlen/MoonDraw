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
    Rectangle(const Point& topLeft, int h, int w) ;

    const Point &getMTopLeft() const;
    int getMH() const;
    int getMW() const;

    void setMH(int mH);
    void setMW(int mW);

private:
    Point m_topLeft;
    int m_h;
    int m_w;

};


#endif //MOONDRAW_RECTANGLE_H
