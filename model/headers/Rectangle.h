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

    const Point &getTopLeft() const;
    const Point &getBottomRight() const;

    void setTopLeft(int x, int y);
    void setBottomRight(int x, int y);

    int getH() const;
    int getW() const;

    void setH(int h);
    void setW(int w);

private:
    Point m_topLeft;
    Point m_bottomRight;
    int m_h;
    int m_w;

};


#endif //MOONDRAW_RECTANGLE_H
