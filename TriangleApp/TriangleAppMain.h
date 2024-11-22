#pragma once

#include <cstdint>
#include <vector>
#include <vulkan/vulkan_core.h>

#include "Geometry/FVertex.h"

using TriangleApp::Geometry::FVertex;

struct FSwapChainSupportDetails;
struct FQueueFamilyIndices;
class GLFWwindow;
class VkInstance_T;

namespace TriangleApp {

    class TriangleAppMain {
        public:

            static constexpr uint32_t WIDTH = 1920;
            static constexpr uint32_t HEIGHT = 1080;

            static constexpr int MAX_FRAMES_IN_FLIGHT = 2;

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
            VkPipeline VKGraphicsPipeline;

            VkCommandPool VKCommandPool;
            std::vector<VkCommandBuffer> VKCommandBuffers;

            std::vector<VkSemaphore> imageAvailableSemaphores;
            std::vector<VkSemaphore> renderFinishedSemaphores;
            std::vector<VkFence> inFlightFences;

            std::vector<VkImage> SwapChainImages;
            std::vector<VkImageView> SwapChainImageViews;

            std::vector<VkFramebuffer> swapChainFramebuffers;

            VkBuffer VKVertexBuffer;
            VkDeviceMemory VKVertexBufferMemory;

            VkBuffer VKIndexBuffer;
            VkDeviceMemory VKIndexBufferMemory;

            std::vector<VkBuffer> uniformBuffers;
            std::vector<VkDeviceMemory> uniformBuffersMemory;
            std::vector<void*> uniformBuffersMapped;

            VkDescriptorSetLayout VKDescriptorSetLayout;
            VkPipelineLayout VKPipelineLayout;

            VkDescriptorPool VKDescriptorPool;
            std::vector<VkDescriptorSet> VKDescriptorSets;

            bool framebufferResized = false;

            uint32_t currentFrame = 0;

            const std::vector<const char*> validationLayers = {
                "VK_LAYER_KHRONOS_validation"
            };

            const std::vector<const char*> deviceExtensions = {
                VK_KHR_SWAPCHAIN_EXTENSION_NAME
            };

            const std::vector<FVertex> vertices = {
                {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
                {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
                {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
                {{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

                {{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
                {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
                {{0.5f, 0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
                {{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
            };

            const std::vector<uint16_t> indices = {
                0, 1, 2, 2, 3, 0,
                4, 5, 6, 6, 7, 4
            };

            VkImage textureImage;
            VkDeviceMemory textureImageMemory;

            VkImageView textureImageView;
            VkSampler textureSampler;

            VkImage depthImage;
            VkDeviceMemory depthImageMemory;
            VkImageView depthImageView;

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

#pragma region SwapChain & Surface

            VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
            VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
            VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
            void createSurface();
            void createSwapChain();
            void cleanupSwapChain();
            void recreateSwapChain();

            void createImageViews();

#pragma endregion

            void CreateInstance();

            void MainLoop();
            void Cleanup();

            bool checkValidationLayerSupport() const;
            std::vector<const char*> getRequiredExtensions() const;

#pragma region Render Pipeline

            VkShaderModule createShaderModule(const std::vector<char>& code);

            void createDescriptorSetLayout();

            void createGraphicsPipeline();

            void createRenderPass();

#pragma endregion

#pragma region Command Buffers

            VkCommandBuffer beginSingleTimeCommandBuffer() const;
            void endSingleTimeCommands(VkCommandBuffer commandBuffer);

#pragma endregion

#pragma region Framebuffers
            void createFramebuffers();
            static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
#pragma endregion

#pragma region Render Commands

            void createCommandPool();
            void createCommandBuffers();

            void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

#pragma endregion

#pragma region VertexBuffer

            void createVertexBuffer();
            void createIndexBuffer();
            void createUniformsBuffers();

            void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);


#pragma endregion

#pragma region Buffer

        void copyBuffer (VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

#pragma endregion

#pragma region Uniform Buffer

            void updateUniformBuffer(uint32_t currentImage);

#pragma endregion

#pragma region Descriptor

            void createDescriptorPool();
            void createDescriptorSets();

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

#pragma region Texture

            void createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
            void createTextureImage();

            void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);

            void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

            void createTextureImageView();

            void createTextureSampler();

#pragma endregion

#pragma region Image

            VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags = VK_IMAGE_ASPECT_COLOR_BIT);

#pragma endregion

#pragma region Depth

        VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
        VkFormat findDepthFormat();

            static bool hasStencilComponent(VkFormat format);

        void createDepthResources();

#pragma endregion
    };

}