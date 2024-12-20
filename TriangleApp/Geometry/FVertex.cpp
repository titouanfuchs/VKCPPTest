//
// Created by fush on 11/11/24.
//

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

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

        std::array<VkVertexInputAttributeDescription, 3> FVertex::getAttributesDescriptions() {
            std::array<VkVertexInputAttributeDescription, 3> attributesDescriptions{};

            attributesDescriptions[0].binding = 0;
            attributesDescriptions[0].location = 0;
            attributesDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributesDescriptions[0].offset = offsetof(FVertex, pos);

            attributesDescriptions[1].binding = 0;
            attributesDescriptions[1].location = 1;
            attributesDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributesDescriptions[1].offset = offsetof(FVertex, color);

            attributesDescriptions[2].binding = 0;
            attributesDescriptions[2].location = 2;
            attributesDescriptions[2].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributesDescriptions[2].offset = offsetof(FVertex, texCoord);

            return attributesDescriptions;
        }

        bool FVertex::operator==(const FVertex &other) const {
            return pos == other.pos && color == other.color && texCoord == other.texCoord;
        }
    }
}

std::size_t std::hash<TriangleApp::Geometry::FVertex>::operator()(TriangleApp::Geometry::FVertex const &vertex) const {
    return ((hash<glm::vec3>()(vertex.pos) ^
       (hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^
       (hash<glm::vec2>()(vertex.texCoord) << 1);
}
