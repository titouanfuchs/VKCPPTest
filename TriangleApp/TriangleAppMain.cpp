#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "TriangleAppMain.h"

#include <iostream>

namespace TriangleApp {

    void TriangleAppMain::Run() {
        InitWindow();
        InitVulkan();
        MainLoop();
        Cleanup();
    }

    void TriangleAppMain::InitWindow() {
        std::cout << "Init Window" << std::endl;

        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        Window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle App", nullptr, nullptr);
    }

    void TriangleAppMain::InitVulkan() {
        std::cout << "Init Vulkan" << std::endl;
    }

    void TriangleAppMain::MainLoop() {
        std::cout << "Main loop" << std::endl;

        while(!glfwWindowShouldClose(Window))
            glfwPollEvents();
    }

    void TriangleAppMain::Cleanup() {
        std::cout << "End" << std::endl;

        glfwDestroyWindow(Window);
        glfwTerminate();
    }
}
