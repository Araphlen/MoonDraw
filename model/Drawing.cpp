//
// Created by araphlen on 08/06/2021.
//

#include <iostream>
#include "headers/Drawing.h"

Drawing::Drawing() {

}
//add a figure to the current drawing
void Drawing::addRectangle(Rectangle *rect) {
    m_figures.push_back(rect);
}



void Drawing::setCurrentRectangle(int i, int x_br, int y_br) {
//    std::cout << "je redefini le point bottomRight a "<<x_br<<" "<<y_br << std::endl;
    this->operator[](i)->setBottomRight(x_br, y_br);
//    std::cout << "(Dans drawing)on vérifie si le point  a bien été redefinit a " << this->accessRectangle(i).getBottomRight().getX() << " " << this->accessRectangle(i).getBottomRight().getY() << std::endl;

}


void Drawing::addFigure(Figure *figure) {
    m_figures.push_back(figure);
}

void Drawing::setCircleCourant(int i, int pointerX, int pointerY) {
    this->operator[](i)->setRay(pointerX,pointerY);
}

const int Drawing::nbFormes() {
    return m_figures.size();
}

Figure *Drawing::operator[](int i) const{
    return m_figures[i];
}

//}

