//
// Created by fush on 11/11/24.
//

#ifndef MEMORYHELPER_H
#define MEMORYHELPER_H
#include <cstdint>
#include <vulkan/vulkan_core.h>

namespace TriangleApp {
    namespace Memory {

        class MemoryHelper {
        public:
            static uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties, VkPhysicalDevice physicalDevice);
        };

    } // Memory
}


#endif //MEMORYHELPER_H
