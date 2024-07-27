//
// Created by bolek on 15.04.2023.
//
#include "shape.h"
#ifndef TESTS_RECTANGLE_H
#define TESTS_RECTANGLE_H

#endif //TESTS_RECTANGLE_H

namespace Shapes {
    class Rectangle : public Shape
    {
    private:
        int x1, y1, xTo1, yTo1;
    public:
        Rectangle(const int& a, const int& b, const int& c, const int& d);
        bool isIn(int x, int y) const override;
        int x() const;
        int y() const;
        int xTo() const;
        int yTo() const;
    };
}






