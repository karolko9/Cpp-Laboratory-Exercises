//
// Created by bolek on 23.04.2023.
//

#ifndef TESTS_CIRCLE_H
#define TESTS_CIRCLE_H

#endif //TESTS_CIRCLE_H

#include "shape.h"

namespace Shapes {
    class Circle : public Shape
    {
    private:
        int x1, y1, r1;
    public:
        Circle(const int& a, const int& b, const int& c);
        bool isIn(int x, int y) const override;
        int getRadius() const;
        int x() const;
        int y() const;

    };
}
