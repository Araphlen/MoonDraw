//
// Created by araphlen on 08/06/2021.
//

#include "headers/Drawing.h"

Drawing::Drawing() {

}
//add a figure to the current drawing
void Drawing::addRectangle(const Rectangle &rect) {
    m_rectangles.push_back(rect);
}

Drawing::Drawing(const Drawing *pDrawing) : m_rectangles(pDrawing->m_rectangles) {
}

const int Drawing::nbRectangles() {
    return m_rectangles.size();
}

Rectangle Drawing::getRectangle(int i) {
    return m_rectangles[i];
}

void Drawing::setRectangleCourant(int i, int h, int w) {

    this->getRectangle(i).setMH(h);
    this->getRectangle(i).setMW(w);
}



//int Drawing::Open() {
//}

