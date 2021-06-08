//
// Created by araphlen on 08/06/2021.
//

#include "headers/Figure.h"
#define DEFAULT_SHAPE 0
Figure::Figure() {
    m_shape = DEFAULT_SHAPE;
}

Figure::Figure(const int shape) {
    m_shape = shape;
}

int Figure::getShape() {
    return m_shape;
}
