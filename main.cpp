#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
//TODO : FIX THE LAGGY FEEL OF RESIZING THE WINDOW
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void renderFunc(GLFWwindow* window);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

/************Boilerplate inspired by learnopengl.com*********************************/
    /*Parameters*/
    int windowWidth = 1000;
    int windowHeight = 800;
    /************/
    /************WindowCreation****************/
    GLFWwindow* rocketWindow {
        glfwCreateWindow(
            windowWidth,
            windowHeight,
            "ROCKET WINDOW",
            nullptr,
            nullptr
        )
    };

    if (!rocketWindow)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(rocketWindow);
    /***************************************/


    /************InitializingGLAD****************/
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    /*********************************************/

    /*************WindowProcedure*****************/
    glfwSetFramebufferSizeCallback(rocketWindow, framebuffer_size_callback);
    /*********************************************/
    glViewport(0, 0, windowWidth, windowHeight);
/***********************************************************************************/


/*******************************Render Loop*****************************************/
    while (!glfwWindowShouldClose(rocketWindow))
    {
        //input handling
        processInput(rocketWindow);
        //rendering commands
        renderFunc(rocketWindow);
        //check and call events
        glfwPollEvents();

    }
/***********************************************************************************/
    glfwTerminate();
    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_F))
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void renderFunc(GLFWwindow* window)
{
    glClearColor(0.4f, 0.1f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}
