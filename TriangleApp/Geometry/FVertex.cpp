//
// Created by fush on 11/11/24.
//

#include "FVertex.h"

#include <array>
#include <vulkan/vulkan_core.h>

namespace TriangleApp {
    namespace Geometry {
        VkVertexInputBindingDescription FVertex::getBindingDescription() {
            VkVertexInputBindingDescription bindingDescription{};
            bindingDescription.binding = 0;
            bindingDescription.stride = sizeof(FVertex);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

            return bindingDescription;
        }

        std::array<VkVertexInputAttributeDescription, 2> FVertex::getAttributesDescriptions() {
            std::array<VkVertexInputAttributeDescription, 2> attributesDescriptions{};

            attributesDescriptions[0].binding = 0;
            attributesDescriptions[0].location = 0;
            attributesDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
            attributesDescriptions[0].offset = offsetof(FVertex, pos);

            attributesDescriptions[1].binding = 0;
            attributesDescriptions[1].location = 1;
            attributesDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributesDescriptions[1].offset = offsetof(FVertex, color);

            return attributesDescriptions;
        }
    }
}
