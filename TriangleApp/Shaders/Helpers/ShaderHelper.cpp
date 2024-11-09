//
// Created by fush on 11/9/24.
//
#include "ShaderHelper.h"

#include <fstream>

namespace TriangleApp {
    namespace Shader {
        std::vector<char> ShaderHelper::readFile(const std::string &filename) {
            std::ifstream file(filename, std::ios::ate | std::ios::binary);

            if (!file.is_open()) {
                throw std::runtime_error("failed to open file!");
            }

            size_t fileSize = (size_t)file.tellg();

            std::vector<char> buffer(fileSize);

            file.close();

            return buffer;
        }
    }
}
