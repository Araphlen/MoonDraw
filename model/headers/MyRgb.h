//
// Created by araphlen on 11/06/2021.
//

#ifndef MOONDRAW_MYRGB_H
#define MOONDRAW_MYRGB_H


class MyRgb {
public:
    MyRgb(unsigned char r, unsigned char g, unsigned char b);

    unsigned char getR() const;

    void setR(unsigned char r);

    unsigned char getG() const;

    void setG(unsigned char g);

    unsigned char getB() const;

    void setB(unsigned char b);
private:
    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
};


#endif //MOONDRAW_MYRGB_H
