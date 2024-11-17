//
// Created by fush on 11/17/24.
//

#ifndef FUNIFORMBUFFEROBJET_H
#define FUNIFORMBUFFEROBJET_H

#include <glm/glm.hpp>

namespace TriangleApp {
    namespace Geometry {

        struct FUniformBufferObjet {
            glm::mat4 model;
            glm::mat4 view;
            glm::mat4 proj;
        };

    } // Geometry
}

#endif //FUNIFORMBUFFEROBJET_H
