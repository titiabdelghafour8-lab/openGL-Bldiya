cmake_minimum_required(VERSION 3.14)
project(Rocketboy)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        Rocketboy
        main.cpp
        ./deps/glad/src/glad.c
)

target_include_directories(Rocketboy PRIVATE ./deps/glad/include)

target_link_libraries(
        Rocketboy PRIVATE
        OpenGL::GL
        glfw
        glm::glm
)