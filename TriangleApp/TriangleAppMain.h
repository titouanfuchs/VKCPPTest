#pragma once

#include <cstdint>
#include <vector>
#include <vulkan/vulkan_core.h>

struct FQueueFamilyIndices;
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
            VkInstance VKInstance;
            VkPhysicalDevice VKPhysicalDevice = VK_NULL_HANDLE;
            VkDevice VKDevice;
            VkQueue VKQueue;
            VkDebugUtilsMessengerEXT DebugMessenger;

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
            void pickPhysicalDevice();
            void createLogicalDevice();
            bool isDeviceSuitable(VkPhysicalDevice device);
            FQueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

            void CreateInstance();

            void MainLoop();
            void Cleanup();

            bool checkValidationLayerSupport() const;
            std::vector<const char*> getRequiredExtensions() const;

#pragma region Debug

            void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& messengerCreateInfo);
            void setupDebugMessenger();
            VkResult createDebugMessenger(VkInstance instance,
                const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                const VkAllocationCallbacks* pAllocator,
                VkDebugUtilsMessengerEXT*pDebugMessenger);
            void destroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

            static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback( VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                void* pUserData);
#pragma endregion
    };

}