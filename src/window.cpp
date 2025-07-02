#include "Engine/window.h"
#include <stdexcept>

namespace Engine {
    Window::Window(int width, int height, const std::string& title) {
        if (!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!m_Window)
            throw std::runtime_error("Failed to create GLFW window");

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);
    }

    Window::~Window() {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::PollEvents() const {
        glfwPollEvents();
    }

    void Window::SwapBuffers() const {
        glfwSwapBuffers(m_Window);
    }

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(m_Window);
    }

    GLFWwindow* Window::GetNativeWindow() const {
        return m_Window;
    }
}
