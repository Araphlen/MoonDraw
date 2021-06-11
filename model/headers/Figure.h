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

    int getPenSize() const;

    Figure(const int shape,const std::string& penColor,const std::string& brushColor,int penSize);

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


    virtual void addPoint(int x, int y){};
    virtual int getNbPoints(){return 0;};
    virtual Point getPoint(int p){return Point();};

    void setShape(int mShape);
    void SetBorderColor(const std::string &color);
    void SetFillColor(const std::string &fillColor);

    std::string GetBorderColor() const;
    std::string GetFillColor() const ;


protected:
    std::string * m_label;
    int m_shape;
    std::string * m_borderColor;
    std::string * m_fillColor;
    int m_penSize;
};


#endif //MOONDRAW_FIGURE_H
