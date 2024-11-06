cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 20)

project(VKCPPTest)

find_package(Vulkan REQUIRED FATAL_ERROR)
find_package(glfw3 REQUIRED FATAL_ERROR)

add_executable(VKCPPTest main.cpp TriangleApp/TriangleAppMain.h TriangleApp/TriangleAppMain.cpp)

target_link_libraries(VKCPPTest glfw vulkan)