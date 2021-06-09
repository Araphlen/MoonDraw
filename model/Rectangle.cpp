//
// Created by araphlen on 08/06/2021.
//

#include <iostream>
#include "headers/Rectangle.h"
#define RECT_SHAPE 1

Rectangle::Rectangle() :Figure(RECT_SHAPE) {
    m_topLeft = Point(0,0);
    m_h=10;
    m_w=20;
    m_bottomRight = Point(m_w+ m_topLeft.getX(), m_h + m_topLeft.getY());
}

Rectangle::Rectangle(const Point &topLeft, int h, int w) :Figure(RECT_SHAPE) {
    m_topLeft = topLeft;
    m_h = h;
    m_w = w;
    m_bottomRight = Point(m_w+ m_topLeft.getX(), m_h + m_topLeft.getY());
}
Rectangle::Rectangle(const Point &topLeft, const Point &bottomRight) :Figure(RECT_SHAPE) {
    m_topLeft = topLeft;
    m_bottomRight =bottomRight;
    m_h = m_bottomRight.getY() - m_topLeft.getY();
    m_w = m_bottomRight.getX() - m_topLeft.getX();

}

const Point &Rectangle::getTopLeft() const {
    return m_topLeft;
}

const Point &Rectangle::getBottomRight() const {
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







