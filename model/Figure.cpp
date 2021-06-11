//
// Created by araphlen on 08/06/2021.
//

#include "headers/Figure.h"
#define EDIT_SHAPE 0

//Figure::Figure() {
//    m_shape = EDIT_SHAPE;
//    m_borderColor = MyRgb(0,0,0);
//    m_fillColor= MyRgb(255,255,255);
//    m_penSize=1;
//}

//Figure::Figure(const int shape,const MyRgb penColor,const MyRgb brushColor,int penSize) {
//    m_shape = shape;
//    m_borderColor = penColor;
//    m_fillColor= brushColor;
//    m_penSize= penSize;
//
//}
Figure::Figure(int mShape, const MyRgb &mBorderColor, const MyRgb &mFillColor, int mPenSize,bool isTransparent) : m_shape(mShape),
                                                                                               m_borderColor(mBorderColor),
                                                                                               m_fillColor(mFillColor),
                                                                                               m_penSize(mPenSize),
                                                                                               m_isTransparent(isTransparent){}

int Figure::getShape() {
    return m_shape;
}

void Figure::setShape(int mShape) {
    m_shape = mShape;
}

int Figure::getPenSize() const {
    return m_penSize;
}

const MyRgb &Figure::getBorderColor() const {
    return m_borderColor;
}

void Figure::setBorderColor(const MyRgb &mBorderColor) {
    m_borderColor = mBorderColor;
}

const MyRgb &Figure::getFillColor() const {
    return m_fillColor;
}

void Figure::setFillColor(const MyRgb &mFillColor) {
    m_fillColor = mFillColor;
}

bool Figure::isTransparent() const {
    return m_isTransparent;
}

void Figure::setIsTransparent(bool mIsTransparent) {
    m_isTransparent = mIsTransparent;
}

