#include "Engine/renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>   // ← pour glfwGetProcAddress
#include <stdexcept>      // ← pour std::runtime_error

namespace Engine {
    Renderer::Renderer() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD");
        }
        glEnable(GL_DEPTH_TEST);
    }

    Renderer::~Renderer() {}

    void Renderer::Clear(float r, float g, float b, float a) const {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
