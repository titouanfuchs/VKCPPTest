#pragma once

#include <cstdint>

class GLFWwindow;
class VkInstance_T;

namespace TriangleApp {

    class TriangleAppMain {
        public:

            static constexpr uint32_t WIDTH = 1280;
            static constexpr uint32_t HEIGHT = 720;

            void Run();

        private:

            GLFWwindow* Window = nullptr;
            VkInstance_T* VKInstance;

            void InitWindow();
            void InitVulkan();
            void MainLoop();
            void Cleanup();
    };

}