#pragma once

#include <string>
#include <GLFW/glfw3.h>

namespace Zio {

    class Window {
    public:
        Window(int width, int height, const std::string& title);
        ~Window();

        void SwapBuffers() const;
        bool ShouldClose() const;

        inline int GetWidth() const { return m_Width; }
        inline int GetHeight() const { return m_Height; }
        inline GLFWwindow* GetNativeWindow() const { return m_Window; }

        static void PollEvents();

    private:
        void Init(int width, int height, const std::string& title);
        void Shutdown();

    private:
        int m_Width, m_Height;
        GLFWwindow* m_Window = nullptr;
    };

} // namespace Zio
