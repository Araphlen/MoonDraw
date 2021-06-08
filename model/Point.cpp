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

int Point::getMX() const {
    return m_x;
}

int Point::getMY() const {
    return m_y;
}
