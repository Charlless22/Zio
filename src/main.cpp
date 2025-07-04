#include <Zio/zio.hpp>
#include <iostream>

int main() {
    try {
        Zio::Window window(800, 600, "Test");
        Zio::Input::Init(window.GetNativeWindow());

        while (!window.ShouldClose()) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            window.SwapBuffers();
            Zio::Window::PollEvents();

            if (Zio::Input::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
                std::cout << "Espace pressé !" << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
