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
    Circle(const Point &center, int ray,const std::string& penColor,const std::string& brushColor,int penSize);

    Point getCenter() const override;
    void setRay(int pointerX, int pointerY) override;

    int getRay() const override;

private:
    Point m_center;
    int m_ray;
};


#endif //MOONDRAW_CIRCLE_H