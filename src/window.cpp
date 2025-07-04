#include "Zio/window.hpp"
#include <stdexcept>
#include <iostream>

namespace Zio {

    Window::Window(int width, int height, const std::string& title) : m_Width(width), m_Height(height) {
        Init(width, height, title);
    }

    Window::~Window() {
        Shutdown();
    }

    void Window::Init(int width, int height, const std::string& title) {
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!m_Window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1); // Enable VSync
    }

    void Window::Shutdown() {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::SwapBuffers() const {
        glfwSwapBuffers(m_Window);
    }

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(m_Window);
    }

    void Window::PollEvents() {
        glfwPollEvents();
    }

}
