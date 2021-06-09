//
// Created by araphlen on 08/06/2021.
//

#include <iostream>
#include "headers/Drawing.h"

Drawing::Drawing() {

}
//add a figure to the current drawing
void Drawing::addRectangle(const Rectangle &rect) {
    m_rectangles.push_back(rect);
}


const int Drawing::nbRectangles() {
    return m_rectangles.size();
}

Rectangle& Drawing::accessRectangle(int i) {
    return m_rectangles[i];
}

void Drawing::setRectangleCourant(int i, int x_br, int y_br) {
//    std::cout << "je redefini le point bottomRight a "<<x_br<<" "<<y_br << std::endl;
    this->accessRectangle(i).setBottomRight(x_br, y_br);
//    std::cout << "(Dans drawing)on vérifie si le point  a bien été redefinit a " << this->accessRectangle(i).getBottomRight().getX() << " " << this->accessRectangle(i).getBottomRight().getY() << std::endl;

}

int Drawing::nbCircles() {
    return m_circles.size();
}

Circle &Drawing::accessCircle(int i) {
    return m_circles[i];
}

void Drawing::addCircle(const Circle &circle) {
    m_circles.push_back(circle);
}

void Drawing::setCircleCourant(int i, int pointerX, int pointerY) {
    this->accessCircle(i).setRay(pointerX,pointerY);
}

//}

