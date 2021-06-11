//
// Created by araphlen on 10/06/2021.
//

#ifndef MOONDRAW_ELLIPSE_H
#define MOONDRAW_ELLIPSE_H


#include "Point.h"
#include "Figure.h"

class Ellipse : public Figure{
public:
    Ellipse();
    Ellipse(const Point& topLeft, int h, int w,const std::string& penColor,const std::string& brushColor,int penSize) ;
    Ellipse(const Point& topLeft, const Point& bottomRight,const std::string& penColor,const std::string& brushColor,int penSize);

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


#endif //MOONDRAW_ELLIPSE_H
