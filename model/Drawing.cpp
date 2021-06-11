//
// Created by araphlen on 08/06/2021.
//

#include <iostream>
#include "headers/Drawing.h"

Drawing::Drawing() {

}

void Drawing::setCurrentRectangle(int i, int x_br, int y_br) {
//    std::cout << "je redefini le point bottomRight a "<<x_br<<" "<<y_br << std::endl;
    this->operator[](i)->setBottomRight(x_br, y_br);
//    std::cout << "(Dans drawing)on vérifie si le point  a bien été redefinit a " << this->accessRectangle(i).getBottomRight().getX() << " " << this->accessRectangle(i).getBottomRight().getY() << std::endl;

}

//add a figure to the current drawing
void Drawing::addFigure(Figure *figure) {
    m_figures.push_back(figure);
}

void Drawing::setCircleCourant(int i, int pointerX, int pointerY) {
    this->operator[](i)->setRay(pointerX,pointerY);
}

const int Drawing::nbFigures() {
    return m_figures.size();
}

Figure *Drawing::operator[](int i) const{
    return m_figures[i];
}

bool Drawing::isEmpty() {
    return m_figures.empty();
}

bool Drawing::isTempFigEmpty() {
    return m_tempRemovedFigures.empty();
}

void Drawing::tempRemoveCurrentFig() {
    m_tempRemovedFigures.push_back(m_figures.back());
    m_figures.pop_back();
}

void Drawing::reDrawFig() {
    m_figures.push_back(m_tempRemovedFigures.back());
    m_tempRemovedFigures.pop_back();
}

void Drawing::unSelectAll() {
    //if we dclick outside any figure a
    for (int i = 0; i < this->nbFigures(); ++i) {
        m_figures[i]->setSelect(false);
    }
}