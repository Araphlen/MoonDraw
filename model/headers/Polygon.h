//
// Created by araphlen on 11/06/2021.
//

#ifndef MOONDRAW_POLYGON_H
#define MOONDRAW_POLYGON_H


#include <vector>
#include "Point.h"
#include "Figure.h"

class Polygon : public Figure{
public:
    Polygon(const Point& p1,const std::string& penColor,const std::string& brushColor,int penSize);
    void addPoint(int x , int y);
    int getNbPoints();
    Point getPoint(int p);
private:
    std::vector<Point> m_points;
};


#endif //MOONDRAW_POLYGON_H