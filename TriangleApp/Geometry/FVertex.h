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
            glm::vec3 pos;
            glm::vec3 color;
            glm::vec2 texCoord;

            static VkVertexInputBindingDescription getBindingDescription();

            static std::array<VkVertexInputAttributeDescription, 3> getAttributesDescriptions();

            bool operator==(const FVertex &other) const;
        };
    }
}

namespace std {
    template<> struct hash<TriangleApp::Geometry::FVertex> {
        size_t operator()(TriangleApp::Geometry::FVertex const& vertex) const;
    };
}
#endif //FVERTEX_H
