cmake_minimum_required(VERSION 3.14)
project(Rocketboy)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        ${PROJECT_NAME}
        main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/glad/src/glad.c
        RayTracer.cpp
)

target_include_directories(
        ${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/glad/include/
)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        OpenGL::GL
        glfw
        glm::glm
)