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

//Drawing::Drawing(const Drawing *pDrawing) : m_rectangles(pDrawing->m_rectangles) {
//}

const int Drawing::nbRectangles() {
    return m_rectangles.size();
}

Rectangle& Drawing::getRectangle(int i) {
    return m_rectangles[i];
}

void Drawing::setRectangleCourant(int i, int x_br, int y_br) {
    std::cout << "je redefini le point bottomRight a "<<x_br<<" "<<y_br << std::endl;
    this->getRectangle(i).setMBottomRight(x_br,y_br);
    std::cout << "(Dans drawing)on vérifie si le point  a bien été redefinit a "<<this->getRectangle(i).getMBottomRight().getMX()<<" "<<this->getRectangle(i).getMBottomRight().getMY() << std::endl;

}



//int Drawing::Open() {
//}

