//
// Created by araphlen on 08/06/2021.
//

#include "headers/Point.h"

Point::Point() {
}

Point::Point(int x, int y) {
    m_x=x;
    m_y=y;
}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}

void Point::setX(int mX) {
    m_x = mX;
}

void Point::setY(int mY) {
    m_y = mY;
}
