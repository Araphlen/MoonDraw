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
}

Rectangle::Rectangle(const Point &topLeft, int h, int w) {
    m_topLeft = topLeft;
    m_h = h;
    m_w = w;
}

const Point &Rectangle::getMTopLeft() const {
    return m_topLeft;
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




