//
// Created by araphlen on 09/06/2021.
//

#include "headers/Circle.h"
#include <cmath>
#define CIRCLE_SHAPE 2

Circle::Circle():Figure(CIRCLE_SHAPE) {
    m_center = Point(0,0);
    m_ray = 0;
}

Circle::Circle(const Point &center, int ray):Figure(CIRCLE_SHAPE)  {
    m_center= center;
    m_ray=ray;
}

void Circle::setRay(int pointerX, int pointerY){
    int centerX= m_center.getX();
    int centerY = m_center.getY();
    m_ray= (int) sqrt((centerX-pointerX)*(centerX-pointerX)+(centerY-pointerY)*(centerY-pointerY));
}

const Point &Circle::getCenter() const {
    return m_center;
}

int Circle::getRay() const {
    return m_ray;
}


