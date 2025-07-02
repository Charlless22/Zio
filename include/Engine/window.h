#pragma once

#include <string>
#include <GLFW/glfw3.h>

namespace Engine {
    class Window {
    public:
        Window(int width, int height, const std::string& title);
        ~Window();

        void PollEvents() const;
        void SwapBuffers() const;
        bool ShouldClose() const;

        GLFWwindow* GetNativeWindow() const;

    private:
        GLFWwindow* m_Window;
    };
}
