//
// Created by araphlen on 09/06/2021.
//

#include "headers/Circle.h"
#include <cmath>
#define CIRCLE_SHAPE 2

Circle::Circle():Figure(CIRCLE_SHAPE,MyRgb(0,0,0), MyRgb(255,255,255),1,false) {
    m_center = Point(0,0);
    m_ray = 0;
}

Circle::Circle(const Point &center, int ray,const MyRgb &penColor, const MyRgb &brushColor,int penSize,bool isTransparent) :Figure(CIRCLE_SHAPE,penColor,brushColor,penSize,isTransparent) {
    m_center= center;
    m_ray=ray;
}

void Circle::setRay(int pointerX, int pointerY){
    int centerX= m_center.getX();
    int centerY = m_center.getY();
    m_ray= (int) sqrt((centerX-pointerX)*(centerX-pointerX)+(centerY-pointerY)*(centerY-pointerY));
}

 Point Circle::getCenter() const {
    return m_center;
}

int Circle::getRay() const {
    return m_ray;
}


