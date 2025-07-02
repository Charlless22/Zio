#include "Engine/window.h"
#include "Engine/renderer.h"
#include <iostream>

int main() {
    try {
        Engine::Window window(1280, 720, "MyEngine");
        Engine::Renderer renderer;

        while (!window.ShouldClose()) {
            window.PollEvents();
            renderer.Clear(0.2f, 0.3f, 0.3f, 1.0f);
            window.SwapBuffers();
        }
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
