#pragma once

//
// Created by fush on 11/9/24.
//

#ifndef SHADERHELPER_H
#define SHADERHELPER_H
#include <string>
#include <vector>

namespace TriangleApp {
    namespace Shader {
        class ShaderHelper {
        public:
            static std::vector<char> readFile(const std::string& filename);
        };
    }
}

#endif //SHADERHELPER_H
