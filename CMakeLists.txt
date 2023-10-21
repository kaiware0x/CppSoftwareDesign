cmake_minimum_required(VERSION 3.0.0)
project(CppSoftwareDesign VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CppSoftwareDesign 
    04_Visitor_Classical/main.cpp
    # 06_Observer_Classical/main.cpp
)
