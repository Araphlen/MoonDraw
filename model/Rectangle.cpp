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
    m_bottomRight = Point(m_w+m_topLeft.getMX(),m_h+m_topLeft.getMY());
}

Rectangle::Rectangle(const Point &topLeft, int h, int w) {
    m_topLeft = topLeft;
    m_h = h;
    m_w = w;
    m_bottomRight = Point(m_w+m_topLeft.getMX(),m_h+m_topLeft.getMY());
}
Rectangle::Rectangle(const Point &topLeft, const Point &bottomRight) {
    m_topLeft = topLeft;
    m_bottomRight =bottomRight;
    m_h = m_bottomRight.getMY() - m_topLeft.getMY();
    m_w = m_bottomRight.getMX() - m_topLeft.getMX();

}

const Point &Rectangle::getMTopLeft() const {
    return m_topLeft;
}

const Point &Rectangle::getMBottomRight() const {
    return m_bottomRight;
}

int Rectangle::getMH() const {
    return m_h;
}

int Rectangle::getMW() const {
    return m_w;
}

void Rectangle::setMH(int mH) {
//    std::cout<<"m_h="<<m_h<<std::endl;
    m_h = mH;
//    std::cout<<"m_h="<<m_h<<std::endl;

}

void Rectangle::setMW(int mW) {
//    std::cout<<"m_w="<<m_w<<std::endl;
    m_w = mW;
//    std::cout<<"m_w="<<m_w<<std::endl;
}

void Rectangle::setMTopLeft(int x, int y) {
    m_topLeft.setMX(x);
    m_topLeft.setMY(y);
}

void Rectangle::setMBottomRight(int x,int y) {
    std::cout << "Pour l'instant le point est à "<<this->getMBottomRight().getMX()<<" "<<this->getMBottomRight().getMY() << std::endl;
    std::cout << "et on veut le mettre à  "<<x<<" "<<y << std::endl;

    m_bottomRight.setMX(x);
    m_bottomRight.setMY(y);
    std::cout << "le point a bien été redefinit a "<<this->getMBottomRight().getMX()<<" "<<this->getMBottomRight().getMY() << std::endl;

}







