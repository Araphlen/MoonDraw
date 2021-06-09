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
    Rectangle(const Point& topLeft, const Point& bottomRight);

    const Point &getMTopLeft() const;
    const Point &getMBottomRight() const;

    void setMTopLeft(int x, int y);
    void setMBottomRight(int x,int y);

    int getMH() const;
    int getMW() const;

    void setMH(int mH);
    void setMW(int mW);

private:
    Point m_topLeft;
    Point m_bottomRight;
    int m_h;
    int m_w;

};


#endif //MOONDRAW_RECTANGLE_H
