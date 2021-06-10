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
    Rectangle(const Point& topLeft, int h, int w,const std::string& penColor,const std::string& brushColor) ;
    Rectangle(const Point& topLeft, const Point& bottomRight,const std::string& penColor,const std::string& brushColor);

     Point getTopLeft() const override;
     Point getBottomRight() const override;

    void setTopLeft(int x, int y) override;
    void setBottomRight(int x, int y) override;

    int getH() const override;
    int getW() const override;

    void setH(int h) override;
    void setW(int w) override;

private:
    Point m_topLeft;
    Point m_bottomRight;
    int m_h;
    int m_w;

};


#endif //MOONDRAW_RECTANGLE_H
