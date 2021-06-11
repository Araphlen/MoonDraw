//
// Created by araphlen on 08/06/2021.
//

#include <iostream>
#include "headers/Rectangle.h"
#define RECT_SHAPE 1

Rectangle::Rectangle() :Figure(RECT_SHAPE,MyRgb(0,0,0),MyRgb(255,255,255),1, false) {
    m_topLeft = Point(0,0);
    m_h=10;
    m_w=20;
    m_bottomRight = Point(m_w+ m_topLeft.getX(), m_h + m_topLeft.getY());
}

Rectangle::Rectangle(const Point &topLeft, int h, int w,const MyRgb &penColor, const MyRgb &brushColor,int penSize, bool isTransparent) :Figure(RECT_SHAPE,penColor,brushColor,penSize,isTransparent) {
    m_topLeft = topLeft;
    m_h = h;
    m_w = w;
    m_bottomRight = Point(m_w+ m_topLeft.getX(), m_h + m_topLeft.getY());
}
Rectangle::Rectangle(const Point &topLeft, const Point &bottomRight,const MyRgb &penColor, const MyRgb &brushColor,int penSize,bool isTransparent) :Figure(RECT_SHAPE,penColor,brushColor,penSize,isTransparent) {
    m_topLeft = topLeft;
    m_bottomRight =bottomRight;
    m_h = m_bottomRight.getY() - m_topLeft.getY();
    m_w = m_bottomRight.getX() - m_topLeft.getX();

}

 Point Rectangle::getTopLeft() const {
    return m_topLeft;
}

 Point Rectangle::getBottomRight() const {
    return m_bottomRight;
}

int Rectangle::getH() const {
    return m_h;
}

int Rectangle::getW() const {
    return m_w;
}

void Rectangle::setH(int h) {
    m_h = h;
    m_bottomRight.setY(m_topLeft.getY()+m_h);
}

void Rectangle::setW(int w) {
    m_w = w;
    m_bottomRight.setX(m_topLeft.getX()+m_w);

}

void Rectangle::setTopLeft(int x, int y) {
    m_topLeft.setX(x);
    m_topLeft.setY(y);
    m_h = m_bottomRight.getY() - m_topLeft.getY();
    m_w = m_bottomRight.getX() - m_topLeft.getX();
}

void Rectangle::setBottomRight(int x, int y) {
    m_bottomRight.setX(x);
    m_bottomRight.setY(y);
    m_h = m_bottomRight.getY() - m_topLeft.getY();
    m_w = m_bottomRight.getX() - m_topLeft.getX();
}

bool Rectangle::areCoorInFigure(int mousex, int mousey) const {
    return m_topLeft.getX()<mousex && mousex<m_bottomRight.getX() && m_topLeft.getY()<mousey && mousey<m_bottomRight.getY();
}

void Rectangle::setEditBottomRight(bool isEditable) {
    m_TLEditable = isEditable;
}

void Rectangle::setEditTopLeft(bool isEditable) {
    m_BREditable = isEditable;
}

bool Rectangle::isBottomRightEditable(){
    return m_BREditable;
}

bool Rectangle::isTopLeftEditable() {
    return m_TLEditable;
}







