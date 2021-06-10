//
// Created by araphlen on 08/06/2021.
//

#include "headers/Figure.h"
#define DEFAULT_SHAPE 0

Figure::Figure() {
    m_shape = DEFAULT_SHAPE;
    m_borderColor = new std::string("#000000");
    m_fillColor= new std::string("#FFFFFF");

}

Figure::Figure(const int shape,const std::string& penColor,const std::string& brushColor) {
    m_shape = shape;
    m_borderColor = new std::string(penColor);
    m_fillColor= new std::string(brushColor);
}

int Figure::getShape() {
    return m_shape;
}

void Figure::setShape(int mShape) {
    m_shape = mShape;
}

void Figure::SetBorderColor(const std::string &color) {

    *m_borderColor= color;
}
void Figure::SetFillColor(const std::string &fillColor) {
    *m_fillColor= fillColor;
}

std::string Figure::GetBorderColor() const {
    return *(m_borderColor);
}
std::string Figure::GetFillColor() const {
    return *(m_fillColor);
}