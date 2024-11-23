cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 20)

project(VKCPPTest)

find_package(Vulkan REQUIRED FATAL_ERROR)
find_package(glfw3 REQUIRED FATAL_ERROR)

add_executable(VKCPPTest main.cpp TriangleApp/TriangleAppMain.h TriangleApp/TriangleAppMain.cpp
        TriangleApp/FQueueFamilyIndices.h
        TriangleApp/FSwapChainSupportDetails.h
        TriangleApp/Shaders/Helpers/ShaderHelper.cpp
        TriangleApp/Shaders/Helpers/ShaderHelper.h
        TriangleApp/Geometry/FVertex.h
        TriangleApp/Geometry/FVertex.cpp
        TriangleApp/Memory/MemoryHelper.cpp
        TriangleApp/Memory/MemoryHelper.h
        TriangleApp/Geometry/FUniformBufferObjet.cpp
        TriangleApp/Geometry/FUniformBufferObjet.h
        TriangleApp/Libs/stb_image.h
        TriangleApp/Libs/tiny_obj_loader.h)

target_link_libraries(VKCPPTest glfw vulkan)