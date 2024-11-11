//
// Created by fush on 11/11/24.
//

#include "MemoryHelper.h"

#include <stdexcept>

namespace TriangleApp {
    namespace Memory {
        uint32_t MemoryHelper::findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties,
            VkPhysicalDevice physicalDevice) {

            VkPhysicalDeviceMemoryProperties memProperties;
            vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);

            for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
                if (typeFilter & (1 << i) && (memProperties.memoryTypes[i].propertyFlags & properties)) {
                    return i;
                }
            }

            throw std::runtime_error("Failed to fin suitable memory type!");
        }
    }
}
