//
// Created by fush on 11/11/24.
//

#ifndef FVERTEX_H
#define FVERTEX_H

#include <glm/glm.hpp>
#include <vulkan/vulkan_core.h>

struct VkVertexInputBindingDescription;

namespace TriangleApp {
    namespace Geometry {
        struct FVertex {
        public:
            glm::vec2 pos;
            glm::vec3 color;

            static VkVertexInputBindingDescription getBindingDescription();

            static std::array<VkVertexInputAttributeDescription, 2> getAttributesDescriptions();
        };
    }
}

#endif //FVERTEX_H
