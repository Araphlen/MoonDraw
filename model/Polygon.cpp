//
// Created by araphlen on 11/06/2021.
//
#define POLYGONE_SHAPE 4

#include <iostream>
#include "headers/Polygon.h"

Polygon::Polygon(const Point &p1, const MyRgb &penColor, const MyRgb &brushColor, int penSize,bool isTransparent) : Figure(POLYGONE_SHAPE,penColor,brushColor,penSize,isTransparent){
    m_points.push_back(p1);
}

void Polygon::addPoint(int x, int y) {
    m_points.emplace_back(x,y);

}

int Polygon::getNbPoints() {
    return m_points.size();
}

Point Polygon::getPoint(int p) {
    return m_points[p];
}
