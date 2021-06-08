//
// Created by araphlen on 08/06/2021.
//

#include "headers/Figure.h"

Figure::Figure() {
    m_label = new std::string;
}

Figure::Figure(const std::string &label) {
    m_label = new std::string(label);
}
