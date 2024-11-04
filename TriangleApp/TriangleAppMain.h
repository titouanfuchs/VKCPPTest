#pragma once

#include <cstdint>
#include <vector>

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

            const std::vector<const char*> validationLayers = {
                "VK_LAYER_KHRONOS_validation"
            };

#ifdef NDEBUG
            const bool enableValidationLayers = false;
#else
            const bool enableValidationLayers = true;
#endif

            void InitWindow();
            void InitVulkan();

            void CreateInstance();

            void MainLoop();
            void Cleanup();

            bool checkValidationLayerSupport() const;
    };

}