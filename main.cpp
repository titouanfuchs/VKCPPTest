#include <exception>
#include <iostream>

#include "TriangleApp/TriangleAppMain.h"

using namespace TriangleApp;

int main() {
    TriangleAppMain triangleApp;

    try {
        triangleApp.Run();
    }catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;

        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
