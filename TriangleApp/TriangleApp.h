//
// Created by fush on 10/17/24.
//

#ifndef TRIANGLEAPP_H
#define TRIANGLEAPP_H

namespace TriangleApp {

class TriangleApp {
public:
    void Run();

private:
    void InitVulkan();
    void MainLoop();
    void Cleanup();
};

} // TriangleApp

#endif //TRIANGLEAPP_H
