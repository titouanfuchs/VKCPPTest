namespace TriangleApp {

    class TriangleAppMain {
        public:
            void Run();

        private:
            void InitVulkan();
            void MainLoop();
            void Cleanup();
    };

}