//
// Created by araphlen on 09/06/2021.
//

#ifndef MOONDRAW_CIRCLE_H
#define MOONDRAW_CIRCLE_H

#include "Figure.h"
#include "Point.h"

class Circle : public Figure{
public:
    Circle();
    Circle(const Point &center, int ray,const MyRgb &penColor, const MyRgb &brushColor,int penSize,bool isTransparent);

    Point getCenter() const override;
    void setRay(int pointerX, int pointerY) override;

    int getRay() const override;
    Point getPointCircle() const;
private:
    Point m_center;
    Point m_pointCercle;
    int m_ray;

};


#endif //MOONDRAW_CIRCLE_H
