#pragma once

#include <cstdint>

class GLFWwindow;
namespace TriangleApp {

    class TriangleAppMain {
        public:

            static constexpr uint32_t WIDTH = 1280;
            static constexpr uint32_t HEIGHT = 720;

            void Run();

        private:

            GLFWwindow* Window = nullptr;

            void InitWindow();
            void InitVulkan();
            void MainLoop();
            void Cleanup();
    };

}