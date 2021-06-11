//
// Created by araphlen on 11/06/2021.
//

#include "headers/MyRgb.h"

unsigned char MyRgb::getR() const {
    return m_r;
}

void MyRgb::setR(unsigned char r) {
    m_r = r;
}

unsigned char MyRgb::getG() const {
    return m_g;
}

void MyRgb::setG(unsigned char g) {
    m_g = g;
}

unsigned char MyRgb::getB() const {
    return m_b;
}

void MyRgb::setB(unsigned char b) {
    m_b = b;
}

MyRgb::MyRgb(unsigned char r, unsigned char g, unsigned char b) {
    m_r= r;
    m_g =g;
    m_b = b;
}

