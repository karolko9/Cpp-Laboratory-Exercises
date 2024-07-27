//
// Created by bolek on 15.04.2023.
//
#include "rectangle.h"


namespace Shapes {

    bool Rectangle::isIn(int x, int y) const {
        if(x>=x1&&x<=xTo1&&y>=y1&&y<=yTo1){
            return true;
        } else return false;
    }

    Rectangle::Rectangle(const int &a, const int &b, const int &c, const int &d) {
        x1=a;
        y1=b;
        xTo1=c;
        yTo1=d;
    }

    int Rectangle::x() const {
        return x1;
    }

    int Rectangle::y() const {
        return y1;
    }

    int Rectangle::xTo() const {
        return xTo1;
    }

    int Rectangle::yTo() const {
        return yTo1;
    }
}