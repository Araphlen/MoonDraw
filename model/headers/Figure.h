//
// Created by araphlen on 08/06/2021.
//

#ifndef MOONDRAW_FIGURE_H
#define MOONDRAW_FIGURE_H

#include <string>


class Figure {
public:
    Figure();
    Figure(const std::string& label);

protected:
    std::string * m_label;

};


#endif //MOONDRAW_FIGURE_H
