#pragma once

namespace Engine {
    class Renderer {
    public:
        Renderer();
        ~Renderer();

        void Clear(float r = 0.1f, float g = 0.1f, float b = 0.1f, float a = 1.0f) const;
    };
}
