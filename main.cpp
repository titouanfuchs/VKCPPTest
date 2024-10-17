#include <exception>
#include <iostream>

#include "TriangleApp/TriangleApp.h"

int main() {
    TriangleApp::TriangleApp* triangleApp = new TriangleApp::TriangleApp();

    try {
        triangleApp->Run();
    }catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;

        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
