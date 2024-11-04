#define GLFW_INCLUDE_VULKAN
#include "TriangleAppMain.h"

#include <cstring>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

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

        CreateInstance();
    }

    void TriangleAppMain::CreateInstance() {

        if (enableValidationLayers && !checkValidationLayerSupport()) {
            throw std::runtime_error("Validation layers requested, but not available!");
        }

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "FshEngine";
        appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;

        const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;

        createInfo.enabledLayerCount = 0;

        VkResult result = vkCreateInstance(&createInfo, nullptr, &VKInstance);

        if (vkCreateInstance(&createInfo, nullptr, &VKInstance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance!");
        }

        uint32_t extensionsCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionsCount, nullptr);

        std::vector<VkExtensionProperties> extensions(extensionsCount);

        vkEnumerateInstanceExtensionProperties(nullptr, &extensionsCount, extensions.data());

        std::cout << "available extensions: \n";

        for (const auto& extension : extensions) {
            std::cout << "\t" << extension.extensionName << "\n";
        }
    }

    void TriangleAppMain::MainLoop() {
        std::cout << "Main loop" << std::endl;

        while(!glfwWindowShouldClose(Window))
            glfwPollEvents();
    }

    void TriangleAppMain::Cleanup() {
        std::cout << "End" << std::endl;

        vkDestroyInstance(VKInstance, nullptr);

        glfwDestroyWindow(Window);
        glfwTerminate();
    }

    bool TriangleAppMain::checkValidationLayerSupport() const {
        uint32_t layerCount;

        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        for (const char* layerName : validationLayers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) return false;
        }

        return true;
    }
}
