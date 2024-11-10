#pragma once

#include <cstdint>
#include <vector>
#include <vulkan/vulkan_core.h>

struct FSwapChainSupportDetails;
struct FQueueFamilyIndices;
class GLFWwindow;
class VkInstance_T;

namespace TriangleApp {

    class TriangleAppMain {
        public:

            static constexpr uint32_t WIDTH = 1920;
            static constexpr uint32_t HEIGHT = 1080;

            void Run();

        private:

            GLFWwindow* Window = nullptr;
            VkInstance VKInstance;
            VkPhysicalDevice VKPhysicalDevice = VK_NULL_HANDLE;
            VkDevice VKDevice;
            VkQueue VKGraphicsQueue;
            VkQueue VKPresentQueue;
            VkDebugUtilsMessengerEXT DebugMessenger;
            VkSwapchainKHR VKSwapChain;
            VkSurfaceKHR VKSurface;

            VkFormat SwapChainImageFormat;
            VkExtent2D SwapChainExtent;

            VkRenderPass VKRenderPass;
            VkPipelineLayout pipelineLayout;
            VkPipeline VKPipeline;

            VkCommandPool VKCommandPool;
            VkCommandBuffer VKCommandBuffer;

            VkSemaphore imageAvailableSemaphore;
            VkSemaphore renderFinishedSemaphore;
            VkFence inFlightFence;

            std::vector<VkImage> SwapChainImages;
            std::vector<VkImageView> SwapChainImageViews;

            std::vector<VkFramebuffer> swapChainFramebuffers;

            const std::vector<const char*> validationLayers = {
                "VK_LAYER_KHRONOS_validation"
            };

            const std::vector<const char*> deviceExtensions = {
                VK_KHR_SWAPCHAIN_EXTENSION_NAME
            };

#ifdef NDEBUG
            const bool enableValidationLayers = false;
#else
            const bool enableValidationLayers = true;
#endif

            void InitWindow();

            void InitVulkan();

#pragma region Device
            void pickPhysicalDevice();
            void createLogicalDevice();
            bool isDeviceSuitable(VkPhysicalDevice device);
            bool checkDeviceExtensionsSupport(VkPhysicalDevice device) const;
            FQueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
            FSwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
#pragma endregion

            VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
            VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
            VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
            void createSurface();
            void createSwapChain();

            void createImageViews();

            void CreateInstance();

            void MainLoop();
            void Cleanup();

            bool checkValidationLayerSupport() const;
            std::vector<const char*> getRequiredExtensions() const;

#pragma region Render Pipeline

            VkShaderModule createShaderModule(const std::vector<char>& code);

            void createGraphicsPipeline();

            void createRenderPass();

#pragma endregion

#pragma region Framebuffers
            void createFramebuffers();
#pragma endregion

#pragma region Render Commands

            void createCommandPool();
            void createCommandBuffer();

            void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

#pragma endregion

#pragma region Drawing
    void createSyncObjects();

    void drawFrame();
#pragma endregion

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