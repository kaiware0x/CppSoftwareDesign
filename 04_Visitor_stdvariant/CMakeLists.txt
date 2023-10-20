cmake_minimum_required(VERSION 3.5)

project(VariantVisitor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VariantVisitor main.cpp
    Circle.h
    Point.h
    Square.h
    Shapes.h
    Shape.h
    Draw.h
    DrawAllShapes.cpp DrawAllShapes.h
)
