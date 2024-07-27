//
// Created by bolek on 23.04.2023.
//

#ifndef TESTS_SHAPECOMPOSITE_H
#define TESTS_SHAPECOMPOSITE_H

#endif //TESTS_SHAPECOMPOSITE_H
#include <memory>
#include "shape.h"
//#include "circle.h"
//#include "rectangle.h"

namespace Shapes {
    enum class ShapeOperation {
        INTERSECTION,
        SUM,
        DIFFERENCE
    };
    class ShapeComposite : public Shape {
    private:
        std::shared_ptr<Shape> shape1;
        std::shared_ptr<Shape> shape2;
        ShapeOperation operation;
    public:
        bool isIn(int x, int y) const override;
        ShapeComposite(const std::shared_ptr<Shape>& shape11, const std::shared_ptr<Shape>& shape22, ShapeOperation operation33);
    };
}
