//
// Created by bolek on 23.04.2023.
//
#include "shapecomposite.h"

Shapes::ShapeComposite::ShapeComposite(const std::shared_ptr<Shape> &shape11, const std::shared_ptr<Shape> &shape22, ShapeOperation operation33)
        : shape1(shape11), shape2(shape22), operation(operation33)
{}
bool Shapes::ShapeComposite::isIn(int x, int y) const
{
    switch (operation) {
        case ShapeOperation::INTERSECTION:
            return (shape1->isIn(x, y) && shape2->isIn(x, y));
            break;
        case ShapeOperation::SUM:
            return (shape1->isIn(x, y) || shape2->isIn(x, y));
            break;
        case ShapeOperation::DIFFERENCE:
            return (shape1->isIn(x, y) && !shape2->isIn(x, y));
            break;
        default:
            return false;
    }
}