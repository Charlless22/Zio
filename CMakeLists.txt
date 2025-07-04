cmake_minimum_required(VERSION 3.15)
project(MyEngine)

set(CMAKE_CXX_STANDARD 20)

# VCPKG support
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "")
endif()

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

add_executable(MyEngine
        src/main.cpp
        src/window.cpp
        src/input.cpp
)

target_include_directories(MyEngine PRIVATE include)
target_link_libraries(MyEngine PRIVATE OpenGL::GL glfw glad::glad)
