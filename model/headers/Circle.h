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
    Circle(const Point &center, int ray);

    const Point &getCenter() const;
    void setRay(int pointerX, int pointerY);

    int getRay() const;

private:
    Point m_center;
    int m_ray;
};


#endif //MOONDRAW_CIRCLE_H
