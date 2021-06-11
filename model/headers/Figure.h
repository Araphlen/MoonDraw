//
// Created by araphlen on 08/06/2021.
//

#ifndef MOONDRAW_FIGURE_H
#define MOONDRAW_FIGURE_H

#include <string>
#include "Point.h"
#include "MyRgb.h"


class Figure {
public:
//    Figure();
    Figure(int mShape, const MyRgb &mBorderColor, const MyRgb &mFillColor, int mPenSize,bool isTransparent);

    int getPenSize() const;

//    Figure(const int shape,const MyRgb penColor,const MyRgb brushColor,int penSize);

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

    const MyRgb &getBorderColor() const;

    void setBorderColor(const MyRgb &mBorderColor);

    const MyRgb &getFillColor() const;

    void setFillColor(const MyRgb &mFillColor);

    bool isTransparent() const;

    void setIsTransparent(bool mIsTransparent);

protected:
    std::string * m_label;
    int m_shape;
    MyRgb m_borderColor;
    MyRgb m_fillColor;
    int m_penSize;
    bool m_isTransparent;
};


#endif //MOONDRAW_FIGURE_H
