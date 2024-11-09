//
// Created by fush on 11/9/24.
//

#ifndef FSWAPCHAINSUPPORTDETAILS_H
#define FSWAPCHAINSUPPORTDETAILS_H
#include <vector>
#include <vulkan/vulkan_core.h>

struct FSwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

#endif //FSWAPCHAINSUPPORTDETAILS_H
