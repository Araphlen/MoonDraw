//
// Created by araphlen on 10/06/2021.
//

#include "headers/Ellipse.h"
#include "headers/Figure.h"

#define ELLIPSE_SHAPE 3

Ellipse::Ellipse() :Figure(ELLIPSE_SHAPE,"#000000","#FFFFFF") {
    m_topLeft = Point(0,0);
    m_h=10;
    m_w=20;
    m_bottomRight = Point(m_w+ m_topLeft.getX(), m_h + m_topLeft.getY());
}

Ellipse::Ellipse(const Point &topLeft, int h, int w,const std::string& penColor,const std::string& brushColor) :Figure(ELLIPSE_SHAPE,penColor,brushColor) {
    m_topLeft = topLeft;
    m_h = h;
    m_w = w;
    m_bottomRight = Point(m_w+ m_topLeft.getX(), m_h + m_topLeft.getY());
}
Ellipse::Ellipse(const Point &topLeft, const Point &bottomRight,const std::string& penColor,const std::string& brushColor) :Figure(ELLIPSE_SHAPE,penColor,brushColor) {
    m_topLeft = topLeft;
    m_bottomRight =bottomRight;
    m_h = m_bottomRight.getY() - m_topLeft.getY();
    m_w = m_bottomRight.getX() - m_topLeft.getX();

}

Point Ellipse::getTopLeft() const {
    return m_topLeft;
}

Point Ellipse::getBottomRight() const {
    return m_bottomRight;
}

int Ellipse::getH() const {
    return m_h;
}

int Ellipse::getW() const {
    return m_w;
}

void Ellipse::setH(int h) {
    m_h = h;
    m_bottomRight.setY(m_topLeft.getY()+m_h);
}

void Ellipse::setW(int w) {
    m_w = w;
    m_bottomRight.setX(m_topLeft.getX()+m_w);

}

void Ellipse::setTopLeft(int x, int y) {
    m_topLeft.setX(x);
    m_topLeft.setY(y);
    m_h = m_bottomRight.getY() - m_topLeft.getY();
    m_w = m_bottomRight.getX() - m_topLeft.getX();
}

void Ellipse::setBottomRight(int x, int y) {
    m_bottomRight.setX(x);
    m_bottomRight.setY(y);
    m_h = m_bottomRight.getY() - m_topLeft.getY();
    m_w = m_bottomRight.getX() - m_topLeft.getX();
}

