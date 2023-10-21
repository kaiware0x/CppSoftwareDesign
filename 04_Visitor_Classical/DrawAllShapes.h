
#include <memory>
#include <vector>

#include "Draw.h"
#include "Shape.h"

inline void drawAllShapes(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (auto&& shape : shapes) {
        /// Cons: 仮想関数が2回コールされるので遅い
        shape->accept(Draw{});
    }
}