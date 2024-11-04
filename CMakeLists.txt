cmake_minimum_required(VERSION 3.29)
project(VKCPPTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(VKCPPTest main.cpp
        TriangleApp/TriangleAppMain.cpp
        TriangleApp/TriangleAppMain.h)
