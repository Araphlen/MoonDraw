//
// Created by araphlen on 08/06/2021.
//

#ifndef MOONDRAW_POINT_H
#define MOONDRAW_POINT_H


#include <wx/gdicmn.h>

class Point {
public:
    Point();
    Point(int x, int y);

    int getMX() const;
    int getMY() const;

    void setMX(int mX);

    void setMY(int mY);

private:
    int m_x;
    int m_y;
};


#endif //MOONDRAW_POINT_H
