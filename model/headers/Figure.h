//
// Created by araphlen on 08/06/2021.
//

#ifndef MOONDRAW_FIGURE_H
#define MOONDRAW_FIGURE_H

#include <string>
#include "Point.h"


class Figure {
public:
    Figure();
    Figure(const int shape);

    int getShape();

    virtual Point getTopLeft() const {
        return Point();
    };

    virtual Point getBottomRight() const{return Point();};

    virtual void setTopLeft(int x, int y){};
    virtual void setBottomRight(int x, int y){};

    virtual int getH() const {return 0;};
    virtual int getW() const{return 0;};

    virtual void setH(int h){};
    virtual void setW(int w){};

    //virtual methode for circles
    virtual Point getCenter() const {return Point();};
    virtual void setRay(int pointerX, int pointerY){};

    virtual int getRay() const {return 0;};

protected:
    std::string * m_label;
    int m_shape;
};


#endif //MOONDRAW_FIGURE_H
