cmake_minimum_required(VERSION 3.0.0)
project(CppSoftwareDesign VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CppSoftwareDesign 
    # 04_Visitor_Classical/main.cpp
    # 04_Visitor_stdvariant/main.cpp
    # 05_Strategy_Classical/main.cpp
    # 05_Strategy_stdfunction/main.cpp
    # 05_Command/main.cpp
    # 06_Observer_Classical/main.cpp
    # 06_Observer_stdfunction/main.cpp
    # 06-5_CRTP_mixin/main.cpp
    # 07-2_ExternalPolymorphism/main.cpp
    # 08_TypeErasure/main.cpp
    # 09-1_Decorator/main.cpp
    09-2_Decorator_allocator/main.cpp
)
