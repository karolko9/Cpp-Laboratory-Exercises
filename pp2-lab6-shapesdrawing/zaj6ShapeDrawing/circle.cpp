//
// Created by bolek on 23.04.2023.
//
#include <cmath>
#include "circle.h"

int Shapes::Circle::getRadius() const {
    return r1;
}

Shapes::Circle::Circle(const int &a, const int &b, const int &c) {
    x1 = a;
    y1 = b;
    r1 = c;
}

bool Shapes::Circle::isIn(int x, int y) const {
    double distance = std::sqrt(std::pow(x - x1, 2) + std::pow(y - y1, 2));
    if (distance <= r1) {
        return true;
    }
    else {
        return false;
    }
}

int Shapes::Circle::x() const {
    return x1;
}

int Shapes::Circle::y() const {
    return y1;
}
